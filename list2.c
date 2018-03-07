#include <stdio.h>
#include <stdlib.h>
struct dbl_item {
    double data;
    struct dbl_item *next, *prev;
};

static struct dbl_item *first = NULL, *last = NULL;
static struct dbl_item *current = NULL, *tmp;

void add_dbl_item_begin(double x)
/* добавление нового элемента в начало списка */
{
    tmp = malloc(sizeof(struct dbl_item));
    tmp->data = x;
    tmp->prev = NULL;
    tmp->next = first;
    if (first)
        first->prev = tmp;
    else
        last = tmp;
    first = tmp;
}

void add_dbl_item_end(double x)
/* добавление нового элемента в конец списка */
{
    tmp = malloc(sizeof(struct dbl_item));
    tmp->data = x;
    tmp->next = NULL;
    tmp->prev = last;
    if (last)
        last->next = tmp;
    else
        first = tmp;
    last = tmp;
}

void del_dbl_item_begin(void)
/* удаление первого элемента списка*/
{
    if (first) { /* проверка обязательна! */
        tmp = first;
        first = first->next;
        if (first)
            first->prev = NULL;
        else        /* список опустел */
            last = NULL;
        free(tmp);
    }
}

void del_dbl_item_end(void)
/* удаление последнего элемента списка*/
{
    if (last) {  /* проверка обязательна! */
        tmp = last;
        last = last->prev;
        if (last)
            last->next = NULL;
        else        /* список опустел */
            first = NULL;
        free(tmp);
    }
}

void del_dbl_item_all(void)
/* удаление всего списка */
{
    if(first) {
        first = first->next;
        while(first){
            free(first->prev);
            first = first->next;
        }
        free(last);
        last = NULL;
        printf("\n        dbl_item list all removed\n");
    }
}

void append_dbl_item_current(double x)
/* вставка элемента списка перед текущим */
{
    if (current) {
        tmp = malloc(sizeof(struct dbl_item));
        tmp->data = x;
        tmp->next = current;
        tmp->prev = current->prev;
        current->prev = tmp;
        if (tmp->prev)
            tmp->prev->next = tmp;
        else
            first = tmp;
    }
}

void append_dbl_item_2current(double x)
/* вставка элемента списка после текущего */
{
    if (current) {
        tmp = malloc(sizeof(struct dbl_item));
        tmp->data = x;
        tmp->prev = current;
        tmp->next = current->next;
        current->next = tmp;
        if (tmp->next)
            tmp->next->prev = tmp;
        else
            last = tmp;
    }
}

void del_dbl_item_current(void)
/* удаление текущего элемента списка */
{
    if (current) {
        if (current->prev)
            current->prev->next = current->next;
        else
            first = current->next;
        
        if (current->next)
            current->next->prev = current->prev;
        else
            last = current->prev;

        tmp = current;
        current = current->next;
        free(tmp);

    }
}
void print_dbl_item_all(void)
/* print (data) всего списка */
{
    if(first) {
        printf("\n All dbl_list will be print!\n");
        tmp = first;
        while(tmp){
            printf("%02.2f\n", tmp->data);
            tmp = tmp->next;
        }
        tmp = NULL;
        // printf("\n");
    }
}


int main()
{
    double arr[] = {1,2,3,4,5,6,7,8,9,10};
    int i =0, len;
    len = sizeof(arr)/sizeof(*arr);
    for(i=0; i< len; i++)     /* create dbl_item */
        add_dbl_item_end(arr[i]);
    printf("\n    dbl_item list created\n");
    print_dbl_item_all();

    printf("\n    dbl_item list add elements\n");
    current = first;
    append_dbl_item_current(0.0);
    current = last;
    append_dbl_item_current(0.0);
    current = last;
    append_dbl_item_2current(15.0);
    print_dbl_item_all();

    printf("\n    dbl_item list del elements\n");
    current = first;
    del_dbl_item_current();
    current = last;
    del_dbl_item_current();
    current = last->prev;
    del_dbl_item_current();
    print_dbl_item_all();

    printf("\n    dbl_item list del all\n");
    del_dbl_item_all();
    return 0;
}


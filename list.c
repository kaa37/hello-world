#include <stdio.h>
#include <stdlib.h>
struct item {
    int data;
    struct item *next;
};

struct item *int_array_to_list(int *arr, int len)
/* создание односвязного списка из массива*/
{
    struct item *tmp;
    if(!len)
        return NULL;
    tmp = malloc(sizeof(struct item));
    tmp->data = *arr;
    tmp->next = int_array_to_list(arr+1, len-1);
    return tmp;
}

int int_list_sum(const struct item *lst)
/* вычисление суммы всех элементов списка */
{
    if(lst)
        return lst->data +  int_list_sum(lst->next);
    else
        return 0;
}

void delete_int_list(struct item *lst)
/* удалить весь список из памяти */
{
    if(!lst)
        return;
    else
        delete_int_list(lst->next);
        free(lst);
}

struct item *delete_custom_from_list(struct item *pcur, int limit)
/* удалить определённые элементы (<limit) из списка */
{
    struct item *res = pcur;
    if(pcur) {
        pcur->next = delete_custom_from_list(pcur->next, limit);
        if(pcur->data < limit) {
            res = pcur->next;
            free(pcur);
        }
    }
    return res;
}

int is_lower20(int x) {return x < 20;}
int is_lower30(int x) {return x < 30;}

void delete_from_int_list(struct item **pcur, int (*crit)(int))
/* удалить определённые элементы (crit def) из списка */
{
    while(*pcur) {
        if((*crit)((*pcur)->data)) {
            struct item *tmp = *pcur;
            *pcur = (*pcur)->next;
            free(tmp);
        } else {
            pcur = &(*pcur)->next;
        }
    }
}

void print_all_list(struct item *lst)
/* напечатать все элементы списка */
{
    if(!lst)
        return;
    printf("%4d",lst->data);
    print_all_list(lst->next);
}

int main()
{
    int m[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int len;
    len = sizeof(m)/sizeof(*m);
    printf("%3d\n",len);
    struct item *list1;
    list1 =  int_array_to_list(m, len);
    print_all_list(list1);
    printf("\n");
    printf("Sum=%5d\n", int_list_sum(list1));
    
    list1=delete_custom_from_list(list1, 20);
    print_all_list(list1);
    printf("\n");
    printf("Sum=%5d\n", int_list_sum(list1));
    delete_int_list(list1);
    
    printf("Second try\n");
    list1 =  int_array_to_list(m, len);
    print_all_list(list1);
    printf("\n");
    delete_from_int_list(&list1, &is_lower20);
    print_all_list(list1);
    printf("\n");
    delete_int_list(list1);

    
    printf("Third try\n");
    list1 =  int_array_to_list(m, len);
    print_all_list(list1);
    printf("\n");
    delete_from_int_list(&list1, &is_lower30);
    print_all_list(list1);
    printf("\n");
    delete_int_list(list1);
    return 0;
}


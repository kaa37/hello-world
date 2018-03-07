#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *left, *right;
};
struct node *root_tree = NULL;

void int_bin_tree_print(struct node *ptr) {
/* напечатать все числа хранящиеся в дереве */
    if (!ptr)
        return;
    int_bin_tree_print(ptr->left);
    printf("%d ", ptr->val);
    int_bin_tree_print(ptr->right);
}

void int_bin_tree_add(struct node **root, int n)
{
/* добавить новый элемент в дерево с упорядочиванием по val */
    if (!*root) {
        *root = malloc(sizeof(**root));
        (*root)->val = n;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    if ((*root)->val == n)
        return;
    if (n < (*root)->val)
        int_bin_tree_add( &((*root)->left), n);
    else
        int_bin_tree_add( &((*root)->right), n);
}

int main(void)
{
    int arr[]={5, 6, 3, 7, 1, 8, 9, 2, 4};
    int i, len;
    // root_tree = NULL;
    len = sizeof(arr)/sizeof(*arr);
    for (i=0; i < len; i++)
        int_bin_tree_add(&root_tree, arr[i]);
    int_bin_tree_print(root_tree);
    printf("\n");
    return 0;
}

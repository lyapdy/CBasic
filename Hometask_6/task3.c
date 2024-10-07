/*
Напишите программу, которая находит разницу между максимальным и
минимальным элементом в дереве.

На входе - дерево 10 5 3 1 7 6 15 13 18.

На выходе: 17
*/

#include <stdio.h>
#include <limits.h>

#define datatype int

typedef struct node
{
    datatype key;
    struct node *left, *right, *parent;
} node;

int findDiff(node *root, int *min, int *max)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->key < *min)
    {
        *min = root->key;
    }

    if (root->key > *max)
    {
        *max = root->key;
    }

    findDiff(root->left, min, max);
    findDiff(root->right, min, max);

    return *max - *min;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    if (root->left) 
        preorder(root->left);
    if (root->right) 
        preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    if (root->left)
        postorder(root->left);
    if (root->right)
        postorder(root->right);
    printf("%d ", root->key);
}




int main(int argc, char **argv)
{
    node n[10] = {0};
    n[0].left = n + 1;
    n[0].right = n + 2;
    n[0].key = 10;
    n[1].left = n + 3;
    n[1].right = n + 4;
    n[1].key = 5;
    n[1].parent = n + 0;
    n[2].left = n + 5;
    n[2].right = n + 6;
    n[2].key = 15;
    n[2].parent = n + 0;
    n[3].left = n + 7;
    n[3].parent = n + 1;
    n[3].key = 3;
    n[4].left = n + 8;
    n[4].parent = n + 1;
    n[4].key = 7;
    n[5].key = 13;
    n[5].parent = n + 2;
    n[6].key = 18;
    n[6].parent = n + 2;
    n[7].key = 1;
    n[7].parent = n + 3;
    n[8].key = 6;
    n[8].parent = n + 4;

    printf("preorder: ");
    preorder(n);
    putchar('\n');
    printf("postorder: ");
    postorder(n);
    putchar('\n');

    int min = INT_MAX;
    int max = INT_MIN;

    int diff = findDiff(n, &min, &max);

    printf("Difference between max and min: %d\n", diff);

    return 0;
}



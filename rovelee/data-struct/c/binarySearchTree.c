#ifndef Tree_H
#define Tree_H
#define TN TreeNode
#define BST BinarySearchTree

struct TN;
typedef struct TN *TN;
typedef TN BST;

BST bst_new(BST T);
TN bst_search(BST T, int elem);
TN bst_min(BST T);
TN bst_max(BST T);
BST bst_insert(BST T, int elem);
BST bst_delete(BST T, int elem);
void bst_free(BST T);

#endif

#include <stdlib.h>
struct TN
{
    int elem;
    TN *left;
    TN *right;
};

void bst_free(BST T)
{
    if (T)
    {
        bst_free(T->left);
        bst_free(T->right);
        free(T);
    }
}

BST bst_insert(BST T, int elem)
{
    if (!T)
    {
        T = malloc(sizeof(struct TN));
        if (!T)
            return NULL;
        else
        {
            T->elem = elem;
            T->left = T->right = NULL;
        }
    }
    else if (elem < T->elem)
        T->left = bst_insert(T->left, elem);
    else if (elem > T->elem)
        T->right = bst_insert(T->right, elem);
    return T;
}

BST bst_delete(BST T, int elem)
{
    if (!T)
        return NULL; // error
    else if (elem < T->elem)
        T->left = bst_delete(T->left, elem);
    else if (elem > T->right)
        T->right = bst_delete(T->right, elem);
    else if (T->right && T->left)
    {
        TN tmp = bst_min(T->right);
        T->elem = tmp->elem;
        T->right = bst_delete(T->right, T->elem);
    }
    else
    {
        TN tmp = T;
        if (!T->left)
            T = T->left;
        else if (!T->right)
            T = T->right;
        free(tmp);
    }
    return T;
}

TN bst_search(BST T, int elem)
{
    if (!T)
        return NULL;
    if (elem < T->elem)
        return bst_search(T->left, elem);
    else if (elem > T->elem)
        return bst_search(T->right, elem);
    else
        return T;
}

TN bst_max(BST T)
{
    if (T)
        while (T->right)
            T = T->right;
    return T;
}

TN bst_min(BST T)
{
    if (!T)
        return T;
    else if (!T->left)
        return T;
    else
        return bst_min(T->left);
}
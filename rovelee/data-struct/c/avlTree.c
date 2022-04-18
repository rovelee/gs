// 
// Adelson-Velskii and Landis Tree (aka AVL Tree)
// 
// avlTree.h
// 
#ifndef AVL_TREE_H
#define N AvlNode
#define E Element
#define T AvlTree

struct N;
typedef struct N *T;
typedef struct N *N;

T avl_makeEmpty(T t);
N avl_find(E x, T t);
N avl_min(T t);
N avl_max(T t);
T avl_insert(E x, T t);
T avl_delete(E x, T t);
E avl_retrieve(N p);

#undef N
#undef E
#undef T
#endif
// 
// avlTree.c
// 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N AvlNode
#define E Element
#define T AvlTree
#define Max(x,y) (x>y?x:y)

typedef int E;
typedef struct N
{
	E elem;
	T left;
	T right;
	int height;
}*N,*T;
// 
static int avl_height(N p)
{
	if(p == NULL)
		return -1;
	else
		return p->height;
}
void FatalError(char *msg)
{
	printf("%s\n", msg);
	exit(-1);
}
void avl_inOrder(T t)
{
	if(t)
	{
		printf("%d ", t->elem);
		avl_inOrder(t->left);
		avl_inOrder(t->right);
	}
}
// single rotation
N leftRotation(N k1)
{
	N k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = Max(avl_height(k1->left),avl_height(k1->right))+1;
	k2->height = Max(avl_height(k2->left),avl_height(k2->right))+1;

	return k2;
}
N rightRotation(N k1)
{
	N k2;

	k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;

	k1->height = Max(avl_height(k1->left),avl_height(k1->right))+1;
	k2->height = Max(avl_height(k2->left),avl_height(k2->right))+1;

	return k2;
}
// double rotation
N rightLeftRotation(N k1)
{
	k1->right = rightRotation(k1->right);
	return leftRotation(k1);
}
N leftRightRotation(N k1)
{
	k1->left = leftRotation(k1->left);
	return rightRotation(k1);
}
// 
T avl_insert(E x, T t)
{
	if(!t)
	{
		t = malloc(sizeof(struct N));
		if(!t)
			FatalError("Out of space!!!");
		else
		{
			t->elem = x;
			t->left = NULL;
			t->right = NULL;
			t->height = 0;
		}
	}else
	if(x<t->elem)
	{
		avl_insert(x,t->left);
		if(avl_height(t->left)-avl_height(t->right)==2)
			if(x<t->left)
				t=rightRotation(t);
			else
				t=leftRightRotation(t);
	}else
	if(x>t->elem)
	{
		avl_insert(x,t->right);
		if(avl_height(t->right)-avl_height(t->left)==2)
			if(x<t->left)
				t=leftRotation(t);
			else
				t=rightLeftRotation(t);
	}else
		return t;

	t->height = Max(avl_height(t->left),avl_height(t->right))+1;
	return t;
}
T avl_makeEmpty(T t);
N avl_find(E x, T t);
N avl_min(T t);
N avl_max(T t);
T avl_delete(E x, T t);
E avl_retrieve(N p);

#undef N
#undef E
#undef T

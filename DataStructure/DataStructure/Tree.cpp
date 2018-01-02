#include <stdafx.h>
#include <stdlib.h>
#include <stdio.h>
#define IS_FULL(ptr) (!(ptr))
typedef char T;
typedef struct btnode
{
	T Element;
	struct btnode *Lchild, *Rchild;

}BTNode;

typedef struct btree
{
	struct btnode *Root;
}BTree;

BTNode* NewNode()
{
	BTNode *p = (BTNode*)malloc(sizeof(BTNode));
	if (IS_FULL(p))
	{
		exit(1);
	}
	return p;
}

void CreateBT(BTree *Bt)
{
	Bt->Root = NULL;
}

void MakeBT(BTree *Bt, T x, BTree *Lt, BTree *Rt)
{
	BTNode *p = NewNode();
	p->Element = x;
	p->Lchild = Lt->Root;
	p->Rchild = Rt->Root;
	Lt->Root = Rt->Root = NULL;
	Bt->Root = p;
}


void Visit(BTNode *p)
{
	printf("%c", p->Element);
}

void preOrd(void(*Visit)(BTNode *u), BTNode *t)
{
	if (t)
	{
		(*Visit)(t);
		preOrd(Visit, t->Lchild);
		preOrd(Visit, t->Rchild);
	}
}

void preOrder(BTree Bt, void(*Visit) (BTNode *u))
{
	preOrd(Visit, Bt.Root);
}


/*
void main()
{
	BTree a, x, y, z; T e;
	CreateBT(&a);
	CreateBT(&x);
	CreateBT(&y);
	CreateBT(&z);
	MakeBT(&y, 'E', &a, &a);
	MakeBT(&z, 'F', &a, &a);
	MakeBT(&x, 'C', &y, &z);
	preOrder(x, Visit);
	


	//printf("hello");
	//return 0;

}


*/
#include <stdafx.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)
#define IS_FULL(ptr) (!(ptr))
#define Swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAXSIZE 10	/*  用于要排序数组个数最大值，可根据需要修改 */

typedef int T;
typedef struct node {
	char name[10];
	T Element;
	struct node *Link;
	
	
}Node;

typedef Node *List;


T* InputElement()
{
	static T a;
	scanf("%d", &a);
	return &a;

}
void PrintElement(T x)
{
	printf("%d", x);
}

Node* NewNode1()
{
	Node *p = (Node*)malloc(sizeof(Node));
	if (IS_FULL(p))
	{
		exit(1);
	}
	p->Element = *InputElement();
	p -> Link = NULL;
	return p;

}

List BuildList()
{
	Node* p, *r = NULL, *first = NULL; char c;
	printf("Another element? y/n");
	while ((c = getchar()) == '\n');
	while (tolower(c) != 'n') {
		p = NewNode1();
		if (first != NULL) 
			r->Link = p; 
		else 
			first = p;
		r = p;
		printf("Another element? y/n");
		while ((c = getchar()) == '\n');
	}
	return first;
}

void PrintList(List first)
{
	for (; first; first=first->Link)
	{
		PrintElement(first->Element);

	}
	printf("\n\n");
}


void Clear(List * first)
{
	Node *p = *first;
	while (*first) {
		p = (*first)->Link;
		free(*first);
		*first = p;
	}
}

void addStudent(List *head, char name, int english)
{
	Node *p=new Node;
	Node *q=new Node;
	p->Element = english;
	p->name[0] = name;
	if (p->Element <= (*head)->Element)
	{
		p->Link = *head;
		*head = p;
		//printf("%d", head->Element);
		//printf("%d", head->Link->Element);
		
	}
	else
	{
		//something wrong bug
		if ((*head)->Link != NULL)
		{
		
			q=(*head)->Link;
			(*head)->Link = p;
			p->Link = q;
			addStudent(&q, name, english);

		}
		else
		{
			(*head)->Link = p;
			p->Link = NULL;
		}
	}
	//printf("%d", head->Element);
	//printf("%d", head->Link);
	//return head;
}

/*

void main()
{
	Node *head = new Node;
	// head = { 'ab',62,NULL };
	head->Element = 62;
	head->name[0] = 'a';
	head->Link = NULL;


	addStudent(&head, 'b', 59);
	//printf("%d", head->Element);
	//printf("%d", head->Link->Element);
	PrintList(head);

	addStudent(&head, 'c', 65);
	//printf("%d", head->Element);
	//printf("%d", head->Link->Element);
	printf("\n\n");

	PrintList(head);
	//List l = new List{'a',90,NULL};
	//l->Element = 90;
	//l->Link = NULL;
	//l->name[0] = "a";
	//l = BuildList();
	//PrintList(l);

}

*/
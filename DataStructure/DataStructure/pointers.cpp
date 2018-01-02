#include <stdafx.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct node
{
	int item;
	char *name;
	struct node* link;
	
}Node;
typedef Node* List;

Node* createNewNode(int n,char *name)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->item = n;
	p->name = name;
	p->link = NULL;
	return p;

}

List insertList(Node *head, Node* anode)
{
	Node* temp = head;
	if (temp == NULL)
	{
		head = anode;
	}
	else
	{
		while (temp->link!=NULL)
		{
			temp = temp->link;

		}
		temp->link = anode;
	}

	return head;

}

void insertList(List *head, int n, char* name)
{
	Node* anode = (Node*)malloc(sizeof(Node));
	anode->item = n;
	anode->name = name;
	anode->link = NULL;

	Node* temp = *head;
	if (temp == NULL)
	{
		*head = anode;
	}
	else
	{
		if (anode->item >= temp->item)
		{
			anode->link = *head;
			*head = anode;

		}
		else
		{
			while (temp->link != NULL)
			{
				if ((anode->item < temp->item) && ((anode->item >= temp->link->item)) )
				{
					anode->link = temp->link;
					temp->link = anode;
					break;
				}
				temp = temp->link;
			}
			if (temp->link == NULL && anode->item <= temp->item)
			{
				temp->link = anode;
				anode->link = NULL;
			}

			
		}


	}
}



void printList(List first)
{
	for (; first; first = first->link)
	{
		printf("%d", first->item);
		printf("\t");
		printf("%s", first->name);
		printf("\n");
	}
	
}

void main()
{

	//创建单链表的两种写法 Node* head要写返回值头结点， List* head不用写返回值。
	int a[8] = {52,63,73,14,49,89,99,3};
	//char *name = "he";
	char *name[8] = { "li","wang","zhao","d","he","f","ok","sb" };
	//printf("%s", name[0]);
	//printf("%d", sizeof(name));
	
	Node* head = NULL;
	for (int i = 0; i < 8; i++)
	{
		insertList(&head, a[i],name[i]);
		
	}
	printList(head);
	//Node* node1 = createNewNode(i);
	//insertList(&head, node1);
	//printf("%d", head->item);
	
	/*
	Node* head=NULL,*root=NULL;
	Node* anode = createNewNode(i);
	head=insertList(head, anode);
	Node* anode2 = createNewNode(i+1);
	root=insertList(head, anode2);

	printf("%d", head->item);
	printf("\n\n");
	printf("%d", root->link->item);
	*/


	/*
	MyStruct s1 = { 1,'v',"hello" };
	MyStruct *ptr_s1 = &s1;
	printf("%s", ptr_s1->str);
	printf("\n\n");
	printf("%p", ptr_s1);
	printf("\n\n");
	printf("%p", &s1.i);
	printf("\n\n");
	printf("%p", &s1.a);
	printf("\n\n");
	printf("%p", &s1.str);
	char a[] = "world";
	int b[4] = { 1,2,3,4 };
	char *name = "hello";

	
	printf("%p", name);
	printf("\n\n");
	printf("%p", &name[0]);
	printf("\n\n");
	printf("%s",name);
	printf("\n\n");
	prin(name);
	printf("\n\n");
	printf("%p", a);
	printf("\n\n");
	printf("%s", a);
	printf("\n\n");
	printf("%p", &b[0]);
	printf("\n\n");
	printf("%p", &b[1]);
	printf("\n\n");
	prin(a);
	//prin(name);
	//char *name ;
	//name = a;

	
	//prin(a);


	int i = 6;
	int* p = &i;
	printf("%p", p);
	printf("%p",p++);
	*/

	//char t[5]="asdf";
	//prin(t);
	//char *input_s=t;
	//scanf("%s", t);
	//printf("%s", t);

}
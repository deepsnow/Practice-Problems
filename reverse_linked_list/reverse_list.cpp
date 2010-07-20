// reverse_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int name_size = 24;

typedef struct Node * pNode;
struct Node
{
	//char name[24];
	char name[name_size];
	pNode next;
};

void printInOrder(pNode first_node)
{
	pNode currNode = first_node;
	while(currNode != NULL)
	{
		cout << currNode->name << " ";
		currNode = currNode->next;
	}
	cout << endl;
}

pNode reverseList(pNode first_node)
{
	pNode currNode = first_node;
	pNode before, after;
	before = after = NULL;
	pNode newBegin = NULL;

	while(currNode != NULL)
	{
		if(currNode->next == NULL)
		{
			newBegin = currNode;
			currNode->next = before;
			currNode = NULL;
		}
		else
		{
			after = currNode->next;
			if(before != NULL)
				currNode->next = before;
			else currNode->next = NULL;
			before = currNode;
			currNode = after;
		}
	}

	return newBegin;
}

pNode reverseListRecursive(pNode prevNode, pNode currNode)
{
	pNode pN_result = NULL;

	if(currNode == NULL)
		throw std::exception("invalid invocation: currNode must be non-NULL");
	if(currNode->next != NULL)
	{
		pN_result = reverseListRecursive(currNode, currNode->next);
	}
	else
	{
		pN_result = currNode;
	}

	currNode->next = prevNode;

	return pN_result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node begin;
	memset(begin.name, 0, name_size);
	Node second;
	memset(second.name, 0, name_size);
	Node third;
	memset(third.name, 0, name_size);
	Node end;
	memset(end.name, 0, name_size);

	strcpy(begin.name,"doug");
	begin.next = &second;
	//second.name = "is";
	strcpy(second.name,"is");
	second.next = &third;
	//third.name = "working";
	strcpy(third.name,"working");
	third.next = &end;
	//end.name = "hard";
	strcpy(end.name,"hard");
	end.next = NULL;

	printInOrder(&begin);
	pNode newBegin = reverseList(&begin);
	printInOrder(newBegin);
	newBegin = reverseListRecursive(NULL, newBegin);
	printInOrder(newBegin);

	Node singleton;
	memset(singleton.name, 0, name_size);
	singleton.next = NULL;
	strcpy(singleton.name, "onesy");

	printInOrder(&singleton);
	newBegin = reverseList(&singleton);
	printInOrder(newBegin);
	newBegin = reverseListRecursive(NULL, newBegin);
	printInOrder(newBegin);

	Node two;
	memset(two.name, 0, name_size);
	Node peas;
	memset(peas.name, 0, name_size);

	strcpy(two.name,"two");
	two.next = &peas;
	strcpy(peas.name,"peas");
	peas.next = NULL;

	printInOrder(&two);
	newBegin = reverseList(&two);
	printInOrder(newBegin);
	newBegin = reverseListRecursive(NULL, newBegin);
	printInOrder(newBegin);

	return 0;
}

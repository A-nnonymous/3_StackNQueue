#pragma once
using namespace std;
#define MAXSIZE 10

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

void array_stack_push(int array[], int& stack_top, int push_item)
{
	array[++stack_top] = push_item;
}

int array_stack_pop(int array[], int& stack_top)
{
	return array[stack_top--];
}

int linked_stack_pop(LNode*& head)
{
	int ans;
	LNode* top;
	if (head->next == NULL)return 0;
	top = head->next;	ans = top->data;
	top = top->next;
	free(head->next); head->next = top;
	return ans;
}

void linked_stack_push(LNode*& head, int item)
{
	LNode* insertion;
	insertion = (LNode*)malloc(sizeof(LNode));
	insertion->data = item;
	insertion->next = head->next;
	head->next = insertion;
}

void linked_queue_out()
{
}
void linked_queue_in()
{
}

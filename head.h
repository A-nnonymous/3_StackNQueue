#pragma once
using namespace std;
#define MAXSIZE 20

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

void cprint(char ch)
{
	if (ch != '(' && ch != ')')
	{
		cout << ch;
	}
}
int get_priority(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 0;
	}
	else if (ch == '*' || ch == '/')
	{
		return 1;
	}
	else return -1;
}
int get_clength(char ch[])
{
	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return i;
}
void charray_reverse(char ch[], int length)
{
	int swap;
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		swap = ch[i]; ch[i] = ch[j]; ch[j] = swap;
	}
}
void Infix_To_Postfix(char infix[], char pofix[])
{
	char symbol_stack[MAXSIZE];
	int sstop = -1, potop = -1;
	int i = 0;
	while (infix[i] != '\0')    //run till EOL
	{
		if (infix[i] >= 'a' && infix[i] <= 'z')
		{
			pofix[++potop] = infix[i++];
		}

		else if (infix[i] == '(')   //left quote push
		{
			symbol_stack[++sstop] = infix[i++];
		}

		else if (infix[i] == '+' ||
			infix[i] == '-' ||
			infix[i] == '*' ||
			infix[i] == '/')   // symbol
		{
			if (sstop == -1 ||
				get_priority(infix[i]) >
				get_priority(symbol_stack[sstop]))
			{
				symbol_stack[++sstop] = infix[i++];
			}
			else
			{
				pofix[++potop] = symbol_stack[sstop--];
			}
		}

		else if (infix[i] == ')')
		{
			while (symbol_stack[sstop] != '(')
			{
				pofix[++potop] = symbol_stack[sstop--];
			}
			--sstop; ++i;
		}
	}
	while (sstop != -1)
	{
		pofix[++potop] = symbol_stack[sstop--];
	}
	pofix[++potop] = '\0';
}
void Infix_To_Prefix(char infix[], char prefix[])
{
	char symbol_stack[MAXSIZE];
	int sstop = -1, pretop = -1;
	int in_length = get_clength(infix); int i = in_length - 1;
	int pre_length;
	while (infix[i] >= 0)    //run till EOL
	{
		if (infix[i] >= 'a' && infix[i] <= 'z')
		{
			prefix[++pretop] = infix[i--];
		}

		else if (infix[i] == ')')   //left quote push
		{
			symbol_stack[++sstop] = infix[i--];
		}

		else if (infix[i] == '+' ||
			infix[i] == '-' ||
			infix[i] == '*' ||
			infix[i] == '/')   // symbol
		{
			if (sstop == -1 ||
				get_priority(infix[i]) >=
				get_priority(symbol_stack[sstop]))
			{
				symbol_stack[++sstop] = infix[i--];
			}
			else
			{
				prefix[++pretop] = symbol_stack[sstop--];
			}
		}

		else if (infix[i] == '(')
		{
			while (symbol_stack[sstop] != ')')
			{
				prefix[++pretop] = symbol_stack[sstop--];
			}
			--sstop; --i;
		}
	}
	while (sstop != -1)
	{
		prefix[++pretop] = symbol_stack[sstop--];
	}
	prefix[++pretop] = '\0';

	int temp; pre_length = get_clength(prefix);
	charray_reverse(prefix, pre_length);
}

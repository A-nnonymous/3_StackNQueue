#include<iostream>
#include"head.h"
using namespace std;

void main()
{
	int temp;
	int Array_Stack1[MAXSIZE]; int ASTop1 = -1;
	LNode* linked_stack_head; linked_stack_head = (LNode*)malloc(sizeof(LNode));
	/*----------------array stack test-------------------------*/
	/*for (int i = 0; i < 10; i++)
	{
		array_stack_push(Array_Stack1, ASTop1, i);
	}
	for (int i = 0; i < 10; i++)
	{
		temp = array_stack_pop(Array_Stack1, ASTop1);
		cout << "The " << i << " th output item is:" << temp << endl;
	}
	*/
	/*----------------array stack test-------------------------*/
	/*--------------------linked stack test--------------------*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << "Please input the inserting item:"; cin >> temp;
		linked_stack_push(linked_stack_head, temp);
	}
	cout << "INPUT OVER, START POPING..." << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "The " << i << " th item is:" << linked_stack_pop(linked_stack_head) << endl;
	}

	/*--------------------linked stack test--------------------*/

	/*------------------midfix to PostFIx (stack)--------------*/
	char input[MAXSIZE], output[MAXSIZE];
	int top2 = -1;
	int i = 0;
	cout << "input expression: "; cin >> input;
	Infix_To_Postfix(input, output);
	while (output[i] != '\0')
	{
		cprint(output[i++]);
	}
}
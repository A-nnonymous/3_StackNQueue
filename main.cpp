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

	/*------------------infix to postfix (stack)--------------*/
	/*char input[MAXSIZE], output[MAXSIZE];
	cout << "input expression: "; cin >> input;
	Infix_To_Postfix(input, output);
	cout << "The positfix exp is: " << output << endl;

	/*-------------------infix to prefix (stack)------------------------*/
	/*char input[MAXSIZE], output[MAXSIZE];
	cout << "input expression: "; cin >> input;
	Infix_To_Prefix(input, output);
	cout << "The prefix exp is: " << output << endl;

	/*--------------equivalent proving(FALSE)------------*/
	char input[MAXSIZE], prefix[MAXSIZE], postfix[MAXSIZE];
	char quasi_prefix[MAXSIZE];
	int input_length;
	cout << "input expression: "; cin >> input;
	input_length = get_clength(input);
	Infix_To_Prefix(input, prefix);
	Infix_To_Postfix(input, postfix);
	cout << "\nFormal prefix exp: " << prefix << endl;
	cout << "\nFormal postfix exp: " << postfix << endl;
	charray_reverse(input, input_length);
	Infix_To_Postfix(input, quasi_prefix);
	charray_reverse(quasi_prefix, get_clength(quasi_prefix));
	cout << "\nQuasi prefix exp:" << quasi_prefix << endl;
}
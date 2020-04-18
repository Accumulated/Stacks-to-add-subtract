//============================================================================
// Name        : stack.cpp
// Author      : newname
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;


// Just carry my extra baby
int Carry = 0;


// By desgin there are 1st, 2nd and Final result stacks
int number_of_arguments = 0;

// Strings For Integer part
static string argv1 = "";
static string argv2 = "";

// Strings for decimal part
static string argv3 = "";
static string argv4 = "";


						/* 		User data is saved 		*/

// Getting user's strings
void Fetch_string_from_user(string arg1, string arg2)
{
	unsigned int i = 0;
	int size = 0;

	argv3 = ".";
	argv4 = ".";

	// Divide and concur the First string
	stringstream ss(arg1);
	string word;
	while(std:: getline(ss, word, '.'))
	{
		if(i == 0)
			argv1 = word;
		else
			argv3 += word;
		i++;
	}

	// Divide and concur the second string
	stringstream ss2(arg2);
	string word2;

	i = 0;
	while(std:: getline(ss2, word2, '.'))
	{
		if(i == 0)
			argv2 = word2;
		else
			argv4 += word2;
		i++;
	}

	// Dot found
	if(arg1.find(".")!= string::npos || arg2.find(".")!= string::npos)
	{
		if(argv3.size() > argv4.size())
		{
			// Get the size difference
			size = argv3.size() - argv4.size();
			for(int i = 0; i < size; i++)
				argv4 += '0';
		}
		else if(argv3.size() < argv4.size())
		{
			size = -argv3.size() + argv4.size();
			for(int i = 0; i < size; i++)
				argv3 += '0';
		}
		else;

	}
	argv1 += argv3;
	argv2 += argv4;

}

						/* Starting the Party of stacks	*/

// Constructor
StackLinkedListClass :: StackLinkedListClass()
{
	// Empty list has NULL head
	head = NULL;
	Stack_size = 0;
	Insertion_helper();
}


// Insert strings in memory, depending on occuarance
void StackLinkedListClass:: Insertion_helper()
{
	unsigned int i = 0;

	number_of_arguments++;

	// First variable, pushed in its own stack
	if(number_of_arguments == 1)
	{
		i = 0;
		Insertion_helper_even_more(1);

		// Accumulate the first stack
		while (i < argv1.size())
		{
			push(argv1[i]);
			i++;
		}
	}

	// Second Variable pushed in its own stack
	if(number_of_arguments == 2)
	{
		i = 0;
		Insertion_helper_even_more(2);

		// Accumulate the second stack
		while (i < argv2.size())
		{
			push(argv2[i]);
			i++;
		}
	}

	// WARNING:: This is the result stack, move carefully
	if(number_of_arguments == 3)
	{
		// WARNING:: EXECUTING RESULTANT FUNCTION
		// The call is from outside, not from inside
	}
}


// Just get the line you need to insert into the stack
std:: string StackLinkedListClass:: Insertion_helper_even_more(int choose_a_string_to_return)
{
	switch(choose_a_string_to_return)
	{
		case 1:
			return argv1;
			break;

		case 2:
			return argv2;
			break;

		default:
			break;
	}
	return "Not possible";
}


// Push items in the list
void StackLinkedListClass :: push(SET item)
{
	node *tmp = new node;
	if(!tmp)
		cout << "Error allocating new node\n";

	else
	{
		tmp -> data = item;
		tmp -> next = head;
		head = tmp;
		Stack_size++;
	}
}


// Pop items and delete them after popped
SET StackLinkedListClass:: pop()
{
	SET returned_value = 0;

	// Show me the head
	if(head == NULL)
	{
		//cout << "No more data to print\n";
		return 0;
	}

	else
	{
		//cout << head -> data << " is the head data\n";
		returned_value = (head -> data) % 0x30;

		// Define tmp variable to hold the next address in the head
		node *tmp = NULL;

		// Save the next address to be able to hold the list
		tmp = head -> next;

		delete head;
		Stack_size--;

		head = tmp;
	}

	return returned_value;
}


// Check for empty stack
bool StackLinkedListClass:: isempty()
{
	// True this is an empty stack
	if(head == NULL)
		return true;
	return false;
}


// Get stack size to operate on
int StackLinkedListClass:: Stack_Size()
{
	return Stack_size;
}


void StackLinkedListClass:: StackResults_Accumulated(StackLinkedListClass &c1, StackLinkedListClass &c2)
{
	int number = 0, operating_size = 0;

	SET buff1 = 0, buff2 = 0;

	// Consider different sizes to be the general case
	if(c1.Stack_Size() >= c2.Stack_Size())
		operating_size = c1.Stack_Size();
	else
		operating_size = c2.Stack_Size();

	// Iterate over the largest stack size
	while(operating_size > 0)
	{
		buff1 = c1.pop();
		buff2 = c2.pop();
		if(buff1 == '.' % 0x30 || buff2 == '.' % 0x30)
		{
			operating_size--;
			push('.');

		}

		else
		{
			number = buff1 + buff2 + Carry;

			if(number >= 10)
			{
				Carry = 1;
				number -= 10;
			}

			else
				Carry = 0;

			operating_size--;
			push(number);
		}
	}

	if(Carry == 1)
		push(1);
	Carry = 0;

	while(Stack_Size() > 0)
	{
		buff1 = pop();
		if(buff1 == '.')
			cout << '.';
		else
			cout << buff1;
	}


}


void StackLinkedListClass:: StackResults_Accumulated_Subtraction(StackLinkedListClass &c1, StackLinkedListClass &c2)
{
	int number = 0, operating_size = 0;

	SET buff1 = 0, buff2 = 0;

	// Consider different sizes to be the general case
	if(c1.Stack_Size() >= c2.Stack_Size())
		operating_size = c1.Stack_Size();
	else
		operating_size = c2.Stack_Size();

	// Iterate over the largest stack size
	while(operating_size > 0)
	{
		buff1 = c1.pop();
		buff2 = c2.pop();

		if(buff1 == '.' % 0x30 || buff2 == '.' % 0x30)
		{
			push('.');
		}

		else
		{
			//if(buff1 == 0);
			//else
				buff1 += Carry ;
				Carry = 0;

			if(buff1 >= buff2)
				number = buff1 - buff2;

			else
			{
				buff1 += 10;
				Carry = -1;
				number = buff1 - buff2;
			}

			push(number);
		}

		operating_size--;
	}

	if(Carry == -1)
		//push(0);
	Carry = 0;

	while(Stack_Size() > 0)
	{
		buff1 = pop();
		if(buff1 == '.')
			cout << '.';
		else
			cout << buff1;
	}


}

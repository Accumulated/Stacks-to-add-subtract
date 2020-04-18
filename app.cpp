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


bool Check_My_String(string str);
void String_Divide_And_Qnc(string str);


// Dummy variables just to fetch from user and supply to right operation
static string str1 = "";
static string str2 = "";
static string operation = "";

// This only rises when an operation is indicated
bool op_flag = false;
int dot_flag = 0;


int main(int argc, char *argv[])
{

	// Check for number of argument to be exact of 2
	if(argc != 2)
	{
		cout << "Incorrect number of arguments\n";
		return 1;
	}

	// Check for user's input
	if(!Check_My_String(argv[1]))
	{
		// Invalid string causes function to return false
		cout << "Invalid Input\n";
		return 1;
	}

	// Start dividing the string into 2
	String_Divide_And_Qnc(argv[1]);

	//string s1 = "5.505";
	//string s2 = "4.505";
	//string operation = "+";

	cout << "Result= ";

	Fetch_string_from_user(str1, str2);

	StackLinkedListClass First_operand_data;
	StackLinkedListClass Second_operand_data;
	StackLinkedListClass Result_data;

	if(operation == "+")
		Result_data.StackResults_Accumulated(First_operand_data, Second_operand_data);
	else
		Result_data.StackResults_Accumulated_Subtraction(First_operand_data, Second_operand_data);


	return 0;
}


// Gets called once in the beginning
bool Check_My_String(string str)
{

	for(int i = 0; i < str.length(); i++)
	{
		// Number or +- operations only
		if((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-' || str[i] == '+')
		{
			// Operation checker
			if(str[i] == '-' || str[i] == '+')
			{
				// Multiple operations indicated, exit
				if(op_flag)
					return false;

				op_flag = true;

				// Get Operation
				if(str[i] == '-')
					operation = "-";
				else
					operation = "+";
			}

			// Dot checker
			if(str[i] == '.')
			{
				// By design; First time is #1
				dot_flag++;

				// 3 dots indicated, exit
				if(dot_flag == 3)
					return false;
			}

		}
		else
		{
			return false;
		}
	}

	// It's Okay :"D
	return true;
}

// Get the strings separated
void String_Divide_And_Qnc(string str)
{
	// Initialize ss to read the whole string for further manipulation
	stringstream ss(str);
	string word = "";

	// Get a word from the buffered string
	while(std:: getline(ss, word, '+'))
	{
		stringstream buff(word);
		string buffe;

		while(std:: getline(buff, buffe, '-'))
		{
			// Empty string deserves a line indeed :"D
			if(str1 == "")
				str1 = buffe;
			else
				str2 = buffe;
		}
	}
}




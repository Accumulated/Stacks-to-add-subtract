/*
 * stack.h
 *
 *  Created on: Apr 7, 2020
 *      Author: newname
 */

#ifndef STACK_H_
#define STACK_H_


// Stack element type
typedef int SET;

class StackLinkedListClass
{

	private:

		struct node;
		struct node
		{
			SET data;
			node *next;
		};

		// Pointer to the last element in the stack
		node *head;
		int Stack_size;

	public:

		// Constructor
		StackLinkedListClass();

		// Main operations
		void push(SET item);
		SET pop();
		void StackResults_Accumulated(StackLinkedListClass &c1, StackLinkedListClass &c2);
		void StackResults_Accumulated_Subtraction(StackLinkedListClass &c1, StackLinkedListClass &c2);
		int Stack_Size(void);
		void Insertion_helper();
		std:: string Insertion_helper_even_more(int choose_a_string_to_return);


		// Side operations
		bool isempty();
};

void Fetch_string_from_user(std::string arg1, std::string arg2);

#endif /* STACK_H_ */

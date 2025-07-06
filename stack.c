/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */
 
#include <stdio.h>
#include "stack.h"

/**
* This function initializes the stack by setting its top index to -1,
* indicating that the stack is empty and ready to accept elements.
*
* @param s Pointer to the Stack structure
*/
void CREATE(Stack *s)
{
	s->top = -1;
}

/**
* This function checks if the stack is already full 
* and stops any more elements from being pushed onto it.
*
* @param s Pointer to the Stack structure
* @return 1 if full, 0 otherwise
*/
int ISFULL(Stack *s)
{
	return s->top == MAX_STACK_SIZE - 1;
}

/**
* This function checks if the stack is empty 
* and confirms there are no elements to pop or view.
*
* @param s Pointer to the Stack structure
* @return 1 if empty, 0 otherwise
*/
int ISEMPTY(Stack *s)
{
	return s->top == -1;
}

/**
* This function pushes a Point element onto the stack.
* It prints an error if stack is full.
*
* @param s Pointer to the Stack structure
* @param elem Point element to be added to the stack
*/
void PUSH(Stack *s, Point elem)
{
	if (ISFULL(s))
	{
		printf("Stack is full and can no longer accept elements or it will cause overflow.\n"); 
	}
	else
	{
		// Increment top before storing the element
		// (e.g., if top is 0, it becomes 1 before storing the element)
		s->data[++(s->top)] = elem;
	}
}

/**
* This function pops and returns the top element of the stack.
* It prints an error message if the stack is empty 
* and returns a Point (-1.0, -1.0) to indicate an error state.
*
* @param s Pointer to the Stack structure
* @return Top Point if available, or error point otherwise (empty).
*/
Point POP(Stack *s)
{
	if (ISEMPTY(s))
	{
		printf("Stack is empty and can not pop elements or it will cause underflow.\n");
		Point errorPoint = {-1.0, -1.0}; //indicate error
		return errorPoint;
	}
	else
	{
		// return current top element, then decrement s->top to remove it from the stack
		return s->data[(s->top)--]; 
	}
}

/**
* This function returns the top element of the stack without removing it.
* It prints an error message if the stack is empty 
* and returns a Point (-1.0, -1.0) to indicate an error state.
*
* @param s Pointer to the Stack structure
* @return Top Point if available, or error point otherwise (empty).
*/
Point TOP(Stack *s)
{
	if (ISEMPTY(s))
	{
		printf("Stack is empty.\n"); 
		Point errorPoint = {-1.0, -1.0}; //indicate error
		return errorPoint;
	}
	else
	{
		// Return the current top element 
		return s->data[s->top];
	}
}

/**
* This function returns the element just below the top of the stack.
* It prints an error message if the stack does not have enough elements
* and returns a Point (-1.0, -1.0) to indicate an error state.
*
* @param s Pointer to the Stack structure
* @return The next-to-top Point if available, or error point otherwise.
*/
Point NEXTTOTOP(Stack *s)
{
        if (s->top < 1) //Less than 2 elements in the stack
	{
		printf("Stack does not have enough elements.\n"); 
		Point errorPoint = {-1.0, -1.0}; //indicate error
		return errorPoint;
	}
	else
	{
		// Return the element below the top of the stack
		return s->data[s->top - 1];
	}
}






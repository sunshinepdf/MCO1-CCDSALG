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

void CREATE(Stack *s)
{
	s->top = -1;
}

int ISFULL(Stack *s)
{
	return s->top == MAX_STACK_SIZE - 1;
}

int ISEMPTY(Stack *s)
{
	return s->top == -1;
}

void PUSH(Stack *s, Point elem)
{
	if (ISFULL(s))
	{
		printf("Stack is full and can no longer accept elements or it will cause overflow"); //not sure if i should use printf or fprintf
	}
	else
	{
		s->data[++(s->top)] = elem; //++(s->top) is pre-increment so like if top is 0 then it will increment it to 1
	}
}

Point POP(Stack *s)
{
	if (ISEMPTY(s))
	{
		printf("Stack is empty and can not pop elements or it will cause underflow"); //not sure if i should use printf or fprintf
	}
	else
	{
		return s->data[(s->top)--];
	}
}

Point TOP(Stack *s)
{
	if (ISEMPTY(s))
	{
		printf("Stack is empty"); //not sure if i should use printf or fprintf
	}
	else
	{
		return s->data[s->top];
	}
}

Point NEXTTOTOP(Stack *s)
{
	if (ISEMPTY(s))
	{
		printf("stack is empty"); //not sure if i should use printf or fprintf
	}
	else
	{
		return s->data[s->top - 1];
	}
}






/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#ifndef STACK_H
#define STACK_H
#define MAX_STACK_SIZE 32768 // 2^15 elements

/** 
 * This structure is for the x and y coordinate of a point in the stack.
 */
typedef struct 
{
    double x;
    double y;
} Point;

/** 
 * This structure is for the point array where each coordinate will be stored. It also has top for the stack.
 */
typedef struct 
{
    Point data[MAX_STACK_SIZE];
    int top;
} Stack;

void CREATE(Stack *s);
int ISFULL(Stack *s);
int ISEMPTY(Stack *s);
void PUSH(Stack *s, Point elem);
Point POP(Stack *s);
Point TOP(Stack *s);
Point NEXTTOTOP(Stack *s);

#endif
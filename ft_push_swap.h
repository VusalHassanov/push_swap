#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

#include "lib_ft/libft.h"

typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

void initStack(Stack* stack);
void push(Stack* stack, int value);
void pop(Stack* stack);
int isEmpty(Stack* stack);
void rotate(Stack* stack);
void r_rotate(Stack* stack);



#endif
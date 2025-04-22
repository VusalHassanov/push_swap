#include "ft_push_swap.h"

void push(Stack* stack, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        write(1, "Memory allocation failed", 24);
        return 1;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}
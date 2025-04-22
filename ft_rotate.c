#include "ft_push_swap.h"

void rotate(Stack* stack){
    Node* old_top;
    Node* current;

    if(stack->top == NULL || stack->top->next == NULL)
        return;
    old_top = stack->top;
    stack->top = stack->top->next;
    old_top->next = NULL;
    current = stack->top;
    while(current->next != NULL)
        current = current->next;
    current->next = old_top;
}
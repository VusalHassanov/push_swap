#include "ft_push_swap.h"

void r_rotate(Stack* stack){
    Node* new_end;
    Node* last;

    if(stack->top == NULL || stack->top->next == NULL)
        return;
    new_end = stack->top;
    while(new_end->next->next != NULL)
        new_end = new_end->next;
    last = new_end->next;
    last->next = stack->top;
    stack->top = last;
    new_end->next = NULL;
}
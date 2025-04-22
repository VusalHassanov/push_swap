#include "ft_push_swap.h"

void initStack(Stack* stack){
    Node* current;
    Node* temp;

    if(stack->top != NULL){
        current = stack->top;
        while(current != NULL){
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    stack->top = NULL;
}

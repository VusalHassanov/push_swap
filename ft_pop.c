#include "ft_push_swap.h"

void pop(Stack* stack){
    if(stack->top == NULL){
        write(1, "Stack underflow !", 17);
        return 1;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}
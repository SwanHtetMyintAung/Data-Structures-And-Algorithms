#include "stdio.h"
#include "stdlib.h"
#define MAX_DATA 10

struct Stack{
    int data[10];
    int top;//to point the data
};

void stack_initialize(struct Stack* stack){
    stack->top = -1;
}

int stack_check_empty(int top){
    return (top < 0 );
}
int stack_check_full(int top){
    return (top == (MAX_DATA-1));
}

void stack_push(struct Stack* stack , int data){
    //check if the stack is full
    if(stack_check_full(stack->top)){
        printf("The Stack Is Full!\n");
        exit(-1);
    }
    //will work if there's space in the stack
    stack->data[++(stack->top)] = data;
}
int stack_pop(struct Stack* stack){
    //check if the stack is empty
    if(stack_check_empty(stack->top)){
        printf("The Stack Is Empty!\n");
        exit(-1);
    }
    return stack->data[stack->top--];
}
int stack_peek(struct Stack* stack){
    //check if the stack is empty
    if(stack_check_empty(stack->top)){
        printf("The Stack Is Empty!\n");
        exit(-1);
    }
    return stack->data[stack->top];
}
void stack_log(struct Stack* stack){
    //check if the stack is empty
    if(stack_check_empty(stack->top)){
        printf("The Stack Is Empty!\n");
        exit(-1);
    }
    int i;
    printf("Data:\n");
    for(i = stack->top;i>=0;i--){
        printf("%d\n",stack->data[i]);
    }
    printf("Done!\n");
}
int main(){
    struct Stack stack;
    
    stack_initialize(&stack);
    stack_push(&stack,10);
    stack_push(&stack,20);
    stack_push(&stack,30);
    
    printf("Popped:%d\n",stack_pop(&stack));
    printf("peeked:%d\n",stack_peek(&stack));

    stack_push(&stack,50);
    stack_push(&stack,60);
    stack_push(&stack,70);

    printf("Popped:%d\n",stack_pop(&stack));
    printf("peeked:%d\n",stack_peek(&stack));

    stack_log(&stack);
    return 0;
}
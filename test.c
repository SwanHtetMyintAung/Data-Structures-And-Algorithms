#include<stdio.h>
#include<stdlib.h>
#include"loosyGoose.h"

int main(){
    //for testing stack
    // struct Stack stack;
    
    // stack_initialize(&stack);
    // stack_push(&stack,10);
    // stack_push(&stack,20);
    // stack_push(&stack,30);
    
    // printf("Popped:%d\n",stack_pop(&stack));
    // printf("peeked:%d\n",stack_peek(&stack));

    // stack_push(&stack,50);
    // stack_push(&stack,60);
    // stack_push(&stack,70);

    // printf("Popped:%d\n",stack_pop(&stack));
    // printf("peeked:%d\n",stack_peek(&stack));

    // stack_log(&stack);


    //testing link list
    struct Link_List* head = NULL;
    ll_push(&head,10);
    ll_append(&head,20);
    ll_push(&head,30);
    ll_show_all_node(head);
    ll_insert_after(&head,10,40);
    ll_show_all_node(head);
    ll_delete_node(&head,20);
    ll_show_all_node(head);

    

    return 0;
}

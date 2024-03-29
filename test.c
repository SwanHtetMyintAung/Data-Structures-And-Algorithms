#include<stdio.h>
#include<stdlib.h>
#include"loosyGoose.h"

int main(){
    /****************8for testing stack*****************/
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


    /*********************testing link list******************/
    // struct Link_List* head = NULL;
    // ll_push(&head,10);
    // ll_append(&head,20);
    // ll_push(&head,30);
    // ll_show_all_node(head);
    // ll_insert_after(&head,10,40);
    // ll_show_all_node(head);
    // ll_delete_node(&head,20);
    // ll_show_all_node(head);

    /**********************testing stack with link list **********************/ 
    // struct Stack_Linklist* stack = (struct Stack_Linklist*)malloc(sizeof(struct Stack_Linklist));
    // stack_ll_initialize(stack);
    // stack_ll_push(stack,10);
    // printf("peek:%d\n",stack_ll_peek(stack));
    // stack_ll_push(stack,20);
    // printf("peek:%d\n",stack_ll_peek(stack));
    // stack_ll_pop(stack);
    // printf("peek:%d\n",stack_ll_peek(stack));
    // stack_ll_push(stack,30);
    // printf("peek:%d\n",stack_ll_peek(stack));
    /*note:
        since this stack use the linklist to store data.
        you can re-use the function from the link list section .
        just treate the "top" as head 
    */
    //ll_show_all_node(stack->top);
    //ll_append(&(stack->top),50);
    //ll_show_all_node(stack->top);

    /**************Testing BST*******************/
    struct Tree_Node* root;

    root = insert_tree_node(root,10);
    root = insert_tree_node(root,20);
    root = insert_tree_node(root,30);
    root = insert_tree_node(root,25);
    root = insert_tree_node(root,9);

    printf("Inorder traversal before deleting:");
    inorderTraversal(root);
    printf("\n");

    root = delete_tree_node(root,10);

    printf("Inorder traversal After deleting 10:");
    inorderTraversal(root);
    printf("\n");

    
    return 0;
}

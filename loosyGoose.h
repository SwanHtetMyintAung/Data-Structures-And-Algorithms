#ifndef LOOSYGOOSE_H
#define LOOSYGOOSE_H
#include <stdio.h>
#include <stdlib.h>
#define  MAX_DATA 10

struct Stack{
    int data[10];
    int top;//to point the data
};
struct Link_List{
    int data;
    struct Link_List* next;
};
//stack
void stack_initialize(struct Stack* stack);
void stack_push(struct Stack* stack , int data);
int stack_pop(struct Stack* stack);
int stack_peek(struct Stack* stack);
void stack_log(struct Stack* stack);
int stack_check_empty(int top);
int stack_check_full(int top);
//link list
struct Link_List* ll_create_node(int number);
void ll_push(struct Link_List** head ,int data);
void ll_append(struct Link_List** head , int data);
void ll_insert_after(struct Link_List** head,int target,int data);
void ll_delete_node(struct Link_List** head , int target);
void ll_show_all_node(struct Link_List* head);


//stack
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

//link list 
struct Link_List* ll_create_node(int number){
    struct Link_List* node = (struct Link_List*)malloc(sizeof(struct Link_List));
    node->data  = number;
    node->next = NULL;

    return node;
}
//insert a node to the end
void ll_push(struct Link_List** head ,int data){
    //create a new node
    struct Link_List* newNode = ll_create_node(data);
    //if there's no prior nodes , make this new node the first
    if((*head)==NULL){
        (*head) = newNode;
        return;
    }
    //if there's already nodes
    struct Link_List* temp = (*head);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode; 
}
//insert a node to the beginning
void ll_append(struct Link_List **head , int data){
    struct Link_List* newNode = ll_create_node(data);
    newNode->next = (*head);
    (*head) = newNode;
}
void ll_insert_after(struct Link_List **head,int target,int data){
    struct Link_List* newNode = ll_create_node(data);

    //if no node exist
    if((*head)==NULL){
        (*head) = newNode;
    }
    struct Link_List* temp , *prev;
    temp = (*head);
    //data didn't match AND still more nodes in the link
    while(temp->next != NULL && temp->data != target){
        prev = temp;
        temp = temp->next;
    }
    //if we found the node
    if(temp->data == target){
        newNode->next =temp->next;
        temp->next = newNode;
    }else{
        //this will trigger if we didn't found the node
        //current node will be linked to the last
        temp->next = newNode;
    }
}
void ll_delete_node(struct Link_List** head , int target){
    struct Link_List *temp,*prev;
    temp = (*head);
    if(temp == NULL){
        printf("There's no Nodes On The List!\n");
        return;
    }
    if((*head)->data == target){
        (*head) = (*head)->next;
        return;
    }
    //find the node that is to be deleted
    while(temp->next != NULL && temp->data != target){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("There's No Such Data!\n");
        return;
    }

    prev->next = temp->next;
}
void ll_show_all_node(struct Link_List* head){
    if(head == NULL){
        printf("There's no Nodes On The List!\n");
        return;
    }
    printf("Printing Data:\n");
    while(head != NULL){
        printf("%d\n",head->data);
        head = head->next;
    }
    printf("Printing Done!\n");

}


#endif
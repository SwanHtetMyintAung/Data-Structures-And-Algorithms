#include "stdio.h"
#include "stdlib.h"

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
void showAllNodes(struct Node* head){
    if(head == NULL){
        printf("There is No Node To show!\n");
    }
    while(head != NULL){
        printf("data:%d\n",head->data);
        head = head->next;
    }
}
struct Node* createNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
//insert a node at the beginning of the linkList
void push(struct Node** head , int number){
    struct Node* newNode = createNode(number);
    (*head)->prev = newNode;
    newNode->next = (*head);
    (*head) = newNode;
}
//insert a node at the end of the chain/linklist
void append(struct Node** head, int number){
    struct Node* newNode = createNode(number);
    if((*head)==NULL){
        (*head) = newNode;
        return;
    }
    struct Node* temp = (*head);
    //search the last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
//insert after the node with the the same data
void insertAfter(struct Node** head,int target,int number){
    struct Node* newNode = createNode(number);
    if((*head)==NULL){
        (*head) = newNode;
        return;
    }
    struct Node *temp = (*head);
    while(temp->next != NULL && temp->data != target){
        temp = temp->next;
    }
    //this will be the last node on list we if couldn't find the data
    //else this will the node with the data we wanted
    if(temp->next == NULL){
        newNode->prev = temp;
        temp->next = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;
}
//delete a node with the same data
void delete(struct Node** head, int number){
    struct Node *temp,*prevNode;
    temp = (*head);
    if(temp == NULL){
        printf("There's no Nodes On The List!\n");
        return;
    }
    //finding the node 
    while(temp->data != number){
        prevNode = temp;
        temp = temp->next;
    }
    if(temp == NULL)return;
    //linking the nodes
        
    prevNode->next = temp->next;
    temp->next->prev = prevNode;
    free(temp);

}
void main(){
    struct Node* head;
    append(&head,10);
    push(&head,20);
    append(&head,5);
    append(&head,50);
    insertAfter(&head,10,101);
    showAllNodes(head);
    printf("After Deleting\n");
    delete(&head,10);
    insertAfter(&head,123,99);
    showAllNodes(head);
    
}
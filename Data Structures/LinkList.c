#include "stdio.h"
#include "stdlib.h"

struct node{
    int value;
    struct node* next;
};

struct node *head = NULL;
void createNodeAtFirst(int number){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = number;
    newNode->next = head;
    head = newNode;
}
void createNodeAtLast(int number){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = number;

    struct node *cNode = head;
    //if there is no first node
    if(cNode == NULL){
        head = newNode;
        return;
    }

    while(cNode->next != NULL){
        cNode = cNode->next;
    }
    cNode->next = newNode;

}
void printAllNode(){
    struct node* currentNode = head;

    while(currentNode != NULL){
        printf("value:%d\n",currentNode->value);
        currentNode = currentNode->next;
    }
}
void deleteNode(int key){
    struct node *currentNode = head , *prev;
    if(currentNode != NULL && currentNode->value == key){
        head = head->next;
        return;
    }
    while(currentNode != NULL && currentNode->value != key){
        prev = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == NULL)return;

    prev->next = currentNode->next;
}
int main(){
    createNodeAtLast(1);
    createNodeAtLast(2);
    createNodeAtLast(3);
    createNodeAtFirst(4);
    createNodeAtFirst(5);
    printAllNode();
    printf("After Removing Node\n");
    deleteNode(2);
    deleteNode(4);
    printAllNode();
    return 0;
}
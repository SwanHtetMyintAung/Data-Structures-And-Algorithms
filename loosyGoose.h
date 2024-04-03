#ifndef LOOSYGOOSE_H
#define LOOSYGOOSE_H
#include <stdio.h>
#include <stdlib.h>
#define  MAX_DATA 10
#define QUEUE_MAX 10

struct Stack{
    int data[10];
    int top;//to point the data
};
struct Link_List{
    int data;
    struct Link_List* next;
};
struct Stack_Linklist{
    struct Link_List* top;
};
struct Tree_Node{
    int data;
    struct Tree_Node *left;
    struct Tree_Node *right;

};
struct queue{
    int collection[QUEUE_MAX];
    //rear will point which index to insert the data
    int rear;
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
//stack with link list
int stack_ll_is_empty(struct Stack_Linklist *stack);
void stack_ll_initialize(struct Stack_Linklist* stack);
void stack_ll_push(struct Stack_Linklist *stack , int data);
//binary search tree
void inorderTraversal(struct Tree_Node* root);
struct Tree_Node* create_tree_node(int data);
struct Tree_Node* insert_tree_node(struct Tree_Node* root , int data);
struct Tree_Node* find_min_tree_node(struct Tree_Node* root);
struct Tree_Node* delete_tree_node(struct Tree_Node* root,int data);
//queue
void queue_start(struct queue* queue);
void enqueue(struct queue* queue , int data);
void dequeue(struct queue* queue);
void queue_print_all(struct queue* queue);

//*************************stack
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

//***********************link list 
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

//************************stack with linklist
int stack_ll_is_empty(struct Stack_Linklist *stack){
    return (stack->top == NULL);
}
void stack_ll_initialize(struct Stack_Linklist* stack){
    stack->top = NULL;
}
void stack_ll_push(struct Stack_Linklist *stack , int data){
    struct Link_List* newNode = ll_create_node(data);
    newNode->next = stack->top;
    stack->top = newNode;
}
int stack_ll_pop(struct Stack_Linklist *stack ){
    if(stack_ll_is_empty(stack)){
        printf("stack is empty!\n");
        exit(1);
    }
    struct Link_List *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
int stack_ll_peek(struct Stack_Linklist *stack){
    if(stack_ll_is_empty(stack)){
        printf("stack is empty!\n");
        exit(1);
    }
    return stack->top->data;
}

/*******************Binary Search Tree**********/

struct Tree_Node* create_tree_node(int data){
    struct Tree_Node* newNode = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
    if(!newNode){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Tree_Node* insert_tree_node(struct Tree_Node* root , int data){
    //create a new node if current one is NULL
    if(root  == NULL){
        root = create_tree_node(data);
    }else if(data <= root->data){
        //if the data is LESS (or equal) than the current node,
        //we will call the function again but the left node of current ROOT as root
        root->left = insert_tree_node(root->left,data);
    }else{
        //same but if the data is GREATER than current node
        root->right = insert_tree_node(root->right,data);
    }
    //return the node
    //this line will return the "created node" if the the first condion is met
    //until the we haven't add a new Node to the tree, 
    //this function will recursive
    return root;
}
void inorderTraversal(struct Tree_Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
//find and return a node with smallest value
struct Tree_Node* find_min_tree_node(struct Tree_Node* root){
    if(root == NULL){
        return root;
    }
    if(root->left == NULL){
        return root;
    }else{
        root->left = find_min_tree_node(root->left);
    }
}
struct Tree_Node* delete_tree_node(struct Tree_Node* root,int data){
    if(root == NULL){
        return root;
    }
    //will go to left node
    if(data < root->data){
        root->left = delete_tree_node(root->left , data);
        return root;
    //if the data was greater than current node , it will continue to the right
    }else if(data > root->data){
        root->right = delete_tree_node(root->right , data);
        return root;
    //case for if we found the data .
    //data == root->data
    }else{
        //case 1: root has NO children
        if((root->left==NULL)&&(root->right==NULL)){
            //to store the Current ROOT and delete it later
            struct Tree_Node* temp = root;
            free(temp);
            return root;
        //case 2 : root has 1 child
        }else if(root->left == NULL){
            //to store the Current ROOT and delete it later
            struct Tree_Node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }else if(root->right == NULL){
            //to store the Current ROOT and delete it later
            struct Tree_Node* temp = root;
            root = root->left;
            free(temp);
            return root;
        //case 3: root has 2 children
        }else if((root->left)&&(root->right)){
            //find the "smallest" value in the RIGHT side
                struct Tree_Node *parent =  root;
                //finding the smallest value in the right sub-tree of the root
                struct Tree_Node *child  = root->right;
                while(child->left != NULL){
                    //keep track of the parent of the child
                    parent = child;
                    //go to next "left" node if it exists
                    child = child->left;
                }
                //the "child" node we have to delete is the child of root
                //this mean , we didn't need to find the child node which lead the "parent" node
                //to be the same as starting point
                if(parent == root){
                    parent->right = child->right;
                //if we somehow managed to find the smallest node ,
                //which mean this "child" node has no "left" node 
                //but there might be "right" node ,
                //we are basically linking the 
                //"parent" of the node we have to delete and the
                //the only "child"(in this case we know it could only be the right side)
                }else{
                    parent->left = child->right;
                }
                //replace the value
                root->data = child->data;
                free(child);
                return root;
        }

    }
}
//************************* queue
void queue_start(struct queue* queue){
    queue->rear = -1;
}
//add an element
void enqueue(struct queue* queue , int data){
    if(queue->rear >= (QUEUE_MAX-1)){
        printf("the queue is full!\n");
        return;
    }
    //increase the rear
    if(queue->rear < QUEUE_MAX) queue->rear++;
    else return;
    queue->collection[queue->rear] = data;
}
//delete the first index element
void dequeue(struct queue* queue){
    if(queue->rear == -1){
        printf("the queue is empty!\n");
        return;
    }
    int i=0;
    //if current element is not NULL and it hasn't reach the "rear"
    while(queue->collection[i] && (i <= queue->rear)){
        //assigning null to current element
        queue->collection[i] = '\0';
        //replace the current index with the next one
        queue->collection[i] = queue->collection[i+1];
        i++;
    }
    queue->rear--;
}
//print all elements in a queue
void queue_print_all(struct queue* queue){
    int i = 0;
    //work until it get to "rear"
    while(queue->collection[i] && (i <= queue->rear)){
        printf("index %d : %d\n", i-1 , queue->collection[i++]);
    }
}

#endif

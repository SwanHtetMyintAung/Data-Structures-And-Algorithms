#include<stdio.h>
#include<stdlib.h>

struct Tree_Node{
    int data;
    struct Tree_Node *left;
    struct Tree_Node *right;

};
struct Tree_Node* create_tree_node(int data){
    struct Tree_Node *newNode = (struct Tree_Node*)malloc(sizeof(struct Tree_Node));
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

int main(){
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



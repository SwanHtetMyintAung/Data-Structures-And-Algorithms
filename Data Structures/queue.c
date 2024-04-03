#include<stdio.h>
#include<stdlib.h>
#define QUEUE_MAX 10

struct queue{
    int collection[QUEUE_MAX];
    //rear will point which index to insert the data
    int rear;
};

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




int main(){
    struct queue queue ;
    //initialize the rear 
    queue_start(&queue);

    enqueue(&queue,10);
    enqueue(&queue,20);
    enqueue(&queue,30);
    enqueue(&queue,40);
    enqueue(&queue,50);
    enqueue(&queue,60);
    enqueue(&queue,70);
    enqueue(&queue,80);
    enqueue(&queue,90);
    enqueue(&queue,100);
    //extra element to test
    enqueue(&queue,110);

    queue_print_all(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    printf("After deleting :\n");
    queue_print_all(&queue);


    return 0;
}
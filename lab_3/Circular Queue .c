        

// using extra space 
#include<stdio.h>
#include<conio.h>
#define n 5


int front = n-1, rear = n-1  , queue[n];


void enqueue( int data){
    if (front == (rear+1)%n)
    {
        printf("\nfull");
    }
    else{
        rear = (rear+1)%n;
        queue[rear] = data;
    }
}
void dequeue(){
    if(front == rear){
        printf("\nempty");
    }
    else{
        front = (front+1)%n;
        int data = queue[front];
        printf("\n %d is dequeue" ,data );
    }
}

void dispaly(){
    int i;
    printf("\n");
    for( i = (front+1)%n;i!= (rear + 1) % n;i = (i+1)%n){
        printf("%d ", queue[i]);
    }
}
int main(){
    
    enqueue(4);
    enqueue(3);
    enqueue(13);
    enqueue(5);
    enqueue(15);
    enqueue(15);

    dispaly();
    dequeue();
    dequeue();
    dequeue();
    dispaly();

    enqueue(13);
    enqueue(5);
    enqueue(15);
    enqueue(15);
    dispaly();

    
    getch();
    return 0;
}








        
        
        
     /**    
        #include<stdio.h>
        #include<stdlib.h>
        #define MAX 4
        
        int queue[MAX];
        int rear=-1;
        int front=-1;
        
        void enqueue(int data);
        void dequeue();
        void peek();
        void display();
        int isFull();
        int isEmpty();
        
        int main()
        {
                int choice,data;
                while(1)
                {
                        printf("\n1.enqueue\n");
                        printf("2.dequeueete\n");
                        printf("3.Display element at the front\n");
                        printf("4.Display all elements of the queue\n");
                        printf("5.Quit\n");
                        printf("\nEnter your choice : ");
                        scanf("%d",&choice);
        
                        switch(choice)
                        {
                        case 1:
                                printf("\nInput the element for adding in queue : ");
                                scanf("%d",&data);
                                enqueue(data);
                                break;
                        case 2:
                                dequeue();
                                break;
                        case 3:
                                peek();
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(1);
                        default:
                                printf("\nWrong choice\n");
                        }
                }
                return 0;
        }
        
        void enqueue(int data)
        {
                if( isFull() )
                {
                        printf("\nQueue Overflow\n");
                        
                }
                else{
                if (isEmpty()) {
                    front = 0;
                }
                        rear = (rear + 1)%MAX;
                        queue[rear]=data ;
                }
        }
        void dequeue()
        {
                
                if( isEmpty() )
                {
                        printf("\nQueue Underflow\n");
                }
                else{
                int item = queue[front];
                if(front == rear ){
                        
                        front = -1;
                        rear = -1;               
                }
                else{
                        
                        front = (front + 1) % MAX;
                }
                printf("\ndequeued element is  %d\n",item);
                }
        }
        
        void peek()
        {
                if( isEmpty() )
                {
                        printf("\nQueue Underflow\n");
                }
                else{
                        printf("\nElement at the front is %d\n",queue[front]);
                }
        }
        
        int isEmpty()
        {
                return front==-1;
        
        }
        
        int isFull()
        {
              return front == (rear + 1)%MAX ;
        
        }
        
        void display()
        {
                int i;
                if ( isEmpty() )
                
                        printf("\nQueue is empty\n");
                else{
                        printf("\nQueue is :\n\n");
                        
                        for(i=front;i != rear;i = (i + 1) % MAX)
                        {
                           
                        printf("%d  ",queue[i]);
        
                        }
                        printf("%d\n\n", queue[i]);
        
                }   
                
        }
        
        
        
     **/   
        
        
        
        

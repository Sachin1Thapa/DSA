#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;

};
struct node *front  = NULL , *rear = NULL;

void enqueue(int data){         // similar to add at last (link list)
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if(front == NULL){
        front = n;
        rear = n;
    }
    else{
        rear->next = n;
        rear = n;
    }
}

void dequeue(){         //similar to delete at first (link list)
    if(front == NULL){
        printf("\nEmpty");
    }
    else{
        printf("\n %d is deqeued\n",front->data);
        struct node *temp = front;
        front = front->next;
        temp->next = NULL;
        free(temp);
    }
}

void display()
{
    struct node *current = front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void peek(){
    if(front == NULL){
        printf("Queue is empty");
    }
    else{
        printf("%d is at top of Queue",front->data);
    }
}

    
int main()
{
        int choice, data;
        while (1)
        {
                printf("\n1.enqueue\n");
                printf("2.dequeueete\n");
                printf("3.Display element at the front\n");
                printf("4.Display all elements of the queue\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d", &data);
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




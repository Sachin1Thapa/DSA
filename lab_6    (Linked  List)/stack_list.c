#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;

};
struct node *top = NULL;

void push( int data){       // similar to add at first (single list)
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if(top == NULL){
        top = n;
    }
    else{
        n->next = top;
        top = n;

    }

}
void pop(){                 //similar to delete at first (single list)
    if(top == NULL){
        printf("\n stack is Empty");
    }
    else{
        printf("\n %d is pop\n",top->data);
        struct node *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
}
void peek(){
    if(top == NULL){
        printf("stack is empty");
    }
    else{
        printf("%d is at top of stack",top->data);
    }
}
void display()
{
    struct node *current = top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(){  
    do
    {
        int choice ,n ;
        printf("\n 1. push \n 2. pop \n 3. peek \n 4. display");
        printf(" \n Enter the number :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be push in stack : ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            exit(1);
        }
    } while (1);

    getch();
    return 0;

}

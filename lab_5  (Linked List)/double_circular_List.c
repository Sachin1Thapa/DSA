#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void display();
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

// addition of the data (Double circular link list )
void fadd(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    if (start == NULL)
    {
        start = n;
        start->prev = start;
        start->next = start;
    }
    else
    {
        /*
        start->prev->next = n;
        n->next = start;
        n->prev = start->prev;
        start->prev = n;
        start = n;

        */

        struct node *temp = start->prev;
        n->next = start;
        start->prev = n;
        n->prev = temp;
        temp->next = n;
        start = n;
    }
}

void ladd(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    if (start == NULL)
    {
        start = n;
        start->prev = start;
        start->next = start;
    }
    else
    {
        start->prev->next = n;
        n->prev = start->prev;
        n->next = start;
        start->prev = n;
    }
}

void padd(int data, int pos)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = n;
    n->prev = n;

    struct node *temp = start;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

// deletion of the data (double circular list)

void fdel()
{

    if (start == NULL)
    {
        printf("Circular list nai chainw ");
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        start->prev = temp->prev;
        temp->prev->next = start;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

void ldel()
{

    if (start == NULL)
    {
        printf("Circular list nai chainw ");
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start->prev;
        start->prev = temp->prev;
        temp->prev->next = start;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

void pdel(int pos)
{
    if (start == NULL)
    {
        printf("there is no list");
    }
    else
    {
        int i;
        struct node *temp = start;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->prev = NULL;
        temp2->next = NULL;
        free(temp2);
    }
}

int main()
{
    fadd(2);
    fadd(0);
    fadd(0);
    fadd(0);
    fadd(-12);
    ladd(60);
    fadd(7);
    ladd(-1);
    padd(6, 3);
    padd(6, 3);
    padd(36, 5);
    padd(36, 5);
    padd(16, 4);
    padd(16, 4);

    fdel();
    fdel();
    fdel();
    fdel();

    ldel();
    ldel();
    ldel();

    pdel(2);
    pdel(2);
    pdel(3);
    pdel(3);
    display();

    getch();
    return 0;
}

void display()
{
    struct node *current = start;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != start);

    printf("\n");
}
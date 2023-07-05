#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void display();

// addition of the data in circular list

void fadd(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = n;

    if (start == NULL)
    {
        start = n;
        n->next = n;
    }

    else
    {
        struct node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        n->next = start;
        temp->next = n;
        start = n;
    }
}

void ladd(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
        n->next = n;
    }

    else
    {
        struct node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = start;
    }
}

void padd(int data, int pos)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
        n->next = n;
    }
    else
    {
        struct node *temp = start;
        int i = 1;
        for (i; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

// deletion of the data in circular list

void fdel()
{
    if (start == NULL)
    {
        printf("Empty cha list");
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start, *temp2 = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        start = temp2->next;
        temp2->next = NULL;
        free(temp2);
        temp->next = start;
    }
}

void ldel()
{
    if (start == NULL)
    {
        printf("list empty cha ");
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start;
        while (temp->next->next != start)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = start;
        temp2->next = NULL;
        free(temp2);
    }
}

void pdel(int pos)
{
    if (start == NULL)
    {
        printf("list empty cha ");
    }
    //     else if (start->next == start){
    //     free(start);
    //     start = NULL;
    // }
    else
    {
        int i = 1;
        struct node *temp = start;
        for (i; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        free(temp2);
    }
}

int main()
{
    fadd(6);
    ladd(26);
    fadd(96);
    ldel();
    ladd(8);
    fadd(56);
    fadd(36);
    ldel();
    fadd(36);
    fadd(36);
    fadd(36);
    ladd(25);
    fdel();
    ladd(-9);
    padd(99, 2);
    fdel();
    ldel();
    pdel(3);
    pdel(3);
    pdel(4);
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
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

// addition of the data (double link list )
void fadd(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    if (start == NULL)
    {
        start = n;
    }
    else
    {
        n->next = start;
        start->prev = n;
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
    }

    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void padd(int data, int pos)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    if (start == NULL)
    {
        start = n;
    }

    else
    {
        int i;
        struct node *temp = start;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next->prev = n;
        n->prev = temp;
        temp->next = n;
    }
}

//  deletion of the data (double link list)

void fdel()
{
    if (start == NULL)
    {
        printf("list nai chainw !");
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        start->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

void ldel()
{
    if (start == NULL)
    {
        printf("Mes que un Club");
    }
    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
    }

    else
    {
        struct node *temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp2);
    }
}

void pdel(int pos)
{
    if (start == NULL)
    {
        printf("MOre than a club");
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
        temp2->next->prev = temp->next;
        temp2->prev = NULL;
        temp2->next = NULL;
        free(temp2);
    }
}

int main()
{
    ladd(0);
    fadd(2);
    fdel();
    fadd(32);
    fadd(26);
    ladd(19);
    fadd(-2);
    ladd(9);
    padd(2, 3);
    padd(9, 7);
    fdel();
    pdel(2);
    display();
    fdel();
    fdel();
    pdel(2);
    display();

    getch();
    return 0;
}

void display()
{
    struct node *current = start;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

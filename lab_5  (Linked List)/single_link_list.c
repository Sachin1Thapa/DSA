#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

// addition of element

void fadd(int data) // add data at begining
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        n->next = start;
        start = n;
    }
}

void ladd(int data) // add data at last
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
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
    }
}

void padd(int data, int pos)
{ // add at position
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    struct node *temp = start;
    int i = 1;
    for (i; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

// deletion of element

void fdel()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        temp->next = NULL;
        free(temp);
    }
}

void ldel() // delete at last
{
    if (start == NULL)
    {
        printf("Empty list ");
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
        free(temp->next);
        temp->next = NULL;
    }
}

void pdel(int pos)
{
    if (start == NULL)
    {
        printf("Empty ");
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
        temp->next = temp->next->next;
        temp2->next = NULL;
        free(temp2);
    }
}

int main()
{

    fadd(6);
    fadd(67);
    ladd(9);
    ladd(-79);
    padd(15, 3);
    padd(1, 4);
    padd(105, 5);
    ldel();
    ldel();
    ldel();
    fdel();
    ldel();
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

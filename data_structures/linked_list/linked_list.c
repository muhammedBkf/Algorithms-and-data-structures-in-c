#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List *initialization()
{
    List *new = malloc(sizeof(struct linked_list));
    new->head = NULL;
    new->tail = NULL;
    new->nodeNumber = 0;
}
List *create(int number)
{
    List *list = malloc(sizeof(List));
    node *new = malloc(sizeof(node));
    printf("The value : ");
    scanf("%d", &new->data);
    list->head = new;
    node *temp = list->head;
    for (number; number > 1; number--)
    {
        node *new = malloc(sizeof(node));
        printf("The value : ");
        scanf("%d", &new->data);
        temp->next = new;
        temp = new;
    }
    list->tail = temp;
    list->nodeNumber = number;
}
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void read(List *list)
{
    node *i = list->head;
    if (i == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        while (i != NULL)
        {
            printf("%d ", i->data);
            i = i->next;
        }
    }
}
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void insert_beginnig(List *list, int number)
{
    node *new = malloc(sizeof(node));
    new->data = number;
    new->next = NULL;
    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        list->head = new;
    }
    list->nodeNumber++;
}
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void insert_end(List *list, int number)
{
    node *new = malloc(sizeof(node));
    new->data = number;
    new->next = NULL;

    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        list->tail->next = new;
        list->tail = new;
    }
    list->nodeNumber++;
}
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
node *previous(List *list, node *actual)
{
    node *temp = list->head;
    node *temp1 = temp->next;
    if (temp == NULL || actual == list->head)
    {
        printf("Hello");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (temp1 != actual)
        {
            temp = temp1;
            temp1 = temp->next;
        }
        return temp;
    }
}

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

void swap(List *list, node *a, node *b)
{

    if (a == list->head)
    {
        a->next = b->next;
        b->next = a;
        list->head = b;
    }
    else if (b == list->tail)
    {
        previous(list, a)->next = b;
        b->next = a;
        a->next = NULL;
        list->tail = a;
    }
    else
    {
        previous(list, a)->next = b;
        a->next = b->next;
        b->next = a;
    }
}

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void sort(List *list)
{
    char done = 0;
    node *actual = list->head;
    node *follow = actual->next;
    if (actual == NULL)
    {
        printf("sma");
        exit(EXIT_SUCCESS);
    }
    else
    {
        while (done == 0)
        {
            done = 1;
            actual = list->head;
            follow = actual->next;
            while (follow != NULL)
            {
                if (follow->data < actual->data)
                {
                    swap(list, actual, follow);
                    done = 0;
                }
                actual = follow;
                follow = follow->next;
            }
        }
    }
}

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

void randomFill(List *list, int nodeNumber, int min, int max)
{

    node *new = malloc(sizeof(node));
    new->data = (rand() % (max - min)) + min;
    new->next = NULL;
    list->head = new;
    node *temp = list->head;
    for (nodeNumber; nodeNumber > 1; nodeNumber--)
    {
        node *new = malloc(sizeof(node));
        new->data = (rand() % (max - min)) + min;
        new->next = NULL;
        temp->next = new;
        temp = new;
    }
    list->nodeNumber = nodeNumber;
}
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void destroy(List *list)
{
    node *actual = list->head;
    node *next = NULL;

    while (actual != NULL)
    {
        next = actual->next;
        free(actual);
        actual = next;
    }
    free(list);
};
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
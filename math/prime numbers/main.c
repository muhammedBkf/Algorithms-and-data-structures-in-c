#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include <time.h>
#include <math.h>
// this function will write the contnt of a linked list in a file with '.' as a delimiter
void writeToFile(List *list)
{
    node *perm = list->head;
    FILE *fptr;
    fptr = fopen("generated.txt", "w");
    while (list->nodeNumber)
    {
        fprintf(fptr, "%d.", perm->data);
        perm = perm->next;
        list->nodeNumber--;
    }

    fclose(fptr);
}
//this function will append the content of the linked list to the end of the file
void append(List *list)
{
    node *perm = list->head;
    FILE *fptr;
    fptr = fopen("generated.txt", "a");
    while (list->nodeNumber)
    {
        fprintf(fptr, "%d.", perm->data);
        perm = perm->next;
        list->nodeNumber--;
    }
    fclose(fptr);
    destroy(list);
    list = initialization();
}
//this function will put the numbers (smaller than the root of number) contained in a file in the list nodes
void readFromFile(List *list, int number)
{
    FILE *fptr;
    fptr = fopen("prime.txt", "r");
    char c = 0;
    int num = 0;
    int i = 0;

    while (list->tail->data < sqrt(number))
    {
        num = 0;
        while ((c = fgetc(fptr)) != '.')
        {
            num = num * 10 + c - '0';
        }
        if (list->tail->data < num)
        {
            insert_end(list, num);
        }
        i++;
    }

    fclose(fptr);
}
//this function will count the prime numbers contained in a file with '.' as delimiter
int count()
{
    FILE *fptr;
    fptr = fopen("generated.txt", "r");
    char c = 0;
    int count = 0;
    while ((c = fgetc(fptr)) != EOF)
    {
        if (c == '.')
        {
            count++;
        }
    }
    return count;
}
//this function will generate a number of the form : number=6k+sign
int number(int num, int sign)
{
    if (sign == 1)
    {
        return (6 * num + 1);
    }
    else
    {
        return (6 * num - 1);
    }
}
//this function will return 1 if number is a prime number 0 if not
int isprime(int number, List *list)
{

    node *i = list->head;
    while ((i->data < (sqrt(number)) && (number % i->data != 0)))
    {
        i = i->next;
    }
    if ((i->data < (sqrt(number))) || (number % i->data == 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int checkPrime(int num, List *list)
{
    if ((num % 6 == 1) || (num % 6 == 5))
    {
        readFromFile(list, num);
        return isprime(num, list);
    }
    else
    {
        return 0;
    }
}
int main(void)
{

    List *prime = initialization();
    insert_end(prime, 2);
    insert_end(prime, 3);

    char choice = 0;
    int num;
    List *prime1 = NULL;

    do
    {
        printf("What do u want to do :\n1_Generate prime numbers to file\n2_Check if a number is a prime number\n0_Quit\nChoose one please : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("What do u want to do :\n1_Generate from file (1,000,000,000,000 is the max)\n2_generate from scratch (your hardware is the limit)\n0_Quit\nChoose one please : ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                prime1 = initialization();
                insert_end(prime1, 2);
                insert_end(prime1, 3);
                printf("enter the number n : ");
                scanf("%d", &num);
                int i = 1;
                readFromFile(prime, num);

                remove("generated.txt");

                while (number(i, 1) < num)
                {
                    if (isprime(number(i, -1), prime))
                    {

                        insert_end(prime1, number(i, -1));
                    }
                    if (isprime(number(i, 1), prime))
                    {

                        insert_end(prime1, number(i, 1));
                    }

                    if (prime1->nodeNumber > 10000)
                    {
                        append(prime1);
                    }
                    i++;
                }

                append(prime1);
                destroy(prime1);
                printf("The %d prime numbers smaller than %d are generated.\n", count(), num);
                printf("**********************************************************\n");
                break;
            case 2:
                printf("enter the number n : ");
                scanf("%d", &num);
                remove("generated.txt");
                i = 1;
                while (number(i, 1) < num)
                {
                    if (isprime(number(i, -1), prime))
                    {
                        insert_end(prime, number(i, -1));
                    }
                    if (isprime(number(i, 1), prime))
                    {
                        insert_end(prime, number(i, 1));
                    }

                    i++;
                }
                writeToFile(prime);
                printf("The %d prime numbers smaller than %d are generated.\n", count(), num);

                printf("**********************************************************\n");
                break;
            default:
                break;
            }

            break;
        case 2:
            printf("enter the number n : ");
            scanf("%d", &num);
            if (checkPrime(num, prime))
            {
                printf("%d is a prime number. \n", num);
            }
            else
            {
                printf("%d is not a prime number. \n", num);
            }
            printf("**********************************************************\n");
            break;
        default:
            break;
        }
    } while (choice);

    destroy(prime);
}
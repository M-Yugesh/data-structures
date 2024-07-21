#include <stdio.h>
#include <conio.h>  // Remove if not needed
#include <stdlib.h>   // For exit()

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int a,b[20], n, p, e, i, pos;

int main()
{
    int ch;
    char g='y';

    do
    {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display\n 6. Exit \n");
printf("\n Enter your Choice ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf(" \n Enter the correct choice:");
        }

printf("\n Do u want to continue:::");
        scanf(" %c", &g);  // Added a space before %c to consume newline properly
    }
    while(g == 'y' || g == 'Y');

    return 0;
}

void create()
{
printf("\n Enter the number of nodes ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
printf("\n Enter the Element:",i+1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
printf("\n Enter the position u want to delete::");
    scanf("%d", &pos);

    if(pos >= n)
    {
        printf("\n Invalid Location::");
        return;
    }

    for(i = pos; i < n - 1; i++)
    {
        b[i] = b[i + 1];
    }

    n--;

    printf("\n The Elements after deletion:");
    for(i = 0; i < n; i++)
    {
        printf("\t%d", b[i]);
    }
}

void search()
{
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);

    for(i = 0; i < n; i++)
    {
        if(b[i] == e)
        {
            printf("Value %d is in the %d Position\n", e, i);
            return;  // Added return to exit after finding the element
        }
    }

printf("Value %d is not in the list::", e);
}

void insert()
{
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);

    if(pos > n)
    {
        printf("\n Invalid Location::");
        return;
    }

printf("\n Enter the element to insert::\n");
    scanf("%d", &p);

    for(i = n - 1; i >= pos; i--)
    {
        b[i + 1] = b[i];
    }

    b[pos] = p;
    n++;

printf("\n The list after insertion::\n");
    display();
}

void display()
{
    printf("\n The Elements of The list ADT are:");
    for(i = 0; i < n; i++)
    {
        printf("\n");
        printf("\n%d", b[i]);
    }
    printf("\n");
}

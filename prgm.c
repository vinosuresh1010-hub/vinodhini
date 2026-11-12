
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} LIST;

LIST *head = NULL;

LIST* create(int element);
void insert();
void deletion();
void display();

int pos, opt, item;

int main()
{
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                insert();
                display();
                break;

            case 2:
                deletion();
                display();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option");
        }

    } while(1);

    return 0;
}

LIST* create(int element)
{
    LIST *newnode;

    newnode = (LIST*)malloc(sizeof(LIST));

    if(newnode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    newnode->data = element;
    newnode->next = NULL;

    return newnode;
}

void insert()
{
    int j;

    printf("Enter the item to be inserted: ");
    scanf("%d", &item);

    p = create(item);

    if(head == NULL)
    {
        head = p;
        return;
    }

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position");
        free(p);
        return;
    }

    if(pos == 1)
    {
        p->next = head;
        head = p;
    }
    else
    {
        temp = head;

        for(j = 1; j < pos-1 && temp != NULL; j++)
            temp = temp->next;

        if(temp == NULL)
        {
            printf("Invalid position");
            free(p);
            return;
        }

        p->next = temp->next;
        temp->next = p;
    }
}

void deletion()
{
    LIST *ptr, *prev;

    printf("Enter the item to be deleted: ");
    scanf("%d", &item);

    if(head == NULL)
    {
        printf("LINKED LIST IS EMPTY");
        return;
    }

    ptr = head;
    prev = NULL;

    while(ptr != NULL && ptr->data != item)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("ITEM NOT FOUND");
        return;
    }

    if(prev == NULL)
        head = head->next;
    else
        prev->next = ptr->next;

    free(ptr);
}

void display()
{
    LIST *ptr;

    if(head == NULL)
    {
        printf("\nLINKED LIST IS EMPTY");
        return;
    }

    ptr = head;

    printf("\nLinked List: ");

    while(ptr != NULL)
    {
        printf("-> %d ", ptr->data);
        ptr = ptr->next;
    }

    printf("-> NULL\n");
}

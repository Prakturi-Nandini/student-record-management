#include "student.h"

void add_record(struct student **head)
{
    struct student *newnode;
    struct student *temp;
    int roll = 1;

    newnode = malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }

    while(1)
    {
        temp = *head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if(temp == NULL)
            break;

        roll++;
    }

    newnode->rollno = roll;

    getchar();

    do
    {
        printf("Enter name: ");
        fgets(newnode->name,50,stdin);

        newnode->name[strcspn(newnode->name,"\n")] = '\0';

        if(strlen(newnode->name) == 0)
            printf("Name cannot be empty\n");

    }while(strlen(newnode->name) == 0);

    do
    {
        printf("Enter percentage: ");
        scanf("%f",&newnode->percentage);

        if(newnode->percentage < 0 ||
           newnode->percentage > 100)
        {
            printf("Enter percentage between 0 and 100\n");
        }

    }while(newnode->percentage < 0 ||
           newnode->percentage > 100);

    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Record added successfully\n");
    printf("Roll number = %d\n",roll);
}

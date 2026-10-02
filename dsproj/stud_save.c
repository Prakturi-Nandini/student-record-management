#include "student.h"

void save_records(struct student *head)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "w");

    if(fp == NULL)
    {
        printf("\nFile opening failed!");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%d %s %.2f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nStudent records saved successfully!");
}


void load_records(struct student **head)
{
    FILE *fp;
    struct student *newnode;
    struct student *temp;

    int rollno;
    char name[50];
    float percentage;
    int i;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        if(fscanf(fp, "%d %49s %f",
                  &rollno,
                  name,
                  &percentage) != 3)
        {
            break;
        }

        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("\nMemory allocation failed!");
            fclose(fp);
            return;
        }

        newnode->rollno = rollno;

        i = 0;

        while(name[i] != '\0')
        {
            newnode->name[i] = name[i];
            i++;
        }

        newnode->name[i] = '\0';

        newnode->percentage = percentage;
        newnode->next = NULL;

        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    fclose(fp);

    printf("\nStudent records loaded successfully!");
}

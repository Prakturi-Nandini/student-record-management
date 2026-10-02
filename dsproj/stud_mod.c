#include "student.h"

void update_student(struct student *temp)
{
    char name[50];
    int i, len;

    getchar();

    while(1)
    {
        printf("Enter new name: ");
        fgets(name, 50, stdin);

        /* remove newline manually */
        len = 0;
        while(name[len] != '\0')
        {
            if(name[len] == '\n')
            {
                name[len] = '\0';
                break;
            }
            len++;
        }

        /* check empty name */
        if(name[0] != '\0')
            break;

        printf("Name cannot be empty.\n");
    }

    /* copy name manually */
    i = 0;
    while(name[i] != '\0')
    {
        temp->name[i] = name[i];
        i++;
    }

    temp->name[i] = '\0';

    while(1)
    {
        printf("Enter new percentage: ");
        scanf("%f",&temp->percentage);

        if(temp->percentage >= 0 &&
           temp->percentage <= 100)
        {
            break;
        }

        printf("Invalid percentage. Enter 0 to 100.\n");
    }

    printf("Record modified successfully.\n");
}


void modify_by_roll(struct student *head)
{
    int roll;
    struct student *temp = head;

    printf("Enter roll number: ");
    scanf("%d",&roll);

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            printf("\nCurrent Details:\n");
            printf("Roll No    : %d\n",temp->rollno);
            printf("Name       : %s\n",temp->name);
            printf("Percentage : %.2f\n",temp->percentage);

            update_student(temp);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found.\n");
}


void modify_by_name(struct student *head)
{
    char name[50];
    struct student *temp;
    int count = 0;
    int roll;
    int i;
    int same;

    getchar();

    printf("Enter name: ");
    fgets(name,50,stdin);

    /* remove newline manually */
    i = 0;
    while(name[i] != '\0')
    {
        if(name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
        i++;
    }

    printf("\nMatching records:\n");
    printf("---------------------------------------------\n");

    temp = head;

    while(temp != NULL)
    {
        /* compare two strings manually */
        i = 0;
        same = 1;

        while(name[i] != '\0' || temp->name[i] != '\0')
        {
            if(name[i] != temp->name[i])
            {
                same = 0;
                break;
            }

            i++;
        }

        if(same == 1)
        {
            printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                   temp->rollno,
                   temp->name,
                   temp->percentage);

            count++;
        }

        temp = temp->next;
    }

    if(count == 0)
    {
        printf("No matching record found.\n");
        return;
    }

    printf("---------------------------------------------\n");

    printf("Enter roll number to modify: ");
    scanf("%d",&roll);

    temp = head;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            /* compare name manually again */
            i = 0;
            same = 1;

            while(name[i] != '\0' || temp->name[i] != '\0')
            {
                if(name[i] != temp->name[i])
                {
                    same = 0;
                    break;
                }

                i++;
            }

            if(same == 1)
            {
                update_student(temp);
                return;
            }

            printf("Selected roll number does not belong to this name.\n");
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found.\n");
}


void modify_by_percentage(struct student *head)
{
    float percentage;
    struct student *temp;
    int count = 0;
    int roll;

    printf("Enter percentage: ");
    scanf("%f",&percentage);

    printf("\nMatching records:\n");
    printf("---------------------------------------------\n");

    temp = head;

    while(temp != NULL)
    {
        if(temp->percentage == percentage)
        {
            printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                   temp->rollno,
                   temp->name,
                   temp->percentage);

            count++;
        }

        temp = temp->next;
    }

    if(count == 0)
    {
        printf("No matching record found.\n");
        return;
    }

    printf("---------------------------------------------\n");

    printf("Enter roll number to modify: ");
    scanf("%d",&roll);

    temp = head;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            if(temp->percentage == percentage)
            {
                update_student(temp);
                return;
            }

            printf("Selected roll number does not have that percentage.\n");
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found.\n");
}


void modify_record(struct student *head)
{
    char choice;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nEnter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    printf("Enter your choice: ");
    scanf(" %c",&choice);

    switch(choice)
    {
        case 'r':
        case 'R':
            modify_by_roll(head);
            break;

        case 'n':
        case 'N':
            modify_by_name(head);
            break;

        case 'p':
        case 'P':
            modify_by_percentage(head);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

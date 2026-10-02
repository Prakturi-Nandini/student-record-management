#include "student.h"

void sort_by_name(struct student **head)
{
    struct student *sorted = NULL;
    struct student *current;
    struct student *temp;
    int i;
    int result;

    if(*head == NULL || (*head)->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    while(*head != NULL)
    {
        current = *head;
        *head = (*head)->next;

        if(sorted == NULL)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            /* compare current name with first name */
            i = 0;
            result = 0;

            while(current->name[i] != '\0' &&
                  sorted->name[i] != '\0')
            {
                if(current->name[i] < sorted->name[i])
                {
                    result = -1;
                    break;
                }

                if(current->name[i] > sorted->name[i])
                {
                    result = 1;
                    break;
                }

                i++;
            }

            if(result == 0)
            {
                if(current->name[i] == '\0' &&
                   sorted->name[i] != '\0')
                {
                    result = -1;
                }
                else if(current->name[i] != '\0' &&
                        sorted->name[i] == '\0')
                {
                    result = 1;
                }
            }

            if(result < 0)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                temp = sorted;

                while(temp->next != NULL)
                {
                    i = 0;
                    result = 0;

                    while(current->name[i] != '\0' &&
                          temp->next->name[i] != '\0')
                    {
                        if(current->name[i] < temp->next->name[i])
                        {
                            result = -1;
                            break;
                        }

                        if(current->name[i] > temp->next->name[i])
                        {
                            result = 1;
                            break;
                        }

                        i++;
                    }

                    if(result == 0)
                    {
                        if(current->name[i] == '\0' &&
                           temp->next->name[i] != '\0')
                        {
                            result = -1;
                        }
                        else if(current->name[i] != '\0' &&
                                temp->next->name[i] == '\0')
                        {
                            result = 1;
                        }
                    }

                    if(result < 0)
                        break;

                    temp = temp->next;
                }

                current->next = temp->next;
                temp->next = current;
            }
        }
    }

    *head = sorted;

    printf("List sorted alphabetically by name.\n");
}


void sort_by_percentage(struct student **head)
{
    struct student *sorted = NULL;
    struct student *current;
    struct student *temp;

    if(*head == NULL || (*head)->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    while(*head != NULL)
    {
        current = *head;
        *head = (*head)->next;

        if(sorted == NULL ||
           current->percentage > sorted->percentage)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            temp = sorted;

            while(temp->next != NULL &&
                  temp->next->percentage >= current->percentage)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
    }

    *head = sorted;

    printf("List sorted by percentage in descending order.\n");
}


void sort_records(struct student **head)
{
    char choice;

    if(*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nN/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    printf("Enter your choice: ");
    scanf(" %c",&choice);

    switch(choice)
    {
        case 'n':
        case 'N':
            sort_by_name(head);
            break;

        case 'p':
        case 'P':
            sort_by_percentage(head);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

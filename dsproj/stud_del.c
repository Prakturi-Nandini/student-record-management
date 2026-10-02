#include "student.h"

void delete_record(struct student **head)
{
    struct student *temp, *prev;
    int rollno;
    char name[50];
    char choice;
    int i, same;
    int count;

    if(*head == NULL)
    {
        printf("\nNo student records found!");
        return;
    }

    printf("\nR/r : Enter roll number to delete");
    printf("\nN/n : Enter name to delete");
    printf("\nEnter your choice: ");
    scanf(" %c",&choice);

    /* Delete by roll number */
    if(choice == 'R' || choice == 'r')
    {
        printf("\nEnter roll number: ");
        scanf("%d",&rollno);

        temp = *head;
        prev = NULL;

        while(temp != NULL)
        {
            if(temp->rollno == rollno)
                break;

            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("\nStudent with roll number %d not found!",rollno);
            return;
        }

        if(prev == NULL)
        {
            *head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("\nStudent deleted successfully!");
    }

    /* Delete by name */
    else if(choice == 'N' || choice == 'n')
    {
        getchar();

        printf("\nEnter student name: ");
        fgets(name,50,stdin);

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

        count = 0;
        temp = *head;

        printf("\nMatching records:\n");
        printf("---------------------------------------------\n");

        while(temp != NULL)
        {
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
                printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno,
                       temp->name,
                       temp->percentage);

                count++;
            }

            temp = temp->next;
        }

        printf("---------------------------------------------\n");

        if(count == 0)
        {
            printf("Student with name %s not found!",name);
            return;
        }

        /* Select the required record using roll number */
        printf("\nEnter roll number to delete: ");
        scanf("%d",&rollno);

        temp = *head;
        prev = NULL;

        while(temp != NULL)
        {
            if(temp->rollno == rollno)
                break;

            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("\nRoll number not found!");
            return;
        }

        /* Check whether selected roll belongs to entered name */
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

        if(same == 0)
        {
            printf("\nSelected roll number does not belong to this name!");
            return;
        }

        /* Unlink node */
        if(prev == NULL)
        {
            *head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        free(temp);

        printf("\nStudent deleted successfully!");
    }

    else
    {
        printf("\nInvalid choice!");
    }
}

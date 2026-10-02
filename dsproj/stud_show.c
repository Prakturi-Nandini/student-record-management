#include "student.h"

void show_records(struct student *head)
{
    struct student *temp;

    if (head == NULL)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-30s %-12s\n",
           "Roll No.", "Name", "Percentage");
    printf("------------------------------------------------------------\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%-10d %-30s %-12.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}

#include "student.h"

void delete_all(struct student **head)
{
    struct student *temp;

    if(*head == NULL)
    {
        printf("\nNo student records available!");
        return;
    }

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }

    printf("\nAll student records deleted successfully!");
}

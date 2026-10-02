#include "student.h"

void reverse_list(struct student **head)
{
    struct student *prev;
    struct student *current;
    struct student *next;

    if(*head == NULL)
    {
        printf("\nNo student records available.");
        return;
    }

    prev = NULL;
    current = *head;

    while(current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    *head = prev;

    printf("\nList reversed successfully.");
}

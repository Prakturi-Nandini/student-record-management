#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void add_record(struct student **head);
void delete_record(struct student **head);
void show_records(struct student *head);
void modify_record(struct student *head);

void save_records(struct student *head);
void load_records(struct student **head);

void delete_all(struct student **head);

void sort_records(struct student **head);
void reverse_list(struct student **head);



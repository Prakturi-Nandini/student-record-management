# Student Record Management System

## Overview

The **Student Record Management System** is a menu-driven C project developed using a **singly linked list**.

The system allows users to add, delete, display, modify, save, load, sort, delete all, and reverse student records.

The project also demonstrates **dynamic memory allocation, file handling, searching, sorting, and modular programming** in C.

---

## Features

* Add a new student record
* Automatically assign a unique roll number
* Delete a student by roll number
* Delete a student by name
* Display all student records
* Modify student details
* Search records by:

  * Roll number
  * Name
  * Percentage
* Sort records by:

  * Name
  * Percentage
* Save records to a text file
* Load records from a text file
* Delete all records
* Reverse the singly linked list
* Save and exit / exit without saving
* Dynamic memory allocation and deallocation

---

## Student Structure

```c
struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};
```

### Structure Members

| Member       | Description              |
| ------------ | ------------------------ |
| `rollno`     | Unique roll number       |
| `name`       | Student name             |
| `percentage` | Student percentage       |
| `next`       | Pointer to the next node |

---

## Menu

```text
******** STUDENT RECORD MENU ********

a/A : Add new record
d/D : Delete a record
s/S : Show the list
m/M : Modify a record
v/V : Save records
e/E : Exit
t/T : Sort the list
l/L : Delete all the records
r/R : Reverse the list
```

---

## Add Record

The user can add a new student record.

The program:

1. Allocates memory using `malloc()`.
2. Finds the smallest unused positive roll number.
3. Accepts the student name.
4. Accepts percentage between `0` and `100`.
5. Adds the new node to the linked list.

---

## Delete Record

The user can select:

```text
R/r : Enter roll number to delete
N/n : Enter name to delete
```

### Delete by Roll Number

The program searches for the specified roll number.

If found:

* The node is unlinked.
* Memory is released using `free()`.
* A successful deletion message is displayed.

If the roll number is not found, an appropriate message is displayed.

### Delete by Name

The program searches for matching names.

If multiple students have the same name, all matching records are displayed with their roll numbers.

Example:

```text
Matching records:

Roll No: 1  Name: Rahul  Percentage: 85.00
Roll No: 3  Name: Rahul  Percentage: 78.00

Enter roll number to delete:
```

The user can then select the required roll number.

---

## Display Records

All student records are displayed in a table.

Example:

```text
---------------------------------------------
Roll No.    Name              Percentage
---------------------------------------------
1           Rahul             85.00
2           Priya             91.50
3           Arun              78.00
---------------------------------------------
```

If there are no records, the program displays an appropriate message.

---

## Modify Record

The user can search for a record using:

```text
R/r : Search by roll number
N/n : Search by name
P/p : Search by percentage
```

If multiple records have the same name or percentage, the matching records are displayed with their roll numbers.

The user can select the required roll number for modification.

The roll number remains unchanged.

---

## Sort Records

The program provides two sorting options:

```text
N/n : Sort with name
P/p : Sort with percentage
```

### Sort by Name

Student records are arranged alphabetically by name.

### Sort by Percentage

Student records are arranged in descending order of percentage.

The sorting operation rearranges the existing linked-list nodes by changing their links.

No duplicate set of nodes is created.

---

## Reverse Linked List

The singly linked list can be reversed using:

```text
R/r : Reverse the list
```

Example:

```text
Before:

1 → 2 → 3 → 4 → NULL

After:

4 → 3 → 2 → 1 → NULL
```

The reversal is performed by changing the `next` pointers.

No new nodes are created.

---

## File Handling

Student records are stored in:

```text
student.dat
```

The project uses a **text file**, not a binary file.

Example file contents:

```text
1 Rahul 85.00
2 Priya 91.50
3 Arun 78.00
```

### Save

Records are written using:

```c
fprintf()
```

### Load

Records are read using:

```c
fscanf()
```

The `next` pointer is not stored in the file.

When records are loaded, the linked list is reconstructed using dynamically allocated nodes.

---

## Delete All Records

The `Delete All` option:

* Frees every node.
* Sets the head pointer to `NULL`.
* Removes all records from memory.

The `student.dat` file is **not deleted**.

---

## Exit Options

When the user selects `e/E`:

```text
S/s : Save and exit
E/e : Exit without saving
```

Before the program terminates, allocated memory is released.

---

## Project Structure

```text
Student-Record-Management-System/
│
├── student.h
├── stud_main.c
├── stud_add.c
├── stud_del.c
├── stud_show.c
├── stud_mod.c
├── stud_save.c
├── stud_sort.c
├── stud_reverse.c
├── README.md
└── student.dat
```

### Source Files

| File             | Purpose                                      |
| ---------------- | -------------------------------------------- |
| `student.h`      | Structure definition and function prototypes |
| `stud_main.c`    | Main function and menu                       |
| `stud_add.c`     | Add student records                          |
| `stud_del.c`     | Delete student records                       |
| `stud_show.c`    | Display student records                      |
| `stud_mod.c`     | Modify student records                       |
| `stud_save.c`    | Save and load records                        |
| `stud_sort.c`    | Sort student records                         |
| `stud_reverse.c` | Reverse linked list                          |
| `README.md`      | Project documentation                        |
| `student.dat`    | Saved student data                           |

---

## Technologies Used

* **Language:** C
* **Data Structure:** Singly Linked List
* **Memory Management:** Dynamic Memory Allocation
* **File Handling:** Text File
* **Compiler:** GCC

---

## Compilation

Compile all source files together:

```bash
gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c stud_reverse.c -o student
```

---

## Run

### Linux / WSL

```bash
./student
```

### Windows

```bash
student.exe
```

---

## Concepts Used

This project demonstrates:

* C structures
* Pointers
* Pointer to pointer
* Singly linked lists
* Dynamic memory allocation
* `malloc()`
* `free()`
* Searching
* Sorting
* File handling
* `fopen()`
* `fprintf()`
* `fscanf()`
* `fclose()`
* Modular programming
* Linked-list insertion
* Linked-list deletion
* Linked-list reversal
* Memory management

---

## Memory Management

Each student node is dynamically allocated using:

```c
malloc(sizeof(struct student));
```

When a node is deleted, its memory is released using:

```c
free(temp);
```

When all records are deleted, every allocated node is freed.

This helps prevent memory leaks and invalid memory usage.

---

## Conclusion

The **Student Record Management System** is a practical C project that demonstrates how a singly linked list can be used to manage student information.

The project combines linked-list operations with dynamic memory allocation, searching, sorting, modification, deletion, file handling, and list reversal.

The source code is divided into multiple files to demonstrate **modular programming** and make the project easier to understand and maintain.

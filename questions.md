# Questions

## Question 1

What is the time complexity of the following C program?

```c
#include <stdio.h>

#define MAXN 100

int main() {
    int n = 0, i = 0, j = 0;
    int mat[MAXN][MAXN];

    fscanf(stdin, "%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(stdin, "%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        mat[i][0] *= 2;
    }
}
```
The time complexity of the program above is O(n^2), because it is determined by the nested for loops.

## Question 2

What is a memory leak? Explain how to correctly free memory after a dynamic
memory allocation in C

A memory leak happens when a program allocates memory dynamically but fails to free it. To correctly free memory after a dynamic allocation, you should use the free() function in C. It is recommended that, after freeing the memory, the programmer sets the pointer to NULL to prevent a "read after free" vulnerability.
## Question 3

What is an abstract method in OOP? How is it used?

Abstract method in OOP are methods defined in a parent class, which will be very generic, and ha to be implementes in each descendent class.

## Question 4

How is `systemd` used in most Linux systems?

I don't know the answer to this question.

## Question 5

What is a `git rebase`?

It is used to commit the changes to an existing branch, without merging the two, its maily used to modify the commits.
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
int list[MAXSIZE];
int index1 = -1;

void insertAtEnd(int value)
{
    if (index1 < MAXSIZE - 1) {
        index1++;
        list[index1] = value;
    }
}

void display()
{
    for (int i = 0; i <= index1; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void insertAtPos(int pos, int value)
{
    if (pos >= 0 && pos <= index1 + 1 && index1 < MAXSIZE - 1) {
        index1++;
        for (int i = index1; i > pos; i--)
        {
            list[i] = list[i - 1];
        }
        list[pos] = value;
    }
}

void insertAtBeginning(int value)
{
    if (index1 < MAXSIZE - 1) {
        index1++;
        for (int i = index1; i > 0; i--)
        {
            list[i] = list[i - 1];
        }
        list[0] = value;
    }
}

void deleteAtEnd() {
    if (index1 >= 0) {
        index1--;
    }
}

void deleteFromPos(int pos) {
    if (index1 >= 0 && pos >= 0 && pos <= index1) {
        for (int i = pos; i < index1; i++) {
            list[i] = list[i + 1];
        }
        index1--;
    }
}

void deleteAtBeginning() {
    if (index1 >= 0) {
        for (int i = 0; i < index1; i++) {
            list[i] = list[i + 1];
        }
        index1--;
    }
}

void main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();

    deleteAtEnd();
    display();

    insertAtBeginning(40);
    display();

    deleteAtBeginning();
    display();

    insertAtPos(0, 60);
    display();

    deleteFromPos(1);
    display();
}
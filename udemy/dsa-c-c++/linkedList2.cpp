#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// int *SetHead(int *newHead)
// {
//     int *p = (int *)malloc(sizeof(int));
//     return p;
// }

// int *SetTail()
// {
//     int *p = (int *)malloc(sizeof(int));
//     return p;
// }

Node *createNode(int data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

Node *createLinkedList(int data[], int count)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *curr = NULL;

    for (size_t i = 0; i < count; i++)
    {
        /* code */

        head == NULL ? head = curr = createNode(data[i]) : curr = createNode(data[i]);
        if (tail != NULL)
        {
            tail->next = curr;
        }
        tail = curr;
    }

    return head;
}

void printLinkedList(Node *p)
{
    while (p != NULL)
    {
        printf("Data in linked node = %d\n", p->data);
        p = p->next;
    }
}

void printLinkedListRecursive(Node *p)
{
    if (p != NULL)
    {
        printf("Data in linked node = %d\n", p->data);
        p = p->next;
        printLinkedListRecursive(p);
    }
}

int countNodes(Node *p)
{
    static int count = 0;
    if (p != NULL)
    {
        count++;
        p = p->next;
        countNodes(p);
    }
    return count;
}

int sumOfNodes(Node *p)
{
    if (p->next != NULL)
    {
        return p->data + sumOfNodes(p->next);
    }
    return p->data;
}

int maxElementInLinkedlist(Node *p)
{

    int max = p->data;
    if (p->next != NULL)
    {
        int nextMax = maxElementInLinkedlist(p->next);
        return nextMax > max ? nextMax : max;
    }
    return max;
}

Node *searchByValue(Node *head, int value)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == value)
        {
            if (q == NULL)
            {
                // value found at head
                return head;
            }

            q->next = p->next;
            p->next = head;
            head = p;
            return head;w
        }
        q = p;
        p = p->next;
    }
    return head;
}

Node *insertNewNode(Node *head, int index)
{
}

int main()
{
    int arr1[] = {1, 2, 7, 10, 5, 8};
    Node *head = createLinkedList(arr1, sizeof(arr1) / sizeof(int));
    printLinkedList(head);
    printf("Recursively printing linked list \n");
    printLinkedListRecursive(head);

    printf("Count of  nodes in linked list \n%d\n", countNodes(head));

    printf("Sum of  nodes in linked list \n%d\n", sumOfNodes(head));

    printf("Max value  in linked list \n%d\n", maxElementInLinkedlist(head));

    Node *search1 = searchByValue(head, 5);
    head = search1;
    Node *search2 = searchByValue(head, 7);
    head = search2;
    printLinkedList(head);
}

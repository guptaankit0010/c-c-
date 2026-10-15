#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

Node *createLinkedList(int arrList[], int size)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (size_t i = 0; i < size; i++)
    {
        Node *n1 = (Node *)malloc(sizeof(Node));
        n1->data = arrList[i];
        n1->next = NULL;
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }
    }
    return head;
}

void printLinkedList(Node *p)
{
    printf("Data in linked node = %d\n", p->data);
    if (p->next != NULL)
    {
        printLinkedList(p->next);
    }
}

void countNodes(Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    printf("No. of nodes in linked list = %d\n", cnt);
}

int countNodesR1(Node *p)
{
    if (p != NULL)
    {
        return countNodesR1(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int countNodesR2(Node *p)
{
    int cnt = 0;
    if (p != NULL)
    {
        cnt = countNodesR1(p->next);
        return cnt + 1;
    }
    else
    {
        return cnt;
    }
}

int sumNodesR(Node *p)
{
    int sum = 0;
    if (p->next != NULL)
    {
        sum = sumNodesR(p->next);
        return sum + p->data;
    }
    else
    {
        return sum + p->data;
    }
}
void sumNodes(Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("Sum of nodes in linked list = %d\n", sum);
}

int maxNodeValue(Node *p)
{
    int max = p->data;
    if (p->next != NULL)
    {
        max = maxNodeValue(p->next);
        return p->data > maxNodeValue(p->next) ? p->data : max;
    }
    else
    {
        return p->data;
    }
}

Node *search(Node *head, Node *p, int key)
{
    Node *q = p;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            return p;
        }
        q = p;
        p = p->next;
    }
}

Node *insertNewNode(Node *p, int index)
{
    int curPos = 0;
    Node *q = p;
    Node *head = p;
    while (p != NULL)
    {
        if (index == curPos)
        {

            Node *n1 = (Node *)malloc(sizeof(Node));
            n1->next = p;
            n1->data = 0;
            if (q != p)
            {
                q->next = n1;
                return head;
            }
            else
            {
                return n1;
            }
        }
        curPos++;
        q = p;

        p = p->next;
    }
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    // insert at beginning
    if (index == 0)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *temp = head;
    int pos = 0;

    // move to node before insertion point
    while (temp != NULL && pos < index - 1)
    {
        temp = temp->next;
        pos++;
    }

    // invalid index
    if (temp == NULL)
    {
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node *insertIntoSortedList(Node *p, int val)
{
    Node *q = p;
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->data = val;
    if (p == NULL || p->data > val)
    {
        n1->next = p;
        return n1;
    }
    while (q->next != NULL && q->next->data < val)
    {
        q = q->next;
    }
    n1->next = q->next;
    q->next = n1;
    return p;
}

Node *deleteNodeAtIndex(Node *p, int index)
{
    Node *head = p;
    int curPos = 0;
    if (index == 0)
    {
        head = p->next;
        free(p);
        return head;
    }

    while (p != NULL)
    {
        if (index - 1 == curPos)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return head;
        }
        curPos++;
        p = p->next;
    }
    return head;
}

bool checkListSorted(Node *p)
{
    int x = -1;
    while (p != NULL)
    {
        if (x > p->data)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

Node *removeDuplicateNodes(Node *p)
{
    Node *head = p;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    return head;
}

Node *reverseLinkedList1(Node *p, Node *q)
{
    Node *head = p;
    if (p == NULL)
    {
        head = q;
    }
    else
    {
        head = reverseLinkedList1(p->next, p);
        p->next = q;
    }
    return head;
}

Node *reverseLinkedList2(Node *p)
{
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

Node *mergeLinkdedList(Node *p1, Node *p2)
{
    Node *p3, *t3 = NULL;
    if (p1->data < p2->data)
    {
        p3 = t3 = p1;
        p1 = p1->next;
        t3->next = NULL;
    }
    else
    {
        p3 = t3 = p2;
        p2 = p2->next;
        t3->next = NULL;
    }

    while (p2 != NULL && p1 != NULL)
    {
        if (p1->data < p2->data)
        {
            t3->next = p1;
            t3 = p1;
            p1 = p1->next;
            t3->next = NULL;
        }
        else
        {
            t3->next = p2;
            t3 = p2;
            p2 = p2->next;
            t3->next = NULL;
        }
    }
    if (p1 != NULL)
    {
        t3->next = p1;
    }
    if (p2 != NULL)
    {
        t3->next = p2;
    }
    return p3;
}

int main()
{
    int arr1[] = {1, 2, 7, 4, 5, 6};
    Node *head = createLinkedList(arr1, sizeof(arr1) / sizeof(int));

    printLinkedList(head);
    countNodes(head);
    sumNodes(head);
    int noOfNodesR1 = countNodesR1(head);
    printf("No. of nodes in linked list = %d\n", noOfNodesR1);
    int noOfNodesR2 = countNodesR2(head);
    printf("No. of nodes in linked list = %d\n", noOfNodesR2);

    int sumNodes1 = sumNodesR(head);
    printf("Sum of nodes in linked list = %d\n", sumNodes1);

    int maxVal = maxNodeValue(head);
    printf("Max value in linked list = %d\n", maxVal);

    Node *search1 = search(head, head, 5);
    head = search1;
    Node *search2 = search(head, head, 7);
    head = search2;
    printLinkedList(head);

    head = insertNewNode(head, 0);
    printLinkedList(head);

    printf("\n\n\n");
    insertNewNode(head, 5);
    printLinkedList(head);

    printf("\n\n\n");
    head = insertAtIndex(head, 5, 10);
    printLinkedList(head);

    int arr2[] = {1, 2, 4, 8, 16, 32};
    Node *head2 = createLinkedList(arr2, sizeof(arr2) / sizeof(int));
    insertIntoSortedList(head2, 10);
    printLinkedList(head2);

    Node *head3 = reverseLinkedList1(head2, NULL);
    printLinkedList(head3);
}

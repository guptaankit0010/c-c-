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
    printf("===============================\n");
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
            return head;
        }
        q = p;
        p = p->next;
    }
    return head;
}

Node *insertNewNode(Node *p, int index, int value)
{
    int currentIndex = 0;
    if(index == 0){
        Node *newNode = createNode(value);
        newNode->next = p;
        return newNode;
    }
    Node *newHead = p;
    while(p != NULL){
        currentIndex++;
        if (index == currentIndex)
        {
            Node *newNode = createNode(value);
            newNode->next = p->next;
            p->next = newNode;
            return newHead;
        }
        
        p = p->next;
    }
    return NULL;
}

Node *insertIntoSortedList(Node *p, int value)
{
    Node *q=NULL;
    for(;p != NULL;p=p->next){
        
        if( p->data > value){
            // then insert new node after *p node
            Node *newNode = createNode(value);
            newNode->next=p;
            if(q != NULL){
                q->next=newNode;
            }
            return p;
        }
        q=p;
    }
    return NULL;
}

Node *deleteNodeAtIndex(Node *p, int index){
    Node *q = NULL;
    if(index == 0){
        q = p->next;
        free(p);    
        return q;
    }
    for(int i=0;p != NULL;i++){
        
        if(i == index){
            q->next = p->next; 
            free(p);
            return q;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

bool checkSortedLinkedList(Node *p){
        
        while(p != NULL){
            if(p->next && p->data > p->next->data){
                return false;
            }
            p = p->next;
        }
        return true;
}

Node *reverseLinkedList1(Node *p){
    Node *q = NULL;
    Node *r = NULL;

    while(p != NULL){
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    return q;
}

Node *reverseLinkedList2(Node *p,Node *q){
    Node *head = NULL;
    if(p != NULL){
        head = reverseLinkedList2(p->next,p);
        p->next = q;
    }
    else{
        head = q;
    }
    return head;
}

Node * mergeLinkedLists(Node *p1,Node *p2){

    Node *p3;
    Node *t3;
    
    if(p1->data < p2->data){
        p3=p1;
        p1 =p1->next;
        p3->next = NULL;
    }
    else{
        p3 = p2;
        p2 = p2->next;
        p3->next = NULL;
    }

    t3 = p3;
    while( p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            t3->next = p1;
            t3 = t3->next;
            p1 = p1->next;
            t3->next = NULL;
        }
        else{
            t3->next = p2;
            t3 = t3->next;
            p2 = p2->next;
            t3->next = NULL;
            
        }
    }

    if(p1 == NULL){
        t3->next = p2;
    }
    if(p2 == NULL){
        t3->next = p1;
    }

    return p3;
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

    Node *insert1 = insertNewNode(head, 0, 110);
    head = insert1;
    printLinkedList(head);
    Node *insert2 = insertNewNode(head, 6, 20);
    printLinkedList(head);
    // Node *insert3 = insertNewNode(head, 9, 20);
    // printLinkedList(head);

    // Node *insert4 = insertNewNode(head, -1, 20);
    // printLinkedList(head);

    // New Linked List
    int arr2[] = {101, 201, 701, 101, 501, 801};
    Node *head2 = createNode(arr2[0]);
    for(size_t i = 1; i < sizeof(arr2) / sizeof(int); i++){
        insertNewNode(head2,i,arr2[i]);
    }
    printLinkedList(head2);

    int arr3[] = {5, 10, 15, 20, 25, 30};
    Node *head3 = createLinkedList(arr3, sizeof(arr3) / sizeof(int));
    printLinkedList(head3);
    insertIntoSortedList(head3,24);
    printLinkedList(head3);
    insertIntoSortedList(head3,35);
    printLinkedList(head3);
    insertIntoSortedList(head3,4);
    printLinkedList(head3);
    deleteNodeAtIndex(head3,2);
    printLinkedList(head3);
    deleteNodeAtIndex(head3,4);
    printLinkedList(head3);
    Node *newHead3 = deleteNodeAtIndex(head3,0);
    printLinkedList(newHead3);

    printf("List is sorted : %d\n",checkSortedLinkedList(newHead3));

    printf("List is sorted : %d\n",checkSortedLinkedList(head2));

    int arr4[] = {75, 10, 15, 20, 25, 40};
    Node *head4 = createLinkedList(arr4, sizeof(arr4) / sizeof(int));
    printLinkedList(head4);

    head4 = reverseLinkedList1(head4);
    printLinkedList(head4);

    head4 = reverseLinkedList2(head4,NULL);
    printLinkedList(head4);

    int arr5[] = {275, 410, 570, 640, 715, 840};
    Node *head5 = createLinkedList(arr5, sizeof(arr5) / sizeof(int));

    int arr6[] = {45, 105, 215, 320, 425, 540};
    Node *head6 = createLinkedList(arr6, sizeof(arr6) / sizeof(int));

    Node *head7 = mergeLinkedLists(head5,head6);
    printLinkedList(head7);
}

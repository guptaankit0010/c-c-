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

        // if last node, then make it circular
        if(i == count-1){
            tail->next = head;
        }
    }

    return head;
}

void printLinkedList(Node *p)
{
    Node *head = p;
    do{
        printf("Data in linked node = %d\n", p->data);
        p = p->next;
    }while (p != head);
    
    printf("===============================\n");
}

void printLinkedListRecursive(Node *p,Node *head)
{
    static int count = 0;
    if (p != head)
    {
        printf("Data in linked node = %d\n", p->data);
        p = p->next;
        printLinkedListRecursive(p,head);
    }
    else{
        if(count > 0){
            return;
        }
        count++;
        printf("Data in linked node = %d\n", p->data);
        printLinkedListRecursive(p->next,head);
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
    Node *newHead = p;
    int currentIndex = 0;
    if(index == 0){
        Node *newNode = createNode(value);
        newNode->next = p;
        Node *q = p;
        do{
            q = p;
            p = p->next;
        }while(p != newHead);
        q->next = newNode;
        return newNode;
    }
    do{
        currentIndex++;
        if (index == currentIndex)
        {
            Node *newNode = createNode(value);
            newNode->next = p->next;
            p->next = newNode;
            return newNode;
        }
        
        p = p->next;
    }while(p != newHead);
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
    Node *head = p;
    if(index == 0){
        while(p->next != head){
            p = p->next;
        }
        p->next = head->next;
        free(head);
        return p->next;
    }
    for(int i=0; i<index;i++){
        q=p;
        p=p->next;  
    }
    q->next = p->next;
    free(p);
    return head;
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
    printLinkedListRecursive(head,head);

    Node *insert1 = insertNewNode(head, 0, 110);
    head = insert1;
    printLinkedList(head);
    Node *insert2 = insertNewNode(head, 6, 20);
    printLinkedList(head);

    deleteNodeAtIndex(head,2);
    printLinkedList(head);
    deleteNodeAtIndex(head,4);
    printLinkedList(head);
}

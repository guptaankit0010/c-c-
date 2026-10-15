#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int *qp;
    int head;
    int tail;
};

struct Node
{
    int data;
    Node *next;
};

void enqueue1(Node *head, Node *tail, int x)
{
    Node *t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (head == NULL)
        {
            head = tail = t;
        }
        else
        {
            tail->next = t;
            tail = t;
        }
    }
}

int dequeue1(Node *head, Node *tail)
{
    int x = -1;
    if (head == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        Node *tmp = head;
        x = head->data;
        head = head->next;
        free(tmp);
    }
    return x;
}
void enqueue(struct Queue *q, int data)
{
    if ((q->tail + 1) % (q->size) == q->head)
    {
        printf("Queue is full");
    }
    else
    {
        q->tail = (q->tail + 1) % (q->size);
        q->qp[q->tail] = data;
    }
};

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->head == q->tail)
    {
        printf("Queue is empty");
    }
    else
    {
        q->head = (q->head + 1) % (q->size);
        x = q->qp[q->head];
    }

    return x;
};

void display(struct Queue *q)
{
    int i = q->head + 1;
    do
    {
        printf("%d\n", q->qp[i]);
        i = (i + 1) % (q->size);
    } while (i != (q->tail + 1) % (q->size));
}

int main()
{
    Queue q1;

    q1.size = 10;
    q1.qp = (int *)malloc(sizeof(int) * q1.size);
    q1.head = q1.tail = 0;

    enqueue(&q1, 12);
    enqueue(&q1, 12);
    enqueue(&q1, 42);
    enqueue(&q1, 12);
    enqueue(&q1, 12);
    enqueue(&q1, 52);
    enqueue(&q1, 12);

    display(&q1);
    dequeue(&q1);
    dequeue(&q1);
    enqueue(&q1, 50);
    display(&q1);

    Node *head, *tail = NULL;
}
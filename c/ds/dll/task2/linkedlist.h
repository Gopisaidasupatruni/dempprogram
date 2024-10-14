#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
        struct node *prv;
        int data;
        struct node *link;
}ST;
void d_append(ST **, int);
void display(ST *);
int d_length(ST *);
void d_addatbegin(ST **, int);
#endif // LINKEDLIST_H


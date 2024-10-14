#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
        struct node *prv;
        int data;
        struct node *link;
}ST;
void d_append(ST **, int);
void d_addafter(ST **, int,int);
void display(ST *);
int d_length(ST *);
void d_addatbegin(ST **, int);
void d_delete(ST **, int);
#endif // LINKEDLIST_H


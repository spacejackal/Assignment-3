#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data);
void insert_node(Node **head, int data);
void delete_node(Node **head, int data);
Node* search_node(Node *head, int data);
void free_list(Node **head);

#endif /* LINKEDLIST */
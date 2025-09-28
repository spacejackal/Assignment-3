#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data);
void insert_node(Node **head, int data, int index);
void delete_node(Node **head, int index);
Node* search_node(Node *head, int index);
void free_list(Node **head);

#endif /* LINKEDLIST */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* create_node(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Allocation failed\n");
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

/*
 * Insert a node with value 'data' at 'position' (0-based).
 * If position <= 0 insert at head.
 * If position >= length append at end.
 */
void insert_node(Node **head, int data, int position) {
    if (!head) return;

    Node *new_node = create_node(data);
    if (!new_node) return;

    if (position <= 0 || !*head) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *curr = *head;
    int idx = 0;
    while (curr->next && idx < position - 1) {
        curr = curr->next;
        idx++;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

/*
 * Delete node at index.
 */
void delete_node(Node **head, int index) {
    if (!head || !*head) return;

    Node *curr = *head;
    // If head matches
    if (index == 0) {
        *head = curr->next;
        free(curr);
        return;
    }

    int idx = 0;
    Node *prev = NULL;
    while (curr && idx < index) {
        prev = curr;
        curr = curr->next;
        idx++;
    }
    if (curr) {
        prev->next = curr->next;
        free(curr);
    }
    return;
}

/*
 * Return pointer to first node whose data == data, else NULL.
 */
Node* search_node(Node *head, int index) {
    int idx = 0;
    while (head) {
        if (idx == index) {
            return head;
        }
        head = head->next;
        idx++;
    }
    return -1;
}

/*
 * Free all nodes and set head to NULL.
 */
void free_list(Node **head) {
    if (!head) return;
    Node *curr = *head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}
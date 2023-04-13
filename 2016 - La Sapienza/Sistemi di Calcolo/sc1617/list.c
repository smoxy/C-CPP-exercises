#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char * id;
    char * value;
    struct node * next;
} node_t;

static int count = 0;

node_t* add_node(node_t* l, char* value) {
    node_t* node = malloc(sizeof(node_t));

    char* id= (char*)malloc(sizeof(char)*16);
    sprintf(id, "ID_%d", count++);
    node->id = id;
    node->value = value;

    if (l != NULL)
        node->next = l;
    else
		node->next = NULL;								//CORREZIONE 1
    
    return node;
}

void print_list(node_t* head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%s\n", current->value);
        current = current->next;
    }
}

void delete_list(node_t * head) {
    node_t* current = head;

    while (current != NULL) {
													//CORREZIONE 3
        free(current);								//CORREZIONE 2
        current = current->next;
    }
}

int main() {
    node_t* l;

    l = add_node(NULL, "Hello");
    l = add_node(l, " ");
    l = add_node(l, "World");
    l = add_node(l, "!");

    print_list(l);
    delete_list(l);
}

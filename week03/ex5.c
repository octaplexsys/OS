#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

void insert_node(struct node** head, int a, int i) {
    if (i > 0 && *head == NULL) {
        printf("Couldn't insert. Index is out of bound.\n");
        return;
    }
    if (i == 0) {
        struct node* old_head = *head;
        *head = malloc(sizeof(struct node));
        (*head)->value = a;
        (*head)->prev = NULL;
        (*head)->next = old_head;
        if(old_head != NULL) {
            old_head->prev = (*head);
        }
        return;
    }
    //iterate
    struct node *cur = *head;
    while(--i) {
        //return if index is out of bound
        printf("%d\n", cur->value);
        if(cur->next == NULL) {
            printf("Couldn't insert. Index is out of bound.\n");
            return;
        }
        cur = cur->next;
    }
    struct node* new_node = malloc(sizeof(struct node));
    new_node->value = a;
    new_node->next = cur->next;
    if (cur->next != NULL) {
        new_node->next->prev = new_node;
    }
    new_node->prev = cur;
    cur->next = new_node;
}
void delete_node(struct node** head, int i) {
    if (i == 0) {
        if(*head == NULL) {
            printf("Couldn't delete head node. There are no elements.\n");
            return;
        }
        struct node* next_node = (*head)->next;
        free(*head);
        *head = next_node;
        if ((*head) != NULL) {
            (*head)->prev = NULL;
        }
        return;
    }

    //iterate
    struct node *cur = *head;
    while(--i) {
        //return if index is out of bound
        if(cur->next == NULL) {
            printf("Couldn't delete. Index is out of bound.\n");
            return;
        }
        cur = cur->next;
    }
    struct node* old_node = cur->next;
    cur->next = cur->next->next;
    if (cur->next != NULL) {
        cur->next->prev = cur;
    }
    printf("ok2");
    free(old_node);
}

void print_list(struct node* head) {
    struct node* cur = head;
    while(cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    struct node* double_linked_list_head = NULL;
    int n,a,i;
    printf("Input numbers to execute commands:\n0 - print linked list;\n1 n i - insert number n in index i;\n 2 i - delete number in index i;\n-1 - exit program.\n");
    while (1) {
        printf("Insert command: \n");
        scanf("%d", &n);
        switch (n) {
            case 0:
                print_list(double_linked_list_head);
                break;
            case 1:
                scanf("%d %d", &a, &i);
                insert_node(&double_linked_list_head, a, i);
                break;
            case 2:
                scanf("%d", &i);
                delete_node(&double_linked_list_head, i);
                break;
            case -1:
                printf("GoodBye!\n");
                return 0;
        }
    }
}
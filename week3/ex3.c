#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void insert_node(struct node** head, int a, int i) {
    //iterate
    struct node *cur = *head;
    struct node *prev_cur = NULL;
    while(i--) {
        //return if index is out of bound
        if(cur == NULL) {
            printf("Couldn't insert. Index is out of bound.\n");
            return;
        }
        prev_cur = cur;
        cur = cur->next;
    }
    //insert
    if (prev_cur == NULL) {
        struct node* old_head = *head;
        *head = malloc(sizeof(struct node));
        (*head)->value = a;
        (*head)->next = old_head;
    } else {
        prev_cur->next = malloc(sizeof(struct node));
        prev_cur->next->value = a;
        prev_cur->next->next = cur;
    }
}
void delete_node(struct node** head, int i) {
    //iterate
    struct node *cur = *head;
    struct node *prev_cur = NULL;
    while(i--) {
        //return if index is out of bound
        if(cur == NULL) {
            printf("Couldn't delete. Index is out of bound.\n");
            return;
        }
        prev_cur = cur;
        cur = cur->next;
    }
    //delete
    if (prev_cur == NULL) {
        if(*head == NULL) {
            printf("Couldn't delete head node. There are no elements.\n");
            return;
        }
        struct node* next_node = (*head)->next;
        free(*head);
        *head = next_node;
    } else {
        prev_cur->next = cur->next;
        free(cur);
    }
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
    struct node* list_head = NULL;
    int n,a,i;
    printf("Input numbers to execute commands:\n0 - print linked list;\n1 n i - insert number n in index i;\n 2 i - delete number in index i;\n-1 - exit program.\n");
    while (1) {
        printf("Insert command: \n");
        scanf("%d", &n);
        switch (n) {
            case 0:
                print_list(list_head);
                break;
            case 1:
                scanf("%d %d", &a, &i);
                insert_node(&list_head, a, i);
                break;
            case 2:
                scanf("%d", &i);
                delete_node(&list_head, i);
                break;
            case -1:
                printf("GoodBye!\n");
                return 0;
        }
    }
}
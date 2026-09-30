#include <stdio.h>
#include <stdlib.h>
#include "Circularlist.h"

void init_list(node_t **head){
    *head = NULL;
}

node_t *createNode(double data){
    node_t *new = malloc(sizeof(node_t));
    if(new == NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    new->key = data;
    new->next = NULL;
    return new;
}

node_t *insert(node_t *head, double data, int pos){
    node_t *new = createNode(data);
    if(new == NULL)
        return head;
    if(head == NULL){
        new->next = new;
        return new;
    }
    if(pos<1){
        printf("Invalid position");
        return head;
    }
    if(pos == 1){
        node_t *last = head;
        while(last->next != head)
            last = last->next;
        new->next = head;
        last->next = new;
        return new;
    }
    node_t *temp = head;
    for(int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    new->next = temp->next;
    temp->next = new;
    return head;
}

double del(node_t **head, char *ch){
    if(*head == NULL){
        printf("Nothing to delete. So I'll give you a zero.");
        return 0.0;
    }
    node_t *temp = *head;
    double value;
    if(*ch == 'p' || *ch == 'P'){
        int pos;
        printf("Enter the position: ");
        scanf("%d", &pos);
        if(pos < 1){
            printf("Invalid position.");
            return 0.0;
        }
        if((*head)->next == *head){
            if(pos == 1){
                value = (*head)->key;
                free(*head);
                *head = NULL;
                return value;
            }
            printf("Position does not exist.");
            return 0.0;
	}
        if(pos == 1){
            node_t *last = *head;
            while(last->next != *head)
                last = last->next;
            temp = *head;
            value = temp->key;
            *head = (*head)->next;
            last->next = *head;
            free(temp);
            return value;
        }
        for(int i = 1; i < pos - 1 && temp->next != *head; i++)
            temp = temp->next;
        if(temp->next == *head){
            printf("Position does not exist.");
            return 0.0;
        }
        node_t *delnode = temp->next;
        value = delnode->key;
        temp->next = delnode->next;
        free(delnode);
        return value;
    }
    if(*ch == 'S' || *ch == 's'){
        double q;
        printf("Enter the value to be deleted: ");
        scanf("%lf", &q);
        if((*head)->key == q){
            if((*head)->next == *head){
                value = (*head)->key;
                free(*head);
                *head = NULL;
                return value;
            }
            node_t *last = *head;
            while(last->next != *head)
                last = last->next;
            temp = *head;
            value = temp->key;
            *head = (*head)->next;
            last->next = *head;
            free(temp);
            return value;
        }
        temp = *head;
        while(temp->next != *head){
            if(temp->next->key == q){
                node_t *delnode = temp->next;
                value = delnode->key;
                temp->next = delnode->next;
                free(delnode);
                return value;
            }
            temp = temp->next;
        }
        printf("Node not found so you get a 0.");
        return 0.0;
    }
    printf("I don't understand your choice so I give you a zero.");
    return 0.0;
}

node_t* order(node_t *head, char *ch){
    if(head == NULL || head->next == head)
        return head;
    if(*ch != 'A' && *ch != 'a' &&
       *ch != 'D' && *ch != 'd'){
        printf("I don't understand your choice so I just return the original list lol.");
        return head;
    }
    for(node_t *i = head; i->next != head; i = i->next){
        for(node_t *j = i->next; j != head; j = j->next){
            if((*ch == 'A' || *ch == 'a') && i->key > j->key){
                double temp = i->key;
                i->key = j->key;
                j->key = temp;
            }
            if((*ch == 'D' || *ch == 'd') && i->key < j->key){
                double temp = i->key;
                i->key = j->key;
                j->key = temp;
            }
        }
    }
    return head;
}
void display(node_t *head){
    if(head == NULL){
        printf("The list is empty.");
        return;
    }
    node_t *temp = head;
    do{
        printf("%lf ", temp->key);
        temp = temp->next;
    }while(temp != head);
}

void deinit_list(node_t **head){
    if(*head == NULL)
        return;
    node_t *temp = *head;
    node_t *next;
    while(temp->next != *head){
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
    *head = NULL;
}

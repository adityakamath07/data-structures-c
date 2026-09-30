#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedlist.h"

void init_list(node_t **head){
	*head=NULL;
}

node_t *createNode(double data){
	node_t *new=malloc(sizeof(node_t));
	if(new==NULL){
		printf("Memory allocation failed");
		return new;
	}
	new->key=data;
	new->next=NULL;
	return new;
}

node_t *insert(node_t *head,double data,int pos){
	node_t *new=createNode(data);
	if(head==NULL) {
		new->prev=NULL;
		return new;
	}
    if(pos<1){
        printf("Invalid position.Insertion not succesfull.");
        free(new);
        return head;
    }
	if(pos==1){
		head->prev=new;
		new->next=head;
		new->prev=NULL;
		return new;
	}
	node_t *temp=head;
	for(int i=0;i<pos-1 && temp->next!=NULL;i++) temp=temp->next;
	new->next=temp->next;
	temp->next=new;
	new->prev=temp;
	if(new->next != NULL)
    		new->next->prev = new;
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
        for(int i = 1; i < pos && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Position does not exist.");
            return 0.0;
        }
        value = temp->key;
        if(temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            *head = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
        free(temp);
        return value;
    }
    if(*ch == 'S' || *ch == 's'){
        double q;
        printf("Enter the value to be deleted: ");
        scanf("%lf", &q);
        while(temp != NULL){
            if(temp->key == q){
                value = temp->key;
                if(temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    *head = temp->next;
                if(temp->next != NULL)
                    temp->next->prev = temp->prev;

                free(temp);
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
    if(head == NULL || head->next == NULL)return head;
    if(*ch != 'A' && *ch != 'a' && *ch != 'D' && *ch != 'd'){
        printf("I dont understand your choice so i just return the original list lol.");
        return head;
    }
    for(node_t *i = head; i != NULL; i = i->next){
        for(node_t *j = i->next; j != NULL; j = j->next){
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
	node_t *temp=head;
	if(head==NULL)printf("The list is empty.");
	while(temp!=NULL){
		printf("%lf ",temp->key);
		temp=temp->next;
	}
}

void deinit_list(node_t *head){
	if(head==NULL) return;
	node_t *temp;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
}


#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

void init_list(node_t **head){
	*head=NULL;
}

node_t *createNode(double data){
	node_t *new=malloc(sizeof(node_t));
	if(new==NULL){
		printf("Memory allocation failed(Space...)");
		free(new);
		return new;
	}
	new->key=data;
	new->next=NULL;
	return new;
}

node_t *insert(node_t *head,double data,int pos){
	if(head==NULL) return createNode(data);
	node_t *new=createNode(data);
	if(pos==1){
		new->next=head;
		return new;
	}
	node_t *temp=head;
	for(int i=0;i<pos-1 && temp->next!=NULL;i++) temp=temp->next;
	new->next=temp->next;
	temp->next=new;
	return head;
}

double del(node_t **head,char *ch){
	if(*head==NULL){printf("Nothing to delete. So I'll give you a zero.");return 0.0;}
	node_t *temp=*head;
	double value;
	if(*ch=='p'||*ch=='P'){
		int pos;
		printf("Enter the position.");
		scanf("%d",&pos);
		if(pos==1){
			if((*head)->next==NULL){value=(*head)->key;free(*head);*head=NULL;return value;}
			*head=(*head)->next;
			value=temp->key;
			free(temp);
			return value;
		}
		for(int i=0;i<pos-1 && temp->next!=NULL;i++)temp=temp->next;
		if(temp->next==NULL){printf("Buddy please remember how many elements u input... ;-;");return 0.0;}
		node_t *prev=temp;
		temp=temp->next;
		value=temp->key;
		prev->next=temp->next;
		free(temp);
		return value;
	}
	if(*ch=='S'||*ch=='s'){
		double q;
		printf("Enter the value to be deleted.(It'll be deleted only once on the first encounter)");
		scanf("%lf",&q);
		if(temp->key==q){
				if((*head)->next==NULL){value=(*head)->key;free(*head);*head=NULL;return value;}
				*head=(*head)->next;
				value=temp->key;
				free(temp);
				return value;
		}
		while(temp->next!=NULL){
			if(temp->next->key==q){
				node_t *prev=temp;
				temp=temp->next;
				value=temp->key;
				prev->next=temp->next;
				free(temp);
				return value;
			}
			temp=temp->next;
		}
		printf("Node not found so you get a 0.");
		return 0.0;
	}
	else{
		printf("I dont understand your choice so i give you a zero.");
		return 0.0;
	}
}

node_t *order(node_t *head,char *ch){
	if(*ch=='A'||*ch=='a'){
		node_t *temp=head; 
		node_t *prev=temp;
		if(temp->next==NULL)return head;
		while(temp!=NULL){
			temp=temp->next;
			if(temp->key<prev->key){
				prev->next=temp->next;
				temp->next=prev;
				if(temp==head)head=prev;
			}
			prev=prev->next;
		}
		return head;
	}
	if(*ch=='D'||*ch=='d'){
		node_t *temp=head;
		node_t *prev=temp;
		if(temp->next==NULL)return head;
		while(temp!=NULL){
			temp=temp->next;
			if(temp->key>prev->key){
				prev->next=temp->next;
				temp->next=prev;
				if(temp==head)head=prev;
			}
			prev=prev->next;
		}
		return head;
	}
	else{
		printf("I dont understand your choice so i just return the original list lol.");
		return head;
	}
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


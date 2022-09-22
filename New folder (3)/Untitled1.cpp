#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head;
void insertBeg();
void insertEnd();
void delBeg();
void delEnd();
void display();

int main(){
	int choice = 0;
	while(choice != 6){
		printf("\n Enter the operation to be performed: \n");
		printf("\n 1. Insert at Beginning \n 2. Insert at End \n 3. Delete at Beginning \n 4. Delete at End \n 5. Display \n 6.Exit \n");
		printf("\nEnter the choice:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				insertBeg();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				delBeg();
				break;
			case 4:
				delEnd();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("You have exiited the operation. ");
				break;
			default:
				printf("\n Invalid Input. \n");
		}
	}
}

void insertBeg(){
	struct node *link;
	int item;
	link = (struct node *)malloc(sizeof(struct node *));
	printf("\n Enter the value: ");
	scanf("%d", &item);
	link->data=item;
	link->next=head;
	head=link;
	printf("\n Node Inserted. \n");
}

void insertEnd(){
	struct node *link, *temp;
	int item;
	link = (struct node *)malloc(sizeof(struct node *));
	printf("\n Enter the value: ");
	scanf("%d", &item);
	link->data = item;
	if(head==NULL){
		link->next=NULL;
		head=link;
		printf("\n Node Inserted. \n");
	}else{
		temp=head;
		while(temp->data == NULL){
			temp=temp->next;
		}
		temp->next=link;
		link->next=NULL;
		printf("\n Node Inserted. \n");
	}
}

void delBeg(){
	struct node *link;
	if(head==NULL){
		printf("\n The list is empty. \n");
	}else{
		link=head;
		head=link->next;
		free(link);
		printf("\n Node Deleted. \n");
	}
}

void delEnd(){
	struct node *link, *temp;
	if(head==NULL){
		printf("\n The list is empty. \n");
	}else{
		link=head;
		while(link->next != NULL){
			temp=link;
			link=link->next;
		}
		temp->next=NULL;
		free(link);
		printf("\n Node Deleted. \n");
	}
}

void display(){
	struct node *link;
	link=head;
	if(head==NULL){
		printf("\n No item inserted. \n");
	}else{
		printf("\n The values are: \n");
		while(link!= NULL){
			printf("\n%d", link->data);
			link=link->next;
		}
	}
}













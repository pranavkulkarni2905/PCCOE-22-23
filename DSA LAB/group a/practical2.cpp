#include<iostream>
#include<string>

using namespace std;

struct node{
	int data;
	struct node* next;
	
}*head,*temp,*prev,*newnode,*curr;

void insertAtBegin(){
	int data;
	
	cout<<"\nEnter Data to insert at begining :";
	cin>>data;
	
	newnode=new node;
	newnode->data=data;
	if(head==NULL){
		head=newnode;
		newnode->next=NULL;
	}else{
		newnode->next=head;
		head=newnode;
	}
}

void insertAtEnd(){
	int data;
	cout<<"\nenter data to insert at end:";
	cin>>data;
	
	newnode=new node;
	
	newnode->data=data;
	
	if(head==NULL){
		head=newnode;
		newnode->next=NULL;
	}else{
		temp=new node;
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
		
	}
	
}
void insertAtPos(){
	int pos,data;
	cout<<"\nEnter position to insert data:";
	cin>>pos;
	cout<<"\nEnter data to insert:";
	cin>>data;
	
	newnode=new node;
	temp=new node;
	curr=new node;
	
	temp=head;
	curr=NULL;
	int i=1;
	while(i<pos){
		curr=temp;
		temp=temp->next;
		i++;
	}
	curr->next=newnode;
	newnode->data=data;
	newnode->next=temp;
}
void deleteFromBeg(){
	if(head==NULL){
		cout<<"\nList is empty..";
	}else{
		temp=new node;
		temp=head;
		head=head->next;
		delete temp;
	}
}
void deleteFromEnd(){
	if(head==NULL){
		cout<<"\nList is empty..";
	}else{
		temp=head;
		curr=NULL;
		while(temp->next!=NULL){
			curr=temp;
			temp=temp->next;
		}
		curr->next=NULL;
		delete temp;
		
	}
}
void deleteFromPos(){
	int pos;
	
	temp=head;
	curr=NULL;
	int i=1;
	cout<<"\nEnter position to delete element:";
	cin>>pos;
	while(i<pos){
		curr=temp;
		temp=temp->next;
		i++;
	}
	curr->next=temp->next;
	delete temp;
}
void search(){
	int data,flag=0;
	cout<<"\nEnter data to search:";
	cin>>data;
	
	temp=head;
	while(temp!=NULL){
		if(data==temp->data){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==0){
		cout<<"\nElement not found..";
	}else{
		cout<<"\nElement Found...";
	}
}
void display(){
	temp=new node;
	if(head==NULL){
		cout<<"\nList is empty..";
	}else{
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"\t ";
			temp=temp->next;
		}
	}
}
void reverse(){
	temp=head;
	curr=head;
	prev=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head=prev;
	display();
}
int main(){
	int ch,choice,n;
	do{
		cout<<"\n1.Insert At beg\n2.Inser At specific position\n3.Insert at End\n4.Delete from begin\n5.Delete from specific position\n6.Delete from end\n7.Display Linked list\n8.Search element\n9.Reverse Linked list";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				insertAtBegin();
				break;
			case 2:
				insertAtPos();
				break;
			case 3:
				insertAtEnd();
				break;
			case 4:
				deleteFromBeg();
				break;
			case 5:
				deleteFromPos();
				
				break;
			case 6:
				deleteFromEnd();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				reverse();
				break;
			case 10:
				break;
		}
		cout<<"\nDo you want to continue press 1:";
		cin>>choice;
	}while(choice==1);
	
	return 0;
}

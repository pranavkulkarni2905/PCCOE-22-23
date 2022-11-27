/*
Date:27-11-2022
Programmer:Pranav Kulkarni
Title:Write a C++ program to implement a singly link list and perform operations such as insert,delete, display, search 
element from it and reverse the list

*/

#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList(){
        	head=NULL;
		}
		
		void insertAtBegin(int data);
		void insertAtPosition(int data);
		void insertAtEnd(int data);
		int deleteFromBegin();
		int deleteFromPosition();
		int deleteFromEnd();
		void display();
		void search(int data);
		void reverse();    
};

void LinkedList::insertAtBegin(int data){
	
}

int main(){
	int choice,n;
	
	do{
		cout<<"\n----------- MAIN MENU ------------";
		cout<<"\nHow can help u?";
		cout<<"\n1.Insert At End\n2.Insert At Specific Position\n3.Insert At End\n4.Delete From Begining\n5.Delete From Specific Position\n6.Delete From End\n7.Display Linked List\n8.Search Element\n9.Reverse List";
		cout<<"\n-----------------------------------";
		cout<<"\nEnter Your Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				exit(0);
				break;
			cout<<"\nDo You want to continue MAIN MENU Press 1 :";
			cin>>n;
		}
	}while(n==1);
	
	return 0;
}

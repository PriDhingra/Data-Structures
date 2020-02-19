#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insertAtBeginning(int new_data){
    struct Node* new_node= new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int new_data){
    struct Node* new_node = new Node();
    struct Node* ftr;
    ftr = head;
    new_node->data = new_data;
    new_node->next = NULL;
    while(ftr->next != NULL){
        ftr = ftr->next;
    }
    ftr->next = new_node;
}

void insertAtPosition(int pos,int new_data){
    if(pos == 1){
        insertAtBeginning(new_data);
    }
    struct Node* new_node = new Node();
    new_node->data = new_data;
    struct Node* ftr;
    ftr = head;
    while((pos-1) > 0){
        ftr = ftr->next;
        pos--;
    }
    new_node->next = ftr->next;
    ftr->next = new_node;
}

void deleteAtBeginning(){
    struct Node* ftr;
    ftr = head;
    head = head->next;
    free(ftr);
}

void deleteAtEnd(){
    struct Node* ftr1;
    struct Node* ftr2;
    ftr1 = head;
    ftr2 = head;
    int count = 0;
    while(ftr1->next != NULL){
        ftr1 = ftr1->next;
        if(count != 0){
            ftr2 = ftr2->next;
        }
        count++;
        
    }
    ftr2->next = NULL;
    free(ftr1->next);
}

void deleteAtPosition(int pos){
    if(pos == 1){
        deleteAtBeginning();
    }
    struct Node* ftr1;
    struct Node* ftr2;
    ftr1 = head;
    ftr2 = head;
    int count = 0;
    while((pos-1) > 0){
        ftr1 = ftr1->next;
        if(count != 0){
            ftr2 = ftr2->next;
        }
        pos--;
        count++;
    }
    ftr2->next = ftr1->next;
    free(ftr1);
}

void display(){
    struct Node* ftr;
    ftr = head;
    while(ftr != NULL){
        cout<<ftr->data<<"  "<<ftr->next;
        cout<<"\n";
        ftr = ftr->next;
    }
}

int main()
{
   insertAtBeginning(1);
   insertAtBeginning(2);
   insertAtEnd(9);
   insertAtEnd(10);
   insertAtBeginning(3);
   insertAtBeginning(4);
   insertAtEnd(5);
   insertAtEnd(6);
   insertAtEnd(7);
   insertAtEnd(8);
   insertAtPosition(3,11);
   insertAtPosition(5,12);
   insertAtPosition(7,13);
   insertAtPosition(8,14);
   deleteAtBeginning();
   deleteAtBeginning();
   deleteAtEnd();
   deleteAtEnd();
   deleteAtEnd();
   deleteAtPosition(4);
   
   
   display(); 
   
   return 0;
}

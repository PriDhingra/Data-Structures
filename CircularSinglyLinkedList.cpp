#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* tail = NULL;
int count = 0;

void startLinkedList(int new_data){
    struct Node* new_node = new Node();
    count++;
    new_node->data = new_data;
    new_node->next = new_node;
    tail = new_node;
}

void insertAtBeginning(int new_data){
    if(tail == NULL){
        startLinkedList(new_data);
    }else{
        struct Node* new_node = new Node();
        count++;
        new_node->data = new_data;
        new_node->next = tail->next;
        tail->next = new_node;
    }
}

void insertAtEnd(int new_data){
    struct Node* new_node = new Node();
    count++;
    new_node->data = new_data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
}

void insertAtPosition(int pos,int new_data){
    if(pos == 1){
        insertAtBeginning(new_data);
    }else if((pos-1) == count){
        insertAtEnd(new_data);
    }else if((pos-1) > count){
        
    }else{
        struct Node* ptr;
        ptr = tail;
        struct Node* new_node = new Node();
        count++;
        new_node->data = new_data;
        while((pos-1) != 0){
            ptr = ptr->next;
            pos--;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void display(){
    struct Node* ptr;
    ptr = tail->next;
    while(ptr->next != tail->next){
        cout<<ptr->data<<" "<<ptr->next<<"\n";
        ptr = ptr->next;
    }
    cout<<ptr->data<<" "<<ptr->next<<"\n";
    cout<<"\n"<<count;
}

int main()
{
   insertAtBeginning(1);
   insertAtBeginning(2);
   insertAtBeginning(3);
   insertAtBeginning(4);
   insertAtBeginning(5);
   insertAtEnd(6);
   insertAtEnd(7);
   insertAtEnd(8);
   insertAtEnd(9);
   insertAtEnd(10);
   insertAtPosition(1,11);
   insertAtPosition(4,12);
   insertAtPosition(7,13);
   insertAtPosition(8,14);
   insertAtPosition(9,15);
   insertAtPosition(16,16);
   insertAtPosition(19,17);
   
   display();
   
   return 0;
}

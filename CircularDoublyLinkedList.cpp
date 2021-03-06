#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* tail = NULL;
struct Node* head = NULL;
int count = 0;
int count1 = 0;

void startLinkedList(int data){
    struct Node* new_node = new Node();
    count++;
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;
    tail = new_node;
    head = tail;
}

void insertAtBeginning(int data){
    if(tail == NULL){
        startLinkedList(data);
    }else{
        struct Node* new_node = new Node();
        count++;
        count1++;
        new_node->data = data;
        new_node->next = tail->next;
        new_node->prev = tail;
        tail->next = new_node;
        if(count1 > 1){
            head = head->prev;
            head->prev = new_node;
        }else if(count1 == 1){
            tail->prev = new_node;
        }
    }
}

void insertAtEnd(int data){
    if(tail == NULL){
        startLinkedList(data);
    }else{
        struct Node* new_node = new Node();
        count++;
        new_node->data = data;
        new_node->prev = tail;
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
        tail->next->prev = tail;
    }
}

void insertAtPosition(int pos,int data){
    if(pos == 1){
        insertAtBeginning(data);
    }else if(pos == count){
        insertAtEnd(data);
    }else{
        int count2 = 0;
        struct Node* ptr1 = tail->next;
        struct Node* ptr2 = tail->next;
        struct Node* new_node = new Node();
        count++;
        new_node->data = data;
        while((pos-1) != 0){
            ptr1 = ptr1->next;
            if(count2 != 0){
                ptr2 = ptr2->next;
            }
            pos--;
            count2++;
        }
        new_node->next = ptr1;
        new_node->prev = ptr2;
        ptr1->prev = new_node;
        ptr2->next = new_node;
    }
}

void deleteAtBeginning(){
    if(tail == NULL){
        
    }else{
        struct Node* ptr = tail->next;
        ptr->next->prev = tail;
        tail->next = ptr->next;
        free(ptr);
        count--;
    }
}

void deleteAtEnd(){
    if(tail == NULL){
        
    }else{
        struct Node* ptr = tail;
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        tail = tail->prev;
        free(ptr);
        count--;
    }
}

void deleteAtPosition(int pos){
    if(pos == 1){
        deleteAtBeginning();
    }else if(pos == count){
        deleteAtBeginning();
    }else if(pos > count){
        
    }else{
        int count2 = 0;
        struct Node* ptr1 = tail->next;
        struct Node* ptr2 = tail->next;
        while((pos-1) != 0){
            ptr1 = ptr1->next;
            if(count2 != 0){
                ptr2 = ptr2->next;
            }
            pos--;
            count2++;
        }
        ptr2->next = ptr1->next;
        ptr1->next->prev = ptr2;
        free(ptr1);
        count--;
     }
}

void display(){
    struct Node* ptr = tail->next;
    cout<<"   NPA     ND     NNA             NA\n\n";
    while(ptr->next != tail->next){
        cout<<ptr->prev<<"   "<<ptr->data<<"  "<<ptr->next<<"       "<<ptr<<"\n";
        ptr = ptr->next;
    }
    cout<<ptr->prev<<"   "<<ptr->data<<"  "<<ptr->next<<"       "<<ptr;
    cout<<"\n\n"<<"Length of Linked List is: "<<count;
}

int main()
{
   insertAtBeginning(1);
   insertAtBeginning(2);
   insertAtBeginning(3);
   insertAtBeginning(4);
   insertAtEnd(5);
   insertAtEnd(6);
   insertAtEnd(7);
   insertAtEnd(8);
   insertAtEnd(9);
   insertAtPosition(3,10);
   insertAtPosition(1,11);
   insertAtPosition(10,12);
   insertAtPosition(7,13);
   deleteAtBeginning();
   deleteAtBeginning();
   deleteAtBeginning();
   deleteAtEnd();
   deleteAtEnd();
   deleteAtEnd();
   deleteAtPosition(3);
   deleteAtPosition(5);
   deleteAtPosition(5);
   
   display();
   
   return 0;
}

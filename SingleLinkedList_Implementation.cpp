#include<iostream>
using namespace std ;

class node{
public:
  int data;
  node* NEXT;

  node(int value){
    this->data = value;
    this->NEXT = NULL;
  }
};

class LinkedList{
private:
  node* head;

public:
  LinkedList(){
      this->head = NULL;
  }

  void insertAtBegin(int value){
    node* newNode = new node(value);

    //If head is NULL then head will point to the new node
    if(this->head == NULL){
      head = newNode;
    }
    //If there are elements in linked list  then node will point to wherever head is pointing and then head will point to Node
    else{
    newNode->NEXT = head;
    head = newNode;
}
    return;
  }

  void insertAtTail(int value){
    node* newNode = new node(value);

    if(this->head == NULL){
      head = newNode;
    }
    else{
      node* temp = head ;
      while(temp->NEXT != NULL){
        temp = temp->NEXT;
      }
      temp->NEXT = newNode;
    }
    return;
  }

  void display(){
    node* node = this->head;
    while(node -> NEXT != NULL){
     cout<<node->data<<" -> ";
     node = node->NEXT ;
    }
    cout<<node->data<<"\n";
    return;
  }

  void insertAtK(int value , int pos){
    node* newNode = new node(value);

    // If linked list is empty insert at begin
    if(this->head == NULL){
      head = newNode;
    }
    // if linked list is not empty point newnode to the adress temp is pointing to
    else{
      node* temp = head ;
      // if we exceed the length of linked list stop the loop and insert at end
      while((--pos > 1)&&(temp->NEXT)){
        temp = temp -> NEXT;
      }
        newNode->NEXT = temp->NEXT ;
        temp->NEXT = newNode;
    }
    return;
  }

  void deleteAtBegin(){
    if(this->head == NULL){
      return;
    }
    node* temp = head;
    head = head -> NEXT;
    delete temp;
    return ;
  }

  void deleteAtEnd(){
    if(this->head == NULL){
      return ;
    }

    node* temp = head;
    //go to second last element
    while(temp->NEXT->NEXT != NULL){
      temp = temp -> NEXT ;
    }
    //delete last element
    delete temp->NEXT ;
    //point second last to NULL
    temp -> NEXT = NULL ;
    return ;
  }

  void deleteAtK(int k){
    if(this -> head == NULL || k == 0 ){
      return ;
    }

   node* temp = head ;
   //go to k-1 position
   while((--k > 1) && temp){
     temp = temp -> NEXT ;
   }
   // point previouse element to next element of k
   temp -> NEXT = temp -> NEXT -> NEXT ;
   // delete k
   delete temp -> NEXT ;
  }

  void deleteLinkedList(){
    if(this -> head == NULL){
      return;
    }

    node* temp = head ;
    while(temp -> NEXT != NULL){
      node* tempNext = temp -> NEXT ;
      delete temp -> NEXT ;
      temp = tempNext ;
    }
    return ;

  }

};

int main(){
  LinkedList ll ;
  ll.insertAtBegin(2);
  ll.insertAtBegin(3);
  ll.insertAtBegin(4);
  ll.insertAtBegin(5);
  ll.insertAtTail(1);
  ll.insertAtTail(10);
  ll.display();
  ll.insertAtK(100 , 4);
  ll.display();
  ll.deleteAtBegin();
  ll.deleteAtEnd();
  ll.display();
  ll.deleteAtK(4);
  ll.display();
  ll.deleteLinkedList();
  ll.display();

}

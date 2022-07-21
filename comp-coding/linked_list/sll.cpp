#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data  = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
            
        } 
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int d){ // Why take &head, so that we dont create another copy of head pointer
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail, int pos, int data){
    if(pos==0){
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int prev_pos = pos-1;
    while(prev_pos--){
        temp=temp->next;
    }

    Node* update_next = temp->next;
    if(update_next==NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* new_node = new Node(data);
    new_node->next = update_next;
    temp->next = new_node;
}
void deleteAtPosition(Node* &head,Node* &tail,int pos){

     
    Node* temp = head;
    if(pos==0){
        head = head->next;

        temp->next = NULL;
        delete temp;
        return;
    }   
    int prev_pos = pos-1;
    while(prev_pos--){
        temp=temp->next;
    }

    Node* del_node = temp->next;
    
    //last node
    if(del_node->next == NULL){
        tail= temp;
    }

    temp->next = del_node->next;

    del_node->next = NULL; // make pointers associated NULL before deletion
    delete del_node;

}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ->";
        temp=temp->next;
    }
    cout<<"X"<<endl;
}


int main(){
    //created a new node
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //head,tail pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    //head insertion
    insertAtHead(head,9);
    print(head);

    insertAtHead(head,8);
    print(head);

    //tail insertion
    insertAtTail(tail,11);
    print(head);

    insertAtTail(tail,13);
    print(head);

    //insert at position
    insertAtPosition(head,tail,4,12);
    print(head);

    insertAtPosition(head,tail,6,14);
    print(head);

    insertAtTail(tail,15);
    print(head);

    // delete at position
    deleteAtPosition(head,tail,1);
    print(head);
    cout<<"head data = "<<head->data<<", tail data = "<<tail->data<<endl;

    deleteAtPosition(head,tail,0);
    print(head);
    cout<<"head data = "<<head->data<<", tail data = "<<tail->data<<endl;

    deleteAtPosition(head,tail,5);
    print(head);
    cout<<"head data = "<<head->data<<", tail data = "<<tail->data<<endl;

    return 0;
}
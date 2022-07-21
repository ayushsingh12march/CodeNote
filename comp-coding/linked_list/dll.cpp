#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(next != NULL){
            next = NULL;
            delete next;
        }
        if(prev != NULL){
            prev = NULL;
            delete prev;
        }
        cout<<" The data is deleted : "<<value;

        
    }
};

int main(){


    return 0;
}
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
class Deque{
    Node* head; 
    Node* tail; 
    public:
    Deque();
    ~Deque();
    void enqueueFront(int value);
    void enqueueRear(int value);
    void dequeueFront();
    void dequeueRear();
    void display();
    void displayreverse();
    void search(int value);
    void insert(int value,int pos);
    void remove(int pos);
};
Deque::Deque(){
    head=nullptr;
    tail=nullptr;
}
Deque::~Deque(){
    while(head!=nullptr){
        Node* temp = head;
        head=head->next;
        delete temp;
    }
}
void Deque::enqueueFront(int value){
    Node* newNode = new Node;
    newNode->data= value;
    newNode->next=head;
    newNode->prev=nullptr;
    if(head==nullptr){
        tail=newNode;
        newNode->prev=nullptr;
    }
    else{
        head->prev=newNode;
    }
    head=newNode;
}
void Deque::enqueueRear(int value){
    Node* newNode = new Node;
    newNode->data=value;
    newNode->next=nullptr;
    newNode->prev=tail;
    if(head==nullptr){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
}
void Deque::dequeueFront(){
    if(head==nullptr) return;
    Node* current=head;
    if(head->next!=nullptr){
        head=head->next;
        head->prev=nullptr;
    }
    else{
        head=nullptr;
        tail=nullptr;
    }
    delete current;
}
void Deque::dequeueRear(){
    if(head==nullptr) return;
    Node* current=tail;
    if(tail->prev!=nullptr){
        tail->prev->next= nullptr;
        tail = tail->prev;
    }
    else{
        tail=nullptr;
        head=nullptr;
    }
    delete current;
}
void Deque::display(){
    Node* current = head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current= current->next;
    }
    cout<<"null"<<endl;
}
void Deque::displayreverse(){
    Node* current=tail;
    cout<<"null";
    while(current!=nullptr){
        cout<<"<-"<<current->data;
        current= current->prev;
    }
    cout<<endl;
}
void Deque::search(int value){
    Node* current = head;
    while(current!=nullptr){
        if(current->data==value){
            cout<<value<<" found in deque"<<endl;
            return;
        }
        current=current->next;
    }
    cout<<value<<" not found"<<endl;
}
void Deque::insert(int value, int pos){
    if(pos<0) return;
    if(pos==0) {enqueueFront(value); return;}
    Node* current= head;
    for(int i=0;i<pos-1 && current!=nullptr;i++){
        current = current->next;
    }
    if(current==nullptr) return;
    Node* newNode = new Node;
    newNode->data= value;
    current->next->prev= newNode;
    newNode->next=current->next;
    newNode->prev=current;
    if(newNode->next==nullptr){
        tail=newNode;
    }
    current->next=newNode;
}
void Deque::remove(int value){
    Node* current= head;
    while(current->data!=value && current!=nullptr){
        current = current->next;
    }
    if(current==nullptr) return;
    if(current->prev==nullptr){ dequeueFront(); }
    else{
        current->prev->next=current->next;
    }
    if(current->next==nullptr){
        tail=current->prev;
    }
    else{
    current->next->prev= current->prev;
    }
    delete current;
}
int main(){
    Deque deque;
    deque.enqueueFront(6);
    deque.enqueueFront(5);
    deque.enqueueFront(4);
    deque.display();
    deque.enqueueRear(7);
    deque.enqueueRear(8);
    deque.display();
    deque.dequeueFront();
    deque.dequeueRear();
    deque.display();
    deque.displayreverse();
    deque.search(6);
    deque.search(1);
    deque.insert(10,2);
    deque.display();
    deque.remove(10);
    deque.display();
}
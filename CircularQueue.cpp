#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class CircleQueue{
    Node* head;
    public:
    CircleQueue();
    ~CircleQueue();
    void enqueue(int value);
    void dequeue();
    void display();
    void insertBeg(int value);
    void insert(int value,int pos);
    void remove(int value);
    void removeEnd();
    void search(int value);
    void reverse();
    int count();
};
CircleQueue::CircleQueue(){
    head=nullptr;
}
CircleQueue::~CircleQueue(){
    if(head!=nullptr){
    Node* current=head->next;
    while(current!=head){
        Node* temp = current;
        delete temp;
        current = current->next;
    }
    delete current;
    }
}
void CircleQueue::enqueue(int value){
    Node* newNode= new Node;
    newNode->data=value;
    if(head==nullptr){
        head=newNode;
        newNode->next=head;
    }
    else{
        Node* current=head;
        while(current->next!=head){
            current=current->next;
        }
        current->next=newNode;
        newNode->next=head;
    }
}
void CircleQueue::dequeue(){
    if(head==nullptr) return;
    if(head->next==head){ head=nullptr; return;}
    Node* temp=head;
    Node* current= head;
    while(current->next!=head){
        current=current->next;
    }
    current->next=head->next;
    head=head->next;
    delete temp;
}
void CircleQueue::display(){
    if(head==nullptr) return;
    Node* current=head;
    do{
        cout<<current->data<<"->";
        current = current->next;
    }while(current!=head);
    cout<<"null"<<endl;
}
void CircleQueue::search(int value){
    Node* current=head->next;
    while(current!=head){
        if(current->data==value){
            cout<<value<<" found in queue"<<endl; return;
        }
        current=current->next;
    }
    cout<<value<<" not found"<<endl;
}
void CircleQueue::reverse(){
    if (head == nullptr) return;

    Node* prevNode = nullptr;
    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    } while (current != head);

    head = prevNode;
}
int CircleQueue::count(){
    Node* current= head->next; int count;
    for(count=0; current!=head;count++){
        current=current->next;
    }
    return ++count;
}
void CircleQueue::insertBeg(int value){
    Node* newNode = new Node;
    newNode->data= value;
    if(head==nullptr){
        head = newNode;
        newNode->next= head;
    }
    else{
    newNode->next= head->next;
    head->next=newNode;
    }
}
void CircleQueue::insert(int value,int pos){
    if(pos<0) return;
    if(pos==0) {insertBeg(value); return;}
    Node* newNode = new Node;
    newNode->data = value;
    Node* current = head;
    for(int i=0; i<pos-1 && current->next!=head; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void CircleQueue::removeEnd(){
    Node* current = head->next;
    while(current->next->next!=head){
        current = current->next;
    }
    Node* temp= current->next;
    current->next = head;
    delete temp;
}
void CircleQueue::remove(int value){
    Node* current = head;
    do{
        current = current->next;
    }while( current!=head && current->next->data != value);
    Node* temp = current->next;
    if(current->next!=head){
    current->next = current->next->next;}
    else{
    current->next = current->next->next;
        head = head->next;
    }
    delete temp;
}
int main(){
    CircleQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.display();
    cout<<"Count-"<<cq.count()<<endl;
    cq.insertBeg(10);
    cq.display();
    cq.insert(15,3);
    cq.display();
    cq.removeEnd();
    cq.display();
    cq.remove(2);
    cq.display();
    cq.search(15);
    cq.search(20);
    //cq.reverse(); not works
}
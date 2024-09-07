#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
    vector<int> heap;
    void heapup(){
        int i = heap.size()-1;
        int par= parent(i);
        while(heap[i]>heap[par] && i>0){
            swap(heap[i],heap[par]);
            i=par;
            par = parent(par);
        }
    }
    void heapdown(int n){
        int i=n;
        int left = leftchild(i);
        int right = rightchild(i);
        int largest = i;
        if(heap[left]>heap[largest] && left<heap.size()){
            largest=left;
        }
        if(heap[right]>heap[largest] && right<heap.size()){
            largest=right;
        }
        if(i!=largest){
            swap(heap[i],heap[largest]);
            heapdown(largest);
        }
    }
    public:
    int parent(int index){ return (index-1)/2;}
    int leftchild(int index){ return index*2 +1;}
    int rightchild(int index){ return index*2 +2;}
    void insert(int data);
    int deleteMax();
    int peek();
};
void MaxHeap::insert(int data){
    heap.push_back(data);
    if(heap.size()>1){
        heapup();
    }
};
int MaxHeap::deleteMax(){
    if(heap.empty())return -1;
    int max= heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heapdown(0);
    return max;
};
int MaxHeap::peek(){
    return heap.front();
}
int main(){
    MaxHeap mh;
    mh.insert(5);
    mh.insert(6);
    mh.insert(10);
    mh.insert(15);
    mh.insert(20);
    mh.insert(17);
    cout<<"Max value deleted-"<<mh.deleteMax()<<endl;
    cout<<"Max value left after deleting-"<<mh.peek()<<endl;
}
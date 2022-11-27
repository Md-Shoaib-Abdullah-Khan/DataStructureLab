#include<iostream>

using namespace std;

int MaxQueue, front, rear;
int queue[105];

void Qinsert( int item);
void Qdelete();
void print();
int main(){
    int i, num;
    MaxQueue=100;
    front = -1;
    rear=-1;
    Qinsert(6);
    Qinsert(35);
    print();
    Qinsert(53);
    print();
    Qdelete();

    
    print();
}

void Qinsert(int item){
    if((front==0&&rear==MaxQueue)||(front==rear+1)){
        cout<<"Overflow"<<endl;
        return;
    }
    if(front == -1&&rear==-1)front=0,rear=0;
    else if(rear==MaxQueue)rear=0;
    else rear++;
    queue[rear] = item;
    return;
}
void Qdelete(){
    if(front == -1){
        cout<<"Underflow"<<endl;
        return;
    }
   int item = queue[front]; 
    if(front == rear)rear=-1,front =-1;
    else if(front ==MaxQueue)front =0;
    else front++;
    return;
}
void print(){
    for(int i=front; i<=rear; i++)cout<<" "<<queue[i];
    cout<<endl;
    return;
}
#include<iostream>
using namespace std;
int front=0, rear = 0,n=0;
int queue[100];

void Qinsert(int n, int item);
int Qdelete(int n);
void Qprint();

int main(){

int n=10;
for(int i=1;i<6;i++){

    Qinsert(n,i*2);
}
Qprint();
int a =Qdelete(n);
Qprint();

}


void Qinsert(int n, int item){
    if((front == 1 && rear == n)||front == rear+1){
        cout<<"Overflow"<<endl;;
        return;
    }
    else if(front == 0 && rear == 0)front =1, rear =1;
    else if(rear == n)rear =1;
    else rear++;
    queue[rear]=item;
    return;
}

int Qdelete(int n){
     int item;
    if(front == 0){
        cout<<"Underflow"<<endl;
        return 0;
    }
    item = queue[front];
    if(front == rear)front = 0, rear = 0;
    else if(front == n) front =1;
    else front++;

    return item;

}

void Qprint(){
    if(front == 0){
        cout<<"No element!"<<endl;
        return;
    }
    int i=front;
    while(i != rear){
        cout<<queue[i]<<" ";
        i++;
        if(i==n+1)i=1;
    }
    cout<<queue[rear]<<endl;
    return;
}
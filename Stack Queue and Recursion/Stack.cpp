#include<iostream>

using namespace std;

int MaxStack, Top;
int stack[100];

void push( int item);
void pop();
void print();
int main(){
    int i, num;
    MaxStack=10;
    Top = -1;
    push( 35);
    push( 6);
    push( 53);
    print();
    pop();
    
    print();
}

void push(int item){
    if(Top == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top++;
    stack[Top] = item;
    return;
}
void pop(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return;
    }
   int item = stack[Top]; 
    Top--;
    return;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<stack[i];
    cout<<endl;
    return;
}
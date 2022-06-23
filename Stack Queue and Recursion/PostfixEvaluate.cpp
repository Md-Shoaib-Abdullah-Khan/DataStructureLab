
#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;

int MaxStack, Top;
int Stack[100];
vector<int> digits;

void push( int item);
int pop();
void print();
void PostfixEvaluate(string str);
int digitToNum();
int main(){
    int i, num;
    MaxStack=10;
    Top = -1;
    string s = "5,6,7+-";
    
    PostfixEvaluate(s);
    print();
}

int digitToNum(){
    int num=0,i,j;
    for(i = digits.size()-1, j=1; i>=0;i--, j=j*10)
        num += digits[i]*j;
    return num;
}
void PostfixEvaluate(string str){
    for(int i=0;i<str.size(); i++){
        if(str[i] - '0'>=0 && str[i] - '0'<=9)digits.push_back(str[i] - '0');
        else{
            if(!digits.empty())push(digitToNum());
            if(str[i] != ',') {
                int b = pop();
                int a = pop();
                if(str[i] == '+') push(a+b);
                else if(str[i] == '-') push(a-b);
                else if(str[i] == '*') push(a*b);
                else if(str[i] == '/') push(a/b);
                else if(str[i] == '^') push(pow(a,b));
            }
            digits.clear();

        }
    }

}

void push(int item){
    if(Top == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top++;
    Stack[Top] = item;
    return;
}
int pop(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return 0;
    }
   int item = Stack[Top]; 
    Top--;
    return item;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<Stack[i];
    cout<<endl;
    return;
}
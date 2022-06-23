
#include<iostream>
#include<string.h>

using namespace std;

int MaxStack, Top;
char Stack[100];

void push( char item);
char pop();
void print();
void infixToPostfix(string str);
int preference(char x);
void PostfixEvaluate(string str);
int digitToNum();
int main(){
    int i, num;
    MaxStack=100;
    Top = -1;
    string s = "(A+(B*C-(D/E^F)*G)*H)";
    //s = s+ ")";
    //cout<<s;
    infixToPostfix(s);
    
    

}
void infixToPostfix(string str){
    for(int i=0;i<str.size(); i++){
        //cout<<str[i]<<endl;
        if(str[i] == ')'){
            char bottom;
            while(1){
                bottom = pop();
                if(bottom == '(')break;
                else cout<<bottom;
            }
            
        }
        else if(str[i]-'A' >=0 && str[i]-'A'<=26)cout<<str[i];
        else if(str[i] == '(')push(str[i]);
        else{
            char a = pop();
            if(a == '+' || a =='-'|| a =='*'|| a =='/'|| a =='^'){
                if(preference(str[i]) < preference(a)){
                    cout<<a;
                    push(str[i]);
                }
                else{
                    push(a);
                    push(str[i]);
                }
            }
            else {
                push(a);
                push(str[i]);
            }
        }
    }

}

void push(char item){
    if(Top == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top++;
    Stack[Top] = item;
    //cout<<item<<endl;
    return;
}
char pop(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return 0;
    }
   char item = Stack[Top]; 
    Top--;
    return item;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<Stack[i];
    cout<<endl;
    return;
}
int preference(char x){
    if(x == '+')return 0;
    else if(x=='-')return 0;
    else if(x=='*') return 1;
    else if(x=='/')return 1;
    else if(x=='^') return 2;
    
}
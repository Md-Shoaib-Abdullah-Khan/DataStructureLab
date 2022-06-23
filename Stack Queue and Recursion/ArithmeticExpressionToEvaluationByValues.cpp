
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;

int MaxStack, Top;
char Stack[100];
int Stack1[100];
vector<int> digits;
string floatDigits;
string postfix;


void push( char item);
char pop();
void print();
void infixToPostfix(string str);
int preference(char x);
void PostfixEvaluate(string str);
void push1(int item);
int pop1();
int main(){
    int i, num;
    MaxStack=100;
    Top = -1;
    string s1 = "15,6,7+-";
    string s2 = "(5+6)";
    //s = s+ ")";
    //cout<<s;
    infixToPostfix(s2);
    cout<<postfix<<endl;
    postfix.pop_back();
   // PostfixEvaluate(postfix);
    //print();
    //cout<<postfix<<endl;
    
    

}
int digitToNum(){
    int num=0,i,j;
    for(i = digits.size()-1, j=1; i>=0;i--, j=j*10)
        num += digits[i]*j;
    return num;
}
void PostfixEvaluate(string str){
    for(int i=0;i<str.size(); i++){
        if(str[i] - '0'>=0 && str[i] - '0'<=9)digits.push_back(str[i]-'0');
        else{
            if(!digits.empty())push1(digitToNum());
            if(str[i] != ',') {
                int b = pop1();
                int a = pop1();
                if(str[i] == '+') push1(a+b);
                else if(str[i] == '-') push1(a-b);
                else if(str[i] == '*') push1(a*b);
                else if(str[i] == '/') push1(a/b);
                else if(str[i] == '^') push1(pow(a,b));
            }
            digits.clear();

        }
    }

}
void infixToPostfix(string str){
    for(int i=0;i<str.size(); i++){
        //cout<<str[i]<<endl;
        if(str[i] == ')'){
            char bottom;
            while(1){
                bottom = pop();
                if(bottom == '(')break;
                else {
                    postfix+=bottom;
                    postfix+=",";
                }
            }
            
        }
        else if(str[i]-'0' >=0 && str[i]-'9'<=9 || str[i] == '.'){
            floatDigits += str[i];
            // postfix+=str[i];
            // postfix+=",";
            }
        else if(str[i] == '('){
            push(str[i]);
            }
        else{
            char a = pop();
            if(a == '+' || a =='-'|| a =='*'|| a =='/'|| a =='^'){
                if(preference(str[i]) < preference(a)){
                    postfix+=a;
                    postfix+=",";
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
        if((str[i]-'0' <0 || str[i]-'9'>9) && str[i] != '.'){
         if(!floatDigits.empty()){
                postfix+=floatDigits;
                postfix +=",";
                floatDigits.clear();
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

int preference(char x){
    if(x == '+')return 0;
    else if(x=='-')return 0;
    else if(x=='*') return 1;
    else if(x=='/')return 1;
    else if(x=='^') return 2;
    
}
void push1(int item){
    if(Top == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top++;
    Stack1[Top] = item;
    return;
}
int pop1(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return 0;
    }
   int item = Stack1[Top]; 
    Top--;
    return item;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<Stack1[i];
    cout<<endl;
    return;
}
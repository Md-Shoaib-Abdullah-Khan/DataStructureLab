#include<iostream>
#include<vector>

using namespace std;

int MaxStack, Top;
char stack[101];

vector<char> expression;

void push(char item);
char pop();
void print();
void infixToPostfix(string s);
bool precision(char x, char y);

int main(){
    int i, num;
    MaxStack=100;
    Top = -1;
    string s;
    cin>>s;
    s =  s + ')';
    push('(');
    
    infixToPostfix(s);
    

    for(i=0;i<expression.size();i++)cout<<expression[i];
    cout<<endl;

}

void infixToPostfix(string s){

    for(int i=0;i<s.size();i++){
        if(Top == -1)return;
        if(s[i] == '(') push('(');
        else if(s[i] >=65 && s[i] <= 90) expression.push_back(s[i]);
        else if(s[i] == ')'){
            char x = pop();
            while(x != '('){
                expression.push_back(x);
                x= pop();
            }
        }
        else{
            char x = pop();
            while(x != '(' && precision(s[i], x)){
                expression.push_back(x);
                x= pop();
            }
             push(x);
             push(s[i]);
        }
        
    }
}

bool precision(char x, char y){
    int a,b;
    if(x == '^')a = 2;
    else if(x == '/' || x == '*')a=1;
    else a=0;
    if(y == '^')b = 2;
    else if(y == '/' || y == '*')b=1;
    else b=0;
    if(a<b)return true;
    else return false;
}

void push(char item){
    if(Top == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top++;
    stack[Top] = item;
    return;
}
char pop(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return -1;
    }
   char item = stack[Top]; 
    Top--;
    return item;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<stack[i];
    cout<<endl;
    return;
}
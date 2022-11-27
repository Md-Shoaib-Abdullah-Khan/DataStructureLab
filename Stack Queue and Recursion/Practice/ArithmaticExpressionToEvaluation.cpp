#include<iostream>
#include<vector>

using namespace std;

int MaxStack, Top;
char stack[101];

vector<char> expression;
vector<int>digits;

void push(char item);
char pop();
void print();
void infixToPostfix(string s);
bool precision(char x, char y);


int Top1;
int stack1[101];

void push1(int item);
char pop1();
void print1();
void postfixEvaluation(string s);
int digitsToNum();

int main(){
    int i, num;
    MaxStack=100;
    Top = -1;
    Top1=-1;
    string s;
    cin>>s;
    s =  s + ')';
    push('(');
    
    infixToPostfix(s);
    
    string s1="";
    for(i=0;i<expression.size();i++){
        cout<<expression[i];
        s1+=expression[i];
    }
    cout<<endl;

    postfixEvaluation(s1);
    print1();


}
void push1(int item){
    if(Top1 == MaxStack){
        cout<<"Overflow"<<endl;
        return;
    }
    Top1++;
    stack1[Top1] = item;
    return;
}
char pop1(){
    if(Top1==-1){
        cout<<"Underflow"<<endl;
        return -1;
    }
   int item = stack1[Top1]; 
    Top1--;
    return item;
}
void print1(){
    for(int i=0; i<=Top1; i++)cout<<stack1[i]<<" ";
    cout<<endl;
    return;
}
void postfixEvaluation(string s){

    for(int i=0;i<s.size();i++){

        if(s[i]-'0'>=0 && s[i]-'0'<=9)digits.push_back(s[i]-'0');
        else {
            if(!digits.empty())push1(digitsToNum());
            if(s[i]!=','){
                int x,y;
                x=pop1();
                y=pop1();
                if(s[i]=='+')push1(x+y);
                else if(s[i]=='-')push1(y-x);
                else if(s[i]=='*')push1(y*x);
                else if(s[i]=='/')push1(y/x);
                else if(s[i]=='^')push1(y^x);
            }
            digits.clear();
        }
    }
    
}

void infixToPostfix(string s){
    bool new_num=false;

    for(int i=0;i<s.size();i++){
        if(Top == -1)return;
        if(s[i] == '(') push('(');
        else if(s[i]-'0' >=0 && s[i]-'0' <= 9) {
            if(new_num)expression.push_back(',');
            expression.push_back(s[i]);
            new_num=false;
            }
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
             new_num=true;
        }
        
        
    }
}
int digitsToNum(){
    int num =0,j,i;
    for(i=digits.size()-1, j=1; i>=0;i--,j=j*10)num+=digits[i]*j;
    return num;
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
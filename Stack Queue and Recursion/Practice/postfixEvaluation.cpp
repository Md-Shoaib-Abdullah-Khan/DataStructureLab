#include<iostream>
#include<vector>

using namespace std;

int MaxStack, Top;
int stack[101];
vector<int>digits;


void push(int item);
char pop();
void print();
void postfixEvaluation(string s);
int digitsToNum();


int main(){
    int i, num;
    MaxStack=100;
    Top = -1;
    string s="15,6,7+-";
    
    
    postfixEvaluation(s);
    print();

}

void postfixEvaluation(string s){

    for(int i=0;i<s.size();i++){

        if(s[i]-'0'>=0 && s[i]-'0'<=9)digits.push_back(s[i]-'0');
        else {
            if(!digits.empty())push(digitsToNum());
            if(s[i]!=','){
                int x,y;
                x=pop();
                y=pop();
                if(s[i]=='+')push(x+y);
                else if(s[i]=='-')push(y-x);
                else if(s[i]=='*')push(y*x);
                else if(s[i]=='/')push(y/x);
                else if(s[i]=='^')push(y^x);
            }
            digits.clear();
        }
    }
    
}

int digitsToNum(){
    int num =0,j,i;
    for(i=digits.size()-1, j=1; i>=0;i--,j=j*10)num+=digits[i]*j;
    return num;
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
char pop(){
    if(Top==-1){
        cout<<"Underflow"<<endl;
        return -1;
    }
   int item = stack[Top]; 
    Top--;
    return item;
}
void print(){
    for(int i=0; i<=Top; i++)cout<<" "<<stack[i];
    cout<<endl;
    return;
}
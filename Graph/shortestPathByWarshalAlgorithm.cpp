#include<iostream>
#include<vector>
using namespace std;
int n;

int path[100][100];

void warshal(){

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                    path[i][j] = min(path[i][j] , (path[i][k] + path[k][j]));
}
int main(){
    int m;
    cin>>n>>m;
for(int i=1; i<=n; i++){
       for(int j=0; j<=n; j++)
        {
            path[i][j] = 100000;
        }
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        path[a][b] = c;
    }
   warshal();
    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
}
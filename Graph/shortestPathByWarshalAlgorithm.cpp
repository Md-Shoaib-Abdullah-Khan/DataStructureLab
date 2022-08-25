#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

#define inf 1000000000

int n;
vector<vector<int>>matrix;


int main(){
    cin>>n;
    int path[n][n];

    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++)
        {
            path[i][j] = inf;
        }
    }
    for(int i=0; i<n; i++){
        int a,b,value;
        cin>>a>>b>>value;
        if(!value)path[a][b] = value;
    }

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                    path[i][j] = min(path[i][j] , path[i][k] + path[k][j]);

    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
}
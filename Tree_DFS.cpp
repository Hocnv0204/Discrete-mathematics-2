#include<bits/stdc++.h>
using namespace std;
int n , s ; 
int a[100][100];
bool visited[100];
vector < pair < int , int > > res;
void init(){
    for(int i = 1 ; i<= n ; i ++){
        visited[i] = true;
    }
}
void input(){
    cin >> n >> s;
    init();
    for(int i = 1 ; i <= n ;i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> a[i][j];
        }
    }
}
void Tree_DFS(int u){
    visited[u] = false;
    for(int i = 1 ; i <= n ; i ++){
        if(visited[i] && a[u][i]){
            res.push_back({u,i});
            Tree_DFS(i);
        }
    }
}
int  main(){
    input();
    Tree_DFS(s);
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
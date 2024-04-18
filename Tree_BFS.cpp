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
void Tree_BFS(int u){
    queue < int > q;
    q.push(u);
    visited[u] = false;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; i ++){
            if(visited[i] && a[v][i]){
                q.push(i);
                visited[i] = false;
                res.push_back({v,i});
            }
        }
    }
}
int  main(){
    input();
    Tree_BFS(s);
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n , s , t;
int a[100][100];
bool visited[100];
int parent[100];
void input(){
    memset (visited , false , sizeof(visited));
    cin >> n >> s >> t;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ;  j <= n ;j ++){
            cin >> a[i][j];
        }
    }
}
void DFS(int st){
    visited[st] = true;
    for(int i = 1 ; i <= n ;i ++){
        if( a[st][i] && !visited[i]){
            parent[i] = st;
            DFS(i);
        }
    }
}
int main(){
    input();
    DFS(s);
    vector <int> path;
    while( t != s){
        path.push_back(t);
        t = parent[t];
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    for(int x : path){
        cout << x << " ";
    }
    return 0;
}
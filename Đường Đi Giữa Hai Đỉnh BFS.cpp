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
void BFS(int st){
    queue <int> q;
    q.push(st);
    visited[st] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; i ++){
            if(a[u][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
                parent[i] = u;
            }
        }
    }
}
int main(){
    input();
    BFS(s);
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
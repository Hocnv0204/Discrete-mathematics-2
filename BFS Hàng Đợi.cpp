#include<bits/stdc++.h>
using namespace std;
int n,st ;
int a[100][100];
bool visited[100];
void input(){
    cin >> n >> st; 
    memset (visited, false , sizeof(visited));
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> a[i][j];
        }
    }
}
void BFS(int u){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(int i = 1 ; i <= n ; i ++){
            if(a[v][i] == 1 && visited[i] == 0){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    input();
    BFS(st);
    cout << endl;
    return 0;
}
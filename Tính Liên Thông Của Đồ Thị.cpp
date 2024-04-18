#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
bool visited[100];
void nhap(){
    cin >> n;
    memset (visited , false , sizeof(visited));
    for(int i = 1 ; i <= n ;i ++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
        }
    }
}
int BFS(int u){
    int cnt = 1;
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int s = q.front();
        q.pop();
    for(int i = 1 ; i <= n ; i++){
        if(a[s][i] && !visited[i]){
            visited[i] = true;
            q.push(i);
            cnt++;
            }
        }
    }
    return cnt ;
}
bool Strongly_Connected(){
    memset(visited , false , sizeof(visited));
    for(int i = 1 ; i <= n ; i ++){
        if(BFS(i) != n )
        return false;
        else
        memset(visited , false , sizeof(visited));
    }
    return true;
}
int main(){
    nhap();
    if(Strongly_Connected())
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
    return 0;
}
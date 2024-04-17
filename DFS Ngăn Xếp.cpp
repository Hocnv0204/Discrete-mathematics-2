#include<bits/stdc++.h>
using namespace std;
int n ,st;
int a[100][100];
bool visited[100];
void input(){
    cin >> n >> st;
    for(int i = 1 ; i <= n ;i ++){
        for(int j = 1 ; j <= n ;j ++){
            cin >> a[i][j];
        }
    }
}
void DFS(int u){
    stack <int> s;
    s.push(st);
    visited[st] = true;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        cout << v <<" ";
        for(int i = n  ; i >= 1 ; i--){
            if(a[v][i] == 1 && !visited[i]){
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    input();
    visited[st] = true;
    DFS(st);
    cout << endl;
    return 0;
 }
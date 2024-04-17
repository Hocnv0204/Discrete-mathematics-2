#include<bits/stdc++.h>
using namespace std;
int n , st;
int a[100][100];
bool visited[100];
void input(){
    cin >> n >> st;
    memset(visited,false ,sizeof(visited));
    for(int i = 1 ; i <= n ;i ++ ){
        for(int j = 1 ; j <= n ; j ++){
            cin >> a[i][j];
        }
    }
}
void DFS( int v){
    cout << v << " ";
    for(int i = 1 ; i <= n ;i ++){
        if(a[v][i] == 1 && visited[i] == false){
            visited[i] = true;
            DFS(i);
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
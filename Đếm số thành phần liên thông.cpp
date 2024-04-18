#include<bits/stdc++.h>
using namespace std;
int n , st;
int a[100][100];
bool visited[100];
int value;
void input(){
    value = 0;
    memset (visited , false , sizeof(visited));
    cin >> n >> st;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ;  j <= n ;j ++){
            cin >> a[i][j];
        }
    }
}
void DFS(int st){
    cout << st << " ";
    for(int i = 1 ; i <= n ;i ++){
        if( a[st][i] && !visited[i]){
            visited[i] = true;
            DFS(i);
        }
    }
}
int main(){
    input();
    visited[st] = true;
    for(int i = 1 ; i <= n ; i ++){
        if(!visited[i]){
            visited[i] = true;
            value ++;
            DFS(i);
            cout << endl;
        }
    }
    cout << value << endl;
    return 0;
}
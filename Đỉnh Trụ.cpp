#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
bool visited[100];
void init(){
    for(int i = 1 ; i <= n ; i++){
        visited[i] = false;
    }
}
void nhap(){
    init();
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++)
        cin >> a[i][j];

    }
}
void DFS(int u){
    visited[u] = true;
    for(int i = 1 ; i <= n ; i ++){
        if(a[u][i] && !visited[i]){
            visited[i] = true;
            DFS(i);
        }
    }
}
int tplt(){
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++){
        if(!visited[i]){
            ++ cnt;
            DFS(i);
        }
    }
    return cnt ;
}
void dinh_tru(){
    int cc = tplt();
    for(int i = 1 ; i <= n ; i++){
        init();
        visited[i] = true;
        if(tplt() > cc){
            cout << i << " ";
        }
    }
}
int main(){
    nhap();
    dinh_tru();
    cout << endl;
    return 0;
}
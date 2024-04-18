#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
bool visited[100];
set <pair < int ,int > > se;
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
void canh_cau(){
    int cc = tplt();
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            if(a[i][j]){
                init();
                a[i][j] = 0;
                a[j][i] = 0;
                if(tplt() > cc ){
                    int s = max( i , j); 
                    int t = min (i , j);
                    se.insert({t,s});
                }
                a[i][j] = 1;
                a[j][i] = 1;            }
        }
    }
}
int main(){
    nhap();
    canh_cau();
    for(auto x : se){
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    return 0;
}
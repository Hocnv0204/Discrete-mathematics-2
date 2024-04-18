#include<bits/stdc++.h>
using namespace std;
int n , a[100][100] , s;
bool visited[100];
int x[100];
void init(){
    for(int i = 1 ; i <= n ; i++){
        visited[i] = true;
    }
}
void input(){
    cin >> n >> s;
    init();
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1; j <= n; j ++)
            cin >> a[i][j];
    }
    x[1] = s;
    visited[s] = false;
}
void hmt(int k){
    for(int y = 1 ; y <= n ; y++)
        if(a[x[k-1]][y] == 1)
        if(k == n + 1 && y == x[1] ){
            for(int i = 1 ; i <= n ; i++){
                cout << x[i] << " ";
            }
            cout << x[1] << endl;
        }
        else{
            if(visited[y]){
                x[k] = y;
                visited[y] = false;
                hmt(k+1);
                visited[y] = true;
            }
        }
    }


int main(){
   input();
   hmt(2);
    return 0;
}

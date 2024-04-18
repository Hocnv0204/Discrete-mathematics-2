#include<bits/stdc++.h>
using namespace std;
int n , a[100][100] , s;
bool visited[100];
vector <int> result;
void init(){
    for(int i = 1 ; i <= n ; i++){
        visited[i] = false;
    }
}
void input(){
    cin >> n >> s;
    init();
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++)
        cin >> a[i][j];
    }
}
void Euler_Cycle(int u){
    stack <int> st;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        int index = 1;
        for(int i = 1 ; i <= n ;i ++){
            if(a[s][i]){
                index = 0;
                st.push(i);
                a[s][i] = 0 ; a[i][s] = 0;
                break;
            }
        }
            if(index){
                st.pop();
                result.push_back(s);
            }
    }
    reverse(result.begin(),result.end());
}
int main(){
    input();
    Euler_Cycle(s);
    int num = result.size();
    for(int i = 0 ; i < num ; i ++){
        if(i < num - 1)
            cout << result[i] << "->" ;
            else
            cout << result[i];
    }
    cout << endl;
    return 0;
}
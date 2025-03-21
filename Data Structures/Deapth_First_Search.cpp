#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
 
int di[4]={-1, 1, 0, 0};
int dj[4]={0, 0, -1, 1};
         //U, D, L, R
 
vector<vector<char>> mapa;
vector<vector<bool>> visited;
 
bool esValido(int i, int j){
    return(i>=0 && i<n && j>=0 && j<m);
}
 
void DFS(int i, int j){
     visited[i][j]=true;
    for(int dir=0; dir<4; ++dir){
        int x=i+di[dir];
        int y=j+dj[dir];
        if(esValido(x, y) && mapa[x][y]!='#' && !visited[x][y]){
            DFS(x, y);
        }
    }
}
 
int main()
{
    
    cin>>n>>m;
    visited=vector<vector<bool>> (n, vector<bool> (m, false));
    mapa=vector<vector<char>> (n, vector<char> (m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin>>mapa[i][j];
        }
    }
    int componentes=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(mapa[i][j]=='.'){
                if(!visited[i][j]){
                    DFS(i, j);
                    componentes++;
                }
            }
        }
    }
    cout<<componentes<<endl;
}

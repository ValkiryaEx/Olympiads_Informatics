#include <bits/stdc++.h>
 
using namespace std;

const int mod=1e9+7;

struct Matrix{
    vector<vector<long long>> A;
    Matrix(vector<vector<long long>> I){
        A=I;
    }
    Matrix operator * (const Matrix& B){
        Matrix C({{0,0},{0,0}});
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    C.A[i][j]+=A[i][k]*B.A[k][j]%mod;
                    C.A[i][j]%=mod;
                }
            }
        }
        return C;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n; 
    cin>>n;
    Matrix I({{1,0},{0,1}}), X({{0,1},{1,1}});
    while(n>0){
        if(n%2)I=X*I;
        X=X*X;
        n/=2;
    }
    cout<<I.A[0][1]<<endl;
}

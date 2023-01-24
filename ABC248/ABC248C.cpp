#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
int ctoi(char c){
    return c - '0';
}
int main(){
    int n,m,k;
    ull out=0;
    cin >> n >> m >> k;
    vector<vector<ull>> dp(n+1,vector<ull>(k+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int l=1;l<=m;l++){
                if(j+l<=k){
                    dp[i+1][j+l]+=dp[i][j];
                    dp[i+1][j+1]%=998244353;
                }
                else if(j+l>k){
                    break;
                }
            }
        }
    }
    for(int i=1;i<=k;i++){
        out+=dp[n][i];
        out%=998244353;
    }
    cout << out << endl;
}

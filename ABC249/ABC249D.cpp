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
const int m = 200001;
int c[m];
int main(){
    int n,x,mx=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        mx = max(x,mx);
        c[x]++;
    }
    ull o = 0;
    for(int i=1;i<=mx;i++){
        for(int j=1;i*j<=mx;j++){
            o += (ull)c[i*j]*c[i]*c[j];
        }
    }
    cout << o << endl;
}
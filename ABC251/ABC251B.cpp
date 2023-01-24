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
bool prime(ull x){
    bool f = true;
    ull x_root = sqrt(x);
    for(int i=2;i<=x_root;i++){
        if(x%i==0){
            f = false;
            break;
        }
    }
    return f;
}
int main(){
    unordered_set<int> out;
    int n,w;
    cin >> n >> w;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<=w){
            out.insert(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(a[i]+a[j]<=w){
                out.insert(a[i]+a[j]);
            }
            for(int k=0;k<n;k++){
                if(j==k||i==k){
                    continue;
                }
                if(a[i]+a[j]+a[k]<=w){
                    out.insert(a[i]+a[j]+a[k]);
                }
            }
        }
    }
    cout << out.size() << endl;
}

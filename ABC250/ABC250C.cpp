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
    int n,q,s,t;
    cin >> n >> q;
    int x[q];
    int a[n+1],pos[n+1];
    for(int i=0;i<n;i++){
        a[i+1]=i+1;
        pos[i+1]=i+1;
    }
    for(int i=0;i<q;i++){
        cin >> x[i];
        if(pos[x[i]]==n){
            s=a[pos[x[i]]];
            t=a[pos[x[i]]-1];
            a[pos[x[i]]]=t;
            a[pos[x[i]]-1]=s;
            pos[s]--;
            pos[t]++;
        }
        else{
            s=a[pos[x[i]]];
            t=a[pos[x[i]]+1];
            a[pos[x[i]]]=t;
            a[pos[x[i]]+1]=s;
            pos[s]++;
            pos[t]--;
        }
    }
    cout << a[1];
    for(int i=2;i<n+1;i++){
        cout << ' ' << a[i];
    }
    cout << endl;
}

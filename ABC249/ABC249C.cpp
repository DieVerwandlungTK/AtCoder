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
    int n,k,out=0,c=0;
    cin >> n >> k;
    string s[n];
    vi alphabet(26,0);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<(1<<n);i++){
        cout << "i=" << i << endl;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                for(int l=0;l<s[j].size();l++){
                    alphabet[s[j][l]-'a']++;
                }
            }
        }
        for(int j=0;j<26;j++){
            if(alphabet[j]==k){
                c++;
            }
        }
        out = max(c,out);
        c=0;
        for(int j=0;j<26;j++){
            alphabet[j]=0;
        }
    }
    cout << out << endl;
}
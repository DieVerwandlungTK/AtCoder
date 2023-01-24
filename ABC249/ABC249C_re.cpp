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
    int n,k;
    cin >> n >> k;
    string s[n];
    int str_alphabet[n][26];
    memset(str_alphabet,0,sizeof(str_alphabet));
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(int j=0;j<s[i].size();j++) str_alphabet[i][s[i][j]-'a']++;
    }
    int sum_alphabet[26];
    int sum,sum_max=0;
    for(int i=1;i<(1<<n);i++){
        sum = 0;
        memset(sum_alphabet,0,sizeof(sum_alphabet));
        for(int j=0;j<n;j++) if((i>>j)&1) for(int l=0;l<s[j].size();l++) sum_alphabet[s[j][l]-'a']++;
        for(int j=0;j<26;j++) if(sum_alphabet[j]==k) sum++;
        sum_max = max(sum,sum_max);
    }
    cout << sum_max << endl;
}

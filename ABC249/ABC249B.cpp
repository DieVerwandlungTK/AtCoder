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
    bool f1=0,f2=0,f3=1;
    string s;
    cin >> s;
    set<char> str;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z') f1=1;
        if(s[i]>='a'&&s[i]<='z') f2=1;
        if(str.count(s[i])){
            f3=0;
            break;
        }
        else{
            str.insert(s[i]);
        }
    }
    if(f1&&f2&&f3) cout << "Yes" << endl;
    else cout << "No" << endl;
}
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
    string s;
    cin >> s;
    if(s.size()==1){
        cout << s << s << s << s << s << s ;
    }
    else if(s.size()==2){
        cout << s << s << s;
    }
    else{
        cout << s << s;
    }
    cout << endl;
}

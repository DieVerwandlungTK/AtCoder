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
    ull a,b,c,d,e,f,x,distaka=0,disao=0;
    cin >> a >> b >> c >> d >> e >> f >> x;
    distaka += x/(a+c)*a*b;
    if(x%(a+c)>a){
        distaka += a*b;
    }
    else{
        distaka += (x%(a+c))*b;
    }
    disao += x/(d+f)*d*e;
     if(x%(d+f)>d){
        distaka += d*e;
    }
    else{
        distaka += (x%(d+f))*e;
    }
    disao += (x%(d+f))*e;
    if(distaka>disao){
        cout << "Takahashi" << endl;
    }
    else if(disao>distaka){
        cout << "Aoki" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
}
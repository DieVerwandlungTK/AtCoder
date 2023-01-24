#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull = unsigned long long;
int ctoi(char c){
    return c - '0';
}
int main(){
    ull k,a,b,c=0;
    cin >> a >> b >> k;
    while(b>a){
        a*=k;
        c++;
    }
    cout << c << endl;
}

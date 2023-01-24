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
    int H,W,R,C,c=0;
    cin >> H >> W >> R >> C;
    if(R+1!=H+1){
        c++;
    }
    if(R-1!=0){
        c++;
    }
    if(C+1!=W+1){
        c++;
    }
    if(C-1!=0){
        c++;
    }
    cout << c << endl;
}
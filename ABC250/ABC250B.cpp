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
    int n,a,b;
    cin >> n >> a >> b;
    string x,y;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<b;j++){
                x += '.';
                y += '#';
            }
        }
        else{
            for(int j=0;j<b;j++){
                x += '#';
                y += '.';
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<a;j++){
                cout << x << endl;
            }
        }
        else{
            for(int j=0;j<a;j++){
                cout << y << endl;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int ctoi(char c){
    return c - '0';
}
int main(){
    string number;
    cin >> number;
    set<int> N;
    for(int i=0;i<9;i++){
        N.insert(ctoi(number[i]));
    }
    for(int i=0;i<10;i++){
        if(!N.count(i)){
            cout << i << endl;
        }
    }
}
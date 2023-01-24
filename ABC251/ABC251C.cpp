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
    int n;
    pii fp={0,0};
    cin >> n;
    vector<pair<int,pair<string,int>>> list(n);
    unordered_set<string> memory;
    for(int i=0;i<n;i++){
        list[i].first=i;
        cin >> list[i].second.first >> list[i].second.second;
        if(memory.count(list[i].second.first)){
            continue;
        }
        else{
            memory.insert(list[i].second.first);
        }
        if(fp.second<list[i].second.second){
            fp.first=i;
            fp.second=list[i].second.second;
        }
    }
    cout << fp.first+1 << endl;
}
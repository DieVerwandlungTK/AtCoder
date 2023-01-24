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
    unordered_set<ull> prime_list;
    vector<ull> sum={0,0};
    ull n,q_max,c=0;
    cin >> n;
    q_max=cbrt((n/2));
    for(ull i=2;i<=q_max;i++){
        if(prime(i)){
            prime_list.insert(i);
            sum.push_back(*(sum.end()-1)+1);
        }
        else{
            sum.push_back(*(sum.end()-1));
        }
    }
    for(ull q:prime_list){
        ull p_max=min(q-1,n/q/q/q);
        c += sum[p_max];
    }
    cout << c << endl;
}

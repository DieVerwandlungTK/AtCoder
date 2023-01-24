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
    ull n,q_max,c=0;
    unordered_set<ull> prime_list;
    prime_list.insert(2);
    cin >> n;
    q_max = cbrt((n/2));
    for(ull q=3;q<=q_max;q++){
        if(prime_list.count(q)){
        }
        else if(prime(q)){
            prime_list.insert(q);
        }
        else{
            continue;
        }
        for(ull p=2;p*pow(q,3)<=n;p++){
            if(p>=q){
                break;
            }
            if(prime_list.count(p)){
                c++;
            }
        }
    }
    cout << c << endl;
}

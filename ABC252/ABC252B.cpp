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
template<typename T>
double vec_ave(T &in){
    double sum=0;
    for(int i=0;i<in.size();i++) sum += in[i];
    return sum/in.size();
}
template<typename T>
double vec_error(T &in){
    double in_ave = vec_ave(in),sum=0;
    int x = (in.size()*(in.size()-1));
    for(int i=0;i<in.size();i++){
        sum += pow(in[i]-in_ave,2);
    }
    return sqrt(sum/x);
}
int main(){
    int n,k,a,b,a_max=-1;
    vector<int> list={};
    set<int> B;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a_max<a){
            list={i+1};
            a_max = a;
        }
        else if(a_max==a){
            list.push_back(i+1);
        }
    }
    for(int i=0;i<k;i++){
        cin >> b;
        B.insert(b);
    }
    bool f=false;
    for(int x : list){
        if(B.count(x)){
            f=true;
            break;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

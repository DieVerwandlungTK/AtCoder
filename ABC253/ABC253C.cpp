#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
const int int_max = 2147483647;
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
    int q,n,x,c;
    cin >> q;
    multiset<int> s;
    for(int i=0;i<q;i++){
        cin >> n;
        if(n==1){
            cin >> x;
            s.insert(x);
        }
        else if(n==2){
            cin >> x >> c;
            auto itr = s.find(x);
            while(c>0&&itr!=s.end()){
                s.erase(itr);
                itr = s.find(x);
                c--;
            }
        }
        else cout << *rbegin(s)-*begin(s) << endl;
    }
}

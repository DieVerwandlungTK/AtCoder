#include <bits/stdc++.h>
using namespace std;
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
int gcd(int x,int y){
    if(x<y) swap(x,y);
    int r = x % y;
    while(r!=0){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}
int func(int x){
    int ret=1;
    for(int i=2;i<=x;i++){
        ret *= i;
    }
    return ret;
}
int main(){
    string s[10];
    for(int i=0;i<10;i++) cin >> s[i];
    int i_min=int_max,i_max=-1,j_min=int_max,j_max=-1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(s[i][j]=='#'){
                i_min = min(i,i_min);
                i_max = max(i,i_max);
                j_min = min(j,j_min);
                j_max = max(j,j_max);
            }
        }
    }
    cout << i_min+1 << ' ' << i_max+1 << endl << j_min+1 << ' ' << j_max+1 << endl;
}
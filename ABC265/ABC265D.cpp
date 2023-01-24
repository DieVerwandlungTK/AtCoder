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
int bin_search(ll *array, int begin, int end, ll value){
    int l = begin, r = end;
    int i = l+(r-l)/2;
    if(value<array[l]-(begin==0 ? 0:array[begin-1])||value>array[r]-(begin==0 ? 0:array[begin-1])) return -1;
    else if(value==array[l]-(begin==0 ? 0:array[begin-1])) return l;
    else if(value==array[r]-(begin==0 ? 0:array[begin-1])) return r;
    else{
        if(value==array[i]-(begin==0 ? 0:array[begin-1])) return i;
        else if(value>array[i]-(begin==0 ? 0:array[begin-1])) return bin_search(array,i+1,r,value);
        else return bin_search(array,l,i-1,value);
    }
}
int main(){
    int n;
    ll p,q,r;
    cin >> n >> p >> q >> r;
    ll a[n],s[n];
    cin >> a[0];
    s[0] = a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    bool f = false;
    int x,y,z,w;
    for(x=0;x<n-2;x++){
        y = bin_search(s,x,n-3,p)+1;
        if(y==0) continue;
        z = bin_search(s,y,n-2,q)+1;
        if(z==0) continue;
        w = bin_search(s,z,n-1,r)+1;
        if(w==0) continue;
        f = true;
        //printf("%d,%d,%d,%d\n",x,y,z,w);
        break;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

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

bool is_inside(int*a,int *b,int *c,int *t){
    int abXat = (b[0]-a[0])*(t[1]-a[1]) - (b[1]-a[1])*(t[0]-a[0]);
    int bcXbt = (c[0]-b[0])*(t[1]-b[1]) - (c[1]-b[1])*(t[0]-b[0]);
    int caXct = (a[0]-c[0])*(t[1]-c[1]) - (a[1]-c[1])*(t[0]-c[0]);
    if((abXat>0 && bcXbt>0 && caXct>0) ||(abXat<0 && bcXbt<0 && caXct<0)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a[2],b[2],c[2],d[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1]>> d[0] >> d[1];
    if(!is_inside(a,b,c,d)&&!is_inside(b,c,d,a)&&!is_inside(c,d,a,b)&&!is_inside(d,a,b,c)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

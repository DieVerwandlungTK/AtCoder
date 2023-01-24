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
int main(){
    int n;
    cin >> n;
    string mat[n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> mat[i][j];
    ull sum_max = 0;
    ull sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=-1;k<2;k++){
                for(int l=-1;l<2;l++){
                    if(k==0 && l==0) continue;
                    sum = 0;
                    for(int m=0;m<n;m++){
                        sum += ctoi(mat[(i+m*k+n)%n][(j+m*l+n)%n]) * pow(10,n-m-1);
                    }
                    sum_max = max(sum_max,sum);
                }
            }
        }
    }
    cout << sum_max << endl;
}
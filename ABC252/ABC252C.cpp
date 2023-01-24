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
int main(){
    int n,c,c_max=0,out=int_max;
    ull in;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<10;i++){
        c_max = 0;
        for(int j=0;j<10;j++){
            c=0;
            for(int k=0;k<n;k++){
                if(i==ctoi(s[k][j])){
                    c++;
                }
            }
            c_max=max(c_max,(c-1)*10+j);
        }
        out=min(out,c_max);
    }
    cout << out << endl;
}

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
    string s;
    cin >> s;
    bool f = false;

    bool OR[7];
    if(s[6]=='1') OR[0]=1;
    else OR[0]=0;
    if(s[3]=='1') OR[1]=1;
    else OR[1]=0;
    if(s[7]=='1'||s[1]=='1') OR[2]=1;
    else OR[2]=0;
    if(s[4]=='1'||s[0]=='1') OR[3]=1;
    else OR[3]=0;
    if(s[8]=='1'||s[2]=='1') OR[4]=1;
    else OR[4]=0;
    if(s[5]=='1') OR[5]=1;
    else OR[5]=0;
    if(s[9]=='1') OR[6]=1;
    else OR[6]=0;

    if(s[0]=='0'){
        for(int i=1;i<6;i++){
            if(OR[i]) continue;
            bool lf=0,rf=0;
            for(int j=0;j<i;j++){
                if(OR[j]){
                    lf=1;
                    break;
                }
            }
            for(int j=i+1;j<7;j++){
                if(OR[j]){
                    rf=1;
                    break;
                }
            }
            if(lf&&rf){
                f = true;
                break;
            }
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

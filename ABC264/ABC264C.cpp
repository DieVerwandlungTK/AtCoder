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
    int h1,w1,in;
    cin >> h1 >> w1;
    vii a(h1,vector<int>(w1));
    for(int i=0;i<h1;i++){
        for(int j=0;j<w1;j++){
            cin >> in;
            a[i][j] = in;
        }
    }
    int h2,w2;
    cin >> h2 >> w2;
    vii b(h2,vector<int>(w2));
    for(int i=0;i<h2;i++){
        for(int j=0;j<w2;j++){
            cin >> in;
            b[i][j] = in;
        }
    }
    bool f;
    for(int i=1;i<(1<<h1);i++){
        bitset<10> bin_i = i;
        if(bin_i.count()!=h1-h2) continue;
        for(int j=1;j<(1<<w1);j++){
            bitset<10> bin_j = j;
            if(bin_j.count()!=w1-w2) continue;
            //cout << bin_i << endl << bin_j << endl << endl;
            vi hvec,wvec;
            for(int k=0;k<h1;k++) if(!bin_i.test(k)) hvec.push_back(k);
            for(int k=0;k<w1;k++) if(!bin_j.test(k)) wvec.push_back(k);
            f = true;
            for(int k=0;k<h2;k++){
                for(int l=0;l<w2;l++){
                    if(a[hvec[k]][wvec[l]]!=b[k][l]){
                        f = false;
                        break;
                    }
                }
                if(!f) break;
            }
            if(f) break;
        }
        if(f) break;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

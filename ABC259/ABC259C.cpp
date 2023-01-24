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
vector<pair<char,int>> f(string s){
    vector<pair<char,int>> r;
    pair<char,int> p;
    p.first = s[0];
    p.second = 1;
    r.push_back(p);
    for(int i=1;i<s.size();i++){
        if(s[i]==r.back().first) r.back().second++;
        else{
            p.first = s[i];
            p.second = 1;
            r.push_back(p);
        }
    }
    return r;
}
int main(){
    string s,t;
    cin >> s >> t;
    int c;
    if(s.size()>t.size()) cout << "No" << endl;
    else if(s.size()==t.size()&&s==t) cout << "Yes" << endl;
    else if(s.size()==t.size()&&s!=t) cout << "No" << endl;
    else{
        vector<pair<char,int>> ls,lt;
        ls = f(s);
        lt = f(t);
        if(ls.size()!=lt.size()) cout << "No" << endl;
        else{
            bool f = true;
            for(int i=0;i<ls.size();i++){
                if(ls[i].first==lt[i].first&&ls[i].second==lt[i].second) continue;
                else if(ls[i].first==lt[i].first&&ls[i].second<=lt[i].second&&ls[i].second>1) continue;
                else{
                    f = false;
                    break;
                }
            }
            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

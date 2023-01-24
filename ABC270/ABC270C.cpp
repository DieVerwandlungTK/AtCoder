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
int x,y;
bool dfs(vector<bool> &s, vector<int> &p, vector<vector<int>> &g, int e){
    if(s[e]) return false;
    else s[e] = true;
    if(e==y){
    p.push_back(e);
        return true;
    }
    else if(g[e].size()==0) return false;
    else{
        for(int x:g[e]){
            if(dfs(s,p,g,x)){
                p.push_back(e);
                return true;
                break;
            }
        }
        return false;
    }
}
int main(){
    int n,u,v;
    cin >> n >> x >> y;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> path;
    vector<bool> se(n+1,false);
    dfs(se,path,g,x);
    int s = path.size()-1;
    cout << path[s];
    for(int i=s-1;i>-1;i--){
        cout << ' ' << path[i];
    } 
    cout << endl;
}

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
bool edge(vector<vector<int>> &list, int i, int j){
    if(pow(list[i][0]-list[j][0],2)+pow(list[i][1]-list[j][1],2)<=pow(list[i][2]+list[j][2],2)) return true;
    else return false;
}
int main(){
    int n,sx,sy,tx,ty;
    cin >> n >> sx >> sy >> tx >> ty;
    vector<vector<int>> circle_list(n,vector<int>(3));
    vector<vector<int>> graph(n);
    set<int> searched;
    vector<int> s_list,t_list;
    for(int i=0;i<n;i++){
        cin >> circle_list[i][0] >> circle_list[i][1] >> circle_list[i][2];
        if(pow(circle_list[i][0]-sx,2)+pow(circle_list[i][1]-sy,2)==circle_list[i][2]) s_list.push_back(i);
        if(pow(circle_list[i][0]-tx,2)+pow(circle_list[i][1]-ty,2)==circle_list[i][2]) t_list.push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(edge(circle_list,i,j)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}
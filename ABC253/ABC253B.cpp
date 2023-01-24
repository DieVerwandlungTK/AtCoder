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
    int h,w;
    cin >> h >> w;
    string table[h];
    vi comemory(2);
    vii memory;
    for(int i=0;i<h;i++){
        cin >> table[i];
        for(int j=0;j<w;j++){
            if(table[i][j]=='o'){
                comemory[0]=i;
                comemory[1]=j;
                memory.push_back(comemory);
            }
        }
    }
    cout << abs(memory[0][0]-memory[1][0])+abs(memory[0][1]-memory[1][1]) << endl;
}

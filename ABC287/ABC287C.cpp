#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
const int int_max = 2147483647;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int ctoi(char c)
{
    return c - '0';
}
bool prime(ull x)
{
    bool f = true;
    ull x_root = sqrt(x);
    for (int i = 2; i <= x_root; i++)
    {
        if (x % i == 0)
        {
            f = false;
            break;
        }
    }
    return f;
}
template <typename T>
double vec_ave(T &in)
{
    double sum = 0;
    for (int i = 0; i < in.size(); i++)
        sum += in[i];
    return sum / in.size();
}
template <typename T>
double vec_error(T &in)
{
    double in_ave = vec_ave(in), sum = 0;
    int x = (in.size() * (in.size() - 1));
    for (int i = 0; i < in.size(); i++)
    {
        sum += pow(in[i] - in_ave, 2);
    }
    return sqrt(sum / x);
}
int gcd(int x, int y)
{
    if (x < y)
        swap(x, y);
    int r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}
int func(int x)
{
    int ret = 1;
    for (int i = 2; i <= x; i++)
    {
        ret *= i;
    }
    return ret;
}
int main(){
    int n, m, v, u, c_1=0, c_2=0, c_others=0;
    cin >> n >> m;

    vector<int> deg(n, 0);
    UnionFind uf(n);
    for(int i=0;i<m;i++){
        cin >> v >> u;
        if(uf.same(v-1, u-1)){
            n=0;
            c_others=1;
            break;
        }
        else{
            uf.unite(v-1, u-1);
        }
        deg[v-1]++;
        deg[u-1]++;
    }
    for(int i=0;i<n;i++){
        if(deg[i]==1){
            c_1++;
            if(c_1>2) break;
        }
        else if(deg[i]==2) c_2++;
        else{
            c_others++;
            break;
        }
    }

    if(c_1==2&&c_2==n-2&&c_others==0) cout << "Yes" << endl;
    else cout << "No" << endl;

}

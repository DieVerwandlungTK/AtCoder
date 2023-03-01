#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
const int int_max = 2147483647;
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

bool recur(int idx, int *a, int *b, int x, int n){
    if(idx==n-1){
        return x%a[idx]==0 && x/a[idx]<=b[idx];
    }
    else{
        if(x%a[idx]==0 && x/a[idx]<=b[idx]) return true;
        for(int i=0;i<=b[idx];i++){
            if(x<i*a[idx]) return false;
            if(recur(idx+1, a, b, x-i*a[idx], n)) return true;
            else{
                continue;
            }
        }
        return false;
    }
}
int main(){
    int n, x;
    cin >> n >> x;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    if(recur(0, a, b, x, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

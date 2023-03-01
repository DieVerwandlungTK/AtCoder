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

bool tmp_func(string s){
    int size = s.size();
    int l = 0, r = 0, u = 0, d = 0;
    for(int i=0;i<size;i++){
        if(s[i]=='L') l++;
        else if(s[i]=='R') r++;
        else if(s[i]=='U') u++;
        else d++;
        if((l==r)&&(u==d)) return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l[n], r[n], u[n], d[n];
    l[0] = 0;
    r[0] = 0;
    u[0] = 0;
    d[0] = 0;
    for(int i=1;i<n+1;i++){
        l[i] = l[i-1] + ((s[i-1]=='L')?1:0);
        r[i] = r[i-1] + ((s[i-1]=='R')?1:0);
        u[i] = u[i-1] + ((s[i-1]=='U')?1:0);
        d[i] = d[i-1] + ((s[i-1]=='D')?1:0);
    }
    bool f = false;
    for(int i=0;i<n-1;i++){
        for(int j=1;i+j<n-1;j++){
            if(((l[i+j]-l[i])==(r[i+j]-r[i]))&&((u[i+j]-u[i])==(d[i+j]-d[i]))){
                f = true;
                break;
            }
        }
        if(f) break;
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

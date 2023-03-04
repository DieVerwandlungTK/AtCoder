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

    pii pos = {0, 0};
    set<pii> visited;
    visited.insert(pos);

    for(int i=0;i<n;i++){
        if(s[i]=='L') pos.first--;
        else if(s[i]=='R') pos.first++;
        else if(s[i]=='U') pos.second++;
        else pos.second--;
        if(visited.count(pos)){
            cout << "Yes" << endl;
            return 0;
        }
        else visited.insert(pos);
    }

    cout << "No" << endl;
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pb push_back

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

template <typename T>
void print(const T& value) {cout << value <<"\n";}


void solve() {
    return;
}

int main() {
    solve();
    return 0;
}
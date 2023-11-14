#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define umap unordered_map
#define uset unordered_set

#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair

const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

class Matrix {
public:
    ll a, b, c, d;
    Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
};

Matrix multiply(const Matrix &m1, const Matrix &m2) {
    ll new_a = (m1.a * m2.a + m1.b * m2.c) % MOD;
    ll new_b = (m1.a * m2.b + m1.b * m2.d) % MOD;
    ll new_c = (m1.c * m2.a + m1.d * m2.c) % MOD;
    ll new_d = (m1.c * m2.b + m1.d * m2.d) % MOD;
    return Matrix(new_a, new_b, new_c, new_d);
}

Matrix power(Matrix base, ll exp) {
    if (exp == 1) {
        return base;
    }
    if (exp % 2 == 0) {
        Matrix half_power = power(base, exp / 2);
        return multiply(half_power, half_power);
    } else {
        return multiply(base, power(base, exp - 1));
    }
}

ll fibonacci(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    Matrix base(1, 1, 1, 0);
    Matrix result = power(base, n - 1);
    return result.a;
}

void solve() {
    ll n;
    cin >> n;

    ll result = fibonacci(n) % MOD;
    cout << result << '\n';
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}

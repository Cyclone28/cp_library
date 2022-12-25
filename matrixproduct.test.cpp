#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T>
using pq = priority_queue<T, vector<T>>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1000000007;
const ll MODD = 998244353;

#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = (ll)(n); i >= (ll)(0); i--)
#define rrep2(i, n) for (ll i = (ll)(n); i >= (ll)(0); i--)
#define rrep3(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define rrep4(i, a, b, c) for (ll i = (ll)(a); i >= (ll)(b); i -= (ll)(c))
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define elif else if
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define stoi stoll

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

const ll dx[4] = {0, 0, 1, -1};
const ll dy[4] = {1, -1, 0, 0};

// #include<atcoder/all>
// using namespace atcoder;

template <class T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B, T mod)
{
        vector<vector<T>> ret(A.size(), vector<T>(B[0].size()));
        rep(i, A.size()) rep(k, B.size()) rep(j, B[0].size())
        {
                (ret[i][j] += A[i][k] * B[k][j]) %= mod;
        }
        return ret;
}

template <class T>
vector<vector<T>> pow(vector<vector<T>> A, T n, T mod)
{
        vector<vector<T>> ret(A.size(), vector<T>(A[0].size()));
        rep(A.size()) ret[i][i] = 1;
        while (n > 0)
        {
                if (n & 1)
                        ret = mul(ret, A, mod);
                A = mul(A, A, mod);
                n >>= 1;
        }
        return ret;
}

int main()
{
        ll N, M, K;
        cin >> N >> M >> K;
        vector<vector<ll>> A(N, vector<ll>(M));
        vector<vector<ll>> B(M, vector<ll>(K));
        for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                        cin >> A[i][j];
        for (int i = 0; i < M; ++i)
                for (int j = 0; j < K; ++j)
                        cin >> B[i][j];
        vector<vector<ll>> C = mul(A, B, 998244353LL);
        for (int i = 0; i < N; ++i)
        {
                for (int j = 0; j < K; ++j)
                        cout << C[i][j] << " ";
                cout << endl;
        }
        return 0;
}
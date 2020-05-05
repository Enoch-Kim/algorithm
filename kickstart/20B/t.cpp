#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i <= _##i; i++)
#define repr(i, s, e) for (int i = (s), _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
#define ARR(...) vector<int>({__VA_ARGS__})
#define ARS(...) vector<string>({__VA_ARGS__})
 
 
using namespace std;
using namespace rel_ops;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//typedef complex<double> base;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> &pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    for (auto p : v) os << p << ",";
    os << "]";
    return os;
}
 
template<typename... T>
ostream &operator<<(ostream &os, const set<T...> &v) {
    os << "{";
    for (auto p : v) os << p << ",";
    os << "}";
    return os;
}
 
template<typename... T>
ostream &operator<<(ostream &os, const multiset<T...> &v) {
    os << "{";
    for (auto p : v) os << p << ",";
    os << "}";
    return os;
}
 
template<typename... T>
ostream &operator<<(ostream &os, const map<T...> &v) {
    os << "{";
    for (auto p : v) os << p << ",";
    os << "}";
    return os;
}
 
template<typename T>
struct cector : public vector<T> {
    using vector<T>::size;
    using vector<T>::vector;
 
    T &operator[] (int idx) {
        if (0 <= idx and idx < size()) return vector<T>::operator[](idx);
        idx = idx % (int)size();
        if (idx < 0) idx += size();
 
        return vector<T>::operator[](idx);
    }
};

#ifdef __INTERACTIVE

#define debug(...) cerr << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cerr << *sdbg++;
    cerr << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}

#else
#ifndef __SOULTCH
#define debug(...) 0
#define endl '\n'
 
auto ____x = []{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
 
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
#endif
 
template<typename T> void get_max(T &a, const T &b) { a = max(a, b); }
template<typename T> void get_min(T &a, const T &b) { a = min(a, b); }
 
 
int invGeneral(int a, int b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    int x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}
 
template<int MOD>
struct modular {
    int val; 
    explicit operator int() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
   
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }
 
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
 
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val, MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    // warning :: ^ operator may has low priority in operators
 
    modular& operator^=(const ll m) { *this = pow(*this, m); return *this;}
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    friend modular operator/(modular a, const modular& b) { return a /= b; }
    friend modular operator^(modular a, const ll b) {return a ^= b;}
};
 
template<int M>
ostream& operator<<(ostream& os, const modular<M> &mod) {
    return os << mod.val;
}
 
////////////////////////////////////////////////////////////////////////////////

long double calc_sum(int n, int t) {
	if (t < 0 or t > n) return 0;
	bool f = (t > n-t);
	if (f) t = n-t-1;

	debug(f, n, t);

	long double ret = 1;
	long double sum = 1;
	int rem = n;
	repp(i, 1, t) {
		ret *= (n+1-i);
		ret /= i;

		sum += ret;
		while(sum > 1 and rem > 0) {
			rem--;
			sum /= 2;
			ret /= 2;
		}
	}

	while(rem--) {
		sum /= 2;
	}

	if (f) return 1-sum;
	else return sum;
}

void solve() {
	int W, H, L, U, R, D; cin >> W >> H >> L >> U >> R >> D;

	long double r1 = calc_sum(L+D-2, L-2), r2 = calc_sum(R+U-2, U-2);



	if (D == H) r1 = 0;
	if (R == W) r2 = 0;

	debug(r1, r2);

	cout << r1+r2 << endl;
}

int main(void) {
	int T; cin >> T;
	cout << fixed << setprecision(15);
	repp(i, 1, T) {
		cout << "Case #" << i << ": ";
		solve();
	}	
}
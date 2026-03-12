#include <bits/stdc++.h>
using namespace std;

// ================= Fast IO =================
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// ================= Debug Template =================
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(double x) { cerr << x; }

template <class T>
void _print(vector<T> v){
    cerr << "[ ";
    for(auto i : v){
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(pair<T,V> p){
    cerr << "{";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << "}";
}

// ================= Solve Function =================
void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    debug(n);
    debug(a);

    // example logic
    sort(a.begin(), a.end());

    for(int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

// ================= Main =================
int main() {

    fastio;

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

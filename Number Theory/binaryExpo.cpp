
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const long long mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m){
    if(b == 0){
        return 1;
    }

    long long ans = binpow(a, b/2, m);
    ans = (ans * ans) % m;

    if(b & 1){
        ans = (ans * a) % m;
    }

    return ans;
}

long long binpowItr(long long a, long long b, long long m){
    long long ans = 1;

    while(b > 0){
        if(b & 1){
            ans = (ans * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }

    return ans;
}

long long binarymul(long long a, long long b, long long m){
    long long ans = 0;
    a %= m;

    while(b > 0){
        if(b & 1){
            ans = (ans + a) % m;
        }

        a = (a + a) % m;
        b >>= 1;
    }

    return ans;
}

long long binpowItr2(long long a, long long b, long long m){ // more optimized 
    long long ans = 1;
    a %= m;

    while(b > 0){
        if(b & 1){
            ans = binarymul(ans, a, m);
        }

        a = binarymul(a, a, m);
        b >>= 1;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << binpow(a, b, mod) << endl;
    cout << binpowItr(a, b, mod) << endl;
    cout << binarymul(a, b, mod) << endl;
    cout << binpowItr2(a, b, mod) << endl;

    return 0;
}

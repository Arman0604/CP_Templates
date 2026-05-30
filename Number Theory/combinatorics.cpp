int m = 1e9 + 7;

long long factorial(int n){
  if(n == 0){
    return 1;
  }
  if(n == 1){
    return 1;
  }
  return ((n%m)*1LL*(factorial(n-1)%m))%m;
}

int binpow(int a, int b, int m){
    if(b == 0){
        return 1;
    }
    long ans = binpow(a, b/2, m);
    if(b&1){
        return (a*(ans*ans)%m)%m;
    }
    else{
        return (ans*ans)%m;
    }
}

int binpowItr(int a, int b, int m){ //preferable
    if(b == 0){
        return 1;
    }
    int ans = 1;
    while(b > 0){
      if(b&1){
        ans = (ans*a*1LL)%m;
      }
      a = (a*a*1LL)%m;
      b >>= 1;
    }
    return ans;
}

long binarymul(long a, long b, int m){
    long ans = 0;
    while(b > 0){
      if(b&1){
       ans = (ans + a)%m;
      }
      a = (a + a)%m;
      b >>= 1;
    }
    return ans; 
}

long long binpowItr2(long a, long b, int m){ //more optimized
    long long ans = 1;
    while(b > 0){
      if(b&1){
        ans = binarymul(ans, a, m);
      }
      a = binarymul(a, a, m);
      long double  a = 5;
      b >>= 1;
    }
    return ans;
}

long inver(long a, long k){ // k = m-2
    return binpowItr2(a, k, m);
}

long npr(long n, long r, vector<long>& fact, vector<long>& ifact){
  return binarymul(fact[n], ifact[n-r], m);
}

long ncr(long n, long r, vector<long>& fact, vector<long>& ifact){
  return binarymul(fact[n], binarymul(ifact[r], ifact[n-r], m), m);
}

int main(){
    int n = 2000000;
    vector<long> fact(n+1);
    vector<long> ifact(n+1);
    fact[0] = 1;
    for(int i=1; i<=n; i++){
      fact[i] = binarymul(fact[i-1], i, m);
    }
    ifact[n] = inver(fact[n], m-2); 
    for(int i=n-1; i>=0; i--){
      ifact[i] = binarymul(ifact[i+1], i+1, m);
    }
    long long ans = ncr(10000, 345, fact, ifact);
    cout<<ans<<endl;
    return 0;
}

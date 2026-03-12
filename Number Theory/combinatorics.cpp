int m = 1e9 + 7;

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

// calculating npr
long npr(long n, long r, vector<long> fact, vector<long> ifact){
  return binarymul(fact[n], ifact[n-r], m);
}

// calculating ncr
long ncr(long n, long r, vector<long> fact, vector<long> ifact){
  return binarymul(fact[n], binarymul(ifact[r], ifact[n-r], m), m);
}

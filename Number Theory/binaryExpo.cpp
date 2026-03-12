int m = 1e9 + 7;

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

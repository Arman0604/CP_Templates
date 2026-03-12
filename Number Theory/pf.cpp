void hpf(int n){
   vector<int> hp(n, 0);
   vector<bool> prime(n, true);
   for(int i=2; i<n; i++){
     if(prime[i] == true){
      hp[i] = i;
      for(int j=2*i; j<=n; j+=i){
       prime[j] = false;
       hp[j] = i;
      }
     }
   }
   int k = 5; //no. of which we want to find pfs (here 5)
   vector<int> pfs;
   while(k > 1){
     int pf = hp[k]; // can use lp also here
     while(k%pf == 0){
        k = k/pf;
        pfs.push_back(pf);
     }
   }
   //we can use map to store prime factors and its freq
}

void divisors(int n){ // count and sum of divisors
  int count = 0;
  int sum = 0;
  for(int i=1; i<=sqrt(n); i++){
    if(n%i == 0){
      count++;
      sum += i;
      if((n/i) != i){
        sum += (n/i);
        count++;
      }
    }
  }
}

void pf(int n){ // find prime factors
  int count = 0;
  int sum = 0;
  vector<int> v;
  for(int i=2; i<=sqrt(n); i++){
    if(n%i == 0){
      while(n%i == 0){
        v.push_back(i);
        n /= i;
      }
    }
  }
  if(n > 1){
    v.push_back(n);
  }
}

void lpf(int n){
  vector<int> lp(n, 0);
  vector<bool> prime(n, true);
  for(int i=2; i<n; i++){
    if(prime[i] == true){
      lp[i] = i;
      for(int j=2*i; j<=n; j+=i){
        if(lp[j] == 0){
          lp[j] = i;
        }
        prime[j] = false;
      }
    }
  }
}

// finding prime numbers between 1 to n
void sievealgo(int n){
  vector<bool> prime(n, 1);
  prime[0] = 0; 
  prime[1] = 0;
  for(int i=2; i<=n; i++){ 
    if(prime[i] == 1){
      for(int j=2*i; j<=n; j+=i){
        prime[j] = 0;
      }
    }
  }
  for(int i=0; i<n; i++){
    if(prime[i+1] == 1){
      cout<<i+1<<" ";
    }
  }
  cout<<endl;
}

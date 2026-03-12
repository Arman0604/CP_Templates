#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i){
    return ((1<<i)&n);
}

int setBit(int n, int i){
    return ((1<<i)|1);
}

int clearBit(int n, int i){
    return (~(1<<i)&n);
}

int toggleBit(int n, int i){
    return ((1<<i)^n);
}

int countSetBits(int n){ 
    int count = 0;
    while(n != 0){
        n = (n&(n-1));
        count++;
    } // __builtin_popcount(n); (for inbuilt)
} 

int main(){
    int n = 5;
    int i = 1;
    int ithbit = getBit(n, i);
    cout<<ithbit<<endl;
}

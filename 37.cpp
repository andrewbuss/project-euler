#include <stdio.h>
#include <stack>
#include <math.h>
#define MAXPRIMES 1000000

int main(){
  int t = 0;
  int n = 0;
  bool primes[MAXPRIMES];
  primes[0]=false;
  primes[1]=false;
  primes[2]=true;
  for(int i=3;i<MAXPRIMES; i++) primes[i]=true;
  for(int i=2;i<1000; i++){
    if(!primes[i]) continue;
    for(int j=i+i; j<MAXPRIMES; j+=i) primes[j]=false;
  }
  for(int i=11; i<MAXPRIMES; i+=2){
    if(!primes[i]) continue;
    int j=i;
    while(j>0){
      j/=10;
      if(!primes[j]) break;
    }
    if(j!=0) continue;
    printf("%7i is truncatable\n",i);
    j=i;
    std::stack<int> digits;
    while(j>0){
      digits.push(j%10);
      j/=10;
    }
    j=i;
    while(j>0){
      j-=digits.top()*pow(10,digits.size()-1);
      digits.pop();
      if(!primes[j]) break;
      printf("   %7i is prime\n",j);
    }
    if(j!=0) continue;
    printf("   %7i is completely truncatable\n",i);
    t+=i;
    n++;
  }
  printf("Total reverse truncatable primes found: %i\n", n);
  printf("Total of reverse truncatable primes: %i\n", t);
  return 0;
}
    
    

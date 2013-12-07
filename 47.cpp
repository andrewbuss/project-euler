#include <stdio.h>
#include <bitset>
#define MAXPRIMES 10000000

int main(){
  printf("Initializing primes table: ");
  std::bitset<MAXPRIMES> primes;
  primes.reset();
  primes.flip();
  primes[0]=0;
  primes[1]=0;
  primes[2]=1;
  printf("Done\n");
  for(int i=2;i<3200; i++){
    if(!primes[i]) continue;
    for(int j=i+i; j<MAXPRIMES; j+=i) primes[j]=0;
  }
  printf("Computed primes up to %i\n", MAXPRIMES);
  int i=3;
  int start = 0;
  while(true){
    //printf("Testing I %i\n",i);
    int j=i;
    std::bitset<1000000> factors;
    factors[i]=1;
    int k=2;
    while(!primes[j]){
      if(j%k){
	k++;
	while(!primes[k] && k<j+2) k++;
	//printf("New K: %i\n",k);
	if(k>j) break;
	continue;
      }
      j/=k;
      factors[k]=1;
      //printf("New J: %i\n",j);
    }      
    //printf("| %6i:%1i",i,factors.count());
    if(factors.count()==4 && !start) start = i;
    else if(factors.count()!=4) start = 0;
    else if(i-start==3) break;
    i++;
  }
  printf("%i\n",i);
  return 0;
}

#include <stdio.h>
#include <bitset>
#define MAXPRIMES 10000000

int main(){
  printf("Initializing primes table: ");
  std::bitset<MAXPRIMES> primes;
  primes.flip();
  primes[0]=0;
  primes[1]=0;
  primes[2]=1;
  printf("Done\n");
  for(int i=2;i<3200; i++){
    if(!primes[i]) continue;
    printf("%5i\n",i);
    for(int j=i; j<MAXPRIMES; j+=i) primes[j]=0;
  }
  printf("Computed primes up to %i\n", MAXPRIMES);
  for(int a=9; a>0; a--){
    printf("%i\n",a);
  for(int b=9; b>0; b--){
    if(b==a) continue;
    //    printf(" %i\n",b);
  for(int c=9; c>0; c--){
    if(c==a || c==b) continue;
    //    printf("  %i\n",c);
  for(int d=9; d>0; d--){
    if(d==a || d==b || d==c) continue;
    //    printf("   %i\n",d);
  for(int e=9; e>0; e--){
    if(e==a || e==b || e==c || e==d) continue;
    //    printf("    %i\n",e);
  for(int f=9; f>0; f--){
    if(f==a || f==b || f==c || f==d || f==e) continue;
    //    printf("     %i\n",f);
  for(int g=9; g>0; g--){
    if(g==a || g==b || g==c || g==d || g==e || g==f) continue;
    //    printf("      %i\n",g);
    if(primes[g+f*10+e*100+d*1000+c*10000+b*100000+a*1000000]){
      if(a+b+c+d+e+f+g != 28) continue;
      printf("Found: %i\n",g+f*10+e*100+d*1000+c*10000+b*100000+a*1000000);
      return 0;
    }
  }}}}}}}
}

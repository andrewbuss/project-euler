#include <stdio.h>
#define TRI(n) (n*(n+1))/2
#define PEN(n) (n*(3*n-1))/2
#define HEX(n) n*(2*n-1)

int main(){
  long lpn = 0;
  long lhn = 1;
  long long lp = 0;
  long long lh = 1;
  while(lhn<100000000){
    if(lp<lh){
      lpn++;
      lp=PEN(lpn);
      continue;
    }
    if(lh<lp){
      lhn++;
      lh=HEX(lhn);
      continue;
    }
    printf("Found: %10i\n",lh);
    lhn++;
    lh=HEX(lhn);
  }
  return 0;
}

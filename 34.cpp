#include <stdio.h>

int factorial(int n){
  int p = 1;
  while(n>1){
    p*=n;
    n-=1;
  }
  return p;
}

int main(){
  int t=0;
  for(int i=10;i<9999999;i++){
    int s=0;
    int j=i;
    while(j>0){
      s+=factorial(j%10);
      j/=10;
    }
    if(s==i){
      printf("%5i: %10i\n",i,s);
      t+=s;
    }
  }
  printf("Sum: %10i\n",t);
  return 0;
}

#include <stdio.h>

int main(){
  int s=0;
  for(int i=2; i<1000000; i++){
    int j=i;
    int t=0;
    while(j>0){
      int k=j%10;
      j/=10;
      t+=(k*k*k*k*k);
    }
    if(t==i){
      printf("%5i: %10i\n",i,t);
      s+=t;    
    }
  }
  printf("Sum: %10i\n",s);
  return 0;
}

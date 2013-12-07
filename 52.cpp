#include <stdio.h>

bool samedigits(int a, int b){
  int ad[10];
  int bd[10];
  for(int i=0; i<10; i++){
    ad[i] = 0;
    bd[i] = 0;
  }
  while(a>0){
    ad[a%10]++;
    a/=10;
  }
  while(b>0){
    bd[b%10]++;
    b/=10;
  }
  for(int i=0; i<10; i++){
    if(bd[i]!=ad[i]) return false;
  }
  return true;
}
int main(){
  int x=10;
  while(true){
    printf("X: %7i | ",x);
    int i=2;
    for(; i<7; i++){
      if(samedigits(x,i*x)) printf("%iX: Yes ",i);
      else{
	printf("%iX: No\n",i);
	break;
      }
    }
    if(i==7) break;
    x++;
  }
  return 0;
}

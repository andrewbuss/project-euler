#include<stdio.h>

unsigned char d(long long k){
  unsigned char s = 0;
  while(k>0){
    s+=k%10;
    k-=k%10;
    k/=10;
  }
  return s;
}

long long a[1000000];
long long* ap = &a[0];

int main(){
  for(int i=0; i<10000000; i++){
    if(d(i)==23){
      *ap = i;
      printf("%5i\n", i);
      ap++;
    }
  }
  return 0;
}
  

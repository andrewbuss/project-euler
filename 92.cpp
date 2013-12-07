#include<stdio.h>
#define NCACHE 1000000

int squaredsum(int n){
  int s = 0;
  while(n>0){
    s+=((n%10)*(n%10));
    n/=10;
  }
  return s;
}

unsigned char m[NCACHE];

int main(){
  for(int i=0; i<NCACHE; i++) m[i]=0;
  int s=0;
  for(int i=2; i<10000000; i++){
    int n=i;
    while(n != 1 && n!= 89){
      if(n<NCACHE && m[n]){
	n = m[n];
	break;
      }
      n = squaredsum(n);
    }
    if(n==89) s++;
    if(i<NCACHE) m[i]=n;
  }
  printf("Total ending in 89: %5i\n",s);
  return 0;
}

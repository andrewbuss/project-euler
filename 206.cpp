#include <stdio.h>

int main(){
  for(long long i = 100000003-6; i<140000000;){
    if(i%10==3) i+=4;
    else i+=6;
    long long is = i*i;
    if((is-(is%100))%1000 != 800) continue;
    if((is-(is%10000))%100000 != 70000) continue;
    if((is-(is%1000000))%10000000 != 6000000) continue;
    if((is-(is%100000000))%1000000000 != 500000000) continue;
    if((is-(is%10000000000))%100000000000 != 40000000000) continue;
    if((is-(is%1000000000000))%10000000000000 != 3000000000000) continue;
    printf("%i\n",i);
    if((is-(is%100000000000000))%1000000000000000 != 200000000000000) continue;
  }
  return 0;
}

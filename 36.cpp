#include <stdio.h>

int main(){
  int t = 0;
  for(int i=1; i<1000000; i++){
    unsigned char ften[8];
    unsigned char bten[8];
    unsigned char ftwo[20];
    unsigned char btwo[20];
    for(int j=0;j<8;j++){
      ften[j]=0;
      bten[j]=0;
    }
    for(int j=0;j<20;j++){
      ftwo[j]=0;
      btwo[j]=0;
    }
    int j=i;
    int k=0;
    while(j>0){
      bten[k] = j%10;
      k++;
      j/=10;
    }
    j=i;
    k=k-1;
    while(j>0){
      ften[k] = j%10;
      k--;
      j/=10;
    }
    bool ten=true;
    for(int l=0; l<8; l++){
      //printf("%i %i\n",bten[l],ften[l]);
      if(ften[l]!=bten[l]){
	//printf("%7i is not a palindrome in base 10; going to next number\n",i);
	ten=false;
	break;
      }
    }
    if(!ten) continue;
    //else printf("%7i is a palindrome in base 10; checking base 2\n",i);
    j=i;
    k=0;
    while(j>0){
      btwo[k] = j%2;
      k++;
      j/=2;
    }
    j=i;
    k=k-1;
    while(j>0){
      ftwo[k] = j%2;
      k--;
      j/=2;
    }
    bool two=true;
    for(int l=0; l<20; l++){
      if(ftwo[l]!=btwo[l]){
	//printf("%7i is not a palindrome in base 2; going to next number\n",i);
	two=false;
	break;
      }
    }
    if(!two) continue;
    else printf("%7i is a palindrome in base 2; adding to sum\n",i);
    t+=i;
  }
  printf("Sum: %i\n",t);
  return 0;
}

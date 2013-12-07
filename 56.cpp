#include <stdio.h>
#include <gmp.h>

int main(){
  int max = 0;
  for(int a=1; a<100; a++){
    for(int b=1; b<100; b++){
      mpz_t c;
      mpz_t ma;
      mpz_init(c);
      mpz_init(ma);
      mpz_set_ui(ma, a);
      mpz_pow_ui(c, ma, b);
      char* str = mpz_get_str(NULL, 10, c);
      int ds = 0;
      for(int i=0; str[i]; i++) ds+=str[i]-48;
      if(ds > max){
	printf("%2i^%2i: %i\n",a,b,ds);
	max = ds;
      }
      mpz_clear(c);
      mpz_clear(ma);
    }      
  }
}

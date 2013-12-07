#include <iostream>

int main(){
  int total = 0;
  int currentnumber = 0;
  while(currentnumber <= 1000){
    currentnumber++;
    bool multiple = false;
    if(currentnumber % 3 == 0){
      std::cout << currentnumber << " is a multiple of 3\n";
      multiple = true;
    }
    if(currentnumber % 5 == 0){
      std::cout << currentnumber << " is a multiple of 5\n";
      multiple = true;
    }
    if(multiple){
      std::cout << currentnumber << " is a multiple of 3 or 5, adding to running total\n";
      total += currentnumber;
      std::cout << total << " is the current running total\n";
    }
  }
  return 0;
}
  

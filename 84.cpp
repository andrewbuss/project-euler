#include <stdio.h>
#include <stdlib.h>



int position = 0;
int turns = 0;
int injail = 0;
int ndoubles = 0;
int squares[40];
void cc(){
  int card = rand()%16;
  printf("Card %2i: ",card);
  if(!card){
    position = 0;
    printf("Advance to GO\n");
  }
  else if(card == 1) {
    position = 10;
    printf("Go to Jail\n");
  }
  else printf("Nothing of interest\n");
}

void ch(){
  int card = rand()%16;
  printf("Card %2i: ",card);
  switch(card){
  case 0: 
    position = 0;
    printf("Go to GO\n");
    break;
  case 1:
    position = 10;
    printf("Go to Jail\n");
    jail();
    break;
  case 2:
    position = 11;
    printf("Go to C1\n");
    break;
  case 3:
    position = 24;
    printf("Go to E3\n");
    break;
  case 4:
    position = 39;
    printf("Go to H2\n");
    break;
  case 5:
    position = 5;
    printf("Go to R1\n");
    break;
  case 6: card++;
  case 7:
    printf("Go to next R\n");
    while(!((position+5)%10)) position++;
    break;
  case 8:
    if(position > 12 && position < 28) position = 28;
    else position = 12;
    break;
  case 9:
    position -= 3;
    break;
  default:
    printf("Nothing of interest\n");
  }
}
void jail(){
  turns++;
  int injail = 1;
  while(injail < 4){
    printf("Turn %i in jail\n",injail);
    if(rand()%4==rand()%4){
      printf("Rolled doubles, out of jail now\n");
      turns++;
      squares[10]++;
      break;
    }
    squares[10]++;
    turns++;
    injail++;
  }
  position = 10;
}
int main(){
  srand(123);
  while(turns<1000){
    printf("==============\nTurn %i\nStarting on square %i\n",turns, position);
    int a = rand()%4+1;
    int b = rand()%4+1;
    int roll = a+b;
    bool doubles=false;
    printf("Rolled %i+%i=%i",a,b,roll);
    if(a==b){
      doubles = true;
      ndoubles +=1;
      printf(" (doubles!)\n");
    }else{
      printf("\n");
      doubles = false;
      ndoubles = 0;
    }
    if(ndoubles) printf("Double #%i\n",ndoubles);
    if(ndoubles == 3){
      printf("Going to jail for triple doubles\n");
      jail();
      continue;
    }
    position += roll;
    position %= 40;
    switch(position){
    case 2:
    case 17:
    case 33:
      printf("(CC1): ");
      cc();
      break;
    case 22:
    case 36:
    case 7:
      printf("(CH1): ");
      ch();
      break;
    default:
      printf("Nothing of interest\n");
    }
    if(position==30){
      jail();
      break;
    }
    printf("New position: %2i\n",position);
    if(doubles && (position != 10)){
      printf("Going again because of doubles\n");
      ndoubles += 1;
    }else{
      turns++;
      ndoubles = 0;
    }
    squares[position]++;
  }
  for(int i=0;i<40;i++){
    printf("Square #%2i: %i\n",i,squares[i]);
  }
}
  

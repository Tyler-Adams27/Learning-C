#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main(){

  int number;
  bool isPrime;
  float root;

  printf("Enter a number: ");
  scanf("%i", &number);
  
  root = sqrt(number);

  if(number <= 1){
    isPrime = false;
  }
  else{
  isPrime = true;
  }
  for(int i=2; i < root; i++){
    if(number % i == 0){
      isPrime = false;
      break;
    }

  }
  
  if(isPrime == true)
  {
    printf("%i is prime!\n", number);
  }
  else if (isPrime == false)
  {
    printf("%i is not prime!\n", number);
  }
}

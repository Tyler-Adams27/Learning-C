#include <stdio.h>
#include <stdlib.h>


int main()
{
  int input;
  float c_conversion = 1.8;
  int add = 32;
  float answer;

  printf("Enter a celsius number: ");
  scanf("%i", &input);

  answer = input * c_conversion + add;
  printf("%i degrees celsius is equal to %0.1f degrees in fahrenheit.\n", input, answer);
  return 0;
}

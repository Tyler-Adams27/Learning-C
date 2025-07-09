#include <stdio.h>



void main()
{
  float num_1;
  float num_2;
  float answer;

  printf("Enter first float:  ");
  scanf("%f", &num_1);
  printf("Enter second float:  ");
  scanf("%f", &num_2);
  answer = num_1 * num_2;
  printf("The answer is: %f\n", answer);
  
}

#include <stdio.h>

void main()
{
  int first_num;
  int second_num;
  int temp_num;



  printf("Enter the first number ");
  scanf("%i", &first_num);
  printf("Enter the second number ");
  scanf("%i", &second_num);
  printf("This is before the swap. %i, %i.\n", first_num, second_num);

  temp_num = first_num;
  first_num = second_num;
  second_num = temp_num;
  printf("This is after the swap. %i, %i.\n", first_num, second_num);

}

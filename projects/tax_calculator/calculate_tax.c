#include <stdio.h>
#include <stdlib.h>

// To do:
//
// 1. Get the tax rates.
// 2. 
//
//
//
//
//
char* get_input()
{
  char* salary = malloc(100);
  printf("Enter your salary: ");
  scanf("%s", salary);
  printf("Haha your salary is %s\n", salary);
  return salary;
}

int get_rate()
{
  printf("Main!\n");
  return 0;
}

int main()
{
  char* fin_salary = get_input();
  free(fin_salary);
  return 0;
}

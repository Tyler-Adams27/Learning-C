#include <stdio.h>
#include <stdlib.h>

// Variables
int personal_allowance = 12570;
char* salary;
int rate;
char* rate_text;
int salary_int;
float taxable_income;
float after_taxes;
float tax_total;
//

char* get_input()
{
  salary = malloc(100);
  printf("Enter your salary: ");
  scanf("%s", salary);
  return salary;
}

int get_rate(char* salary)
{
  salary_int = atoi(salary);
  if(salary_int < personal_allowance)
  {
    rate = 0;
    rate_text = "None (0%)";
  }
  else if(personal_allowance < salary_int && salary_int < 50270)
  {
    rate = 1;
    rate_text = "Basic (20%)";
  }
  else if (50270 < salary_int && salary_int < 125140)
  {
    rate = 2;
    rate_text = "Higher (40%)";
  }
  else
  {
    rate = 3;
    rate_text = "Additonal (45%)";
  }
  return rate;
}

float calculate_tax(int salary_int)
{
  if(rate == 0)
  {
    after_taxes = (float)salary_int;
    tax_total = 0;
  }
  else if(rate == 1)
  {
    taxable_income = salary_int - personal_allowance;
    tax_total = taxable_income * 0.2;
    after_taxes = (float)salary_int - tax_total;
  }
  else if(rate == 2)
  {
    taxable_income = (float)salary_int - personal_allowance;
    tax_total = taxable_income * 0.4;
    after_taxes = (float)salary_int - tax_total; 
  }
  else
  {
    after_taxes = (float)salary_int * 0.55;
    tax_total = (float)salary_int * 0.45;
  }
  return after_taxes;
}

int main()
{
  char* test = get_input();
  int test_int = get_rate(salary);
  float test_float = calculate_tax(salary_int);
  printf("Your rate is %s\n", rate_text);
  printf("Your take home pay is £%0.2f\n", test_float);
  printf("The tax you pay is £%0.2f\n", tax_total);
  printf("\nDISCLAIMER: THIS IS NOT TO BE USED FOR ACTUALLY CALCULATING TAXES. USE OFFICIAL WEBSITES TO DO SO.\n");
  printf("\n");
  free(salary);
}

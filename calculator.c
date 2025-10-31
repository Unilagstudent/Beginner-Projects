 #include <stdio.h>
#include <stdlib.h>
 #include <math.h>

int add (num1 , num2) {
 return num1 + num2;
};

int sub (num1 , num2) {
 return num1 - num2;
};

int mul (num1 , num2) {
 return num1 * num2;
};

 int main() {
  int num1;
  int num2;
 int choice;
 printf("Good Day, what exactly do you want to do ?\n");
 printf("1. Addition\n");
 printf("2. Subtraction\n");
 printf("3. Multiplication\n");
 printf("4. Division\n");
 printf("5. Exit\n");
  scanf("%d", &choice);
   printf("\n");

printf("Enter the first number \n");
  scanf("%d", &num1);
  printf("Enter the second number \n");
  scanf("%d", &num2);

  switch (choice) {
   case 1:
    printf("Result: %d\n", add(num1, num2));
   break;
   case 2:
    printf("Result: %d\n", sub(num1, num2));
   break;
   case 3:
    printf("Result: %d\n", mul(num1, num2));
   break;
   case 4:
    printf("Result: %.2f\n", div(num1, num2));
   break;
   case 5:
    exit(0);
   default:
    printf("Invalid choice!\n");
  }
}

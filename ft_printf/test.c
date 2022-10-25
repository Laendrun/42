#include <stdio.h>
#include <stdarg.h>

void test(int num,...) {

   va_list valist;
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      printf("%d\n" ,(va_arg(valist, int)));
   }
	
   /* clean memory reserved for valist */
   va_end(valist);
}

int main() {
   test(4, 2,3,4,5);
   //test(3, 5,10,15);
}
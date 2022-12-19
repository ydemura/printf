//
//  test_ft_printf.c
//  ft_printf
//
//  Created by Yuliia Demura on 12/3/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

// when printf fails
// when after % there is no valid follower, it breaks "Invalid conversion specifier '_'"
// when the number of % and the number of arguments not equal it fails

#include "test_ft_printf.h"
#include "ft_printf.h"
#include "libft.h"
#include <assert.h>

 void	test_start_format_minus(void)
 {
	printf("test_start_format_minus\n\n");
	printf("or:");
 	printf("|%-5i|%-10i|test%---5i|%-*i|", 15, 3, 666, 14, 15);
	printf("\nmy:");
	ft_printf("|%-5i|%-10i|test%---5i|%-*i|", 15, 3, 666, 14, 15);
 	printf("\n");
	printf("----------------------------------------------\n");
 }

 void	test_only_inicialisation_sign(void)
 {
 	printf("test_only_inicialisation_sign\n\n");
	printf("my:");
 	ft_printf("%%%%");
 	printf("\nor:");
 	printf("%%%%");
 	printf("\n");
	printf("----------------------------------------------\n");
 }

 void	test_only_zero_sign(void)
 {
	printf("test_only_zero_sign\n\n");
	printf("or:");
	printf("|%00000000005i|%010i|%05i|%0*i|", 15, 3, 666, 14, 15);
	printf("\nmy:");
	ft_printf("|%00000000005i|%010i|%05i|%0*i|", 15, 3, 666, 14, 15);
	printf("\n");
	printf("----------------------------------------------\n");
 }

void	test_minus_and_zero_together(void)
{
	printf("test_minus_and_zero_together\n\n");
	printf("or:");
	printf("|%00---00000005i|%-010i|%0-5i|%-0*i|", 15, 3, 666, 14, 15);
	printf("\nmy:");
	ft_printf("|%00---00000005i|%-010i|%0-5i|%-0*i|", 15, 3, 666, 14, 15);
	printf("\n");
	printf("----------------------------------------------\n");
}

void	test_mistakes_in_minus_and_zero(void)
{
	printf("test_mistakes_in_minus_and_zero\n\n");
	printf("or:");
	printf("|%0i|%0*i|%-i|%-*i|", 1, 6, 22222, 3, 6, 4);
	printf("\nmy:");
	ft_printf("|%0i|%0*i|%-i|%-*i|", 1, 6, 22222, 3, 6, 4);
	printf("\n");
	printf("----------------------------------------------\n");
}

void	test_precision(void)
{
	printf("test_precision\n\n");
	
	printf("or:");
	printf("|%05.2i|%.3i|%*.i|", 1, 2, 5, 3);
	printf("\nmy:");
	ft_printf("|%05.2i|%.3i|%*.i|", 1, 2, 5, 3);
	printf("\n");
	printf("----------------------------------------------\n");

}

void	test_ft_printf(void)
{
	test_only_inicialisation_sign();// "%%%%" -> %%
	test_start_format_minus();
	test_only_zero_sign();
	test_minus_and_zero_together();
	test_mistakes_in_minus_and_zero();
	
	test_precision();
	
	
	
//	-Wall -Wextra -Werror
	
	
	
//	test_ft_printf3(); // -> error messages
//	test_original_printf() - from main plz
}






void	test_original_printf(void)
{
	//https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160
	
	printf("1. padding to right in the frame given (number 8): \n");
	printf("%8i\n%8d\n%8s\n%8c\n", 123, 1, "string", 'c');

	printf("\n2. padding to left in the frame given (number 8): \n");
	printf("%-8i\n%-8d\n%-8s\n%-8c\n", 123, 1, "string", 'c');

	printf("\n3.1 adding '0' at the beginning as many I as put number (8): \n");
	printf("%08i\n%08d\n", 123, 1);
	printf("'0' doesnt work with '-', '-' dominate\n");
	printf("'0' doesnt work with s, c, maybe others?\n");
	printf("\n3.2 adding '0' at the beginning as many I as put number, if number is 0 or no number no changes: \n");
	printf("%00i\n%00d\n", 123, 1);
	printf("\n3.3 adding '0' with '*', number of 0 specified in arguments: \n");
	printf("%0*i\n%0*d\n", 8, 123, 8,  1);
	int i = 13;
//	unsigned int x = 55;
//	unsigned int X = 56;
//	unsigned int u = 35;
//	char s[] = "string";
//	char *p = s;
//	char c = 'b';

	printf("%.4i", i);
	
//	printf("exmpl: |%%05i|--->|%05i|\n", 1);
//	printf("exmpl: |%%05.2i|->|%05.2i|\n", 1);
//	printf("exmpl: |%%.2i|->|%.2i|\n", 1);
//
//
//	printf("\n");
//	printf("exmpl: |%%-5i|--->|%-5i|\n", 1);
//	printf("exmpl: |%%-5.2i|->|%-5.2i|\n", 1);
//	printf("\n");
//	printf("exmpl: |%%02.3i|->|%02.3i|\n", 1);

// -Wall -Wextra -Werror

}

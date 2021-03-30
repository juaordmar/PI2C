/*
 * tests.c
 *
 *  Created on: 9 nov. 2020
 *      Author: LENOVO
 */

#include "tests.h"

int main(){
	printf("TEST 1\n=============================\n");
	test1("ficheros/PI2Ej1DatosEntrada.txt");
	printf("\nTEST 2\n=============================\n");
	test2("ficheros/PI2Ej2DatosEntrada.txt");
	printf("\nTEST 3\n=============================\n");
	test3("ficheros/PI2Ej3DatosEntrada.txt");
}

void test1(char * file){
	iterator f = file_iterable_pchar(file);
	while(iterable_has_next(&f)){
		char * linea = (char *)iterable_next(&f);
		iterator it = split_iterable_pchar(linea, "#");
		list ls = list_empty(pchar_type);
		while(iterable_split_has_next(&it)){
			char * e = (char *)iterable_split_next(&it);
			list_add(&ls, e);
		}char * a = (char *)list_get(&ls, 0); char * b = (char *)list_get(&ls, 1);
		printf("%s, %s\n", a, b);
		printf("1. Iterativa (while): %i\n", ej1Iterativo(a, b));
		printf("2. Recursiva final: %i\n\n", ej1RecursivoFinal(a, b));
	}
}

void test2(char * file){
	char mem[500];
	int i = 0;
	list ls = file_to_list_of_list(file);
	while(i < list_size(&ls)){
		list ls2 = *((list*)list_get(&ls, i));
		printf("%s\n", list_tostring(&ls2, mem));
		int a = *(int *)list_get(&ls2, 0); int b = *(int *)list_get(&ls2, 1);
		bool res = ej2Iterativo(a, b);
		printf("1. Iterativa (while): %s\n", bool_tostring(&res, mem));
		bool res2 = ej2RecursivoFinal(a, b);
		printf("2. Recursiva final: %s\n\n", bool_tostring(&res2, mem));
		i++;
	}
}

void test3(char * file){
	char mem[500];
		int i = 0;
		list ls = file_to_list_of_list(file);
		while(i < list_size(&ls)){
			list ls2 = *((list*)list_get(&ls, i));
			printf("%s\n", list_tostring(&ls2, mem));
			int a = *(int *)list_get(&ls2, 0); int b = *(int *)list_get(&ls2, 1);
			int res = ej3Iterativo(a, b);
			printf("1. Iterativa (while): %s\n", int_tostring(&res, mem));
			int res2 = ej3RecursivoNoFinal(a, b);
			printf("2. Recursiva no final: %s\n", int_tostring(&res2, mem));
			int res3 = ej3RecursivoFinal(a, b);
			printf("3. Recursiva final: %s\n\n", int_tostring(&res3, mem));
			i++;
	}
}



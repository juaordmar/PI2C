/*
 * ejercicio1.c
 *
 *  Created on: 8 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio1.h"

int ej1Iterativo(char * a, char * b){
	int i = 0; int j = strlen(a); int k = (i+j)/2;
	while((j-i)>1){
		if(a[k]==b[k]){
			i = k;
			k = (i+j)/2;
		}else{
			j = k;
			k = (i+j)/2;
		}
	}return j;
}

int ej1RecursivoFinal(char * a, char * b){
	return ej1RecursivoFinalAux(a, b, 0, strlen(a), (strlen(a)/2));
}

int ej1RecursivoFinalAux(char * a, char * b, int i, int j, int k){
	int res = 0;
	if((j-i)>1){
		if(a[k]==b[k]){
			i = k;
			k = (i+j)/2;
		}else{
			j = k;
			k = (i+j)/2;
		}res = ej1RecursivoFinalAux(a, b, i, j, k);
	}else{
		res = j;
	}return res;
}



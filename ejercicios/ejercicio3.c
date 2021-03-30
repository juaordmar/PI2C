/*
 * ejercicio3.c
 *
 *  Created on: 9 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio3.h"

long ej3Iterativo(long a, int n){
	long res = 1;
	while(n > 0){
		if(n%2==1){
			res = res * a;
		}a = a * a;
		n = n/2;
	}return res;
}

long ej3RecursivoNoFinal(long a, int n){
	long res;
	if(n > 0){
		res = ej3RecursivoNoFinal(a, n/2);
		if(n%2==1){
			res = res*res*a;
		}else{
			res = res*res;
		}
	}else{
		res = 1;
	}return res;
}

long ej3RecursivoFinal(long a, int n){
	return ej3RecursivoFinalAux(a, n, 1);
}

long ej3RecursivoFinalAux(long a, int n, long res){
	long x;
	if(n > 0){
		if(n%2==1){
			res = res * a;
		}x = ej3RecursivoFinalAux(a*a, n/2, res);
	}else{
		x = res;
	}return x;
}







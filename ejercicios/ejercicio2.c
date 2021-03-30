/*
 * ejercicio2.c
 *
 *  Created on: 9 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio2.h"

bool ej2Iterativo(int a, int b){
	bool res;
	while (b <= a){
		a = a - b;
	}if (a == 0){
		res = true;
	}else{
		res = false;
	}return res;
}

bool ej2RecursivoFinal(int a, int b){
	return ej2RecursivoFinalAux(a, b, false);
}

bool ej2RecursivoFinalAux(int a, int b, bool c){
	if(a == 0){
		c = true;
	}else if(a >= b){
		c = ej2RecursivoFinalAux(a - b, b, c);
	}return c;
}




// asmSecondTask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Matrix {
	int** arrOfColumns;
	int size;
};

struct Matrix* createMatrix(int size) {
	int** arrOfColumns;
	__asm {
		mov		ecx, size
		mov		ebx, arrOfColumns
	//	lea		edx, arrOfColumns
	CYCLE: 
	//	push	edx
		push    ecx
		push	ebx
		mov		eax, ecx
		mov		ecx, 4
		imul	ecx
		push	eax
		call	malloc
		add		esp, 4
		pop		ebx
	}
}

void deleteMatrix(struct Matrix* matrix) {
	__asm {

	}
}

int getElement(struct Matrix* matrix, int i, int j) {
	__asm {

	}
}

void setElement(struct Matrix* matrix, int i, int j, int element) {
	__asm {

	}
}

void printMatrix(struct Matrix* matrix) {
	__asm {

	}
}

int countOddSumRows(struct Matrix* matrix) {
	__asm {

	}
}

int main()
/*С помощью ассемблерных  вставок  необходимо
реализовать  функции: 
создать матрицу;
удалить матрицу;
прочитать,  изменить элемент,  стоящий на пересечении i-той строки и j-го столбца;
печать матрицы;
функции, которая описывается в задании.*/
/*
7. Посчитать  количество  строк матрицы, сумма  элементов  которых  есть
нечетное число, если матрица хранится в виде массива столбцов.
*/
{
	__asm {

	}
    return 0;
}


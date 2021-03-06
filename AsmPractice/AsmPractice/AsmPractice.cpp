// AsmPractice.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int getLength(char* s) {
	__asm {
		mov		ebx, s
		mov		eax, 0
		ITERATE :
		cmp		byte ptr[ebx], 0
			je		RETURN
			inc		eax
			inc		ebx
			jmp		ITERATE
			RETURN :
	}
}

int getNumberOfOccurrences(char* s, char c) {
	__asm {
		//??????????????????????????
		mov		ebx, s
		mov		al, c
		mov		eax, 0
	ITERATE :
		mov		bl, [ebx]
		cmp		[ebx], 0
		je		RETURN
		cmp		bl, al
		inc		ebx
		jne		ITERATE
		inc		eax
	RETURN :
	}
}

char* getRepeatingChar(char* s, int numOfOccurrences) {
	__asm {
		mov		ebx, s
		mov		edx, numOfOccurrences
		push	ebx
		push	ebx
		call	getLength
		//	eax = getLength(s)
		add		esp, 4
		pop		ebx
		//	ebx = s
		mov		edx, 0
		cdq
		// (eax == length) / (ecx == numOfOcc) = eax:edx
		mov		ecx, numOfOccurrences
		div		ecx
		inc		eax
		mov		edx, ecx
		//	eax = sup(result.length) = str.length / numOfOccurrences + 1
		push	eax
		call	malloc
		add		esp, 4
		//	eax = char*[str.length / numOfOccurrences + 1];
		push    eax //указатель на начало массива с результатом кладём в стек
	ITERATE :
		cmp		byte ptr [ebx], 0
		je		RETURN
		xor		ecx, ecx
		mov		ecx, [ebx]
		push	eax	//указатель на очередной элемент массива кладём в стек, чтобы не потерять
		push	ebx
		push	ecx
		mov		ebx, s
		push	ebx
		call	getNumberOfOccurrences
		add		esp, 8
		pop		ebx
		cmp		edx, eax
		inc		ebx
		jne		ITERATE
		pop		eax //достаём указатель на очередной элемент
		mov		ecx, [ebx - 4]
		mov		[eax], ecx
		inc		eax
	RETURN :
		pop		eax
	}
}

int main()
{
	const int STR_SIZE = 100;
	char s[STR_SIZE];
	int numOfOccurrences = 0;
	const char* format = "%s%d";
	char* result;
	__asm {
		lea		eax, numOfOccurrences
		push	eax
		lea		eax, s
		push	eax
		mov		ecx, format
		push	ecx
		call	scanf
		add		esp, 12
		//scanf("%s%d", s, &numOfOccurrences);

		lea		ebx, s
		mov		eax, numOfOccurrences
		push	eax
		push	ebx
		call	getRepeatingChar
		add		esp, 8
		mov		result, eax
	}
	int length = strlen(result);
	for (int i = 0; i < length; i++) {
		cout << result[i] << " ";
	}
	
	
	system("pause");

	return 0;
}


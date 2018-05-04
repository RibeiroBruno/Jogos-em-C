#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<time.h>
#include "ADMIN\\forca_funcoes.h"
#include "ADMIN\\forca_funcoes_ind.h"
#include "ADMIN\\forca_MODE.h"

void main() {
	system("color 1F");
	system("title FORCA 3.1");
	setlocale(LC_ALL,"Portuguese");
	nome();
	Sleep(3000);
	system("cls");
	
	menu();
}

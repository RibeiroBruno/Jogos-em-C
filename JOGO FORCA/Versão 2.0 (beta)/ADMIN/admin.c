#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<time.h>
#include "FORCA_ADMIN.h"

int main(void){
	setlocale(LC_ALL,"portuguese");
	ITEM* LISTA_INICIO;
	LISTA_INICIO = CRIA_LISTA();
	//NCERRA_LISTA(LISTA_INICIO);
	menu_admin(LISTA_INICIO);	
}

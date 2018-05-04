#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void limpa_palavra(char palavra[]){
	int i, tam;
	tam=strlen(palavra);
	for(i=0;i<tam;i++){
		palavra[i]=' ';
	}
}

int main(void)
{
	setlocale(LC_ALL, NULL);
	srand(time(NULL));
	int i, tam, j=0, aux=0, aleat; 
	char letra, op, palavra[150];
	char frase[4][150]=
	{"Caro RAJA, detentor de todo conhecimento, dos céus e das profundezas do universo...",
	"Me responda RAJA! Preciso dos seus conhecimentos e de toda sua sabedoria!",
	"Me ajude caro RAJA! Preciso dessa resposta o quanto urgente, eu imploro!",
	"RAJA! Que possui toda sabedoria e sapiência, conhecimento, me ajude por favor!"};
	char msgerro[4][150] = {"Essa pergunta eu não quero responder! Não insista!",
	"Não sou obrigado a ler isso... Faça uma pergunta interessante!",
	"Que tédio... Não me encha a paciência por favor!",
	"Não vou gastar minha sabedoria para responder isso!"};
	do{
		system("cls");
		limpa_palavra(palavra);
		j=0;
		aux=0;
		aleat=rand()%3;
		for(i=0;i<150;i++){
			if(i==0){
				printf("\n\n\n");
				printf("\t||----------------------------------------------------------------------||\n");
				printf("\t||                                                                      ||\n");
				printf("\t||");
			}
			fflush(stdin);
			letra=getch();
			if(letra==13) break;
			if(letra==',') aux=i;
			
			if(aux==0){
				printf("%c",letra);
			}
	
			if(aux==i && aux!=0) {
				if(j>0) palavra[j-1]=letra;
				printf("%c",frase[aleat][j]);
				j++;
				aux++;
			}		
		}
		printf("\n");
		printf("\t||                                                                      ||\n");
		printf("\t||----------------------------------------------------------------------||\n\n");
		printf("\t||----------------------------------------------------------------------||\n");
		printf("\t||                                                                      ||\n");
		printf("\t||");
		if(aux==i){
			printf("%s\n",palavra);
		}
		else printf("%s\n",msgerro[aleat]);
		printf("\t||                                                                      ||\n");
		printf("\t||----------------------------------------------------------------------||\n");
		puts("\tDeseja continuar?\n\tDigite enter para fazer outra pergunta\n\tQualquer tecla para encerrar\n\t\t");
		fflush(stdin);
		op=getch();
	}while(op==13 || op=='s' || op=='S');
}

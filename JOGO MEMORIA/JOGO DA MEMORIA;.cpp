#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

void instruc ();

char jogo ();

void instruc () {
	puts("\tEste jogo consiste em observar um conjunto de 5 números aletórios e tentar escreve-los na ordem.");
	puts("\tAtente-se pois os numeros aparecerao por 5 segundos somente ");
	puts("\tAssim que terminar pressiona ENTER para começar");
}

char jogo () {
	int nums[5];
	int i, j;
	char op; 
	int aleat, tent, acerto=0;
	int tempo = 5;
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		do{
			aleat=rand()%100;
		}while(aleat==nums[i]);
		nums[i]=aleat;	
	}
	
 	do{
 		system("cls");
		printf("Decore os numeros em: %d\n\n\t\t", tempo);
		tempo--;
 		for(i=0;i<5;i++){
 			printf("%d\t",nums[i]);
		}
		printf("\n");
		Sleep(1000);
	}while(tempo>0);
		
		system("cls");
		
	for(i=0;i<5;i++) {
		printf("Digite o %dº numero: ",i+1);
		scanf("%d", &tent);
		if(tent==nums[i]){
			acerto++;
		}	
	}
	
	switch(acerto){
		case 5: printf("Muito bem! Voce acertou toda a sequencia!\n\n\t"); break;
		case 3: printf("Olha... Dava pra ser melhor, voce acertou %d numeros.\n\n\t", acerto); break;
		case 4: printf("Olha... Dava pra ser melhor, voce acertou %d numeros.\n\n\t", acerto); break;
		case 0: printf("Voce não foi bem... acertou %d numeros\n\n\t", acerto); break;
		case 1: printf("Voce não foi bem... acertou %d numeros\n\n\t", acerto); break;
		case 2: printf("Voce não foi bem... acertou %d numeros\n\n\t", acerto); break;
	}
	for(i=0;i<5;i++){
 		printf("%d\t",nums[i]);
	}
	Sleep(4000);
	system("cls");	
	puts("Deseja continuar? \n\t Sim - S \n\t Nao - N");
	op = getchar();
	return op;
}
	
main() {
	int i;
	char x; 
	system("color 1F");
	SetConsoleTitle("Jogo da Memória");
	
	instruc();
	
	do{
		x=getch ();
	}while(x!=13);
	
	do{
		system("cls");
		jogo();
		x=jogo();
		i++;
	} while(x=='S' || x=='s');	
}

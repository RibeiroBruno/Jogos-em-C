#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<time.h>

void nome();
void jogo_individual(int s);
void jogo_modo_dupla();
void leiamejogo_individual(int s);
void leiamejogo_modo_dupla();

	void leiamejogo_individual(){
		puts("\t\t Instrucoes\n\n");
		puts("\t Neste modo o computador escolhe uma palavra aleatoriamente");
		puts("\t 1. O jogo termina ao acertar todas as letras da palavra(exceto hifens '-')");
		puts("\t 2. Letras repetidas não contam erros nem acertos");
		puts("\t 3. O jogo permite até 6 erros, como no modo clásico (cabeça, corpo, dois bracos e duas pernas) e caso atinja o limite de erros se ele encerra");
		puts("\t 4. A qualquer momento o usuario pode arriscar a palavra inteira, que deve ser escrita exatamente igual a correta, pois neste caso nao havera outra chance");
		puts("\t\t APERTE QUALQUER TECLA PARA COMEÇAR!");
		system("pause>>null");
		system("cls");
	}
	void leiamejogo_modo_dupla(){
		puts("\t\t Instrucoes\n\n");
		puts("\t Neste modo um usuario digita uma palavra desafio para que o outro jogue:");
		puts("\t 1. O jogo termina ao acertar todas as letras da palavra(exceto hifens '-')");
		puts("\t 2. Letras repetidas não contam erros nem acertos");
		puts("\t 3. O jogo permite até 6 erros, como no modo clásico (cabeça, corpo, dois bracos e duas pernas) e caso atinja o limite de erros se ele encerra");
		puts("\t 4. A qualquer momento o usuario pode arriscar a palavra inteira, que deve ser escrita exatamente igual a correta, pois neste caso nao havera outra chance");
		puts("\t\t APERTE QUALQUER TECLA PARA COMEÇAR!");
		system("pause>>null");
		system("cls");
	}
 	
	 void nome() {
		printf("\n\n\n\n\n\n");
		puts("\t\t\t     _________    _________     _________    ________          ______          ");
		puts("\t\t\t     |FFFFFFFF|  /OOOOOOOOO\\   |RRRRRRRRR\   /CCCCCCCC\\        /AAAAAA\\         ");
		puts("\t\t\t     |FFFFFFFF| |OOOOOOOOOOO|  |RRRRRRRRR| |CCCCCCCCCC\\      /AAAAAAAA\\        ");
		puts("\t\t\t     |FF|       |OO       OO|  |RR     RR| |CC|      CC|    /AA      AA\\       ");  
		puts("\t\t\t     |FFFFFF|   |OO       OO|  |RR     RR| |CC|            /AA        AA\\      ");
		puts("\t\t\t     |FFFFFF|   |OO       OO|  |RRRRRRRR/  |CC|           /AAAAAAAAAAAAAA\\     ");
		puts("\t\t\t     |FF|       |OO       OO|  |RRRR\\RR\\   |CC|______CC| /AAAAAAAAAAAAAAAA\\    ");
		puts("\t\t\t     |FF|       |OOOOOOOOOOO|  |RR   \\RR\\  |CCCCCCCCCC/ /AA              AA\\   ");
		puts("\t\t\t     |FF|        \\OOOOOOOOO/   |RR    \\RR\\  \\CCCCCCCC/ /AA                AA\\  ");
	}
	
void jogo_modo_dupla(){
	const int alf=26;
	int i, j, n=0, p, tam, tamanpalav,aux=0, totalacerto=0, acerto=0, erro=0;
	char op, tent, tentant[alf], tentcomp[50],tenterro [alf], palavra [50], palaux[50];
	
	for(i=0;i<50;i++){
		palaux[i]=' ';
		tentcomp[i]=' ';
	}
	
	puts("Digite uma palavra simples ou composta de ate 50 caracteres:");
	
	//recebe uma palavra como parâmetro para o jogo
	fflush(stdin);
	gets(palavra);
	strcpy(palaux,palavra);
	//mede tamanho da palavra
	tam=strlen(palavra);
	
	//diferencia letras de espaços em branco
	for(i=0; i<tam;i++) {
		if(palavra[i]==' ' || palavra[i]=='-'){
		aux++;	
		}
	}
	aux=tam-aux;
	
	system("cls");
	
	//palavra auxiliar trabalha junto com palavra parâmetro porém é a exibida durante op jogo composta por _ que são substituidos pelas letras certas.	
	for(i=0; i<tam; i++) {
		if(palavra[i]!=' ')
			palaux[i]='_';	
		else
		  	palaux[i]=' ';
		if(palavra[i]=='-')
			palaux[i]='-';
	}
	// comando de repetição que mantem o jogon rodando enquanto usuario não acertar a palavra ou uktrapassar o limite de acertos		
	do{
	printf("Desafio contem %d letras: \n", aux);
	printf("\t");
	puts(palaux);
	printf("\n");
	
	puts("\n Digite uma letra:");
	printf("\t");
	fflush(stdin);
	gets(tentcomp);
	tamanpalav=strlen(tentcomp);

	if(tamanpalav==1) {
		tent=tentcomp[0];
	//Testa se tentativa ja foi jogada anteriormente.
	for(i=0;i<n;i++){
		if(tentant[i]==tent) {
			puts("Voce ja jogou esta letra! Tente novamente");
			Sleep(1500);
			system("cls");
			p=1;
		}	
	}
	if(p!=1) {
		//Armazena a tentativa em uma posição de tentativas anteriores
		tentant[n]=tent;
		n++;
		//busca letra dentro da string palavra principal, e se encontrar substitui na mesma posição da palavra auxiliar e calcula acertos por tentativa.
		for(i=0;i<tam;i++) {
			if(palavra[i]==tent) {
				acerto++;
				palaux[i]=tent;
				}
			}
		totalacerto+=acerto;
			
		//exibe palavra auxiliar com os acertos da jogada e parabeniza o acerto. Sistema aguarda 4 segundos antes de solicitar outra letra
		if(acerto>0 && totalacerto<aux) {
			printf("\t");
			puts(palaux);
			printf("\n");
			printf("Muito bem, Voce acertou %d letras",acerto);
			Sleep(2000);
			system("cls");	
		}
		//caso usuario não acerte sistema informa numero de erros, exibe sistuação atual do jogo, total de erros e palavra atual
		else if(acerto==0) {
			tenterro[erro]=tent;
			erro++;
			puts("Voce errou! ");
			printf("Voce errou %d de 6 tentativas\n", erro);
			Sleep(1500);
			system("cls");
		}
	}
		// informa quais palavras usuário já tentou e errou
		if(erro>0 && totalacerto!=aux ) {
			puts("Voce tentou as letras");
			for(i=0;i<erro;i++) {
				printf("%3c",tenterro[i]);
			}
			printf("\n");
		}
	}
		if(tamanpalav>1) {
			if(strcmp(palavra,tentcomp)==0) {
			system("cls");
			totalacerto=aux;
			}
			else if(strcmp(palavra,tentcomp)!=0) {
			system("cls");
			erro=6;
			}
		}
		acerto=0;
		p=0;
		// jogo continua por 6 arros ou acerto de todas letras da palavra
	}while(erro<6 && totalacerto<aux);
	
	if(erro==6) {
		system("cls");
		puts("Nao foi dessa vez, Você perdeu!");
		printf("\t");
		puts(palavra);
	}
	else if(totalacerto==aux){
		system("cls");
		puts("Parabens voce acertou a palavra:");
		printf("\t");
		puts(palavra);
	}
	//opção por continuar ou para o jogo.
	puts("Deseja continuar? (""S"" para sim e ""N"" para nao):");
	fflush(stdin);
	scanf("%c", &op);
	if(op=='S' || op=='s') {
		system("cls");
		jogo_modo_dupla();
	}
	else	
	system("pause");
}

void jogo_individual(int s) {
	const int alf=26;
	int i, j, n=0, p, tam, perguntas, tamanpalav, aux=0, totalacerto=0, acerto=0, erro=0, quant=0;
	char op, tent, tentcomp[50], tentant[alf], tenterro [alf], palaux[50], palavraprinc[50];
	FILE *fpalavra;
	
	struct palav_dica {
	char palavra[50]; 
	char dica[100];
	char extra[20];
	};
	
	struct palav_dica palavra[100];
	int aleat;
	
	fpalavra=fopen("Palavras.txt","r");
	if(fpalavra==NULL) {
			puts("Erro de execucao: arquivo base nao encontrado ou corrompido nao pode ser aberto!\a");
			system("pause");
	}
	else 
		while(feof(fpalavra)==0) {
			strcpy(palavra[i].extra, "nao sorteado");
			fgets(palavra[i].palavra, 50, fpalavra);
			if(feof(fpalavra)!=0) break;
			fgets(palavra[i].dica, 100, fpalavra);
			if(feof(fpalavra)!=0) break;
			i++;
		}
		fclose(fpalavra);
		perguntas=i;
	do{	
		n=0; aux=0; totalacerto=0; acerto=0; erro=0; quant=0;
		for(i=0;i<50;i++){
			palaux[i]=' ';
			palavraprinc[i]=' ';
		}
		if(s<perguntas) {
		do{
		srand(time(NULL));
		aleat=rand()%perguntas;
		}while(strcmp(palavra[aleat].extra,"Ja sorteado")==0);
		s++;
		strcpy(palavra[aleat].extra,"Ja sorteado");
		strcpy(palavraprinc,palavra[aleat].palavra);
		
		//todas tentativas anteriores igual a "_"
		for(i=0;i<alf;i++){
			tentant[i]='_';
		}
		//mede tamanho da palavra
		//puts(palavraprinc);
		tam=strlen(palavraprinc);
		palavraprinc[tam-1]='\0';
		tam=strlen(palavraprinc);
		//diferencia letras de espaços em branco
		for(i=0; i<tam-1;i++) {
			if(palavraprinc[i]==' ' || palavraprinc[i]=='-' ){
			aux++;	
			}
		}
		aux=tam-aux;
		
		//palavra auxiliar trabalha junto com palavra parâmetro porém é a exibida durante op jogo composta por _ que são substituidos pelas letras certas.	
		for(i=0; i<tam; i++) {
			if(palavraprinc[i]!=' ')
				palaux[i]='_';
			else
			  	palaux[i]=' ';
			if(palavraprinc[i]=='-')
				palaux[i]='-';
		}
		// comando de repetição que mantem o jogon rodando enquanto usuario não acertar a palavra ou uktrapassar o limite de acertos		
		do{
			puts(palavra[aleat].dica);
			printf("Desafio contem %d letras: \n", aux);
			printf("\t");
			puts(palaux);
			printf("\n");
			
			puts("\n Digite uma letra ou arrisque a palavra completa se souber:");
			printf("\t");
			fflush(stdin);
			gets(tentcomp);
			tamanpalav=strlen(tentcomp);

			if(tamanpalav==1) {
				tent=tentcomp[0];
			
			//Testa se tentativa ja foi jogada anteriormente.
			for(i=0;i<n;i++){
				if(tentant[i]==tent) {
					puts("Voce ja jogou esta letra! Tente novamente");
					Sleep(1500);
					system("cls");
					p=1;
				}	
			}
			if(p!=1) {
				//Armazena a tentativa em uma posição de tentativas anteriores
				tentant[n]=tent;
				n++;
				//busca letra dentro da string palavra principal, e se encontrar substitui na mesma posição da palavra auxiliar e calcula acertos por tentativa.
				for(i=0;i<tam;i++) {
					if(palavraprinc[i]==tent) {
						acerto++;
						palaux[i]=tent;
						}
					}
				totalacerto+=acerto;
					
				//exibe palavra auxiliar com os acertos da jogada e parabeniza o acerto. Sistema aguarda 4 segundos antes de solicitar outra letra
				if(acerto>0 && totalacerto<aux) {
					printf("\t");
					puts(palaux);
					printf("\n");
					printf("Muito bem, Voce acertou %d letra(s)",acerto);
					Sleep(2000);
					system("cls");	
				}
				//caso usuario não acerte sistema informa numero de erros, exibe sistuação atual do jogo, total de erros e palavra atual
				else if(acerto==0) {
					tenterro[erro]=tent;
					erro++;
					puts("Voce errou! ");
					printf("Voce errou %d de 6 tentativas\n", erro);
					Sleep(1500);
					system("cls");
				}
			}		
		}	
				// informa quais palavras usuário já tentou e errou
				if((erro>0 && erro<=6) && totalacerto!=aux) {
					puts("Voce tentou as letras");
					for(i=0;i<erro;i++) {
						printf("%3c",tenterro[i]);
					}
					printf("\n");
				}
				
				//comparar palavra digitada com a palavra do desafio	
				if(tamanpalav>1) {
					if(strcmp(palavraprinc,tentcomp)==0) {
					system("cls");
					totalacerto=aux;
					acerto=aux;
					}
					else if(strcmp(palavraprinc,tentcomp)!=0) {
					system("cls");
					erro=6;
					}
				}
				acerto=0;
				p=0;
				// jogo continua por 6 arros ou acerto de todas letras da palavra
			}while(erro<6 && totalacerto<aux);
			
			if(erro==6) {
				system("cls");
				puts("Nao foi dessa vez, Voce perdeu!");
				printf("\t");
				puts(palavraprinc);
			}
			else if(totalacerto==aux){
				system("cls");
				puts("Parabens voce acertou a palavra:");
				printf("\t");
				puts(palavraprinc);
			}
			//opção por continuar ou para o jogo.
			puts("Deseja continuar? (""S"" para sim e ""N"" para nao):");
			fflush(stdin);
			scanf("%c", &op);
			if(op=='S' || op=='s') {
				strcpy(palaux,"");
				system("cls");		
			}
		}
		else {
			puts("fORCA Encontrou uma Falha! Precisa ser fechado");
			break;
		}	
	}while(op=='S' || op=='s');
	system("pause");
}

main() {
	int s=0, i, op;
	system("color 1F");
	setlocale(LC_ALL,"portuguese");
	/*nome();
	Sleep(3000);
	system("cls");*/
	
	puts("\t   _________________________________  ");	
	puts("\t ||                                 ||");
	puts("\t ||    Selecione o modo de jogo:    ||");
	puts("\t ||_________________________________||");
	puts("\n");
	puts("\t1. Modo dupla (dinamico) - Neste modo um usuário digita as palavras para o outro jogar.\n");
	puts("\t2. Modo individual - Neste modo você joga com palavras escolhidas randomicamente pelo computador.\n");
	puts("\t3. Sair\n");
	printf("\tSelecione o modo de jogo: ");
	
	scanf("%d", &op);
	system("cls");
	switch(op) {
		case 1: leiamejogo_modo_dupla(), jogo_modo_dupla(); break;
		case 2: leiamejogo_individual(), jogo_individual(s); break;
		case 3: system("pause"); break;
		default: puts("\t\tOpção invalida!"); break;
	}
}

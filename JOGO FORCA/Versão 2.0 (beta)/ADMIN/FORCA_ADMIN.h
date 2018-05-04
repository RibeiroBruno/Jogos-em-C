#ifndef FORCA_ADMIN_h
#define FORCA_ADMIN_H
#include<locale.h>

typedef struct palavra_e_dica{
	char palavra[50];
	char dica[100];
}PD;

typedef struct lista_temp{
	PD item;
	struct lista_temp *PROXIMO;
}LISTA;

typedef LISTA* ITEM;

ITEM *CRIA_LISTA(){
	ITEM* LISTA_INICIO= (ITEM *) malloc(sizeof(ITEM));
	if(LISTA_INICIO!=NULL)
		*LISTA_INICIO=NULL;
	return LISTA_INICIO;
}

void ENCERRA_LISTA(LISTA * LISTA_INICIO){
	LISTA * AUX;
	if(LISTA_INICIO != NULL)
		while(AUX!=NULL){
			LISTA_INICIO=AUX->PROXIMO;
			AUX=AUX->PROXIMO;
			free(AUX);
	}
}

int LISTA_VAZIA(ITEM* LISTA_INICIO){
	if(LISTA_INICIO==NULL){
		return 1;
	}
	if(*LISTA_INICIO==NULL){
		return 1;
	}
	else return 0;
}

void adiciona_palavras(ITEM* LISTA_INICIO){
	PD conteudo;
	char op; 
	do{
		printf("\n\n\t\t Inserir palavra:");
		printf("\n\n\t\t Digite a palavra para inserir na base:");
		fflush(stdin);
		fgets(conteudo.palavra, 50, stdin);
		printf("\n\n\t\t Digite a dica para a palavra acima(pense bem para não ser uma dica muito clara):");
		fflush(stdin);
		fgets(conteudo.dica, 100, stdin);
		printf("\n\n\t\t ||Palavra Digitada: \n");
		printf("\t\t ||%s\n", conteudo.palavra); 
		printf("\t\t ||%s\n", conteudo.dica); 
		printf("\n\n\t\t ||Confirma palavra e dica (S - SIM) (Quaquer tecla - NÃO): ");
		scanf("%c",&op);
		if(op=='S' || op=='s'){
			if(insere_lista(LISTA_INICIO, conteudo)==1){
				printf("\n\n\t\t Item Inserido com sucesso!\n");
				Sleep(2000);
				system("cls");
			}
			else {
				printf("\n\n\t\t Item não pôde ser inserido!\n");
				Sleep(2000);
				system("cls");
			}
			break;
		}
	}while(op!='S' || op!='s');
	system("cls");
}

int insere_lista(ITEM * LISTA_INICIO, PD conteudo){
	//if(LISTA_VAZIA(LISTA_INICIO)==1) return 0;
	printf("%d",LISTA_VAZIA(LISTA_INICIO));
	LISTA * NOVO= (LISTA*) malloc(sizeof(LISTA));
	
	if(NOVO==NULL) return 0;
	
	NOVO->item=conteudo;
	NOVO->PROXIMO=*LISTA_INICIO;
	*LISTA_INICIO=NOVO;
	return 1;
}

int insere_base(ITEM * LISTA_INICIO){
	LISTA * AUX;
	FILE * fp;
	if(LISTA_INICIO==NULL) return 0;
	fp=fopen("Palavras.txt","a");
	if(fp==NULL) return 0;
	
	AUX=*LISTA_INICIO;
	while(AUX!=NULL){
		fputs(AUX->item.palavra, fp);
		fputs(AUX->item.dica, fp);
		AUX=AUX->PROXIMO;	
	}
	fclose(fp);
	return 1;
}

int exibe_base(){
	
	char palavra[50], dica[100];
	int cont=0;
	
	FILE * fp;
	
	fp= fopen("Palavras.txt","r");
	
	if(fp==NULL) return 0;
	
	while(feof(fp)==0){
		if(feof(fp)!=0) break;
		fgets(palavra, 50, fp);
		if(feof(fp)!=0) break;
		fgets(dica, 100, fp);
		printf("\tPalavra: %s \tDica: %s\n", palavra, dica);
		cont++;	
	}
	printf("\n\n\tQuantidade de itens na base: %d\n\n", cont);
	fclose(fp);
	return 1;
}

int corrige_base(){
	char op2[5];
	char op3;
	int opprincipal;
	PD * AUX;
	AUX= (PD*) malloc(sizeof(PD));
	if(AUX==NULL) return 0;
	
	int cont=0;
	
	FILE * fp;
	
	fp= fopen("Palavras.txt","r");
	if(fp==NULL) return 0;
	
		cont=0;
		system("cls");
		while(feof(fp)==0){
			AUX=(PD*) realloc(AUX, (cont+1) * sizeof(PD));
			
			if(feof(fp)!=0) break;
			AUX=(PD*) realloc(AUX, (cont+1) * sizeof(PD));
			fgets(AUX[cont].palavra, 50, fp);
			if(feof(fp)!=0) break;
			fgets(AUX[cont].dica, 100, fp);
			cont++;	
		}
		fclose(fp);
	do{
		int i;
		do{
			for(i=0;i<cont;i++){
				printf("\n%4d - Palavra: %s \n\tDica: %s", i+1, AUX[i].palavra, AUX[i].dica);	
			}
			printf("\n\n\tQuantidade de itens: %d\n\n", cont);
			printf("\n\tQual palavra deseja alterar? (Selecione pelo número correspondente): ");
			fflush(stdin);
			fgets(op2, 5, stdin);
			opprincipal=atoi(op2);
			if(opprincipal-1>=cont || opprincipal-1<0){
				printf("Item escolhido é inválido!! Digite um item entre %d e %d", 1, cont);
				Sleep(2500);
				system("cls");
			}
		}while(opprincipal-1>=cont || opprincipal-1<0);
		printf("\n\n\t\t Palavra selecionada: \n");
		printf("\t\t ||%s\n", AUX[opprincipal-1].palavra); 
		printf("\t\t ||%s\n", AUX[opprincipal-1].dica); 
		printf("\n\t\t Deseja alterar esta palavra? (S - SIM) (0 - Para voltar ao Menu principal) (Quaquer tecla - NÃO): ");
		fflush(stdin);
		fgets(op2, 5, stdin);
		if(op2[0]=='0'){ printf("\n\n\t\t\|| Operação abortada! ||\n"); return 0;}
		
		if(op2[0]=='S' || op2[0]=='s'){
			printf("\n\n\t\t Digite a nova palavra ");
			fflush(stdin);
			fgets(AUX[opprincipal-1].palavra, 50, stdin);
			printf("\n\n\t\t Digite a dica para a palavra acima(pense bem para não ser uma dica muito clara):");
			fflush(stdin);
			fgets(AUX[opprincipal-1].dica, 100, stdin);
			printf("\n\n\t\t Palavra Digitada: \n");
			printf("\t\t ||%s\n", AUX[opprincipal-1].palavra); 
			printf("\t\t ||%s\n", AUX[opprincipal-1].dica); 
			printf("\n\n\t\t Confirma palavra e dica (S - SIM) (Quaquer tecla - NÃO): ");
			fflush(stdin);
			fgets(op2, 5, stdin);	
		}
		if(op2[0]=='S' || op2[0]=='s'){
			system("cls");
			fp= fopen("Palavras.txt","w");
			for(i=0;i<cont;i++){
				fprintf(fp, "%s", AUX[i].palavra);
				fprintf(fp, "%s", AUX[i].dica);
			}
			fclose(fp);
			return 1;	
		}
	}while(op2[0]!='S' || op2[0]!='s');
}

int apaga_item_base(){
	char op2[5];
	char op3;
	int opprincipal;
	PD * AUX;
	AUX= (PD*) malloc(sizeof(PD));
	if(AUX==NULL) return 0;
	
	int cont=0;
	
	FILE * fp;
	
	fp= fopen("Palavras.txt","r");
	if(fp==NULL) return 0;
	
		cont=0;
		system("cls");
		while(feof(fp)==0){
			AUX=(PD*) realloc(AUX, (cont+1) * sizeof(PD));
			
			if(feof(fp)!=0) break;
			AUX=(PD*) realloc(AUX, (cont+1) * sizeof(PD));
			fgets(AUX[cont].palavra, 50, fp);
			if(feof(fp)!=0) break;
			fgets(AUX[cont].dica, 100, fp);
			cont++;	
		}
		fclose(fp);
	do{
		int i;
		do{
			for(i=0;i<cont;i++){
				printf("\n%4d - Palavra: %s \n\tDica: %s", i+1, AUX[i].palavra, AUX[i].dica);	
			}
			printf("\n\n\tQuantidade de itens: %d\n\n", cont);
			printf("\n\tQual palavra deseja apagar? (Selecione pelo número correspondente): ");
			fflush(stdin);
			fgets(op2, 5, stdin);
			opprincipal=atoi(op2);
			if(opprincipal-1>=cont || opprincipal-1<0){
				printf("Item escolhido é inválido!! Digite um item entre %d e %d", 1, cont);
				Sleep(2500);
				system("cls");
			}
		}while(opprincipal-1>=cont || opprincipal-1<0);
		printf("\n\n\t\t Palavra selecionada: \n");
		printf("\t\t ||%s\n", AUX[opprincipal-1].palavra); 
		printf("\t\t ||%s\n", AUX[opprincipal-1].dica); 
		printf("\n\t\t Deseja apagar esta palavra? (S - SIM) (0 - Para voltar ao Menu principal) (Quaquer tecla - NÃO): ");
		fflush(stdin);
		fgets(op2, 5, stdin);
		if(op2[0]=='0'){ printf("\n\n\t\t\|| Operação abortada! ||\n"); return 0;}
		if(op2[0]=='S' || op2[0]=='s'){
			int aux=opprincipal-1;
			for(i=0; i<cont-1; i++){
				if(i>=aux && i<cont){
					AUX[i]=AUX[i+1];
				}	
			}
		system("cls");
		fp= fopen("Palavras.txt","w");
		for(i=0;i<cont-1;i++){
			fprintf(fp, "%s", AUX[i].palavra);
			fprintf(fp, "%s", AUX[i].dica);
		}
		getch();
		fclose(fp);
		return 1;
		}
	}while(op2[0]!='S' || op2[0]!='s');
}

void apaga_base(){
	FILE * fp;
	fp=fopen("Palavras.txt","w");
	fclose(fp);
	printf("Base apagada!");
}

void menu_admin(ITEM* LISTA_INICIO){
	printf("\t ||--------------------------------------||\n");
	printf("\t ||     CONTROLADOR FORCA! BEM-VINDO     ||\n");
	printf("\t ||--------------------------------------||\n");
	char op2[5];
	char op3;
	int opprincipal;
	do{
		puts("\t   _________________________________  ");	
		puts("\t ||                                 ||");
		puts("\t ||   Selecione a opção desejada:   ||");
		puts("\t ||_________________________________||");
		puts("\n");
		puts("\t1. Adicionar palavras à base:\n");
		puts("\t2. Exibir Lista da base\n");
		puts("\t3. Corrigir palavra na base\n");
		puts("\t4. Apagar palavra na base\n");
		puts("\t5. Apagar lista atual\n");
		puts("\t6. Sair e salvar alterações na base\n");
		printf("\tSelecione opção: ");
		
		fflush(stdin);
		fgets(op2, 5, stdin);
		opprincipal=atoi(op2);
		
		system("cls");
		switch(opprincipal) {
			
			case 1: 
			adiciona_palavras(LISTA_INICIO); break;
			
			case 2: 
			exibe_base(LISTA_INICIO); 
			if(LISTA_VAZIA(LISTA_INICIO)==0)
				printf("\n\n\tHá itens não salvos na base! Confirme gravação dos dados e solicite esta opção novamente!\n");
				getch();
			system("cls");
			break;
			
			case 3: 
			if(corrige_base()==0) printf("\n\t\tErro encontrado\n");
				else printf("\n\t\tDados corrigidos\n");
			Sleep(2000); system("cls"); break;
			
			break;
			
			case 4: 
			if(apaga_item_base()==0) printf("\n\t\tErro encontrado\n");
				else printf("\n\t\tDados apagados!\n");
			Sleep(2000); system("cls"); break;
	
			case 5: 
			printf("\n\n\t\t Você tem certeza disso? ");
			scanf("%c",&op3);
			if(op3=='S' || op3=='s'){
				apaga_base();
				printf("\n\n\t\t Base apagada!");
				Sleep(2000);
			}
			system("cls"); 
			break;
			
			case 6: 
			if(insere_base(LISTA_INICIO)==1){
				printf("Itens cadastrados na base!\n");
				system("cls");
				getch();
			}
				else {
					printf("Itens não cadastrados na base!");
					getch();
					system("cls");
				}
			puts("\n\n\t\t\t FORCA(admin) será encerrado! Até mais!"); break;
			
			default: puts("\n\n\t\tOpção invalida!"); Sleep(1500); system("cls"); break;
		}
		if(opprincipal==6) exit(1);
		system("cls");
	}while(opprincipal!=6);
}


#endif

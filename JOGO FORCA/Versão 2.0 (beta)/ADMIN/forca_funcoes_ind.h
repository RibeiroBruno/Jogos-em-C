#ifndef forca_funcoes_ind_h
#define forca_funcoes_ind_h

//strutura de armazenamento de palavras a partir do arquivo
typedef struct palav_dica {
	char palavra[50]; 
	char dica[100];
	char extra[20];
}PALAVRA;

//modo de busca de palavras a partir do arquivo para inserir no struct
PALAVRA* leitura_arquivo(int *j, PALAVRA* palavra){
	int i=*j;
	
	FILE* fpalavra;
	palavra= (PALAVRA *) malloc(sizeof (PALAVRA));
	fpalavra=fopen(".\\ADMIN\\Palavras.txt","r");
	if(fpalavra==NULL) {
		puts("Erro de execucao: arquivo base nao encontrado ou corrompido nao pode ser aberto!\a\n");
	}
	else 
		while(feof(fpalavra)==0) {
			palavra= (PALAVRA *) realloc(palavra, (i+1) * sizeof (PALAVRA));
			if(palavra==NULL) {
				printf("ERRO! Erro de memória. Programa será encerrado!");
				return 0;
			}
			else {
				strcpy(palavra[i].extra, "nao sorteado");
				fgets(palavra[i].palavra, 50, fpalavra);
				strlwr(palavra[i].palavra);
				if(feof(fpalavra)!=0) break;
				fgets(palavra[i].dica, 100, fpalavra);
				if(feof(fpalavra)!=0) break;
				i++;
			}	
		}
	*j=i;
	fclose(fpalavra);
	return palavra;
}

//limpa palavra deixando espaços em branco
void limpa_palavra1(char palavra[]) {
	int i;
	for(i=0; i<alf; i++){
		palavra[i]=' ';
	}
}

//Modo de escolha da palavra randomicamente a partir do struct palavras
int palavra_random(PALAVRA* palavra, int s, int aleat, int perguntas, char palavraprinc[], char dica[]){
	do{
		srand(time(NULL));
		aleat=rand()%perguntas;
		printf("\n\t\tCarregando...\n");
		Sleep(100);
		system("cls");
	}while(strcmp(palavra[aleat].extra,"Ja sorteado")==0);
	s++;
	strcpy(palavra[aleat].extra,"Ja sorteado");
	strcpy(palavraprinc, palavra[aleat].palavra);
	strcpy(dica, palavra[aleat].dica);
	return s;
}

int palavra_e_tamanho(char palavra[]){
		int tamanho;
		tamanho=strlen(palavra)-1;
		return tamanho;
	}
	
int design_padrao_int(char palavra1[], char palavra2[], char dica[], int tamanho){
		int tamannho_palavra;	
		printf("\n\n\t||---------------------------------------------------------------------------||\n");
		printf("\t|| %s", dica);
		printf("\t||---------------------------------------------------------------------------||\n");
		printf("\n\n\t||-----------------------------||\n");
		printf("\t||  Desafio contem %d letras:  ||\n", tamanho);
		printf("\t||-----------------------------||\n");
		printf("\n\n\t\t");
		puts(palavra1);
		printf("\n");
	
		puts("\n \t Digite uma letra ou arrisque a palavra:");
		printf("\t");
		tamannho_palavra = ler_palavra_e_tamanho(palavra2);
		strlwr(palavra2);
		return tamannho_palavra;
	}
	
int opcao_ind(char *op){
	char aux;
	printf("\t Deseja continuar? (""S"" para sim e ""N"" para nao): ");
	fflush(stdin);
	scanf("%c", &aux);
	*op=aux;
	/*if(op=='S' || op=='s') {
		system("cls");
		jogo_individual();
	}*/
	if(*op!='S' || *op!='s'){
		system("cls");
	}
	return 3;
	
}

#endif

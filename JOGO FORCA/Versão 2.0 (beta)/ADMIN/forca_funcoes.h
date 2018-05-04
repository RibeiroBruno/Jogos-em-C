#ifndef forca_funcoes_h
#define forca_funcoes_h

void nome();
void jogo_individual();
void jogo_modo_dupla();
void leiamejogo_individual();
void leiamejogo_modo_dupla();
int qtd_palavs_arq=0;
const int MAX=50, alf=26;

//limpa palavra para reiniciar a rodada
void limpa_palavra(char palavra2[], char palavra3[]) {
	int i;
	for(i=0; i<MAX; i++){
		palavra2[i]=' ';
		palavra3[i]=' ';
	}
}

//recebe uma palavra como parâmetro para o jogo
void ler_palavra(char palavra[], char palavra2[]){
	fflush(stdin);
	fgets(palavra,  MAX, stdin);
	strcpy(palavra2,strlwr(palavra));
}

int ler_palavra_e_tamanho(char palavra[]){
	int tamanho;
	fflush(stdin);
	fgets(palavra, MAX, stdin);
	tamanho=strlen(palavra)-1;
	return tamanho;
}

//diferencia letras de espaços em branco
int tamanho_de_letras_validas(int tamanho, char palavra[]){
	int auxiliar=0, i;	
		for(i=0; i<tamanho;i++) {
			if(palavra[i]==' ' || palavra[i]=='-'){
				auxiliar++;	
			}
		}
	tamanho=tamanho-auxiliar;
	return tamanho;
}

//palavra auxiliar trabalha junto com palavra parâmetro porém é a exibida durante op jogo composta por _ que são substituidos pelas letras certas.
void cria_palavra_tracejada(char palavra[], char palavra2[], int tamanho){
	int i;
		for(i=0; i<tamanho; i++) {
			if(palavra[i]!=' ')
				palavra2[i]='_';	
			else
			  	palavra2[i]=' ';
			if(palavra[i]=='-')
				palavra2[i]='-';
		}
}

// Padrão exibido em todas rodadas do jogo que solicita letra a digitar

int design_padrao(char palavra1[], char palavra2[], int tamanho){
	int tamannho_palavra;	
	printf("\n\n\t||---------------------------||\n");
	printf("\t|| Desafio contem %d letras: ||\n", tamanho);
	printf("\t||---------------------------||\n");
	printf("\n\n\t\t");
	puts(palavra1);
	printf("\n");

	puts("\n \t Digite uma letra ou arrisque a palavra:");
	printf("\t");
	tamannho_palavra = ler_palavra_e_tamanho(palavra2);
	strlwr(palavra2);
	return tamannho_palavra;
}

//verifica se letra ja foi jogada
int verifica_letra_repetida(int op, int rodada, char tentant[], char tent){
	int i,j;
	for(i=0;i<rodada;i++){
		if(tentant[i]==tent) {
			puts("\t Voce ja jogou esta letra! Tente novamente");
			Sleep(1500);
			system("cls");
			op=1;
			break;
		}
		else op=0;
	}
	return op;	
}

//busca letra dentro da string palavra principal, e se encontrar substitui na mesma posição da palavra auxiliar e calcula acertos por tentativa.
int verifica_letra_na_palavra(char palavra[], char palaux[], char tent, int acerto, int tamanho) {
int i;		
	for(i=0;i<tamanho;i++) {
		if(palavra[i]==tent) {
			acerto++;
			palaux[i]=tent;
			}
		}
	return acerto;
}

//exibe palavra auxiliar com os acertos da jogada e parabeniza o acerto. Sistema aguarda 4 segundos antes de solicitar outra letra
void quantidade_de_acertos(int acerto, int totalacerto, int aux, char palaux[]){
		printf("\t");
		puts(palaux);
		printf("\n");
		printf("\t ||--------------------------------------||\n");
		printf("\t ||  Muito bem, Voce acertou %d letras!  ||\n",acerto);
		printf("\t ||--------------------------------------||\n");
		Sleep(2000);
		system("cls");	
}

//exibe mensagem de letra errada
int quantidade_de_erros(char tenterro[], int erro, char tent){
	tenterro[erro]=tent;
	erro++;
	printf("\t\t ||-------------------------------- || \n");
	puts("\t\t ||         Voce errou!             ||");
	printf("\t\t || Voce errou %d de 6 tentativas!  || \n", erro);
	printf("\t\t ||-------------------------------- || \n");
	Sleep(1500);
	system("cls");
	return erro;
}

//exibe na tela letras erradas que usuário tentou
void exibe_letras_erradas(int erro, char tenterro[]){
	int i;
	printf("\t\t ||----------------------------------|| \n");
	printf("\t\t ||      Voce tentou as letras       ||\n");
	printf("\t\t      ");
	for(i=0;i<erro;i++) {
		printf("%3c",tenterro[i]);
	}
	printf("\n\t\t ||----------------------------------|| \n");
	printf("\n");
}

// compara palavras quando usuário arrisca uma palavra inteira
void verifica_palavra_completa(char palavra[], char palavra2[], int *totalacerto, int aux, int *erro){
	if(strcmp(palavra,palavra2)==0){
		system("cls");
		*totalacerto=aux;
	}
	else {
		system("cls");
		*erro=6;
	}
}

//calcula alinhamento de palavra
void posicao_f(char palavra[]){
	int i, valor;
	valor=(50-strlen(palavra))/2;
	for(i=0;i<valor;i++)
		printf(" ");
}	

void boneco(int erros){
	switch(erros){
		case 0:
		printf("\n\n\t||-----------|  ");
		printf("\n\t||-----------|  ");
		printf("\n\t||              ");
		printf("\n\t||              ");
		printf("\n\t||              ");
		printf("\n\t||              ");
		printf("\n\t||              ");
		printf("\n\t||____________  ");
		break;
		case 1:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||          O| ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||_____________");
		break;
		case 2:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||          O| ");
		printf("\n\t||          || ");
		printf("\n\t||          || ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||_____________");
		break;
		case 3:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||          O| ");
		printf("\n\t||         /|| ");
		printf("\n\t||          || ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||_____________");
		break;
		case 4:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||          O| ");
		printf("\n\t||         /||\\ ");
		printf("\n\t||          || ");
		printf("\n\t||             ");
		printf("\n\t||             ");
		printf("\n\t||_____________");
		break;
		case 5:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||          O| ");
		printf("\n\t||         /||\\ ");
		printf("\n\t||          || ");
		printf("\n\t||          /  ");
		printf("\n\t||         /   ");
		printf("\n\t||_____________");
		break;
	 	case 6:
		printf("\n\n\t||-----------| ");
		printf("\n\t||-----------| ");
		printf("\n\t||     ||      ");
		printf("\n\t||  ___||___   ");
		printf("\n\t||  ___  ___   ");
		printf("\n\t||     ||      ");
		printf("\n\t||     ||      ");
		printf("\n\t||_____||______");
		break;
	}
}

// exibe resultado final do jogo, acerto da palavra ou estouro do limite de erros
void resultado_rodada(int erro, int totalacerto, int aux, char palavra[]){
		if(erro==6) {
		system("cls");
		boneco(erro);
		puts("\n\n\t ||                                                  ||");
		    puts("\t ||          Nao foi dessa vez, Você perdeu!         ||");
		printf("\t ||");
		posicao_f(palavra);
		printf("%s \n",palavra);
	}
	else if(totalacerto==aux){
		system("cls");
		puts("\n\n\t ||                                                  ||");
		    puts("\t ||       Parabens voce acertou a palavra:           ||");
		printf("\t ||");
		posicao_f(palavra);
		printf("%s \n",palavra);
	}
}

//opcoes ao usuario após término da partida
int opcao(){
int op;
	printf("\t Deseja continuar? (""S"" para sim e ""N"" para nao): ");
	fflush(stdin);
	scanf("%c", &op);
	if(op=='S' || op=='s') {
		system("cls");
		jogo_modo_dupla();
	}
	else{
		system("cls");
	}
	return 3;
}
	
#endif

#ifndef forca_MODE_h
#define forca_MODE_h

void leiamejogo_individual(){ // mode de jogo individual
		puts("\t\t Instruções\n\n");
		puts("\t Neste modo o computador escolhe uma palavra aleatoriamente\n");
		puts("\t 1. O jogo termina ao acertar todas as letras da palavra(exceto hifens '-')\n");
		puts("\t 2. Letras repetidas não contam erros nem acertos\n");
		puts("\t 3. O jogo permite até 6 erros, como no modo clássico (cabeça, corpo, dois bracos e duas pernas) e caso atinja o limite de erros se ele encerra\n");
		puts("\t 4. A qualquer momento o usuario pode arriscar a palavra inteira, que deve ser escrita exatamente igual a correta, pois neste caso nao haverá outra chance\n");
		puts("\t\t PRESSIONE QUALQUER TECLA PARA COMEÇAR!");
		getch();
		system("cls");
	}
void leiamejogo_modo_dupla(){ // modo de jogo de dupla
		puts("\t\t Instruções\n\n");
		puts(" Neste modo um usuário digita uma palavra desafio para que o outro jogue:\n");
		puts(" 1. O jogo termina ao acertar todas as letras da palavra(exceto hifens '-')\n");
		puts(" 2. Letras repetidas não contam erros nem acertos\n");
		puts(" 3. O jogo permite até 6 erros, como no modo clássico (cabeça, corpo, dois bracos e duas pernas) e caso atinja o limite de erros se ele encerra\n");
		puts(" 4. A qualquer momento o usuario pode arriscar a palavra inteira, que deve ser escrita exatamente igual a correta, pois neste caso nao havera outra chance\n");
		puts("\t\t PRESSIONE QUALQUER TECLA PARA COMEÇAR!");
		getch();
		system("cls");
	}
 	
void nome() { // abertura do jogo
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

void menu() {
		char op2[5];
		int opprincipal;
		do{
			puts("\t   _________________________________  ");	
			puts("\t ||                                 ||");
			puts("\t ||    Selecione o modo de jogo:    ||");
			puts("\t ||_________________________________||");
			puts("\n");
			puts("\t1. Modo dupla (dinamico) - Neste modo um usuário digita as palavras para o outro jogar.\n");
			puts("\t2. Modo individual - Neste modo você joga com palavras escolhidas randomicamente pelo computador.\n");
			puts("\t3. Sair\n");
			printf("\tSelecione o modo de jogo: ");
			
			fflush(stdin);
			fgets(op2, 5, stdin);
			opprincipal=atoi(op2);
			
			system("cls");
			switch(opprincipal) {
				case 1: leiamejogo_modo_dupla(), jogo_modo_dupla(); break;
				case 2: leiamejogo_individual(), jogo_individual(); break;
				case 3: puts("\n\n\t\t\t FORCA será encerrado! Até mais!"); Sleep(1500); exit(0); break;
				default: puts("\n\n\t\tOpção invalida!"); Sleep(1500); system("cls"); break;
			}
			if(opprincipal==3) break;
		}while(opprincipal!=1 || opprincipal!=2);
	}
	
	
void jogo_modo_dupla(){ // código jogo dupla
	int i, j, n=0, p, tam, tamanpalav,aux=0, totalacerto=0, acerto=0, erro=0;
	char op, tent, tentant[alf], tenterro [alf], tentcomp[MAX], palavra [MAX], palaux[MAX];
	
	//limpa palavra para reiniciar a rodada
	limpa_palavra(palaux, tentcomp);
	
	printf("\n\n\t|| --------------------------------------------------------------------------------- ||\t");
	printf("\n\t|| Digite uma palavra simples ou composta de ate 50 caracteres (e prepare uma dica): ||\t");
	printf("\n\t|| --------------------------------------------------------------------------------- ||\n\n\t\t");
	
	//recebe uma palavra como parâmetro para o jogo
	ler_palavra(palavra,palaux);
	
	//mede tamanho da palavra
	tam=strlen(palavra)-1;
	
	//diferencia letras de espaços em branco	
	aux=tamanho_de_letras_validas(tam, palavra);
	
	system("cls");
	
	//palavra auxiliar trabalha junto com palavra parâmetro porém é a exibida durante op jogo composta por _ que são substituidos pelas letras certas.

	cria_palavra_tracejada(palavra, palaux, tam);
	
	// comando de repetição que mantem o jogon rodando enquanto usuario não acertar a palavra ou uktrapassar o limite de acertos		
	do{
		// Padrão exibido em todas rodadas do jogo que solicita letra a digitar
		do{
			boneco(erro);
			tamanpalav = design_padrao(palaux, tentcomp, aux);
				if(tamanpalav==0){
				puts("\t  Inisra uma letra ou arrisque a palavra completa!");
				Sleep(1500);
				system("cls");
				exibe_letras_erradas(erro, tenterro);
			}
		}while(tamanpalav==0);
		
		// diferencia letra de palavra
		if(tamanpalav==1) {
			tent=tentcomp[0];
			
			//Testa se tentativa ja foi jogada anteriormente.
			p=verifica_letra_repetida(p, n, tentant, tent);
			
			if(p!=1) {
				//Armazena a tentativa em uma lista de tentativas anteriores
				tentant[n]=tent;
				n++;
				//busca letra dentro da string palavra principal, e se encontrar substitui na mesma posição da palavra auxiliar e calcula acertos por tentativa.
				acerto = verifica_letra_na_palavra(palavra, palaux, tent, acerto, tam);
				totalacerto+=acerto;
				
				//exibe palavra auxiliar com os acertos da jogada e parabeniza o acerto. Sistema aguarda 4 segundos antes de solicitar outra letra
				if(acerto>0 && totalacerto<aux)
					quantidade_de_acertos(acerto, totalacerto, aux, palaux);
				
				//caso usuario não acerte sistema informa numero de erros, exibe sistuação atual do jogo, total de erros e palavra atual
				if(acerto==0)
					erro = quantidade_de_erros(tenterro, erro, tent);
			}
			// informa quais palavras usuário já tentou e errou
			if(erro>0 && totalacerto!=aux )
				exibe_letras_erradas(erro, tenterro);
		}
		else if(tamanpalav>1) {
			// compara palavras quando usuário arrisca uma palavra inteira
			verifica_palavra_completa(palavra, tentcomp, &totalacerto, aux, &erro);	
		}
		//zera p e acertos a cada rodada
		acerto=0;
		p=0;
	// jogo continua por 6 arros ou acerto de todas letras da palavra
	}while(erro<6 && totalacerto<aux);
	
	resultado_rodada(erro, totalacerto, aux, palavra);
	
	//opção por continuar ou para o jogo.
	opcao();
}

void jogo_individual() {
	int i, j, rodada=0, tentativa_letra, tamanho_palavra, perguntas, tamanpalav, tamanho_pal_tracejada=0, totalacerto=0, acerto=0, erro=0;
	char op, tent, tentcomp[MAX], tentant[alf], tenterro [alf], palaux[MAX], palavraprinc[MAX], dica[100];
	int qtd_palavras=0, aleat;
	
 	PALAVRA* palavra;
 	
	palavra=leitura_arquivo(&qtd_palavras, palavra);
	perguntas=qtd_palavras;
		
	do{	
		rodada=0; tamanho_pal_tracejada=0; totalacerto=0; acerto=0; erro=0;
		
		//limpa palavra para reiniciar a rodada
		limpa_palavra(palaux, palavraprinc);
		if(qtd_palavs_arq<perguntas) {
			//Modo de escolha da palavra randomicamente a partir do struct palavras
			qtd_palavs_arq=palavra_random(palavra, qtd_palavs_arq, aleat, perguntas, palavraprinc, dica);

			//todas tentativas anteriores igual a "_"
			limpa_palavra(tentant, palaux);
			
			//mede tamanho da palavra
			tamanho_palavra=palavra_e_tamanho(palavraprinc);
			palaux[tamanho_palavra]='\0';
			
			//diferencia letras de espaços em branco
			tamanho_pal_tracejada= tamanho_de_letras_validas(tamanho_palavra,palavraprinc);
			//printf("%d",tamanho_pal_tracejada);
			
			//palavra auxiliar trabalha junto com palavra parâmetro porém é a exibida durante op jogo composta por _ que são substituidos pelas letras certas.	
			cria_palavra_tracejada(palavraprinc, palaux, tamanho_palavra);
			
			// comando de repetição que mantem o jogon rodando enquanto usuario não acertar a palavra ou uktrapassar o limite de acertos		
			do{
				//solicita letra ou palavra completa enquanto usuário inserir valor em branco
				do{
					boneco(erro);
					tamanpalav=design_padrao_int(palaux, tentcomp, dica, tamanho_palavra);
					if(tamanpalav==0){
						puts("\t  Inisra uma letra ou arrisque a palavra completa!");
						Sleep(1500);
						system("cls");
						exibe_letras_erradas(erro, tenterro);
					}
				}while(tamanpalav==0);
				
				//atribue tentativa a uma letra
				if(tamanpalav==1) {
					tent=tentcomp[0];
				
					//Testa se tentativa ja foi jogada anteriormente.
					tentativa_letra = verifica_letra_repetida(tentativa_letra, rodada, tentant, tent);
					
					if(tentativa_letra!=1) {
						//Armazena a tentativa em uma posição de tentativas anteriores
						tentant[rodada]=tent;
						rodada++;
						
						//busca letra dentro da string palavra principal, e se encontrar substitui na mesma posição da palavra auxiliar e calcula acertos por tentativa.
						acerto=verifica_letra_na_palavra(palavraprinc, palaux, tent, acerto, tamanho_palavra);
						totalacerto+=acerto;
							
						//exibe palavra auxiliar com os acertos da jogada e parabeniza o acerto. Sistema aguarda 4 segundos antes de solicitar outra letra
						if(acerto>0 && totalacerto<tamanho_pal_tracejada) {
							quantidade_de_acertos(acerto, totalacerto, tamanho_pal_tracejada, palaux);
						}
						
						//caso usuario não acerte sistema informa numero de erros, exibe sistuação atual do jogo, total de erros e palavra atual
						if(acerto==0) {
							erro=quantidade_de_erros(tenterro, erro, tent);
						}
					}
					// informa quais palavras usuário já tentou e errou
					if(erro>0)
						exibe_letras_erradas(erro, tenterro);		
				}
					//comparar palavra digitada com a palavra do desafio	
				if(tamanpalav>1) {
					verifica_palavra_completa(palavraprinc, tentcomp, &totalacerto, tamanho_pal_tracejada, &erro);
				}
				acerto=0;
				tentativa_letra=0;
					// jogo continua por 6 arros ou acerto de todas letras da palavra
			}while(erro<6 && totalacerto<tamanho_pal_tracejada);
				
			// exibe resultado final do jogo, acerto da palavra ou estouro do limite de erros
			resultado_rodada(erro, totalacerto, tamanho_pal_tracejada, palavraprinc);
			//opção por continuar ou para o jogo.
			opcao_ind(&op);		
		}
		else {
			puts("fORCA Encontrou uma Falha! Precisa ser fechado");
			Sleep(2000);
			break;
		}	
	}while(op=='S' || op=='s');
	op='3';
}

#endif

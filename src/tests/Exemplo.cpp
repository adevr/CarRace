// Biblioteca Consola para TP de POO
// �ltima alteracao: 17/18 - Nov 2018
// J

/*
Versoes e historial
Dez 2010 - Implementa��o: Funcoes da consola + exemplo + coment�rios
Nov 2013 - Pequenas correc��es
Dez 2015 - Coment�rios melhorados
Dez 2016 - Exemplo melhorado.
         - Compatibilidade com mingw automatizada
         - As fun��es passaram a ser est�ticas
Nov 2018 - Pequenos melhoramentos nos coment�rios
*/

// EXEMPLO DE UTILIZA��O

#include <iostream>
#include "./../../lib/Consola/Consola.cpp"

// Isto � uma biblioteca desenvolvida para POO
// N�o � standard e n�o pretende ser
//
// Em �ltima an�lise, isto � tudo o que � preciso saber:
//
// * Para que serve?
//   . Serve para controlar a consola e imprimir
//     caracteres onde se quiser, com as cores que se quiser
//
// * Requisitos: Sistema Windows NT ou superior
//   . Isto usa fun��es do sistema Windows (NT)
//   . Mac -> N�o d�. Esquece isso. Isto precisa mesmo do Windows (Mac � Unix - ver coment�rio seguinte)
//   . Linux -> N�o d�. Esquece isso. Podes usar os ncurses de SO - Pergunta aos professores
//   . "Mas eu tenho um Mac ou Linux e quero mesmo usar isto"
//      -> usar numa m�quina virtual com o windows
//      ou
//      -> Linux ou Mac s�o unixes. Portanto pode usar a
//         biblioteca ncurses (que at� tem mais coisas)
//
// * Isto constitu�do pelo qu�, afinal?
//   . Uma classe, com fun��es est�ticas que s�o o que interesa
//     -> N�o � necess�rio nem suposto criar objectos desta classe
//
// * Quais s�o os ficheiros envolvidos
//   . Um ficheiro .h que tem as declara��es das fun��es 
//   . Um ficheiro .cpp que tem as defini��es das fun��es e classe
//   . Um exemplo (este ficheiro) para ver como se usa
//
// * Como � que se usa
//   . Pegar no consola.h e no consola.h e junt�-los ao projecto
//   . Declarar um objecto Consola e usar as suas fun��es
//   . Basta ter um objecto Consola. N�o s�o precisos mais
//
// * Isto funciona "no netbeans"?
//   . a pergunta � "se funciona com gcc + mingw/cygwin" (netbeans n�o tem nada a ver)
//   . SIM, funciona mas:
//     -> Alguma funcionalidade n�o est� dispon�vel por limitag��o do mingw
//          - redimensinamento de caracteres
//          - desenhos com pixeis (que nem sequer devem usar em POO)
//     -> Execu��o DENTRO do netbeans
//         => Devem configurar o output no netbeans para consola externa
//
// * Configurar o projecto para C++ 2011
//

using namespace std;

// exemplo. serve de explicacao. Ver isto antes de fazer perguntas
// -> o exemplo apresenta menos coisas se for executado em mingw

int main() {
//	Consola c;  // Este objecto d� acesso � funcionalidade da consola. Basta um por programa

	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::gotoxy(10, 10);
	cout << "Este programa serve para demonstrar o que se pode fazer com";
	Consola::gotoxy(10, 11);
	cout << "a biblioteca \"consola\" de POO";
	Consola::gotoxy(10, 13);
	cout << "Convem ver o codigo disto antes de colocar questoes";
	Consola::gotoxy(10, 15);
	cout << "Primeiro passo: redimensionar o ecran";
	Consola::gotoxy(10, 17);
	cout << "Carrega numa tecla para continuar";

	Consola::getch();

	Consola::setTextSize(10, 10);
	Consola::setScreenSize(50, 80);  // linhas colunas. valores grandes pode nao dar
	Consola::setBackgroundColor(Consola::AZUL);  // favor consultar o .h para ver as constantes
	Consola::setTextColor(Consola::AMARELO_CLARO);
	Consola::clrscr();  // reparar no Consola::xxxx - trata-se de fun��es da biblioteca de Consolda (para POO)
	                    // e n�o das fun��es com o mesmo nome da conio.h do antigo turbo-c

	cout << "\n\n\nEsta parte do programa demostra mudanca de tamanho de caracteres\n";
	cout << "\n\n\n   --> So tem efeito no quando compilado com VisualStudio\n";
	cout << "\n\nVai carregando numa tecla\n";
	cout << "\n\n-> 10x10\n";
	Consola::setTextSize(10, 10);
	Consola::getch();

	cout << "\n\n-> 12x12\n";
	Consola::setTextSize(12, 12);
	Consola::getch();

	cout << "\n\n-> 14x14\n";
	cout << "\n\n-> A seguir vou mudar tambem o tamanho do ecra\n";
	Consola::setTextSize(14, 14);
	Consola::getch();

	cout << "\n\n-> 18x15 (ecra: 30x50)\n";
	Consola::setScreenSize(30, 50);  // linhas colunas. valores grandes pode nao dar
	Consola::setTextSize(18, 15);
	Consola::getch();

	Consola::setScreenSize(50, 80);  // linhas colunas. valores grandes pode nao dar
	Consola::setTextSize(12, 12);

	cout << "\n\n\nEsta parte do programa demostra que se pode ler uma tecla sem esperar pelo enter\n";
	cout << "Cada tecla tem um codigo associado.\n";
	cout << "Teclas especiais (Fxx) tem uma sequencia de dois codigos\n";
	cout << "Carrega em teclas. \"Espaco\" para sair\n";

	char tecla;

	while (1) {
		tecla = Consola::getch();  // reparar em Console:: -> getch da biblioteca de POO, n�o � a do conio.h
		cout << (char)tecla << " = " << (int)tecla << "\n";
		if (tecla == ' ')
			break;
	}

	Consola::setTextColor(Consola::BRANCO_CLARO);
	cout << "\nAgora experimenta teclas de direccao.";
	cout << "\nRepara no asterisco no centro do ecran - fa-lo mexer.";
	cout << "\n(quem sabe se nao daria para implementar os snake e pacman)";
	cout << "\n\"escape\" para sair e depois carrega numa tecla";

	int x = 39, y = 24;
	Consola::gotoxy(x, y);
	cout << '*';
	while (1) {
		tecla = Consola::getch();
		if (tecla == Consola::ESCAPE) break;
		if ((tecla != Consola::ESQUERDA) && (tecla != Consola::DIREITA) &&
			(tecla != Consola::CIMA) && (tecla != Consola::BAIXO)) continue;

		//c.setTextColor(c.AZUL);
		Consola::gotoxy(x, y);
		cout << ' ';

		if (tecla == Consola::ESQUERDA) x--;
		if (tecla == Consola::DIREITA) x++;
		if (tecla == Consola::CIMA) y--;
		if (tecla == Consola::BAIXO) y++;
		Consola::gotoxy(x, y);
		cout << '*';
		// TPC: validar os limites da consola
	}
	// RGB -> macro. valores entre 0 e 255 
	Consola::clrscr();
	Consola::drawLine(0, 0, 300, 200, RGB(255, 0, 0));
	Consola::drawCircle(150, 130, 105, RGB(0, 0, 255), 1);
	Consola::drawCircle(200, 130, 75, RGB(50, 255, 50), 0);

	Consola::setTextColor(Consola::AMARELO_CLARO);
	cout << "Desenho de pixels e possivel mas nao e suportado\n";
	cout << "\n\n   -> E so quando compilado no VSudio\n\n";
	cout << "Sao disponibilizadas algumas funcoes para esse efeito";
	cout << "\nmas o resultado nao fica \"memorizado\" na janela\n";
	cout << "(depois em SO2 resove-se isso)\n";
	cout << "\n\nEscolhendo com cuidado as coordenadas pode-se fazer os desenhos coincidir\n";
	cout << "com os limites dos caracteres\n";
	cout << "mas realmente, ** nao se aconselha ** o uso de pixeis na consola de caracteres\n";
	cout << "\nCaracteres com a mesma altura que a largura melhoram a apresentacao\n";
	cout << "\n\ncarrega numa tecla qualquer";
	Consola::getch();

	Consola::setBackgroundColor(Consola::CINZENTO);
	Consola::setTextColor(Consola::BRANCO_CLARO);
	Consola::clrscr();
	Consola::gotoxy(10, 4);
	cout << "Tabela com caracteres.";
	Consola::gotoxy(10, 5);
	cout << "Reparar que muitos podem ser usados para desenhar molduras e afins";
	Consola::gotoxy(10, 6);
	cout << "Outros podem ser como tonalidades";

	for (int i = 0; i< 16; i++) {
		for (int j = 0; j<16; j++) {
			Consola::gotoxy(20 + j * 3, 9 + i * 2);
			cout << (char)(i * 16 + j);
		}
	}

	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(10, 40);
	cout << "\n\tNotar os seguintes\n\n";
	cout << "\t" << (char)176 << ' ' << (char)177 << ' ' << (char)178 << '\n';
	cout << "\n\t";
	cout << (char)179 << ' ' << (char)180 << ' ';
	for (int i = 192; i<198; i++) cout << (char)i << ' ';
	for (int i = 200; i<207; i++) cout << (char)i << ' ';
	cout << "\n\n\tcarrega numa tecla qualquer para ver exemplos";
	Consola::getch();

	Consola::setTextColor(Consola::PRETO);
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);
	Consola::clrscr();

	Consola::gotoxy(20, 20);
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << '\n';
	Consola::gotoxy(20, 21);
	cout << (char)179 << (char)176 << (char)176 << (char)176 << (char)179 << '\n';
	Consola::gotoxy(20, 22);
	cout << (char)179 << (char)176 << (char)176 << (char)176 << (char)179 << '\n';
	Consola::gotoxy(20, 23);
	cout << (char)179 << (char)176 << (char)176 << (char)176 << (char)179 << '\n';
	Consola::gotoxy(20, 24);
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << '\n';


	Consola::gotoxy(25, 20);
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << '\n';
	Consola::gotoxy(25, 21);
	cout << (char)179 << (char)177 << (char)177 << (char)177 << (char)179 << '\n';
	Consola::gotoxy(25, 22);
	cout << (char)179 << (char)177 << (char)177 << (char)177 << (char)179 << '\n';
	Consola::gotoxy(25, 23);
	cout << (char)179 << (char)177 << (char)177 << (char)177 << (char)179 << '\n';
	Consola::gotoxy(25, 24);
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << '\n';


	Consola::gotoxy(30, 20);
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << '\n';
	Consola::gotoxy(30, 21);
	cout << (char)179 << (char)178 << (char)178 << (char)178 << (char)179 << '\n';
	Consola::gotoxy(30, 22);
	cout << (char)179 << (char)178 << (char)178 << (char)178 << (char)179 << '\n';
	Consola::gotoxy(30, 23);
	cout << (char)179 << (char)178 << (char)178 << (char)178 << (char)179 << '\n';
	Consola::gotoxy(30, 24);
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << '\n';

	Consola::gotoxy(35, 20);
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << '\n';
	Consola::gotoxy(35, 21);
	cout << (char)179 << (char)219 << (char)219 << (char)219 << (char)179 << '\n';
	Consola::gotoxy(35, 22);
	cout << (char)179 << (char)219 << (char)219 << (char)219 << (char)179 << '\n';
	Consola::gotoxy(35, 23);
	cout << (char)179 << (char)219 << (char)219 << (char)219 << (char)179 << '\n';
	Consola::gotoxy(35, 24);
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << '\n';

	Consola::setTextColor(Consola::VERDE);
	cout << "\n\n\t\tAgora e uma questao de criatividade";
	Consola::setTextColor(Consola::PRETO);
	cout << "\n\n\t\tCarrega numa tecla qualquer";
	Consola::getch();
	return 0;
}

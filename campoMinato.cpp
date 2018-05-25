#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
//dichiarazione
int prato[10][10];
char pratoVisivo[11][11];
char orizzontale;
char verticale;
int x=0;//coordinata orizzontale matrice int
int y=0;//coordinata verticale matrice int

void SetColor(int forground, int background){
	WORD consoleColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		consoleColor = (forground + (background * 16));
		SetConsoleTextAttribute(hStdOut, consoleColor);
	}
} 

void impostaColore(char prato[][11], int i,int j){
	if(prato[i][j]=='b'&& i>0&& j>0){
	SetColor(4, 0);
			
	}
	
	if(prato[i][j]=='!'&& i>0&& j>0){
	SetColor(10, 0);
	
	}
	
	if(prato[i][j]=='0'&& i>0&& j>0){
	SetColor(3, 0);
	
	}
	if(prato[i][j]=='1'&& i>0&& j>0){
	SetColor(14, 0);
	}
	
	if(prato[i][j]=='2'&& i>0&& j>0){
	SetColor(6, 0);
		
	}
	if(prato[i][j]=='3'&& i>0&& j>0){
	SetColor(12 , 0);
	
	}
	if(prato[i][j]=='x'&& i>0&& j>0){
	SetColor(7, 0);
	}
	/*else{
		SetColor(7,0);
	}*/
}

void piazzamentoBombe() {
	int i=0;//contatore
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			prato[i][j]=0;
		}
	}
	while(i<10){
		x=rand()%10;
		y=rand()%10;
		if(prato[x][y]!=1){
			prato[x][y]=1;
			i=i+1;
		}
	}
}
int inserimentoRisposta(){
	char Y;
	int y=0;
	cin>>Y;
	while(Y!='Y'&&Y!='N'&&Y!='y'&&Y!='n'&&Y!='S'&&Y!='s'&&Y!='Y'/*&&Y!='0'&&Y!='1'&&Y!='2'&&Y!='3'&&Y!='4'&&Y!='5'&&Y!='6'&&Y!='7'&&Y!='8'&&Y!='9'&&Y!='x'&&Y!='X'*/){
	cout<<"non ho capito, reinserisci"<<endl;
	cin>>Y;
	}
	if(Y=='Y'||Y=='y'||Y=='S'||Y=='s'/*||Y=='0'||Y=='1'||Y=='2'||Y=='3'||Y=='4'||Y=='5'||Y=='6'||Y=='7'||Y=='8'||Y=='9'||Y=='x'||Y=='X'*/ ){
		y=1;
	}
	return y;
}
bool esplosione( int prato [][10], int x, int y) {
	return(prato[x][y]==1);
}
int controlloBombe( int prato [][10], int x, int y) {
	int bombe=0;
//	cout<<"controllo bombe"<<endl;
	if(x==0||x==9||y==0||y==9){
		int i=-1;
		int puntoFermoX	=2;
		if(x==0){
			i			=0;
		}
		if(x==9){
			i			=-1;
			puntoFermoX	=1;
		}
		while(i<puntoFermoX){
			int j=-1;
			int puntoFermoY	=2;
			if(y==0){
			j				=0;
			}
			if(y==9){
				j			=-1;
				puntoFermoY	=1;
			}
			while(j<puntoFermoY){
				if(prato[x+i][y+j]==1){
					bombe=bombe+1;
				}
//				cout<<"casella controllata:  "<<x+i<<y+j<<endl;
				j=j+1;			
			}
//			cout<<"i="<<i<<endl;
			i=i+1;
//			Sleep(1000);
		}
	}
	else{
		for(int i=-1;i<2; i++ ){
			for(int j=-1; j<2; j++){
				if(prato[x+i][y+j]==1){
					bombe=bombe+1;				
				}
//			cout<<"casella controllata:  "<<x+i<<y+j<<endl;
//			Sleep(1000);
			}
		}
	}
	return bombe;
}

void riempimentoVisivo( char prato [][11]){

	for(int i=0; i<12; i++) {
		for(int j=0; j<12; j++) {
			prato[i][j]= 'x';
		}
	}
	prato[0][0]='c';
	prato[0][1]='1';
	prato[0][2]='2';
	prato[0][3]='3';
	prato[0][4]='4';
	prato[0][5]='5';
	prato[0][6]='6';
	prato[0][7]='7';
	prato[0][8]='8';
	prato[0][9]='9';
	prato[0][10]='X';
	prato[1][0]='1';
	prato[2][0]='2';
	prato[3][0]='3';
	prato[4][0]='4';
	prato[5][0]='5';
	prato[6][0]='6';
	prato[7][0]='7';
	prato[8][0]='8';
	prato[9][0]='9';
	prato[10][0]='X';
}

void stampaPrato( char prato [][11]) {
system("CLS");
cout<<""<<endl;
cout<<"                                           __             __         "<<endl;
cout<<".----.---.-.--------.-----.-----..--------|__.-----.---.-|  |_.-----."<<endl;
cout<<"|  __|  _  |        |  _  |  _  ||        |  |     |  _  |   _|  _  |"<<endl;
cout<<"|____|___._|__|__|__|   __|_____||__|__|__|__|__|__|___._|____|_____|"<<endl;
cout<<"                    |__|                                             "<<endl;
cout<<""<<endl;
cout<<""<<endl;
	for(int i=0; i<11; i++) {
		for(int j=0; j<10; j++) {
			impostaColore(pratoVisivo,i,j);
			cout<<pratoVisivo[i][j];
			SetColor(7,0);
			cout<<" | ";
		}
		impostaColore(pratoVisivo,i,10);
		cout<<prato[i][10]<<endl;
		SetColor(7,0);
	}

}
char castChar(int bombaInt) {
	char bombaChar;
	if(bombaInt==0)
		bombaChar='0';
	if(bombaInt==1)
		bombaChar='1';
	if(bombaInt==2)
		bombaChar='2';
	if(bombaInt==3)
		bombaChar='3';
	if(bombaInt==3)
		bombaChar='3';
	if(bombaInt==4)
		bombaChar='4';
	if(bombaInt==5)
		bombaChar='5';
	if(bombaInt==6)
		bombaChar='6';
	if(bombaInt==7)
		bombaChar='7';
	if(bombaInt==8)
		bombaChar='8';
	if(bombaInt==9)
		bombaChar='9';
	if(bombaInt==10)
		bombaChar='!';
	return bombaChar;
}
int castInt(char coordinataChar) {
	int coordinataInt;
	if(coordinataChar=='1')
		coordinataInt=1;
	if(coordinataChar=='2')
		coordinataInt=2;
	if(coordinataChar=='3')
		coordinataInt=3;
	if(coordinataChar=='4')
		coordinataInt=4;
	if(coordinataChar=='5')
		coordinataInt=5;
	if(coordinataChar=='6')
		coordinataInt=6;
	if(coordinataChar=='7')
		coordinataInt=7;
	if(coordinataChar=='8')
		coordinataInt=8;
	if(coordinataChar=='9')
		coordinataInt=9;
	if(coordinataChar=='X'||coordinataChar=='x')
		coordinataInt=10;
	return coordinataInt;
}
void controlloVicino(int casellaPrecedente,int prato[][10], char pratoVisivo[][11], int x, int y){
	int bombe=0;
	char bomba;
	cout<<"eccomi";
	if(casellaPrecedente==0){   
		for(int i=-1; i<2; i++){
			for(int j=-1; j<2; j++){
				if((x+i)<0||(x+i)>9||(y+j)<0||(y+j)>9){
					//outside board
				}
				else{
					bombe=controlloBombe(prato, x+i, y+j);
					bomba=castChar(bombe);
					pratoVisivo[x+1+i][y+1+j]=bomba;	
				}
			}
		}
	}
	
}


void inserimentoCoordinate(){
		cout<<"(Inserisci coordinata orizzontale)"<<endl;
		cin>>orizzontale;
		cout<<"(Inserisci coordinata verticale)"<<endl;
		cin>>verticale;
}
void controlloCoordinate(/*char orizzontale, char verticale*/) {
	while(orizzontale!='1'&&orizzontale!='2'&&orizzontale!='3'&&orizzontale!='4'&&orizzontale!='5'&&orizzontale!='6'&&orizzontale!='7'&&orizzontale!='8'&&orizzontale!='9'&&orizzontale!='X'&&orizzontale!='x') {
		cout<<"coordinata orizzontale non valida, reinserire coordinata orizzontale"<<endl;
		cin>>orizzontale;
	}
	while(verticale!='1'&&verticale!='2'&&verticale!='3'&&verticale!='4'&&verticale!='5'&&verticale!='6'&&verticale!='7'&&verticale!='8'&&verticale!='9'&&verticale!='X'&&verticale!='x') {
		cout<<"coordinata verticale non valida, reinserire coordinata verticale"<<endl;
		cin>>verticale;
	}
	x=castInt(orizzontale);
	y=castInt(verticale);
	if(pratoVisivo[x][y]=='!'){
		cout<<"Hai già impostato una bandiera su questa casella, vuoi procedere ugualmente? (Y/N)"<<endl;
		int risposta=0;
		risposta= inserimentoRisposta();
		if(risposta!=1){
			inserimentoCoordinate();
			controlloCoordinate();
		}
	}
}

int vuoiGiocare(){
	char Y;
	int y=0;
	cout<<"Vuoi giocare? (Y/N)"<<endl;
	cin>>Y;
	while(Y!='Y'&&Y!='N'&&Y!='y'&&Y!='n'&&Y!='S'&&Y!='s'){
	cout<<"non ho capito, reinserisci"<<endl;
	cin>>Y;
	}
	if(Y=='Y'||Y=='y'||Y=='S'||Y=='s'){
		y=1;
	}
	return y;
}
void scoproBombe(){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(prato[i][j]==1){
				system("CLS");
				pratoVisivo[i+1][j+1]='b';
				stampaPrato(pratoVisivo);
				cout<<""<<endl;
				cout<<".-----.---.-.--------.-----..-----.--.--.-----.----."<<endl;
				cout<<"|  _  |  _  |        |  -__||  _  |  |  |  -__|   _|"<<endl;
				cout<<"|___  |___._|__|__|__|_____||_____|\\___/|_____|__|  "<<endl;
				cout<<"|_____|                                             "<<endl;
				cout<<""<<endl;
				cout<<""<<endl;
				cout<<""<<endl;			
				Sleep(1000); 
			}
		}
	}
}
int punteggio(char pratoVisivo[][11], int bombe){
	int caselle=0;
	for(int i =1; i<11; i++){
		for(int j=1; j<11; j++){
			if(pratoVisivo[i][j]=='0'||pratoVisivo[i][j]=='1'||pratoVisivo[i][j]=='2'||pratoVisivo[i][j]=='3'||pratoVisivo[i][j]=='4')
			caselle++;
		/*	if(pratoVisivo[i][j]!='x'||pratoVisivo[i][j]!='!'){
				//nothing
			}
			else if(pratoVisivo[i][j]=='1'||pratoVisivo[i][j]=='2'||pratoVisivo[i][j]=='3'){
				caselle++;
			}*/
		}
	}
	cout<<""<<endl<<endl;
	cout<<"Caselle controllate:"<<""<<caselle<<"         "<<"Bandiere piazzate: "<<bombe<<endl;
	cout<<""<<endl<<endl;
	return caselle;
}

int bandiera(int caselleControllate){
	if(caselleControllate>0){
		int risposta=0;
		cout<<""<<endl;
		cout<<"Pensi di sapere dove si trovano delle bombe? (Y/N)"<<endl;
		risposta=inserimentoRisposta();
		if (risposta==1){
			cout<<""<<endl;
			cout<<"Dove si trovano?"<<endl;
			inserimentoCoordinate();
			controlloCoordinate();
		}
		return risposta;
	}
}
int controlloBandiere(/*char prato[][11]*/){
	int bandiera=0;
	for(int i=0; i<11;i ++){
		for(int j=0; j<11; j++){
			if (pratoVisivo[i][j]=='!'){
				bandiera=bandiera+1;
			}
		}
	}
	return bandiera;
}
int controlloFinale(int risposta){
	int bombe=0;
	int perso=0;
	if(risposta==1){
		for(int i=1;i<12;i++){
			for(int j=1; j<12; j++){
				if(pratoVisivo[i][j]=='!' && prato[i-1][j-1]==1)
					bombe=bombe+1;
			}
		}
	if(bombe==10){
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	cout<<"88                     88                88                              "<<endl;
	cout<<"88                     \"\"                \"\"              ,d              "<<endl;
	cout<<"88                                                       88              "<<endl;
	cout<<"88,dPPYba,  ,adPPYYba, 88    8b       d8 88 8b,dPPYba, MM88MMM ,adPPYba, "<<endl;
	cout<<"88P'    \"8a \"\"     `Y8 88    `8b     d8' 88 88P'   `\"8a  88   a8\"     \"8a"<<endl;
	cout<<"88       88 ,adPPPPP88 88     `8b   d8'  88 88       88  88   8b       d8"<<endl;
	cout<<"88       88 88,    ,88 88      `8b,d8'   88 88       88  88,  \"8a,   ,a8\""<<endl;
	cout<<"88       88 `\"8bbdP\"Y8 88        \"8\"     88 88       88  \"Y888 `\"YbbdP\"' "<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	system("PAUSE");
	
	}
	else{
		cout<<""<<endl;
		cout<<""<<endl;
		cout<<""<<endl;
		cout<<"88                     88                                                           "<<endl;
		cout<<"88                     \"\"                                                           "<<endl;
		cout<<"88                                                                                  "<<endl;
		cout<<"88,dPPYba,  ,adPPYYba, 88    8b,dPPYba,   ,adPPYba, 8b,dPPYba, ,adPPYba,  ,adPPYba, "<<endl;
		cout<<"88P'    \"8a \"\"     `Y8 88    88P'    \"8a a8P_____88 88P'   \"Y8 I8[    \"\" a8\"     \"8a"<<endl;
		cout<<"88       88 ,adPPPPP88 88    88       d8 8PP\"\"\"\"\"\"\" 88          `\"Y8ba,  8b       d8"<<endl;
		cout<<"88       88 88,    ,88 88    88b,   ,a8\" \"8b,   ,aa 88         aa    ]8I \"8a,   ,a8\""<<endl;
		cout<<"88       88 `\"8bbdP\"Y8 88    88`YbbdP\"'   `\"Ybbd8\"' 88         `\"YbbdP\"'  `\"YbbdP\"' "<<endl;
		cout<<"                             88                                                     "<<endl;
		cout<<"                             88                                                     "<<endl;
		cout<<""<<endl;
		cout<<""<<endl;

		perso=1;
		system("PAUSE");
	}	 
	scoproBombe();
	system("PAUSE");
	}
	return perso;
}    
           


int main() {
inizio:
cout<<""<<endl;
cout<<"                                           __             __         "<<endl;
cout<<".----.---.-.--------.-----.-----..--------|__.-----.---.-|  |_.-----."<<endl;
cout<<"|  __|  _  |        |  _  |  _  ||        |  |     |  _  |   _|  _  |"<<endl;
cout<<"|____|___._|__|__|__|   __|_____||__|__|__|__|__|__|___._|____|_____|"<<endl;
cout<<"                    |__|                                             "<<endl;
cout<<""<<endl<<endl<<endl;
cout<<"Ripulisci il campo dalle 10 bombe scavando nelle caselle!"<<endl<<endl<<endl;;
int vuoi_giocare=0;
vuoi_giocare=vuoiGiocare();
srand((unsigned) time(NULL));
while(vuoi_giocare==1)
{
	system("CLS");
	int bombe=0;
	int caselleVuote=0;
	int bandiere=0;
	int perso=0;
	int trovatoBombe=0;
	piazzamentoBombe();
	riempimentoVisivo(pratoVisivo);
	while(caselleVuote==90||perso==0) {
		stampaPrato(pratoVisivo);
		caselleVuote=punteggio(pratoVisivo, bandiere);
		if(bandiere==10){
            cout<<"Hai piazzato 10 bandiere! le vuoi controllare? (Y/N)"<<endl;
            int perso=0;
            perso=controlloFinale(inserimentoRisposta());
            system("CLS");
            goto inizio;
    	}
    	else{
		}
		trovatoBombe=bandiera(caselleVuote);
		if(trovatoBombe==1){ // chiede se sa dove ci sono le bombe
			x=castInt(orizzontale);
			y=castInt(verticale);
			pratoVisivo[x][y]='!';
			bandiere=controlloBandiere();
		}
		else{
			system("CLS");
			stampaPrato(pratoVisivo);
			caselleVuote=punteggio(pratoVisivo, bandiere);
			cout<<"Ispeziona le caselle"<<endl;
			inserimentoCoordinate();
			controlloCoordinate(/*orizzontale, verticale*/);
			x=castInt(orizzontale);
			y=castInt(verticale);
			while(pratoVisivo[x][y]!='x'&&pratoVisivo[x][y]!='!'){
				cout<<"coordinate controllate, inseriscine di nuove"<<endl;	
				inserimentoCoordinate();
				x=castInt(orizzontale);
				y=castInt(verticale);
			}
			if(esplosione(prato, x-1, y-1)) {
				perso=perso+1;
				pratoVisivo[x][y]='b'; //numero ideale riconoscibile
				scoproBombe();
			vuoi_giocare=vuoiGiocare();
			} 
			else {
			bombe=controlloBombe( prato, x-1, y-1);	
			controlloVicino(bombe, prato, pratoVisivo, x-1, y-1);		
			pratoVisivo[x][y]=castChar(bombe);
			}
		}
	}
	//vuoi_giocare=vuoiGiocare();
	system("CLS");
	}
system("CLS");
cout<<""<<endl;
cout<<"                                           __             __         "<<endl;
cout<<".----.---.-.--------.-----.-----..--------|__.-----.---.-|  |_.-----."<<endl;
cout<<"|  __|  _  |        |  _  |  _  ||        |  |     |  _  |   _|  _  |"<<endl;
cout<<"|____|___._|__|__|__|   __|_____||__|__|__|__|__|__|___._|____|_____|"<<endl;
cout<<"                    |__|                                             "<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"Developed by"<<endl;
cout<<"_______         _________                             ________         ________________              _________________ "<<endl;
cout<<"___    |_______ ______  /_____________ ______ _       ___  __ \\______ ____  __/___  __/______ ______ ___  /___  /___(_)"<<endl;
cout<<"__  /| |__  __ \\_  __  / __  ___/_  _ \\_  __ `/       __  /_/ /_  __ `/__  /_  __  /_  _  __ `/_  _ \\__  / __  / __  /"<<endl;
cout<<"_  ___ |_  / / // /_/ /  _  /    /  __// /_/ /        _  _, _/ / /_/ / _  __/  _  __/  / /_/ / /  __/_  /  _  /  _  /  "<<endl;
cout<<"/_/  |_|/_/ /_/ \\__,_/   /_/     \\___/ \\__,_/         /_/ |_|  \\__,_/  /_/     /_/     \\__,_/  \\___/ /_/   /_/   /_/   "<<endl;
cout<<""<<endl;
cout<<""<<endl;
system("PAUSE");
return(0);
}



#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<iomanip>

using namespace std;

HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

int Cantidad[3] = {0};
int AnoActual = 2024;
int CantidadTotal = 0;
double PromedioAdmitidos = 0.0;
double PromedioEnEspera = 0.0;
double PromedioNoAdmitidos = 0.0;

//prototipos de funciones y procedimientos
void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void IngresarDatos();
void Estadisticas();
void Graficos();

//procedimientos
void gotoxy(int x ,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void cuadro(int x1, int y1, int x2, int y2){
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}


void IngresarDatos(){
	char sigue;
	int Cedula, AnoNacimiento;
	int Edad;
	int AnoActual = 2024;
	string NombreCompleto;
	int NotaMate, NotaEspanol, NotaCiencias, NotaSociales;
	int NotaAdmision, SumaPromedios, PromedioNotas, PorcentajeCriterio;
	int PorcentajeAdmision, PromedioAdmision;
	
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	do{
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 3);
	cuadro(10,7,120,29);
	cuadro(18,3,45,5);
	
	gotoxy(19,4); printf("***DATOS DEL ESTUDIANTE***"); 
	
	SetConsoleTextAttribute (hConsoleHandle, 5);
	gotoxy(11,9); cout << ("Ingrese Cedula:");
	gotoxy(39,9); cin >> Cedula;
	cin.ignore();
	gotoxy(11,11); cout << ("Ingrese Nombre Completo: ");
	gotoxy(38,11); getline(cin, NombreCompleto);
	gotoxy(11,13); cout << ("Ingrese Ano de Nacimiento: ");
	gotoxy(38,13); cin >> AnoNacimiento;
	gotoxy(11,15); cout << ("Ingrese promedio final de matematicas: ");
	gotoxy(52,15); cin >> NotaMate;
	gotoxy(11,17); cout << ("Ingrese promedio final de espanol:");
	gotoxy(52,17); cin >> NotaEspanol;
	gotoxy(11,19); cout << ("Ingrese promedio final de ciencias: ");
	gotoxy(52,19); cin >> NotaCiencias;
	gotoxy(11,21); cout << ("Ingrese promedio final de sociales: ");
	gotoxy(52,21); cin >> NotaSociales;
	gotoxy(11,23); cout << ("Ingrese nota examen de admision de UTC: ");
	gotoxy(52,23); cin >> NotaAdmision;
	
	Cantidad[3]++;
	Edad = AnoActual - AnoNacimiento;
	SumaPromedios = NotaMate + NotaEspanol + NotaCiencias + NotaSociales;
	PromedioNotas = SumaPromedios / 4;
	PorcentajeCriterio = PromedioNotas * 0.40;
	PorcentajeAdmision = NotaAdmision * 0.60;
	PromedioAdmision = PorcentajeCriterio + PorcentajeAdmision;
	
	if (PromedioAdmision < 75) {
            Cantidad[0]++;
            gotoxy(60,8);  cout << "DATOS DEL ESTUDIANTE REGISTRADO\n";
            gotoxy(60,9);  cout << "Cedula del estudiante: " << Cedula;
            gotoxy(60,10);  cout << "Nombre del Estudiante: " << NombreCompleto;
            gotoxy(60,11);  cout << "Ano Nacimiento del Estudiante: " << AnoNacimiento;
            gotoxy(60,12);  cout << "Edad del Estudiante: " << Edad;
            gotoxy(60,13);  cout << "Las calificaciones de las cuatro materias:";
            gotoxy(60,14);  cout << "Nota Matematica: " << NotaMate;
            gotoxy(60,15);  cout << "Nota Espanol: " << NotaEspanol;
            gotoxy(60,16);  cout << "Nota Ciencias: " << NotaCiencias;
            gotoxy(60,17);  cout << "Nota Sociales: " << NotaSociales;
            gotoxy(60,18);  cout << "Promedio de Colegio: " << PromedioNotas;
            gotoxy(60,19);  cout << "Porcentaje Criterio Colegio: " << PorcentajeCriterio;
            gotoxy(60,20);  cout << "Porcentaje Examen Admision: " << PorcentajeAdmision;
            gotoxy(60,21);  cout << "Promedio Admision: " << PromedioAdmision;
            gotoxy(60,22);  cout << "Calificacion: NO ADMITIDO";
        } else if (PromedioAdmision >= 75 && PromedioAdmision < 85) {
            Cantidad[1]++;
            gotoxy(60,8); cout << "DATOS DEL ESTUDIANTE REGISTRADO\n";
            gotoxy(60,9);  cout << "Cedula del estudiante: " << Cedula;
            gotoxy(60,10);  cout << "Nombre del Estudiante: " << NombreCompleto;
            gotoxy(60,11);  cout << "Ano Nacimiento del Estudiante: " << AnoNacimiento;
            gotoxy(60,12);  cout << "Edad del Estudiante: " << Edad;
            gotoxy(60,13);  cout << "Las calificaciones de las cuatro materias:";
            gotoxy(60,14);  cout << "Nota Matematica: " << NotaMate;
            gotoxy(60,15);  cout << "Nota Espanol: " << NotaEspanol;
            gotoxy(60,16);  cout << "Nota Ciencias: " << NotaCiencias;
            gotoxy(60,17);  cout << "Nota Sociales: " << NotaSociales;
            gotoxy(60,18);  cout << "Promedio de Colegio: " << PromedioNotas;
            gotoxy(60,19);  cout << "Porcentaje Criterio Colegio: " << PorcentajeCriterio;
            gotoxy(60,20);  cout << "Porcentaje Examen Admision: " << PorcentajeAdmision;
            gotoxy(60,21);  cout << "Promedio Admision: " << PromedioAdmision;
            gotoxy(60,22);  cout << "Calificacion: EN ESPERA";
        } else if (PromedioAdmision >= 85) {
            Cantidad[2]++;
            gotoxy(60,8);  cout << "DATOS DEL ESTUDIANTE REGISTRADO\n";
            gotoxy(60,9);  cout << "Cedula del estudiante: " << Cedula;
            gotoxy(60,10);  cout << "Nombre del Estudiante: " << NombreCompleto;
            gotoxy(60,11);  cout << "Ano Nacimiento del Estudiante: " << AnoNacimiento;
            gotoxy(60,12);  cout << "Edad del Estudiante: " << Edad;
            gotoxy(60,13);  cout << "Las calificaciones de las cuatro materias:";
            gotoxy(60,14);  cout << "Nota Matematica: " << NotaMate;
            gotoxy(60,15);  cout << "Nota Espanol: " << NotaEspanol;
            gotoxy(60,16);  cout << "Nota Ciencias: " << NotaCiencias;
            gotoxy(60,17);  cout << "Nota Sociales: " << NotaSociales;
            gotoxy(60,18);  cout << "Promedio de Colegio: " << PromedioNotas;
            gotoxy(60,19);  cout << "Porcentaje Criterio Colegio: " << PorcentajeCriterio;
            gotoxy(60,20);  cout << "Porcentaje Examen Admision: " << PorcentajeAdmision;
            gotoxy(60,21);  cout << "Promedio Admision: " << PromedioAdmision;
            gotoxy(60,22);  cout << "Calificacion: ADMITIDO";
        }

	
	
	do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(90,28); cout << ("Desea ingresar otro usuario? S/N");
			sigue = getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	if (tolower(sigue)=='n') {
		void menu();
		return;
	}	
} while (tolower (sigue) == 's');
}

void Estadisticas(){
	    char sigue;
		system("cls");
		
		cuadro(10,7,100,29);
		cuadro(18,3,57,5);
		
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(19,4); cout << ("***ESTADISTICAS PROCESO DE ADMISION***");
		
		gotoxy(12,9); cout << ("Cantidad de No Admitidos: ") << Cantidad[0];
		gotoxy(12,11); cout << ("Cantidad de En Espera: ") << Cantidad[1];
		gotoxy(12,13); cout << ("Cantidad de Admitidos: ") << Cantidad[2];
		
	    double PorcentajeNoAdmitidos = (static_cast<double>(Cantidad[0]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * 100.0;
        double PorcentajeEnEspera = (static_cast<double>(Cantidad[1]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * 100.0;
        double PorcentajeAdmitidos = (static_cast<double>(Cantidad[2]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * 100.0;
        
        gotoxy(12, 16); cout << "Porcentaje de No Admitidos: " << fixed << setprecision(2) << PorcentajeNoAdmitidos << "%";
        gotoxy(12, 18); cout << "Porcentaje de En Espera: " << fixed << setprecision(2) << PorcentajeEnEspera << "%";
        gotoxy(12, 20); cout << "Porcentaje de Admitidos: " << fixed << setprecision(2) << PorcentajeAdmitidos << "%";


		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(70,28); cout << ("Volver al menu principal S/N");
			sigue = getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	if (tolower(sigue)=='s') {
		void menu();
		return;
	}	 while (tolower (sigue) == 'n');
} 

void Graficos(){
	char sigue;
	system("cls");
    cuadro(10, 7, 120, 29);
    cuadro(18, 3, 57, 5);  

    gotoxy(19, 4); printf("***GRAFICOS DEL PROCESO DE ADMISION***");

    SetConsoleTextAttribute(hConsoleHandle, 5);
    int baseX = 15;
    int baseY = 10;
    int ancho = 50;
    int alto = 4;

    // Graficar No Admitidos
    gotoxy(baseX, baseY - 1); cout << "No Admitidos";
    cuadro(baseX, baseY, baseX + ancho, baseY + alto);
    int longitudNoAdmitidos = static_cast<int>((static_cast<double>(Cantidad[0]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * ancho);
    SetConsoleTextAttribute(hConsoleHandle, 4); 
    for (int i = 0; i < longitudNoAdmitidos; ++i) {
        gotoxy(baseX + i, baseY + alto / 2); cout << "|";
    }

    // Graficar En Espera
    SetConsoleTextAttribute(hConsoleHandle, 5); 
    gotoxy(baseX, baseY + alto + 1); cout << "En Espera";
    cuadro(baseX, baseY + alto + 2, baseX + ancho, baseY + 2 * alto + 2);
    int longitudEnEspera = static_cast<int>((static_cast<double>(Cantidad[1]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * ancho);
    SetConsoleTextAttribute(hConsoleHandle, 5); 
    for (int i = 0; i < longitudEnEspera; ++i) {
        gotoxy(baseX + i, baseY + alto + 2 + alto / 2); cout << "|";
    }
    
    // Graficar Admitidos
    SetConsoleTextAttribute(hConsoleHandle, 2); 
    gotoxy(baseX, baseY + 2 * (alto + 2) + 1); cout << "Admitidos";
    cuadro(baseX, baseY + 2 * (alto + 2) + 2, baseX + ancho, baseY + 3 * alto + 3 + 3);
    int longitudAdmitidos = static_cast<int>((static_cast<double>(Cantidad[2]) / (Cantidad[0] + Cantidad[1] + Cantidad[2])) * ancho);
    SetConsoleTextAttribute(hConsoleHandle, 2); 
    for (int i = 0; i < longitudAdmitidos; ++i) {
        gotoxy(baseX + i, baseY + 2 * (alto + 2) + 2 + alto / 2); cout << "|";
    }

    
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(90,28);printf("Volver al menu principal S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	 while (tolower(sigue)=='n');
}

void menu(){
	char opc,conti;
	
	do{
		
		system("cls");
		cuadro(16,2,67,6); //primer cuadro de arriba hacia abajo
		cuadro(8,8,72,22);//grande
		cuadro(8,23,72,25); //cuadro de abajo opcion es
		cuadro(56,19,68,21); //cuadro pequeño salir

        SetConsoleTextAttribute (hConsoleHandle, 5);
        gotoxy(22,4);printf(" UNIVERSIDAD TECNOLOGICA COSTARRICENSE ");
		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(15,9);printf("----- MENU PRINCIPAL DEL SISTEMA -----");
        SetConsoleTextAttribute (hConsoleHandle, 15);
        gotoxy(15,12);printf("[1]  INGRESAR DATOS DEL ESTUDIANTE");
	    gotoxy(15,14);printf("[2]  ESTADISTICAS");
		gotoxy(15,16);printf("[3]  GRAFICOS");
		gotoxy(57,20);printf("<[4] SALIR>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(18,24);printf("* Su opcion es: ");
		opc=getch();

		switch(opc)
		{
		case '1': IngresarDatos();break;
	    case '2': Estadisticas(); break;
		case '3': Graficos(); break;
		case '4':
			system("cls");
			gotoxy(20,10);printf("Estas seguro Que Deseas Salir del Sistema");
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);printf("Desea Continuar S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
				menu();
			else if (conti=='S' || conti=='s')

		
				break; 
		
		}
			

		}while(opc!='4');

}

int main(int argc, char** argv) {
	menu();
	return 0;
}

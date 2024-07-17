#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

//los arreglos se quitaron ya que al calcular los porcentajes para los graficos daba errores
//double tipocarro[6]={0};//0=sencillo 1=4x4 2=microbuscamion 3=%sencillo 4=%4x4 5=%microbuscamion
//double cantidades[9]={0}; //0=dinerosencillo 1=dinerocuatroporcuatro 2=dineromicrobuscamion 3=lavado 4=completo
						// 5=dinerosololavado 6=dinerocompleto 7=promediolavado 8=promediocompleto  9=porcentajesololavada 10=porcentajecompleto

// Variables globales
double cantidadtotal = 0;		
double sencillo = 0;
double cuatroxcuatro = 0;
double microbuscamion = 0;
double porcentajesencillo = 0;
double porcentajecuatroxcuatro = 0;
double porcentajemicrobuscamion = 0;
int dinerosencillo = 0;
int dinerocuatroporcuatro = 0;
int dineromicrobuscamion = 0;
int lavado = 0;
int completo = 0;
int dinerosololavado = 0;
int dinerocompleto = 0;
int promediolavado = 0;
int promediocompleto = 0;
int porcentajesololavada = 0;
int porcentajecompleto = 0;



						
int numerofactura = 0;
//Void
void menu();
void ingresardatos();
void estadisticassegunvehiculo();
void estadisticassegunlavado();
void graficotipovehiculo();
void graficotipolavado();
void salir();




void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


int main(){
	menu();
return 0;
}

void menu(){
	int opcionmenu;
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 3);
	cuadro(25,5,97,20);
	gotoxy(30,8);cout << "1-Ingresar Datos Vehiculos" << endl;
	gotoxy(30,9);cout << "2-Ver Estadisticas Vehiculos Lavados segun tipo de Vehiculo" << endl;
	gotoxy(30,10);cout << "3-Ver Estadisticas Vehiculos Lavados segun tipo de Lavado" << endl;
	gotoxy(30,11);cout << "4-Ver Grafico Vehiculos Lavados por Tipo de Vehiculo" << endl;
	gotoxy(30,12);cout << "5-Ver Grafico Vehiculos Lavados por Tipo de Lavado" << endl;
	gotoxy(30,13);cout << "6-Salir" << endl;
	
	gotoxy(50,15);cout << "Ingrese su opcion." << endl;
	
	gotoxy(50,16);cin >> opcionmenu;
	
	
	switch(opcionmenu){
		case 1: ingresardatos();
		break;
		
		case 2: estadisticassegunvehiculo();
		break;
		
		case 3: estadisticassegunlavado();
		break;
		case 4: graficotipovehiculo();
		break;
		case 5: graficotipolavado();
		break;
		case 6: salir();
		
		
	default:
    gotoxy(80,17);cout << "Opcion invalida." << endl;
	break;
	}
	
}
	
void ingresardatos() {
    char opcionresp, marca[50], modelo[50];
    int numerodeplaca, tipovehiculo, tipolavado;
    
    
system("cls");

    do {
    	cuadro(23,5,62,25);
		cuadro(65,6,98,19);
        gotoxy(25,8);cout << "Numero de placa" << endl;
        gotoxy(50,8);cin >> numerodeplaca;
        gotoxy(25,9);cout << "Marca del Vehiculo" << endl;
        gotoxy(50,9);cin >> marca;
        gotoxy(25,10);cout << "Modelo del vehiculo" << endl;
        gotoxy(50,10);cin >> modelo;
        gotoxy(25,11);cout << "Tipo de vehiculo" << endl;
        gotoxy(25,12);cout << "1- Sencillo" << endl;
        gotoxy(25,13);cout << "2- 4X4" << endl;
        gotoxy(25,14);cout << "3- Microbus o Camion" << endl;
        gotoxy(25,15);cout << "Ingrese su opcion" << endl;
        gotoxy(50,15);cin >> tipovehiculo;
        numerofactura++;
        cantidadtotal++;
        
        switch (tipovehiculo) {
            case 1:
            	gotoxy(25,16);cout << "Tipo de lavado" << endl;
                gotoxy(25,17);cout << "1- Solo lavado." << endl;
                gotoxy(25,18);cout << "2- Lavado, aspirado y encerado" << endl;
                gotoxy(57,18);cin >> tipolavado;
                sencillo++;
                switch (tipolavado) {
                    case 1:
                    	gotoxy(70,8); cout<< "Factura Lavacar La Bomba."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,15);cout << "Tipo Vehiculo: Sencillo" << endl;
                        gotoxy(70,16);cout << "Tipo lavado: Solo Lavado" << endl;
                        gotoxy(70,17);cout << "Precio a pagar: 3000" << endl;
                        dinerosencillo += 3000;
                        dinerosololavado+= 3000;
                        lavado++;
                        break;

                    case 2:
                    	gotoxy(70,8); cout<< "Factura Lavacar La Bomba."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,15);cout << "Tipo Vehiculo: Sencillo" << endl;
                        gotoxy(70,16);cout << "Tipo lavado: Lavado, aspirado y encerado" << endl;
                        gotoxy(70,17);cout << "Precio a pagar: 5000" << endl;
                        dinerosencillo += 5000;
                        dinerocompleto += 5000;
                        completo++;
                        break;

                    default:
                        gotoxy(80,20);cout << "Opcion invalida." << endl;
                        break;
                }
                break;

            case 2:
                gotoxy(25,16);cout << "Tipo de lavado" << endl;
                gotoxy(25,17);cout << "1- Solo lavado." << endl;
                gotoxy(25,18);cout << "2- Lavado, aspirado y encerado" << endl;
                gotoxy(60,18);cin >> tipolavado;
                cuatroxcuatro++;
                switch (tipolavado) {
                    case 1:
                    	gotoxy(70,8); cout<< "Factura Lavacar La Bomba."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,14);cout << "Tipo Vehiculo: 4X4" << endl;
                        gotoxy(70,15);cout << "Tipo lavado: Solo Lavado" << endl;
                        gotoxy(70,16);cout << "Precio a pagar: 5000" << endl;
                        dinerocuatroporcuatro += 5000;
                        dinerosololavado += 5000;
                        lavado++;
                        break;

                    case 2:
                    	gotoxy(70,8); cout<< "Factura Lavacar La Bomba."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,15);cout << "Tipo Vehiculo: 4X4" << endl;
                        gotoxy(70,16);cout << "Tipo lavado: Lavado, aspirado y encerado" << endl;
                        gotoxy(70,17);cout << "Precio a pagar: 7000" << endl;
                        dinerocuatroporcuatro += 7000;
                        dinerocompleto += 7000;
                        completo++;
                        break;

                    default:
                        gotoxy(80,20);cout << "Opcion invalida." << endl;
                        break;
                }
                break;

            case 3:
                gotoxy(25,16);cout << "Tipo de lavado" << endl;
                gotoxy(25,17);cout << "1- Solo lavado." << endl;
                gotoxy(25,18);cout << "2- Lavado, aspirado y encerado" << endl;
                gotoxy(55,18);cin >> tipolavado;
                microbuscamion++;
                switch (tipolavado) {
                    case 1:
                    	gotoxy(70,8); cout<< "Factura Lavacar La Bomba."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,15);cout << "Tipo Vehiculo: Microbus o Camion" << endl;
                        gotoxy(70,16);cout << "Tipo lavado: Solo Lavado" << endl;
                        gotoxy(70,17);cout << "Precio a pagar: 7000" << endl;
                        dineromicrobuscamion += 7000;
                        dinerosololavado += 7000;
                        lavado++;
                        break;

                    case 2:
                    	gotoxy(70,8);cout<< "Factura Lavacar La Bomba.."<< endl;
                        gotoxy(70,11);cout << "Numero factura: " << numerofactura << endl;
                        gotoxy(70,12);cout << "Numero de placa: " << numerodeplaca << endl;
                        gotoxy(70,13);cout << "Marca: " << marca << endl;
                        gotoxy(70,14);cout << "Modelo: " << modelo << endl;
                        gotoxy(70,15);cout << "Tipo Vehiculo: Microbus o Camion" << endl;
                        gotoxy(70,16);cout << "Tipo lavado: Lavado, aspirado y encerado" << endl;
                        gotoxy(70,17);cout << "Precio a pagar: 12000" << endl;
                        dineromicrobuscamion += 12000;
                        dinerocompleto += 12000;
                        completo++;
                        break;

                    default:
                        gotoxy(80,22);cout << "Opcion invalida." << endl;
                        break;
                }
                break;

            default:
                gotoxy(80,22);cout << "Opcion invalida." << endl;
                break;
        }

        gotoxy(25,22);cout << "Desea ingresar otro vehiculo (s/n): ";
        gotoxy(61,22);cin >> opcionresp;
        system("cls");
    } while (opcionresp == 's' || opcionresp == 'S');

	porcentajesencillo = (sencillo / cantidadtotal) * 100.0;
    porcentajecuatroxcuatro = (cuatroxcuatro / cantidadtotal) * 100.0;
	porcentajemicrobuscamion = (microbuscamion / cantidadtotal) * 100.0;

	promediolavado = lavado > 0 ? dinerosololavado / lavado : 0;
    promediocompleto = completo > 0 ? dinerocompleto / completo : 0;
	
	porcentajesololavada = (lavado / cantidadtotal) * 100.0;
	porcentajecompleto = (completo / cantidadtotal) * 100.0;
	
	menu();
    
}


void estadisticassegunvehiculo(){
	
	char opcionregresar;
	system("cls");
	cuadro(25,5,97,25);
	do{	
	gotoxy(30,8);cout << "Cantidad de vehiculos tipo sencillo:   " << sencillo << endl;
	gotoxy(30,9);cout << "Dinero recaudado de vehiculos tipo sencillo:   " << dinerosencillo << endl;
	gotoxy(30,10);cout << "Cantidad de vehiculos tipo 4X4:   " << cuatroxcuatro << endl;
	gotoxy(30,11);cout << "Dinero recaudado de vehiculos tipo 4X4:   " << dinerocuatroporcuatro << endl;
	gotoxy(30,12);cout << "cantidad de vehiculos tipo Microbus o Camion:   " << microbuscamion << endl;
	gotoxy(30,13);cout << "Dinero recaudado de vehiculos tipo Microbus o Camion:   " << dineromicrobuscamion << endl;
	
	gotoxy(30,22);cout << "Presione 'S' para regresar al menu principal: " << endl;
	gotoxy(80,22);opcionregresar = tolower(getchar());
    } while (opcionregresar != 's');
	
	menu();
	
}

void estadisticassegunlavado(){
	char opcionregresar;
	system("cls");
	cuadro(25,5,105,25);
	do{	
	gotoxy(30,8);cout << "Cantidad de Vehiculos con solo Lavado:  " << lavado << endl;
	gotoxy(30,9);cout << "Cantidad de Dinero por  Vehiculos con solo Lavado:  " << dinerosololavado <<endl;
	gotoxy(30,10);cout << "Promedio Dinero Recaudado de Vehiculos con solo Lavado:  " << promediolavado << endl;
	gotoxy(30,11);cout << "Cantidad de Vehiculos con Lavado, Aspirado y Encerado:  " << completo << endl;
	gotoxy(30,12);cout << "Cantidad de Dinero por  Vehiculos con Lavado, Aspirado y Encerado:  " << dinerocompleto << endl;
	gotoxy(30,13);cout << "Promedio Dinero Recaudado de Vehiculos con Lavado, Aspirado y Encerado:  " << promediocompleto << endl;
		
	gotoxy(30,22);cout << "Presione 'S' para regresar al menu principal: "<< endl;
	gotoxy(80,22);opcionregresar = tolower(getchar());
    } while (opcionregresar != 's');

	menu();
	
}
void graficotipovehiculo(){
		char opcionregresar;
	system("cls");
	cuadro(2,5,117,25);
	cuadro(14,11,115,13);
	cuadro(14,14,115,16);
	cuadro(14,17,115,19);
	do {
		
        gotoxy(30, 8); cout << "Grafico Lavados por Tipo de Vehiculo" << endl;
        
        // Grafico Sencillo
        gotoxy(4, 12); cout << "Sencillo:  ";
        for (int i = 0; i < static_cast<int>(porcentajesencillo); ++i) {
            cout << "|";
        }
        
        // Grafico 4X4
        gotoxy(4, 15); cout << "4X4:       ";
        for (int i = 0; i < static_cast<int>(porcentajecuatroxcuatro); ++i) {
            cout << "|";
        }
        
        // Grafico Microbus o Camion
        gotoxy(4, 18); cout << "Pesados:   ";
        						
        for (int i = 0; i < static_cast<int>(porcentajemicrobuscamion); ++i) {
            cout << "|";
        } 
    	
		
	gotoxy(30,22);cout << "Presione 'S' para regresar al menu principal: " << endl;
	gotoxy(80,22);opcionregresar = tolower(getchar());
    } while (opcionregresar != 's');

    menu();	
}

void graficotipolavado() {
    char opcionregresar;
    system("cls");
    cuadro(2, 5, 117, 25);
    cuadro(14, 11, 115, 13);
    cuadro(14, 15, 115, 17);

    do {
        gotoxy(30, 8); cout << "Grafico Lavados por Tipo de Lavado" << endl;
        cout << endl;

 		gotoxy(4, 12); cout << "Sencillo:  ";
        for (int i = 0; i < static_cast<int>(porcentajesololavada); ++i) {
            cout << "|";
        }
        
        gotoxy(4, 16); cout << "Completo:  ";
        for (int i = 0; i < static_cast<int>(porcentajecompleto); ++i) {
		
        cout << "|";
		}
        gotoxy(30, 22); cout << "Presione 'S' para regresar al menu principal: ";
        gotoxy(80,22);opcionregresar = tolower(getchar());
    } while (opcionregresar != 's');

    menu();
}

void salir() {
    gotoxy(50, 24);cout << "Saliendo del programa..." << std::endl;
    exit(0);  
}


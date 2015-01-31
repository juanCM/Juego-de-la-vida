#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

//lo mas importante, el tablero y las coordenadas
int tablero [50][50];
int x;int y;


//para numeros aleatorios
int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

//void para revisar celdas alrededor
int arround(){
	
	int contador = 0;
		
		//analizar cada celda alrededor y aumentar el contador si esta viva
			//pos 0-0
			if(tablero[x-1][y-1] == 1 )
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 0-1
			if(tablero[x-1][y] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 0-2
			if(tablero[x-1][y+1] == 1	)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			
			//pos 1-0
			if(tablero[x][y-1] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 1-1
			
			//pos 1-2
			if(tablero[x][y+1] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 2-0
			if(tablero[x+1][y-1] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 2-1
			if(tablero[x+1][y] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
			//pos 2-2
			if(tablero[x+1][y+1] == 1)
			{
				contador = contador + 1;
			}
				else
				{
					contador = contador;
				}
		//si hay menos de dos celdas vivas alrededor la celda muere
		if(contador < 2)
		{
			tablero[x][y] = 0;
		}
		//si hay exactamente tres celdas vivas alrededor la celda vive
		else if (contador == 3 && tablero[x][y] == 0 )
		{
			tablero[x][y] = 1;
		}
		//si hay mas de tres celdas vivas alrededor la celda muere
		else if(contador > 3)
		{
			tablero[x][y] = 0;
		}
		//si hay dos celdas vivas alrededor la celda tiene su mismo valor
		else
		{
			tablero[x][y] = tablero[x][y];
		}
	
}


int main() {

    srand(rdtsc());
    
	//asignar celdas vivas o muertas aleatoriamente
	for(x=0;x<10;x++){
		for(y=0;y<35;y++){
			tablero[x][y]= rand()%2 ;
		}
	}
	
		//recorrer el tablero y dibujarlo infinitamente 
	
		while(true){
			system("CLS");
			//for para dibijar el tablero
			for(x = 0; x < 10; x++){
				cout<<"\n"<<endl;
				for(y = 0; y < 35; y++){
					//si hay una celda viva
					if(tablero[x][y] == 1){
						cout <<"\xDB ";	
					}
					//si esta muerta
					else{
						cout<<"\xEE ";	 
					}	
				}	
			}
			//for para analizar las celdas alrededor
			for(x=0;x<10;x++){
				for(y=0;y<35;y++)
				{
					arround();
				}
			}
			//esperar 150 milisegundos y redibujar el tablero con los nuevos valores
			Sleep(150);
		}
		
	
	cin.get();
	return 0;
}
/*
	Name: Juan Jose Carvajal Muñoz
	Copyright: Free
	Author: Juan Jose Carvajal Muñoz
	Date: 30/01/15 14:15
	Description: Proyecto para el "juego de la vida"
	consiste en un tablero que que simula celdas que 
	pueden estar vivas o muertas. Estas celdas viviran
	o moriran dependiendo de las celdas que esten
	a su alrededor
	Libre para su uso y modificacion.
	Email: juan98.cm@gmail.com
*/

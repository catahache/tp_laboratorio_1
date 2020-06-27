#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "book.h"
#include "Controller.h"
#include "menu.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int abmBooks()
{
    char confirm = 'n';
    char exitOut = 'n';
    int flagText = 0;
    int flagBin = 0;


    LinkedList* listaLibros = ll_newLinkedList();
    //if linked list is empty

    do{
    	system("clear");
        switch(menu())
        {
            case 1:
            	if(flagBin != 1 && flagText == 0)//si no fue cargado como binario
            	{
            		if(controller_loadFromText("dataLibros.csv",listaLibros) == 0)
					{
						flagText = 1; //se cargo como texto
					}
            	}
            	else
				{
					printf("El archivo ya fue cargado.\n");
				}
                break;
            case 2:
            	if(flagText != 1 && flagBin == 0)//si no fue cargado como texto
            	{
            		if(!controller_loadFromBinary("dataLibros.bin", listaLibros))
            		{
            			flagBin = 1; //se cargo como binario
            		}
            	}
            	else
            	{
            		printf("El archivo ya fue cargado.\n");
            	}
            	break;
            case 3:
            	if(flagText == 1 || flagBin == 1)
            	{
            		controller_addBook(listaLibros);
            	}
            	else
            	{
            		printf("Error. Aun no se cargo ningun archivo.\n");
            	}
            	break;
            case 4:
            	if(flagText == 1 || flagBin == 1)
				{
					controller_editBook(listaLibros);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 5:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_removeBook(listaLibros);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 6:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_ListBook(listaLibros);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 7:
            	if(flagText == 1 || flagBin == 1)
				{
					controller_sortBook(listaLibros);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
				break;
            case 8:
            	if(flagText == 1 || flagBin == 1)
            	{
            	controller_SecuritySave("dataLibrosSeguridad.bin", listaLibros);
            	}
            	else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 9:
            	if(flagText == 1 || flagBin == 1)
            	{
            		controller_saveAsText("dataLibros.csv", listaLibros);
            	}
            	else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 10:
            	if(flagText == 1 || flagBin == 1)
            	{
            		controller_saveAsBinary("dataLibros.bin", listaLibros);
            	}
            	else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 11:
            	printf("Confirma salir? y/n: ");
            	fpurge(stdin);
            	scanf("%c", &confirm);
            	if(confirm == 'y')
            	{
            		exitOut = 'y';
            		ll_deleteLinkedList(listaLibros);
            	}
            	break;
        }
        pause();

    }while(exitOut == 'n');
    return 0;
}


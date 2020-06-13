#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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



int main()
{
    char confirm = 'n';
    char exitOut = 'n';
    int flagText = 0;
    int flagBin = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	system("clear");
        switch(menu())
        {
            case 1:
            	if(flagBin != 1)//si no fue cargado como binario
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados) > -1)
					{
						flagText = 1; //se cargo como texto
					}
            	}
            	else
				{
					printf("El archivo ya fue cargado como Binario.\n");
				}
                break;
            case 2:
            	if(flagText != 1)//si no fue cargado como texto
            	{
            		if(!controller_loadFromBinary("data.bin", listaEmpleados))
            		{
            			flagBin = 1; //se cargo como binario
            		}

            	}
            	else
            	{
            		printf("El archivo ya fue cargado como Texto.\n");
            	}
            	break;
            case 3:
            	if(flagText == 1 || flagBin == 1)
            	{
            		controller_addEmployee("data.csv", listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Aun no se cargo ningun archivo.\n");
            	}
            	break;
            case 4:
            	if(flagText == 1 || flagBin == 1)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 5:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 6:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Aun no se cargo ningun archivo.\n");
				}
            	break;
            case 7:
            	break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	break;
            case 10:
            	printf("Confirma salir? y/n ");
            	fpurge(stdin);
            	scanf("%c", &confirm);
            	if(confirm == 'y')
            	{
            		exitOut = 'y';
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	break;
        }
        pause();

    }while(exitOut == 'n');
    return 0;
}

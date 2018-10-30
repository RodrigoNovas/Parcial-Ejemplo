#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"
#include "juego.h"

///isEmpty 1 (TODOS LOS LUGARES QUE ESTEN CARGADOS)

///GENERAR ID DEL CLIENTE
static int generarNextId()
{
    static int idCliente=0;
    idCliente++;
    return idCliente;
}
///-------------------------------------------
///INICIALIZAR CLIENTE
void inicializarCliente(eCliente* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=0;
    }
}
///--------------------------------------------
///MENU CLIENTES
int menuClientes(eCliente cliente[], int len)
{
    int opcionCliente=0;
    int flagCliente=0;

    do
    {
        system("cls");
        printf("\n *** MENU CLIENTES *** \n\n");
        printf(" 1. ALTA\n");
        printf(" 2. MODIFICACION\n");
        printf(" 3. BAJA\n");
        printf(" 4. LISTAR\n");
        printf(" 5. SALIR\n\n");
        fflush(stdin);
        scanf("%d",&opcionCliente);

        switch(opcionCliente)
        {
        case 1:
            agregarCliente(cliente, len);
            flagCliente=1;
            break;
        case 2:
            if(flagCliente==0)
            {
                printf(" No hay datos ingresados.\n");
            }
            else
            {
                modificarCliente(cliente, len);
            }
            break;
        case 3:
            if(flagCliente==0)
            {
                printf(" No hay datos ingresados.\n");
            }
            else
            {
                borrarCliente(cliente, len);
            }
            break;
        case 4:
            if(flagCliente==0)
            {
                printf(" No hay datos ingresados.\n");
            }
            else
            {
                ordenarCliente(cliente, len);
            }
            break;
        case 5:
            printf(" Saliendo..\n\n");
            break;
        default:
            printf(" Opcion incorrecta. Ingrese una opcion del 1 al 5.\n\n");
            break;
        }
        system("pause");
    }
    while(opcionCliente!=5);

    return opcionCliente;
}
///------------------------------------------------
///BUSCAR ESPACIO LIBRE EN CLIENTES
int buscarEspacioLibreCliente(eCliente list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
///--------------------------------------------------
///BUSCAR CLIENTE POR ID
int buscarClientrePorID(eCliente list[], int len, int idCliente)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].idCliente==idCliente)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
///---------------------------------------------------
///MOSTRAR CLIENTE
void mostrarCliente(eCliente list)
{
    printf("%d %s %s %c %s\n\n", list.idCliente, list.apellido, list.nombre, list.sexo, list.domicilio);
}
///----------------------------------------------------
///MOSTRAR TODOS LOS CLIENTES
void mostrarClientes(eCliente* list, int len)
{
    system("cls");
    printf("\n CLIENTES \n\n");
    printf("ID\tAPELLIDO\tNOMBRE\tSEXO\tDOMICILIO\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printf("%d\t%s\t\t%s\t%c\t%s\n\n", list[i].idCliente, list[i].apellido, list[i].nombre, list[i].sexo, list[i].domicilio);
        }
    }
}
///-------------------------------------------------------
///ALTA CLIENTE
int agregarCliente(eCliente list[], int len)
{
    eCliente cliente;

    int retorno=-1;
    int found;

    system("cls");
    printf("\n  *** ALTA CLIENTE ***\n\n");

    found = buscarEspacioLibreCliente(list, len);

    if(found == -1)
    {
        printf(" No hay lugar.\n\n");
    }
    else
    {
        getValidString(" Ingrese el apellido: ", cliente.apellido,3,51);
        getValidString(" Ingrese el nombre: ",cliente.nombre,3,51);

        getValidSexo(" Ingrese el sexo: ",&cliente.sexo);

        getValidString(" Ingrese domicilio: ", cliente.domicilio, 3, 51);

        cliente.idCliente=generarNextId();//ID
        cliente.isEmpty=1;
        retorno=0;

        list[found]=cliente;

    }
    return retorno;
}
///----------------------------------------------------------------
///MODIFICAR CLIENTE
int modificarCliente(eCliente list[], int len)
{
    int idCliente;
    int retorno=-1;
    int found;
    char respuesta;
    int opcion=0;

    system("cls");
    printf("\n  *** MODIFICAR CLIENTE ***\n\n");

    getValidInt(" Ingrese el ID del cliente que desea modificar: \n",&idCliente,1,200);

    found=buscarClientrePorID(list,len,idCliente);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarCliente(list[found]);

        getValidString("Desea modificar este clinete? s/n\n",&respuesta,1,1);

        if(respuesta=='s')
        {
            do
            {
                system("cls");
                printf("\n *** MODIFICAIONES CLIENTE *** --\n\n");
                printf(" 1. Apellido \n");
                printf(" 2. Nombre \n");
                printf(" 3. Sexo\n");
                printf(" 4. Domicilio\n");
                printf(" 5. Salir\n\n");
                printf(" Seleccione una opcion: \n\n");
                fflush(stdin);
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getValidString(" Ingrese nuevo apellido: \n",list[found].apellido,3,50);
                    break;
                case 2:
                    getValidString(" Ingrese nuevo nombre: \n",list[found].nombre,3,50);
                    break;
                case 3:
                    getValidSexo(" Ingrese nuevo sexo: \n",&list[found].sexo);
                    break;
                case 4:
                    getValidAlfaNumerico(" Ingrese nuevo domicilio: ", list[found].domicilio, 1, 51);
                    break;
                case 5:
                    printf("\n Modifcaiones realizadas...\n\n");
                    break;
                default:
                    printf(" Opcion incorrecta. Ingrese una opcion del 1 al 5.\n");
                    break;
                }
            }
            while(opcion!=5);
        }
        else
        {
            printf("Modificacion cancelada.\n\n");
        }

    }
    else
    {
        printf("Cliente no encontrado\n");
    }

    return retorno;
}
///------------------------------------------------------------
///BAJA CLIENTE
int borrarCliente(eCliente list[], int len)
{
    int idCliente;
    int found;
    char borrar;

    system("cls");
    printf("  *** BAJA CLIENTE ***\n\n");

    getValidInt(" Ingrese el ID del cliente que desea dar de baja: \n",&idCliente,1,200);

    found=buscarClientrePorID(list,len,idCliente);

    if(found>= 0 && list[found].isEmpty == 1)
    {
        mostrarCliente(list[found]);

        getValidString(" Esta seguro de que quiere dar de baja a este empleado? s/n\n",&borrar,1,1);

        if(borrar=='s')
        {
            list[found].isEmpty=0;
            printf(" Cliente dado de baja.\n\n");
        }
        else
        {
            printf(" Borrado cancelado.\n\n");
        }
    }

    else
    {
        printf(" Cliente no encontrado.\n");
    }
    return -1;
}
///------------------------------------------------------------
///ORDENAR JUEGOS
int ordenarCliente(eCliente* list, int len)
{
    eCliente cliente;

    system("cls");
    printf("  ***  CLIENTES ***\n\n");
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].apellido,list[j].apellido)>0)
            {
                cliente = list[i];
                list[i] = list[j];
                list[j] = cliente;
            }

            if(strcmp(list[i].apellido,list[j].apellido)==0 && strcmp(list[i].nombre,list[j].nombre)>0)
            {
                cliente = list[i];
                list[i] = list[j];
                list[j] = cliente;
            }

        }
    }

    mostrarClientes(list, len);

    return 0;
}
///-------------------------------------------------------
///HARCODEO CLIENTES
void harcodearCliente(eCliente y[])
{
    eCliente x[]=
    {
        {1,"Gimenez","Mabel",'f',"Arieta 5623",1},
        {2,"Perez","Carlos",'f',"Reano 15",1},
        {3,"Gimenez","Gonzalo",'f',"Fajardo 1594",1},
        {4,"Soria","Ana",'f',"Lopez May 152",1},
        {5,"Baez","Brenda",'f',"General Rojo 15",1}
    };

    for(int i=0; i<5; i++)
    {
        y[i] = x[i];
    }

}
///---------------------------------------------------------

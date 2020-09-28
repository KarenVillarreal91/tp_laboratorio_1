#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesEmpleados.h"

int menu()
{
    int op;

    printf(" ----------- Menu -----------\n");      //Imprime el menu, pide y valida la opcion ingresada
    printf(" 1. Alta a un empleado.\n");
    printf(" 2. Modificar a un empleado.\n");
    printf(" 3. Baja a un empleado.\n");
    printf(" 4. Informes.\n");
    printf(" 5. Salir.\n");
    printf(" ----------------------------\n");
    utn_getEntero(&op,0,"\nIngrese la opcion: ","\nError! Opcion invalida.\n\n",1,5);

    system("cls");

    return op;
}

char confirmar()
{
    char resp;
                            //Verifica que el usario desea continuar
    utn_getCaracter(&resp,"\nDesea continuar? s/n: ","\n\nError! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

int crearId(Employee list[],int len)
{
    int i;
    int id = -1;

    for(i = 1; i <= len; i++)       //Recorre y asigna la ID
    {
        if(list[i].isEmpty == VACIO)    //Valida que el espacio este vacio y asigna
        {
            id = i;
            break;
        }
    }

    return id;
}

int pedirId(Employee list[], int tam)
{
    int i;
    int id;
    int retorno = -1;

    printEmployees(list,tam);       //Muestra todos los empleados existentes

    if(utn_getEntero(&id,1,"\n\nIngrese la ID del empleado: ","\n\nError! ID invalido.\n",1,tam) == 0)      //Pide la ID y valida
    {
        for(i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == OCUPADO && list[i].id == id)      //Verifica que en la ID ingresada exista un empleado y asigna
            {
                retorno = id;

                break;
            }
        }
    }

    return retorno;
}

int contarEmpleados(Employee list[],int len)
{
    int cantidadEmpleados = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)       //Recorre el cupo buscando espacios ocupados y los cuenta
        {
            cantidadEmpleados++;
        }
    }

    return cantidadEmpleados;
}

int crearUnEmpleado(Employee list[],int len)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    int retorno = -1;

    id = crearId(list,len);         //Asigna la ID mediante la funcion

    if(id != -1)    //Si la ID se creo correctamente continua
    {
        if(utn_getCadena(name,51,3,"Ingrese el nombre: ","\nError! Nombre invalido.\n") == 0)       //Pide todos los datos, verifica y continua
        {
            if(utn_getCadena(lastName,51,3,"Ingrese el apellido: ","\nError! Apellido invalido.\n") == 0)
            {
                if(utn_getFlotante(&salary,3,"Ingrese el salario: ","\nError! Salario invalido.\n",0,999999999) == 0)
                {
                    if(utn_getEntero(&sector,3,"Ingrese el sector: ","\nError! Sector invalido (1 a 20).\n",1,20) == 0)
                    {
                        retorno = addEmployee(list,len,id,name,lastName,salary,sector);      //Asigna los valores ingresados al empleado nuevo

                        if(retorno == 0)        //Si se asigno correctamente informa y finaliza
                        {
                            printf("\nEmpleado agregado correctamente.\n\n");
                        }
                        else
                        {
                            printf("\nNo se registrara al empleado.\n\n");
                        }
                    }
                    else
                    {
                      printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
                    }
                }
                else
                {
                   printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
                }
            }
            else
            {
               printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
            }
        }
        else
        {
           printf("\nSuperaste la cantidad de intentos, intente de nuevo.\n\n");
        }
    }
    else
    {
        printf("\nYa no hay espacios libres para agregar un nuevo empleado.\n\n");
    }

    return retorno;
}

void salarios(Employee list[],int tam)
{
    float acumuladorSalario = 0;
    int cantidadEmpleados;
    int contadorSuperanElPromedio = 0;
    float promedio;
    int i;

    cantidadEmpleados = contarEmpleados(list,tam);      //Llama a funcion para contar los empleados existentes

    for(i = 0; i < tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)      //Recorre el cupo y suma todos los salarios existentes
        {
            acumuladorSalario += list[i].salary;
        }
    }

    promedio = (float) acumuladorSalario / cantidadEmpleados;       //Calcula el promedio

    for(i = 0; i < tam; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].salary > promedio)     //Recorre el cupo contando cuantos superan el promedio
        {
            contadorSuperanElPromedio++;
        }
    }

    printf("\n\n\n%56s\n","--------------- Informes de Salarios ---------------");
    printf("%16s %14s %22s\n","Suma Total","Promedio","Superan el promedio");
    printf("%57s\n","------------------------------------------------------");

    printf("%6c%.3f %6c%.3f %11d\n\n\n\n",'$',acumuladorSalario,'$',promedio,contadorSuperanElPromedio);    //Imprime los resultados
}

void informesEmpleados(Employee list[],int tam)
{
    int order;
    int retornoOrdenado;
    char respuesta;
                            //Pregunta al usuario como desea ordenar y verifica
    if(utn_getEntero(&order,0,"\nComo desea ordenar el Apellido y Sector?\n 1. Desendente.\n 2. Ascendente.\n\nSu opcion: ","\nError! Opcion invalida.\n\n",1,2) == 0)
    {
        respuesta = confirmar();        //Confirma que esta seguro de ordenar

        if(respuesta == 's')        //Si responde "s" continua
        {
            retornoOrdenado = sortEmployees(list,tam,order);        //Llama a funcion para ordenar usando burbujeo y asigna el retorno

            system("cls");

            if(retornoOrdenado == 0)        //Si se ordeno correctamente continua
            {
                if(order == 1)      //Informa de que modo esta ordenado
                {
                    printf("\n\n%44s\n\n","|Ordenado de forma Desendente|");
                }
                else
                {
                    if(order == 2)
                    {
                        printf("\n\n%44s\n\n","|Ordenado de forma Ascendente|");
                    }
                }

                printEmployees(list,tam);       //Imprime los empleados ordenados

                salarios(list,tam);         //Llama a funcion para calcular y mostrar el informe sobre los salarios
            }
            else
            {
                printf("\nOcurrio un error al ordenar!\n\n");
            }
        }
        else
        {
            printf("\nNo se ordernara ni se mostraran los empleados!\n\n");
        }
    }
}

void modificarEmpleado(Employee list[], int tam, int id)
{
    int indice = findEmployeeById(list,tam,id);         //Busca el indice mediante la ID ingresada por el usuario
    int opcion;
    char respuesta;
    char respuestaSalir;

    Employee empleadoModificado;

    if(indice != -1)        //Si lo encontro correctamente continua
    {
        do
        {
            system("pause");
            system("cls");

            printf("%56s\n","----------------- Datos del empleado -----------------");          //Imprime los datos del empleado seleccionado
            printf("%7s %9s %13s %11s %10s\n","ID","Nombre","Apellido","Salario","Sector");
            printf("%57s\n","------------------------------------------------------");

            printf("%6d     %-10s  %-8s %4c%.3f %6d\n", list[indice].id, list[indice].name, list[indice].lastName,'$', list[indice].salary, list[indice].sector);

            //Pregunta al usuario que desea modificar mediante opciones y verifica
            if(utn_getEntero(&opcion,0,"\nQue desea modificar?\n 1. Nombre.\n 2. Apellido.\n 3. Salario.\n 4. Sector.\n 5. Salir.\n\nSu opcion: ","\n\nError! Opcion invalida.\n\n",1,5) == 0)
            {
                switch(opcion)
                {
                    case 1:  //1. Modifica el nombre
                        if(utn_getCadena(empleadoModificado.name,51,0,"\nIngrese el nombre nuevo: ","\n\nError! Nombre invalido.\n\n") == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo nombre
                            {
                                strcpy(list[indice].name,empleadoModificado.name);

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 2:  //2. Modifica el apellido
                        if(utn_getCadena(empleadoModificado.lastName,51,0,"\nIngrese el apellido nuevo: ","\n\nError! Apellido invalido.\n\n") == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo apellido
                            {
                                strcpy(list[indice].lastName,empleadoModificado.lastName);

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 3:  //3. Modifica el salario
                        if(utn_getFlotante(&empleadoModificado.salary,0,"\nIngrese el salario nuevo: ","\n\nError! Salario invalido.\n\n",0,999999999) == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo salario
                            {
                                list[indice].salary = empleadoModificado.salary;

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }

                    break;

                    case 4:  //4. Modifica el sector
                        if(utn_getEntero(&empleadoModificado.sector,0,"\nIngrese el sector nuevo: ","\n\nError! Sector invalido.\n\n",1,20) == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo sector
                            {
                                list[indice].sector = empleadoModificado.sector;

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 5:  //5. Salida, confirma que desea salir
                        respuestaSalir = confirmar();
                    break;
                }
            }

        }while(respuestaSalir != 's');      //Mientras el usuario no elija la opcion 5 y confirme repite
    }
    else
    {
        printf("\nNo se encontro a un empleado con esa ID.\n\n");
    }
}

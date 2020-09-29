#ifndef FUNCIONESEMPLEADOS_H_INCLUDED
#define FUNCIONESEMPLEADOS_H_INCLUDED
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 1000
#define VACIO 0
#define OCUPADO 1
#endif // FUNCIONESEMPLEADOS_H_INCLUDED

/** \brief Menu principal del programa.
 *
 * \return int Retorna la opcion elegida por el usuario.
 *
 */
int menu();

/** \brief Pregunta al usuario si quiere continuar con lo que esta haciendo.
 *
 * \return char Retorna la respuesta (s o n).
 *
 */
char confirmar();

/** \brief Busca un espacio libre entre el cupo de empleados.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param len int   Cupo total de empleados.
 * \return int   Retorna el indice del espacio libre si lo encuentra.
 *
 */
int buscarLibre(Employee list[],int len);

/** \brief Pregunta al usuario todo lo necesario para crear el empleado.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param len int   Cupo total de empleados.
 * \param idParam int   ID creado.
 * \return int Retorna 0 si se creo correctamente, -1 si no se creo el empleado.
 *
 */
int crearUnEmpleado(Employee list[],int len,int idParam);

/** \brief Calcula y muestra el promedio, total y cuantos superan el promedio de salario.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param tam int   Cupo total de empleados.
 * \return void
 *
 */
void salarios(Employee list[],int tam);

/** \brief Pregunta al usuario como desea ordenar
 * y muestra la lista de empleados ordenado junto a la funcion "salarios".
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param tam int   Cupo total de empleados.
 * \return void
 *
 */
void informesEmpleados(Employee list[],int tam);

/** \brief Muestra un menu para que el usuario elija que desea modificar
 * (nombre, apellido, salario, sector) mientras muestra al empleado seleccionado.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param tam int   Cupo total de empleados.
 * \param id int   ID del empleado que el usuario selecciono para modificar.
 * \return void
 *
 */
void modificarEmpleado(Employee list[], int tam, int id);

/** \brief Pide el ID de un empleado al usuario y verifica.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param tam int   Cupo total de empleados.
 * \param maximoId int  El maximo ID creado.
 * \return int   Retorna el ID que el usario selecciono.
 *
 */
int pedirId(Employee list[], int tam, int maximoId);

/** \brief Cuenta los empleados existentes.
 *
 * \param list[] Employee   Lista de todos los empleados.
 * \param len int   Cupo total de empleados.
 * \return int   Retorna el numero de empleados ya contados.
 *
 */
int contarEmpleados(Employee list[],int len);

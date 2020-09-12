#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#endif // MENU_H_INCLUDED

/** \brief Muestra un menu con opciones
 *
 * \param x int Operando A ingresado
 * \param y int Operando B ingresado
 * \param flagUno int Bandera para mostrar el operando A ingresado
 * \param flagDos int Bandera para mostrar el operando B ingresado
 * \return int Opcion ingresada (respuesta del usuario)
 *
 */
int menu(int x, int y, int flagUno, int flagDos);

/** \brief Permite ingresar los operandos
 *
 * \param x int Operando A o B ingresado
 * \return int Operando A o B ingresado por el usuario
 *
 */
int pedirOperando(int x);

/** \brief Muestra un error en el caso de no ingresar operandos
 *
 * \return void
 *
 */
void errorOperando();

/** \brief Muestra los resultados de las operaciones realizadas
 *
 * \param x int Operando A ingresado
 * \param y int Operando B ingresado
 * \param suma int Resultado de la suma
 * \param resta int Resultado de la resta
 * \param division float Resultado de la division
 * \param multiplicacion int Resultado de la multiplicacion
 * \param factorialUno int Resultado del factorial de operando A
 * \param factorialDos int Resultado del factorial de operando B
 * \return void
 *
 */
void mostrarResultados(int x,int y, int suma, int resta, float division, int multiplicacion, int factorialUno, int factorialDos);

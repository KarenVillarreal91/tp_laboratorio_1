#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);


int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);

int getCadena(char* pAux,int limite);


int getInt(int* pAux);


int isInt(char *pAux);


int isFloat(char* pAux);


int getFloat(float*pAux);



int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);



int isLetras(char*pAux);



int validateFlag(int* flag, char* msgError);


int validarMail(char *pAux);


int utn_getEmail(char* pString, int limite, int reintentos, char* msg, char* msgError);

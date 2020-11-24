#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL)
    {
        if(nodeIndex > -1 && nodeIndex < ll_len(this))
        {
            pNode = this->pFirstNode;   //Obtiene el primer nodo de la lista

            while(nodeIndex > 0)   //Mientras el indice sea mayor a 0 continua
            {
                pNode = pNode->pNextNode;   //Obtiene el siguiente nodo al actual nodo
                nodeIndex--;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    //Node* next;
    Node* nuevoNodo;

    if(this != NULL)
    {
        if(nodeIndex > -1 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*) malloc(sizeof(Node));   //Reserva espacio para el nodo nuevo

            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement; //El elemento del nodo nuevo toma el valor del elemento pasado por parametro
                nuevoNodo->pNextNode = NULL;    //El siguiente nodo toma el valor NULL

                if(nodeIndex == 0)  //Si no hay elementos en la lista actual
                {
                    nuevoNodo->pNextNode = this->pFirstNode;   //El siguiente nodo del nuevo nodo toma el valor del primer nodo de la lista
                    this->pFirstNode = nuevoNodo;   //El primer nodo de la lista toma el valor del nuevo nodo
                }
                else
                {
                    prev = getNode(this,nodeIndex - 1); //Se obtiene el nodo del anterior indice al pasado por parametro

                    nuevoNodo->pNextNode = prev->pNextNode; //El siguiente nodo del nuevo nodo toma el valor del siguiente nodo del anterior nodo
                    prev->pNextNode = nuevoNodo;    //El siguiento nodo del anterior nodo toma el valor del nuevo nodo
                }

                this->size++;   //Aumenta el tamaño de la lista
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = ll_len(this);
    //Node* actual;

    if(this != NULL)
    {
        returnAux = addNode(this,indice,pElement);
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL)
    {
        auxNode = getNode(this,index);  //Obtiene el nodo del indice pasado por parametro

        if(auxNode != NULL)
        {
            returnAux = auxNode->pElement;  //Retorno toma el valor del elemento del nodo obtenido
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    //int cantidad;

    actual = getNode(this,index);   //Obtiene el nodo actual del indice pasado por parametro

    if(actual != NULL)
    {
        actual->pElement = pElement;    //El elemento del nodo actual toma el valor del elemento pasado por parametro
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* prev;
    //int indice = 0;

    actual = getNode(this,index);   //Obtiene el nodo del indice pasado por parametro

    if(actual != NULL)
    {
        if(index == 0)  //Si el indice es 0 borra el nodo actual y el nodo siguiente toma su lugar
        {
           this->pFirstNode = actual->pNextNode;
           this->size--;
           free(actual);
           returnAux = 0;
        }
        else
        {
            prev = getNode(this,index - 1); //Obtiene el nodo del indice anterior al pasado por parametro

            if(prev != NULL)   //Verifica nulidad, borra nodo actual y el nodo anterior toma su lugar
            {
                prev->pNextNode = actual->pNextNode;
                this->size--;
                free(actual);
                returnAux = 0;
            }
        }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        do
        {
            returnAux = ll_remove(this,0);   //Elimina el elemento en el indice actual de la lista

        }while(ll_len(this) != 0);
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this) == 0) //Elimina todos los elementos de la lista
        {
            free(this); //Elimina la lista
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len = ll_len(this);
    Node* nodo;

    //if(len != -1)
    if(!ll_isEmpty(this)) //Verifica que la lista no esta vacia
    {
        for(i = 0; i < len; i++)    //Recorre la lista
        {
            nodo = getNode(this,i); //Obtiene el nodo del indice actual

            if(nodo != NULL && nodo->pElement == pElement)  //Verifica nulidad y busca el elemento del nodo que sea el igual
            {                                               // al elemento pasado como parametro
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;

    returnAux = addNode(this,index,pElement);

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodo;

    nodo = getNode(this,index); //Obtiene el nodo del indice pasado por parametro

    if(nodo != NULL)
    {
        returnAux = nodo->pElement; //Retorno toma el valor del elemento del nodo

        if(ll_remove(this,index) != 0)  //Elimina el elemento del indice pasado por parametro y verifica si pudo eliminarlo
        {
            returnAux = NULL;   //Si no pudo retorno toma el valor NULL
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;

        if(ll_indexOf(this,pElement) != -1) //Busca el indice del elemento, si lo encuentra continua
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len = ll_len(this2);    //Obtiene el tamaño de la segunda lista
    void* pElement;

    if(this != NULL && this2 != NULL)   //Verifica nulidad
    {
        returnAux = 1;

        for(i = 0; i < len; i++)    //Recorre la segunda lista
        {
            pElement = ll_get(this2,i);     //Obtiene los elementos de la segunda lista por cada indice

            if(ll_contains(this,pElement) == 0)     //Verifica si el elemento actual de la segunda lista esta en la primera lista
            {
                returnAux = 0;
                //break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int len = ll_len(this);
    void* pElement;

    if(this != NULL && from > -1 && from < len && to >= from && to <= len)
    {
        cloneArray = ll_newLinkedList();    //Crea una nueva lista

        if(cloneArray != NULL)
        {
            for(i = from; i < to; i++)  //Recorre la lista de from a to
            {
                pElement = ll_get(this,i);  //Obtiene el elemento del indice actual
                ll_add(cloneArray,pElement);    //Agrega el elemento a la nueva lista
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);

    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,len);    //Crea una nueva lista desde el indice 0 al ultimo de la lista
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int len = ll_len(this);
    int i;
    int j;
    void* pElementI;
    void* pElementJ;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)   //Verifica nulidad y que el orden sea 0 o 1 solamente
    {
        for(i = 0; i < len-1; i++)  //Burbujeo
        {
            for(j = i+1; j < len; j++)
            {
                pElementI = ll_get(this,i); //Obtiene el elemento actual en el indice I
                pElementJ = ll_get(this,j); //Obtiene el elemento actual en el indice J

                //Si elem. de I es mayor que elem. de J y el orden es ascendente O elem. de I menor que elem. de J y el orden es descendente
                if((pFunc(pElementI,pElementJ) > 0 && order == 1) || (pFunc(pElementI,pElementJ) < 0 && order == 0))
                {
                    pAux = pElementI;
                    ll_set(this,i,pElementJ);
                    ll_set(this,j,pAux);

                    returnAux = 0;
                }
            }
        }
    }

    return returnAux;
}


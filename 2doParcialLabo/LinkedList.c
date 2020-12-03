#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Competitor.h"

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
    int len;

    len=ll_len(this);
    if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
    {
        pNode=this->pFirstNode; // primer vagon
        while(nodeIndex>0)
        {
            pNode=pNode->pNextNode; // estructura anidada, hacia donde apunta
            nodeIndex--; // de esta manera no declaro otra var.
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
    Node* prev=NULL;
    Node* nuevoNodo=NULL;
    int len;
    int i=0;

    // Busco tamaño lista
    len=ll_len(this);
    // Si es nulo, sumo 1 espacio
    if(len==NULL)
    {
        len++;
    }

    // el nodeIndex tenia que ser <=len porque sin el "=" no entra en el caso del ultimo elemento
    // el espacio se crea una vez ingresado al if
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
        // Creo espacio en memoria para nuevo nodo
        nuevoNodo=(Node*) malloc(sizeof(Node));

        // si el primer nodo es nulo, entonces el nuevo nodo es el primero
        if(this->pFirstNode==NULL)
        {
            this->pFirstNode=nuevoNodo;
            nuevoNodo->pNextNode=NULL;
        }
        else if(nodeIndex==0)
        {
            // busco el actual 0 y lo guardo
            prev=getNode(this,0);
            // establezco como nuevo 0 al nuevo
            this->pFirstNode=nuevoNodo;
            // establezco como siguiente del nuevo al otro
            nuevoNodo->pNextNode=prev;
        }
        // sino 1)obtengo previo, 2)paso el siguiente nodo del previo al siguiente del nuevo nodo y cargo como siguiente nodo del previo al nuevo.
        else
        {
            prev=getNode(this,nodeIndex-1);
            nuevoNodo->pNextNode=prev->pNextNode;
            prev->pNextNode=nuevoNodo;
        }

        nuevoNodo->pElement=pElement; //contenido
        this->size++;
        returnAux=0;
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
    int indice = 0;

    if (this!=NULL)
    {
        // saco indice con el tamaño del ll
        indice=this->size;
        // si se hizo bien, devuelve el 0 para el retorno
        returnAux=addNode(this,indice,pElement);
    }

    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    int len;

    len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
        pNode=getNode(this,index);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
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
    Node* actual=NULL;
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        // traigo nodo
        actual=getNode(this,index);
        // guardo modoficacion
        actual->pElement=pElement;
        returnAux=0;
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
    int len;

    len=ll_len(this);

    if(this!=NULL && index>=0 && index<len)
    {
        if(index==0)
        {
            actual=getNode(this,index); // actual con getNode
            this->pFirstNode=actual->pNextNode;// establezco el siguiente nodo como primero para no romper cadena
        }
        else
        {
            // traigo previo y actual con getNode
            actual=getNode(this,index);
            prev=getNode(this,index-1);
            // paso el proximo nodo del actual al previo para no romper cadena
            prev->pNextNode=actual->pNextNode;
        }
        // libero y disminuyo tamaño
        free(actual);
        this->size--;
        returnAux=0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                       ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            ll_remove(this,0);
        }
        returnAux=0;
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
    int itsOk;

    if(this!=NULL)
    {
        // elimino elementos
        itsOk=ll_clear(this);
        // si se elimino, chau lista
        if (itsOk==0)
        {
            free(this);
            returnAux=0;
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
    Node* nodo;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            nodo=getNode(this,i);
            // si pElement coincide con puntero, guardo index
            if(pElement==nodo->pElement)
            {
                returnAux=i;
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
    int returnAux = -1;
    int len;

    len=ll_len(this);
    if(this!=NULL && index>=0 && index<=len)
    {
        returnAux=addNode(this,index,pElement);
    }

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
    int len;
    int itsOk=-1;

    len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
        // traigo nodo
        nodo=getNode(this,index);
        // guardo pElement en return aux
        returnAux=nodo->pElement;
        // elimino
        itsOk=ll_remove(this,index);
        // si no elimino, cambio return aux a null
        if (itsOk!=0)
        {
            returnAux=NULL;
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
    int index;
    int isEmpty;

    isEmpty=ll_isEmpty(this);

    if(isEmpty!=-1)
    {
        index=ll_indexOf(this,pElement);
        returnAux=0;
        if(index!=-1)
        {
            returnAux=1;
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
    Node* nodo;
    int len;
    int len2;
    int contains;

    if(this!=NULL && this2!=NULL)
    {
        len=ll_len(this);
        len2=ll_len(this);
        if(len!=NULL && len2!=NULL)
        {
            returnAux=1;
            for(i=0;i<len;i++)
            {
                // traigo nodo y si contains devuelve 0 rompo iteracion
                nodo=getNode(this2,i);
                contains=ll_contains(this,nodo->pElement);

                if(contains==0)
                {
                    returnAux=0;
                    break;
                }
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
    void* pElement;
    int len;

    len=ll_len(this);

    if (this!=NULL && from>=0 && from<len && to>from && to<=len)
    {
        // creo lista
        cloneArray=ll_newLinkedList();
        if (cloneArray!=NULL)
        {
            for(i=from;i<to;i++)
            {
                // traigo contenido
                pElement=ll_get(this,i);
                // agrego nodos a la sublista
                addNode(cloneArray,i,pElement);
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
    int len;

    len=ll_len(this);

    if (this!=NULL)
    {
        cloneArray=ll_subList(this,0,len);
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
    void* pAux2;
    int i;
    int j;
    int len;

    if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
        len=ll_len(this);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                // getters
                pAux=ll_get(this,i);
                pAux2=ll_get(this,j);
                switch(order)
                {
                    case 0:
                        // orden descendente
                        if(pFunc(pAux,pAux2)<0)
                        {
                            // swaps
                            ll_set(this,j,pAux);
                            ll_set(this,i,pAux2);
                        }

                    break;
                    case 1:
                        // orden ascendente
                        if(pFunc(pAux,pAux2)>0)
                        {
                            // swaps
                            ll_set(this,j,pAux);
                            ll_set(this,i,pAux2);
                        }
                    break;
                }
            }
        }
        returnAux=0;
    }

    return returnAux;
}

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    void* pElement;
    int i;
    int len;
    int returnValue=-1;

    if(this!=NULL && pFunc!=NULL)
    {
        len=ll_len(this);

        for(i=0;i<len;i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement)==0)
            {
                returnValue=0;
            }
        }
    }

    return returnValue;
}

int ll_count(LinkedList* this, int (*fn)(void*))
{
    void* pElement;
    int i;
    int len;
    int acumulador=0;

    if(this!=NULL && fn!= NULL)
    {
        len=ll_len(this);
        for(i=0; i<len; i++)
        {
            pElement=ll_get(this, i);
            acumulador+=(fn(pElement));
        }
    }
    return acumulador;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void*,float))
{
    int i;
    int len;
    float promedio;
    void* pElement;
    LinkedList* aux;

    aux=ll_newLinkedList();

    if(this!=NULL && fn!= NULL)
    {
        len=ll_len(this);
        // traigo mejor promedio
        promedio=competitor_getMejorPromedio(this);
        for(i=0; i<len; i++)
        {
            pElement=ll_get(this, i);

            //la funcion criterio es buscar si es mejor promedio y busco confirmacion de si es o no
            if(fn(pElement,promedio)==1)
            {
                ll_add(aux,pElement);
            }
        }
    }
    return aux;

}

LinkedList* ll_filterv2(LinkedList* this, int (*fn)(void*, int))
{
    int i;
    int len;
    int  puntaje;
    void* pElement;
    LinkedList* aux; // lista resultante(con mejores puntajes)
    LinkedList* aux2; // lista clonada, para no modificar original

    aux=ll_newLinkedList();

    if(this!=NULL && fn!= NULL)
    {
        aux2=ll_clone(this);
        len=ll_len(aux2);
        puntaje=competitor_getMejoresPuntajes(aux2);
        for(i=0; i<len; i++)
        {
            pElement=ll_get(aux2, i);
            if(fn(pElement,puntaje)==1)
            {
                ll_pop(aux2,i); // elimino de la clonada al mejor promedio
                ll_add(aux,pElement); // agrego el mejor promedio al resultante
            }
        }
        len=ll_len(aux2);
        puntaje=competitor_getMejoresPuntajes(aux2); //recalculo 2
        for(i=0; i<len; i++)
        {
            pElement=ll_get(aux2, i);
            if(fn(pElement,puntaje)==1)
            {
                ll_pop(aux2,i);
                ll_add(aux,pElement);
            }
        }
        len=ll_len(aux2);
        puntaje=competitor_getMejoresPuntajes(aux2); //recalculo3
        for(i=0; i<len; i++)
        {
            pElement=ll_get(aux2, i);
            if(fn(pElement,puntaje)==1)
            {
                ll_pop(aux2,i);
                ll_add(aux,pElement);
            }
        }
    }

    return aux;
}

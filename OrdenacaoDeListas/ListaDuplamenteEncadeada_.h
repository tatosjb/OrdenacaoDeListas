/*
struct MusicaDE{
    string Nome;
    string Autor;
};
*/

template<typename T>
struct ElementoDE{

    T dado;
    ElementoDE<T> * proximo;
    ElementoDE<T> * anterior;
};

template<typename T>
struct ListaDE{

    ElementoDE<T> * inicio;
    ElementoDE<T> * final;
    int qtd;
};

template<typename T>
void IniciaListaDE(ListaDE<T> &L){

    L.inicio = NULL;
    L.final  = NULL;
    L.qtd    = 0;
}

template<typename T>
bool InsereInicioDE(ListaDE<T> &L, T NovoDado){

    ElementoDE<T> * novo = new ElementoDE<T>;
    novo->dado    = NovoDado;
    novo->anterior= NULL;
    novo->proximo = L.inicio;
    if(novo==NULL){
        return false;
    }
    if(L.qtd==0){
        L.final  = novo;
    }else{
        L.inicio->anterior = novo;
    }
    L.inicio = novo;
    L.qtd ++;
    return true;
}

template<typename T>
bool RemoveFinalDE(ListaDE<T> &L){

    if(L.final==NULL){
        return false;
    }

    ElementoDE<T> * aux;
    L.aux = L.final;
    L.final = L.final->anterior;
    L.final->proximo = NULL;
    delete aux;
    return true;
}

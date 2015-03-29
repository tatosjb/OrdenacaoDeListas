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
bool InsereFinalDE(ListaDE<T> &L, T NovoDado){

    if(L.qtd==0){
        return InsereInicioDE(L,NovoDado);
    }

    ElementoDE<T> * novo = new ElementoDE<T>;
    novo   ->dado     = NovoDado;
    novo   ->proximo  = NULL;
    novo   ->anterior  = L.final;
    L.final->proximo= novo;
    L.qtd++;

    return true;
}

template<typename T>
bool InserePosicaoDE(ListaDE<T> &L, T NovoDado, int Posicao){

    if(Posicao>L.qtd || Posicao<0){
        return false;
    }
    if(L.qtd==0){
        return InsereInicioDE(L,NovoDado);
    }
    if(Posicao==L.qtd){
        return InsereFinalDE(L,NovoDado);
    }

    ElementoDE<T> * novo = new ElementoDE<T>;
    novo->dado = NovoDado;
    ElementoDE<T> * aux;
    aux = L.inicio;

    for(int i=0; i=Posicao-1;i++){
        aux = aux->proximo;
    }

    novo->anterior  = aux;
    novo->proximo   = aux->proximo;
    aux ->proximo->anterior =   novo;
    aux ->proximo   = novo;
    L.qtd++;

    return true;
}

template<typename T>
bool RemoveInicioDE(ListaDE<T> &L){

    if(L.qtd==0){
        return false;
    }

    if(L.qtd==1){
        delete L.inicio;
        L.inicio=NULL;
        L.final =NULL;
    }else{
        L.inicio=L.inicio->proximo;
        delete L.inicio->anterior;
        L.inicio->anterior=NULL;
    }

    L.qtd--;
    return true;
}

template<typename T>
bool RemoveFinalDE(ListaDE<T> &L){

    if(L.qtd==0){
        return false;
    }

    ElementoDE<T> * aux;
    aux = L.final;
    L.final = L.final->anterior;

    if(L.qtd>1){
        L.final->proximo = NULL;
    }else{
        L.inicio=NULL;
    }

    delete aux;
    L.qtd--;

    return true;
}

template<typename T>
bool RemovePosicaoDE(ListaDE<T> &L, int Posicao){

    if(Posicao>=L.qtd || L.qtd==0 || Posicao<0){
        return false;
    }
    if(L.qtd==1){
        return RemoveInicioDE(L);
    }
    if(Posicao=L.qtd-1){
        return RemoveFinalDE(L);
    }

    ElementoDE<T> * aux = L.inicio;

    for(int i=0; i=Posicao;i++){
        aux = aux->proximo;
    }

    aux->anterior->proximo=aux->proximo;
    aux->proximo->anterior=aux->anterior;
    delete aux;
    L.qtd--;

    return true;
}

template<typename T>
void bubblesortDE (ListaDE<T> &L){

    ElementoDE<T> * aux1=L.inicio;
    ElementoDE<T> * aux2=L.inicio;

    for(int i=0; i<L.qtd-1; i++){
        for(int j=0; j<L.qtd; j++){
            if(aux1->dado > aux1->proximo->dado){
                swap(aux1->dado , aux1->proximo->dado);
            }
            aux1=aux1.proximo;
        }
        aux2=aux2.proximo;
		aux1=aux2.proximo;
    }
}

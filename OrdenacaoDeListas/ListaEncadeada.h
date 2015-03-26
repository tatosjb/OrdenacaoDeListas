
struct Musica{
    string Nome;
    string Autor;
};

struct Elemento{
    Musica dado;
    Elemento * proximo;
};

struct ListaEnc{
    Elemento * inicio;
    int qtd;
};

void IniciaListaE (ListaEnc &L){
    L.inicio = NULL;
    L.qtd=0;
}

bool InsereInicioLE (ListaEnc &L, Musica d){

    Elemento * novo = new Elemento;
    novo->dado = d;

    if(L.qtd==0){
        novo->proximo=NULL;
    }else{
        novo->proximo = L.inicio;
    }

    L.inicio = novo;
    L.qtd++;
    return true;
}

bool InsereFinalLE (ListaEnc &LE, Musica d){

    Elemento * novo = new Elemento;
    novo->dado = d;
    novo->proximo = NULL;

    if(LE.qtd==0){
        return InsereInicioLE(LE, d);
    }else{
        Elemento * aux = LE.inicio;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo=novo;
        LE.qtd++;
        return true;
    }
}

bool InserePosicaoLE (ListaEnc &LE, Musica d, int Posicao){

    if(Posicao>LE.qtd || Posicao<0){
        return false;
    }
    if(LE.qtd==0){
        return InsereInicioLE(LE, d);
    }
    if(Posicao==LE.qtd){
        return InsereFinalLE(LE, d);
    }

    Elemento * aux = LE.inicio;
    Elemento * novo = new Elemento;
    novo->dado = d;

    for(int i=0; i<Posicao-1;i++){
        aux = aux->proximo;
    }

    novo->proximo=aux->proximo;
    aux->proximo=novo;
    LE.qtd++;

    return true;
}


bool RemoveInicioLE(ListaEnc &LE){

    if(LE.qtd==0){
        return false;
    }else{
        Elemento * aux = LE.inicio;
        LE.inicio=LE.inicio->proximo;
        delete aux;
        LE.qtd--;
        return true;
    }
}

bool RemoveFinalLE(ListaEnc &LE){

    if(LE.qtd==0){
        return false;
    }else{
        Elemento * aux = LE.inicio;
        for(int i=0; i<LE.qtd-2;i++){
            aux = aux->proximo;
        }
        delete aux->proximo;
        aux->proximo=NULL;
    }
    LE.qtd--;
    return true;
}

void ImprimeListaEnc (ListaEnc &LE){

    Elemento * aux = LE.inicio;
    while(aux!=NULL){
        cout<<aux->dado.Nome<<"\n";
        aux = aux->proximo;
    }
}

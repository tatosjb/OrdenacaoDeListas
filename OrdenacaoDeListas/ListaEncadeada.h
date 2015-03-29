
struct Musica{
	int Sequencia;
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

bool RemovePosicaoLE(ListaEnc &LE, int Posicao){
    if(Posicao>=LE.qtd || LE.qtd==0 || Posicao<0){
        return false;
    }
    if(LE.qtd==1){
        return RemoveInicioLE(LE);
    }
    if(Posicao=LE.qtd-1){
        return RemoveFinalLE(LE);
    }

	Elemento * aux = LE.inicio;
	Elemento * aux2= LE.inicio;;

	for(int i=0; i<Posicao-1; i++){
		aux=aux->proximo; // Auxiliar fica no elemento anterior ao que será deletado.
		aux2=aux2->proximo;
	}

	aux=aux->proximo;
	aux2->proximo=aux->proximo;
	delete aux;
	LE.qtd--;

	return true;
}

void BubblesortLE(ListaEnc &LE){

	Elemento * aux1 = LE.inicio;
	Elemento * aux2 = LE.inicio;

	for(int i=0; i<LE.qtd-1; i++){
		for(int j=0; j<LE.qtd; j++){
			if(aux1->dado.Sequencia > aux1->proximo->dado.Sequencia){
				swap(aux1->dado , aux1->proximo->dado);
			}
			aux1=aux1->proximo;
		}
		aux2=aux2->proximo;
		aux1=aux2->proximo;
	}
}


const int MAX=10;

struct Contato{
    string nome;
    string telefone;
};

struct ListaEst{
    Contato elementos[MAX];
    int qtd;
};

void IniciaLista(ListaEst &L){
    L.qtd=0;
}

bool InsereFinal(ListaEst &L, Contato C){
    if(L.qtd<MAX){
        L.elementos[L.qtd]=C;
        L.qtd++;
        return true;
    }else{
        return false;
    }
}

bool InsereInicio(ListaEst &L, Contato C){
    if(L.qtd<MAX){
        for(int i=L.qtd;i>0;i--){
            L.elementos[L.qtd]=L.elementos[L.qtd-1];
        }
        L.elementos[0]=C;
        L.qtd++;
        return true;
    }else{
        return false;
    }
}

bool InserePosicao(ListaEst &L, Contato C, int Pos){
    if(L.qtd<MAX && Pos>=0 && Pos<=L.qtd){
        for(int i=L.qtd;i>Pos;i--){
            L.elementos[L.qtd]=L.elementos[L.qtd-1];
        }
        L.elementos[Pos]=C;
        L.qtd++;
        return true;
    }
    return false;
}

void ImprimeLista(ListaEst L){
    for(int i=0; i<L.qtd; i++){
        cout<<"\n---"<<"\n"<<L.elementos[i].nome<<"\n"<<L.elementos[i].telefone<<"\n";
    }
}

bool RemoveFinal(ListaEst &L){
    if(L.qtd>0){
        L.qtd --;
        return true;
    }
    return false;
}

bool RemoveInicio(ListaEst &L){
    if(L.qtd>0){
        for(int i=0;i<L.qtd-1;i++){
            L.elementos[i]=L.elementos[i+1];
        }
        L.qtd--;
        return true;
    }else{
        return false;
    }
}

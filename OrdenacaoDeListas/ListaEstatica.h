
const int MAX=10;

struct Contato{
    string nome;
    string telefone;
	int id;
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

bool RemoveFinal(ListaEst &L){
    if(L.qtd>0){
        L.qtd --;
        return true;
    }
    return false;
}

bool RemovePosicao(ListaEst &L, int Posicao){
	if(L.qtd==0 || Posicao<0 || Posicao>=L.qtd){
		return false;
	}
    if(L.qtd==1){
        return RemoveInicio(L);
    }
    if(Posicao=L.qtd-1){
        return RemoveFinal(L);
    }else{
		if(L.qtd>0){
			for(int i=Posicao;i<L.qtd-1;i++){
				L.elementos[i]=L.elementos[i+1];
			}
			L.qtd--;
		}
	}
}

void Bubblesort(ListaEst &L){
	for(int i=0; i<L.qtd-1; i++){
		for(int j=0; j<L.qtd; j++){
			if(L.elementos[i].id > L.elementos[j].id){
				swap(L.elementos[i], L.elementos[j]);
			}
		}
	}
}
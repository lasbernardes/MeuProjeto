#include<iostream>
#include<vector>

using namespace std;

template <typename T>

class ListaG{

    public:
    vector<T> vecT;
    
    void adicionar(T _elemento){
        vecT.push_back(_elemento);
    }

    void remover(T _elemento){
        int i=0;
        for(auto it=vecT.begin();it!=vecT.end();it++, i++){
            if(*it == _elemento){
                vecT.erase(vecT.begin()+i);
                break;
            }
        }
    }

    void listar(){
        
        for(auto &e:vecT){
            cout<<e<<endl;
        }
    }


};
int main(){

    ListaG<int> listaGInt;

    listaGInt.adicionar(4);
    listaGInt.adicionar(16);
    listaGInt.adicionar(9);
    listaGInt.adicionar(12);
    listaGInt.listar();
    listaGInt.remover(9);
    listaGInt.listar();

    return 0;
}
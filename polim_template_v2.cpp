#include<iostream>
#include<vector>

using namespace std;

class Pessoa{
public:
    string nome;
    friend ostream& operator<< (ostream& o, Pessoa const& p){
        o<<p.nome;
        return o;
    }

};

template <typename T>

class ListaG{

    private:
    vector<T> *vecT;
    
    public:

    ListaG(){
        this->vecT = new vector<T>();

    }

    void adicionar(T _elemento){
        this->vecT->push_back(_elemento);
    }

    T remover(){
        T temp;
        temp = this->vecT->back();
        this->vecT->pop_back();
        return temp;
        /*nt i=0;
        for(auto it=vecT.begin();it!=vecT.end();it++, i++){
            if(*it == _elemento){
                vecT.erase(vecT.begin()+i);
                break;
            }
        }*/
    }
    T remover1(T _elemento){
        
        int i=0;
        for(auto it=this->vecT->begin();it!=this->vecT->end();it++, i++){
            if(*it == _elemento){
                this->vecT->erase(this->vecT->begin()+i);
                break;
            }
        }
    }


    void listar(){
        
        for(auto el:*this->vecT){
            cout << el << endl;
        }
    }


};
int main(){

    ListaG<int> *listaGInt =new ListaG<int>();

    listaGInt->adicionar(4);
    listaGInt->adicionar(16);
    listaGInt->adicionar(9);
    listaGInt->adicionar(12);
    listaGInt->listar();
    listaGInt->remover1(9);
    listaGInt->listar();

    ListaG<Pessoa> *listaGPessoa = new ListaG<Pessoa>();
    Pessoa p;
    p.nome="Nicole";
    listaGPessoa->adicionar(p);
    p.nome="Helder";
    listaGPessoa->adicionar(p);
    p.nome="Gilvana";
    listaGPessoa->adicionar(p);
    listaGPessoa->listar();
    listaGPessoa->remover1("Helder");
    return 0;
}
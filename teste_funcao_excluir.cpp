#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include "teste.h"

//PRIMEIRA PARTE

using namespace std;

struct Cliente {

    string cpf;
    string nome;
    string dtnascimento;
    string cnh;
};

struct Veiculo{

    string renavam;
    string placadoveiculo;
    string data_hora_retirada;  // prevista
    string data_hora_entrega;   // prevista
    string loja_retirada;

};

void preencheVetorVeiculos(vector<Veiculo>& vect){

    vect.push_back(Veiculo());
    vect[0].renavam="12121212";
    vect[0].placadoveiculo="AAA1A11";
    vect[0].data_hora_retirada="19/09/2023 12:00";
    vect[0].data_hora_entrega="21/09/2023 12:01";
    vect[0].loja_retirada="aeroporto";
    
    vect.push_back(Veiculo());
    vect[1].renavam="23232323";
    vect[1].placadoveiculo="BBB2B22";
    vect[1].data_hora_retirada="22/10/2023 13:00";
    vect[1].data_hora_entrega="25/10/2023 15:01";
    vect[1].loja_retirada="centro";
    
    vect.push_back(Veiculo());
    vect[2].renavam="34343434";
    vect[2].placadoveiculo="CCC3C33";
    vect[2].data_hora_retirada="23/10/2023 15:00";
    vect[2].data_hora_entrega="24/10/2023 11:01";
    vect[2].loja_retirada="sapetinga";

    vect.push_back(Veiculo());
    vect[3].renavam="45454545";
    vect[3].placadoveiculo="DDD4D44";
    vect[3].data_hora_retirada="23/09/2023 16:00";
    vect[3].data_hora_entrega="22/10/2023 17:01";
    vect[3].loja_retirada="sapetinga";

    
}
void ExcluirVeiculo(vector<Veiculo>& veiculos) {
    string placa;
    int cont=0;
    bool flag=false;

    cout << "Digite a placa do veículo que deseja excluir: "<<endl;
    cin >> placa;

    for(auto& veic: veiculos){
        if(placa == veic.placadoveiculo){
           //cout<<"encontrou"<<endl;
           flag=true;
           break;
        }
        cont++;
    }
    
    //auto it = remove_if(veiculos.begin(), veiculos.end(), [&placa](const Veiculo& v) { return v.placadoveiculo == placa; });
    //cout << *it <<endl;
   //it = veiculos.begin();
    //cout <<"it begin: "<< it << endl;
    if(flag){
        veiculos.erase(veiculos.begin()+ cont); 
        cout<<"Veículo excluido!"<<endl<<endl;
    } else {
        cout << "Veículo não encontrado. " << endl;
    }

    /*if (it != veiculos.end()) {
        veiculos.erase(it, veiculos.end());
        cout << "Veículo excluído com sucesso. " << endl;
    } else {
        cout << "Veículo não encontrado. " << endl;
    }
    */
}

void ListarVeiculos(vector<Veiculo>& veiculos) {
    for (const auto& veiculo : veiculos) {
        cout<<"\tRenavam                : " << veiculo.renavam << endl;
        cout<<"\tPlaca                  : " << veiculo.placadoveiculo <<endl;
        cout<<"\tData e hora de retirada: " << veiculo.data_hora_retirada <<endl;
        cout<<"\tData e hora de entrega : " << veiculo.data_hora_entrega << endl;
        cout<<"\tLoja de retirada       : " << veiculo.loja_retirada<<endl<<endl;
    }
}

int main(){

    vector<Veiculo> vect;
    preencheVetorVeiculos(vect);
    ListarVeiculos(vect);
    ExcluirVeiculo(vect);
    ListarVeiculos(vect);


    return 0;
}
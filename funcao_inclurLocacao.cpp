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

struct Locacao {
    Cliente* cliente;
    Veiculo* veiculo;
    string realizada;  // 's' para Sim ou 'n' para não
    string dataHoraRetiradaReal;
    string dataHoraEntregaReal;
    //Ocorrencia ocorrencia; // Atributo do tipo Ocorrencia QUARTA PARTE
};

void preencheVetorCliente(vector<Cliente>& vect){

    vect.push_back(Cliente());
    vect[0].cpf="123.456.789-10";
    vect[0].nome="Adriano";
    vect[0].dtnascimento="12/10/1982";
    vect[0].cnh="11111111";
    
    vect.push_back(Cliente());
    vect[1].cpf="234.567.890-12";
    vect[1].nome="Bruna";
    vect[1].dtnascimento="22/11/1983";
    vect[1].cnh="22222222";

    vect.push_back(Cliente());
    vect[2].cpf="345.678.901-23";
    vect[2].nome="Carla Maria";
    vect[2].dtnascimento="02/02/1972";
    vect[2].cnh="33333333";
    return;
}

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



void incluirLocacao(vector<Locacao>& locacoes, vector<Cliente>& clientes, vector<Veiculo>& veiculos) {
    string cnh, placa;
    Veiculo* ptrVeiculo;
    Cliente* ptrCliente;
    Locacao locacao;
    bool flag=false;

    cout << "Digite o CNH do cliente: "<<endl;
    cin >> cnh;

    // Verificar se o cliente existe:
    //Cliente* clientePtr = nullptr;
            //cout<<">>>"<<&clientes[0].cnh<<endl;

    for (auto& c : clientes) {
        cout<<">> "<<&c.cnh<<endl;
        if (c.cnh == cnh) {
            cout<<">>>"<<&clientes[0].cnh<<endl;

            //clientePtr = &c;
            ptrCliente=&c;
            cout<<"ptrCli: " << ptrCliente<<endl;
            flag=true;
            break;
        }
    }

    //if (!clientePtr) {
    if(!flag){
        cout << "Cliente não encontrado." <<endl;
        return;
    }
    locacao.cliente = ptrCliente;

    cout << "Digite a placa do veículo: ";
    cin >> placa;
    flag=false;
    // Verificar se o veículo existe:
    //Veiculo* veiculoPtr = nullptr;
    for (auto& v : veiculos) {
        if (v.placadoveiculo == placa) {
            ptrVeiculo = &v;
            flag=true;
            break;
        }
    }

    //if (!veiculoPtr) {
    if(!flag){
        cout << "Veículo não encontrado!\n";
        return;
    }
    locacao.veiculo = ptrVeiculo;
  
    cout << "Digite a data e hora real de retirada (DD/MM/AAAA HH:MM): ";
    cin.ignore();
    getline(cin, locacao.dataHoraRetiradaReal);
    cout << "Digite a data e hora real de entrega (DD/MM/AAAA HH:MM): ";
    //cin.ignore();
    getline(cin, locacao.dataHoraEntregaReal);
    cout << "Retirada já realizada? (S/N): ";
    cin >> locacao.realizada;
    
    locacoes.push_back(locacao);
    cout << "Locação registrada com sucesso!\n";
}

void ListarCliente(vector<Cliente>& veccli){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
        cout<<"Nome\tCPF\tData Nasc.\tCNH"<<endl;
                for(const auto& it:veccli){
                    cout<<it.nome<<"\t";
                    cout<<it.cpf<<"\t";
                    cout<<it.dtnascimento<<"\t";
                    cout<<it.cnh<<endl<<endl;
                }
    return;
}

void ListarVeiculos(vector<Veiculo>& veiculos) {
    cout<<"Renavam\tPlaca\tD.H.Retirada\tD.H.Entrega\tLoja Retirada"<<endl;
    for (const auto& veiculo : veiculos) {
        cout<< veiculo.renavam <<"\t";
        cout<< veiculo.placadoveiculo<<"\t";
        cout<< veiculo.data_hora_retirada<<"\t";
        cout<< veiculo.data_hora_entrega<<"\t";
        cout<< veiculo.loja_retirada<<endl<<endl;
    }
    return;
}
void listarLocacoes(vector<Locacao>& locacoes){//, vector<Veiculo>&veiculos, vector<Cliente>&clientes) {
    for (const auto& loc : locacoes) {
        cout << "CPF               : " << loc.cliente->cpf <<endl;
        cout << "Nome              : " << loc.cliente->nome<<endl;
        cout << "Placa             : " << loc.veiculo->placadoveiculo <<endl;
        cout << "Retirada Realizada: " << loc.realizada <<endl; 
        cout << "Data/Hora Retirada: " << loc.dataHoraRetiradaReal <<endl;
        cout << "Data/Hora Entrega : " << loc.dataHoraEntregaReal << endl<<endl;
    }
}


int main(){

    vector<Veiculo> vecveic;
    vector<Cliente> veccli;
    vector<Locacao> vecloc;

    preencheVetorCliente(veccli);
    preencheVetorVeiculos(vecveic);
    ListarCliente(veccli);
    ListarVeiculos(vecveic);

    cout<<">>cnh: "<<&veccli[0].cnh<<endl;
    
    incluirLocacao(vecloc,veccli,vecveic);
    //ListarCliente(veccli);
    //ListarVeiculos(vecveic);
    listarLocacoes(vecloc);//,vecveic,veccli);


    return 0;
}

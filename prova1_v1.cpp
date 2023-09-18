#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cliente{

    string cpf;
    string nome;
    string dtNascimento;
    string cnh;
};
struct DH{
    int dia;
    int mes;
    int ano;
    int hora;
    bool retirada=true;

};
struct Veiculo{
    string renavam;
    string placa;
    DH dhretirada;
    DH dhentrega;
};

int Menu(){
        int op=0;
        cout<<"****CLIENTE****"<<endl;
        cout<<"1-Incluir"<<endl;
        cout<<"2-Excluir"<<endl;
        cout<<"3-Alterar (Digite CPF)"<<endl;
        cout<<"4-Listar"<<endl;
        cout<<"5-Localizar (Digite CPF)"<<endl;
        cout<<"0-Sair"<<endl;
        cin>>op;
        return op;
        //cin>>ws;
        

}
void Incluir(vector<Cliente>& veccli){
    
                Cliente cli;    
                
                cout<<"Nome: ";
                cin>>cli.nome;
                //cin>>ws;
                cout<<"CPF: ";
                cin>>cli.cpf;
                //cin>>ws;
                cout<<"Data nascimento: ";
                cin>>cli.dtNascimento;
                //cin>>ws;
                cout<<"CNH: ";
                cin>>cli.cnh;
                //cin>>ws;
                veccli.push_back(cli);

}
void Listar(vector<Cliente>& veccli){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
                for(auto& it:veccli){
                    cout<<"Nome       : "<<it.nome<<endl;
                    cout<<"CPF        : "<<it.cpf<<endl;
                    cout<<"Data Nasc. : "<<it.dtNascimento<<endl;
                    cout<<"CNH        : "<<it.cnh<<endl<<endl;
                }

}
int Find(vector<Cliente>& veccli, string cpf){

                string excluir=cpf;
                int i=0,pos;
                for(auto& it:veccli){
                    if(excluir == it.cpf){
                        pos=i;
                        break;
                    }
                    i++;

                }
                return pos;
                veccli.erase(veccli.begin()+pos);

}

void Erase(vector<Cliente>& veccli,string cpf){
        int pos;
        pos=Find(veccli,cpf);
        veccli.erase(veccli.begin()+pos);


}
/*
void Replace(vector<Cliente>& veccli){
        int pos;
        pos=Find(veccli);
        veccli.
        veccli.erase(veccli.begin()+pos);


}*/

int main(){
    vector<Cliente> veccli;
    int op=0;

    do{
        op=Menu();
        //cout<<"op: '"<<op<<"''"<<endl;
        if(op==0){
            cout<<"Programam encerrado!"<<endl;
            break;
        }
        switch(op){
            case 1:{
                Incluir(veccli);
                
                break;
            }
            case 2:{ //Excluir
                /*
                string excluir="123";
                int i=0,pos;
                for(auto& it:veccli){
                    if(excluir == it.cpf){
                        pos=i;
                        break;
                    }
                    i++;

                }
                veccli.erase(veccli.begin()+pos);
                */
                string cpf;
                cout<<"Digite CPF: ";
                cin>>cpf;
                Erase(veccli,cpf);
                break;
            }
            case 3:{//Replace
                    int pos;
                string cpf;
                cout<<"Digite CPF: ";
                cin>>cpf;
                    pos=Find(veccli,cpf);
                    cout<<"pos: '"<<pos<<"'"<<endl;
                    //veccli.
                    //veccli.erase(veccli.begin()+pos);

                break;
            }
            case 4:{
                Listar(veccli);
                break;
            }
            case 5:{
                break;
            }


        }
    }while(1);

}
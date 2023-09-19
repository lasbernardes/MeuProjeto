#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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
void Erase (vector<Cliente>& veccli, string cpf){

                string excluir=cpf;
                int i=0,pos;
                for(auto& it:veccli){
                    if(excluir == it.cpf){
                        pos=i;
                        break;
                    }
                    i++;

                }
                veccli.erase(veccli.begin()+pos);

}
void Replace(vector<Cliente>& veccli, string cpf){

                string excluir=cpf;
                string nnome,ncpf,ndtNasc,ncnh;
                int i=0,pos=-1;
                for(auto& it:veccli){
                    if(excluir == it.cpf){
                        pos=i;
                        break;
                    }
                    i++;

                }
                cout<<"pos: '"<<pos<<"'"<<endl;
                cout<<"nome atual: "<<veccli.at(pos).nome<<endl;

                //veccli.erase(veccli.begin()+pos);
                if(pos != -1){
                    cout<<"Novo Nome           : ";
                    cin>>nnome;
                    cout<<"Novo  CPF           : ";
                    cin>>ncpf;
                    cout<<"Nova data Nascimento: ";
                    cin>>ndtNasc;
                    cout<<"Nova CNH            : ";
                    cin>>ncnh;

                    veccli.at(pos).nome=nnome;
                    veccli.at(pos).cpf=ncpf;
                    veccli.at(pos).dtNascimento=ndtNasc;
                    veccli.at(pos).cnh=ncnh;
                    //cout<<"nome modificado: "<<veccli.at(pos).nome<<endl;

                       // replace(veccli.begin(), veccli.end(), cli.nome.at(pos), nnome);

                }

}
void Locate(vector<Cliente>& veccli, string cpf){

                string localizar=cpf;
                int i=0,pos=-1;
                for(auto& it:veccli){
                    if(localizar == it.cpf){
                        pos=i;
                        break;
                    }
                    i++;

                }
                //cout<<"pos: '"<<pos<<"'"<<endl;
                cout<<"nome atual: "<<veccli.at(pos).nome<<endl;

                //veccli.erase(veccli.begin()+pos);
                if(pos != -1){
                    cout<<"Nome           : "<<veccli.at(pos).nome<<endl;
                    cout<<"CPF            : "<<veccli.at(pos).cpf<<endl;
                    cout<<"data Nascimento: "<<veccli.at(pos).dtNascimento<<endl;
                    cout<<"CNH            : "<<veccli.at(pos).cnh<<endl;
                    
                }

}

int main(){
    vector<Cliente> veccli;
    int op=0, op1=0;
    do{
        cout<<"1-Cliente"<<endl;
        cout<<"2-Veículo"<<endl;
        cin>>op1;
        if(op1==1){
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
                            Replace(veccli,cpf);
                            //veccli.
                            //veccli.erase(veccli.begin()+pos);

                        break;
                    }
                    case 4:{
                        Listar(veccli);
                        break;
                    }
                    case 5:{//Localizar
                        string lcpf;
                        cout<<"Digite CPF: ";
                        cin>>lcpf;
                        Locate(veccli, lcpf);
                        break;
                    }


                }
            }while(1);
        }else{

            
        }
    }while(1);

}
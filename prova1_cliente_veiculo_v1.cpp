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
struct Veic{
    string renavam;
    string placa;
    //DH dhretirada;
    //DH dhentrega;
    string dhretirada;
    string dhentrega;
    string loja;
};
//----CLIENTE
int cMenu(){
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
}
void cIncluir(vector<Cliente>& veccli){
                Cliente cli;    
                cout<<"Nome: ";
                cin>>cli.nome;
                cout<<"CPF: ";
                cin>>cli.cpf;
                cout<<"Data nascimento: ";
                cin>>cli.dtNascimento;
                cout<<"CNH: ";
                cin>>cli.cnh;
                veccli.push_back(cli);
}
void cListar(vector<Cliente>& veccli){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
                for(auto& it:veccli){
                    cout<<"Nome       : "<<it.nome<<endl;
                    cout<<"CPF        : "<<it.cpf<<endl;
                    cout<<"Data Nasc. : "<<it.dtNascimento<<endl;
                    cout<<"CNH        : "<<it.cnh<<endl<<endl;
                }
}
void cErase (vector<Cliente>& veccli, string cpf){
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
void cReplace(vector<Cliente>& veccli, string cpf){
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
                }
}
void cLocate(vector<Cliente>& veccli, string cpf){
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
                //cout<<"nome atual: "<<veccli.at(pos).nome<<endl;
                if(pos != -1){
                    cout<<"Nome           : "<<veccli.at(pos).nome<<endl;
                    cout<<"CPF            : "<<veccli.at(pos).cpf<<endl;
                    cout<<"data Nascimento: "<<veccli.at(pos).dtNascimento<<endl;
                    cout<<"CNH            : "<<veccli.at(pos).cnh<<endl;
                }
}
//----VEICULO
int Menu(){
        int op=0;
        cout<<"****VEÍCULO****"<<endl;
        cout<<"1-Incluir"<<endl;
        cout<<"2-Excluir"<<endl;
        cout<<"3-Alterar (Digite placa)"<<endl;
        cout<<"4-Listar"<<endl;
        cout<<"5-Localizar (Digite placa)"<<endl;
        cout<<"0-Sair"<<endl;
        cin>>op;
        return op;
}
void Incluir(vector<Veic>& vecveic){
                Veic veic;    
                cout<<"Renavam: ";
                cin>>veic.renavam;
                cout<<"Placa: ";
                cin>>veic.placa;
                cout<<"Data retirada: ";
                cin>>veic.dhretirada;
                cout<<"Data entrega: ";
                cin>>veic.dhentrega;
                cout<<"Loja da retirada: ";
                cin>>veic.loja;
                vecveic.push_back(veic);
}
void Listar(vector<Veic>& vecveic){
    //for(auto it=vecveic.begin();it!=vecveic.end(); it++){
                for(auto& it:vecveic){
                    cout<<"Renavam            : "<<it.renavam<<endl;
                    cout<<"Placa              : "<<it.placa<<endl;
                    cout<<"Data hora retirada : "<<it.dhretirada<<endl;
                    cout<<"Data hora entrega  : "<<it.dhentrega<<endl;
                    cout<<"CNH                : "<<it.loja<<endl<<endl;
                }
}
void Erase (vector<Veic>& vecveic, string placa){
                string excluir=placa;
                int i=0,pos;
                for(auto& it:vecveic){
                    if(excluir == it.placa){
                        pos=i;
                        break;
                    }
                    i++;
                }
                vecveic.erase(vecveic.begin()+pos);
}
void Replace(vector<Veic>& vecveic, string placa){
                string excluir=placa;
                string nrenavam,nplaca,ndhret,ndhent,nloja;
                int i=0,pos=-1;
                do{
                    for(auto& it:vecveic){
                        if(excluir == it.placa){
                            pos=i;
                            break;
                        }
                        i++;
                    }
                    cout<<"pos: '"<<pos<<"'"<<endl;
                    cout<<"renavam atual: "<<vecveic.at(pos).renavam<<endl;
                }while(pos==-1);
                //vecveic.erase(vecveic.begin()+pos);
                if(pos != -1){
                    cout<<"Novo Renavam           : ";
                    cin>>nrenavam;
                    cout<<"Novo  Placa            : ";
                    cin>>nplaca;
                    cout<<"Nova data hora Retirada: ";
                    cin>>ndhret;
                    cout<<"Nova data hora Entrega : ";
                    cin>>ndhent;
                    cout<<"Nova Loja de retirada  : ";
                    cin>>nloja;

                    vecveic.at(pos).renavam=nrenavam;
                    vecveic.at(pos).placa=nplaca;
                    vecveic.at(pos).dhretirada=ndhret;
                    vecveic.at(pos).dhentrega=ndhent;
                    vecveic.at(pos).loja=nloja;
                    //cout<<"renavam modificado: "<<vecveic.at(pos).renavam<<endl;
                }
}
void Locate(vector<Veic>& vecveic, string placa){
                string localizar=placa;
                int i=0,pos=-1;
                for(auto& it:vecveic){
                    if(localizar == it.placa){
                        pos=i;
                        break;
                    }
                    i++;
                }
                //cout<<"pos: '"<<pos<<"'"<<endl;
                //cout<<"renavam atual: "<<vecveic.at(pos).renavam<<endl;
                if(pos != -1){
                    cout<<"Renavam           : "<<vecveic.at(pos).renavam<<endl;
                    cout<<"Placa             : "<<vecveic.at(pos).placa<<endl;
                    cout<<"data hora retirada: "<<vecveic.at(pos).dhretirada<<endl;
                    cout<<"data hora entrega : "<<vecveic.at(pos).dhentrega<<endl;
                    cout<<"Loja de retirada  : "<<vecveic.at(pos).loja<<endl;
                }
}

int main(){
    vector<Cliente> veccli;
    vector<Veic> vecveic;

    int op=0, op1=0;
    do{
        cout<<"1-Cliente"<<endl;
        cout<<"2-Veículo"<<endl;
        cout<<"0-Sair"<<endl;
        cin>>op1;
        if(op1==0){
            cout<<"Programa - Programa encerrado!"<<endl;
            break;
        }
            
        switch (op1){
            case 1:{
                do{
                    op=cMenu();
                    //cout<<"op: '"<<op<<"''"<<endl;
                    if(op==0){
                        cout<<"Cliente - Programa encerrado!"<<endl;
                        break;
                    }
                    switch(op){
                    
                        case 1:{
                            cIncluir(veccli);
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
                            cErase(veccli,cpf);
                            break;
                        }
                        case 3:{//Replace
                                int pos;
                            string cpf;
                            cout<<"Digite CPF: ";
                            cin>>cpf;
                                cReplace(veccli,cpf);
                                //veccli.
                                //veccli.erase(veccli.begin()+pos);

                            break;
                        }
                        case 4:{
                            cListar(veccli);
                            break;
                        }
                        case 5:{//Localizar
                            string lcpf;
                            cout<<"Digite CPF: ";
                            cin>>lcpf;
                            cLocate(veccli, lcpf);
                            break;
                        }
                        default:{
                            cout<<"Cliente - Opção inválida!"<<endl<<endl;
                        }
                    }
                }while(1);
                break;
            }
            case 2:{
                do{
                    op=Menu();
                    //cout<<"op: '"<<op<<"''"<<endl;
                    if(op==0){
                        cout<<"Veículo - Programa encerrado!"<<endl;
                        break;
                    }
                    switch(op){
                        case 1:{
                            Incluir(vecveic);
                            break;
                        }
                        case 2:{ //Excluir
                            /*
                            string excluir="123";
                            int i=0,pos;
                            for(auto& it:vecveic){
                                if(excluir == it.placa){
                                    pos=i;
                                    break;
                                }
                                i++;

                            }
                            vecveic.erase(vecveic.begin()+pos);
                            */
                            string placa;
                            cout<<"Digite Placa: ";
                            cin>>placa;
                            Erase(vecveic,placa);
                            break;
                        }
                        case 3:{//Replace
                                int pos;
                            string placa;
                            cout<<"Digite Placa: ";
                            cin>>placa;
                                Replace(vecveic,placa);
                                //vecveic.
                                //vecveic.erase(vecveic.begin()+pos);

                            break;
                        }
                        case 4:{
                            Listar(vecveic);
                            break;
                        }
                        case 5:{//Localizar
                            string lplaca;
                            cout<<"Digite Placa: ";
                            cin>>lplaca;
                            Locate(vecveic, lplaca);
                            break;
                        }
                        default:{
                            cout<<"Veículo - Opção inválida!"<<endl<<endl;
                        }

                    }
                }while(1);
                break;
            }
            default:{
                cout<<"Programa - Opção inválida!"<<endl<<endl; 
            }
        }
    }while(1);
}
#include<iostream>
#include <cmath>
#include<vector>

using namespace std;

class Desenhavel{
public:
    virtual void desenhar() = 0;

};

class Forma{
public:
    virtual double calcularArea(){
        //cout<<"metodo area"<<endl;
        return 0.0;
    }
};

class Circulo:public Forma, public Desenhavel{
    public:

    double raio;
        Circulo(double _raio){
            raio = _raio <= 0 ? 0 : _raio;
        }

        void desenhar() override {
            cout<<"Desenhar circulo"<<endl;
        }

        double calcularArea() override {
            return M_PI*raio*raio;
        }
};

class Retangulo : public Forma, public Desenhavel{
    public:
        double base,altura;
        Retangulo(double _base, double _altura){
            base = _base <= 0 ? 0 : _base;
            altura = _altura;
        }

        void desenhar() override {
            cout<<"Desenhei um retangulo"<<endl;
        }

        double calcularArea() override {
            return base * altura;
        }
};

int main(){

    Circulo *circulo=new Circulo(0);
    Retangulo *retangulo =new Retangulo(0,0);

    //Desenhavel* item1 = circulo;
    //Desenhavel* item2 = retangulo;
    retangulo->base= 16;
    retangulo->altura=9;
    
    

    cout<<retangulo->calcularArea()<<endl;

    cout<<"Elementos do vector: "<<endl;
    
    cout<<"Elementos imprimiveis: "<<endl;
    Desenhavel *formaDesenho;
    formaDesenho = circulo;
    formaDesenho->desenhar();
    return 0;
}
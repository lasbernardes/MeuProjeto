#include<iostream>
#include <cmath>
#include<vector>

using namespace std;


class Forma{
public:
    virtual double calcularArea(){
        //cout<<"metodo area"<<endl;
        return 0.0;
    }
};

class Circulo:public Forma{
    public:

    double raio;
    Circulo(double _raio){
            raio = _raio <= 0 ? 0 : _raio;
        }

        void desenhar(){
            cout<<"Desenhar circulo"<<endl;
        }

        double calcularArea() override {
            return M_PI*raio*raio;
        }
};

class Retangulo : public Forma{
    public:
        double base,altura;
        Retangulo(double _base, double _altura){
            base = _base <= 0 ? 0 : _base;
            altura = _altura;
        }

        void desenhar(){
            cout<<"Desenhei um retangulo"<<endl;
        }

        double calcularArea() override {
            return base * altura;
        }
};

int main(){

    vector <Forma*> vecForma;

    Circulo *circulo = new Circulo(0);
    circulo->raio=2;
    cout<< circulo->calcularArea()<<endl;
    vecForma.push_back(circulo);

    Circulo circ(3.0);
    Retangulo ret(2.0,3.0);
    cout<<circ.calcularArea()<<endl;
    cout<<ret.calcularArea()<<endl;
    return 0;
}
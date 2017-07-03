#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <list>
typedef string elemento;
class Conjunto
{
    public:
        Conjunto();
        std::list <elemento> conjunto;
        std::list<elemento>::iterator it;
        string numconjunto;
        void AgregarElemento(elemento);
        void EliminarElemento(elemento);
        void SetNumeroDelConjunto(string);
    protected:

    private:
};
Conjunto::Conjunto()
{

}
void Conjunto::AgregarElemento(elemento elem)
{
    conjunto.push_back(elem);
}
void Conjunto::EliminarElemento(elemento elem)
{
    conjunto.remove(elem);
}
void Conjunto::SetNumeroDelConjunto(string num)
{
    numconjunto = num;
}


#endif // CONJUNTO_H

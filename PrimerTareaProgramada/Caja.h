#ifndef CAJA_H
#define CAJA_H

#include <iostream>

using namespace std;
template <class T>
class Caja
{
    public:
        Caja();
        virtual ~Caja();
        T dato;
        Caja *ptr;

    protected:

    private:
};
template <class T>
Caja<T>::Caja()
{
    ptr = 0;
}
template <class T>
Caja<T>::~Caja()
{

}

#endif // CAJA_H

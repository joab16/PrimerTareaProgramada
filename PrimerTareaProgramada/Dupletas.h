#ifndef DUPLETAS_H
#define DUPLETAS_H

#include <iostream>

using namespace std;
template <class Z>
class Dupletas
{
    public:
        Dupletas();
        Dupletas(Z, Z);
        //virtual ~Dupletas();
		Z origen;
		Z adyacente;
    protected:

    private:
};

template <class Z>
Dupletas<Z>::Dupletas()
{

}

template <class Z>
Dupletas<Z>::Dupletas(Z v, Z u)
{
    origen = v;
    adyacente = u;
}

#endif // DUPLETAS_H

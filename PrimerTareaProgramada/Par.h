#ifndef PAR_H
#define PAR_H

#include <iostream>

using namespace std;

template <class T1,class T2>
class Par
{
    public:
        Par();
        Par(T1,T2);
        T1 dato;
        T2 prioridad;
        T1 GetDato();
        T2 GetPrioridad();
        virtual ~Par();

    protected:

    private:
};
template <class T1,class T2>
Par<T1,T2>::Par()
{

}
template <class T1,class T2>
Par<T1,T2>::Par(T1 dat, T2 prio)
{
    dato = dat;
    prioridad = prio;
}
template <class T1,class T2>
Par<T1,T2>::~Par()
{

}
template <class T1,class T2>
T1 Par<T1,T2>::GetDato()
{
    return dato;
}
template <class T1,class T2>
T2 Par<T1,T2>::GetPrioridad()
{
   return prioridad;
}
#endif // PAR_H

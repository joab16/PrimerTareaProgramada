#ifndef DUPLETAS_H
#define DUPLETAS_H

class Dupletas
{
    public:
        Dupletas();
        Dupletas(vertice, vertice);
        //virtual ~Dupletas();
        vertice origen;
        vertice adyacente;
    protected:

    private:
};

Dupletas::Dupletas()
{

}
Dupletas::Dupletas(vertice v, vertice u)
{
    origen = v;
    adyacente = u;
}

#endif // DUPLETAS_H

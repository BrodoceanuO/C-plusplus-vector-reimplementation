#include "NrComplex.h"
#include <math.h>
#include <iostream>

using namespace std;

NrComplex::NrComplex()
{
pR=0;
pIm=0;
}

NrComplex::NrComplex(float r,float i)
{
pR=r;
pIm=i;
}

ostream & operator<< (ostream &out, const NrComplex &c)
{
    out << c.pR;
    if (c.pIm > 0)
        out <<"+"<<c.pIm<<"*i" <<endl;
    else
        out <<"-" <<-1*c.pIm<<"*i"<<endl;
    return out;
}

istream & operator >> (istream &in, NrComplex &c)
{
cout <<"Introduceti partea reala: ";
in >> c.pR;
cout << "Introduceti partea imaginara: ";
in >>c.pIm;
return in;
}

float NrComplex::modul()
{
    return sqrt(pow(pR,2)+pow(pIm,2));
}

NrComplex NrComplex::operator+(NrComplex b)
{
    NrComplex New;
    New.pIm=pIm+b.pIm;
    New.pR=pR+b.pR;
    return New;
}


/*NrComplex operator+(float r,NrComplex nr)
{
NrComplex New;
New.pIm=nr.pIm;
New.pR=nr.pR+r;
return New;
} */

bool NrComplex::operator==(NrComplex nr)
{
if (pIm==nr.pIm && pR==nr.pR) return true;
return false;
}

NrComplex NrComplex::operator=(NrComplex nr)
{
NrComplex copie;
pIm=nr.pIm;
pR=nr.pR;
copie.pIm=pIm;
copie.pR=pR;
return copie;
}


NrComplex NrComplex::operator*(NrComplex b)
{
    NrComplex New;
    New.pR=(pR*b.pR)-(pIm*b.pIm);
    New.pIm=(pIm*b.pIm)+(pIm*b.pR);
    return New;
}

NrComplex NrComplex::operator+(float r) //FUNCTIE FRIEND TRANSFORMATA IN FUNCTIE MEMBRA
{
    NrComplex New;
    New.pIm=pIm;
    New.pR=pR+r;
    return New;
}

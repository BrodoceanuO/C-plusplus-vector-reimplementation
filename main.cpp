#include <iostream>
#include <vector>
#include "NrComplex.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

class NVectC;

class VectC{
    int numElem;    //numarul de elemente
    NrComplex* v;   // array-ul ce contine numerele complexe
public:
    VectC(VectC&); //constructor de copiere
    VectC();    //constructor fara parametrii, marimea va fi 0 iar v va pointa la null
    VectC(int);     // contructor ce primeste numarul de elemente si aloca dinamic memorie
    VectC(int,NrComplex); //contructor ce initializeaza intreg array-ul cu un numar complex dat
    ~VectC();   //destructorul, seteaza marimea la 0 si elibereaza zona de memorie
    int getNum(){return numElem;}   //getter pentru numarul de elemente
    void Show();    // metoda pentru afisarea vectorului ce o apeleaza
    float* ModV();  // metoda ce returneaza un vector de module din vectorul complex ce o apeleaza
    NrComplex suma();   //metoda ce returneaza suma tuturor elementelor din vectorul complex
    void Sort();    //motoda de sortare
    NrComplex operator*(VectC& v);  //metoda ce returneaza produsul scalar
    VectC operator=(VectC);     //overloaded operator = de atribuire pentru vectori complesci
    NrComplex* operator[](int);     //overloaded operator [] ce returneaza numarul complex de pe pozitia introdusa
    friend ostream& operator<<(ostream&,const VectC& vect);     //overloaded operator out
    friend istream & operator>>(istream& in, VectC& vect);      //overloaded operator in
    friend void Add(NVectC&);       //functie friend pentru adaugarea unui vector complex in clasa vector de vectori complecsi
    friend void Modul(NVectC A);    //functie friend pentru modulul a doi vectori coplecsi in cadrul clasei vector de vectori complecsi
    friend void ProdusScalar(NVectC A);     //functie friend pentru returnarea produsului scalar a doi vectori in cadrul clasei vector de vectori complecsi
};

class NVectC
{
VectC* vect;
int nr;
    public:
        NVectC();   //constructor fara parametrii
        NVectC(NVectC&);    //constructor de copiere
        void ShowAll() // metoda de afisare a tuturor vectorilor
        {
         cout<<"Ati ales sa afisati toti vectorii complecsi: "<<endl;
         for (int i=0;i<nr;i++)
            cout<<vect[i];
         cout<<endl<<endl;
        }
        int getNr() //getter penru numarul de elemente
        {
        return nr;
        }
        friend void Sort(NVectC);
        friend void Show(NVectC);
        friend void Add(NVectC&); //functie friend pentru adaugarea unui vector complex in clasa vector de vectori complecsi
        friend void Modul(NVectC A);    //functie friend pentru modulul a doi vectori coplecsi introdusi ptin indici in
        friend void Suma(NVectC A);     //functie friend pentru calcularea sumei elementelor unui vector complex introdus prin indice
        friend void ProdusScalar(NVectC A);     //functie friend ce returneaza produsul scalar al unui vector complex introdus prin indice
};

VectC VectC::operator=(VectC B)
{
numElem=B.numElem;
v= new NrComplex[numElem];
for (int i=0;i<numElem;i++)
    v[i]=B.v[i];
return *this;
}


NVectC::NVectC()
{
    cout<<"Cati vectori complecsi doriti sa introduceti: ";
    cin>>nr; //numarul de vectori complecsi
    vect = new VectC[nr];
    for (int i=0;i<nr;i++)
        cin>>vect[i];
    cout<<endl;
    for (int i=0;i<nr;i++)
        cout<<vect[i]<<endl;
}

NVectC::NVectC(NVectC& B)
{
vect=B.vect;
nr=B.nr;
}

VectC::VectC()
{
v=nullptr;
numElem=0;
}

VectC::~VectC()
{
    free(v);
    numElem=0;
}

void VectC::Sort()
{
NrComplex aux(0,0); //NrComplex auxiliar folosit la sortare
for (int i=0;i<numElem;i++)
    for (int j=0;j<numElem;j++)
    {
     if ( v[i].modul()<v[j].modul() )
        {
         aux=v[i];
         v[i]=v[j];
         v[j]=aux;
        }
    }
}

VectC::VectC(VectC& original)
{
numElem=original.numElem;
v = new NrComplex[numElem];
for (int i=0;i<numElem;i++)
        v[i]=original.v[i];
}


ostream& operator<<(ostream& out,const VectC& vect)
{
for (int i=0;i<vect.numElem;i++)
    {
    out << vect.v[i];
    }
return out;
}

istream& operator>>(istream& in, VectC& vect)
{
cout<<"Introduceti numarul de elemente: ";
cin>>vect.numElem;
vect.v= new NrComplex[vect.numElem];
for (int i=0;i<vect.numElem;i++)
    {
    in>>vect.v[i];
    }
cout<<endl;
return in;
}

VectC::VectC(int num)
{
numElem=num;
v = new NrComplex[numElem];
}

float* VectC::ModV()
{
float* mod = new float[numElem];
for (int i=0;i<numElem;i++)
    {
     mod[i]=v[i].modul();
    }
return mod;
}

NrComplex VectC::suma()
{
NrComplex sum(0,0); //suma setata la 0+0*i
for (int i =0;i<numElem;i++)
    {
     sum=sum+v[i];
    }
return sum;
}

VectC::VectC(int num,NrComplex nr)
{
numElem=num;
v= new NrComplex[numElem];
for (int i=0;i<numElem;i++)
    {
     v[i]=nr;
    }
}

NrComplex VectC::operator*(VectC& v2)
{
NrComplex PS(0,0);
if (numElem!=v2.numElem) //daca cei doi vectori nu au acelsai numar de elemente functia se opreste
    {
    cout<<"Cei doi vectori nu au aceeasi lungime!";
    return PS;
    }
for (int i=0;i<numElem;i++)
    {
    PS=PS+v[i]*v2.v[i];
    }
return PS;
}

void VectC::Show()
{
for (int i=0;i<numElem;i++)
    {
     cout<<v[i]<<endl;
    }
}

void Sort(NVectC A)
{
cout<<"Ati ales sa sortati"<<endl;
cout<<"Care dintre vectori doriti sa sortati dupa modul: "<<endl;
int nr;
eticheta:cin>>nr;
cout<<endl;
if (nr<A.nr)
    {
     A.vect[nr].Sort();
    cout<<A.vect[nr];
    }
else
    {
    cout<<"Introduceti un vector valabil!"<<endl;
    goto eticheta;
    }
}


void Show(NVectC A)
{
cout<<"Ce vector doriti sa afisati?"<<endl;
int i;
cin>>i;
if (i>=A.nr)
{
    cout<<"Nu sunt atatea vectori!"<<endl;
    return;
}
cout<<A.vect[i];
}

void Add(NVectC &A)
{
cout<<"Ati decis sa adaugati un vector"<<endl;
NVectC B(A);    //copie auxiliara
A.vect=new VectC[B.nr+1]; //setam memoria la marimea anterioara+1
A.nr=B.nr+1;//setam marimea la marimea anterioara+1
for (int i=0;i<B.nr;i++)
    A.vect[i]=B.vect[i]; //reumplem A cu vechile valori
cout<<"Doriti sa instantiati vectorul cu un numar complex pe toate pozitiile ? d/n"<<endl;
char c; // alegere daca noul vector se va inializa cu un NrComplex sau daca valorile vor fi date manual
eticheta:cin>>c;
if (c=='d')
    {
    cout<<"Introduceti numarul de elemente: ";
    cin>>A.vect[A.nr-1].numElem;
    NrComplex n;
    cout<<"Introduceti numarul complex: "<<endl;
    cin>>n;
    A.vect[A.nr-1].v=new NrComplex[A.vect[A.nr-1].numElem];
    for (int i=0;i<A.vect[A.nr-1].numElem;i++)
        A.vect[A.nr-1].v[i]=n;
    }
else if (c=='n')
     cin>>A.vect[A.nr-1];
else
    {
    cout<<"Introduceti o comanda valida!"<<endl;
    goto eticheta;
    }
}

void Modul(NVectC A)
{
cout<<"Modulul carui vector il doriti ?"<<endl;
int nr;
eticheta:
cin>>nr;
cout<<endl;
if (nr<A.nr)
    {
     float* f = new float[A.vect[nr].numElem];
     f=A.vect[nr].ModV();
     for (int i=0;i<A.vect[nr].numElem;i++)
        cout<<f[i]<<endl;
    }
else
    {
    cout<<"Introduceti un vector valabil!"<<endl;
    goto eticheta;
    }
}

void Suma(NVectC A)
{
cout<<"Suma carui vector il doriti ?"<<endl;
int nr;
eticheta:
cin>>nr;
cout<<endl;
if (nr<A.nr)
    {
     NrComplex s=A.vect[nr].suma();
     cout<<s;
    }
else
    {
    cout<<"Introduceti un vector valabil!"<<endl;
    goto eticheta;
    }
}

void ProdusScalar(NVectC A)
{
cout<<"Ati ales sa inmultiti doi vectori"<<endl;
int nr1;
cout<<"Introduceti primul vector: ";
eticheta1:cin>>nr1;
cout<<endl;
if (nr1>A.nr)
    {
    cout<<"Introduceti un vector valabil!"<<endl;
    goto eticheta1;
    }
int nr2;
cout<<"Introduceti cel de-al doilea vector: ";
eticheta2:cin>>nr2;
cout<<endl;
if (nr2>A.nr)
    {
    cout<<"Introduceti un vector valabil!"<<endl;
    goto eticheta2;
    }
if (A.vect[nr1].numElem!=A.vect[nr2].numElem)
    {
    cout<<"Cei doi vectori nu au marii egale!"<<endl;
    return;
    }
else
    cout<<A.vect[nr1]*A.vect[nr2];
}

int main()
{
    NVectC A;
    char input;
    if (A.getNr()==0)
    {
        cout<<"Trebuie introdus cel putin un vector!"<<endl;
        Add(A);
    }
    while (input!='X')
    {
     cout<<"Introduceti o comanda: ";
     cin>>input;
     switch (input)
        {
        case 'a':
            Sort(A);
            break;
        case 'b':
            Show(A);
            break;
        case 'c':
            Add(A);
            break;
        case 'd':
            Modul(A);
            break;
        case 'e':
            Suma(A);
            break;
        case 'f':
            ProdusScalar(A);
            break;
        case 'g':
            A.ShowAll();
            break;
        }
    }
    return 0;
}

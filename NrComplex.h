#ifndef NRCOMPLEX_H
#define NRCOMPLEX_H
#include <iostream>

using namespace std;

class NrComplex{
    float pR; //partea reala
    float pIm; //partea imaginara
public:
    NrComplex(); // constructor fara param.
    NrComplex(float,float); // consructor ce primeste partea reala si imaginara
    getpR(){ return pR;}; //getter parte reala
    getpIm(){ return pIm;}; //getter parte imaginara
    float modul();  // modului nr. complex
    NrComplex operator+(NrComplex); // adunarea a 2 nr complexe
    NrComplex operator+(float); // adunarea unui nr. complex cu un nr. real
    bool operator==(NrComplex); // operator verificarea egalitatilor
    NrComplex operator=(NrComplex); // operator atribuire
    friend NrComplex operator+(float,NrComplex); //adunarea unui nr. complex cu un nr. real
    NrComplex operator*(NrComplex); // inmultirea a doua numere complexe
    friend ostream & operator << (ostream &out, const NrComplex &c);    //operator out
    friend istream & operator >> (istream &in, NrComplex &c);   //operator in
};

#endif // NRCOMPLEX_H

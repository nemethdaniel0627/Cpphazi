#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

struct Koordinata
{
    double hossz;
    double szeless;
};

struct Megallo
{
    string azonosito;
    string nev;
    Koordinata koordinata;
};

Megallo feldolgoz(ifstream &sor)
{
    Megallo megallo;
    string tmp;
    getline(sor, megallo.azonosito, ';');
    getline(sor, megallo.nev, ';');
    sor >> megallo.koordinata.szeless;
    sor >> megallo.koordinata.hossz;
    getline(sor, tmp) >> ws;
    return megallo;
}

void beolvas(string fajlnev)
{
    ifstream bf(fajlnev);
    string sor;
    vector<Megallo> megallok;
    if (bf.good())
    {
        getline(bf, sor) >> ws;
    }
    while (bf.good())
    {
        megallok.push_back(feldolgoz(bf));
    }
}

void kiir(vector<Megallo>& adatok) {
    for (Megallo megallo : adatok) {
        cout << megallo.azonosito << " " << megallo.nev << " " << megallo.koordinata.szeless << " " << megallo.koordinata.hossz << endl; 
    }
}

int megalloKeres(string keres, vector<Megallo> adatok) {
    int counter = 0;
    for (Megallo megallo : adatok) {
        if (megallo.nev == keres) 
            counter++;
    }
    return counter;
}

int main()
{
    beolvas("stops.txt");
    return 0;
}

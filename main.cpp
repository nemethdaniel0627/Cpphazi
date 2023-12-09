#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

struct NapiHom {
    int reggel;
    int del;
    int este;
};

vector<NapiHom> beolvas(ifstream& bf) {
    vector<NapiHom> napiHomertek;
    while(bf.good()) {
        char szemet;
        NapiHom nap;
        bf >> nap.reggel >> szemet >> nap.del >> szemet >> nap.este;
        napiHomertek.push_back(nap);
    }
    return napiHomertek;
}

int napiHoIngad(vector<NapiHom> napihomertek) {
    double maxAtlag = 0;
    int melyikNap = 0;
    for (std::size_t i = 0; i < napihomertek.size(); i++) {
        double atlag = (abs(napihomertek[i].reggel - napihomertek[i].del) + abs(napihomertek[i].del - napihomertek[i].este)) / 2;
        if (maxAtlag < atlag) {
            maxAtlag = atlag;
            melyikNap = i+1;
        }
    }
    return melyikNap;
}

int main() {
    ifstream bf;
    bf.open("homertek.txt");
    vector<NapiHom> napiHomertek = beolvas(bf);
    cout << napiHoIngad(napiHomertek) << endl;
    return 0;
}

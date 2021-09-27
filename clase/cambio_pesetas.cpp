#include <iostream>
#include <iomanip>
using namespace std;

/* Programa que te realiza un cambio de Euros a Pesetas*/

int main(){

    const double ptas_por_euro = 166.386;
    unsigned pesetas; // Lo declaro como unsigned, ya que lo unico que se, es que el billete sera una cifra positiva.

    cout << "Escriba la cifra de pesetas: ";
    cin >> pesetas;
    cout << fixed << setprecision(2) << pesetas/ptas_por_euro << " euros"<<endl;

    return 0;
}
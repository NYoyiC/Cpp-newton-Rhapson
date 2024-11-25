#include <iostream>
#include <cmath>
#include <iomanip> // Para formato de salida

using namespace std;

// Constantes de la Ley de Planck
const double h = 6.626e-34;  // Constante de Planck (J·s)
const double c = 3e8;        // Velocidad de la luz (m/s)
const double k_B = 1.38e-23; // Constante de Boltzmann (J/K)
const double nu = 3.25e14;   // Frecuencia constante (Hz)

// Función f(T)
double f(double T) {
    double cs = 2 * h * pow(nu, 3) / pow(c, 2);
    double denominador = exp(h * nu / (k_B * T)) - 1;
    if (denominador <= 0) {
        return NAN; // Retorna NaN si el denominador es cero o negativo
    }
    return cs / denominador;
}

// Derivada de f(T), f'(T)
double fp(double T) {
    double cs = 2 * h * pow(nu, 3) / pow(c, 2);
    double exp_term = exp(h * nu / (k_B * T));
    double denominador = exp_term - 1;
    if (denominador <= 0) {
        return NAN; // Retorna NaN si el denominador es cero o negativo
    }
    double derivada = cs * (h * nu / (k_B * T * T)) * exp_term / (denominador * denominador);
    return derivada;
}

int main() {
    int n = 0;
    int maxiteraciones = 1000;
    double T0 = 5000; // Empieza con un valor más alto para evitar NaN
    double T1;
    
    while (n < maxiteraciones) {
        double fT0 = f(T0);
        double fpT0 = fp(T0);
        
        if (isnan(fT0) || isnan(fpT0)) {
            cout << "Se produjo un valor NaN en la iteracion " << n << ". Verifica los calculos." << endl;
            break;
        }
        
        T1 = T0 - fT0 / fpT0;
        
        // Si la diferencia entre iteraciones es pequeña, consideramos que hemos convergido
        if (abs(T1 - T0) < 1e-6) {
            break;
        }
        
        // Evitar valores negativos
        if (T1 < 0) {
            cout << "Se alcanzo un valor negativo en la iteracion " << n << ". T = " << T1 << endl;
            break;
        }
        
        T0 = T1;
        cout << "Iteracion " << n << ": T = " << T1 << endl;
        n++;
    }

    cout << "Temperatura encontrada: " << T1 << endl;

    return 0;
}

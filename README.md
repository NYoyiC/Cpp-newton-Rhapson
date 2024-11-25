# Ley de Planck y Método de Newton-Raphson

Este proyecto contiene un código en C++ que implementa la ley de Planck y utiliza el método de Newton-Raphson para encontrar la temperatura en la cual la radiación de cuerpo negro se distribuye según esta ley.

## Descripción

La ley de Planck describe la distribución espectral de la radiación electromagnética emitida por un cuerpo negro en equilibrio térmico a una temperatura definida \( T \). Este proyecto incluye:

1. **Implementación de la ley de Planck**: Calculo de la intensidad espectral de la radiación \( f(T) \).
2. **Derivada de la ley de Planck**: Derivación simbólica de \( f(T) \).
3. **Método de Newton-Raphson**: Aplicación del método iterativo de Newton-Raphson para encontrar la temperatura \( T \).

## Uso

Compila el código y ejecútalo para ver las iteraciones y el valor final de la temperatura encontrada.

### Compilación

Asegúrate de tener un compilador C++ instalado. Puedes usar `g++`:

```sh
g++ -o planck_newton planck_newton.cpp

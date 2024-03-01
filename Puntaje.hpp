// Puntaje.hpp
#ifndef PUNTAJE_HPP
#define PUNTAJE_HPP

#include <string>

class Puntaje {
public:
    Puntaje(const std::string& nombre, int puntaje);
    std::string ConsultarNombre() const;
    int ConsultarPuntaje() const;

    // Sobrecarga del operador < para comparar puntajes
    bool operator<(const Puntaje& otro) const;

private:
    std::string nombre;
    int puntaje;
};

#endif // PUNTAJE_HPP

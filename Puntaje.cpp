// Puntaje.cpp
#include "Puntaje.hpp"

Puntaje::Puntaje(const std::string& nombre, int puntaje) : nombre(nombre), puntaje(puntaje) {}

std::string Puntaje::ConsultarNombre() const {
    return nombre;
}

int Puntaje::ConsultarPuntaje() const {
    return puntaje;
}

bool Puntaje::operator<(const Puntaje& otro) const {
    // Ordenar en orden descendente (mayor a menor)
    return puntaje > otro.puntaje;
}

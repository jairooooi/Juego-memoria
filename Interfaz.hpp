#include <iostream>
#include <SFML/Graphics.hpp>
#include "Puntaje.hpp"


using namespace std;
using namespace sf;

class Interfaz : public Drawable{
    private:
        int puntos=0;
        int descubiertas=0;
        Clock clock;
        Time time;
        Font font;
        Text puntosText;
        Text descubiertasText;
        Text clockText;
        Text resultadoText;

        //Vector de Objetos Puntaje
        vector<Puntaje> puntajes;

    public:
        Interfaz();
        void Update();
        void CambiarPuntaje(int mod);
        void CambiarDescubiertas(int mod);
        int ConsultarDescubiertas();
        int ConsultarTiempo();

        // Consultar el puntaje actual
        int ConsultarPuntaje() const {
            return puntos;
        }

        //Funciones para manejar puntaje y archivos
        void LeerPuntajesDesdeArchivo();
        void GuardarPuntajesEnArchivo() const;

        // Actualizar las funciones de puntajes para usar archivos
        void AgregarPuntaje(const Puntaje& puntaje);
        void MostrarPuntajes() const;
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
};
#include "Interfaz.hpp"
#include "Puntaje.hpp"
#include <fstream>
#include <algorithm> 

Interfaz::Interfaz(){
    if(!font.loadFromFile("Bubblegum.ttf")) cout<<"Error al cargar la fuente de texto"<<endl;
    
    puntosText.setFont(font);
    descubiertasText.setFont(font);
    clockText.setFont(font);
    resultadoText.setFont(font);

    puntosText.setPosition(400,685);
    descubiertasText.setPosition(715,695);
    clockText.setPosition(30,695);
    resultadoText.setPosition(300,350);

    puntosText.setScale(1.5,1.5);
    descubiertasText.setScale(1.25,1.25);
    clockText.setScale(1.25,1.25);
    resultadoText.setScale(2,2);
}

void Interfaz::Update(){
    if(puntos>9) puntosText.setString(to_string(puntos));
    else puntosText.setString("0"+to_string(puntos));

    if(descubiertas>9) descubiertasText.setString(to_string(descubiertas)+"/12");
    else descubiertasText.setString("0"+to_string(descubiertas)+"/12");
    
    time=clock.getElapsedTime();
    if(descubiertas==12){
        resultadoText.setString("GANASTE");
        resultadoText.setFillColor(Color::Green);
    }else if((int)45-(int)time.asSeconds()<0){
        resultadoText.setString("PERDISTE");
        resultadoText.setFillColor(Color::Red);
    }else{
        if((int)45-(int)time.asSeconds()>9) clockText.setString(to_string((int)45-(int)time.asSeconds()));
        else clockText.setString("0"+to_string((int)45-(int)time.asSeconds()));
    }
}

// Implementar las funciones de puntajes y archivos
void Interfaz::LeerPuntajesDesdeArchivo() {
    puntajes.clear(); // Limpiar los puntajes actuales

    ifstream archivo("puntajes.txt");
    if (archivo.is_open()) {
        string nombre;
        int puntaje;

        while (archivo >> nombre >> puntaje) {
            puntajes.emplace_back(nombre, puntaje);
        }

        archivo.close();
    }
}

void Interfaz::GuardarPuntajesEnArchivo() const {
    ofstream archivo("puntajes.txt");
    if (archivo.is_open()) {
        // Ordenar puntajes antes de guardar solo los primeros 3
        sort(puntajes.begin(), puntajes.end());

        // Guardar solo los primeros 3 puntajes
        size_t limite = puntajes.size() < 3 ? puntajes.size() : 3;
        for (size_t i = 0; i < limite; ++i) {
            archivo << puntajes[i].ConsultarNombre() << " " << puntajes[i].ConsultarPuntaje() << "\n";
        }

        archivo.close();
    }
}

void Interfaz::CambiarPuntaje(int mod){
    puntos+=mod;
    puntos=max(puntos,0);
}

void Interfaz::CambiarDescubiertas(int mod){
    descubiertas+=mod;
}

int Interfaz::ConsultarDescubiertas(){
    return descubiertas;
}

int Interfaz::ConsultarTiempo(){
    time=clock.getElapsedTime();
    return (int)45-(int)time.asSeconds();
}

void Interfaz::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(puntosText,rs);
    rt.draw(descubiertasText,rs);
    rt.draw(clockText,rs);
    rt.draw(resultadoText,rs);
}
#ifndef TABLERO_H
#define TABLERO_H

#include <array>
#include <string> //para aTexto(), que devuelve el texto
using namespace std;

/**
 * @brief Representa un estado del 8-puzzle (un tablero de 3x3).
 *
 * Las fichas van del 1 al 8 y el espacio vacio lo representamos con un 0.
 * Las posiciones van de 0 a 8:
 *      0 1 2
 *      3 4 5
 *      6 7 8
 */

class Tablero
{
    public:
        static const int LADO = 3; //Numero de casillas por fila y columna
        static const int TOTAL_CASILLAS = 9; //Numero de casillas totales del tablero

        //Movimientos o Direcciones en las que se puede mover el hueco
        enum class Direccion
        {
            ARRIBA,
            ABAJO,
            IZQUIERDA,  
            DERECHA
        };

        //Creacion del tablero ya resuelto: 1 2 3 / 4 5 6 / 7 8 _
        Tablero();

        /**         
         * @brief Crea un tablero con los 9 valores dados.
         * @param valores Los numeros del 0 al 8, en orden por filas.
         * @throw invalid_argument si los valores no son validos.
         */
        explicit Tablero(const array <int, TOTAL_CASILLAS>& valores);

        /**         
         * @brief Verificacion de los valores que sean del 0 a 8 sin repetir.
         * @param valores Arreglo a revisar si son valores del 0 al 8 sin repetir.
         * @return true si es una configuracion valida.
         */
        static bool esConfiguracionValida(const array <int, TOTAL_CASILLAS> & valores);
        /**
         * @brief Devuelve el numero que hay en una posicion del tablero.
         * @param posicion Posicion del 0 a 8.
         * @return El numero de la casilla (0 si es el hueco).
         */
        int obtenerValor(int posicion) const; 

        /// Devuelve la posicion del 0 al 8 en la que esta el hueco
        int obtenerPosicionVacio() const; 

        /**
         * @brief Indica si el hueco puede moverse en una direccion sin salirse del tablero.
         * @param direccion  Direccion a revisar.
         * @return true si el movimiento es posible.
         */
        bool puedeMover(Direccion direccion) const;

        /**
         * @brief Mueve el hueco en una direccion (la ficha vecina ocupa su lugar).
         * @param direccion Direccion en la que va el hueco.
         * @return true si se movio, false si el movimiento no era posible.
        */
        bool mover(Direccion direccion);

        /**
         * @brief Indica si la ficha de una posicion esta pegada al hueco (sin diagonales).
         * @param posicion Posicion de la ficha del 0 al 8 
         * @return true si esta arriba, abajo, a la izquierda o a la derecha del hueco.
         */
        bool esAdyacenteAlVacio(int posicion) const;

        /**
         * @brief Mueve la ficha que se toco hacia el hueco, si esta pegada a el.
         * @param posicion Posicion de la ficha tocada.
         * @return true si la ficha se movio, false si no estaba pegada al hueco.
         */
        bool moverFichaEnPosicion(int posicion); 

        /// Dos tableros son iguales si tienen los mismos numeros en las mismas posiciones.
        bool operator==(const Tablero& otro) const;

        /// Devuelve el tablero como texto (el hueco se muestra como '_'), para imprimirlo.
        string aTexto() const;

    private:
        array <int, TOTAL_CASILLAS>  casillas_; //Los 9 numeros del tablero
        int posicionVacio_;                     //Posicion del 0 al 8 del hueco
};
    
#endif
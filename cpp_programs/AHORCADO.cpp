#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <string>
using namespace std;

class Ahorcado {
	
private:
    string palabras[20] = {
        "perro", "gato", "casa", "arbol", "pelota",
        "coche", "libro", "computadora", "playa", "valle",
        "sol", "luna", "estrella", "nube", "rio",
        "mar", "ciudad", "avion", "tren", "bicicleta"
    };
public:
    int indice;
    string palabraSistema;

    // Constructor
    Ahorcado() 
	{
    	int in = 0 + rand() % (21 - 0);
    	
        this->indice = in;
        this->palabraSistema = palabras[indice];
        cout << endl << "Inicializando datos..." << endl;
        
        sleep(2);
        system("cls");
    }

    // Destructor
    ~Ahorcado() { cout << endl << "Eliminando datos..." << endl; }

    friend ostream& operator<<(ostream& os, const Ahorcado& ahorcado) {
        os << endl << "La palabra era: " << ahorcado.palabraSistema << endl;
        return os;
    }
};

class Juego : public Ahorcado {
	
private:
    string palabraUsuario;
    char letra;
    int vidas;
    list<char> letrasAdivinadas;
    list<char> letrasErroneas;

public:
    // Constructor
    Juego() 
	{
        vidas = 5;
        letrasAdivinadas.clear(); 
        letrasErroneas.clear(); 
        
        for (int i = 0; i < palabraSistema.length(); i++)
        	palabraUsuario += "_";	
    }
    
    void inicio()
	{
		cout << "=============\n";
		cout << "AHORCADO ESPECIAL \n";
		cout << "=============\n";
		cout << "Instrucciones: No dejes que los aliens abduzcan al monito, adivina la palabra.\n";
	}

    // Método para que el usuario adivine una letra
    char adivinaLetra() 
	{
        char intento;
        cout << endl << "Ingresa una letra: ";
        cin >> intento;
        this->letra = intento;
        return intento;
    }

    // Método para verificar si la letra adivinada está en la palabra
    void verificarLetra(char let) 
	{
        bool acierto = false;
        for (int i = 0; i < palabraSistema.length(); i++) 
		{
            if (let == palabraSistema[i]) 
			{
                palabraUsuario[i] = let; 
                letrasAdivinadas.push_back(let); 
                acierto = true;
            }
        }
        if (!acierto) 
		{
            letrasErroneas.push_back(let); 
            vidas--; 
        }
    }

    // Método para imprimir el estado actual del juego
    void imprimirEstado() 
	{
    	cout << endl << "Letras incorrectas: " << endl;
        for (auto it = letrasErroneas.begin(); it != letrasErroneas.end(); ++it) 
		{
            cout << *it << " ";
        }
        cout << endl << "Vidas: " << vidas << endl;
        cout << endl << "Palabra a adivinar: " << endl;
        
        for (int i = 0; i < palabraUsuario.length(); i++)
        	cout << palabraUsuario[i] << " ";
    }

    // Método para comprobar si el juego ha terminado
    bool juegoTerminado() 
	{
        return (vidas == 0 || palabraUsuario == palabraSistema);
    }
    
    void final()
	{
		if (Ahorcado::palabraSistema == palabraUsuario)
			cout << endl << "Lo lograste! Salvaste al monito" << endl;
		else
			cout << endl << "No pudiste salvar al monito :c " << endl; 
	}
	
	void mostrarAhorcado ()
	{
	    if (this->vidas == 5)
	    {
	        cout << "                  .                           \n";
	        cout << "                  |                           \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    '-----------..  \n";
	        cout << "              /     \\        (  AYUDAAAAA! )  \n";
	        cout << "             /   0   \\      / '-----------'   \n";
	        cout << "            /  --|--  \\    /                  \n";
	        cout << "           /     |     \\                      \n";
	        cout << "          /     / \\     \\                     \n";
	        cout << "         /               \\                    \n";
	    }
	    else if (this->vidas == 4)
	    {
	        cout << "                 .                            \n";
	        cout << "                 |                            \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    ,-----------..  \n";
	        cout << "              /  0  \\        (  AYUDAAAAA! )  \n";
	        cout << "             / --|-- \\      / `-----------'   \n";
	        cout << "            /    |    \\    /                  \n";
	        cout << "           /    / \\    \\                      \n";
	        cout << "          /             \\                     \n";
	        cout << "         /               \\                    \n";
	    }
	    else if (this->vidas == 3)
	    {
	        cout << "                 .                            \n";
	        cout << "                 |                            \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    ,-----------..  \n";
	        cout << "              /--|--\\        (  AYUDAAAAA! ) \n";
	        cout << "             /   |   \\      / `-----------'  \n";
	        cout << "            /   / \\   \\    /                 \n";
	        cout << "           /           \\                     \n";
	        cout << "          /             \\                    \n";
	        cout << "         /               \\                   \n";
	    }
	    else if (this->vidas == 2)
	    {
	        cout << "                 .                            \n";
	        cout << "                 |                            \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    ,-----------..  \n";
	        cout << "              /  |  \\        (  AYUDAAAAA! ) \n";
	        cout << "             /  / \\  \\      / `-----------'  \n";
	        cout << "            /         \\    /                 \n";
	        cout << "           /           \\                     \n";
	        cout << "          /             \\                    \n";
	        cout << "         /               \\                   \n";
	    }
	    else if (this->vidas == 1)
	    {
	        cout << "                 .                            \n";
	        cout << "                 |                            \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    ,-----------..  \n";
	        cout << "              / / \\ \\        (  AYUDAAAAA! ) \n";
	        cout << "             /       \\      / `-----------'  \n";
	        cout << "            /         \\    /                 \n";
	        cout << "           /           \\                     \n";
	        cout << "          /             \\                    \n";
	        cout << "         /               \\                   \n";
	    }
	    else if (this->vidas == 0)
	    {
	        cout << "                 .                            \n";
	        cout << "                 |                            \n";
	        cout << "              .-\"^\"-.                       \n";
	        cout << "             /_....._\\                       \n";
	        cout << "         .-\"`         `\"-.                  \n";
	        cout << "        (  ooo  ooo  ooo  )                   \n";
	        cout << "         '-.,_________,.-'    ,-----------..  \n";
	        cout << "              /     \\        (     :(      ) \n";
	        cout << "             /       \\      / `-----------'  \n";
	        cout << "            /         \\    /                 \n";
	        cout << "           /           \\                     \n";
	        cout << "          /             \\                    \n";
	        cout << "         /               \\                   \n";
	    }
	}

};

int main() {
	srand(time(NULL));
    int opc = 1;

    while (opc == 1) {
        Juego juego;

        while (!juego.juegoTerminado()) 
		{
        	system("cls");
        	
        	juego.inicio();
            juego.mostrarAhorcado(); 
            juego.imprimirEstado(); 
            char letra = juego.adivinaLetra(); 
            juego.verificarLetra(letra); 
        }
		
		if (juego.juegoTerminado())
		{
			system("cls");
			
			juego.inicio();
            juego.mostrarAhorcado(); 
            juego.imprimirEstado(); 
		}
		
        juego.final();
        cout << juego << endl;
		cin.ignore();
        cout << "Desea jugar de nuevo? (1 = Si, 0 = No): ";
        cin >> opc;
    }

    return 0;
}

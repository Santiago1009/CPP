/*
    Leslie Lucero Franco Calleros 223053
    Anna Lizbeth Barajas Sandoval 222835
    Santiago Mendivil Alvarez 226129

    Justificacion de uso de la libreria algorithm:
        En este programa se usa en varias ocasiones el metodo "find" de la libreria algorithm, esto
        con el proposito de simplificar la busqueda de ocurrencias de un elemento especificado por
        usuario en lugar de recorrer manualmente los vectores utilizados, ya que garantiza un rendimiento
        optimo y ayuda a hacer la busqueda mas facil.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct nodo
{
    nodo *siguiente;
    nodo *anterior;
    nodo *inicio;
    string proceso;

    // Atributos de la tarjeta de debito
    float debitoSaldo;
    float debitoSaldoGeneral = 3500;

    // Atributos de la tarjeta de credito
    float creditoDisponible = 7500;
    float creditoPagar = 2500;
    float creditoLimite = 10000;
    float creditoSaldo;
};
typedef struct nodo *LD;

LD crearListaDoble()
{
    /* Crea la lista doble */
    LD lista = new nodo;
    lista->inicio = NULL;
    return lista;
}

LD crearNodo()
{
    LD Nodo = new nodo;
    Nodo->proceso = "";
    Nodo->siguiente = NULL;
    Nodo->anterior = NULL;
    // Inicializa la tarjeta de debito
    Nodo->debitoSaldo = 0.0;
    Nodo->debitoSaldoGeneral = 3500;

    // Inicializa la tarjeta de credito
    Nodo->creditoDisponible = 7500;
    Nodo->creditoPagar = 2500;
    Nodo->creditoLimite = 10000;
    Nodo->creditoSaldo = 0.0;

    return Nodo;
}

/* ---------- TARJETA DE DEBITO ---------- */
void insertarFinal(LD &lista, LD nuevo_nodo)
{
    /* Funcion para insertar nuevos nodos al final de la lista */
    LD aux = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = nuevo_nodo;
    }
    else
    {
        aux = lista->inicio;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = aux;
    }
}

void consultaDebito(LD &lista)
{
    /* Funcion para insertar consultas en la lista Debito */
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Consulta";
    if (aux == NULL)
    {
        auxNodo->debitoSaldoGeneral = 3500;
        auxNodo->debitoSaldo = 3500;
        cout << endl
             << "Saldo actual: " << auxNodo->debitoSaldo;
        insertarFinal(lista, auxNodo);
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        auxNodo->debitoSaldoGeneral = aux->debitoSaldoGeneral;
        auxNodo->debitoSaldo = auxNodo->debitoSaldoGeneral;
        cout << endl
             << "Saldo actual: " << auxNodo->debitoSaldo;
        insertarFinal(lista, auxNodo);
    }
}

void depositoDebito(LD &lista)
{
    /* Funcion para insertar depositos en la lista Debito */
    float cantidad;
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Deposito";

    cout << endl
         << "Ingresa la cantidad a depositar: ";
    cin >> cantidad;

    while (cantidad <= 0)
    {
        cout << endl
             << "ERROR. Ingrese una cantidad valida: ";
        cin >> cantidad;
    }
    if (aux == NULL)
    {
        auxNodo->debitoSaldoGeneral = 3500;
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        auxNodo->debitoSaldoGeneral = aux->debitoSaldoGeneral;
    }
    auxNodo->debitoSaldoGeneral += cantidad;
    auxNodo->debitoSaldo = cantidad;
    insertarFinal(lista, auxNodo);
}

void retiroDebito(LD &lista)
{
    /* Funcion para insertar retiros en la lista Debito */
    int cantidad;
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Retiro";
    if (aux == NULL)
    {
        auxNodo->debitoSaldoGeneral = 3500;
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        auxNodo->debitoSaldoGeneral = aux->debitoSaldoGeneral;
    }

    cout << endl
         << "Ingresa la cantidad a retirar: ";
    cin >> cantidad;
    while (cantidad % 50 != 0 || cantidad <= 0 || cantidad > auxNodo->debitoSaldoGeneral)
    {
        if (cantidad > auxNodo->debitoSaldoGeneral)
        {
            cout << endl
                 << "ERROR. La cantidad es mayor al saldo disponible, intente de nuevo: ";
            cin >> cantidad;
        }

        if (cantidad % 50 != 0)
        {
            cout << endl
                 << "ERROR. La cantidad debe ser multiplo de 50, intente de nuevo: ";
            cin >> cantidad;
        }

        if (cantidad <= 0)
        {
            cout << endl
                 << "ERROR. La cantidad debe ser mayor a 0, intente de nuevo: ";
            cin >> cantidad;
        }
    }
    auxNodo->debitoSaldoGeneral -= cantidad;
    auxNodo->debitoSaldo = cantidad;
    insertarFinal(lista, auxNodo);
}

void historialDebito(LD lista)
{
    /* Funcion para mostrar el historial de acciones de Debito */
    LD aux = lista->inicio;
    if (aux == NULL)
    {
        cout << endl
             << "Historial vacio..." << endl;
    }
    else
    {
        cout << endl
             << "Historial";
        while (aux != NULL)
        {
            cout << endl
                 << "| " << aux->proceso;
            cout << " $" << aux->debitoSaldo << " | ";
            aux = aux->siguiente;
        }
    }
}

/* ---------- TARJETA DE CREDITO ---------- */
void consultaCredito(LD &lista)
{
    /* Funcion para insertar consultas en la lista Credito  */
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Consulta";
    if (aux == NULL)
    {
        auxNodo->creditoDisponible = 7500;
        auxNodo->creditoPagar = 2500;
        auxNodo->creditoLimite = 10000;
        cout << endl
             << "Saldo total: " << auxNodo->creditoLimite;
        cout << endl
             << "Saldo disponible: " << auxNodo->creditoDisponible;
        cout << endl
             << "Saldo a pagar: " << auxNodo->creditoPagar;
        insertarFinal(lista, auxNodo);
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        auxNodo->creditoLimite = aux->creditoLimite;
        auxNodo->creditoDisponible = aux->creditoDisponible;
        auxNodo->creditoPagar = aux->creditoPagar;
        cout << endl
             << "Saldo total: " << auxNodo->creditoLimite;
        cout << endl
             << "Saldo disponible: " << auxNodo->creditoDisponible;
        cout << endl
             << "Saldo a pagar: " << auxNodo->creditoPagar;
        insertarFinal(lista, auxNodo);
    }
}
void pagarCredito(LD &lista)
{
    /* Funcion para insertar pagos en la lista Credito */
    int cantidad;
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Pago";

    if (aux == NULL)
    {
        auxNodo->creditoDisponible = 7500;
        auxNodo->creditoPagar = 2500;
        auxNodo->creditoLimite = 10000;
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        auxNodo->creditoDisponible = aux->creditoDisponible;
        auxNodo->creditoPagar = aux->creditoPagar;
        auxNodo->creditoLimite = aux->creditoLimite;
    }

    if (auxNodo->creditoPagar == 0)
    {
        cout << endl
             << "No hay credito a pagar";
        cantidad = 0;
    }
    else
    {
        cout << endl
             << "Ingresa la cantidad a pagar: ";
        cin >> cantidad;
        while (cantidad <= 0 || cantidad > auxNodo->creditoPagar)
        {
            if (cantidad > auxNodo->creditoPagar)
            {
                cout << endl
                     << "ERROR. La cantidad es mayor al credito a pagar, intente de nuevo: ";
                cin >> cantidad;
            }

            if (cantidad <= 0)
            {
                cout << endl
                     << "ERROR. La cantidad debe ser mayor a 0, intente de nuevo: ";
                cin >> cantidad;
            }
        }
    }

    auxNodo->creditoDisponible += cantidad;
    auxNodo->creditoPagar -= cantidad;
    auxNodo->creditoSaldo = cantidad;
    insertarFinal(lista, auxNodo);
}

void gastarCredito(LD lista)
{
    /* Funcion para insertar gastos en la lista Credito */
    int cantidad, opc, sobregiro;
    LD aux = lista->inicio;
    LD auxNodo = crearNodo();
    auxNodo->proceso = "Gasto";
    if (aux == NULL)
    {
        auxNodo->creditoDisponible = 7500;
        auxNodo->creditoPagar = 2500;
        auxNodo->creditoLimite = 10000;
    }
    else
    {
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        auxNodo->creditoDisponible = aux->creditoDisponible;
        auxNodo->creditoPagar = aux->creditoPagar;
        auxNodo->creditoLimite = aux->creditoLimite;
    }

    if (auxNodo->creditoDisponible <= 0)
    {
        sobregiro = auxNodo->creditoDisponible;
        sobregiro = (sobregiro * -1) + 1;
        cout << endl
             << "Tarjeta sobregirada - para usarla debe de pagar : $ " << sobregiro;
        cantidad = 0;
    }
    else
    {
        cout << endl
             << "Ingresa la cantidad a gastar: ";
        cin >> cantidad;
        while (cantidad <= 0 || cantidad > 10000)
        {
            if (cantidad <= 0)
                cout << endl
                     << "ERROR. La cantidad debe ser mayor a 0, intente de nuevo: ";
            cin >> cantidad;
            if (cantidad > 10000)
                cout << endl
                     << "ERROR. La cantidad debe ser menor a 10000, intente de nuevo: ";
            cin >> cantidad;
        }

        if (cantidad > auxNodo->creditoDisponible)
        {
            cout << endl
                 << "ADVERTENCIA. Se generara un sobregiro en la tarjeta."
                 << endl
                 << "Autoriza la compra (Si = 1, No = 0): ";
            cin >> opc;
            if (opc == 1)
            {
                cout << endl
                     << "Debe de pagar el sobregiro para volver a usar la tarjeta de credito";
            }
            else
            {
                cout << endl
                     << "Regresando al menu...";
                cantidad = 0.0;
            }
        }
    }

    auxNodo->creditoDisponible -= cantidad;
    auxNodo->creditoPagar += cantidad;
    auxNodo->creditoSaldo = cantidad;
    insertarFinal(lista, auxNodo);
}

void historialCredito(LD lista)
{
    /* Funcion para mostrar el historial de acciones de Credito */
    LD aux = lista->inicio;
    if (aux == NULL)
    {
        cout << endl
             << "Historial vacio..." << endl;
    }
    else
    {
        cout << endl
             << "Historial";
        while (aux != NULL)
        {
            cout << endl
                 << "| " << aux->proceso;
            if (aux->proceso == "Consulta")
            {
                cout << " Saldo total: $" << aux->creditoLimite
                     << "  Saldo disponible: $" << aux->creditoDisponible
                     << "  Saldo a pagar: $" << aux->creditoPagar << " | ";
            }
            else
            {
                cout << " $" << aux->creditoSaldo << " | ";
            }
            aux = aux->siguiente;
        }
    }
}

/* ---------- SECCION DE ELIMINAR REGISTROS ---------- */
inline bool buscarRegistros(LD lista, string registro)
{
    LD aux = lista->inicio;

    if (aux == NULL)
    {
        cout << endl
             << "No hay registros" << endl;
        return false;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->proceso == registro)
                return true;

            aux = aux->siguiente;
        }
    }
    return false;
}

void eliminarNodoIndividual(LD &lista, int posicion)
{
    /* Eliminacion de nodos segun la posicion que se indique - */
    LD aux = lista->inicio;
    LD anterior = NULL;

    for (int i = 1; i < posicion && aux != NULL; i++)
    {
        anterior = aux;
        aux = aux->siguiente;
    }

    if (aux == NULL)
    {
        cout << "No existe dicho numero de registro." << endl;
        return;
    }

    // Caso especial: si el nodo a eliminar es el primero
    if (anterior == NULL)
    {
        lista->inicio = aux->siguiente;
    }
    else
    {
        anterior->siguiente = aux->siguiente;
    }

    // Liberar la memoria del nodo eliminado
    delete aux;
}

void eliminarNodoGrupal(LD &lista, LD nodo)
{
    /* Funcion para eliminar nodos en la lista - Funcion especial para la eliminacion grupal (Variacion de eliminar nodo individual que acepta dos listas)*/
    LD aux = lista;

    if (nodo == aux->inicio)
    {
        aux->inicio = nodo->siguiente;
    }

    if (nodo->siguiente != NULL)
    {
        nodo->siguiente->anterior = nodo->anterior;
    }

    if (nodo->anterior != NULL)
    {
        nodo->anterior->siguiente = nodo->siguiente;
    }

    // Liberar la memoria del nodo
    delete nodo;
}

void eliminarConsultas(LD lista, int tipo_tarjeta)
{
    /* Funcion para eliminar consultas de la lista pasada por parametro en la funcion eliminarIndividual() */
    int posicion = 1, opc;
    vector<int> posiciones = {};

    LD aux = lista->inicio;

    if (aux == NULL)
    {
        cout << endl
             << "No hay consultas por eliminar. ";
        return;
    }
    else if (buscarRegistros(lista, "Consulta"))
    {
        // Tarjeta de debito
        if (tipo_tarjeta == 1)
        {
            cout << endl
                 << "Eliminacion de consultas | Tarjeta de debito" << endl;
            while (aux != NULL)
            {
                if (aux->proceso == "Consulta")
                {
                    cout << endl
                         << "[" << posicion
                         << "] Consulta con total de: " << aux->debitoSaldoGeneral
                         << endl;
                    posiciones.push_back(posicion);
                }
                posicion++;
                aux = aux->siguiente;
            }
        }
        // Tarjeta de credito
        else if (tipo_tarjeta == 2)
        {
            cout << endl
                 << "Eliminacion de consultas | Tarjeta de credito" << endl;
            while (aux != NULL)
            {
                if (aux->proceso == "Consulta")
                {
                    cout << endl
                         << "[" << posicion << "] Consulta con: "
                         << "\tCredito disponible: " << aux->creditoDisponible
                         << "\t\tCredito a pagar: " << aux->creditoPagar
                         << endl;

                    posiciones.push_back(posicion);
                }
                posicion++;
                aux = aux->siguiente;
            }
        }
        cout << endl
             << "Ingrese el numero de la consulta a eliminar: ";
        cin >> opc;

        // Verificar si la opcion ingresada esta en el vector de posiciones
        if (find(posiciones.begin(), posiciones.end(), opc) != posiciones.end())
        {
            eliminarNodoIndividual(lista, opc);
            cout << "Eliminado correctamente. ";
        }
        else
        {
            cout << "No existe dicha consulta, vuelve intentarlo.";
            return;
        }
    }
    else
    {
        cout << endl
             << "No hay consultas por eliminar." << endl;
        return;
    }
}

void eliminarRegistrosIndividuales(LD lista, string opc)
{
    /* Eliminacion de registros (No consultas) del tipo de tarjeta pasada por parametro en la funcion eliminarIndividual() */
    float monto;
    int posicion = 1, num;
    vector<int> posiciones = {};

    LD aux = lista->inicio;
    if (aux == NULL)
    {
        cout << endl
             << "No hay registros por eliminar.";
        return;
    }
    else if (buscarRegistros(lista, opc))
    {
        cout << endl
             << "Digite el monto del " << opc << ": ";
        cin >> monto;
        while (aux != NULL)
        {
            if ((opc == "Deposito" && aux->proceso == "Deposito" && aux->debitoSaldo == monto) ||
                (opc == "Retiro" && aux->proceso == "Retiro" && aux->debitoSaldo == monto) ||
                (opc == "Gasto" && aux->proceso == "Gasto" && aux->creditoSaldo == monto) ||
                (opc == "Pago" && aux->proceso == "Pago" && aux->creditoSaldo == monto))
            {
                if (opc == "Deposito" || opc == "Retiro")
                {
                    posiciones.push_back(posicion);
                    cout << endl
                         << "[" << posicion << "] " << opc << " de: " << aux->debitoSaldo;
                }
                else if (opc == "Gasto" || opc == "Pago")
                {
                    posiciones.push_back(posicion);
                    cout << endl
                         << "[" << posicion << "] " << opc << " de: " << aux->creditoSaldo;
                }
            }
            posicion++;
            aux = aux->siguiente;
        }
        if (posiciones.empty())
        {
            cout << "No hay " << opc << "s con el monto ingresado." << endl;
            return;
        }

        cout << endl
             << "Ingrese el numero del registro a eliminar: ";
        cin >> num;

        if (find(posiciones.begin(), posiciones.end(), num) != posiciones.end())
        {
            eliminarNodoIndividual(lista, num);
            cout << "Eliminado correctamente.";
        }
        else
        {
            cout << "No existe dicho registro, vuelve a intentarlo." << endl;
            return;
        }
    }
    else
    {
        cout << endl
             << "No hay registros de " << opc << " por eliminar." << endl;
    }
}

void eliminarIndividual(LD &lista, int tipo_tarjeta)
{
    /* Eliminacion individual teniendo en cuenta un nodo especifico en la tarjeta pasada por parametro en main() */
    string opc_proceso;
    float monto;
    int consulta_eliminar, registro_deposito_eliminar, pago_gasto_eliminar;

    LD aux = lista->inicio;

    if (aux == NULL)
    {
        cout << endl
             << "No hay registros por eliminar." << endl;
        return;
    }
    else
    {
        if (tipo_tarjeta == 1) // Debito - Terminado
        {
            system("cls");
            cout << endl
                 << "De las siguientes opciones: | Consulta - Deposito - Retiro |"
                 << endl
                 << "Escriba el nombre del proceso a eliminar: ";

            cin.ignore();
            getline(cin, opc_proceso);

            if (!opc_proceso.empty()) // Convierte la primera letra del proceso a mayuscula
                opc_proceso[0] = toupper(opc_proceso[0]);

            if (opc_proceso == "Consulta")
                eliminarConsultas(lista, tipo_tarjeta);
            else if (opc_proceso == "Deposito" || opc_proceso == "Retiro")
                eliminarRegistrosIndividuales(lista, opc_proceso);
            else
                cout << endl
                     << "Proceso invalido..." << endl;
        }
        else if (tipo_tarjeta == 2) // Credito - Proceso
        {
            system("cls");
            cout << endl
                 << "De las siguientes opciones: | Consulta - Pago - Gasto |"
                 << endl
                 << "Escriba el nombre del proceso a eliminar: ";

            cin.ignore();
            getline(cin, opc_proceso);

            if (!opc_proceso.empty()) // Convierte la primera letra del proceso a mayuscula
                opc_proceso[0] = toupper(opc_proceso[0]);

            /* Agregar la funcionalidad de eliminar segun el pago y el gasto */
            if (opc_proceso == "Consulta")
                eliminarConsultas(lista, tipo_tarjeta);
            else if (opc_proceso == "Pago" || opc_proceso == "Gasto")
                eliminarRegistrosIndividuales(lista, opc_proceso);
            else
                cout << endl
                     << "Proceso invalido..." << endl;
        }
    }
}

void eliminarRegistros(LD &lista, string proceso)
{
    /* Funcion que se encarga de eliminar todos los registros de un proceso indicado en la funcion eliminarGrupal() */
    LD actual = lista->inicio;
    while (actual != NULL)
    {
        LD siguiente = actual->siguiente;

        if (actual->proceso == proceso)
        {
            eliminarNodoGrupal(lista, actual);
        }
        actual = siguiente;
    }
}

void eliminarGrupal(LD &lista, int tipo_tarjeta)
{
    /* Funcion para eliminar de manera grupal un proceso en la tarjeta especificada por parametros en main() */
    int respuesta;
    string opc_proceso;
    LD aux = lista->inicio;

    if (aux == NULL)
    {
        cout << endl
             << "No hay registros por eliminar." << endl;
        return;
    }
    else
    {
        if (tipo_tarjeta == 1) // Debito - Terminado
        {
            system("cls");
            cout << endl
                 << "De las siguientes opciones: | Consulta - Deposito - Retiro |"
                 << endl
                 << "Escriba el nombre del proceso a eliminar: ";

            cin.ignore();
            getline(cin, opc_proceso);

            if (!opc_proceso.empty()) // Convierte la primera letra del proceso a mayuscula
                opc_proceso[0] = toupper(opc_proceso[0]);

            if (opc_proceso != "Consulta" && opc_proceso != "Deposito" && opc_proceso != "Retiro")
            {
                cout << endl
                     << "Proceso invalido." << endl;
                return;
            }

            if (buscarRegistros(lista, opc_proceso))
            {
                cout << endl
                     << "Esta seguro de eliminar todos los registros de " << opc_proceso << " (1=Si / 0=No): ";
                cin >> respuesta;
                if (respuesta == 1)
                    eliminarRegistros(lista, opc_proceso);
                else if (respuesta == 0)
                {
                    cout << endl
                         << "Volviendo al menu..." << endl;
                    return;
                }
                else
                {
                    cout << endl
                         << "Respuesta invalida" << endl;
                    return;
                }
            }
        }
        else if (tipo_tarjeta == 2) // Credito - Terminado
        {
            system("cls");
            cout << endl
                 << "De las siguientes opciones: | Consulta - Pago - Gasto |"
                 << endl
                 << "Escriba el nombre del proceso a eliminar: ";

            cin.ignore();
            getline(cin, opc_proceso);

            if (!opc_proceso.empty()) // Convierte la primera letra del proceso a mayuscula
                opc_proceso[0] = toupper(opc_proceso[0]);

            if (opc_proceso != "Consulta" && opc_proceso != "Pago" && opc_proceso != "Gasto")
            {
                cout << endl
                     << "Proceso invalido." << endl;
                return;
            }

            if (buscarRegistros(lista, opc_proceso))
            {
                cout << endl
                     << "Esta seguro de eliminar todos los registros de " << opc_proceso << " (1=Si / 0=No): ";
                cin >> respuesta;
                if (respuesta == 1)
                    eliminarRegistros(lista, opc_proceso);
                else if (respuesta == 0)
                {
                    cout << endl
                         << "Volviendo al menu..." << endl;
                    return;
                }
                else
                {
                    cout << endl
                         << "Respuesta invalida" << endl;
                    return;
                }
            }
            else
            {
                cout << endl
                     << "No hay registros de " << opc_proceso << " por eliminar." << endl;
                return;
            }
        }
    }
}

/* ---------- MAIN ---------- */

int main()
{
    int opc, opcDebito, opcCredito, opcEliminacion, tipo_tarjeta;
    string proceso_eliminar;
    float cantidad_eliminar;
    LD listaDebito = crearListaDoble();
    LD listaCredito = crearListaDoble();

    do
    {
        system("cls");
        cout << endl
             << "***Menu***"
             << endl
             << "Elija la tarjeta a utilizar"
             << endl
             << "1. Debito"
             << endl
             << "2. Credito "
             << endl
             << "0. Salir "
             << endl
             << "Opcion: ";
        cin >> opc;

        if (opc == 1)
        {
            // Tarjeta de debito
            tipo_tarjeta = 1; // Valor para distinguir acciones en la eliminacion de procesos
            do
            {
                system("cls");
                cout << endl
                     << "***Tarjeta de debito***"
                     << endl
                     << "1. Consulta"
                     << endl
                     << "2. Deposito"
                     << endl
                     << "3. Retiro"
                     << endl
                     << "4. Historial"
                     << endl
                     << "5. Eliminar"
                     << endl
                     << "0. Salir"
                     << endl
                     << "Opcion: ";
                cin >> opcDebito;
                switch (opcDebito)
                {
                case 0:
                    cout << endl
                         << "Saliendo de cuenta de debito..." << endl;
                    break;

                default:
                    cout << endl
                         << "Opcion invalida" << endl;
                    cout << endl;
                    system("pause");
                    break;

                case 1:
                    consultaDebito(listaDebito);
                    cout << endl;
                    system("pause");
                    break;

                case 2:
                    depositoDebito(listaDebito);
                    cout << endl;
                    system("pause");
                    break;

                case 3:
                    retiroDebito(listaDebito);
                    cout << endl;
                    system("pause");
                    break;

                case 4:
                    historialDebito(listaDebito);
                    cout << endl;
                    system("pause");
                    break;

                case 5:
                    cout << endl
                         << "Elija una forma de eliminacion de las siguientes opciones"
                         << endl
                         << "1. Individual"
                         << endl
                         << "2. Grupal"
                         << endl
                         << "Opcion: ";
                    cin >> opcEliminacion;

                    if (opcEliminacion == 1)
                    {
                        eliminarIndividual(listaDebito, tipo_tarjeta);
                    }
                    else if (opcEliminacion == 2)
                    {
                        eliminarGrupal(listaDebito, tipo_tarjeta);
                    }

                    cout << endl;
                    system("pause");
                    break;
                }
            } while (opcDebito != 0);
        }
        else if (opc == 2)
        {
            // Tarjeta de credito
            tipo_tarjeta = 2; // Valor para distinguir acciones en la eliminacion de procesos
            do
            {
                system("cls");
                cout << endl
                     << "***Tarjeta de Credito***"
                     << endl
                     << "1. Consulta"
                     << endl
                     << "2. Pagar"
                     << endl
                     << "3. Gastar"
                     << endl
                     << "4. Historial"
                     << endl
                     << "5. Eliminar"
                     << endl
                     << "0. Salir"
                     << endl
                     << "Opcion: ";
                cin >> opcCredito;

                switch (opcCredito)
                {
                case 0:
                    cout << endl
                         << "Saliendo de cuenta de credito..." << endl;
                    break;

                default:
                    cout << endl
                         << "Opcion invalida" << endl;
                    cout << endl;
                    system("pause");
                    break;

                case 1:
                    consultaCredito(listaCredito);
                    cout << endl;
                    system("pause");
                    break;

                case 2:
                    pagarCredito(listaCredito);
                    cout << endl;
                    system("pause");
                    break;

                case 3:
                    gastarCredito(listaCredito);
                    cout << endl;
                    system("pause");
                    break;

                case 4:
                    historialCredito(listaCredito);
                    cout << endl;
                    system("pause");
                    break;

                case 5:
                    cout << endl
                         << "Elija una forma de eliminacion de las siguientes opciones"
                         << endl
                         << "1. Individual"
                         << endl
                         << "2. Grupal"
                         << endl
                         << "Opcion: ";
                    cin >> opcEliminacion;
                    cout << endl;

                    if (opcEliminacion == 1)
                    {
                        eliminarIndividual(listaCredito, tipo_tarjeta);
                    }
                    else if (opcEliminacion == 2)
                    {
                        eliminarGrupal(listaCredito, tipo_tarjeta);
                    }

                    cout << endl;
                    system("pause");
                    break;
                }
            } while (opcCredito != 0);
        }
        else if (opc == 0)
        {
            cout << endl
                 << "Saliendo del cajero..." << endl;
        }
        else
        {
            cout << endl
                 << "Opcion invalida, intente de nuevo. " << endl;
        }

    } while (opc != 0);

    return 0;
}

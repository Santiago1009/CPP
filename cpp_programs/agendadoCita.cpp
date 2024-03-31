/*
    Integrantes:
        Leslie Lucero Franco Calleros 223053
        Santiago Mendivil Alvarez 226129
*/

#include <iostream>
#include <vector>
using namespace std;

bool fecha_validada = false;

class Fecha
{
private:
    int aa, mm, dd;
    string mes;

public:
    Fecha()
    {
        aa = 0;
        mm = 0;
        dd = 0;
        mes = "";
    }
    friend class Empleado;
    bool verificar_aa(int aa)
    {
        if (aa < 1950)
            return false;

        this->aa = aa;
        return true;
    }
    bool verificar_mm(int mm)
    {
        if (mm < 1 || mm > 12)
            return false;

        this->mm = mm;
        return true;
    }

    bool verificar_mm(string mes)
    {
        string meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

        for (int i = 0; i < 12; i++)
        {
            if (mes == meses[i])
            {
                this->mes = mes;
                return true;
            }
        }
        return false;
    }
    bool verificar_dd(int dd)
    {
        int bisiesto;
        if (this->mm == 1 || this->mm == 3 || this->mm == 5 || this->mm == 7 || this->mm == 8 ||
            this->mm == 10 || this->mm == 12 || this->mes == "enero" || this->mes == "marzo" ||
            this->mes == "mayo" || this->mes == "julio" || this->mes == "agosto" || this->mes == "octubre" ||
            this->mes == "diciembre")
        {
            if (dd < 1 || dd > 31)
            {
                return false;
            }
            else
            {
                this->dd = dd;
                return true;
            }
        }
        else if (this->mm == 4 || this->mm == 6 || this->mm == 9 || this->mm == 11 ||
                 this->mes == "abril" || this->mes == "junio" || this->mes == "septiembre" ||
                 this->mes == "noviembre")
        {
            if (dd < 1 || dd > 30)
            {
                return false;
            }
            else
            {
                this->dd = dd;
                return true;
            }
        }
        else if (this->mm == 2 || this->mes == "febrero")
        {
            cout << "El anio es bisiesto: Seleccione una opcion (1=Si / 0=No): ";
            cin >> bisiesto;

            if (bisiesto == 1)
            {
                if (dd < 1 || dd > 29)
                {
                    return false;
                }
                else
                {
                    this->dd = dd;
                    return true;
                }
            }
            else
            {
                if (dd < 1 || dd > 28)
                {
                    return false;
                }
                else
                {
                    this->dd = dd;
                    return true;
                }
            }
        }
        return false;
    }
    void imprimir_fecha()
    {

        if (mes != "")
        {
            if (mes == "enero")
                mm = 1;
            else if (mes == "febrero")
                mm = 2;
            else if (mes == "marzo")
                mm = 3;
            else if (mes == "abril")
                mm = 4;
            else if (mes == "mayo")
                mm = 5;
            else if (mes == "junio")
                mm = 6;
            else if (mes == "julio")
                mm = 7;
            else if (mes == "agosto")
                mm = 8;
            else if (mes == "septiembre")
                mm = 9;
            else if (mes == "octubre")
                mm = 10;
            else if (mes == "noviembre")
                mm = 11;
            else if (mes == "diciembre")
                mm = 12;
        }

        cout << aa << "/" << mm << "/" << dd << endl;
    }
};

class Empleado
{
private:
    Fecha fechaNacimiento;
    Fecha fechaContratacion;

public:
    string nombre;
    string apellidos;

    void _fechaNacimiento()
    {
        int aa, mm, dd;
        string month;

        // Año de nacimiento
        cout << endl
             << "Ingrese el anio de nacimiento: ";
        cin >> aa;

        if (fechaNacimiento.verificar_aa(aa))
            cout << endl;
        else
        {
            cout << "Anio invalido, intente de nuevo" << endl;
            return;
        }

        // Mes de nacimiento
        cout << "Ingrese el mes de nacimiento: ";
        cin >> month;

        if (!fechaNacimiento.verificar_mm(month))
        {
            // Intentar convertir a entero para saber si usar la función de enteros
            try
            {
                mm = stoi(month);
                if (!fechaNacimiento.verificar_mm(mm))
                {
                    cout << "Mes invalido, intente de nuevo." << endl;
                    return;
                }
            }
            catch (const invalid_argument &e)
            {
                cout << "Mes invalido, intente de nuevo." << endl;
                return;
            }
        }
        cout << endl;

        // Dia de nacimiento
        cout << "Ingrese el dia de nacimiento: ";
        cin >> dd;

        if (fechaNacimiento.verificar_dd(dd))
            cout << endl;
        else
        {
            cout << "Dia invalido, intente de nuevo. " << endl;
            return;
        }
        fecha_validada = true;
    }

    void _fechaContratacion()
    {
        int aa, dd, mm;
        string month;

        // Año de contratación
        cout << endl
             << "Ingrese el anio de contratacion: ";
        cin >> aa;

        if (fechaContratacion.verificar_aa(aa))
            cout << endl;
        else
        {
            cout << "Anio invalido, intente de nuevo" << endl;
            return;
        }

        // Mes de contratación
        cout << "Ingrese el mes de contratacion: ";
        cin >> month;

        if (!fechaContratacion.verificar_mm(month))
        {
            // Intentar convertir a entero para saber si usar la función de enteros
            try
            {
                mm = stoi(month);
                if (!fechaContratacion.verificar_mm(mm))
                {
                    cout << "Mes invalido, intente de nuevo." << endl;
                    return;
                }
            }
            catch (const invalid_argument &e)
            {
                cout << "Mes invalido, intente de nuevo." << endl;
                return;
            }
        }

        cout << endl;

        // Dia de contratación
        cout << "Ingrese el dia de contratacion: ";
        cin >> dd;

        if (fechaContratacion.verificar_dd(dd))
            cout << endl;
        else
        {
            cout << "Dia invalido, intente de nuevo. " << endl;
            return;
        }
        fecha_validada = true;
    }

    void nombreYApellido()
    {
        cout << endl
             << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, nombre);

        cout << endl
             << "Ingrese los apellidos del empleado: ";
        getline(cin, apellidos);
    }

    void imprimirEmpleado()
    {
        cout << endl
             << "Nombre(s) del empleado: " << nombre << endl
             << "Apellido(s) del empleado: " << apellidos << endl
             << "Fecha de nacimiento: "
             << "\t" << endl;
        fechaNacimiento.imprimir_fecha();
        cout << endl
             << "Fecha de contratacion: " << endl;
        fechaContratacion.imprimir_fecha();
    }
};

int main()
{
    short int repetir = 1, opc, empleadoDespedido;
    vector<Empleado> empleados;

    while (repetir == 1)
    {

        while (true)
        {
            cout << "REGISTRO DE EMPLEADOS" << endl
                 << "1 Ingresar empleado" << endl
                 << "2 Mostrar empleados" << endl
                 << "0 Salir" << endl
                 << "Opcion: ";
            cin >> opc;

            if (opc == 1)
            {

                // Creamos la instancia del empleado a agregar
                Empleado empleado;

                // Peticion del nombre y apellido
                cout << endl
                     << "Paso 1" << endl;
                empleado.nombreYApellido();
                system("cls");

                // Peticion de fecha de nacimiento
                cout << endl
                     << "Paso 2" << endl;
                empleado._fechaNacimiento();

                // Peticion de fecha de contratacion
                system("cls");
                cout << endl
                     << "Paso 3" << endl;
                empleado._fechaContratacion();

                empleados.push_back(empleado); // Agregamos el empleado al vector de empleados

                system("cls");
                cout << endl
                     << "Empleado registrado" << endl
                     << "Datos: " << endl;
                empleado.imprimirEmpleado(); // Imprimimos los detalles del empleado
                system("pause");
                system("cls");
            }
            else if (opc == 2)
            {
                // Recorremos el vector e imprimimos los datos de cada indice
                for (size_t i = 0; i < empleados.size(); ++i)
                {
                    cout << endl
                         << "Empleado " << i + 1 << ":" << endl;
                    empleados[i].imprimirEmpleado();
                }
                system("pause");
                system("cls");
            }
            else if (opc == 0)
                break;
            else
                cout << endl
                     << "Opcion invalida" << endl;
        }

        empleados.clear();
        cout << "Repetir proceso (1): ";
        cin >> repetir;
    }

    return 0;
}

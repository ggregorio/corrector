#include <iostream>
#include <fstream>
#include <regex>
#include <Archivo.h>
#include <Diccionario.h>
#define MIN(x,y) ((x) < (y) ? (x) : (y))

using namespace std;

int DistanciaLev(const string &Entrada, const string &Dicc)
{
    int longEntrada = Entrada.length();
    int longDicc = Dicc.length();
    int M[longEntrada+1][longDicc+1];
    for(int i=0;i<=longEntrada;i++){
        M[i][0] = i;
    }
    for(int j=0;j<=longDicc;j++){
        M[0][j] = j;
    }
    for(int i=1;i<=longEntrada;i++){
        for(int j=1;j<=longDicc;j++){
            if(Entrada[i-1] == Dicc[j-1]){
                M[i][j] = M[i-1][j-1];
            }else{
                M[i][j] = MIN(MIN(M[i-1][j] + 1 , M[i][j-1] + 1) , M[i-1][j-1] + 1);
            }
        }
    }
    return M[longEntrada][longDicc];
}

int main(int argc, char *argv[])
{
    if(argc == 4){
        regex txt("^[a-z,A-Z,0-9]+.txt$");
        string txtEntrada,txtDiccionario,txtSalida;
        txtEntrada = argv[1];
        txtDiccionario = argv[2];
        txtSalida = argv[3];
        if(regex_match(txtEntrada,txt) && regex_match(txtDiccionario,txt) && regex_match(txtSalida,txt)){
            cout << txtEntrada << endl;
            cout << txtDiccionario << endl;
            cout << txtSalida << endl;
            Archivo Entrada;
            Diccionario Dicc;
            Entrada.Cargar(txtEntrada);
            cout << Entrada;
            /*
            Entrada.Iterador_Reset();
            while(!Entrada.Iterador_Fin())
            {
                cout << Entrada.Iterador() <<endl;
            }
            Entrada.Guardar("pedro.txt");
            */
            Entrada.Iterador_Reset();
            Dicc.Agregar(Entrada.Iterador());
            Dicc.Mostrar();
        }else{
            cout << "Archivos no validos (nombrearchivo.txt,nombrearchivo tiene que ser alfanumerico).";
        }
    }else{
        cout << "Numero de parametros invalidos. (corrector Entrada.txt Diccionario.txt Salida.txt).";
    }
    return 0;
}

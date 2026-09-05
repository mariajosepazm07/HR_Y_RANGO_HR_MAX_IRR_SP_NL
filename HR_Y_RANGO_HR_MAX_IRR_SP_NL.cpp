#include <iostream>
#include <fstream>
#include <sstream>
#include "windows.h"

using namespace std;

int main(){
    SetConsoleOutputCP(65001);
    
    ifstream archivo; 
    string linea;
    int horaMax = 0, horaMaxVentana = 0;
    double promedioVentana = 0, maxPromedioVentana = 0;

    
    double sumaPorHora[24] = {0};
    double promPorHora[24] = {0};
    int contPorHora[24] = {0};
    double maxPromedio = promPorHora[0];

    int YR, MO, DY, HR;

    double ALLSKY_SFC_SW_DWN;

    archivo.open("POWER_Point_Hourly_20260101_20260904_025d66N_0100d38W_LST.csv");
    
    if (archivo.is_open()){
            for(int i = 0; i < 9; i++){
                if(!getline(archivo, linea)){
                    cout << "Fallo al saltar encabezado en la linea " << i << endl;
                    return 1;
                }
            }
            
        int contLineas = 0;
        
        while(getline(archivo, linea)) {
            for(int i = 0; i < linea.length(); i++){
                if(linea[i] == ','){
                    linea[i] = ' ';
                }
            }

        contLineas++;
        stringstream ss(linea);
        
        if(!(ss >> YR >> MO >> DY >> HR >> ALLSKY_SFC_SW_DWN)){
            continue;
        }
        
        if(ALLSKY_SFC_SW_DWN == -999){
            continue;
        }else{
            sumaPorHora[HR] = sumaPorHora[HR] + ALLSKY_SFC_SW_DWN;
            contPorHora[HR] = contPorHora[HR] + 1;
            }
        } 

        cout << "Total de lineas de datos procesadas: " << contLineas << endl;  

        for(int i = 0; i < 24; i++){
            if(contPorHora[i] == 0){
                continue;
            }else{
                promPorHora[i] = sumaPorHora[i] / contPorHora[i];
            }
        }

        for(int i = 0; i < 24; i++ ){
            if(promPorHora[i] > maxPromedio){
                maxPromedio = promPorHora[i];
                horaMax = i;
            }
        }

        for(int i = 0; i < 24; i++){
            cout << "Hora " << i << ": promedio = " << promPorHora[i] << endl;
        }   

        cout << "Días con datos: " << contPorHora[0] << endl;

        cout << "Hora de maxima irradiancia en San Pedro, Garza García Nuevo León: " << horaMax << " h" << endl;

        cout << "Con un promedio de: " << maxPromedio << " Wh/m^2" << endl; 

        for(int i = 0; i < 23; i++){
            promedioVentana = (promPorHora[i] + promPorHora[i+1]) / 2.0;
            if(promedioVentana > maxPromedioVentana){
                maxPromedioVentana = promedioVentana;
                horaMaxVentana = i;
            }
        }
        cout << "Rango de 2 horas de maxima irradiancia en San Pedro, Garza García Nuevo León: " << horaMaxVentana << "h - " <<
        (horaMaxVentana + 1) << "h" << endl;

        cout << "Con un promedio combinado de: " << maxPromedioVentana << " Wh/m^2" << endl;

    }else{ 
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }

archivo.close();
return 0; 
}
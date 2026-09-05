# HR_Y_RANGO_HR_MAX_IRR_SP_NL
Programa en C++ que analiza datos horarios de NASA POWER para identificar los horarios de mayor irradiancia solar en San Pedro Garza García, N.L.

Este proyecto analiza un año de datos horarios de irradiancia solar (ALLSKY_SFC_SW_DWN, en Wh/m²) obtenidos de la base de datos NASA POWER, con el objetivo de determinar:
La hora individual con el promedio de irradiancia más alto a lo largo de todo el periodo analizado.
El rango de dos horas consecutivas con la mayor irradiancia combinada, útil para identificar la ventana de máxima captación solar.

El programa procesa alrededor de 5,900 registros horarios, valida y limpia los datos (manejo de valores faltantes y formato de archivo), y calcula promedios estadísticos por hora del día.

Tecnologías utilizadas:
C++ (estándar, sin librerías externas más allá de la STL)
Librerías: <fstream>, <sstream>, <iostream>
Datos: NASA POWER Project — resolución horaria

Los datos fueron obtenidos del proyecto Prediction Of Worldwide Energy Resources (POWER) de la NASA Langley Research Center, financiado a través de la NASA Earth Science Division.
Parámetro: ALLSKY_SFC_SW_DWN — CERES SYN1deg All Sky Surface Shortwave Downward Irradiance (Wh/m²)
Ubicación: Latitud 25.6574, Longitud -100.3807 (San Pedro Garza García, N.L., México)
Periodo: 01/01/2026 al 09/04/2026, hora local (LST)
Resolución: Horaria (Hourly)

Cómo funciona:
- Lectura del archivo: se omiten las 9 líneas de metadatos del CSV de NASA POWER hasta llegar a los datos.
- Parseo de cada línea: se reemplazan las comas por espacios y se extraen los campos YEAR, MO, DY, HR, ALLSKY_SFC_SW_DWN con stringstream.
- Validación: se descartan líneas mal formadas (filas vacías o incompletas al final del archivo) y valores marcados como -999 (dato faltante).
- Acumulación: se suman los valores válidos de irradiancia y se cuentan las observaciones por cada una de las 24 horas del día.
- Cálculo de promedios: se obtiene el promedio de irradiancia por hora (suma / conteo).
- Resultados:
  Hora individual con el promedio más alto.
  Ventana de 2 horas consecutivas con el promedio combinado más alto (búsqueda por ventana deslizante).

Posibles mejoras futuras:
- Permitir analizar por mes o estación del año en lugar de todo el periodo junto.
- Exportar los resultados a un archivo CSV o generar una gráfica.
- Generalizar el programa para aceptar cualquier ubicación o rango de fechas como parámetro.
  
Autora: María José Paz Meleiro. Estudiante de ingeniería en tecnologías computacionales.

Licencia:
Este proyecto usa datos públicos del NASA POWER Project. Ver Referencing Guide de NASA POWER para más detalles sobre el uso y cita de los datos.

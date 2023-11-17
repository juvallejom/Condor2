

<div align="center">
<h1> ESC
</div>


## 1.Telemetry and documentation for measurements

Para el ensamble del Condor 2, se usa un ESC Foxxer Reaper F4 128K 60 A. Este cuenta con un sistema de medicion de tension y corriente que se comnunica a partir de protocolo serial. A continuación se describiran los pasos para monitorear estas variables y poder visualizarlas a travez de Mission Planner.


### 1.1 Port Connections 

El protocolo por el cual se media la comunicacion y la tranmisicion de datos de la corriente es el protocolo serial. La conexion se puede realizar por medio de los puertos Telem 1 o Telem2 los cuales estan capacitados para soportar protocolos UART. Los puertos Telem tienen asigandos los siguientes pines :

<div align="center">
 
| Pin  | Conexiones |
| ------------- | ------------- |
| 1 | VCC  |
| 2 | TX (OUT)  |
| 3 | RX (IN)  |
| 4 | CTS  |
| 5 | RTS  |
| 6 | GND  |

</div>


La conexión entre pines pines seria
| ESC  | Telem |
| ------------- | ------------- |
| VCC | VCC  |
| Current | RX (IN)  |
| GND | GND  |



### 1.2 ESC Firmware

Usando el software , 

### 1.3 Mission Planner






## 2.ESC as Power Supply
 

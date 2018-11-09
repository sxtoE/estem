#include "dir_viento.h"

int dir_readDirViento() {
				int read_dir;
				int pos = 0;
				float dprom[10];
				int direccion = 0;

				while (pos < 10) {
								read_dir = analogRead(PIN_DVIENTO);
								dprom[pos] = read_dir;
								direccion = direccion + dprom[pos];
								pos++;
				}
				//pos=0;
				return (direccion / 10.0);
}

int dir_direccion()
{
				int dir;
				int cdir;

				dir = dir_readDirViento();

				if ((dir >= 0 && dir < 20)  || (dir > 978)) {
								cdir = 1; //"N"
				}
				else if (dir >= 20 && dir < 150){
								cdir = 2; //"NO";
				}
				else if (dir >=150 && dir < 320){
								cdir = 3; //"O";
				}
				else if (dir >= 320 && dir < 485){
								cdir = 4; //"SO";
				} 
				else if (dir >= 485 && dir < 557){
								cdir = 5; //"S";
				}
				else if (dir >= 557 && dir < 804){
								cdir = 6; //"SE";
				}
				else if (dir >= 804 && dir < 961){
								cdir = 7; //"E";
				}
				else if (dir >= 961 && dir < 978) {
								cdir = 8; //"NE";
				}
				else {
								cdir = 0; //Error
				} 
				return cdir;
}

void dir_printDir()
{
				int dir;
				int cdir;

				dir = dir_readDirViento();

				if ((dir >= 0 && dir < 20)  || (dir > 978)) {
								cdir = 1; //"N"
								Serial.print("Direccion Viento:\t");
								Serial.println("N");
				}
				else if (dir >= 20 && dir < 150){
								cdir = 2; //"NO";
								Serial.print("Direccion Viento:\t");
								Serial.println("NO");
				}
				else if (dir >=150 && dir < 320){
								cdir = 3; //"O";
								Serial.print("Direccion Viento:\t");
								Serial.println("O");
				}
				else if (dir >= 320 && dir < 485){
								cdir = 4; //"SO";
								Serial.print("Direccion Viento:\t");
								Serial.println("SO");
				} 
				else if (dir >= 485 && dir < 557){
								cdir = 5; //"S";
								Serial.print("Direccion Viento:\t");
								Serial.println("S");
				}
				else if (dir >= 557 && dir < 804){
								cdir = 6; //"SE";
								Serial.print("Direccion Viento:\t");
								Serial.println("SE");
				}
				else if (dir >= 804 && dir < 961){
								cdir = 7; //"E";
								Serial.print("Direccion Viento:\t");
								Serial.println("E");
				}
				else if (dir >= 961 && dir < 978) {
								cdir = 8; //"NE";
								Serial.print("Direccion Viento:\t");
								Serial.println("NE");
				}
				else {
								cdir = 0; //Error
				} 
}

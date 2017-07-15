#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	int i=0,bitDo=0,ok=0,tiempo=0,tiempo1,tiempo2,tiempo3;
	char enter,cadena[10],cadena2[10];
	
	printf("ADVERTENCIA: NO USAR ESTE PROGRAMA SI TIENE EN EJECUCION UN DISCO EN\n");
	printf("SU LECTOR DE DISCO YA QUE EL FIN DEL TEMPORIZADOR PROVOCA UNA ALARMA\n");
	printf("DE DETENCION Y APERTURA DE LA UNIDAD LECTORA DE DISCO PUDIENDO\n");
	printf("PROVOCAR DANOS IRREPARABLES O CORRUPCION EN EL DVD INTRODUCIDO\n");
	
	while (ok==0){
	  printf("\nPulse intro para continuar: ");
	  scanf("%c",&enter);
	  if (enter=='\n')
	    ok=1;
	  else
	    getchar();
	}
	
	ok=0;
	system("clear");
	sleep(1);
	
	printf("\t\t\t\t<<TEMPORIZADOR>>\n\n");
	
	printf("Este programa está bajo copyright y sus derechos pertenecen a Jesus\n"); 
	printf("Jimenez Roman. Es un programa de codigo abierto escrito totalmente\n");
	printf("en lenguaje de baja abstraccion C con licencia GPL. Los derechos de\n");
	printf("distribucion permanecen reservados al autor. Puede contactar con Jesus\n");
	printf("a traves de su correo correofalso@dominioinventado.es.\n");
	
	while (ok==0){
	  printf("\nPulse intro para continuar: ");
	  scanf("%c",&enter);
	  if (enter=='\n')
	    ok=1;
	  else
	    getchar();
	}
	
	do{
	  tiempo=0;
	  tiempo1=0;
	  tiempo2=0;
	  tiempo3=0;
	  cadena[0]='\0';
	  cadena2[0]='\0';
	  bitDo=0;
	  system("clear");
	  sleep(1);
	  printf("\t\t<<TEMPORIZADOR>>\n\n");
	  printf("Introduce HH:MM:SS: ");
	  scanf("%s",cadena);
	  if (strlen(cadena)!=8 || cadena[2]!=':' || cadena[5]!=':' || (atoi(&cadena[3]))>=60 || (atoi(&cadena[6]))>=60){
	    printf("Valores de temporizador incorrecto\n");
	    if (strlen(cadena)!=8){
	      sleep(2);
	      printf("Error en tamaño de cadena\n");
	    }
	    if (cadena[2]!=':' || cadena[5]!=':'){
	      sleep(2);
	      printf("Error en sintaxis\n");
	    }
	    if (atoi(&cadena[3])>=60){
	      sleep(2);
	      printf("Minutero incorrecto\n");
	    }
	    if (atoi(&cadena[6])>=60){
	      sleep(2);
	      printf("Segundero incorrecto\n");
	    }
	  }
	  else{
	    cadena2[0]=cadena[0];
	    cadena2[1]=cadena[1];
	    tiempo3=atoi(cadena2);
	    cadena2[0]=cadena[3];
	    cadena2[1]=cadena[4];
	    tiempo2=atoi(cadena2);
	    if (tiempo2 < 60){
	      cadena2[0]=cadena[6];
	      cadena2[1]=cadena[7];
	      tiempo1=atoi(cadena2);
	      if (tiempo3 < 60){
	        printf("Tiempo1:%d\n",tiempo1);
                printf("Tiempo2:%d\n",tiempo2);
                printf("Tiempo3:%d\n",tiempo3);
                do{
                  system("clear");
                  printf("\t\t\t\t<<TEMPORIZADOR>>\n\n");
                  if (tiempo3<10 && tiempo2>=10 && tiempo1>=10)
                    printf("El temporizador finaliza en 0%d:%d:%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo2<10 && tiempo3>=10 && tiempo1>=10)
                    printf("El temporizador finaliza en %d:0%d:%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo1<10 && tiempo2>=10 && tiempo3>=10)
                    printf("El temporizador finaliza en %d:%d:0%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo3<10 && tiempo2<10 && tiempo1<10)
                    printf("El temporizador finaliza en 0%d:0%d:0%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo3<10 && tiempo2<10 && tiempo1>=10)
                    printf("El temporizador finaliza en 0%d:0%d:%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo3>=10 && tiempo2<10 && tiempo1<10)
                    printf("El temporizador finaliza en %d:0%d:0%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo3<10 && tiempo2>=10 && tiempo1<10)
                    printf("El temporizador finaliza en 0%d:%d:0%d\n",tiempo3,tiempo2,tiempo1);
                  if (tiempo1==0){
                    if (tiempo2==0){
                      if (tiempo3==0){
                        bitDo=1;
                      }
                      else{
                        tiempo3--;
                        tiempo2=59;
                        tiempo1=59;
                      }
                    }
                    else{
                      tiempo2--;
                      tiempo1=59;
                    }
                  }
                  else
                    tiempo1--;
                  sleep(1);
                  
                }while (bitDo==0);
                system("eject");
	        printf("El temporizador ha finalizado\n");
	      }
	      else
	        printf("Segundos incorrectos\n");
	    }
	    else
	      printf("Minutos incorrectos\n");
	  }
	  sleep(2);
	  system("clear");
	  cadena2[0]='\0';
	  printf("\t\t<<TEMPORIZADOR>>\n\n");
	  printf("¿Quieres poner otro temporizador? (no olvide cerrar la unidad lectora si acepta) (Y/N): ");
	  scanf("%s",cadena2);
	}while(cadena2[0]=='y');

  return 0;
}

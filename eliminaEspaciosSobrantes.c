#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

  int c,cont=0;
  FILE *f, *f2;
  char cadena[30],cop[2]="1";
  
  switch(argc){
    case 2:
  
      if (argc < 2){
        printf("Se esperaba %s <fichero1> ... <ficheroN>\n",argv[0]);
        exit(-1);
      }
  
      if ((f=fopen(argv[1],"r"))==NULL){
        printf("Error al abrir fichero\n");
        exit(-1);
      }
  
      strcpy(cadena,argv[1]);
      strcat(cadena,cop);
  
      if ((f2=fopen(cadena,"w"))==NULL){
        printf("Error al abrir fichero\n");
        exit(-1);
      }
      
      while((c=fgetc(f))!=EOF){
        if (c!=' '){
          fputc(c,f2);
        }
      }
  
  }
  
  fclose(f2);
  fclose(f);

  return 0;
}

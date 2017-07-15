#include <stdio.h>
#include <stdlib.h> //Para funcion system()
#include <unistd.h> //Para funcion sleep()

int kbhit(void);

int main(){

	int i=1;
	char enter;
	
	for(i=1;;i++){
		system("clear");
		printf("%d\t\tPULSE ENTER PARA FINALIZAR EL CONTADOR\n",i);
		sleep(1);
		
		if (kbhit()){
		  enter = getchar();
		  if (enter=='\n')
		    return 1;
		}
	}

  return 0;
}

/*
   Permite introducir cualquier cadena en segundo plano sin afectar la ejecucion del bucle 
   y si se introduce en este caso la entrada Enter el bucle se detiene
*/

int kbhit(){
	struct timeval tv;
	fd_set rdfs;
	
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	
	FD_ZERO(&rdfs);
	FD_SET(STDIN_FILENO, &rdfs);
	
	select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &rdfs);
}

#include <stdio.h>                                                                 
#include <stdlib.h>                                                                
#include <unistd.h>    
#include <fcntl.h>                                             
#include <string.h>                                                                
#include <sys/wait.h>                                                              
                    

/**                                                                                    
Enunciado: Write a program that calls fork(). Before calling fork(), have              
the main process access a variable (e.g., x) and set its value to something            
(e.g., 100). What value is the variable in the child process? What happens             
to the variable when both the child and parent cha nge the value of x?                 
                                                                                       
Author:Herney Eduardo Quintero, Juan Camilo Sanchez, Carlos murillo                                                                               
                                                                                
*/                                                                                     
                                                                                       
// Incluir archivos de cabecera que definen los prototipos de las                      
// funciones: 'printf', 'sleep' y 'fork'                                               


int main(char *argc, char ** argv){
        int x;
        
        pid_t pid = fork();
        if(!pid){
		x=9;
		printf("Soy el hijo, mi pid es %d y X tiene el valor de %d para mi\n", getpid(), x);
	}
	else{
		wait(NULL);
		x=99;
		printf("Soy el padre, mi pid es %d y X tiene el valor de %d para mi\n", getpid(), x);
	}

return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
/**                                                                                    
Enunciado: "Write another program using fork() . The child process should              
print “hello”; the parent process should print “goodbye”. You should try to            
ensure that the child process always prints first; can you do this without             
calling wait() in the parent?"                                                         
                                                                                       
Author:Herney Eduardo Quintero, Juan Camilo Sanchez, Carlos murillo                                                                                       
                                                                                 
*/                                                                                     
                                                                                       
// Incluya los archivos de cabecera necesarios para llevar a cabo la                   
// solucion en C de acuerdo al enunciado                                               
                                                                                       
int main(int argc, char** argv) {                                                      
  pid_t pid;                                                                           
  int status;                                                                          
                                                                                       
  // invoque la llamada al sistema fork() 
pid=fork();

                                           
  if (pid != 0) {                                                                      
    // esta es la parte del padre que debe imprimir 'goodbye' 
waitpid(pid,NULL,0);
printf("goodbye\n");                        

  } else {                                                                             
    // esta es la parte del hijo que debe imprimir 'hello'   
printf("hello\n"); 
sleep(2);                         

  }                                                                                    
} 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
//Author:Herney Eduardo Quintero, Juan Camilo Sanchez, Carlos murillo       
// Incluir archivos de cabecera para las funciones que requiere para                   
// solucionar el enunciado                                                             
                                                                                       
int main(int argc, char **argv) {                                                      
  // Usar estas variables                                                              
  int x;                                                                               
  pid_t pid;                                                                           
  char *filename="code-02.txt";                                                        
  int fd;                                                                              
                                                                                       
  //                                                                                   
  // Instrucciones para abrir archivo de lectura/escritura)                            
  //                                                                                   
  fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);                                                                                      
  x = 100;                                                                             
  pid = fork();                                                                        
  if (pid == 0) {                                                                      
    x++;                                                                               
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'          
dprintf(fd, "Soy el hijo, mi PID es %d y mi x es %d\n", getpid(), x);                                             
  } else {                                                                             
    x+=2;                                                                              
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'           
dprintf(fd, "Soy el padre, mi PID es %d y mi x es %d\n", getpid(), x);                                            
  }                                                                                    
                                                                                       
  close(fd);           }

 #include <stdio.h>                                                                 
 #include <stdlib.h>                                                                
 #include <unistd.h>                                                                
 #include <string.h>                                                                
 #include <sys/wait.h>                                                              
 int                                                                                
 main(int argc, char*                                                               
 argv[])                                                                            
 {                                   
	while(1){
		char comando[80];
		printf("$: ");
		scanf("%s",comando);
		printf("digito %s\n",comando);
		if (!strcmp("exit", comando)){
			break;
		}
		pid_t pid = fork();
		if(!pid) {
			char * myargs[2];
			myargs[0] = strdup(comando); 	//rpogram: "wc" (word count)
			myargs[1] = NULL;		//marks end of array
			execvp(myargs[0],myargs);	//runs word count
		}else{
			wait(NULL);
		}
	}             
 }

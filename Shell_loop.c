#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define PATH "/home/osman/Desktop/FinalProject"


void shell_loop(void);
char *readline(void);
char **getargs(char *);
int execute(char **);

//This is a loop  of shell loop has a basic timeline (getline->splitargs->execute)
void shell_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
	char cwd[PATH_MAX];
	if (getcwd(cwd,sizeof(cwd)) != NULL){
    printf("%s >> ",cwd);
	}
    line = readline();
    if(strcmp(line,"\n") != 0){
    args = getargs(line);
    status=execute(args);
    free(line);
	free(args);
}

  } while (status==0);
}


//executing files are works with execpv or execv but for a succesfull process they must open as a child process and fork() does it for as.
int execute(char **args){
	pid_t c_pid,pid;
	int status;
	
	char *cmdargs[] = {
        PATH "/C_files/Makecreator/makegen",
	args[1],
        NULL};    
        
        char *cmdargsen[] = {
        PATH "/C_files/encryption/encryption",
        args[2],args[3],
        NULL};    
        
        char *cmdargsdec[] = {
        PATH "/C_files/encryption/decryption",
        args[2],args[3],args[4],
        NULL};    
        
     char *cmdargs2[] = {
       "/bin/bash",
       PATH "/scripts/finfo.sh",
        NULL };
        
        char *cmdhisted[] = {
       "/bin/bash",
       PATH "/scripts/histed.sh",
       args[1],args[2],args[3],
        NULL };
        // manuals
        char *mancrypto[] = {
       "/bin/bash",
        PATH "/Manuals/mancrypto.sh",
        NULL };
        
        char *manfilesys[] = {
		"/bin/bash",
       PATH "/Manuals/manfile.sh",
        NULL };
        
        char *manhisted[] = {
       "/bin/bash",
       PATH "/Manuals/manhisted.sh",
        NULL };
        
        char *manmakegen[] = {
       "/bin/bash",
       PATH "/Manuals/manmakegen.sh",
        NULL };
        
        
        if(strcmp(args[0],"filesys")==0){
				 c_pid =fork();
			if(c_pid == 0){
				execvp(cmdargs2[0], cmdargs2);
				perror("execve failed");
				}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}else{
					perror("fork failed");
					_exit(1);
				}
		
		}
		
		
		else if(strcmp(args[0],"histed")==0){
				 c_pid =fork();
			if(c_pid == 0){
				execvp(cmdhisted[0], cmdhisted);
				perror("execve failed");
				}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}else{
					perror("fork failed");
					_exit(1);
				}
		
		}
        //Makefile Generator
       else if(strcmp(args[0],"makegen")==0){
			c_pid =fork();
			if(c_pid == 0){
				execv(cmdargs[0],cmdargs); 
				perror("execve failed");
				}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}else{
					perror("fork failed");
					_exit(1);
				}
		}
		
		 //encryption and Decryption Generator
       else if(strcmp(args[0],"crypto")==0){
			if(strcmp(args[1],"-dec")==0){
			c_pid =fork();
			if(c_pid == 0){
				execv(cmdargsdec[0],cmdargsdec); 
				perror("execve failed");
				}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}else{
					perror("fork failed");
					_exit(1);
				}
		}
		else if(strcmp(args[1],"-enc")==0){
			c_pid =fork();
			if(c_pid == 0){
				execv(cmdargsen[0],cmdargsen); 
				perror("execve failed");
				}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}else{
					perror("fork failed");
					_exit(1);
				}
		}else {
			printf("Crypto needs an option");}
	}
	
	else if(strcmp(args[0],"help") == 0){
			printf("\e[1;1H\e[2J");
			printf("Welcome to help don't worry you are not alone here\n\n");
			printf("Available commands:\n");
			printf("filesys  	:This is a command for entering the file information system you can create and check all files information.\n\n");
			printf("makegen		:This is command is for generating makefile for your C project (all files should be on path).\n\n");
			printf("crypto		:This command is for encrypt your favorite file for no one can see your information . ( crypto -dec for decryption, crypto -enc for encryption).\n\n");
			printf("histed		:This function is for modify your file for their time.\n\n");
			printf("cd		:Changing directory\n\n");
			printf("clean		:Cleaning terminal\n\n");
			printf("exit		:Exiting from terminal");
			printf("For more option you can check their manual by typing man [function] .\n\n");
		 }
			
		// Manuals
		else if(strcmp(args[0],"man")==0){
			c_pid =fork();
		if(c_pid == 0){
			if(strcmp(args[1],"filesys")==0){
				execv(manfilesys[0],manfilesys);
			}else if(strcmp(args[1],"makegen")==0){
				execv(manmakegen[0],manmakegen);
			}else if(strcmp(args[1],"crypto")==0){
				execv(mancrypto[0],mancrypto);
			}else if(strcmp(args[1],"histed")==0){
				execv(manhisted[0],manhisted);
			}else{
				printf("There is no such Function as %s\n",args[1]);}
				
		}else if(c_pid > 0){
					if((pid =wait(&status)) < 0){
					perror("wait");
					_exit(1);
					}
				}
			return 0;
		}
		
		
		else if(strcmp(args[0],"cd")==0){
			chdir(args[1]);
			return 0;
		}
		
		else if(strcmp(args[0],"clean")==0){
			printf("\e[1;1H\e[2J");
			return 0;
		}
		
		else if(strcmp(args[0],"exit")==0){
			return 1;
		}
		else{
			printf("There is no such function as %s\n",args[0]);}
		
		
	return 0;
		
}

// Readline is made by getline function.
char *readline(void)
{
  char *line = NULL,shell_prompt[100];
  ssize_t bufsize = 0; // have getline allocate a buffer for us
 getline(&line, &bufsize, stdin);
  return line;
}


// In a line our program needs to get arguments in the line. getargs checking tabs and space for seperating arguments. 
char **getargs(char *line)
{
  int bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "SCOF: can't find argumants\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "SCOF: can't split args\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[position] = NULL;
  return tokens;
}


int main(){
printf("\e[1;1H\e[2J");
shell_loop();
printf("\e[1;1H\e[2J");
return 0;
}

	

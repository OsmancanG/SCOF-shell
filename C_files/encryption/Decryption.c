/*
 * 2019 Feyza Türker <feyzaturker@feyzaturker>
 * 
 * Lecture Code <COMP 205>
 * Student ID <041602002>
 * 
 * The program works for making a decryption on a given file. Decryption is obained with shifting ASCII numbers of
 * all chars of the given file. All key numbers are representing the amount of shifting from 32 in decimal (from the
 * space character). The original file is obtained with the shifting operation.
 * 
 */

#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h>

void DecryptedFile(char *arg1, char *arg2, char *arg3);
void Decryption(int fd, int fd2, int fd3);
char * ReadChar (int fd);
int CharCount(int fd);

int main(int argc, char **argv)
{
	DecryptedFile(argv[1], argv[2], argv[3]);
	return 0;
}

//Creates an decrypted (original) file from the key file
void DecryptedFile(char *arg1, char *arg2, char *arg3){
	
	int fd, fd2, fd3;
	
	fd = open(arg1, O_RDONLY); //key file
	fd2 = open(arg2, O_RDONLY); //new file with full of spaces
	//decrypted file (go back to the original file)
	fd3=open(arg3,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

	if ((fd<0) || (fd2<0) || (fd3<0)){
		perror("There is a problem about files");
		exit(1);
	}
	
	Decryption(fd,fd2,fd3);
	
	close(fd);
	close(fd2);
	close(fd3);
}

//Makes decryption and writes the original file
void Decryption(int fd, int fd2, int fd3){
	
	lseek(fd2,0,SEEK_SET);
	int numofspace=CharCount(fd2);
	char * allkey = malloc(sizeof(char)*numofspace);
	
	lseek(fd,0,SEEK_SET);
	allkey=ReadChar(fd);
	
	
	char * key = malloc(sizeof(char)*5);
	char * letter = malloc(sizeof(char));
	int j=0;
	int k=0;
	int keyterm;
	int temp=0;
	
	/* Shifts by the number of character in the encrypted file
	 Solves the key file */
	for(k; k<numofspace; k++){
		int i=0;
		
		while((int)allkey[j] != 32){
			key[i]=allkey[j];	
			i++;
			j++;
		}
		
		keyterm = atoi(key); //converts the key into an integer
		temp=keyterm+32; //shifts 32 in ASCII code
		letter[0] = (char)temp; //return back from ASCII to char
		
		write(fd3,letter,strlen(letter));

		letter[0]=NULL;
		j++;

		/*free gives an error therefore, the code makes 
		 the pointer null manually */
		 
		for(int l=0; l<sizeof(key); l++){
			key[l]=NULL;
		}
	}
}

//Reads all chars from the given file
char * ReadChar (int fd){
	
	int sz=0;
	char chr;
	int numofchar = CharCount(fd);
	lseek(fd,0,SEEK_SET);
	
	char * alltext = malloc(sizeof(char)*numofchar);
	
	for(int i=0; i<numofchar; i++){
		sz=read(fd,&chr,1);
		alltext[i]=chr;
	}
	return alltext;
}

//Counts the number of character of the given file
int CharCount(int fd){
	
	int sz, i=0;
	char chr;
	do{
		sz=read(fd, &chr,1);	
		i++;
	}
	while(sz != 0);
	
	return i;
	
}

/* 
 * 2019 Feyza Türker <feyzaturker@feyzaturker>
 * 
 * Lecture Code <COMP 205>
 * Student ID <041602002>
 * 
 * The program works for making an encryption on a given file. Encryption is obained with shifting ASCII numbers of
 * all chars of the given file. All characters are shifted to the 32 in decimal (to the space character) and got a
 * key number. The key number is specifed with the amount of shifting for each character. The key number is kept on
 * "encrypted.txt". The program also creates a new .txt file with any given name. The file is fulled with spaces 
 * by the number of the character in original file. 
 */
 
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h> 

void EncryptedFile(char *arg1, char *arg2);
void Encryption(int fd, int fd2, int fd3);
char * ReadChar (int fd);
int CharCount(int fd);


int main(int argc, char **argv)
{
	EncryptedFile(argv[1],argv[2]);
	return 0;
}

//Creates an encrypted file from the or1ginal file
//Creates file that keeps key of encryption
void EncryptedFile(char *arg1, char *arg2){
	
	int fd, fd2, fd3;
	
	fd=open(arg1, O_RDONLY); //the file that is wanted to be encrypted
	//key file
	fd2=open("encryptedfile.txt", O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	//new file with full of spaces
	fd3=open(arg2,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

	if ((fd<0) || (fd2<0) || (fd3<0)){
		perror("There is a problem about files");
		exit(1);
	}
	Encryption(fd, fd2, fd3);

	close (fd);
	close (fd2);
	close (fd3);
}
//Makes encryption and writes the key file
void Encryption(int fd, int fd2, int fd3){
	
	int temp;
	int key;
	
	lseek(fd,0,SEEK_SET);
	int numofchar = CharCount(fd);
	char * keystr = malloc(sizeof(char)*numofchar*4);
	char * text = malloc(sizeof(char)*numofchar);

	lseek(fd,0,SEEK_SET);
	text = ReadChar(fd);

	/*The key is obtained by shifting all characters
	 by 32 which is the ASCII number of space character*/
	for(int i=0; i<numofchar-2; i++){
		temp=(int)(text[i]);
		if(temp<32){
			key= -(32-temp);
			sprintf(keystr, "%d", key);
		}
		else if(temp>=32){
			key= temp-32;
			sprintf(keystr, "%d", key);
			
		}
	//Writes the files
		write(fd2,keystr,strlen(keystr));
		write(fd2," ",strlen(" "));
		write(fd3," ",strlen(" "));
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

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct linking_park{
	char filename[100];
	char headerso[10][100];
	char Ofiles[10][100];
	int headnumber;
	struct linking_park *tail;
};

struct linking_park *start=NULL;
struct linking_park *prev;


int cDetector(char *str);
void FilesinPath(void);
void passHeaders(struct linking_park *cur);
void addtostack(struct linking_park *ptr);
void display(void);
void make_o(void);
void addo(struct linking_park *cur);
void displayo(void);
void makeFilegen(char *str,char *exe);


int main(int argc, char *argv[]){
	char *make_name="makefile";
	FilesinPath();
	display();
	make_o();
	makeFilegen(make_name,argv[1]);
	return 0;
}


void makeFilegen(char *str,char *exe){
	FILE * fp;
	struct linking_park *cur;
	cur=start;
	
	fp =fopen(str, "w+");
	fprintf(fp,"%s : ",exe);
	
		while(cur != NULL){
				fprintf(fp,"%s ",cur->Ofiles[0]);
			cur = cur->tail;
		}
	fprintf(fp,"\n");
	fprintf(fp,"\tcc -o %s ",exe);
	
	cur=start;
	while(cur != NULL){
				fprintf(fp,"%s ",cur->Ofiles[0]);
			cur = cur->tail;
		}
	fprintf(fp,"\n");
	fprintf(fp,"\n");
	
	cur=start;
	while(cur != NULL){
		fprintf(fp,"%s : ",cur->Ofiles[0]);
		fprintf(fp,"%s ",cur->filename);
		for(int i=0; i<cur->headnumber;i++){
			fprintf(fp,"%s ",cur->headerso[i]);
		}
		fprintf(fp,"\n");
		fprintf(fp,"\tcc -c %s ",cur->filename);
		fprintf(fp,"\n");
		cur = cur->tail;
	}
	
	fprintf(fp,"clean:");
	fprintf(fp,"\n");
	fprintf(fp,"\trm -r ");
	
	cur=start;
	while(cur != NULL){
				fprintf(fp,"%s ",cur->Ofiles[0]);
			cur = cur->tail;
		}
	fprintf(fp,"\n");
}


void make_o(void){
	struct linking_park *cur;
	cur=start;
	while(cur != NULL){
			addo(cur);
			cur = cur->tail;
		}
	}
		

void addo(struct linking_park *cur){
	char *inccheck;
	int j=0;
	int i=0;
	inccheck=malloc(sizeof(char)*100);
		j=0;
		while(1){
			inccheck[j]=cur->filename[j];
			if(cur->filename[j] == '.') break;
			j++;
		}
			inccheck[j+1]= 'o';
			inccheck[j+2]= '\0';
			strcpy(cur->Ofiles[0],inccheck);
			free(inccheck);
	
	for(i=0; i < cur->headnumber; i++){
		inccheck=malloc(sizeof(char)*100);
		j=0;
		while(1){
			inccheck[j]=cur->headerso[i][j];
			if(cur->headerso[i][j] == '.') break;
			j++;
		}
			inccheck[j+1]= 'o';
			inccheck[j+2]= '\0';
			strcpy(cur->Ofiles[i+1],inccheck);
			free(inccheck);
	}
}




void displayo(void){
		struct linking_park *cur;
		cur=start;
		while(cur != NULL){
			for(int i=0; i < cur->headnumber+1;i++){
				printf("%s ",cur->Ofiles[i]);
			}
			cur = cur->tail;
		}
	}

int cDetector(char *str){ 
	int i = 0;
	while(1){
		if(str[i] == '.') break;
		i++;}
	if(str[i+1] == 'c') return 1;
	else return 0;
		
	}
	
	int hDetector(char *str){
	int i = 0;
	char type[20];
	int j = 0;
	while(1){
		if(str[i] == '.') break;
		i++;}
		
	while(1){
		if(str[i] == '\0') break;
		if(str[i] == '\0' && j == 0) return 1;
		type[j] =str[i];
		j++;
		i++;
	}
		type[j+1] ='\0';
		return strcmp(type, ".h");
	}
	
	
	void addtostack(struct linking_park *ptr){
		if(start == NULL){
			start = ptr;
			prev = ptr;
		}
		else{
			prev->tail = ptr;
			prev = ptr;
		
		}
		
		
		}
		
	void display(void){
		struct linking_park *cur;
		cur=start;
		while(cur != NULL){
			printf("%s ->", cur->filename);
			for(int i=0; i < cur->headnumber;i++){
				printf("%s ",cur->headerso[i]);
			}
			printf("\n");
			cur = cur->tail;
		}
	}
	

void FilesinPath(void)
{
    DIR *d;
    struct dirent *dir=malloc(sizeof(struct dirent));
    struct linking_park *sub;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(cDetector(dir->d_name) == 1){
				sub = malloc(sizeof(struct linking_park));
				sub->tail = NULL;
				strcpy(sub->filename,dir->d_name);
				passHeaders(sub);
				addtostack(sub);
			}
        }
        closedir(d);
    }
}

void passHeaders(struct linking_park *cur){
	int c; 
	int i=0;
	int j=0;
	char *inccheck;
	inccheck=malloc(sizeof(char)*100);
	int flag=0,flag1=0, flag2=0;
	FILE *fp;
	char *onehead;
	fp =fopen(cur->filename,"r");
	if(fp ==NULL){
		printf("there is no such file\n");
		exit(1);}

	while(1){
		c=fgetc(fp);
		if(c == 35){
			fread(inccheck,7,1,fp);
		if(strcmp(inccheck,"include") == 0){
			flag = 1;
			onehead=calloc(40,sizeof(char));
			free(inccheck);
	}
	}
		if(flag==1){
			if(c==34){
				flag1=!flag1;
				continue;
		}
	}
		
		if(c == 10){
			inccheck=malloc(sizeof(char)*100);
			if(flag2 == 1){
				onehead[i] ='\0';
				strcpy(cur->headerso[j],onehead);
				free(onehead);
				j++;
				flag2=0;
			}
			flag=0;
			flag1=0;
			i=0;
		}
		
		if(flag1 == 1){
			onehead[i]=c;
			i++;
			flag2=1;
		}
		
		if(feof(fp)){
		 break;	}
	}
	
	cur->headnumber = j;
	fflush(fp);
	fclose(fp);
}




	


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINP 1024
#define MAXLINE 1024
#define MAXPATHS 10

enum {FALSE, TRUE};

void help(void);
void getinp(char *);
void clearstr(char *);
char *getpath();

char input[MAXINP];
char *paths[MAXPATHS];

int main(int argc, char *argv)
{
	int c;
	char priv = '$'; /*privilege character*/
	//paths = getpath();
 
	while(TRUE){
		clearstr(input);
		printf("%c> ", priv);
		getinp(input);
		
		if (strcmp(input, "help") == 0)
			help();
		if (strcmp(input, "quit") == 0)
			exit(0);
		if (strcmp(input, "git gud") == 0)
			printf("You can't git gud YE SCRUB!!\n");
	}
}

void getinp(char *s)
{
	int c;

	while ((c = getchar()) != EOF && c != '\n')
		*s++ = c;
}

char *getpath()
{
	FILE *fp;
	int c;
	char *pth[MAXPATHS], *p = pth;

	if ((fp = fopen(".path", "r")) != NULL){
		while ((fgets(*p++, MAXLINE, fp)) != NULL)
			;
	}else{
		printf("Error opening .path, using /bin/ and /usr/bin/\n");
	}
	return *pth;
}

void clearstr(char *s)
{
	int i;
	for (i = 0; i < MAXINP; i++)
		*s++ = '\0';
}

void help(void)
{
	printf("This is nanoShell.\n"
		"Usage:\n"
		"\tprogram arguments\n"
		"The programs can be found in either\n"
		"\t/bin/\tor\t/usr/bin/\n");
}

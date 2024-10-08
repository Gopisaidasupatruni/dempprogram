/*
 * Task1 :
 This is a  program with command line arguments that compares two text files. If the files are identical,
 the program will print an appropriate message. If not, all lines containing differences must be printed
 to the screen with their line numbers. If the files differ in more than 10 lines, the program can stop
 printing after the 10th line.
 Good to have try to redirect the screen output to a text file without changing the source code.
 */
/*  Author :Gopisai
 *  Created: 18/9/2024
 *  modified: 18/9/2024
 */
/* Required header files */
#include<stdio.h>
#include<string.h>
/* Macro definitions */
#define MAX 500
/** MAIN PROGRAM */
/* main: To compare two text files */
int main(int argc,char*argv[])
{
	char sStr1[MAX];
	char sStr2[MAX];
	int iIndex1=0,iIndex2=0;
	/* If arguments less than three */
	if(argc<3)
	{
		printf("Usage ./a.out file1 file2\n");
		return 1;
	}
	/* Two files */
	FILE *fp1 = fopen(argv[1],"r"); 
	/*opens the file in read mode */

	if(fp1 == NULL) {  
		/*checking the file is exist or not */
		printf("file doesn't exist\n");
		return 0;
	}

	char cCh;
	while( (cCh = fgetc(fp1)) != EOF ){ 
		/*reads all the characters from file */
		sStr1[iIndex1++]=cCh;
	}
	sStr1[iIndex1]='\0';
	fclose(fp1);
	FILE *fp2 = fopen(argv[2],"r"); 
	/*opens the file in read mode */

	if(fp2 == NULL) { 
	       	/*checking the file is exist or not */
		printf("file doesn't exist\n");
		return 0;
	}

	char cCh2;
	while( (cCh2 = fgetc(fp2)) != EOF )
	       	/*reads all the characters from file. */
		sStr2[iIndex2++]=cCh2;
	sStr2[iIndex2]='\0';
	fclose(fp2);
	int ivar1=0,ivar2=0;
	int iInc1=0,iInc2=0,icount=0;
        int lineNumber = 1;
	char sString1[MAX], sString2[MAX];
      /* To compare strings from two different files */
	for(ivar1=0,ivar2=0;sStr1[ivar1]&&sStr2[ivar2];ivar1++,ivar2++){
		while(sStr1[ivar1]!='\n'){
		sString1[ iInc1++ ]=sStr1[ivar1++];
		}
		while(sStr2[ivar2]!='\n'){
		sString2[ iInc2++]=sStr2[ivar2++];
		}
		
			sString1[iInc1]='\0';sString2[iInc2]='\0';

			
			/* comparing two strings equal or not */
			if(strcmp(sString1,sString2)!=0){
				
				printf("%s\n %s\n",sString1,sString2);
				icount++;
			}
			iInc2=0;iInc1=0;

		
		/* To count upto ten unequal stings */
		if(icount==10)
			return 1;
	}

}

/* End main */

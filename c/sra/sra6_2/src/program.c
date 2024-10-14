#include<stdio.h>
#include"task1.h"

void test_readPerson(ST s1)
{
  /* Opening file in read mode */
        FILE*fp=fopen("file","r");
        
        /* To scan data from file */
    while (fscanf(fp, "%s %d %f", s1.sName, &s1.iAge, &s1.fSalary) != EOF) {
        printf("name: %s\n", s1.sName);
        printf("age: %d\n", s1.iAge);
        printf("salary: %.2f\n", s1.fSalary);
        printf("\n");
    }
    /* closing file */
        fclose(fp);

}

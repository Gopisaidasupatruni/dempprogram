/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 
 * Name:D.Gopisai
 * Date:25/06/2024
 
#include<stdio.h>
int main()
{
int i;
char ch;
int count=0,len=0;
while((ch=getchar())!=EOF){
	if(ch=='\n'||ch=='\t'||ch==' '){
        printf("\n");
	}
	else{
		printf("*");
	        count++;
	}
}
*/
#include<stdio.h>
int main()
{
int i=0;
char ch;
int count=0;
char a[20];
while((ch=getchar())!=EOF){
	count++;
	if(ch=='\n'||ch=='\t'||ch==' '){
		a[i]=count-1;
		i++;
		count=0;}
}
    // Find the maximum word length
    int j;
    int max_length = 0;
    for (j = 0; j < i; j++) {
        if (a[j] > max_length) {
            max_length = a[j];
        }
    }
int k;
for(j=max_length;j>0;j--){
		for(k=0;k<i;k++){
			 if (a[k] >= j) {
                printf(" * ");
            } else {
                printf("   ");
            }}
		printf("\n");
		}
}

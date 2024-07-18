/*Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to 
write a program that reverses its input a line at a time. */
#include<stdio.h>
void rev(char s[]);
int main(){

        char s[200],a[200],ch;
        int i,j,k=0,t=0;
        while((ch=getchar())!=EOF){
		s[k++]=ch;
	if(ch=='\n'){
		rev(s);
		k=0;
	}
	}
}
void rev(char s[]){
	int i,j,n,k;
	char temp,a[200];
        for(j=0;s[j]!='\0';j++); 
        for(i=0,j=j-1;i<j;i++,j--)
        {
                temp = s[i], s[i] = s[j], s[j] = temp;
        }
	
        printf("After reversing the string : %s\n",s);

}

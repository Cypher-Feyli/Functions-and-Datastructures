/* ====================================
File name: exerc_2_3.c (or cpp)
Date: 2018-02-01
Group Number: 1
Members that contributed:
Sayf Rashid
Melinda Ivók
Mehrshad Hosseini
Demonstration code: 24676 Important , No code no bonus !
====================================== */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   // char a[4]= "dbe";
   // char b[4]= "dbe";
    //24676
    if(argc >= 2)	{
        getchar();
        printf("%s",argv[1]);
		if(strcmp(argv[1], argv[2]) == 0)	{
			puts(" the same");
                         getchar();
		}
		else	{
			printf("not the same");
                         getchar();
                }
                 //printf("lets try with self made method");
    getchar();
}
    printf("lets try with self made method");
    getchar();
    if(argc >= 2){	
		if(compareStrings(argv[1], argv[2]) == 0){
			printf(" the same");
		}
		else	{
			printf("not the same");
                }
}
    
    

    //printf("%d",compareStrings(a,b));
    return 0;
}

int compareStrings(char *s1,char *s2){
   int len = strlen(s1);
   if(len == strlen(s2)){
       for(int i =0;i<len;i++){
           if(s1[i] != s2[i]){
               return 1;;
           }
       }
   }else{return 1;
   }return 0;
}
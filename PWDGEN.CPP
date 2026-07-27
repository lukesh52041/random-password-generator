#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
char chars[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*";
int poolsize=sizeof(chars)-1;
int length;
printf("enter the length:");
scanf("%d",&length);
char password[100];
srand(time(NULL));
for(int i=0;i<length;i++){
password[i]=chars[rand()%poolsize];
}
password[length]='\0';
printf("\ngenerated password is:%s",password);
FILE*file=fopen("password.txt","w");
if(file==NULL) {
printf("error could not create one\n");
return 1;
}
fprintf(file,"%s\n",password);
fclose(file);
printf("\npassword saved to password.txt");
return 0;
}

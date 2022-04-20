#include "head.h"
int main(){
 FILE *f;
 Person p;
 node *head=NULL;
 if((f=fopen("person.dat","wb"))!=NULL)
 {
 do{
 printf ("next name:");
 scanf("%29s",p.name);
 if(!strcmp(p.name,"*"))break;
 printf("next number:");
 scanf("%d",&(p.n));
 fwrite(&p, sizeof(Person),1,f);
 printf("Writing the structure in the file\n");
}while (1);
fclose(f);
printf("The file was created\n");
}
else
 { printf("File Opening Error!\n"); exit(1);}

if (!(f=fopen("person.dat","rb"))){
 printf("File Opening Error!\n"); exit(1);
 }
head=makeSrtLst(head,f);
prt(head);
find_sum(head);
head= free_m(head);
return 0;
}

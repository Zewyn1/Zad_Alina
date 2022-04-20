#include "head.h"
node * makeSrtLst(node * head, FILE *f)
{
    node * p,*crnt,*prev;
    do{
        p=(node *)malloc(sizeof(node));
        if (p==NULL) {printf("Memory Error!");exit(1);}
        p->next= NULL;
        if(!fread(&(p->prs),sizeof(Person),1,f)){
            free(p);
            break;
        }
        prev=NULL;crnt=head;
        p->next=head;
        head = p;
    }while(1);
    return head;
}
void prt(node *crnt){
    if (crnt){
        printf("the list is:\n");
        while(crnt){
            printf("%s has %d na adres: %d\n",crnt->prs.name,crnt->prs.n, crnt);
            crnt=crnt->next;
        }
    }
    else
        printf("Prazen spisak!\n");
}
void find_sum(node *crnt)
{
    int sum=0;
    if (crnt)
    {
        while(crnt){
            sum+=crnt->prs.n;
            crnt=crnt->next;
        }
        printf("sum = %d",sum);
    }
    else
        printf("Prazen spisak!\n");
}
node * free_m(node *crnt){
    node* next;
    printf("\nMemory free!\n");
    while(crnt){
        next = crnt->next; free(crnt); crnt=next;
    }
    return NULL;
}
//look for a number in the list using input
node * find_num(node *crnt, int num)
{
    if (crnt)
    {
        while(crnt){
            if (crnt->prs.n==num)
                return crnt;
            crnt=crnt->next;
        }
    }
    else
        printf("Prazen spisak!\n");
    return NULL;
}
//change the number of a person in the list by using input
node * change_num(node *crnt, int num)
{
    if (crnt)
    {
        while(crnt){
            if (crnt->prs.n==num)
            {
                printf("Enter new number: ");
                scanf("%d",&(crnt->prs.n));
                return crnt;
            }
            crnt=crnt->next;
        }
    }
    else
        printf("Prazen spisak!\n");
    return NULL;
}
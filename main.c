#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void displayCar(char uc[], char ucl[]);
void dispfb();
void del();
void entry();
void fb();
void insert(char cn1[],char cc1[]);
void displayOrders();
void order();
void create();
void place(char uc[],char ucl[]);
void process();

int st[10];
char stn[10][30];
int top=-1,tp=-1;
struct custom{
    char * name;
    int mob;
};
char Q[10][30],Q1[10][30];
int f=-1,r=-1,f1=-1,r1=-1,max=10;

enum boolean{FALSE,TRUE};

enum boolean isempty()
{
   if(f==-1||r==-1)
      return TRUE;
   else
      return FALSE;
}

enum boolean isfull()
{
    if(r==max-1)
      return TRUE;
    else
      return FALSE;
}

struct car{
    char cn[30],cc[30];
    long int cost;
    int l;
    struct car *next;
}*first=NULL,*last=NULL;


void create(){
    struct car *nn;
    char cn[30],cc[30];
    long int cost;
    int n;
    printf("Enter any number to proceed further, enter -1 to stop\n");
    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        else{
            nn=(struct car *)malloc(sizeof(struct car));
            printf("Enter car name, color, cost:\n");
            scanf("%s%s%ld",cn,cc,&cost);
            strcpy(nn->cn,cn);
            strcpy(nn->cc,cc);
            nn->cost=cost;
            nn->next=NULL;
            if(first==NULL){
                first=nn;
                last=nn;
            }else{
                last->next=nn;
                last=nn;
            }
        }
    
    }
    
}

void place(char uc[],char ucl[])
{   struct car *temp;
    int flag=0;
    temp=first;
    while(temp!=NULL)
    {
        if(strcmp(temp->cc,ucl)==0  && strcmp(temp->cn,uc)==0)
        {
             flag=1;
             break;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("Hurrah!!Car %s of %s color is available in the garage\n",uc,ucl);
        displayCar(uc,ucl);
        del();
        printf("******************************************************\n");
    }
    else
    {
        printf("There isn't a car %s available right now. Sorry:{\n",uc);
        del();
        printf("******************************************************\n");
    }
}

void process(){
    int i;
    if(isempty())
    {
        printf("No Orders Available To Proceed\n");
        return;
    }
    else{
        for(i=f;i<=r;i++)
        {
            place(Q[i],Q1[i]);
            
        }
    }
}

void displayCar(char uc[],char ucl[]){
    struct car *temp;
    temp=first;
    int n;
    while(temp!=NULL)
    {
        if(strcmp(temp->cc,ucl)==0  && strcmp(temp->cn,uc)==0)
        {
            printf("******************************************************\n");
            printf("\nCAR DETAILS:--\n");
            printf("Car name: %s\n",temp->cc);
            printf("Car color: %s\n",temp->cn);
            printf("Car cost: %ld\n",temp->cost);
            printf("Enter 1 to proceed the purchase\n");
            scanf("%d",&n);
            if(n==1){
                printf("Congratulations on your new car!!\n");
                fb();
            }
             
        }
        temp=temp->next;
    }
}

void dispfb(){
    printf("***Displaying Feedbacks***\n");
    int i=0;
    for(i=top;i>=0;i--){
        printf("User\tRating\t\n");
        printf("%s\t%d\n",stn[i],st[i]);
        printf("******************************************************\n");
    }
    
}

void fb(){
    printf("******************************************************\n");
    printf("***Please rate on a scale of 1-5***\n");
    int r;
    char nm[30];
    printf("Enter your name and rating\n");
    scanf("%s%d",nm,&r);
    top=top+1;
    st[top]=r;
    tp+=1;
    strcpy(stn[tp],nm);
    printf("******************************************************\n");
}

void entry(){
    struct custom s1;
    printf("****Enter your details****\n");
    printf("Your good name\n");
    scanf("%s",&s1.name);
    printf("Phone number\n");
    scanf("%d",&s1.mob);
    printf("******************************************************\n");
}

void insert(char cn1[],char cc1[])
{
    if(isfull())
    {
        printf("Cant take orders right now!!\n");
        return;
    }
    if(r==-1)
    {
        r=0;
        f=0;
        r1=0;
        f1=0;
    }
    else
    {
        r++;
        r1++;
    }
    strcpy(Q[r],cn1);
    strcpy(Q1[r1],cc1);
}


void displayOrders()
{
    int i;
    if(isempty())
    {
        printf("No Orders Available\n");
        return;
    }
    else{
        printf("***Displaying Orders***\n");
        printf("User \t Order\n");
        for(i=f;i<=r;i++)
        {
            printf("%s\t %s\n",Q[i],Q1[i]);
        }
    }
    
}

void order(){
    printf("***Please enter all the orders into the database***\n");
    printf("Enter the number of orders\n");
    int n;
    char uc[30],ucl[30];
    scanf("%d",&n);
    while(n>0){
        printf("Enter the customer user ordered and its color\n");
        scanf("%s%s",uc,ucl);
        insert(uc,ucl);
        n--;
    }
    printf("All The Orders Have Been Entered Successfully!!!\n");
    printf("******************************************************\n");
}


void del()
{
    if(isempty())
    {
        printf("No Orders Available\n");
        return;
    }
    else
    {
      if(f==r)
      {
        f=-1;
        r=-1;
        f1=-1;
        r1=-1;
      }
      else
      {
        f++;
        f1++;
      }
      printf("Order is deleted Successfully\n");
        
    }
}


int main(){
    printf("\t\t\t\t*******Welcome to SRI Car Showroom *******\t\t\t\t\n");
    create();
    int op;
    do{
        printf("\n1.User\n2.Place Order\n3.display Orders\n4.Process The Orders\n5.Display Feedback\n6.Exit\nEnter the option of your choice:\n");
        scanf ("%d", &op);
        switch (op)
        {
            case 1:entry();
                   break;
            case 2:order();
                   break;
            case 3:displayOrders();
                   break;
            case 4:process();
                   break;
            case 5:dispfb();
                   break;
        }
        if(op>6)
            printf("Invalid choice\n");
    }while(op!=6);
}


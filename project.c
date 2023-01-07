#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define max
int slot[7][12]={0};//7->seat no    10 -> no of slots(in total 10)

int order=0,plates=0,seat=0,slotno;


struct resturant {
    char name[20];
    int id;
    int phone;
    int order_detailes[20];  // remain to work on it.
    char date[11] ;
    int bill ;
    int table_no;
    int slot;
    struct resturant *next;
};
typedef struct resturant node;
node *head=NULL;
node *tail=NULL;

void time_slot(){
    printf("---------------time slot---------------\n");
    printf("1=11.0-12.0\t");
    printf("2=12.0-13.0\n");
    printf("3=13.0-14.0\t");
    printf("4=14.0-15.0\n");
    printf("5=15.0-16.0\t");
    printf("6=16.0-17.0\n");
    printf("7=17.0-18.0\t");
    printf("8=18.0-19.0\n");
    printf("9=19.0-20.0\t");
    printf("10=20.0-21.0\n");
    printf("11=21.0-22.0\t");
    printf("12=22.0-23.0\n");
    printf("\n Enter Your slot:");
    scanf("%d",&slotno);
    printf("\n----------------------------------\n");

    if(slot[seat][slotno-1]==0  &&  seat<7){
        slot[seat][slotno-1]=1;
        seat++;
        printf("Successful!\n\n\n");
    }
    else{
        printf("This slot is already full please go for the next slot.\n\n");
        time_slot();
    }
}

void menu(node *temp){
    int more=0,bill,or=0;
    printf("\n-----------------Menu-----------------\n");
    printf("1=Chicken Biriyani                   Rs.200.0\t");
    printf("2=Mutton Biryani                     Rs.350.0\n");
    printf("3=Biryani                            Rs. 130.0\t");
    printf("4=Butter Chicken and Naan            Rs.399\n");
    printf("5=Tandori Chicken                    Rs.250\t");
    printf("6=Panjabi Chiken with Lachha Paratha Rs.359\n");
    printf("7=Masala Kulcha                      Rs.110\t");
    printf("8=Chilli Paneer                      Rs. 269.0\n");
    printf("9=Chicken Hakka noodles              Rs. 210.0\t");
    printf("10=Fish Finger                       Rs. 99.0\n");
    printf("11=Ice Cream                         Rs. 89.0\t");
    printf("12=Soft Drink                        Rs. 59.0\n");
    printf("\nEnter your choice : ");//one function to store dishes and no of plats.
    scanf("%d",&order);
    temp->order_detailes[or]=order;
    or=or+1;
    printf("\nPlates : ");
    scanf("%d",&plates);
    if(order==1){
        bill=200*plates;
    }
    else if(order == 2){
        bill=350*plates;       
    }
    else if(order == 3){
        bill=130*plates;
    }
    else if(order == 4){
        bill=399*plates;
    }
    else if(order == 5){
        bill=249*plates;
    }
    else if(order == 6){
        bill=359*plates;
    }
    else if(order == 7){
        bill=110*plates;
    }
    else if(order == 8){
        bill=269*plates;
    }
    else if(order == 9){
        bill=210*plates;
    }
    else if(order == 10){
        bill=99*plates;

    }
    else if(order == 11){
        bill=89*plates;

    }
    else if(order == 12){
        bill=59*plates;
    }
    
    temp->bill=temp->bill+bill;
    printf("%d",temp->bill);
    printf("\nOrder more dishes? \n 1=Yes 0=no : ");
    scanf("%d",&more);
    if(more==1){
        menu(temp);
    }
    
}

void Book_a_table(node *temp){
    static int x=0;

        temp->id=1000+x;
        x++;
        printf("your id no is : %d\n",temp->id);
        printf("Enter your name\n");
        fflush(stdin);
        gets(temp->name);        
        printf("Enter your phone number\n");
        scanf("%d",&temp->phone);
        printf("Enter todays date\n");
        gets(temp->date);
        // printf("Enter order details\n");
        // scanf("%d",&temp->order_detailes);
        // printf("Enter table number\n");
        // scanf("%d",&temp->table_no);
        // printf("Enter time slot time of your choice\n");
        // scanf("%d",&temp->slot);

    
    menu(temp);
    time_slot(temp);

}


void ava_check(node *temp){
    printf("---------------time slot---------------\n");
    printf("1=11.0-12.0\t");
    printf("2=12.0-13.0\n");
    printf("3=13.0-14.0\t");
    printf("4=14.0-15.0\n");
    printf("5=15.0-16.0\t");
    printf("6=16.0-17.0\n");
    printf("7=17.0-18.0\t");
    printf("8=18.0-19.0\n");
    printf("9=19.0-20.0\t");
    printf("10=20.0-21.0\n");
    printf("11=21.0-22.0\t");
    printf("12=22.0-23.0\n");
    printf("\n Enter Your slot:");
    scanf("%d",&slotno);
    printf("\n----------------------------------\n");
    for(int i=0;i<7;i++){
        if(slot[i][slotno-1]!=0){
            printf("\nTable number-%d     Status-Booked\t",i+1);
            printf("Customer Id - %d",temp->id);
        }
        else{
            printf("\nTable number-%d     Status-Empty\t",i+1);

        }
    }
}

void col_of_tday(node *temp){
    node *dh=head;
    int tcol=0;
    // printf("%d ",dh->bill);

    do{
        tcol=tcol+dh->bill;
        dh=dh->next;
        
        
    }while(dh!=NULL);
    printf("%d",tcol);
}

void count_cus(){
    int count=0;
    node *dh=head;
    while(dh!=NULL){
        count=count+1;
        dh=dh->next;
    }
    printf("Total no of customers today is %d.\n",count);
}

void cus_deta(){
    int i=0;
    node *dh=head;
    while(dh!=NULL){
    printf("\n----------------------------\n");
    printf("\n----------------------------\n");
    printf("%d\n",dh->id);
    printf("%s\n",dh->name);
    printf("%d\n",dh->phone);
    printf("%s\n",dh->date);
    while(i<strlen(dh->order_detailes))
    {
    if(dh->order_detailes[i]==1){
        printf("/chicken Biryni");
        i=i+1;
    }
    else if(dh->order_detailes[i]==2){
        printf("/Motton Biryani");
        i=i+1;
    }
    else if(dh->order_detailes[i]==3){
        printf("/Biryani");
        i=i+1;
    }
        else if(dh->order_detailes[i]==4){
        printf("/Butter chicken and Naan");
        i=i+1;
    }
    else if(dh->order_detailes[i]==5){
        printf("/Tandoori Chiken");
        i=i+1;
    }
    else if(dh->order_detailes[i]==6){
        printf("/Punjabi chikan with lacha paratha");
        i=i+1;
    }
    else if(dh->order_detailes[i]==7){
        printf("/Masala kulcha");
        i=i+1;
    }
    else if(dh->order_detailes[i]==8){
        printf("/Chilli Paneer");
        i=i+1;
    }
    else if(dh->order_detailes[i]==9){
        printf("/Chicken Hakka noodles");
        i=i+1;
    }
    else if(dh->order_detailes[i]==10){
        printf("/Finger Fish");
        i=i+1;
    }
    else if(dh->order_detailes[i]==11){
        printf("/Ice Cream");
        i=i+1;
    }
    else if(dh->order_detailes[i]==12){
        printf("/Soft Drink");
        i=i+1;
    }
    }
    // printf("%d\n",dh->order_detailes);//
    printf("%d\n",dh->bill);
    printf("%d\n",dh->slot);//associate array with struct(slot and seat).
    dh=dh->next;
    printf("\n----------------------------\n");
    printf("\n----------------------------\n");

    }

}

int main(){
    int n=1;
    node *temp;
    while(n!=0){
        printf("\n1=book atable\n2=check avability\n3=Collection of the day\n");
        printf("4=Total customer of the day\n5=Highest bill of the day\n6=Customer details\n");
        printf("7=Food Menu\n0=Exit\n");
        printf("Enter your coice : ");
        scanf("%d",&n);
        if(n==1){
            temp=(node*)malloc(sizeof (node));
            if(head==NULL){
                head=temp;
                tail=temp;
                temp->next=NULL;
            }
            else{
                tail->next=temp;
                tail=temp;
                tail->next=NULL;
            }
            Book_a_table(temp);
        }
        else if(n==2){
            ava_check(temp);
        }
        else if(n==3){
            col_of_tday(temp);
        }
        else if(n==4){
            count_cus();
        }
        else if(n==5){
            
        }
        else if(n==6){
            cus_deta();
        }
        else if(n==7){
            menu(temp);
        }
        else if(n==0){
            break;
        }
    }

    return 0;
}

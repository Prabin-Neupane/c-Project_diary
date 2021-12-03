#include<stdio.h>
#include<string.h>
void password();
void addrecord();
void viewrecord();

//void editrecord();
//void deleterecord();
//void editpassword();
//void exit();
struct date
    {
        int year,month,day;
    };
struct time {
    int hh,mm;
};

struct data
{
    struct date date1;
    struct time time1; 
    char event[40];
    char place[25];
    char note[1000];

} st[100];


int main (){
    
    //FILE *pass =fopen("password.txt","w+");
    //table:
    int count=0,choice;
    printf(" \n\n\n\t\tTo maintain privacy please cooperate with us !                  \n\n\n");
    password();
    // repeat:
    printf(" Welcome to your system : \n");
    //signup();
    printf("\n\n\t\tMAIN MENU:");

    printf("\n\n\tADD RECORD\t[1]");

    printf("\n\tVIEW RECORD\t[2]");

    printf("\n\tEDIT RECORD\t[3]");

    printf("\n\tDELETE RECORD\t[4]");

    printf("\n\tEDIT PASSWORD\t[5]");

    printf("\n\tEXIT\t\t[6]");

    printf("\n\n\tENTER YOUR CHOICE:");

    
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            addrecord();
            break;
        case 2:
            viewrecord();
            break;
        case 3:
            //deleterecord();
            break;
        case 4:
            //editpassword();
            break;
        case 5:
            //exit();
            break;
        default:
            printf("You entered wrong choice . TRY AGAIN \n"); 
    }

    return 0;
}

void addrecord(){
    FILE *file =fopen("addrecord.txt","a");
    char check;
    int i,count;

    
    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE ADD MENU *");

    printf("\n\t\t***************************\n\n");

   // printf("\n\n\tENTER NAME OF EVENT : ");

    printf("\n\n Enter number of event to add : ");

    scanf("%d",&count);
    for (i=0;i<count;i++){
        printf("\n\n\tENTER DATE OF THE %s :[yyyy-mm-dd]:",st[i].event);

        scanf("%d-%d-%d",&st[i].date1.year,&st[i].date1.month,&st[i].date1.day);
        fprintf(file,"%d-%d-%d  ",st[i].date1.year,st[i].date1.month,st[i].date1.day);

        printf("ENTER NAME OF EVENT : ");
        scanf("%*c%s",st[i].event);
        fprintf(file,"%s  ",st[i].event);

        
        printf("\n\n\tENTER TIME OF THE %s : [hh:mm] : ",st[i].event);
        scanf("%d:%d",&st[i].time1.hh,&st[i].time1.mm);
        fprintf(file,"%d:%d  ",st[i].time1.hh,st[i].time1.mm);
        printf("\n\n\tENTER THE PLACE OF %s : ",st[i].event);

        scanf("%*c%[^\n]s",st[i].place);
        fprintf(file,"%s  ",st[i].place);
        printf("\n\n\tENTER NOTE ABOUT %s  : ",st[i].event);

        scanf("%*c%[^\n]s",st[i].note);
        fprintf(file,"%s",st[i].note);
        fprintf(file,"\n\n\n");
        // repeat:
        // table:
        printf("/n/n/t/t/t Your event has been successfully recorded ! ");
        rewind(file);
    
    
    }


    
    fclose(file);
}
void viewrecord(){
    int year,month,day,flag=0,i=0;
    char c;
    struct data costomer[100];
    FILE *file =fopen("addrecord.txt","r");
    printf("enter date to search event : ");
    scanf("%d-%d-%d",&year,&month,&day);
    
    for (i=0;i<100;i++){

        while (fread(&costomer,sizeof(st),10,file) == 1)
        {
            printf("%d \n",st[i].date1.year);
            if (st[i].date1.year == year /*&& st[i].date1.month == month && st[i].date1.day == day*/){
                printf(" Note = %s\n Event = %s\n",st[i].note,st[i].event);
                printf("Date = %d-%d-%d \n",st[i].date1.year,st[i].date1.month,st[i].date1.day);
                flag++;
            }
        }
    }
    if (flag == 0){
        printf("record not found \n\n\n");
    }
    printf("search again (Y/N)  ?   :  ");
    scanf("%*c%c",&c);
    if (c=='Y'){
        viewrecord();
    }else{
        main();
    }
    fclose(file);
}
    
    //fscanf("%d-%d-%d",&st1.date1.year,&st1.date1.month,&st1.date1.day);
    //printf(file,"%d-%d-%d",st1.date1.year,st1.date1.month,st1.date1.day);

 //   fgets(file ,"%s",st1.event);
    //printf(file,"%s\n",st1.note);
    //printf(file,"%s\n",st1.place);
    //fclose(file);


/*void editrecord(){

}
void deleterecord(){

}
void editpassword(){

}
//void exit(){

//}
*/












void password (){
    char pass[8],real[8]="123456";
    int j,k=0,count=0;
    
    //printf("\n Only 3 trails are allowed : \n");
    
    
    printf("\n\n\t\t  ********* Enter 6 digit password : ********* \n");
    printf("      ********* FOR SECURITY PROPOSE START WITH * ONLY IN FIRST ATTEMPT *********::  ");
    scanf("%*c%[^\n]s",pass);
    for(j=0;pass[j] != '\0';j++){
        if (pass[j] == real[j]){
            k++;
        }
    }
    if (k != 6){
        printf("!!!!!!!!!!!!! INCORRECT PASSWORD \n PLEASE TYPE CAREFULLY OR YOU WILL BE BLOCKED!!!!!!!!!!!!!");
        password(); 
    }
     
        
}

/*void signup(){

    FILE *pass = fopen("password.txt","a");
    char passp[50],user[50];
    printf("enter the user name:");
    scanf("%*c%[^\n]s",&user);
    printf("enter the password:");
    scanf("%*c%[^\n]s",&passp);
    fprintf(pass,"%s\n",user);
    fprintf(pass,"%s\n",passp);

    fclose(pass);
}
*/



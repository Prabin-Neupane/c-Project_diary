#include<stdio.h>
#include<string.h>
void password();
void addrecord();
void viewrecord();
void signup();
//void editrecord();
//void deleterecord();
//void editpassword();
//void exit();
struct date
    {
        int year,month,day;
    }date1;
struct time {
    int hh,mm;
}time1;

struct data
{
    struct date date1;
    struct time time1; 
    char event[40];
    char place[25];
    char note[1000];

} st1;


int main (){
    
    //FILE *pass =fopen("password.txt","w+");
    //table:
    int count=0,choice;
    printf("                        To maintain privacy please cooperate with us !                  \n\n\n");
    password();
    // repeat:
    printf(" Welcome to your system : \n");
    signup();
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
    char record[1000],check;


    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE ADD MENU *");

    printf("\n\t\t***************************\n\n");

    printf("\n\n\tENTER NAME OF EVENT : ");

    scanf("%*c%[^\n]s",st1.event);
    fprintf(file,"%s  ",st1.event);

    printf("\n\n\tENTER DATE OF THE %s :[yyyy-mm-dd]:",st1.event);

    scanf("%d-%d-%d",&st1.date1.year,&st1.date1.month,&st1.date1.day);
    fprintf(file,"%d-%d-%d  ",st1.date1.year,st1.date1.month,st1.date1.day);
    printf("\n\n\tENTER TIME OF THE %s : [hh:mm] : ",st1.event);

    scanf("%d:%d",&st1.time1.hh,&st1.time1.mm);
    fprintf(file,"%d:%d  ",st1.time1.hh,st1.time1.mm);
    printf("\n\n\tENTER THE PLACE OF %s : ",st1.event);

    scanf("%*c%[^\n]s",st1.place);
    fprintf(file,"%s  ",st1.place);
    printf("\n\n\tENTER NOTE ABOUT %s  : ",st1.event);

    scanf("%*c%[^\n]s",st1.note);
    fprintf(file,"%s",st1.note);
    fprintf(file,"\n\n\n");
    repeat:
    table:
    printf("your event has been successfully recorded ! ");
    printf("Add more ? (Y/N) :" );
    scanf("%*c%c",&check);
    if (check == 'Y'){
        void addrecord();
    }
    else if (check == 'N'){
        
        main();
    }

    else{
        printf("Invalid option ! TRY AGAIN : \n");
        goto repeat;

    }


    
    fclose(file);
}
void viewrecord(){
    FILE *file =fopen("addrecord.txt","r");
    printf("enter date to search event : ");
    scanf("%d-%d-%d",&st1.date1.year,&st1.date1.month,&st1.date1.day);
    //fscanf("%d-%d-%d",&st1.date1.year,&st1.date1.month,&st1.date1.day);
    //printf(file,"%d-%d-%d",st1.date1.year,st1.date1.month,st1.date1.day);

    fgets(file ,"%s",st1.event);
    //printf(file,"%s\n",st1.note);
    //printf(file,"%s\n",st1.place);
    //fclose(file);

}
void editrecord(){

}
void deleterecord(){

}
void editpassword(){

}
void exit(){

}











void password (){
    char pass[8],real[8]="123456";
    int j,k=0,count=0;
    
    //printf("\n Only 3 trails are allowed : \n");
    
    
    printf("\t  ********* Enter 6 digit password : *********\n");
    printf("      ********* FOR SECURITY PROPOSE START WITH * ONLY IN FIRST ATTEMPT *********\ ::  ");
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

void signup(){

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



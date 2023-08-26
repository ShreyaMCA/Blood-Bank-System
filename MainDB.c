#include<stdio.h>
#include<conio.h>
struct Donor
{
	char name[20];
	int age;
	int contact_number;
	char blood_type[5];
}Dnr;
char filedonor[]="DnrRecord.txt";
struct Camp
{
	char city[20];
	char venue[20];
	char organizer[20];
}Cmp;
char filecamp[]="CmpRecord.txt";
struct Recipient
{
	char name[20];
	int age;
	int contact_number;
	char blood_type[5];
}Rec;
char fileRecipient[]="RecRecord.txt";
struct Stock
{
	int blood_quantity;
	char blood_type[5];
}Stk;
char fileStock[]="StkRecord.txt";
void insertCmp()
{
 FILE *fp;
 fp=fopen(filecamp,"a+");
 printf("Enter the City:");
 scanf("%s", Cmp.city);
 printf("Enter the Venue:");
 scanf("%s", Cmp.venue);
 printf("Enter the organizer:");
 scanf("%s", Cmp.organizer);
 fwrite(&Cmp, sizeof(Cmp),1 , fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispCmp()
{
 FILE *fp1;
 int eof;
 fp1=fopen(filecamp,"r");
 printf("\n CITY \t\t\t VENUE \t\t\t ORGANIZER \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Cmp,sizeof(Cmp),1,fp1))
 {
	printf("\n %s\t\t%s\t\t\t%s\n", Cmp.city,Cmp.venue,Cmp.organizer);
 }
  fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchCmp()
{
 FILE *fp2;
 int  a,avl=0;
 char n[20];
 printf("\nEnter the city you want to search:");
 scanf("%s",n);
 fp2 = fopen(filecamp,"r");
while (fread(&Cmp,sizeof(Cmp),1,fp2))
{
 if(!strcmp(n,Cmp.city))
{
    printf("\n city  = %s\n", Cmp.city);
    printf("\n venue  = %s\n", Cmp.venue);
    printf("\n organizer  = %s\n", Cmp.organizer);
	avl=1;
	break;
}
}
 //avl = avlname(n);
 if (avl == 0)
  printf("City %s is not available in the file\n",n);
   fclose(fp2);
}
//    FUNCTION TO DELETE A RECORD
void deleteCmpfile()
{
 FILE *fw,*fr;
 char n[20];
 printf("Enter the City you want to delete:");
 scanf("%s", n);
  fr=fopen(filecamp,"r");
  fw=fopen("TempFile","w");
while (fread(&Cmp,sizeof(Cmp),1,fr))
{
if(strcmp(n,Cmp.city))
{
 fwrite(&Cmp,sizeof(Cmp),1,fw);
}
else
{
	printf("%s",Cmp.city);
}
}
  fclose(fw);
  fclose(fr);
 //if (avlname(n) == 0)
  //printf("name %s is not available in the file\n", n);
 //else
 //{
 /*  while (fread(&Dnr, sizeof(Dnr), 1, fpo))
  {
   a = Dnr.age;
   if (a != n)
    fwrite(&Dnr, sizeof(Dnr), 1, fpt);
  }
*/
  fr=fopen("TempFile","r");
  fw=fopen(filecamp,"w");
  while (fread(&Cmp,sizeof(Cmp),1,fr))
  {
  fwrite(&Cmp,sizeof(Cmp),1,fw);
  }
  fclose(fr);
  fclose(fw);
  printf("\nRECORD DELETED\n");
 }
//}
void maincamp()
{
	int c;
    char n[20];
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               CAMP INFORMATION                    ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n 1. INSERT");
  printf("\n 2. DISPLAY");
  printf("\n 3. SEARCH");
  printf("\n 4. DELETE");
  printf("\n 5. EXIT \n");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: \t");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insertCmp();
   break;
  case 2:
    dispCmp();
    break;
  case 3:
   searchCmp();
   break;
  case 4:
   deleteCmpfile();
   break;
   //case 5:
   //exit(1);
   //break;
  default:
   printf("\nYour choice is wrong\n Please try again...\n");
   break;
}
}
while (c!= 5);
} 
void insertDnr()
{
 FILE *fp;
 fp=fopen(filedonor,"a+");
 printf("Enter the name:");
 scanf("%s", Dnr.name);
 printf("Enter the age:");
 scanf("%d", &Dnr.age);
 printf("Enter the contact number:");
 scanf("%d", &Dnr.contact_number);
 printf("Enter the blood type:");
 scanf("%s", Dnr.blood_type);
 fwrite(&Dnr,sizeof(Dnr),1,fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispDnr()
{
 FILE *fp1;
 int eof;
 fp1=fopen(filedonor,"r");
 printf("\n NAME \t\t\t AGE \t \t\tCONTACT NUMBER \t\t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Dnr,sizeof(Dnr),1,fp1))
 {
 	printf("\n %s\t\t\t%d\t\t\t%d\t\t\t%s\n",Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchDnr()
{
 FILE *fp2;
 int  a,avl=0;
 char n[20];
 printf("\n Enter the name you want to search:");
 scanf("%s",n);
 fp2=fopen(filedonor,"r");
while (fread(&Dnr,sizeof(Dnr),1,fp2))
{
if(!strcmp(n,Dnr.name))
{
 printf("\n Name = %s",Dnr.name);
    printf("\n Age  = %d",Dnr.age);
    printf("\n Contact number  = %d\n",Dnr.contact_number);
    printf("\n Blood type  = %s\n",Dnr.blood_type);
	avl=1;
	break;	
}
}
 //avl = avlname(n);
 if (avl == 0)
  printf("Name %s is not available in the file\n",n);
   fclose(fp2);
}
//    FUNCTION TO DELETE A RECORD
void deleteDnrfile()
{
 FILE *fw,*fr;
 char n[20];
 printf("Enter the name you want to delete:");
 scanf("%s",n);
  fr = fopen(filedonor,"r");
  fw = fopen("TempFile","w");
 while (fread(&Dnr, sizeof(Dnr),1,fr))
{
if(strcmp(n,Dnr.name))
{
 fwrite(&Dnr,sizeof(Dnr),1,fw);
}
else
{
	printf("%s",Dnr.name);
}
}
 fclose(fw);
 fclose(fr);
 //if (avlname(n) == 0)
  //printf("name %s is not available in the file\n", n);
 //else
 //{
 /*  while (fread(&Dnr, sizeof(Dnr), 1, fpo))
  {
   a = Dnr.age;
   if (a != n)
    fwrite(&Dnr, sizeof(Dnr), 1, fpt);
  }
*/  
  fr=fopen("TempFile","r");
  fw=fopen(filedonor,"w");
  while(fread(&Dnr,sizeof(Dnr),1,fr))
  {
  fwrite(&Dnr,sizeof(Dnr),1,fw);	
  }
  fclose(fr);
  fclose(fw);
  printf("\nRECORD DELETED\n");
 }
//}
 // MAIN PROGRAM
void maindonor()
{
	int c;
    char n[20];
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               DONOR INFORMATION                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n 1. INSERT");
  printf("\n 2. DISPLAY");
  printf("\n 3. SEARCH");
  printf("\n 4. DELETE");
  printf("\n 5. EXIT \n");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: \t");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insertDnr();
   break;
  case 2:
    dispDnr();
   break;
  case 3:
  searchDnr();
   break;
  case 4:
   deleteDnrfile();
   break;
   //case 5:
   //exit(1);
   //break;
   default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;
}
}
while (c!= 5);
} 
void insertRec()
{
 FILE *fp;
 fp=fopen(fileRecipient,"a+");
 printf("Enter the name:");
 scanf("%s", Rec.name);
 printf("Enter the age:");
 scanf("%d", &Rec.age);
 printf("Enter the contact number:");
 scanf("%d", &Rec.contact_number);
 printf("Enter the blood type:");
 scanf("%s", Rec.blood_type);
 fwrite(&Rec, sizeof(Rec),1 , fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispRec()
{
 FILE *fp1;
 int eof;
 fp1=fopen(fileRecipient,"r");
 printf("\n NAME \t\t\t AGE \t\t\t CONTACT NUMBER \t\t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Rec,sizeof(Rec),1,fp1))
 {
 	printf("\n %s\t\t\t%d\t\t\t%d\t\t\t%s\n",Rec.name,Rec.age,Rec.contact_number,Rec.blood_type);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchRec()
{
 FILE *fp2;
 int a,avl=0;
 char n[20];
 printf("\nEnter the name you want to search:");
 scanf("%s",n);
 fp2 = fopen(fileRecipient,"r");
while(fread(&Rec, sizeof(Rec),1,fp2))
{
if(!strcmp(n,Rec.name))
{
    printf("\n Name = %s",Rec.name);
    printf("\n Age  = %d",Rec.age);
    printf("\n Contact number  = %d\n",Rec.contact_number);
    printf("\n Blood type  = %s\n",Rec.blood_type);
	avl=1;
	break;	
}
}
 //avl = avlname(n);
 if (avl == 0)
  printf("Name %s is not available in the file\n",n);
   fclose(fp2);
 }
//    FUNCTION TO DELETE A RECORD
void deleteRecfile()
{
  FILE *fw,*fr;
  char n[20];
  printf("Enter the name you want to delete:");
  scanf("%s", n);
  fr = fopen(fileRecipient,"r");
  fw = fopen("TempFile","w");
while (fread(&Rec,sizeof(Rec),1,fr))
{
if(strcmp(n,Rec.name))
{
 fwrite(&Rec,sizeof(Rec),1,fw);
}
else
{
	printf("%s",Rec.name);
}
}
  fclose(fw);
  fclose(fr);
 //if (avlname(n) == 0)
  //printf("name %s is not available in the file\n", n);
 //else
 //{
 /*  while (fread(&Dnr, sizeof(Dnr), 1, fpo))
  {
   a = Dnr.age;
   if (a != n)
    fwrite(&Dnr, sizeof(Dnr), 1, fpt);
  }
*/  
  fr=fopen("TempFile","r");
  fw=fopen(fileRecipient,"w");
  while (fread(&Rec,sizeof(Rec),1,fr))
  {
  fwrite(&Rec,sizeof(Rec),1,fw);	
  }
  fclose(fr);
  fclose(fw);
  printf("\nRECORD DELETED\n");
 }
//}
 // MAIN PROGRAM
void mainrec()
{
	int c;
    char n[20];
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               RECIPIENT INFORMATION               ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n 1. INSERT");
  printf("\n 2. DISPLAY");
  printf("\n 3. SEARCH");
  printf("\n 4. DELETE");
  printf("\n 5. EXIT \n");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: \t");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insertRec();
   break;
  case 2:
    dispRec();
   break;
  case 3:
   searchRec();
   break;
  case 4:
   deleteRecfile();
   break;
   //case 5:
   //exit(1);
   //break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;
}
}
while (c!= 5);
} 
void insertStk()
{
 FILE *fp;
 fp=fopen(fileStock,"a+");
 printf("Enter the Blood Quantity:");
 scanf("%d", &Stk.blood_quantity);
 printf("Enter the Blood Type:");
 scanf("%s",Stk.blood_type);
 fwrite(&Stk,sizeof(Stk),1 ,fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispStk()
{
 FILE *fp1;
 int eof;
 fp1=fopen(fileStock,"r");
 printf("\n BLOOD QUANTITY \t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Stk,sizeof(Stk),1,fp1))
 {
 	printf("\n %d\t\t\t\t%s\n",Stk.blood_quantity,Stk.blood_type);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchStk()
{
 FILE *fp2;
 int a,avl=0;
 char n[20];
 printf("\nEnter the blood type you want to search:");
 scanf("%s",n);
 fp2=fopen(fileStock,"r");
while(fread(&Stk,sizeof(Stk),1,fp2))
{
if(!strcmp(n,Stk.blood_type))
{
    printf("\n Blood quantity  = %d\n",Stk.blood_quantity);
    printf("\n Blood type  = %s\n",Stk.blood_type);
	avl=1;
	break;	
}
}
 //avl = avlname(n);
 if (avl == 0)
  printf("Blood Type %s is not available in the file\n",n);
   fclose(fp2);
 }
//    FUNCTION TO DELETE A RECORD
void deleteStkfile()
{
 FILE *fw,*fr;
 char n[20];
 printf("Enter the blood type you want to delete:");
 scanf("%s", n);
  fr = fopen(fileStock,"r");
  fw = fopen("TempFile","w");
 while (fread(&Stk,sizeof(Stk),1,fr))
{
if(strcmp(n,Stk.blood_type))
{
 fwrite(&Stk, sizeof(Stk),1,fw);
}
else
{
	printf("%s",Stk.blood_type);
}
}
 fclose(fw);
  fclose(fr);
 //if (avlname(n) == 0)
  //printf("name %s is not available in the file\n", n);
 //else
 //{
 /*  while (fread(&Dnr, sizeof(Dnr), 1, fpo))
  {
   a = Dnr.age;
   if (a != n)
    fwrite(&Dnr, sizeof(Dnr), 1, fpt);
  }
*/  
  fr=fopen("TempFile","r");
  fw=fopen(fileStock,"w");
  while (fread(&Stk, sizeof(Stk),1,fr))
  {
  fwrite(&Stk,sizeof(Stk),1,fw);	
  }
  fclose(fr);
  fclose(fw);
  printf("\nRECORD DELETED\n");
 }
//}
 // MAIN PROGRAM
void mainstock()
{
	int c;
    char n[20];
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               STOCK INFORMATION                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n 1. INSERT");
  printf("\n 2. DISPLAY");
  printf("\n 3. SEARCH");
  printf("\n 4. DELETE");
  printf("\n 5. EXIT \n");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: \t");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insertStk();
   break;
  case 2:
    dispStk();
   break;
  case 3:
    searchStk();
   break;
  case 4:
   deleteStkfile();
   break;
   //case 5:
   //exit(1);
   //break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;
}
}
while (c!= 5);
}
void main()
{
char ch;
//clrscr();
	while(1)
    {
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              BLOOD BANK MANAGEMENT SYSTEM         ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\nPress 1 for Stock\nPress 2 for Recipent\nPress 3 for Donor\nPress 4 for Camp\nPress 5 for Exit \n");
      ch=getche();
      if(ch=='1')
      {
		mainstock();
      }
      else if(ch=='2')
      {
		mainrec();
      }
      else if(ch=='3')
      {
		maindonor();
      }
      else if(ch=='4')
      {
		maincamp();
      }
      else if(ch=='5')
      {
		break;
      }
      //clrscr();
    }
}

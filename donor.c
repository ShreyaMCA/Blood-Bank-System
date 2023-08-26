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
 fwrite(&Dnr, sizeof(Dnr),1 , fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispDnr()
{
 FILE *fp1;
 int eof;
 fp1 = fopen(filedonor, "r");
 printf("\n NAME \t\t\t AGE \t \t\tCONTACT NUMBER \t\t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Dnr, sizeof(Dnr), 1, fp1))
 {
 	printf("\n %s\t\t\t%d\t\t\t%d\t\t\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
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
while (fread(&Dnr, sizeof(Dnr),1,fp2))
{
if(!strcmp(n,Dnr.name))
{
 printf("\n Name = %s", Dnr.name);
    printf("\n Age  = %d", Dnr.age);
    printf("\n Contact number  = %d\n", Dnr.contact_number);
    printf("\n Blood type  = %s\n", Dnr.blood_type);
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
 fwrite(&Dnr, sizeof(Dnr),1,fw);
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
  fr = fopen("TempFile", "r");
  fw = fopen(filedonor, "w");
  while (fread(&Dnr, sizeof(Dnr), 1, fr))
  {
  fwrite(&Dnr, sizeof(Dnr), 1, fw);	
  }
   
  fclose(fr);
  fclose(fw);
  printf("\nRECORD DELETED\n");
 }
//}
 // MAIN PROGRAM
void main()
{
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               DONOR INFORMATION                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################"); 
 int c;
 char n[20];
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n 1. INSERT");
  printf("\n 2. DISPLAY");
  printf("\n 3. SEARCH");
  printf("\n 4. DELETE");
  printf("\n 5. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
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
while (c != 5);
} 

#include<stdio.h>
#include<conio.h>
struct Recipient
{
	char name[20];
	int age;
	int contact_number;
	char blood_type[5];
}Rec;
char fileRecipient[]="RecRecord.txt";
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
 fp1 = fopen(fileRecipient, "r");
 printf("\n NAME \t\t\t AGE \t\t\t CONTACT NUMBER \t\t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Rec, sizeof(Rec), 1, fp1))
 {
 	printf("\n %s\t\t\t%d\t\t\t%d\t\t\t%s\n", Rec.name, Rec.age, Rec.contact_number,Rec.blood_type);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchRec()
{
 FILE *fp2;
 int  a,avl=0;
 char n[20];
 printf("\nEnter the name you want to search:");
 scanf("%s",n);
 fp2 = fopen(fileRecipient,"r");
while (fread(&Rec, sizeof(Rec),1,fp2))
{
if(!strcmp(n,Rec.name))
{
 printf("\n Name = %s", Rec.name);
    printf("\n Age  = %d", Rec.age);
    printf("\n Contact number  = %d\n", Rec.contact_number);
    printf("\n Blood type  = %s\n", Rec.blood_type);
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
  fr = fopen(fileRecipient, "r");
  fw = fopen("TempFile", "w");

 while (fread(&Rec, sizeof(Rec), 1, fr))
{
if(strcmp(n,Rec.name))
{
 fwrite(&Rec, sizeof(Rec), 1, fw);
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
  fwrite(&Rec, sizeof(Rec),1,fw);	
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
    printf("\n\t\t\t############               RECIPIENT INFORMATION               ############");
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
while (c != 5);
} 

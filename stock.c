#include<stdio.h>
#include<conio.h>
struct Stock
{
	int blood_quantity;
	char blood_type[5];
}Stk;
char fileStock[]="StkRecord.txt";
void insertStk()
{
 FILE *fp;
 fp=fopen(fileStock,"a+");
 printf("Enter the Blood Quantity:");
 scanf("%d", &Stk.blood_quantity);
 printf("Enter the Blood Type:");
 scanf("%s", Stk.blood_type);
 fwrite(&Stk, sizeof(Stk),1 , fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispStk()
{
 FILE *fp1;
 int eof;
 fp1 = fopen(fileStock, "r");
 printf("\n BLOOD QUANTITY \t BLOOD TYPE \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while (fread(&Stk, sizeof(Stk), 1, fp1))
 {
 	printf("\n %d\t\t\t\t%s\n", Stk.blood_quantity,Stk.blood_type);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchStk()
{
 FILE *fp2;
 int  a,avl=0;
 char n[20];
 printf("\nEnter the blood type you want to search:");
 scanf("%s",n);
 fp2 = fopen(fileStock,"r");
while (fread(&Stk, sizeof(Stk),1,fp2))
{
if(!strcmp(n,Stk.blood_type))
{
    printf("\n Blood quantity  = %d\n", Stk.blood_quantity);
    printf("\n Blood type  = %s\n", Stk.blood_type);
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
void main()
{
	printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############               STOCK INFORMATION                   ############");
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
while (c != 5);
} 

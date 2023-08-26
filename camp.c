#include<stdio.h>
#include<conio.h>
struct Camp
{
	char city[20];
	char venue[20];
	char organizer[20];
}Cmp;                                //Cmp: struct varible
char filecamp[]="CmpRecord.txt";
void insertCmp()
{
 FILE *fp;
 fp=fopen(filecamp,"a+");
 printf("Enter the City:");
 scanf("%s",Cmp.city);            // .->Access structure member
 printf("Enter the Venue:");
 scanf("%s",Cmp.venue);
 printf("Enter the organizer:");
 scanf("%s",Cmp.organizer);
 fwrite(&Cmp,sizeof(Cmp),1,fp);
 //fprintf(fp,"%d,%d,%s,%s",Dnr.age,Dnr.contact_number,Dnr.name,Dnr.blood_type);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void dispCmp()
{
 FILE *fp1;
 int eof;
 fp1 = fopen(filecamp,"r");
 printf("\n CITY \t\t\t VENUE \t\t\t ORGANIZER \n\n");
 /*eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);
 printf("\n %s\t\t%d\t%d\t%s\n", Dnr.name, Dnr.age, Dnr.contact_number,Dnr.blood_type);
 eof=fread(&Dnr,sizeof(Dnr),1,fp1);
 printf("%d",eof);*/
 while(fread(&Cmp,sizeof(Cmp),1,fp1))
 {
 	printf("\n %s\t\t%s\t\t\t%s\n", Cmp.city,Cmp.venue,Cmp.organizer);
 }
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void searchCmp()
{
 FILE *fp2;
 int a,avl=0;
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
 scanf("%s",n);
  fr = fopen(filecamp,"r");
  fw = fopen("TempFile","w");
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
  fr = fopen("TempFile", "r");
  fw = fopen(filecamp, "w");
  while (fread(&Cmp, sizeof(Cmp),1,fr))
  {
  fwrite(&Cmp,sizeof(Cmp),1,fw);	
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
    printf("\n\t\t\t############               CAMP INFORMATION                    ############");
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
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;
}
}
while (c != 5);
} 

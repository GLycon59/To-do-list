#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>

#define Gr 10
#define Rd 12
#define Bl 3
#define Yl 6
#define W 15
#define Cy 11

void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}



void afisare(int *arr,char nume[])
{FILE *fPointer;
    fPointer=fopen(nume,"r");
    char nr_task[10];
    fgets(nr_task,10,fPointer);
    int nr=atoi(nr_task);
    set_color(Cy);
printf("<==="); set_color(Bl);
for(int j=0;j<strlen(nume)-4;j++)
    printf("%c",nume[j]);
set_color(Cy);printf("===>\n");
set_color(W);
    for(int i=0;i<nr;i++)
        {
            char sir[255];
            fgets(sir,255,fPointer);
            if(arr[i]!=0)
                {set_color(W);printf("[");
                set_color(Rd);printf("X");
                set_color(W);printf("]");
                set_color(Gr);printf("%d)",i+1);
                set_color(Yl);printf("%s",sir);
                set_color(W);
            }

            else {printf("[ ]");
            set_color(Gr);printf("%d)",i+1);
            set_color(Yl);printf("%s",sir);
            set_color(W);

            }
        }
    printf("\n_______________\n");
 fclose(fPointer);
}
///****************************************************///
void delete(char nume[],int alg)
{FILE *FP=fopen("Fisiere.txt","r");
char temporar[]="temporar.txt",str[50];
FILE *temp=fopen(temporar,"w+");

while(!feof(FP))
{strcpy(str,"\0");
fgets(str,50,FP);
if(!feof(FP));
        if(alg!=0)
            {fprintf(temp,"%s",str);
            }
        alg--;

}
fclose(FP);
fclose(temp);
remove(nume);
char fisier[]="Fisiere.txt";
remove(fisier);
rename(temporar,"Fisiere.txt");
}

///****************************************************///
void selectare_opt_fisier(int *arr,int nr,char nume[],int alg)
{afisare(arr,nume);
int numar=0;
while(numar<nr)
    {
      printf("Selecteaza:");
      int alegere=-1;
      do{set_color(Gr);
         scanf("%d",&alegere);
        }while((alegere<0)||(alegere>nr));
      if(arr[alegere-1]!=1){arr[alegere-1]=1;
      numar++;}
        set_color(W);
      system("CLS");
      afisare(arr,nume);
    }
delete(nume,alg);
system("PAUSE");
system("CLS");
Meniu();

}
///****************************************************///

void fisier(char nume[],int alg)
{FILE *fPointer;
fPointer=fopen(nume,"r");
char nr_task[10];
fgets(nr_task,10,fPointer);
int nr=atoi(nr_task);
fclose(fPointer);
int *arr;
arr=(int *)calloc(nr,sizeof(int));
selectare_opt_fisier(arr,nr,nume,alg);
}
///****************************************************///
void creare_fisier()
{char nume[50];
set_color(Rd);
printf("Fisierul nu trebuie sa contina /?\.\n");
set_color(W);
printf("Nume fisier:");
set_color(Cy);
scanf("%s",nume);
set_color(W);
strcat(nume,".txt");
FILE *FP=fopen(nume,"w+");
fputs("000\n",FP);
fclose(FP);
system("CLS");
FP=fopen("Fisiere.txt","a");
fputs(nume,FP);
fclose(FP);
Meniu();
}


///****************************************************///

void Meniu(void)
{int alg=0;
set_color(Rd);
printf("<==="); set_color(Bl);printf("MENIU");set_color(Rd);printf("===>\n");
set_color(W);
set_color(Gr);printf("1)");
set_color(Cy);printf("Vezi Fisiere\n");
set_color(Gr);printf("2)");
set_color(Cy);printf("Creeaza fisier\n");
set_color(Gr);printf("3)");
set_color(Rd);printf("Stop\n");
set_color(W);
do{set_color(W);
    printf("Alege: ");
    set_color(Gr);scanf("%d",&alg);
}while((alg<=0)||(alg>3));
set_color(W);
if(alg==1){system("CLS");afisare_fisiere();}
else if(alg==2){system("CLS");creare_fisier();}
else exit(1);
}
///****************************************************///

void adaugare(char nume[],int alg)
{
FILE *FP;
FP=fopen(nume,"r+");
    char nr_task[4];
    fgets(nr_task,4,FP);
    int numar=atoi(nr_task);
fclose(FP);
char nr[10];
numar++;
if(numar<10)sprintf(nr,"00%d",numar);
else if(numar<100)sprintf(nr,"0%d",numar);
else sprintf(nr,"%d",numar);
FP=fopen(nume,"r+");
fprintf(FP,nr);
fclose(FP);

char nume_task[30];
printf("Scrie un task:");
//gets(nume_task);
set_color(Cy);
scanf("%s",nume_task);
set_color(W);
FP=fopen(nume,"a");
fputs(nume_task,FP);
fputs("\n",FP);
fclose(FP);
system("CLS");
selectare_afisare_scriere_fisier(nume,alg);
}

///****************************************************///
void selectare_afisare_scriere_fisier(char nume[],int alg)
{set_color(Gr);printf("1)");
set_color(W);printf("Adauga task\n");
 set_color(Gr);printf("2)");
 set_color(W);printf("Afiseaza taskuri\n");
set_color(Gr);printf("3)");
set_color(Rd);printf("Back\n");
set_color(W);printf("______________\n");
 int alegere=0;
 do{set_color(W);
    printf("Selecteaza:");
    set_color(Gr);
    scanf("%d",&alegere);
 }while((alegere<=0)||(alegere>3));
 set_color(W);
if (alegere==2){system("CLS");fisier(nume,alg);}
else if(alegere==3){system("CLS");afisare_fisiere();}
else {system("CLS");adaugare(nume,alg);}
}
///****************************************************///
void afisare_fisiere(void)
{
    char nume[200][50];
    FILE *fp;
    fp=fopen("Fisiere.txt","r");
    int k=0;
    while(fgets(nume[k],50,fp))
    {nume[k][strcspn(nume[k], "\n")] = 0;
    k++;
    }
    fclose(fp);
    int alg=-1;
    set_color(Rd);
    printf("<==="); set_color(Bl);printf("Fisiere");set_color(Rd);printf("===>\n");
    set_color(Gr);printf("0)");
    set_color(W);printf("Back\n");
    for(int i=1;i<=k;i++)
       {
        set_color(Gr);printf("%d)",i);
        set_color(W);printf("%s\n",nume[i-1]);
       }
    printf("_____________\n");
    do{
        printf("Alege fisier:");
        set_color(Gr);
        scanf("%d",&alg);
        set_color(W);
    }while((alg<0)||(alg>k));
    if(alg==0){system("CLS");Meniu();}
    system("CLS");selectare_afisare_scriere_fisier(nume[alg-1],alg-1);

}
///****************************************************///
void director(void)
{
     DIR *d;
     FILE *FP;
     FP=fopen("Fisiere.txt","w+");
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {   if(strstr(dir->d_name,".txt")&&(strcmp(dir->d_name,"Fisiere.txt")))
                {fputs(dir->d_name,FP);
                 fputs("\n",FP);
                }

        }
    fclose(FP);
    closedir(dir);
    }

}

///****************************************************///


int main()
{   director();
    Meniu();

    return 0;
}

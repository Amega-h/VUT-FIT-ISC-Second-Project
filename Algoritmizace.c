                                            /*
                                    Shaposhnik Bogdan
                                        xshapo04
                                       04.11.2022
                                Uloha 2./3. čast projectu
                    E-mail: shaposhnikbogdan@gmail.com || xshapo04@vutbr.cz
                                            */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//Datum structure
//days,months and years are depicted in integers wich can be only over 0
struct datum {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
//Student structure
//char array for login , which maximum is 8 symbols ||| char array both for name and surname ,which maximum is 102 symbols
struct student 
{
    char login[8];
    char jmeno[102];
    char prijmeni[102];
};
//Predmet structure
// char array for name of subject , which maximum is 102 symbols ||| char array for short name of subject ,which maximum is 5 symbols
struct predmet 
{
    char jmeno[102];
    char zkratka[5];
};
//Rozvrh structure
//stucts of student, whoes this schedule is ||| struct of subjects for this student
struct rozvrh 
{
    struct student stud;
    struct predmet pred[10];
};
//says whats date is earlier than other 
int porovnej (struct datum dat1,struct datum dat2)
{
    if (dat1.year < dat2.year)
        return -1;
    else if (dat1.year > dat2.year)
        return 1;
    else if (dat1.month < dat2.month)
        return -1;
    else if (dat1.month > dat2.month)
        return 1;
    else if (dat1.day < dat2.day)
        return -1;
    else if (dat1.day > dat2.day)
        return 1;
    else 
        return 0;
}
//count how many days are between two dates 
int rozdilData (struct datum dat1,struct datum dat2)
{
    if (dat1.year != dat2.year)
        return -1;
    else if (dat1.month != dat2.month)
        return -1;
    else if (dat1.day < dat2.day)
        return (dat2.day - dat1.day);
    else 
        return (dat1.day - dat2.day);
}
//checks if there is subject (predmet p) in schedule (rozvrh r)
bool maPredmet (struct rozvrh r,struct predmet p)
{
 for (int i = 0;i<10;i++)
 {
    // if it founds char array(p.zkratka) in char array (r.pred[i].zkratka) then it returns boolean meaning true(in int it will be 1)
    if (strstr(r.pred[i].zkratka,p.zkratka) != NULL)
    {
        return true;
    }
 } 
 // if not , it returns boolean meaning false(in int it will be 0)
 return false;
}
int main()
{
    // test space for first function(porovnej) and second one (rozdiData)
    struct datum datPr1;
    struct datum datPr2;
    datPr1.year = 2001;
    datPr1.month = 12;
    datPr1.day = 25;
    datPr2.year = 2001;
    datPr2.month = 12;
    datPr2.day = 20;
    printf ("Result of first function is : %d\n",porovnej(datPr1,datPr2));
    printf ("Result of second function is : %d\n",rozdilData(datPr1,datPr2));
    //test space for third function(maPredmet)
    struct predmet predm;
    predm.zkratka[0]='a';
    predm.zkratka[1]='d';
    predm.zkratka[2]='v';
    struct rozvrh roz;
    roz.pred[1].zkratka[0] = 'a';
    roz.pred[1].zkratka[1] = 'b';
    roz.pred[1].zkratka[2] = 'v';
    roz.pred[2].zkratka[1] = 'a';
    roz.pred[2].zkratka[2] = 'd';
    roz.pred[2].zkratka[3] = 'v';
    int temp ;
    printf("Result of third function is: %d\n",maPredmet(roz,predm));
}
<span style="font-size:18px;">#include<stdio.h>     /*I/o函数*/

#include<stdlib.h>    /*其他说明*/

#include<string.h>    /*字符串函数*/

#define LEN 30        /*学号和姓名最大学生人数*/

#define N  100        /*最大学生人数*/

struct  record       /*声明函数体*/

 { 

  char code[20];     /*学号*/

  char name[10];     /*姓名*/

  int   age;          /*年龄*/

  char sex[5];       /*性别*/

  char time[20];     /*出生年月*/

  char addr[20];      /*家庭地址*/

  char tel[20];      /*电话*/

  char mail[20];     /*邮箱地址*/

 }stu[N];

 

int k=1,m,n;

 void Input();

 void Inquire();

 void Amend();

 void Add();

 void Delete();

 void Display();

 void Save();

 void menu();

 void Exit(); 

 void Welcome(); 

 

int main()

 {  

  while(k)

  {

   

   Welcome();

   system("pause");

   system("cls");

   printf("请按任意键进入主菜单!\n");

   system("cls");

   menu();

   system("pause");

  }

  return 0; 

 }

 

void help()

 {         system("COLOR 2f");

 printf("\n  尊敬的用户您好!");

printf("\n  ============================================================\n  |                                                          |");

 printf("\n  |             1.欢迎进入帮助系统!                          |\n  |                                                          |");

 printf("\n  |   ★    ★    ★     ★    ★     ★     ★    ★        |\n  |                                                          |");

 printf("\n  |             2.请按照菜单提示进入数字代号!                |\n  |                                                          |");

 printf("\n  |             3.增加学生信息后，请切记保存!                |\n  |                                                          |");

 printf("\n  |             4.谢谢您的使用!                              |\n  |                                                          |");

 printf("\n  ============================================================\n   ");

 }

 void Input()            /* 实现录入学生基本信息功能 */

 {

  int i,flag=1;

  while(flag)

  {

   flag=0;

   printf("请输入需要创建信息的学生人数（1-100):\n");

   scanf("%d",&n);

   if(n<1||n>100)

   {

    flag=1;

    printf("输入错误，检查后请重新输入!\n");

   }

  }

  for(i=0;i<n;i++)

  {

   printf("请输入第%d个学生的基本信息:\n",i+1);

   printf("请输入学号:\n");

   scanf("%s",stu[i].code);

   printf("请输入姓名:\n");

   scanf("%s",stu[i].name);

   getchar();

   printf("请输入性别(男，女）:\n");

   scanf("%s",stu[i].sex);

   printf("请输入年龄:\n");

   scanf("%d",&stu[i].age);

   printf("请输入出生年月(输入格式:年.月):\n");

   scanf("%s",stu[i].time);

   printf("请输入家庭地址:\n");

   scanf("%s",stu[i].addr);

   printf("请输入电话号码:\n");

   scanf("%s",stu[i].tel);

   printf("请输入E-mail地址:\n");

   scanf("%s",stu[i].mail);

  }

  printf("录入完毕!\n");

  Save();

 }

 

void Save()                       /*保存学生信息到文件的函数*/

 {

  int i;

  FILE *fp;

  if((fp=fopen("student.txt","wb"))==NULL)      /*创建文件并判断是否能够打开成功*/

  {

   printf("文件不能打开!\n");

   exit(0);                              /*如果不能打开文件，则关闭当前所有的文件*/

  }

  for(i=0;i<n;i++)                             /*将内存中的学生信息写入到磁盘文件中*/

   if(fwrite(&stu[i],sizeof(struct record),1,fp)!=1)

             printf("文件输入错误!\n");

   fclose(fp);                               /*关闭文件*/

 }

 

void Inquire()

 {

  int i,t,flag;

  char s1[30];

  system("COLOR 5f");

  printf("\n                =================================\n");

  printf("                |         1.按学号查询          |\n");

  printf("                |         2.按姓名查询          |\n");

  printf("                |         3.退出本菜单          |\n");

  printf("                =================================\n");

  while(1)

  {

         flag=0;

   printf("                请输入子菜单编号: ");

   scanf("%d",&t);

   switch(t)

   {

   case 1:

    printf("                请输入要查询的学生的学号: \n");

    scanf("%s",s1);

    for(i=0;i<n;i++)

     if(strcmp(stu[i].code,s1)==0)

     {

      flag=1;

      printf("学生学号    学生姓名    年龄     性别    出生年月     家庭地址      电话       E-mail   \n");

      printf("================================================================================\n");

      printf("%6s %7s %6d %5s %9s %8s %10s %14s\n", stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].time,stu[i].addr,stu[i].tel,stu[i].mail);

     } 

     if(flag==0)

      printf("该学号不存在!  \n");break;

   case 2:

    printf("                请输入要查询的学生的姓名: \n");

    scanf("%s",s1);

    for(i=0;i<n;i++)

     if(strcmp(stu[i].name,s1)==0)

     {

      flag=1;

      printf("学生学号    学生姓名    年龄     性别    出生年月     家庭地址     电话        E-mail  \n");

      printf("================================================================================\n");

      printf("%6s %7s %6d %5s %9s %8s %10s %14s\n", stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].time,stu[i].addr,stu[i].tel,stu[i].mail);

     }

     if(flag==0)

      printf("该姓名不存在!\n");break;

   case 3:

    return;

   default:

    printf("请在1--3之间选择\n");

         }

  }

 }

 void Amend()

 {

  int i,t,num;

  char sex1[3],s1[30],s2[30];

  printf("                请输入要查询的学生的学号:\n");

  scanf("%s",s1);

  for(i=0;i<n;i++)

   if(strcmp(stu[i].code,s1)==0)

    num=i;

   system("COLOR 4f");

   printf("             =============================================\n");

   printf("             |               1.修改姓名                  |\n");

   printf("             |               2.修改年龄                  |\n");

   printf("             |               3.修改性别                  |\n");

   printf("             |               4.修改出生年月              |\n");

   printf("             |               5.修改地址                  |\n");

   printf("             |               6.修改电话号码              |\n");

   printf("             |               7.修改E-mail                |\n");

   printf("             |               8.修改退出本菜单            |\n");

   printf("             =============================================\n");

   while(1)

   {

    printf("请输入子菜单的编号:");

    scanf("%d",&t);

    switch(t)

    {

    case 1:

     printf("请输入新的姓名:\n");

     scanf("%s",s2);

     strcpy(stu[num].name,s2);break;

    case 2:

     printf("请输入新的年龄:\n");

     scanf("%s",s2);

     scanf("%d",&stu[num].age);break;

     

    case 3:

     printf("请输入新的性别:\n");

     scanf("%s",sex1);

     strcpy(stu[num].sex,sex1);break;

     

    case 4:

                 printf("请输入新的出生年月: \n");

     scanf("%s",s2);

     strcpy(stu[num].time,s2);break;

     

    case 5:

     printf("请输入新的地址: \n");

     scanf("%s",s2);

     strcpy(stu[num].addr,s2);break;

     

    case 6:

     printf("请输入新的电话号码: \n");

     scanf("%s",s2);

     strcpy(stu[num].tel,s2);break;

     

    case 7:

     printf("请输入新的E-mail: \n");

     scanf("%s",s2);

     strcpy(stu[num].mail,s2);break;

     

    case 8:    

     return;

    default:

     printf("请在1--8之间选择\n");}

   }

   

 }

 void Sort()

 {

  int i,j,*p,*q,s;

  char temp[10];

  for(i=0;i<n-1;i++)

  {

   for(j=n-1;j>i;j--)

    if(strcmp(stu[j-1].code,stu[j].code)>0)

    { 

     strcpy(temp,stu[j-1].code);

     strcpy(stu[j-1].code,stu[j].code);

     strcpy(stu[j].code,temp);

     strcpy(temp,stu[j-1].name);

     strcpy(stu[j-1].name,stu[j].name);

     strcpy(stu[j].name,temp);

     strcpy(temp,stu[j-1].sex);

     strcpy(stu[j-1].sex,stu[j].sex);

     strcpy(stu[j].sex,temp);

     strcpy(temp,stu[j-1].time);

     strcpy(stu[j-1].time,stu[j].time);

     strcpy(stu[j].time,temp);

     strcpy(temp,stu[j-1].addr);

     strcpy(stu[j-1].addr,stu[j].addr);

     strcpy(stu[j].addr,temp);

     strcpy(temp,stu[j-1].tel);

     strcpy(stu[j-1].tel,stu[j].tel);

     strcpy(stu[j].tel,temp);

     strcpy(temp,stu[j-1].mail);

     strcpy(stu[j-1].mail,stu[j].mail);

     strcpy(stu[j].mail,temp);

     p=&stu[j-1].age;

     q=&stu[j].age;

     s=*p;

     *p=*q;

     *q=s;

    }

  }

 }

 

void Add()

 {

     int i=n,j,flag;

     printf("请输入将要增加的学生数目:\n");

     scanf("%d",&m);

  do

  {

         flag=1;

   

   while(flag)

   {

    flag=0;

    printf("请输入第%d个学生的学号:\n", i+1);

    scanf("%s",stu[i].code);

    for(j=0;j<i;j++)

     if(strcmp(stu[i].code,stu[j].code)==0)

     {

      printf("该学号已经存在，请仔细核查后重新输入!\n");

      flag=1;break;

     }

   }

   

   printf("请输入第%d个学生的学生姓名:\n",i+1);

   scanf("%s",stu[i].name);

   printf("请输入第%d个学生的学生年龄:\n",i+1);

   scanf("%d",&stu[i].age);

   printf("请输入第%d个学生的学生性别:\n",i+1);

   scanf("%s",stu[i].name);

   printf("请输入第%d个学生的学生出生年月:(格式:年,月,日)\n",i+1);

   scanf("%s",stu[i].time);

   printf("请输入第%d个学生的学生家庭地址:\n",i+1);

   scanf("%s",stu[i].addr);

   printf("请输入第%d个学生的学生电话:\n",i+1);

   scanf("%s",stu[i].tel);

   printf("请输入第%d个学生的学生E-mail:\n",i+1);

   scanf("%s",stu[i].mail);

   if(flag==0)

    i++;

  }while(i<n+m);

  

  n=n+m;

  printf("输入完毕!\n\n");

  Sort();

  

 }

 

void  Delete()

 {

     int i,j,flag=0;

     char s1[15];

     printf("请输入将要删除的学生的学号:\n");

     scanf("%s",s1);

     for(i=1;i<n;i++)

   if(strcmp(stu[i].code,s1)==0)

   {

    flag=1;

    for(j=i;j<n-1;j++)

                 stu[j]=stu[j+1];

   }

   if(flag==0)

    printf("该学号不存在!\n");

   if(flag==1)

   {

    printf("删除成功!显示结果请按6!\n");

    n--;

   }

 }

void Display()

 {

  int i;

  FILE *fp;

  if((fp=fopen("student.txt","rb"))==NULL)

  {

   printf("打开文件时错误!请按任意键退出!");

   system("pause");

   exit(0);

  }

  printf("                        所有学生的信息为：\n \n");

  printf("学生学号   学生姓名   年龄   性别   出生年月   家庭地址    电话     E-mail      ");

  printf("================================================================================");             

  for(i=0;i<n;i++)   

  {     fread(&stu[i],sizeof(struct record),1,fp);

  printf("%6s %7s %6d %5s %9s %8s %10s %14s\n", stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].time,stu[i].addr,stu[i].tel,stu[i].mail);

  }

 }

 

void Exit() 

 { 

  system("COLOR 3f");

  printf("                     --------【学生信息管理系统】-------\n");

  printf("\n");

  printf("\n");

  printf("                               制作人:齐               \n");

  printf("================================================================================\n");

  printf("                             ●☆☆Bye-Bye☆☆●\n");

  printf("\n");

  printf("     ★★★★★★★★★★★★★★           ★★★★★★★★★★★★★★\n");

  printf("\n");

  printf("                            \n");

  printf("                            ☆☆☆☆☆☆☆☆☆☆☆\n");

  printf("\n");

  printf("                            ★★★★★★★★★★★\n");

  printf("                                  信  ★  计               \n");

  printf("                                  阳  ★  算               \n");

  printf("                                  师  ★  机                \n");

  printf("                                  范  ★  五             \n");

  printf("                                  学  ★  一               \n");

  printf("                                  院  ★  班               \n");

  printf("                                      ★                 \n");

  printf("                                      ★                 \n");

  printf("                                 ◆谢谢使用◆\n");

 }

 void Welcome()

 {   

  system("COLOR 6f");

  printf("\n");

  printf("\n");

  printf("\n");

  printf("---------★------------------------信阳师范学院----------------------★---------\n");

  printf("\n");

  printf("\n");

  printf("\n");

  printf("\n");

  printf("\n");

  printf("                               尊敬的用户:您好!\n");

  printf("\n");

  printf("\n");

  printf("                                    欢迎使用\n");

  printf("\n");

  printf("\n");

  printf("                    -------☆-【学生信息管理系统】-☆------\n");

  printf("\n");

 

}

 void menu()

 {    

  int num;

 

 system("COLOR 1f"); 

  printf("\n\n                             计算机系14级学生信息管理系统\n\n");

  printf("================================================================================\n");

  printf("                      ===============制作人：齐===========\n");

  printf("\n");

  printf("                      ==============系统功能菜单==============\n");

  printf("                      =======友情提醒：查询前请刷新系统!======\n");

  printf("                      ========================================\n");

  printf("                      |======================================|\n");

  printf("                      |   0.系统帮助说明     1.输入学生信息  |\n");

  printf("                      |--------------------------------------|\n");

  printf("                      |   2.查询学生信息     3.修改学生信息  |\n");

  printf("                      |--------------------------------------|\n");

  printf("                      |   4.增加学生信息     5.按学号删信息  |\n"); 

  printf("                      |--------------------------------------|\n");

  printf("                      |   6.显示当前信息     7.保存当前信息  |\n");

  printf("                      |--------------------------------------|\n");

  printf("                      |             8.退出系统               |\n");

  printf("                      |======================================|\n");

  printf("                      ========================================\n");

  printf("请选择菜单编号: ");

  scanf("%d",&num);       

  switch(num)

  {

   case 0:system("cls");help();break;

   case 1:system("cls");Input();break;

   case 2:system("cls");Inquire();break;

   case 3:system("cls");Amend();break;

   case 4:system("cls");Add();break;

   case 5:system("cls");Delete();break;

   case 6:system("cls");Display();break;

   case 7:system("cls");Save();break;

   case 8:system("cls");k=0;Exit();

    break;

   default:

    printf("请在1--8之间选择\n");

  }

 }

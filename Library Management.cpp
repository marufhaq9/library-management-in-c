//Portion of source codes credit goes to a website where i found this project(not the whole project), and rest of the code done by me(Mahmudul Maruf)..
//01-01-2015 as a final project of our course
#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <time.h>
#include <process.h>
#define RETURNTIME 15
using namespace std;
//////My functions////Do not edit below/////
int t();
void booklist();
void br_menu();
void menu();
int checkbk(int t);
void search();
void maruf();
//void unlock();
void exitt();
void editbooks();
void returnfunc();
void removebooks();
void style();
void mrf();
void lm();
//////////main
struct library
{
    char bname[40];
    char author[30];
    char dept[15];
    int quantity;
    int id;
    int rack_no;
    ////////////for borrower///
    char stname[30];
    char borrowed[21];
    char returned[20];
    int stid;

} l;
int ent;
int i,j,result,la,s;
char a;
char query[20],findbook,bname[33];
//char password[15]={"maruf"};
FILE *fp, *ft;

main()
{
    //unlock();
    style();
    cout<<"\n";
    system("pause");
    menu();
    getch();
}
//////////////menu by maruf//////////////
void menu()
{
main:
    system("cls");
    //system("color 27");
    printf("\n\t\t    \xB1\xB1\xB1\xB1\xB1\xB2\xB2\xB1\xB1 Library Manager \xB1\xB1\xB2\xB2\xB1\xB1\xB1\xB1\xB1\n");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    t();
    cout<<"\n\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n";

    printf("\n\t\t\xDB\xDB\xB1\xB1[1].Add a Book\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[2].View Booklist\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[3].Search a Book\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[4].Borrow a Book\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[5].Edit a Book\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[6].Delete a Book\n\t\t______________\n");

    printf("\t\t\xDB\xDB\xB1\xB1[7].Exit\n\t\t______________\n");

choice:

    printf("\t\t\xDE\xDE Enter your choice : ");
    scanf("%s", &a);
    //getchar(a);
    switch(a)
    {

    case '1':
add:
        system("cls");
        //system ("color 57");
        //char *ex;
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Adding a Book \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        ///////
        fp=fopen("maruf.txt","a");
        fflush(stdin);
        printf("\n\t\t[\xAF] Book name : ");
        scanf("%[^\n]", &l.bname);
        //gets(l.bname);
        if(stricmp(l.bname,"")==0 || stricmp(l.bname," ")==0)
            break;
        fflush(stdin);
        /////////
        printf("\n\t\t[\xAF] Author name : ");
        gets(l.author);
        fflush(stdin);
        /////////
        printf("\n\t\t\[\xAF] Book ID : ");
        scanf("%d", &l.id);
        fflush(stdin);
        //////////
        printf("\n\t\t[\xAF] Department name : ");
        gets(l.dept);
        fflush(stdin);
        /////////
        printf("\n\t\t\[\xAF] Quantity : ");
        scanf("%d", &l.quantity);
        fflush(stdin);
        //////////
        printf("\n\t\t[\xAF] Rack no: ");
        scanf("%d", &l.rack_no);
        fflush(stdin);
        //////////
        fwrite(&l,sizeof(l),1,fp);
        fclose(fp);
        fflush(stdin);
        printf("\n This Book is Added Successfully....\n ");
again:
        printf("\n\t\t Want to add more books??\n");
        printf("\n\t\t\t\xAF Enter 1/0 from your keyboard....\n\t\t\t(Remember 1 for Yes and 0 for No(Main Menu). :))");
        printf("\n\t\t\t Enter : ");
        scanf("%d", &ent);
        if(ent==1)
        {
            goto add;
        }
        else if(ent==0)
        {
            goto main;
        }
        else
        {
            cout<<"You have entered a wrong key"<<endl;
            //pause(3);
            goto again;
        }
        ///////
        break;
    /********************Book list**************************/
    case '2':
        booklist();
        break;
    /****************Search Book By Maruf*************************/
    case '3':
        search();	/////search function call
        break;
    /*******************Borrow books By Boss Maruf :p *******************/
    case '4':
        br_menu();	//Borrow function call
        break;
    case '5':
        editbooks();
        break;
    /*******************Delete books******************/
    case '6':
        removebooks();
        break;
    /*******************Program Exit By Maruf*********************/
    case '7':
        exitt();
        break;
    default:
        //system("cls");
        cout<<"\n\n\t\t\xDB\xDB\xB1\xB1 You have Entered a Wrong Key.. :(\n"<<endl;
        goto choice;
        break;
    }
}
////***********Time Generator By Maruf****************////
int t()
{
    time_t t;
    time(&t);
    printf("\t\t   Date and time:%s\n",ctime(&t));
    return 0;
}
/////********Booklist Function ;) Maruf**********////
void booklist()
{
    system("cls");
    //system("color 17");
    fflush(stdin);
    result=4;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Viewing Book List \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    //////
    fp=fopen("maruf.txt","r");
    fflush(stdin);
    while(fread(&l,sizeof(l),1,fp)==1)
    {
        printf("\nBook Name : %s", l.bname);

        printf("\nAuthor : %s", l.author);

        printf("\nBook ID : %d", l.id);

        printf("\nDepartment : %s", l.dept);

        printf("\nQuantity : %d", l.quantity);

        printf("\nRack no : %d", l.rack_no);
        cout<<"\n_______________________\n";
        result++;
    }
    /*else if(checkbk(l.id)==0)
    {
    cout<<"\n\t\t\t\xDB\xDB\xB1\xB1";
    cout<<"\n\t\t\t\xDB\xDB\xB1\xB1 Book list is Empty \xDB\xDB\xB1\xB1";
    cout<<"\n\t\t\t\xDB\xDB\xB1\xB1";
    }*/
    printf("\n\n\t\t\t\xAF\xAF\xAF Enter 1/0 from your keyboard....\n\t\t\t(Remember 1 for Main menu and 0 for Exit. :))");
    printf("\n\t\t\t \xDB\xB1\xB1 Enter : ");
    scanf("%d", &ent);
    if(ent==1)
    {
        menu();
    }
    else if(ent==0)
    {
        exitt();
    }
    else
    {
        cout<<"You have entered a wrong key"<<endl;
        system("pause");
        menu();
    }
    fclose(fp);
}
////********Borrow menu by maruf***********///
void br_menu()
{
    int t;
issue:
    system("cls");
    //system("color 37");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BORROW SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\xDB\xDB\xDB\xB2 [1]. Borrow a Book\n");
    printf("\n\t\xDB\xDB\xDB\xB2 [2]. View Borrowed Book\n");
    printf("\n\t\xDB\xDB\xDB\xB2 [3]. Search Borrowed Book\n");
    printf("\n\t\xDB\xDB\xDB\xB2 [4]. Remove Borrowed Book\n");
    printf("\n\t\xDB\xDB\xDB\xB2 [5]. Back to Main Menu\n");
    printf("\n\t Enter a Choice : ");
    switch(getch())
    {
    case '1':		//Borrow
    {
        system("cls");
        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            printf("\n\n\t\t\t\xB2\xB2\xB2 Borrow Book section \xB2\xB2\xB2\n");
            printf("\n\xB2\xB2 Enter the Book Id : ");
            scanf("%d",&t);
            fp=fopen("maruf.txt","r");
            ft=fopen("borrow.dat","a");
            if(checkbk(t)==0) 		//Check book to borrow those which are present in library
            {
                printf("\n\t\xDB\xDB\xB2 The book record is available\n");
                printf("\n\t\xDB\xDB\xB2 There are %d unissued books in library \n",l.quantity);
                printf("\n\t\xDB\xDB\xB2 The name of book is \xAF %s",l.bname);
                cout<<"\n\t_________________________\n";
                printf("\n\t\xDB\xB2 Enter student name : ");
                scanf("%s",l.stname);
                fflush(stdin);
                printf("\n\t\xDB\xB2 Enter student ID : ");
                scanf("%d",&l.stid);
                fflush(stdin);
                printf("\n\t\xDB\xB2 Enter Borrowed Date(10/12/2014) : ");
                scanf("%s",&l.borrowed);
                //gets(l.borrowed);
                //////////
                printf("\n\t\xDB\xB2 Enter Return Date(15/12/2014) : ");
                //gets(l.returned);
                scanf("%s",&l.returned);

                ////////////
                cout<<"\n\t_________________________\n";
                printf("\n\t\xDB\xB2 The BOOK of ID %d is Borrowed \n",l.id);
                printf("\n\t\xDB\xB2 Borrowed date : %s",l.borrowed);
                printf("\n\t\xDB\xB2 To be return : %s",l.returned);
                //fseek(ft,sizeof(l),SEEK_END);
                fwrite(&l,sizeof(l),1,ft);
                fclose(ft);
                c=1;
            }
            if(c==0)
            {
                printf("\n\t\t No record found");
            }
            printf("\n\t\t Borrow any more(Y/N) : ");
            fflush(stdin);
            if(getch()=='y')
                goto issue;
            else
                menu();
            fclose(fp);
        }
        break;
    }
    case '2':	/////////Borrowed booklist start
    {
        system("cls");
        //system("color 47");
        result=4;
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Viewing Borrowed Books \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        ft=fopen("borrow.dat","r");
        fflush(stdin);
        while(fread(&l,sizeof(l),1,ft)==1)
        {
            printf("\nStudent Name : %s",l.stname);

            printf("\nStudent ID : %d",l.stid);

            printf("\nBook Name : %s",l.bname);

            printf("\nBook ID : %d",l.id);

            //printf("\nDepartment : %s",l.dept);

            printf("\nBorrowed Date : %s",l.borrowed);

            printf("\nReturn Date : %s",l.returned);
            cout<<"\n_______________________\n";
            result++;
        }
        ////////
    }
    printf("\n\n\t\t\t\xAF\xAF\xAF Enter 1/0 from your keyboard....\n\t\t\t(Remember 1 for Borrow menu and 0 for Exit. :))");
    printf("\n\t\t\t \xDB\xB1\xB1 Enter : ");
    scanf("%d", &ent);
    if(ent==1)
    {
        br_menu();
    }
    else if(ent==0)
    {
        exit(3);
    }
    else
    {
        cout<<"You have entered a wrong key"<<endl;
        system("pause 3");
        menu();
    }
    break;
    case '3':
    {
        system("cls");
        char ch;
        do
        {
            result=0;
            printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB Search Boorowed Books\xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
            fflush(stdin);
            printf("\n\xB2\xB2\xDB Enter Any Word >> ");
            scanf("%[^\n]",&query);
            la=strlen(query);
            fp=fopen("borrow.dat","r");
            system("cls");
            printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB  Search Borrowed Books \xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
            printf("\n\n\xB2\xB2\xDB Search Result For >> %s \n______________________________________\n",query);
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                for(i=0; i<=la; i++)
                    bname[i]=l.bname[i];
                bname[la]='\0';

                if(stricmp(bname,query)==0)
                {
                    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                    printf("\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 ID : %d",l.id);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Name : %s",l.bname);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Author : %s",l.author);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Department : %s",l.dept);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Borrowed By : %s", l.stname);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Date of Borrow : %s ",l.borrowed);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Dat Of Return : %s",l.returned);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                    result++;
                    if (result%4==0)
                    {
                        printf("\xB2\xB2\xB2 Press any key to continue...");
                        getch();
                    }
                }
            }
            if(result==0)
            {
                printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2\t\t  \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2 No Record Found");
                printf(" \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            }
            printf("\n\t\t Try another search?(Y/N) .....");
            if(getch()=='y')
                search();
            else
                br_menu();
            ///////////////
        }
        while(ch==1);
    }
    break;
    case '4':
    {
        system("cls");
        int d;
        char another='y';
        while(another=='y')  //infinite loop
        {
            system("cls");
            printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Removing a Borrowed Book \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\nEnter the Book ID to Remove : ");
            scanf("%d",&d);
            fp=fopen("borrow.dat","r");
            rewind(fp);
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                if(l.id==d)
                {
                    printf("\nThe book record is available");
                    printf("\nBook name is ");
                    printf(">>");
                    printf(" %s", l.bname);
                    printf("\nThe Book is Borrowed By >> %s", l.stname);
                    findbook='t';
                }
            }
            if(findbook!='t')
            {
                printf("\n\xB2 No record is found modify the search");
                if(getch())
                    br_menu();
            }
            if(findbook=='t' )
            {
                printf("\n\t\t\xB2 Do you want to Remove it?(Y/N) : ");
                if(getch()=='y')
                {
                    ft=fopen("temp.dat","w");  //temporary file for delete
                    rewind(fp);
                    while(fread(&l,sizeof(l),1,fp)==1)
                    {
                        if(l.id!=d)
                        {
                            fseek(ft,0,SEEK_CUR);
                            fwrite(&l,sizeof(l),1,ft); //write all in tempory file except that
                        }                              //we want to delete
                    }
                    fclose(ft);
                    fclose(fp);
                    remove("borrow.dat");
                    rename("temp.dat","borrow.dat"); //copy all item from temporary file to fp except that
                    fp=fopen("borrow.dat","r");    //we want to remove
                    if(findbook=='t')
                    {
                        printf("\n\xB2 The Borrow record is sucessfully Removed");
                        printf("\n\xB2 Remove another record?(Y/N)");
                    }
                }
                else
                    br_menu();
                fflush(stdin);
                another=getch();
            }
        }
        br_menu();
    }
    break;
    case '5':
    {
        menu();
    }
    default:
        printf("\n\t\t You have Entered a wrong key...");
        printf("\n\t\t You will go back to the previous stage now...\n\t\t ");
        system("pause 3");
        goto issue;
        break;
    }
}
////////////Check Book/////////////
int checkbk(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&l,sizeof(l),1,fp)==1)
        if(l.id==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
/*//////////Password protection by Maruf/////////////Not applicable for sir .. :p
void unlock()
{
	system("cls");
	//system("color 33");
	char pass[15];
	//style();
	lm();cout<<"\n";mrf();
	cout<<"\n\n\t _______________________________________";
	cout<<"\n\t >>**Password Protected Project**<<\n";
	//cout<<"\n\t _______________________________________\n";
	cout<<"\t Enter password to Unlock : ";
	if(strcmp(gets(pass),password)==0)
	{
	menu();
	}
	else
	{
	cout<<"\n >:( Wrong password.....\n";

	system("pause 3");
	unlock();
	}
}*/
///////////////Search function
void search()
{
    system("cls");
    int d;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Books \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\xDB\xDB\xDB\xB2 [1]. Search By ID\n");

    printf("\n\t\t\xDB\xDB\xDB\xB2 [2]. Search By Name\n");

    printf("\n\t\t\xDB\xDB\xDB\xB2 [3]. Search By 1st word");

    printf("\n\n\t\t>> Enter Your Choice : ");
    fp=fopen("maruf.txt","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
    case '1':
    {
        system("cls");
        printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB Search Books By Id \xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
        //int d;
        printf("\n\t\t Enter the book id : ");
        scanf("%d",&d);

        printf("\n\t\t Searching........");
        while(fread(&l,sizeof(l),1,fp)==1)
        {
            if(l.id==d)
            {
                printf("\n\t\t The Book is available");

                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                printf("\xB2");
                printf("\t\t\t\t\xB2");
                printf("\n\xB2 ID : %d",l.id);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2 Name : %s",l.bname);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2 Author : %s ",l.author);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2 Qantity:%d ",l.quantity);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2 Department : %s",l.dept);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2 Rack No : %d ",l.rack_no);
                printf("\n\xB2");
                cout<<"\t\t\t\t\xB2";
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                findbook='t';
            }
            ///////search id condition ends
        }
        ////////case 1 ends
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2\t\t  \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2 No Record Found");
            printf(" \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        }
        printf("\n\t\t Try another search?(Y/N)");
        if(getch()=='y')
            search();
        else
            menu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB Search Books By Name \xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
        printf("\n\t\tEnter Book Name:");
        scanf("%s",s);
        int d=0;
        while(fread(&l,sizeof(l),1,fp)==1)
        {
            if(strcmp(l.bname,(s))==0) //checks whether l.name is equal to s or not
            {
                printf("\n\t\tThe Book is available");
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                printf("\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 ID : %d",l.id);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 Name : %s",l.bname);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 Author : %s",l.author);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 Qantity : %d",l.quantity);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 Department : %s",l.dept);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2 Rack No : %d ",l.rack_no);
                printf("\n\xB2");
                cout<<"\t\t\t\xB2";
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                d++;
            }
        }
        cout<<"\n";
        //maruf();		///my function calls
        if(d==0)
        {
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2\t\t  \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2 No Record Found");
            printf(" \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2");
            printf("\t\t  \xB2");
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        }
        printf("\n\t\t Try another search?(Y/N)");
        if(getch()=='y')
            search();
        else
            menu();
        break;
    }
    case '3':
    {
        system("cls");
        char ch;
        do
        {
            result=0;
            printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB Search Books By 1st word \xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
            fflush(stdin);
            printf("\n\xB2\xB2\xDB Enter Any Word >> ");
            scanf("%[^\n]",&query);
            la=strlen(query);
            fp=fopen("maruf.txt","r");
            system("cls");
            printf("\n\t\t\xDB\xDB\xB2\xB2\xB2\xB2\xDB Search Books By Any word \xDB\xDB\xB2\xB2\xB2\xB2\xDB\n");
            printf("\n\n\xB2\xB2\xDB Search Result For >> %s \n______________________________________\n",query);
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                for(i=0; i<=la; i++)
                    bname[i]=l.bname[i];
                bname[la]='\0';

                if(stricmp(bname,query)==0)
                {
                    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                    printf("\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 ID : %d",l.id);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Name : %s",l.bname);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Author : %s",l.author);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Qantity : %d",l.quantity);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Department : %s",l.dept);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2 Rack No : %d ",l.rack_no);
                    printf("\n\xB2");
                    cout<<"\t\t\t\t\xB2";
                    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                    result++;
                    if (result%4==0)
                    {
                        printf("\xB2\xB2\xB2 Press any key to continue...");
                        getch();
                    }
                }
            }
            if(result==0)
            {
                printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2\t\t  \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2 No Record Found");
                printf(" \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2");
                printf("\t\t  \xB2");
                printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            }
            printf("\n\t\t Try another search?(Y/N)");
            if(getch()=='y')
                search();
            else
                menu();
            ///////////////
        }
        while(ch==1);
        break;
    }
    default :
        getch();
        search();
    }
    fclose(fp);
}
//////////Edit Books information
void editbooks()
{
    system("cls");
    //system("color 06");
    char another='y';
    int d;
    int c=0;
    char sd;
    while(another=='y')
    {
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Books \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\t\t \xB2\xB2\xB1 [1].Edit Full Information");
        printf("\n\n\t\t \xB2\xB2\xB1 [2].Edit Name Only");
        printf("\n\n\t\t \xB2\xB2\xB1 [3].Edit Author Only");
        printf("\n\n\t\t \xB2\xB2\xB1 [4].Back To Main Menu");
        printf("\n\n\t\t \xB2\xB2\xB1 ||Enter Your choice >> ");
        switch(getch())
        {
        case '1':
        {
            //////////////
            system("cls");
            printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2 Edit Full Information \xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\t\t\xB2\xB2\xB1 Enter Book ID to be Edited : ");
            scanf("%d", &d);
            //////////Start of Editable book's Details///////////
            fp=fopen("maruf.txt","r");
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                if(l.id==d)
                {
                    printf("\n_________________________\n");
                    printf("\nThe book is availble");
                    printf("\nThe Book ID : %d", l.id);
                    printf("\nYou are going to edit this book >> ");
                    printf("\nBook Name : %s", l.bname);
                    printf("\nBook Author : %s", l.author);
                    printf("\nDepartment : %s", l.dept);
                    printf("\nQuantity : %d", l.quantity);
                    printf("\nRack No : %d", l.rack_no);
                    printf("\n_________________________\n");
                }
            }
            fclose(fp);
            ////////////////////Start Editing/////////////
            fp=fopen("maruf.txt","rb+");
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                if(checkbk(d)==0)
                {
                    fflush(stdin);
                    printf("\nEnter new name : ");
                    gets(l.bname);
                    fflush(stdin);

                    printf("\nEnter new Author : ");
                    gets(l.author);
                    fflush(stdin);

                    printf("\nEnter new ID{enter the default ID/New One} : ");
                    scanf("%d", &l.id);
                    fflush(stdin);

                    printf("\nEnter new Department : ");
                    scanf("%s", &l.dept);
                    fflush(stdin);

                    printf("\nEnter new Quantity : ");
                    scanf("%d", &l.quantity);
                    fflush(stdin);

                    printf("\nEnter new Rack No : ");
                    scanf("%d", &l.rack_no);
                    fflush(stdin);

                    printf("\nThe record is modified");
                    fseek(fp,ftell(fp)-sizeof(l),0);
                    fwrite(&l,sizeof(l),1,fp);
                    fclose(fp);
                    c=1;
                }
                if(l.id!=d)
                {
                    system("cls");
                    printf("\nNo record found");
                }
            }
            //////////
            break;
        }
        case '2':
        {
            //////////////
            system("cls");
            printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2 Edit Name Only \xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\t\t\xB2\xB2\xB1 Enter Book ID to be Edited : ");
            scanf("%d", &d);
            //////////Start of Editable book's Name///////////
            fp=fopen("maruf.txt","r");
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                if(l.id==d)
                {
                    printf("\n_________________________\n");
                    printf("\nThe book is availble");
                    printf("\nThe Book ID : %d", l.id);
                    printf("\nYou are going to edit this book >> ");
                    printf("\nBook Name : %s", l.bname);
                    printf("\n_________________________\n");
                }
            }
            fclose(fp);
            ////////////////////Start Name Editing/////////////
            fp=fopen("maruf.txt","rb+");
            while(fread(&l.bname,sizeof(l),1,fp)==1)
            {
                if(checkbk(d)==0)
                {
                    fflush(stdin);
                    printf("\nEnter new name : ");
                    gets(l.bname);
                    fflush(stdin);
                    ////
                    printf("\nThe record is modified");
                    fseek(fp,ftell(fp)-sizeof(l),0);
                    fwrite(&l.bname,sizeof(l),1,fp);
                    fclose(fp);
                    c=1;
                }
                if(l.id!=d)
                {
                    system("cls");
                    printf("\nNo record found");
                }
            }
            //////////
            break;
        }
        case '3':
        {
            //////////////
            system("cls");
            printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2 Edit Author Name Only \xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\t\t\xB2\xB2\xB1 Enter Book ID to be Edited : ");
            scanf("%d", &d);
            //////////Start of Editable book's Name///////////
            fp=fopen("maruf.txt","r");
            while(fread(&l,sizeof(l),1,fp)==1)
            {
                if(l.id==d)
                {
                    printf("\n_________________________\n");
                    printf("\nThe book is availble");
                    printf("\nThe Book ID : %d", l.id);
                    printf("\nYou are going to edit this book >> ");
                    printf("\nBook Name : %s", l.bname);
                    printf("\nWhich Author is : %s", l.author);
                    printf("\n_________________________\n");
                }
            }
            fclose(fp);
            ////////////////////Start Name Editing/////////////
            fp=fopen("maruf.txt","rb+");
            while(fread(&l.author,sizeof(l),1,fp)==1)
            {
                if(checkbk(d)==0)
                {
                    fflush(stdin);
                    printf("\nEnter new Author name : ");
                    gets(l.author);
                    fflush(stdin);
                    ////
                    printf("\nThe record is modified");
                    fseek(fp,ftell(fp)-sizeof(l),0);
                    fwrite(&l.author,sizeof(l),1,fp);
                    fclose(fp);
                    c=1;
                }
                if(l.id!=d)
                {
                    system("cls");
                    printf("\nNo record found");
                }
            }
            //////////
            break;
        }
        case '4':
        {
            menu();
            break;
        }
        default:
        {
            menu();
            break;
        }
            //////////////
        printf("\nModify another Record?(Y/N)");
        fflush(stdin);
        another=getch();
        }
        returnfunc();
    }
}

//}
void returnfunc()
{
    {
        printf("\n >>Press ENTER to return to main menu<<");
    }
a:
    if(getch()==13) //allow only use of enter using ASCI Code
        menu();
    else
        goto a;
}
/////////////////////Remove Books
void removebooks()
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Deleting a Book \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\nEnter the Book ID to  delete : ");
        scanf("%d",&d);
        fp=fopen("maruf.txt","rb+");
        rewind(fp);
        while(fread(&l,sizeof(l),1,fp)==1)
        {
            if(l.id==d)
            {
                printf("\nThe book record is available");
                printf("\nBook name is ");
                printf(">>");
                printf(" %s", l.bname);
                printf("\nRack No. is %d", l.rack_no);
                findbook='t';
            }
        }
        if(findbook!='t')
        {
            printf("\nNo record is found modify the search");
            if(getch())
                menu();
        }
        if(findbook=='t' )
        {
            printf("\nDo you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("temp.txt","w");  //temporary file for delete
                rewind(fp);
                while(fread(&l,sizeof(l),1,fp)==1)
                {
                    if(l.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&l,sizeof(l),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("maruf.txt");
                rename("temp.txt","maruf.txt"); //copy all item from temporary file to fp except that
                fp=fopen("maruf.txt","r");    //we want to delete
                if(findbook=='t')
                {
                    printf("\nThe record is sucessfully deleted");
                    printf("\n\n >>Delete another record?(Y/N)");
                }
            }
            else
                menu();
            fflush(stdin);
            another=getch();
        }
    }
    menu();
}
///////Exit function by maruf
void exitt()
{
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2 Program is now Exiting \xB2\xB2\xB2\xB2\xB2\n");
    maruf();
    system("pause 5");
    exit(EXIT_FAILURE);
}
//////////My Sign Function
void maruf()
{
    cout<<"\n"<<endl;
    cout<<"\t\xB2";
    cout<<"\xB2   ";
    cout<<"   \xB2";
    cout<<"\xB2";
    cout<<"\n\t\xB2";
    cout<<" \xB2  ";
    cout<<"  \xB2 ";
    cout<<"\xB2";
    cout<<"\n\t\xB2";
    cout<<"  \xB2 ";
    cout<<" \xB2 ";
    cout<<" \xB2";
    cout<<"\n\t\xB2";
    cout<<"   \xB2";
    cout<<"\xB2  ";
    cout<<" \xB2";
    cout<<"\n\t\xB2";
    cout<<"\t \xB2";
    cout<<"\n\t\xB2";
    cout<<"\t \xB2";
    cout<<" ARUF";
    cout<<"\n\n Programmed By (Mahmudul Maruf & his group).... \n";
    printf(">> Student of BRITANNIA UNIVERSITY \n");
    cout<<">> Library Management Project as a project of class..\n";
}
/////////////Design Logo By Maruf//////
void style()
{
    cout<<"\nWelcome to "<<endl;
    lm();
    cout<<"\n";
    mrf();
}
void mrf()
{
    {
        cout<<"\t\t\xB2";
        cout<<"\xB2   ";
        cout<<"   \xB2";
        cout<<"\xB2";
        cout<<"\n\t\t\xB2";
        cout<<" \xB2  ";
        cout<<"  \xB2 ";
        cout<<"\xB2";
        cout<<"\n\t\t\xB2";
        cout<<"  \xB2 ";
        cout<<" \xB2 ";
        cout<<" \xB2";
        cout<<"\n\t\t\xB2";
        cout<<"   \xB2";
        cout<<"\xB2  ";
        cout<<" \xB2";
        cout<<"\n\t\t\xB2";
        cout<<"\t \xB2";
        cout<<"\n\t\t\xB2";
        cout<<"\t \xB2";
        cout<<" ANAGER";
    }
}
void lm()
{
    {
        cout<<"\n";
        cout<<"\t\xB1";
        cout<<"\n\t\xB1";
        cout<<"\n\t\xB1";
        cout<<"\n\t\xB1";
        cout<<"\n\t\xB1";
        cout<<"\n\t\xB1";
        cout<<"\xB1";
        cout<<"\xB1";
        cout<<"\xB1";
        cout<<"\xB1";
        cout<<" IBRARY ";
    }
}
///////////////////////////////Total Program Coded,Edited and Developed By Mahmudul Maruf///////////////////////////

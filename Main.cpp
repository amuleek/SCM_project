


//	PROJECT BOOK LIBRARY

#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU


class MENU
{
	public :
			void main_menu(void) ;
			void introduction(void) ;
	private :
			void edit_menu(void) ;
			void edit_book(void) ;
			void edit_member(void) ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO BOOKS
//**********************************************************

class BOOK
{
	public :
			void list(void) ;
			char *bookname(int) ;
	protected :
			void add_new_book(int, char tname[33], char tauthor[26], float, int, int) ;
			void update_copies(int, int, int) ;
			void modify(int, char[], char[], float) ;
			void deletion(void) ;
			int  book_found(int) ;
			int  bookname_found(char []) ;
			int  recordno(int) ;
			int  available(int) ;
			char *authorname(int) ;
			float bookprice(int) ;
			int  no_of_copies(int) ;
			int  bookcodeof(char[]) ;
			void display(int) ;
			int  reccount(void) ;
			void delete_rec(int) ;
	private :
			int   bookcode, copies ;
			char  name[33], author[26] ;
			float price ;
			int   avail ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO MEMBERS
//**********************************************************

class MEMBER
{
	public :
			void list(void) ;
	protected :
			void add_mem(int, int, char [], char [], char[], int, int, int) ;
			void modify(int, char[], char[], char[]) ;
			int  member_found(int) ;
			void update_book(int, int, int, int, int) ;
			char *membername(int) ;
			char *memberphone(int) ;
			char *memberaddress(int) ;
			int  recordno(int) ;
			int  lastcode(void) ;
			int  issued(int) ;
			int  fine(int) ;
			void display(int) ;
			void delete_rec(int) ;
	private :
			int  memcode, bookcode ;
			char name[26], phone[10], address[33] ;
			int  dd, mm, yy ;   // DATE OF RETURNING THE BOOK //
} ;


//**********************************************************
// THIS IS DERIVED FROM CLASS BOOK & MEMBER AND CONTAINS
// FUNCTIONS FOR WORKING (ISSUE,RETURN,ETC).
//**********************************************************

class WORKING : public BOOK, public MEMBER
{
	public :
			void issuebook(void) ;
			void returnbook(void) ;
			void add_book(void) ;
			void add_member(void) ;
			void modify_book(void) ;
			void modify_member(void) ;
			void delete_book(void) ;
			void delete_member(void) ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED DATE & FINE
//**********************************************************

class DATE
{
	public :
			void extend_date(int,int,int,int) ;
			int  diff(int, int, int, int, int, int) ;
			int  day, mon, year ;
} ;



//**********************************************************
// FUNCTION TO EXTEND GIVEN DATE BY 15 DAYS
//**********************************************************

void DATE :: extend_date(int d1, int m1, int y1, int days)
{
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	for (int i=1; i<=days; i++)
	{
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	day  = d1 ;
	mon  = m1 ;
	year = y1 ;
}


//**********************************************************
// THIS FUNCTION RETURN THE DIFFERENCE BETWEEN TWO GIVEN
// DATES
//**********************************************************

int DATE :: diff(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0 ;
	if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days ;
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++ ;
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	return days ;
}


//**********************************************************
// FUNCTION TO DISPLAY MAIN MENU & CONTROL ALL THE FUNCTION
// IN THE MAIN MENU.
//**********************************************************

void MENU :: main_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(29,6) ;
		cout <<"B O O K  L I B R A R Y" ;
		gotoxy(29,7) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;
		cout <<"1. INTRODUCTION" ;
		gotoxy(30,11) ;
		cout <<"2. ADD NEW BOOK" ;
		gotoxy(30,12) ;
		cout <<"3. ADD NEW MEMBER" ;
		gotoxy(30,13) ;
		cout <<"4. ISSUE BOOK" ;
		gotoxy(30,14) ;
		cout <<"5. RETURN BOOK" ;
		gotoxy(30,15) ;
		cout <<"6. LIST OF BOOKS" ;
		gotoxy(30,16) ;
		cout <<"7. LIST OF MEMBERS" ;
		gotoxy(30,17) ;
		cout <<"8. EDIT" ;
		gotoxy(30,18) ;
		cout <<"0. QUIT" ;
		gotoxy(30,20) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
			introduction() ;
		else
		if (ch == '2')
		{
			WORKING W ;
			W.add_book() ;
		}
		else
		if (ch == '3')
		{
			WORKING W ;
			W.add_member() ;
		}
		else
		if (ch == '4')
		{
			WORKING W ;
			W.issuebook() ;
		}
		else
		if (ch == '5')
		{
			WORKING W ;
			W.returnbook() ;
		}
		else
		if (ch == '6')
		{
			BOOK B ;
			B.list() ;
		}
		else
		if (ch == '7')
		{
			MEMBER M ;
			M.list() ;
		}
		else
		if (ch == '8')
			edit_menu() ;
		else
		if (ch == '0')
			break ;
	}
}


//**********************************************************
// FUNCTION TO DISPLAY EDIT MENU
//**********************************************************

void MENU :: edit_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;
		cout <<"E D I T  M E N U";
		gotoxy(32,10) ;
		cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;
		cout <<"1. BOOKS" ;
		gotoxy(34,14) ;
		cout <<"2. MEMBERS" ;
		gotoxy(34,15) ;
		cout <<"0. EXIT" ;
		gotoxy(31,17) ;
		cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
			edit_book() ;
		else
		if (ch == '2')
			edit_member() ;
		else
		if (ch == '0')
			break ;
	}
}

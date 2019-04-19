#include <iostream.h>
#include <fstream.h>


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

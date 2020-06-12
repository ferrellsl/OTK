/****************************************************************/
/* Application1.c - An example application for Otk library.	*/
/*  Shows how to make: toggle and radio buttons, pull-down 	*/
/*  menu, and selection lists.					*/
/*								*/
/* Compile:
    cc -L/usr/X11R6/lib application1.c -lGLU -lGL -lXmu -lXext -lX11 -lm -o app1.exe
								*/
/* Dec 15, 2004.						*/ 
/****************************************************************/

#include "otk_lib.c"

OtkWidget tbutton1, tbutton2;

void toggled( int state, void *x )
{
 if (state==1) printf("Toggle button %d toggled ON.\n", (int)x);
 else printf("Toggle button %d toggled OFF.\n", (int)x);

 printf(" (Toggle button states: %d %d\n",Otk_Get_Button_State(tbutton1),Otk_Get_Button_State(tbutton2));
}


char directory[500]=".", wildcards[500]="", filename[500]="";

void my_file_answer( char *filename )
{ printf("To open file %s\n", filename); }

void fileopener()
{ Otk_Browse_Files( "File to Open:", 500, directory, wildcards, filename, my_file_answer ); }

void saveas_answer( char *filename )
{ printf("To saveas file %s\n", filename); }

void filesaver()
{ Otk_Browse_Files( "File to Save:", 500, directory, wildcards, filename, saveas_answer ); }


void radiocallback( void *x )
{
 printf("Radio button %d selected.\n", (int)x );
}


void selectlistcallback( void *x )
{
 printf("Item %d selected.\n", (int)x );
}


void testbutton()
{ printf("Test button pressed.\n"); }

void quit( void *x )
{ printf("Exiting\n"); exit(0); }


/* ===================== MAIN ======================== */
main( int argc, char **argv )
{
 OtkWidget menubar, pdmenu1, pdmenu2, pdmenu3, pdmenu4, pdmenu5, sbmenu;
 OtkWidget rbutton1, slist;
 float x=3.0, y=5.0, dx, dy, hsz, vsz;
 int nrows, ncols;

 OtkInitWindow( 400, 450, argc, argv );

 /******************************/
 /* Make some Pull-down Menus. */
 /******************************/
 menubar = OtkMakePanel( OtkOuterWindow, Otk_Flat, OtkSetColor(0.7,0.7,0.7), 0, 0, 100, 5 );

 pdmenu1 = Otk_Make_Menu( menubar, 0, 0, 15, 100, " File " );
 Otk_Add_Menu_Item( pdmenu1, "Open", fileopener, 0 );
 Otk_Add_Menu_Item( pdmenu1, "Save", 0, 0 );
 Otk_Add_Menu_Item( pdmenu1, "Save As", filesaver, 0 );
 Otk_Add_Menu_Item( pdmenu1, "Print", 0, 0 );
 Otk_Add_Menu_Item( pdmenu1, "Exit", quit, 0 );

 pdmenu2 = Otk_Make_Menu( menubar, 15, 0, 15, 100, " Edit " );
 Otk_Add_Menu_Item( pdmenu2, "Cut", 0, 0 );
 Otk_Add_Menu_Item( pdmenu2, "Copy", 0, 0 );
 Otk_Add_Menu_Item( pdmenu2, "Paste", 0, 0 );

 pdmenu3 = Otk_Make_Menu( menubar, 30, 0, 15, 100, " View " );
 Otk_Add_Menu_Item( pdmenu3, "Normal", 0, 0 );
 sbmenu = Otk_Add_SubMenu( pdmenu3, "Zoom" );	/* Add a Sub-Menu. */
 Otk_Add_Menu_Item( sbmenu, "Zoom-In", 0, 0 );
 Otk_Add_Menu_Item( sbmenu, "Zoom-Out", 0, 0 );

 pdmenu4 = Otk_Make_Menu( menubar, 45, 0, 15, 100, " Tools " );
 Otk_Add_Menu_Item( pdmenu4, "Search", 0, 0 );

 pdmenu5 = Otk_Make_Menu( menubar, 60, 0, 15, 100, " Help " );
 Otk_Add_Menu_Item( pdmenu5, "About", 0, 0 );



 /******************************/
 /* Make some toggle buttons.  */
 /******************************/
 x = 3.0;    y = 12.0;		/* x = horizontal position, y = vertical. */
 hsz = 8.0;  vsz=2.0;
 OtkMakeTextLabel( OtkOuterWindow, "Toggle Buttons:", Otk_Black, 2.0, 1.0, x, y );
 tbutton1 = OtkMakeToggleButton( OtkOuterWindow, x+50, y, hsz, vsz, toggled, (void *)1 );
 OtkMakeTextLabel( OtkOuterWindow, "T1", Otk_Black, 2.0, 1.0, x+59, y+0.4 );
 tbutton2 = OtkMakeToggleButton( OtkOuterWindow, x+70, y, hsz, vsz, toggled, (void *)2 );
 OtkMakeTextLabel( OtkOuterWindow, "T2", Otk_Black, 2.0, 1.0, x+79, y+0.4 );


 /******************************/
 /* Make some Radio Buttons.   */
 /******************************/
 x = 3.0;    y = 30.0;
 hsz = 8.0;  vsz=2.0;	dx = 20.0;
 OtkMakeTextLabel( OtkOuterWindow, "Radio Buttons:", Otk_Black, 2.0, 1.0, x, y );
 x = 10.0;  y = y + 5.0;
 rbutton1 = OtkMakeRadioButton( OtkOuterWindow, x, y, hsz, vsz, radiocallback, (void *)1 );
 OtkMakeTextLabel( OtkOuterWindow, "R1", Otk_Black, 2.0, 1.0, x+9.0, y );
 x = x + dx;
 OtkMakeRadioButton( rbutton1, x, y, hsz, vsz, radiocallback, (void *)2 );
 OtkMakeTextLabel( OtkOuterWindow, "R2", Otk_Black, 2.0, 1.0, x+9.0, y );
 x = x + dx;
 OtkMakeRadioButton( rbutton1, x, y, hsz, vsz, radiocallback, (void *)3 );
 OtkMakeTextLabel( OtkOuterWindow, "R3", Otk_Black, 2.0, 1.0, x+9.0, y );
 x = x + dx;
 OtkMakeRadioButton( rbutton1, x, y, hsz, vsz, radiocallback, (void *)4 );
 OtkMakeTextLabel( OtkOuterWindow, "R4", Otk_Black, 2.0, 1.0, x+9.0, y );

 
 /******************************/
 /* Make a selection-list.     */
 /******************************/
 x = 3.0;     y = 50.0;
 OtkMakeTextLabel( OtkOuterWindow, "Selection List:", Otk_Black, 2.0, 1.0, x, y );
 hsz = 70.0;  vsz=20.0;
 x = 10.0;  y = y + 5.0;
 nrows = 5;  ncols = 25;
 slist = Otk_Make_Selection_List( OtkOuterWindow, nrows, ncols, x, y, hsz, vsz );
 Otk_Add_Selection_Item( slist, "Grapes", selectlistcallback, (void *)1 );
 Otk_Add_Selection_Item( slist, "Olives", selectlistcallback, (void *)2 );
 Otk_Add_Selection_Item( slist, "Bananas", selectlistcallback, (void *)3 );
 Otk_Add_Selection_Item( slist, "Cherries", selectlistcallback, (void *)4 );
 Otk_Add_Selection_Item( slist, "Apples", selectlistcallback, (void *)5 );
 Otk_Add_Selection_Item( slist, "Cigars", selectlistcallback, (void *)6 );
 Otk_Add_Selection_Item( slist, "Lemons", selectlistcallback, (void *)7 );
 Otk_Add_Selection_Item( slist, "Tangerines", selectlistcallback, (void *)8 );
 Otk_Frame_Selection_List( slist );


 OtkMakeButton( OtkOuterWindow, 45.0, 89.0, 10.0, 4.0, "Test", testbutton, 0 );
 OtkMakeButton( OtkOuterWindow, 45.0, 95.0, 10.0, 4.0, "Exit", quit, 0 );
 OtkMainLoop();
}

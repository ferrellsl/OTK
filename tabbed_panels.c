/****************************************************************/
/* Tabbed_panel.c - Make a tabbed panel.			*/
/*                                                              */
/* On Linux, compile with:
     cc -I/usr/X11R6/include -L/usr/X11R6/lib tabbed_panels_ex1.c \
        -lGLU -lGL -lXmu -lXext -lX11 -lm -o tabbed_panels_ex1.exe
                                                                */
/****************************************************************/

#include "otk_lib.c"

void quit()
{ exit(0); }

void update(void *x)
{ printf("Update from panel %d\n", (int)x); }


main( int argc, char **argv )
{
 OtkWidget panel1, panel2;
 char *pnames[2];
 OtkTabbedPanel *tabs;

 OtkInitWindow( 900, 600, argc, argv );

 /* Make two tabbed panels. */
 pnames[0] = strdup("Panel One");
 pnames[1] = strdup("Panel Two");
 tabs = Otk_Tabbed_Panel_New( 
		OtkOuterWindow, 
		2, 
		pnames, 
		Otk_Gray, 
		15, 20, 
		70, 70, 
		8 );

 /* Place something on panel 1. */
 panel1 = tabs->panels[0];
 OtkMakeTextLabel( panel1, "Panel Uno", Otk_Blue, 2.0, 1.0, 25, 10);
 OtkMakeButton( panel1, 20, 20, 20, 10, "Update 1", update, (void *)1 );

 /* Place something on panel 2. */
 panel2 = tabs->panels[1];
 OtkMakeTextLabel( panel2, "Panel Two", Otk_Red, 2.0, 1.0, 10, 10);
 OtkMakeButton( panel2, 40, 50, 20, 10, "Update 2", update, (void *)2 );

 OtkMakeButton( OtkOuterWindow, 50, 95, 10, 4, " Exit ", quit, 0 );
 OtkMainLoop();
}

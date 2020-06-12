/**************************************************************************************************
 fbrowse.c - File-Browser widget test.  This demonstrates the use of Otk's built-in 
	    file-selector widget.  It is a simple stand-alone program.

 Comple with:
  cc -I/usr/X11R6/include -L/usr/X11R6/lib fbrowse.c -lGLU -lGL -lXmu -lXext -lX11 -lm -o fbrowse.exe

**************************************************************************************************/

#include "otk_lib.c"

char directory[500]=".", wildcards[500]="", filename[500]="";


void my_file_answer( char *filename )	/* Print name of selected file. */
{
 printf("Browsing returned file-name: '%s'\n", filename );
}


void browsetest()	/* Invoke the File Selection Browser. */
{
 Otk_Browse_Files( "File to Open:", 500, directory, wildcards, filename, my_file_answer );
}


main( int argc, char **argv )
{
  OtkInitWindow( 620, 540, argc, argv );	/* Open a window. */

  OtkMakeButton( OtkOuterWindow, 20.0, 40.0, 60.0, 20.0, "Select File(s)", browsetest, 0 );

  OtkMainLoop();
}

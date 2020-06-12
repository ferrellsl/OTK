/* Created by OTK GUI-Builder v0.22 */
/* Compile on Linux with:
     cc -O -I/usr/X11R6/include -L/usr/X11R6/lib imageview.c \
        -lGLU -lGL -lXmu -lXext -lX11 -lm -o imageview

   Usage:   ./imageview  picture.jpg
*/

#include "otk_lib.c"

#define MAXSTR 5000

OtkWidget picture_object=0, border;
char dirname[MAXSTR]=".", wildcards[MAXSTR]=".ppm .jpg .gif .png", fname[MAXSTR]="";


void file_answer( char *filename )
{  
  printf("Browsing returned file-name: '%s'\n", filename );
  if (picture_object != 0)
   Otk_RemoveObject( picture_object );
  picture_object = OtkMakeImagePanel( border, filename, 4.5, 5, 91.0, 90 );
}


void open_new_image( void *data )       /* Pop-up file browser to select a new image file for display. */
{
  Otk_Browse_Files( "Image to View:", MAXSTR, dirname, wildcards, fname, file_answer );
}


void quit( void *x )
{
 exit(0);
}



main( int argc, char **argv )
{

  OtkInitWindow( 610, 600, argc, argv );        /* Make the outer window. */

  /* Make a border for the picture. */
  border = OtkMakePanel( OtkOuterWindow, Otk_Raised, OtkSetColor( 0.13, 0.22, 0.33), 6, 3, 88, 82 );

  /* Display first image, or note saying no picture. */
  Otk_SetBorderThickness( border, 0.4 );
  if (argc < 2) 
   picture_object = OtkMakeTextLabel( border, "No image.", Otk_Red, 5, 1.0, 30, 40 );
  else
   picture_object = OtkMakeImagePanel( border, argv[1], 4.5, 5, 91.0, 90 );

  /* Place open and close buttons. */
  OtkMakeButton( OtkOuterWindow, 6, 90, 24, 6, "Open ", open_new_image, 0 );
  OtkMakeButton( OtkOuterWindow, 70, 90, 24, 6, "Close ", quit, 0 );

  OtkMainLoop();
}

/****************************************************************/
/* HelloWorld.c - Simplest example program for Otk.		*/
/*								*/
/* On Linux, compile with:					
     cc -I/usr/X11R6/include -L/usr/X11R6/lib helloworld.c \
	-lGLU -lGL -lXmu -lXext -lX11 -lm -o helloworld
								*/
/****************************************************************/

#include "otk_lib.c"

main( int argc, char **argv )
{
  OtkInitWindow( 350, 140, argc, argv );
  OtkMakeButton( OtkOuterWindow, 10.0, 10.0, 80.0, 80.0, "Hello World !", 0, 0 );
  OtkMainLoop();
}


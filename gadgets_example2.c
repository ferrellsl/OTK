/*********************************************************************************/
/* Gadget_Example2.c - Example of combining an Otk GUI with another application, */
/* where Otk is not the main loop.  Three of the meters move on their own, as	 */
/* under the control of an other application.  And two meters are controlled	 */
/* by a slider.									 */
/* 
 cc -I/usr/X11R6/include -L/usr/X11R6/lib gadgets_example2.c -lGLU -lGL -lXmu -lXext -lX11 -lm -o gadgets_example2.exe
										 */
/*										 */
/*********************************************************************************/

//#include "otk_lib/otk_lib.h"
#include "otk_lib.c"
#include "gadget_lib.h"
#include "gadget_lib.c"

OtkWidget dialmeter, ledmeter1, ledmeter2, bargraph1, bargraph2;

void quit_callback()
{
 printf("Exiting\n");
 exit(0);
}

void slider1moved( float x, void *id )
{
 Otk_SetGauge2( dialmeter, 100.0 * x, OtkSetColor( 0.8, 0.0, 0.2) );
}

void slider2moved( float x, void *id )
{
 Otk_SetLEDmeter( ledmeter1, 100.0 * x, OtkSetColor( 0.2, 0.2, 0.2), Otk_Green );
 Otk_SetLEDmeter( ledmeter2, 100.0 * x, OtkSetColor( 0.2, 0.2, 0.2), OtkSetColor( 0.75,0.0,0.0)  );
}

void slider3moved( float x, void *id )
{
 Otk_SetBarMeter( bargraph1, 100.0 * x );
 Otk_SetBarMeter( bargraph2, 100.0 * x );
}


main( int argc, char **argv )
{
 OtkWidget meter, slider, label;
 float x, dx=1.0, width, y, y1, height;

 OtkInitWindow( 500, 650, argc, argv );
 label = OtkMakeTextLabel( OtkOuterWindow, "Gadgets Example 2", Otk_Black, 2.0, 2.0, 2, 2 );

 y = 7.0;
 Otk_Add_Line( OtkOuterWindow, Otk_Black, 1.0, 1, y, 99, y );    /* Separator. */
 y = y + 2.0;
 label = OtkMakeTextLabel( OtkOuterWindow, "Dial Meter:", Otk_Black, 1.5, 1.0, 2, y );

 /* Add a Dial-Gauge. */
 x = 50.0;  y1 = y + 2.0;  width = 30.0;  height = 25.0;
 dialmeter = Otk_MakeGauge2( OtkOuterWindow, x, y1, width, height, "  Pressure and Temperature" );


 /* --- Add Separater. --- */
 y = y + 30.0;
 Otk_Add_Line( OtkOuterWindow, Otk_Black, 1.0, 1, y, 99, y );    /* Separator. */
 y = y + 2.0;
 label = OtkMakeTextLabel( OtkOuterWindow, "LED Meters:", Otk_Black, 1.5, 1.0, 2, y );

 /* Add a horizontal LED meter. */
 x = 20.0;  y1 = y + 10.0;  height = 5.0;
 ledmeter1 = Otk_MakeLEDmeter( OtkOuterWindow, x, y1, width, height, 25, 'h', Otk_DarkGray );
 Otk_SetLEDmeter( ledmeter1, 50.0, Otk_DarkGray, Otk_Green );
 OtkMakeTextLabel( OtkOuterWindow, "0", Otk_Black, 1.0, 1.0, x, y1 + 6.0 );
 OtkMakeTextLabel( OtkOuterWindow, "100", Otk_Black, 1.0, 1.0, x+width-2.0, y1 + 6.0 );

 /* Add a vertical LED meter. */
 x = 75.0;  y1 = y + 2.0;  width = 5.0;  height = 25.0;
 ledmeter2 = Otk_MakeLEDmeter( OtkOuterWindow, x, y1, width, height, 15, 'v', Otk_DarkGray );
 Otk_SetLEDmeter( ledmeter2, 50.0, Otk_DarkGray, OtkSetColor(0.75,0.0,0.0) );
 OtkMakeTextLabel( OtkOuterWindow, "100", Otk_Black, 1.0, 1.0, x+width+1.2, y1 );
 OtkMakeTextLabel( OtkOuterWindow, "0", Otk_Black, 1.0, 1.0, x+width+1.2, y1 + height - 1.0 );


 /* --- Add Separater. --- */
 y = y + 30.0;
 Otk_Add_Line( OtkOuterWindow, Otk_Black, 1.0, 1, y, 99, y );    /* Separator. */
 y = y + 2.0;
 label = OtkMakeTextLabel( OtkOuterWindow, "Bar Meters:", Otk_Black, 1.5, 1.0, 2, y );

 /* Make a slider. */
 x = 20.0;  y1 = y + 13.0;  width = 40.0;
 slider =
 OtkMakeSliderHorizontal( OtkOuterWindow, x, y1, width, slider3moved, 0 );
 OtkMakeTextLabel( OtkOuterWindow, "0", Otk_Black, 1.0, 1.0, x, y1 + 4.5 );
 OtkMakeTextLabel( OtkOuterWindow, "100", Otk_Black, 1.0, 1.0, x+width-2.0, y1 + 4.5 );

 /* Add a horizontal Bar-meter. */
 y1 = y + 4.5;  height = 4.0;
 bargraph1 = Otk_MakeBarMeter( OtkOuterWindow, x, y1, width, height, 'h', OtkSetColor( 0.9, 0.9, 0.0) );
 Otk_SetBarMeter( bargraph1, 50.0 );

 /* Add a vertical Bar-meter. */
 x = 75.0;  y1 = y + 1.5;  width = 5.0;  height = 17.0;
 bargraph2 = Otk_MakeBarMeter( OtkOuterWindow, x, y1, width, height, 'v', OtkSetColor( 0.0, 0.0, 1.0) );
 Otk_SetBarMeter( bargraph2, 50.0  );
 OtkMakeTextLabel( OtkOuterWindow, "100", Otk_Black, 1.0, 1.0, x+width+1.2, y1 );
 OtkMakeTextLabel( OtkOuterWindow, "0", Otk_Black, 1.0, 1.0, x+width+1.2, y1 + height - 1.0 );


 y = 94.0;
 Otk_Add_Line( OtkOuterWindow, Otk_Black, 1.0, 1, y, 99, y );    /* Separator. */
 OtkMakeButton( OtkOuterWindow, 45.0, 95.0, 10.0, 4.0, "Exit", quit_callback, 0 );

 x = 0.0;
 while (1)
  {
   OtkUpdateCheck();

   Otk_SetGauge2( dialmeter, x, OtkSetColor( 0.8, 0.0, 0.2) );		/* Move the analog meter. */

   Otk_SetLEDmeter( ledmeter1, x, Otk_DarkGray, Otk_Green );			/* Move the LED meter. */
   Otk_SetLEDmeter( ledmeter2, x, Otk_DarkGray, OtkSetColor(0.75,0.0,0.0) );	/* Move the LED meter. */

   x = x + dx;
   if ((x>100.0) || (x<0.0)) dx = -dx;
  }
}

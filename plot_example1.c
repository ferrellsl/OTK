/****************************************************************/
/* Plot_exmple1.c - Displays one simple graph and two 		*/
/*  strip-charts.  Updates the two strip-charts.		*/
/*                                                              */
/* On Linux, compile with:
     cc -I/usr/X11R6/include -L/usr/X11R6/lib plot_example1.c \
        -lGLU -lGL -lXmu -lXext -lX11 -lm -o plot_example1.exe
                                                                */
/****************************************************************/

#include "otk_lib.h"
#include "otk_lib.c"
#include "gadget_lib.h"
#include "gadget_lib.c"
#include <math.h>

OtkWidget plot1, plot2;
float phase=0.0;

void update_stripcharts()
{
 float value;
 value = 50.0 + 40.0 * sin( phase );
 Otk_StripChart_AddPoint( plot1, value );
 Otk_StripChart_AddPoint( plot2, value );
 phase = phase + 0.3;
}

void quit()
{ exit(0); }


main( int argc, char **argv )
{
 float xarray[10]={1,5,10,12,14}, yarray[10]={1,8,4,40,4.5};

 OtkInitWindow( 900, 600, argc, argv );

 /* Make a simple graph. */
 plot1 = Otk_Plot_Init( OtkOuterWindow, "Time (Hours)", "Temperature", 33, 5, 41, 30, Otk_Green, Otk_DarkGray );
 Otk_Plot_Set_Axes( plot1,  -5.0, 20.0, 10,   0.0, 10.0, 5,  Otk_Red, Otk_Gray );
 Otk_Plot_Data( plot1, 5, xarray, yarray, Otk_Cyan );	/* Plot first curve in cyan. */
 xarray[0] = 1.0;   yarray[0] = 9.0;
 xarray[1] = 6.5;   yarray[1] = 2.0;
 xarray[2] = 15.0;  yarray[2] = 6.7;
 Otk_Plot_Data( plot1, 3, xarray, yarray, Otk_Violet );	/* Plot second curve in violet. */
 
 /* Make first Strip-Chart. */
 plot1 = Otk_Plot_Init( OtkOuterWindow, "Time", "Value", 2, 41, 45, 50, Otk_Yellow, Otk_Black );
 Otk_StripChart_Init( plot1, 20, 0.0, 100.0, Otk_White, Otk_DarkGray, Otk_Red );

 /* Make Second Strip-Chart. */
 plot2 = Otk_Plot_Init( OtkOuterWindow, "Iterations", "Y-axis", 52, 41, 45, 50, Otk_Blue, Otk_Gray );
 Otk_StripChart_Init( plot2, -1, 0.0, 100.0, Otk_Black, Otk_DarkGray, Otk_Red );

 OtkMakeTextLabel( OtkOuterWindow, "A Simple Graph", Otk_Black, 1.9, 1.0, 35.0, 2.0 );
 OtkMakeTextLabel( OtkOuterWindow, "Strip-Chart 1", Otk_Black, 1.5, 1.0, 12.0, 38.0 );
 OtkMakeTextLabel( OtkOuterWindow, "Strip-Chart 2", Otk_Black, 1.5, 1.0, 63.0, 38.0 );
 OtkMakeButton( OtkOuterWindow, 45, 95, 10, 4, " Exit ", quit, 0 );
 //OtkMainLoop();
 while (1)
  {
   OtkUpdateCheck();
   update_stripcharts();
  }
}

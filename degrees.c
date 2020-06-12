/****************************************************************/
/* Degree.s - Convert degrees Fahrenheight to Celsius and vice 	*/
/*  versa.  An example program for Otk.				*/
/*                                                              */
/* On Linux, compile with:
     cc -I/usr/X11R6/include -L/usr/X11R6/lib degrees.c \
        -lGLU -lGL -lXmu -lXext -lX11 -lm -o degrees.exe
                                                                */
/****************************************************************/


 #include "otk_lib.c"
 OtkWidget formbox1, formbox2;

void convert( void *sw )
 {
  char temp[100];
  float t1, t2;

  if ((int)sw==1)
   {
    Otk_Get_Text( formbox1, temp, 100 );
    if (sscanf(temp,"%f",&t1)!=1) {printf("error reading fahrneheit\n"); return;}
    t2 = (t1 - 32.0) * 5.0/9.0;
    sprintf(temp,"%g",t2);
    Otk_Modify_Text( formbox2, temp );
   }
  else
   {
    Otk_Get_Text( formbox2, temp, 100 );
    if (sscanf(temp,"%f",&t1)!=1) {printf("error reading celsius\n"); return;}
    t2 = t1 * 9.0/5.0 + 32.0;
    sprintf(temp,"%g",t2);
    Otk_Modify_Text( formbox1, temp );
   }
 }

void cnvrt_frmbx( char *s, void *x )
{ convert( x ); }

void help()
{ 
 OtkWidget w;
 float y=15.0, dy=25.0;

 Otk_Set_Text_Aspect( 0.2 );
 w = OtkMakeWindow( Otk_Recessed, Otk_Blue, Otk_LightGray, 10, 10, 70, 80 );
 OtkMakeTextLabel( w, "This program converts temperature", Otk_Black, 3.0, 1.0, 5, y );
 y = y + dy;
 OtkMakeTextLabel( w, "in degrees Fahrenheit to degrees", Otk_Black, 3.0, 1.0, 5, y );
 y = y + dy;
 OtkMakeTextLabel( w, "Celsius, or vice versa.", Otk_Black, 3.0, 1.0, 5, y );
 Otk_Set_Text_Aspect( 1.0 );
}

void quit()
{ exit(0); }

void clr()
{
 Otk_Modify_Text( formbox1, "" );
 Otk_Modify_Text( formbox2, "" );
}


main( int argc, char **argv )
{
 OtkWidget panel1, panel2;

 OtkInitWindow( 400, 200, argc, argv );
 panel1 = OtkMakePanel( OtkOuterWindow, Otk_Raised, Otk_LightGray, 0, 0, 100, 70 );
 Otk_Set_Text_Aspect( 0.45 );
 OtkMakeTextLabel( panel1, "Fahrenheit", Otk_Black, 3.0, 1.0, 5, 25 );
 OtkMakeTextLabel( panel1, "Celsius", Otk_Black, 3.0, 1.0, 5, 65 );
 Otk_Set_Text_Aspect( 1.0 );
 formbox1 = OtkMakeTextFormBox( panel1, "", 12, 36, 20, 35, 25, cnvrt_frmbx, (void *)1 );
 formbox2 = OtkMakeTextFormBox( panel1, "", 12, 36, 60, 35, 25, cnvrt_frmbx, (void *)2 );
 OtkMakeButton( panel1, 75, 20, 20, 25, "Convert", convert, (void *)1 );
 OtkMakeButton( panel1, 75, 60, 20, 25, "Convert", convert, (void *)2 );

 panel2 = OtkMakePanel( OtkOuterWindow, Otk_Raised, Otk_LightGray, 0, 70, 100, 30 );
 OtkMakeButton( panel2,  5, 20, 20, 60, "Help?", help, 0 );
 OtkMakeButton( panel2, 40, 20, 20, 60, "Clear", clr, 0 );
 OtkMakeButton( panel2, 75, 20, 20, 60, " Exit ", quit, 0 );
	   
 OtkMainLoop();
}

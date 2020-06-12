/******************************************************************************/
OTK - A general purpose GUI environment based on OpenGL.
 (GUI = Graphical User Interface.)

For Documentation and Usage Notes, see:    http://otk.sourceforge.net/

 Carl Kindman 1-17-2014     carlkindman@yahoo.com


The package contains the Otk_lib source files:
  Readme.txt
  otk_lib.h
  otk_lib.c
  letter2vector2.c
  gadget_lib.h
  gadget_lib.c 


Demo Files:
	Helloworld.c
	application1.c
	degrees.c
	fbrowse.c
	gadgets_example1.c
	gadgets_example2.c
	imageview.c
	plot_example1.c
	tabbed_panels.c

Build Scripts:
	Unix/Linux: 	makeX11exe.sh
	Windows:  	makeWindowsEXE.bat
	MacOS:  	makeMacOSexe.sh


Version History:
v0.96 - Added ability to use GPU-based anti-aliasing (multi-sampling) if your
	system supports it.  Defaults to off, since it may cause some systems to crash.
	See otk_set_multisamp().   Added missing symbols in built-in font set.
	Some general code cleanups and safety improvements.
v0.95 - Added Otk_Set_Timer function. Some code minor improvements.
v0.94 - Minor code cleanups and safety improvements. 
v0.93 - Minor safety & quality improvements. Added Otk_Set_SliderKnob function.
v0.92 - Completed activating mouse scroll-wheel for all platforms.
v0.91 - Fixed registered window-kill call-back parameter bug.
v0.90 - Improved handling of numeric keypad and mouse scroll wheel.
v0.89 - Added switch for showing hidden 'dot' directories and files.
        Minor fixes for replacing highlighted text.
        Added new symbols and improvements to vector-font set.
v0.88 - Added two new functions to gadget library for setting
        partial ranges of LED and Bar meters.
v0.87 - Added "Browse for directory" mode to file-browser.
        Added file-browser size hints. Fixed outer-window
        background coming up black.  Fixed slider on selection
        lists, such as file-browser, from sometimes not scrolling
        to last item in a list.
v0.86 - Fixed 'missing-cursor' problem, caused by a previous change.
        Tool-tip hover-boxes now disappear after a few seconds.
v0.85 - Added ability to make movies by capturing frames.
        Fixed text alignment in small pull-down menus.
v0.84 - Activated text-highlighting for copy to paste-buffer in single-line
        text-form boxes.
v0.83 - Minor syntax error fix in MS-Win section.
v0.82 - Added Otk_Get_Screen_Size function. Useful for optimally setting
        application's window size.  Enabled registering window-kill call-back
        on OtkOuterWindow, activated by forced closure by window manager.
        Added protection against resizing window too small.
        Added otk_set_not_native_window function, to enable including Otk
        widgets within OpenGL applications that already create window.
v0.81 - Activated tab-key jumping to next text form-box.
        Improved test-capture by adding time-tags.
v0.80 - Added ability to suggest alternate (or recent) directories in file-browser.
        Made pull-down menus fit within screen when opened too near edge of screen.
v0.78 - Adaptively improves rendering for best quality display with good
        speed on given hardware.  Added ability to request better
        quality or better speed, via Otk_Set_Render_Quality_Hint function.
v0.77 - Added function to right-justify formbox text.
        Added makefile.  Fixed syntax error in MSwin version.
v0.76 - Added function to change mouse-cursor.
        Improved menu highlighting. Fixed max-image size.
v0.75 - Added function to attach icons to buttons.
        Improved mouse-feedback on pull-down menus.
        Improved tabbed-panel appearance.
v0.74 - Enhanced MS-Win timer.  Enabled slider-slot clicking.
v0.73 - Added Otk_Snapshot function.  Improved graphics for capable machines.
        Added Otk_Enable_Hoverboxes and Otk_Disable_Hoverboxes functions.
        Minor bug-fix for drop-down menus.
v0.72 - Fixed minor bug in highlighting of coordinated selection lists.
        Improved positioning of hover-boxes near window edges.
v0.71 - Added hover-box (tool-tips) functions.
        Added function to resolve which mouse button was clicked.
v0.70 - Fixed arrow-key issue in ms-win platform.
        Improved sub-window separation.
        Added major/minor version macros.
v0.69 - Added screen-update for Otk_RemoveObject().
        Fixed small memory-leak for text labels, and scz-images.
v0.68 - Added test automated capture/stimulus support capabilities.
v0.67 - Fixed file-browser issue.
v0.66 - Added selection-list coordination function.
        Improved selection-list scroll-bars.
v0.65 - Added checks in image-read-in routines for better image safety.
        Added ability to make efficient user-defined objects.
v0.64 - Faster and more memory-efficient image loads.
        Safer file-browser operation on MacOSx.
        Added two new functions:
                Otk_Set_Window_Name( char *name );
                Otk_Dispose_Image( char *image_file_name );
v0.63 - Further file-browser improvement, strcasecmp patch from Snoyberg.
v0.62 - Improved file-browser gadget.
v0.61 - Added Otk_MakeCircle function.
v0.60 - Added ability to read scz compressed images. Improved safety.


To Compile:   Directives in code should detect environment and do the right things.
  Unix/Linux:    
       gcc -O helloworld.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o helloworld
  
Microsoft with MinGW/Cygwin/MSYS compiler:
       gcc -O helloworld.c -lglu32 -lopengl32 -lwinmm -lgdi32 -o helloworld

MacOS: MacOS user must ensure that they've installed XQuartz and the XCode command-line utilities:  Get XQuartz here:  https://www.xquartz.org/

gcc -O helloworld.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o helloworld

Build script for all 3 platforms are included in the repository

/********************************************************************************/

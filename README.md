OTK - A general purpose, cross-platform GUI library based on OpenGL.<br />


For Documentation and Usage Notes, see:    http://otk.sourceforge.net/<br />

 Carl Kindman 1-17-2014     carlkindman@yahoo.com<br />


The package contains the Otk_lib source files: <br />
  Readme.txt <br />
  otk_lib.h<br />
  otk_lib.c <br />
  letter2vector2.c <br />
  gadget_lib.h <br />
  gadget_lib.c <br />
  
  Demo Files: <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Helloworld.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; application1.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; degrees.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; fbrowse.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; gadgets_example1.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; gadgets_example2.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; imageview.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; plot_example1.c <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; tabbed_panels.c <br />

Build Scripts: <br />
	Unix/Linux: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;makeX11exe.sh <br />
	Windows: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;makeWindowsEXE.bat <br />
	MacOS: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;makeMacOSexe.sh <br />


Version History: <br />
v0.96 - Added ability to use GPU-based anti-aliasing (multi-sampling) if your <br />
	system supports it.  Defaults to off, since it may cause some systems to crash. <br />
	See otk_set_multisamp().   Added missing symbols in built-in font set. <br />
	Some general code cleanups and safety improvements. <br />
v0.95 - Added Otk_Set_Timer function. Some code minor improvements. <br />
v0.94 - Minor code cleanups and safety improvements. <br />
v0.93 - Minor safety & quality improvements. Added Otk_Set_SliderKnob function. <br />
v0.92 - Completed activating mouse scroll-wheel for all platforms. <br />
v0.91 - Fixed registered window-kill call-back parameter bug. <br />
v0.90 - Improved handling of numeric keypad and mouse scroll wheel. <br />
v0.89 - Added switch for showing hidden 'dot' directories and files. <br />
        Minor fixes for replacing highlighted text. <br />
        Added new symbols and improvements to vector-font set. <br />
v0.88 - Added two new functions to gadget library for setting <br />
        partial ranges of LED and Bar meters. <br />
v0.87 - Added "Browse for directory" mode to file-browser. <br />
        Added file-browser size hints. Fixed outer-window <br />
        background coming up black.  Fixed slider on selection <br />
        lists, such as file-browser, from sometimes not scrolling <br />
        to last item in a list. <br />
v0.86 - Fixed 'missing-cursor' problem, caused by a previous change. <br />
        Tool-tip hover-boxes now disappear after a few seconds. <br />
v0.85 - Added ability to make movies by capturing frames. <br />
        Fixed text alignment in small pull-down menus. <br />
v0.84 - Activated text-highlighting for copy to paste-buffer in single-line <br />
        text-form boxes. <br />
v0.83 - Minor syntax error fix in MS-Win section. <br />
v0.82 - Added Otk_Get_Screen_Size function. Useful for optimally setting <br />
        application's window size.  Enabled registering window-kill call-back <br />
        on OtkOuterWindow, activated by forced closure by window manager. <br />
        Added protection against resizing window too small. <br />
        Added otk_set_not_native_window function, to enable including Otk <br />
        widgets within OpenGL applications that already create window. <br />
v0.81 - Activated tab-key jumping to next text form-box. <br />
        Improved test-capture by adding time-tags. <br />
v0.80 - Added ability to suggest alternate (or recent) directories in file-browser. <br />
        Made pull-down menus fit within screen when opened too near edge of screen. <br />
v0.78 - Adaptively improves rendering for best quality display with good <br />
        speed on given hardware.  Added ability to request better <br />
        quality or better speed, via Otk_Set_Render_Quality_Hint function. <br />
v0.77 - Added function to right-justify formbox text. <br />
        Added makefile.  Fixed syntax error in MSwin version. <br />
v0.76 - Added function to change mouse-cursor. <br />
        Improved menu highlighting. Fixed max-image size. <br />
v0.75 - Added function to attach icons to buttons. <br />
        Improved mouse-feedback on pull-down menus .<br />
        Improved tabbed-panel appearance. <br />
v0.74 - Enhanced MS-Win timer.  Enabled slider-slot clicking. <br />
v0.73 - Added Otk_Snapshot function.  Improved graphics for capable machines. <br />
        Added Otk_Enable_Hoverboxes and Otk_Disable_Hoverboxes functions. <br />
        Minor bug-fix for drop-down menus. <br />
v0.72 - Fixed minor bug in highlighting of coordinated selection lists. <br />
        Improved positioning of hover-boxes near window edges. <br />
v0.71 - Added hover-box (tool-tips) functions. <br />
        Added function to resolve which mouse button was clicked. <br />
v0.70 - Fixed arrow-key issue in ms-win platform. <br />
        Improved sub-window separation. <br />
        Added major/minor version macros. <br />
v0.69 - Added screen-update for Otk_RemoveObject(). <br />
        Fixed small memory-leak for text labels, and scz-images. <br />
v0.68 - Added test automated capture/stimulus support capabilities. <br />
v0.67 - Fixed file-browser issue. <br />
v0.66 - Added selection-list coordination function. <br />
        Improved selection-list scroll-bars. <br />
v0.65 - Added checks in image-read-in routines for better image safety. <br />
        Added ability to make efficient user-defined objects. <br />
v0.64 - Faster and more memory-efficient image loads. <br />
        Safer file-browser operation on MacOSx. <br />
        Added two new functions: <br />
                Otk_Set_Window_Name( char *name ); <br />
                Otk_Dispose_Image( char *image_file_name ); <br />
v0.63 - Further file-browser improvement, strcasecmp patch from Snoyberg. <br />
v0.62 - Improved file-browser gadget. <br />
v0.61 - Added Otk_MakeCircle function. <br />
v0.60 - Added ability to read scz compressed images. Improved safety. <br />


To Compile:   Directives in code should detect environment and do the right things. <br />
  Unix/Linux: <br />    
       gcc -O helloworld.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o helloworld<br />
  
Microsoft with MinGW/Cygwin/MSYS compiler: <br />
       gcc -O helloworld.c -lglu32 -lopengl32 -lwinmm -lgdi32 -o helloworld<br />

MacOS: MacOS user must ensure that they've installed XQuartz and the XCode command-line utilities:  Get XQuartz here:  https://www.xquartz.org/ <br />

gcc -O helloworld.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o helloworld<br />

Build script for all 3 platforms are included in the repository<br />
  

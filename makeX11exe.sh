#!/bin/sh
gcc -O helloworld.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o helloworld

gcc -O application1.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o application1

gcc -O degrees.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o degrees

gcc -O fbrowse.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o fbrowse

gcc -O gadgets_example1.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o gadgets_example1

gcc -O gadgets_example2.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o gadgets_example2

gcc -O imageview.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o imageview

gcc -O plot_example1.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o plot_example1

gcc -O tabbed_panels.c -no-pie -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lm -lGL -lGLU -L/opt/X11/lib -lX11 -lXmu -o tabbed_panels


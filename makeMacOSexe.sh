#!/bin/sh
gcc -O helloworld.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o helloworld

gcc -O application1.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o application1

gcc -O degrees.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o degrees

gcc -O fbrowse.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o fbrowse

gcc -O gadgets_example1.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o gadgets_example1

gcc -O gadgets_example2.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o gadgets_example2

gcc -O imageview.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o imageview

gcc -O plot_example1.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o plot_example1

gcc -O tabbed_panels.c -D GL_SILENCE_DEPRECATION -D PLATFORM_KIND=Posix_Platform -I /opt/X11/include -lGL -lGLU -framework OpenGL -framework GLUT -L/opt/X11/lib -lX11 -lXMU -o tabbed_panels



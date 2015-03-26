PROG=test
OBJS=mosaic_gradation.c ppmimage.c
CC=gcc
CFLAGS=-L/usr/X11R6/lib -lX11 -Wall

Album: ${OBJS}
	${CC} ${OBJS} -o ${PROG} ${CFLAGS}
display_r:
	emacs output.ppm &
display:
	emacs sample1.ppm &
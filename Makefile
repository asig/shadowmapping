BIN = smdemo
CFLAGS = -Wall
CXXFLAGS = -Wall
LD = g++
OBJS = \
	COLOR.o \
	FPS_COUNTER.o \
	GLee.o \
	main.o \
	MATRIX4X4.o \
	scene.o \
	TIMER.o \
	VECTOR3D.o \
	VECTOR4D.o \

LDFLAGS =  -lGL -lglut -lGLU

smdemo: $(OBJS)
	$(LD) $(OBJS) -o smdemo $(LDFLAGS)

clean:
	rm *.o
	rm $(BIN)

	
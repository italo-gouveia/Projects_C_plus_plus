CPP    = g++
RM     = rm -f
OBJS   = main.o \
         NovoArquivo.o

LIBS   =
CFLAGS =

.PHONY: Projeto2.exe clean clean-after

all: Projeto2.exe

clean:
	$(RM) $(OBJS) Projeto2.exe

clean-after:
	$(RM) $(OBJS)

Projeto2.exe: $(OBJS)
	$(CPP)  -o $@ $(OBJS) $(LIBS)

main.o: main.cpp
	$(CPP)  -c $< -o $@ $(CFLAGS)

NovoArquivo.o: NovoArquivo.cpp
	$(CPP)  -c $< -o $@ $(CFLAGS)


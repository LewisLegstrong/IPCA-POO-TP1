.PHONY := all build clean
EXT := .exe

EXEC := teste

CC := g++

SRCDIR := src
INCDIR := inc
OBJDIR := obj
SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

all: builddir $(EXEC)$(EXT)

$(EXEC)$(EXT): $(OBJFILES)
	echo $(OBJFILES)
	$(CC) -I./$(INCDIR)/ $(OBJFILES) main.cpp -o  $@

builddir:
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -I./$(INCDIR)/ -c -o $@ $<

clean:
	del /f /q $(OBJDIR) $(EXEC).exe $(EXEC)
	rmdir /s /q $(OBJDIR)

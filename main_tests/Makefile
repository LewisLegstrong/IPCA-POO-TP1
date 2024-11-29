.PHONY := all build clean
EXT := .exe

PARK_EXEC := park_teste
VEHICLE_EXEC := vehicle_teste
TIME_EXEC := time_teste

CC := g++

SRCTEST := main_tests
SRCDIR := ../src
INCDIR := ../inc
OBJDIR := obj

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

call: clean all
all: builddir $(EXEC)$(EXT)
pall: clean builddir $(PARK_EXEC)$(EXT)
vall: clean builddir $(VEHICLE_EXEC)$(EXT)
tall: clean builddir $(TIME_EXEC)$(EXT)

$(PARK_EXEC)$(EXT): $(OBJFILES)
	$(CC) -I./$(INCDIR)/ $(OBJFILES) park_main.cpp -o  $@

$(VEHICLE_EXEC)$(EXT): $(OBJFILES)
	$(CC) -I./$(INCDIR)/ $(OBJFILES) vehicle\&reg_main.cpp -o  $@

$(TIME_EXEC)$(EXT): $(OBJFILES)
	$(CC) -I./$(INCDIR)/ $(OBJFILES) time_main.cpp -o  $@
	
builddir:
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -I./$(INCDIR)/ -c -o $@ $<

clean:
	del /f /q $(OBJDIR) *.exe *.txt
	rmdir /s /q $(OBJDIR)

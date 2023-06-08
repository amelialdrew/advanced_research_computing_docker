# compilers, flags and libraries 
CC = gcc
CFLAGS := -g -O3 -xHost 

# library packages you are useing
LIBS := 
    
# Directories for code objects, and librarys      
OBJDIR := Objects
SRCDIR := Code
BINDIR := .

# source file(s) without suffix 
CFILES = file1 file2 file3 

PROGRAMS = program1 program2

#This says don't look for a file called program1 or program2
.PHONY := $(PROGRAMS)
    
program1 : $(CFILES:%=$(OBJDIR)/%.o) $(mainfile1:%=$(OBJDIR)/%.o)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $(BINDIR)/$@ $(LIBS) 

program2 : $(CFILES:%=$(OBJDIR)/%.o) $(mainfile2:%=$(OBJDIR)/%.o)
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $(BINDIR)/$@ $(LIBS)

# everything that ends in '.o' should be made from the same file with '.c' instead
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@ 
    
clean : 
	rm $(OBJDIR)*.o
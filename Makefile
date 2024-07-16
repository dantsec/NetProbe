# @@Variables
SRCDIR := src
OBJDIR := $(SRCDIR)/obj
BINDIR := .

# @@Files
UTILS := utils
DNS := dns
MAIN := main

# @@Commands
all: $(OBJDIR)
	gcc -c $(SRCDIR)/lib/utils.c -o $(OBJDIR)/$(UTILS).o
	gcc -c $(SRCDIR)/lib/dns.c -o $(OBJDIR)/$(DNS).o
	gcc $(SRCDIR)/main.c $(OBJDIR)/$(UTILS).o $(OBJDIR)/$(DNS).o -o $(BINDIR)/$(MAIN)

clean:
	rm -rf $(BINDIR)/$(MAIN) $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

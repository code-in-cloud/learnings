CC=clang
CCFLAGS=-Wall -g -O0

# Define folder structure
SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin
TESTSRCDIR=tests
TESTBINDIR=$(TESTSRCDIR)/$(BINDIR)

BIN=$(BINDIR)/main
SUBMIT=learning.zip


SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TESTS=$(wildcard $(TESTSRCDIR)/*.c)
TESTBINS=$(patsubst $(TESTSRCDIR)/%.c,$(TESTBINDIR)/%,$(TESTS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

submit:
	rm $(SUBMIT) 2>/dev/null || zip $(SUBMIT) $(BIN)

clean:
	rm -f ${OBJDIR}/* ${LIBDIR}/* ${BINDIR}/*

lib: $(OBJS)
	ar rcs ${LIBDIR}/lib.a $<

run:
	${BIN}

py:
	pytest

$(TESTBINDIR):
	mkdir -p -v $@

test: $(TESTBINDIR) $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(TESTBINS): $(TESTS)
	$(CC) $(CCFLAGS) $< $(OBJS) -o $@ -lcriterion



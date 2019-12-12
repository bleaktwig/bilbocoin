cc     = gcc
cflags = -g
srcdir = src
src    = $(wildcard $(srcdir)/*.c)
obj    = $(src:.c=.o)
exec   = test

$(exec) : $(obj)
	$(cc) $(cflags) -o $@ $^

.PHONY : clean
clean :
	rm $(exec) $(obj)

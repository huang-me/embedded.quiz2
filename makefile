CC = gcc
ref = comparemod.c is_ascii.c quickmod.c hexchar2val.c strlower.c singlenum.c
flags = -Wall -O2
exe = comparemod is_ascii quickmod hexchar2val strlower singlenum
output = *.out.*

all: comparemod is_ascii quickmod hexchar2val strlower singlenum

comparemod: comparemod.c
	$(CC) $^ -o $@ $(flags)

is_ascii: is_ascii.c
	$(CC) $^ -o $@ $(flags)

quickmod: quickmod.c
	$(CC) $^ -o $@ $(flags)

hexchar2val: hexchar2val.c
	$(CC) $^ -o $@ $(flags)

strlower: strlower.c
	$(CC) $^ -o $@ $(flags)

singlenum: singlenum.c
	$(CC) $^ -o $@ $(flags)

clean: $(exe)
	rm -f $(exe) $(output)

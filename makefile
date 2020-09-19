CC = gcc
ref = comparemod.c is_ascii.c quickmod.c hexchar2val.c
exe = comparemod is_ascii quickmod hexchar2val

all: comparemod ascii quickmod hexchar2val

comparemod: comparemod.c
	$(CC) comparemod.c -o comparemod

ascii: is_ascii.c
	$(CC) is_ascii.c -o is_ascii

quickmod: quickmod.c
	$(CC) quickmod.c -o quickmod

hexchar2val: hexchar2val.c
	$(CC) hexchar2val.c -o hexchar2val

clean: $(exe)
	rm -f $(exe)

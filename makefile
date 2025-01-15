CC = gcc
EXEC = deplacer

$(EXEC) : main.o copydir.o copyFile.o copyFileToDir.o removeDir.o RemoveFile.o createDossier.o head.h
	$(CC) -o $@ $^
%.o: $(CC) -o $@  $^ -c %.c  entetes.h -$(CFLAGS)

clean :
	rm -f *.o
mrproper:
	rm -f * ~ $@

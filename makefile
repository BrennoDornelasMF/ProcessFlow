processflow: main.o parcer.o
			gcc main.o parcer.o -o processflow

main.o: main.c parcer.h
		gcc -c main.c

parcer.o: parcer.c parcer.h
		gcc -c parcer.c 

clean:
	rm -f *.o processflow
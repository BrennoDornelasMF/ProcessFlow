processflow: obj/main.o obj/parcer.o
	gcc obj/main.o obj/parcer.o -o processflow

obj/main.o: src/main.c include/parcer.h
	gcc -c -Iinclude src/main.c -o obj/main.o

obj/parcer.o: src/parcer.c include/parcer.h
	gcc -c -Iinclude src/parcer.c -o obj/parcer.o 

clean:
	rm -f obj/*.o processflow
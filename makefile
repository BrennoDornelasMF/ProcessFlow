processflow: obj/main.o obj/parcer.o obj/task.o
	gcc obj/main.o obj/parcer.o obj/task.o -o processflow

obj/main.o: src/main.c include/parcer.h include/task.h
	gcc -c -Iinclude src/main.c -o obj/main.o

obj/parcer.o: src/parcer.c include/parcer.h
	gcc -c -Iinclude src/parcer.c -o obj/parcer.o 

obj/task.o: src/task.c include/parcer.h
	gcc -c -Iinclude src/task.c -o obj/task.o

clean:
	rm -f obj/*.o processflow
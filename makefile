processflow: obj/main.o obj/parcer.o obj/task.o obj/run.o obj/workdir.o
	gcc obj/main.o obj/parcer.o obj/task.o obj/run.o obj/workdir.o -o processflow

obj/main.o: src/main.c include/parcer.h include/task.h
	gcc -c -Iinclude src/main.c -o obj/main.o

obj/parcer.o: src/parcer.c include/parcer.h
	gcc -c -Iinclude src/parcer.c -o obj/parcer.o 

obj/task.o: src/task.c include/parcer.h
	gcc -c -Iinclude src/task.c -o obj/task.o

obj/run.o: src/run.c include/task.h
	gcc -c -Iinclude src/run.c -o obj/run.o

obj/workdir.o: src/workdir.c include/workdir.h
	gcc -c -Iinclude src/workdir.c -o obj/workdir.o

clean:
	rm -f obj/*.o processflow
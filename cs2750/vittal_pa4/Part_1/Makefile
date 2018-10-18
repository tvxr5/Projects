deater: main.o func.o
	gcc main.o func.o -o deater

main.o: main.c
	gcc -c main.c

func.o: func.c func.h
	gcc -c func.c

clean:
	rm *.o  # deater
		# uncomment deater if you want to delete executable as well when cleaning.		

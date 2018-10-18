phone: phone.o phone_fmt.o
	gcc phone.o phone_fmt.o -o phone

phone.o: phone.c
	gcc -c phone.c

phone_fmt.o: phone_fmt.c phone_fmt.h
	gcc -c phone_fmt.c

clean:
	rm *.o  # phone
		# uncomment phone if you want makefile to delete executable as well when cleaning. 

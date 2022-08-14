FLAGS = -c -Wall

a.out: main.o libf.a libg.a
	cc -static main.o ./libf.a ./libg.a ./libf.a

main.o: main.c
	cc $(FLAGS) main.c

libf.a: f1.o f2.o
	ar rcs libf.a f1.o f2.o

f1.o: f1.c
	cc $(FLAGS) f1.c

f2.o: f2.c
	cc $(FLAGS) f2.c

libg.a: g1.o g2.o
	ar rcs libg.a g1.o g2.o

g1.o: g1.c
	cc $(FLAGS) g1.c

g2.o: g2.c
	cc $(FLAGS) g2.c

clean:
	-rm *.o *.a a.out

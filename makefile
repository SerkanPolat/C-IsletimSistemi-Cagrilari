hepsi: derle calistir

derle:
	gcc -I ./include -o ./lib/dizi.o -c ./src/dizi.c
	gcc -I ./include -o ./lib/KomutYorum.o -c src/KomutYorum.c
	gcc -I ./include -o ./lib/Yonlendirme.o -c src/Yonlendirme.c
	gcc -I ./include -o ./bin/main ./src/main.c

calistir:
	./bin/main






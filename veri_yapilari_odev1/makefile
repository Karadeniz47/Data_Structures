tum: derleme calistirma

derleme:
	g++ -I ./inc/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./inc/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./inc/ -o ./lib/SayilarListesi.o -c ./src/SayilarListesi.cpp
	g++ -I ./inc/ -o ./lib/Basamak.o -c ./src/Basamak.cpp

	g++ -I ./inc/ -o ./bin/test ./lib/Dugum.o ./lib/Sayi.o ./lib/SayilarListesi.o ./lib/Basamak.o ./src/test.cpp

calistirma:
	./bin/test
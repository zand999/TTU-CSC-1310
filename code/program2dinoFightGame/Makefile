all				:	DinosaurFight

DinosaurFight	:	Dinosaur.o DinosaurFight.o
					g++ -o DinosaurFight.exe Dinosaur.o DinosaurFight.o
				
DinosaurFight.o	:	DinosaurFight.cpp
					g++ -I ./ -c DinosaurFight.cpp
				
clean			:	DinosaurFight.exe
					del *.o
					del DinosaurFight.exe
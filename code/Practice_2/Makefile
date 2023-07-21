#Makefile for program 1 - video game library

all					:	Program1

Program1			:	Planet.o Driver.o 
						g++ -o Program.exe Planet.o Driver.o

Planet.o			:	Planet.cpp
						g++ -I ./ -c Planet.cpp
				
Driver.o			:	Driver.cpp
						g++ -I ./ -c Driver.cpp

clean				:	Program1.exe
						del *.o 
						del Program1.exe
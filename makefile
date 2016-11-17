exo1_gen_fnc.exe: exo1_gen_fnc.cpp
	g++ -Wall -o exo1_gen_fnc.exe exo1_gen_fnc.cpp

exo2_bonus_genfnc.exe: exo2_bonus_genfnc.cpp
	g++ -Wall exo2_bonus_genfnc.cpp -o exo2_bonus_genfnc.exe

clean:
	rm -f *.exe

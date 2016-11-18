#!/bin/bash

make exo2_bonus_genfnc.exe

./exo2_bonus_genfnc.exe $1 > temp.cnf

if [[ $? == 1 ]]
then
	echo "UNSATISFABLE"
	exit 0
fi

let var=`cat temp.cnf | wc -l`-2
var="s/ght/"$var"/"

cat temp.cnf | sed $var > exo2_fnc.cnf

minisat exo2_fnc.cnf

rm -f temp.cnf

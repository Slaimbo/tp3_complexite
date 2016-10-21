#!/bin/bash

make exo1_gen_fnc.exe > videordure.ord

./exo1_gen_fnc.exe $1 > exo1_fnc.cnf
echo "Graphe : $1"
echo "Fomule :"
cat exo1_fnc.cnf

minisat -verb=0 exo1_fnc.cnf exo1_res.txt > videordure.ord

p="Il n'existe pas de noyau."
test=`cat exo1_res.txt | grep -cE "^SAT"`
echo
echo

if (( $test > 0 ))
then
	p="Il existe un noyau composé de(s) sommet(s) : "
	p=$p`cat exo1_res.txt | grep -Eo "\-?[1-9]+" | grep -v "-" | tr '\n' ' '`
fi

echo $p

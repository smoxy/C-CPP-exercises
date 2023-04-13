#!/bin/sh
mkdir $HOME/TDP_E8_20160414
cd $HOME/TDP_E8_20160414
wget www.dis.uniroma1.it/~iocchi/Didattica/tp_2015_16/Esercitazioni/tdp_esercitazione_8_no_soluzioni.tgz
tar xzvf tdp_esercitazione_8_no_soluzioni.tgz
cd tdp_esercitazione_8_no_soluzioni

echo "\n******************************************"
echo "File scaricati nella cartella"
pwd
echo "******************************************\n"

READMEFILE=$HOME/TDP_E8_20160414/tdp_esercitazione_8_no_soluzioni/README.txt

echo "\n============================================" > $READMEFILE
echo "Svolgere l'esercitazione in questa directory" >> $READMEFILE
echo "Modificare il file matrix_ops.c" >> $READMEFILE
echo "Compilare con make" >> $READMEFILE
echo "============================================\n" >> $READMEFILE

roxterm -T "Esercitazione 8" --color-scheme="Default" -e $SHELL -c "cat README.txt; $SHELL" &






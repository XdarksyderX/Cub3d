#!/bin/bash

read -p "Are you a good or a bad boy? (good/bad): " OPTION

if [[ $OPTION = "good" ]];
then
    CONTADOR=0
    for archivo in $(ls assets/maps/good)
    do
        ./cub3d "assets/maps/good/$archivo" 2> /dev/null & PID=$!
        sleep 1
        kill $PID 2> /dev/null
        if [[ $? -eq 0 ]];
        then
            CONTADOR=$(($CONTADOR + 1))
        else
            echo "Malardo (en el mal sentido) el $archivo"
        fi
    done

    echo "Esta cantidad de mapas son buenardos: $CONTADOR"
    exit 0
fi

CONTADOR=0
for archivo in $(ls assets/maps/bad)
do
	SALIDA=$(./cub3d "assets/maps/bad/$archivo" 2> /dev/null)
	if [[ $? -ne 0 ]] || [[ $SALIDA = "Usage: ./cub3d <map_file.cub>" ]];
	then
		CONTADOR=$(($CONTADOR + 1))
	else
		echo "Buenardo (en el mal sentido) el $archivo"
	fi
done

echo "Esta cantidad de mapas son malardos: $CONTADOR"

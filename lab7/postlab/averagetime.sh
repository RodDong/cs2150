#!/bin/bash

echo "enter the exponent for counter.cpp:"

read e

if [[ $e == "quit" ]] ; then
    exit 0
    fi

iteration=5
totalTime=0

for((i=1; i <=iteration; i++))
do
    echo "Running iteration" "$i" "..."
    time=`./a.out "$e"`
    echo "time taken:" "$time" "ms"
    totalTime=$((totalTime + time))
done
average=$((totalTime / iteration))
echo "5 iterations took" "$totalTime" "ms"
echo "Average time was" "$average" "ms"
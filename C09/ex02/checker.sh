#!/bin/bash

./PmergeMe 1 >> output.txt
./PmergeMe 2 1 >> output.txt
./PmergeMe 1 2 >> output.txt
./PmergeMe 3 1 2 >> output.txt
./PmergeMe 2 3 1 >> output.txt

./PmergeMe 10 3 >> output.txt
./PmergeMe 10 3 5 >> output.txt
./PmergeMe 10 3 5 2 >> output.txt
./PmergeMe 3 5 9 7 4 >> output.txt
./PmergeMe 5 4 3 2 1 >> output.txt
./PmergeMe 1 3 2 5 4 >> output.txt

./PmergeMe 1 2 3 4 5 >> output.txt
./PmergeMe 10 20 30 40 50 60 >> output.txt
./PmergeMe 5 10 15 20 25 30 35 >> output.txt

./PmergeMe 5 4 3 2 1 >> output.txt
./PmergeMe 100 90 80 70 60 50 >> output.txt
./PmergeMe 9 8 7 6 5 4 3 2 1 >> output.txt

./PmergeMe 8 3 7 4 >> output.txt
./PmergeMe 9 1 8 2 7 >> output.txt
./PmergeMe 4 9 1 8 2 7 >> output.txt
./PmergeMe 6 5 4 3 2 >> output.txt

./PmergeMe 42 7 19 3 25 11 >> output.txt
./PmergeMe 88 12 55 33 1 99 >> output.txt
./PmergeMe 17 4 29 6 8 13 21 >> output.txt
./PmergeMe 3 14 15 9 26 5 >> output.txt

./PmergeMe 100 1 99 2 98 3 97 4 >> output.txt
./PmergeMe 50 10 40 20 30 >> output.txt
./PmergeMe 1000 10 900 20 800 30 >> output.txt

./PmergeMe 15 3 27 9 42 1 33 18 24 >> output.txt
./PmergeMe 100 34 78 12 56 90 11 45 67 >> output.txt
./PmergeMe 9 81 72 63 54 45 36 27 18 >> output.txt

./PmergeMe `shuf -i 1-100 -n 10 | tr "\n" " "` >> output.txt

./PmergeMe `shuf -i 1-1000 -n 100 | tr "\n" " "` >> output.txt

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "` >> output.txt

./PmergeMe >> output.txt
./PmergeMe -1 2 >> output.txt
./PmergeMe 0 5 >> output.txt
./PmergeMe 3 abc 5 >> output.txt

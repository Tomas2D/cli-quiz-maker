# cli-quiz-maker

This simple program serves as a tester from a given set of questions where some of them are marked as correct (none/single or multi choice is possible).
When you finish an initial round and you make some mistake, program will offer you to retake the exam with failed answers only.
At the end, you will see some statistics. Look at the example run below for more info.

## Setup
Look at `example.txt`, first line serves  as a question, following lines are possible answers, where correct ones ends with `//`.

## Build
```shell
$ make all
```

## Run
```shell
$ ./quiz.out example.txt
```

## Example test scenario

```shell
$ ./quiz.out example.txt
Instructions:

This is a multi-choice tester. Any answer can be correct or incorrect.
In your answer, type letters of answers you think are correct, delimited by space. Other answers are considered as incorrect by default.

Get ready!

1. Pro klasifikaci platí:

A: Jejím výstupem je reálné číslo.
B: V současné době je nahrazována regresí.
C: jejím výstupem je strom
D: Může být realizována algoritme k-NN. 
E: Jejím výstupem je prvek konečné množiny. 
F: jedná se o metodu učení bez učitele

Your answer: E D
✅ Correct! :-)

2. Nalezení nejkratší cesty ve stavovém prostoru bez ohodnocení akcí garantuje algoritmus:

A: BFS 
B: Hill climbing
C: Greedy search
D: DFS

Your answer: A
✅ Correct! :-)

3. Plánovací úloha ve STRIPS je zadána čtveřicí (P, A, I, G), tato čtveřice reprezentuje:

A: množinu atomů, algoritmus hledání řešení, vstup, koncový stav
B: množinu atomů, množinu akcí, počáteční stav, koncový stav 
C: množinu atomů, algortimus hledání řešení, vstup, koncový stav
D: plánovací algoritmus, množinu atomů, vstup, koncový stav

Your answer: B
✅ Correct! :-)

4. Pravděpodobnost přijetí zhoršující změny při simulovaném žíhání záleží na:

A: velikosti zhoršení 
B: čase
C: setrvačnosti
D: teplotě 

Your answer: D
❗Wrong! Success rate: 75%
❗Correct was: A D 

5. Informované prohledávání stavového prostoru:

A: Může být realizováno Dijkstrovým algoritmem.
B: Může být realizováno algoritmem Greedy search. 
C: Vyžaduje heuristickou funkci. 
D: Může být realizováno algoritmem A*. 

Your answer: B D C
✅ Correct! :-)

6. Umělé neuronové sítě mohou být:

A: použity pro klasifikaci 
B: samoorganizující 
C: dopředné 
D: rekurentní 

Your answer: C D A B
✅ Correct! :-)

7. Předností hill climbingu v základní formě je:

A: zaručená konvergence 
B: zaručená konvergence ke globálnímu optimu
C: rychlost řešní problémů s vysokou dimenzionalitou
D: vysoká klasifikační úspěšnost

Your answer: A
✅ Correct! :-)

=========================================

Test finished!

Questions answered: 7/7
Questions answered (correct): 6/7
Questions answered (incorrect): 1/7
Total correct answers: 29/30
Total incorrect answers: 1/30
Success rate: 6/7
Percentage: 85.7143%

Do you want to rerun test with failed answers only? [yes/no]
Your answer: no


Do you want to start new test? [yes/no]
Your answer: no
```

## TODO
- [] Rewrite `example.txt` to English.
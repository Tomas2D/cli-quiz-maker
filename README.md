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

1. Informed state space search:

A: Requires a heuristic function. 
B: Can be implemented by the A* algorithm. 
C: Can be implemented by the Greedy search algorithm. 
D: Can be implemented by Dijkstra's algorithm.

Your answer: A B C
✅ Correct! :-)

2. Artificial neural networks can be:

A: self-organizing 
B: forward 
C: used for classification 
D: recurrent 

Your answer: D C A B
✅ Correct! :-)

3. The advantage of hill climbing in its basic form is:

A: high classification success rate
B: guaranteed convergence 
C: guaranteed convergence to the global optimum
D: speed of solving high-dimensional problems

Your answer: B
✅ Correct! :-)

4. Finding the shortest path in the state space without evaluating actions is guaranteed by the algorithm:

A: BFS 
B: Hill climbing
C: Greedy search
D: DFS

Your answer: A
✅ Correct! :-)

5. The planning problem in STRIPS is given by a quartet (P, A, I, G), this quartet represents:

A: the set of atoms, the solution finding algorithm, the input, the final state
B: set of atoms, solution search algorithm, input, end state
C: set of atoms, set of actions, initial state, final state 
D: the planning algorithm, the set of atoms, the input, the end state

Your answer: D
❗Wrong! Success rate: 50%
❗Correct was: C 

6. For classification:

A: Its output is a real number.
B: Its output is an element of a finite set. 
C: It can be implemented by the k-NN algorithm. 
D: Its output is a tree
E: It is currently being replaced by regression.
F: it is a method of learning without a teacher

Your answer: C B
✅ Correct! :-)

7. The probability of accepting a deteriorating change in simulated annealing depends on:

A: time
B: temperature 
C: inertia
D: the magnitude of the deterioration 

Your answer: B D
✅ Correct! :-)

=========================================

Test finished!

Questions answered: 7/7
Questions answered (correct): 6/7
Questions answered (incorrect): 1/7
Total correct answers: 28/30
Total incorrect answers: 2/30
Success rate: 6/7
Percentage: 85.7143%

Do you want to rerun test with failed answers only? [yes/no]
Your answer: no


Do you want to start new test? [yes/no]
Your answer: no
```

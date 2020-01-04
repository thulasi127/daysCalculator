all: calculatorA.c calculatorB.c calculatorC.c calculatorD.c calculatorE.c
	gcc -ansi -o calculatorA calculatorA.c
	gcc -ansi -o calculatorB calculatorB.c
	gcc -ansi -o calculatorC calculatorC.c
	gcc -ansi -o calculatorD calculatorD.c
	gcc -ansi -o calculatorE calculatorE.c

calculatorA: calculatorA.c
	gcc -ansi -o calculatorA calculatorA.c

calculatorB: calculatorB.c
	gcc -ansi -o calculatorB calculatorB.c

calculatorC: calculatorC.c
	gcc -ansi -o calculatorC calculatorC.c

calculatorD: calculatorD.c
	gcc -ansi -o calculatorD calculatorD.c

calculatorE: calculatorE.c
	gcc -ansi -o calculatorE calculatorE.c

clean:
	rm calculatorA calculatorB calculatorC calculatorD calculatorE

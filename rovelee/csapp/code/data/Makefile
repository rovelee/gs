test-show: test-show.c show.c
	gcc -o show.test test-show.c

test-bits: test-bits.c bit-operator.c
	gcc -o test-bits.test test-bits.c

ex-test: ex-test.c
	gcc -o ex-test.test ex-test.c

fcomp: fcomp.c
	gcc -O2 -o fcomp.test fcomp.c

clean:
	rm -f *.o *.test
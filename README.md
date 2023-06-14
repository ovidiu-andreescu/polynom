
Exercise 3:

For each section of the exercise, an ifstream file for the input is defined.
The names that are used are: ex3_case1.in, ex3_case2.in, ex3_case3.in, ex3_case4.in, ex3_case5.in

Section 1 accepts input as following: 2 2 1 1 1 0 1 - First - degree | Alternating - exponent, coefficient 
Section 2 accepts input as following: 2 2 1 1 1 0 1 2 - First - degree | Alternating - exponent, coefficient | Last - x to compute
Section 4 accepts input as following: 2 1 2 2 1 1 0 0 1 1 0 1 - First - degree1, Second -degree2 | Alternating - exponent, coefficient for both polynomials(pair of numbers for the first followed by a pair of numbers for the second and so on)
Section 5 accepts input as following: 2 2 1 3 1 1 2 0 1 1 - First - degree | Alternating - exponent, coefficient real, coefficient imaginary

The standard C++ linked list is used.
The user inputs numbers such as degree, exponent, coefficient, x for computing.

We made a class for the terms of the polynomials. The polynomial is constructed by assigning nodes in a linked list
for each term of the rare polynomial. There are 3 constructors for the polynomial: one empty, one that accepts 
a coefficient and an exponent and one for the imaginary polynomial(real, imaginary, exponent).

All the calculations are made between the nodes(terms of the polynomial) of the linked list.

The complex polynomial is showing(or not) garbage memory addresses, when it should have printed the coefficient as (Re + iIm)x^n. The sum
was supposed to be computed as (Re1 + iIm1) + (Re2 + iIm2) = (Re1+Re2) + i(Im1 + Im2) in the method sumPolyIm.

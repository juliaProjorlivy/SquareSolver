# Solve Quadratic Equation
### Description
Solves quadratic equation. Takes coifficients and returns the solution to the equation. Outputs to stdout.

## Installation
To compile 
```
$ make
```

## Usage
```
$ ./solve_square.exe
```
Example run:
```
///$ make
///$ ./solve_square.exe
enter the coefficients separated by spaces:
5 -6 -6
5.000000 -6.000000 -6.000000
the roots are:
x1 = 1.849000
x2 = -0.649000
```

## Testing
```
$ make tests
```
```
$ ./testsing.exe --UnitTest
```
Example:
```
///successfull launch
///$ ./testing.exe --UnitTest
$${\color{green}test case passed successully}$$
```
```
///failed launch
///$ ./testing.exe --UnitTest
$${\color{red}test case failed:
x1 = 0.000000; x2 = 0.000000; nRoots = 0
expected:
x1 = 0.000000; x2 = 6.000000; nRoots = 0}$$
```
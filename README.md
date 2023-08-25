# Solve Quadratic Equation
## Description
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
$ make
$ ./solve_square.exe
enter the coefficients separated by spaces:
5 -6 -6             ///your input
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

    ///successfull launch
    $ make tests
    $ ./testing.exe --UnitTest
<span style="color:green">
    test case passed successully
</span>


    ///failed launch
    $ make tests
    $ ./testing.exe --UnitTest
<span style="color:red">
    test case failed
</span>
    x1 = 0.000000; x2 = 0.000000; nRoots = 0
    expected:
    x1 = 0.000000; x2 = 6.000000; nRoots = 0


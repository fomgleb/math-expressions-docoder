# math-expressions-docoder

# Description
This program is used for decode all valid variations of an encrypted math expression.

# Build
Use `make` command to build application.

# Usage
`./path_of_the_matrix [operator1] [operation] [operator2] [result]`
Use `?` to encrypt some digit of number.
Use " for command parameters, it prevents errors. If something's wrong - use this notation: for example: " ?8? " " * " " 3 " " 2 ", put spaces inside quotes.

# Examples
./path_of_the_matrix "?" "?" "1" "8"
7 + 1 = 8
9 - 1 = 8
8 * 1 = 8
8 / 1 = 8

./path_of_the_matrix "-3" "+" "-?4" "-2?"
-3 + -24 = -27

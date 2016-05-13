import sys
from collections import deque

# A prime number is only divisible by 1 and itself such that there is no
# remainder.  This function checks all other possible divisors of a number to
# see if any result in no remainder, in which case the number is not prime.

def is_prime( num ):
    if num == 0 or num == 1:
        return False

    elif num == 2:
        return True

    else:
        for x in range( 2, num ):
            if num % x == 0:
                return False
    
        else:
            return True

# ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- #

def div_by_3( num ):
    if num % 3 == 0:
        return True

    else:
        return False

# ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- #

def div_by_5( num ):
    if num % 5 == 0:
        return True

    else:
        return False

# ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- #

# the first n values of a Fibonacci series are generated and the value is
# substituted for...
#
# ... "Buzz" if divisible by 3
# ... "Fizz" if divisible by 5
# ... "BuzzFizz" if prime
# ... and the number, otherwise
#
# Note that precedence is assumed top to bottom as show, e.g., 15 becomes
# Buzz (even though divisible by 5) and 5 becomes Fizz even though prime
#
# This implmentation creates the "word" list on the fly and only saves off
# the last two Fib series numbers for forward calculation
#
# Note that the Fibonacci series may start with either 0 or 1 with the same
# result.  This implementation begins with 0, which is substituted for a
# Buzz because 0 is divisible by every number.

def main():
    DIV_BY_3 = 'Buzz'
    DIV_BY_5 = 'Fizz'
    PRIME = 'BuzzFizz'

    if len( sys.argv ) != 2:
        print( 'Usage:  my_prompt>  python3 swift_nav_main.py <num_in_series>' )
        return

    fib_list_words = []
    n = int( sys.argv[ 1 ] )

    if n == 1:
        fib_list_words = [ DIV_BY_3 ]

    elif n == 2:
        fib_list_words = [ DIV_BY_3, 1 ]

    else:
        fib_list_words = [ DIV_BY_3, 1 ]
        last_two = deque( range( 2 ), 2 )

        for x in range( 2, n ): 
            next_el = sum( last_two )
            last_two.append( next_el )
            
            if div_by_3( next_el ):
                fib_list_words.append( DIV_BY_3 )

            elif div_by_5( next_el ):
                fib_list_words.append( DIV_BY_5 )

            elif is_prime( next_el ):
                fib_list_words.append( PRIME )

            else:
                fib_list_words.append( next_el )

    print( fib_list_words )

# ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- #

if __name__ == '__main__':
    main()

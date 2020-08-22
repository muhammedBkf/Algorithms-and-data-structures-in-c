# Prime numbers
This program allows you to : <br />
<strong>1 </strong> _ Generate all prime numbers less than the entered number "n" and put them in a file named generated.txt . <br />
<strong>2</strong> _ Check if an entered number n is a prime number .


## Hint
We can notice that all the prime numbers are of the form  "N=6k+1 or N=6k-1" ,So we first verify if      "N &equiv; 1 mod [6] or N &equiv; -1 mod [6]" . <br />
If the condition is satisfied we check if N is not divisible by all the prime numbers less than its root ,If it isn't N is a <strong>prime number</strong> .
## Note
I have tried to optimize this program so that it does not consume too much memory that's why i used files .

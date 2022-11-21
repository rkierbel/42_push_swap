# 42_push_swap
Implementing an algorithm sorting integers the fastest way possible using two stacks.

Stack A is filled with a random number of random integers.
Stack B is empty.

Following instructions are available (and have to be implemented):

- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements)

- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements)

- ss : sa and sb at the same time

- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty

- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty

- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one

- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one

- rr : ra and rb at the same time

- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one

- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one

- rrr : rra and rrb at the same time

-> The push_swap program receives as an argument a stack, formatted as a list of integers -> it must display the smallest list of instructions to sort the stack A, the smallest number being at the top of the stack => the goal is to sort stack A with the minimum number of operations.

-> The checker program  will get as an argument the stack a formatted as a list of integers. If no argument is given checker stops and displays nothing.
Checker will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, checker will execute them on the stack received as an argument. If after executing those instructions, stack A is actually sorted and B is empty, then checker will display "OK" followed by a ’\n’ on the standard output. In every other case, checker will display "KO" followed by a ’\n’ on the standard output.

You might find below the ideas underlying my implementation.

PUSH_SWAP :

MAIN.C

-> 1. Is there an argument ?

	-> NO > skip verifications, exit

	-> YES > store args in double array of chars; check this array; fill stack A

		-> if failure during checking >> free stack A, free array, exit

		-> no failure during check >> is stack A sorted ?

			-> YES >>> exit success

			-> NO >>> send stack A and B to sorting : first step sort

-> 2. Fill stack A > stack implemented as linked list

	-> following the necessary iterations through array of chars, we insert a node in the list each time ft_atoi successfully return an integer (ft create node)

	-> if create_node fails -> we free array of chars, return false, exit

	-> else free array, return true, pursue sorting

-> 3. ft_check_sort is used to verify if stack is sorted (true) ie if the content of next is higher than current (if next is lower than current, stack is not sorted => return false)


FIRST_STEP_SORT.C

->	GOAL : optimize pushing to stack B

	HOW ? Find mid value in stack A (we first sort the stack with quick sort) ; send numbers lower than this value to stack B

		> if top number in A < mid -> sent to stack B (ft push reorder ——> once the number is on stack B, check if < mid value of stack B -> YES ? We can rotate RB because we want the lower numbers at the bot of stack B - we perform the same check for stack A compared with mid value of stack B) ;

		> else, we find a way to send the first number < mid we encounter to top of A (ft shortest path ---> call ft rotate few if number is closer to top, else call ft rev rotate few). Call ft push reorder.

	-> we divide stack A in two each time we call ft push reorder, until stack A contains 3 numbers only => we create chunks into stack B -> the chunks are sorted with each others, as the min value of chunk on top of B is always greater than the max value of the previous chunk.

	-> we call sort three numbers

	-> we pursue with the second step of sorting


QUICKSORT.C

-> HOW -> create two empty sub arrays, one will hold elements greater than pivot, the other elements lower than pivot. We recurse until sub arrays are sorted. Two basic ops : swapping items, partitioning sections of the array

	-> find pivot -> last element of array

	-> while value at the left pointer in the array is not >= than the pivot, move left pointer to the right (+1)

	-> while value at the right pointer in the array is not <= than the pivot, move right pointer ro left (-1)

	-> if left pointer is <= right pointer, swap values at this location


SORT_UTILS and ERROR.C

-> ft_sort three numbers :

	> if first is == highest, rotate (use of ft find highest)

	> if first is > second highest, swap

	> else rr

	-> we sort three numbers in max 2 moves


SECOND STEP SORT.C

->	1. Until stack B is empty, locate highest and second highest values in stack B -> which one is closer to the top ? If second highest -> send to stack A ; then highest, then swap in stack A

->	2. To select the highest or second highest number, we use the designated ft  and put it on top -> if shortest path from bot and we look for 2nd highest, flag activation -? Indicates us that we will need to reverse rotate -> see in utils ft push second highest, we activate the flag, then call push highest (with help of shortest path ft) and swap first two numbers of stack A

->	3. Shortest path -> finds shortest path to move highest on top


CHECKER :

MAIN.C

-> 1. Args ? YES, we check array, fill stack A, call ft get process inputs until ret GNL != 0 -> what actions to exec

	->then we verify if stack sorted, print result on ctrl+D

-> 2. Call GNL, then ft process actions, if we return false from this ft -> exit failure because value read doesn’t match any action

-> 3. Process actions will route to the right ft or return false

-> 4. Ft fill stack A will insert the args in a linked list, creating a node with ft atoi each time -> failure ? Return false and free OR success return true and free until program ends

-> 5. Check sort after processing instructions


Random number sets generation to test the programs :
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG (dont forget the "`" before ruby and before the semicolon)

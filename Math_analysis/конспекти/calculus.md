
For example, what is 1 + 3 + 5 + 7 + 9? The hard way, computing the definite integral directly, is to add up the items directly. (What about 50 items? 500?)

The easy way is to realize this pattern of numbers comes from a growing square. We know the last change (+9) happens at
, so we’ve built up to a 5

5 square. Therefore, the sum of the entire sequence is 25:
https://betterexplained.com/wp-content/uploads/calculus/course/lesson6/square-addition

Neat! If we have the original pattern, we have a shortcut to measure the size of the steps.

How about a partial sequence like 5 + 7 + 9? Well, just take the total accumulation and subtract the part we’re missing (in this case, the missing 1 + 3 represents a missing 2

2 square).
https://betterexplained.com/wp-content/uploads/calculus/course/lesson6/square-partial-addition

And yep, the sum of the partial sequence is: 5
5 - 2

2 = 25 - 4 = 21.

I hope the strategy clicks for you: avoid manually computing the definite integral by finding the original pattern.

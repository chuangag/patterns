/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name:HUANG, Chia-hung 
Login:chuangag            
Hours to complete assignment (optional): 20?



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
I used 4 nested for loops to check every combination of 4 points that if they form a line.
I add
a static Point origin.
constructor and destructor, get functions of x, y coordinate and the angle with origin.
set functions of x,y coordinate and origin(given x,y)

also overloaded operator < == and!=. All comparing angle with origin. Note that since the return value of atan is double,
we cannot use == directly, so I set a const eps for comparison. The precision can be adjusted by changing the eps.


/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type
 *           What steps did you do to print a minimal representation?
 **********************************************************************/

I reset the origin and sort by angle. Then the points with the same angle are on the line with the origin.
The point type is same as the point in Brute.
I originally want to check the repeated point by a Line class, which contain a,b,c as the coefficients of the line
equation ax+by+c=0. However, I found that due to the floating point error, the checking method won't success. So I 
eventually check repeated lines directly by the result printed. Since I will sort by x coordinate and y coordinate 
before printed, the line should be unique.


/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10		0	    0
     20         0           0
     40         0           0
     80         0.01        0
    100         0.02        0.01
    150         0.07        0.02
    200         0.23        0.04
    400         3.75        0.18
   1000         144.51      1.2   
   2000         NA          5.12
   4000         NA          21.79
  10000         NA          NA


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute:6*10^7 years
Sorting:78 days



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute:O(N^4)
Sorting:O(N^2 *log(N))

N(n origin)*( Nlog(N)(sort of stl) + (N-1)(check whether points except origin is on line) )
=> N^2 *log(N)


/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
As mentioned, the error of finding line can be affected by eps.
Also due to time issue, I have no time to simplify the checking of repeat lines, so
there is still room for improvement on running time.


ALSO, when testing Brute and Fast, use < to input files

BUT, < is not needed for testing patterns, or it will occur Segmentation fault, please beware!!!!!!

And the run time is showed in TERMINAL, unlike the sample which shows by QMessageBox


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

no, just remember to seperate the implementation and declaration or QT cannot run.


/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/



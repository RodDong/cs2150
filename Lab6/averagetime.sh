
#!/bin/bash
#ask the user to enter the dictionary file address
echo $"Enter the dictionary file here: "
#read the dictionary file 
read dict
#ask the user to enter the grid file address
echo $"Enter the grid file here: "
# Ask the user for grid file
read grid
# run the program for five times and sum all the times in miliseconds
RUNNING_TIME1=`./a.out | tail -1`
sum=RUNNING_TIME1
RUNNING_TIME2=`./a.out | tail -1`
sum1=`expr $RUNNING_TIME1 + $RUNNING_TIME2`
RUNNING_TIME3=`./a.out | tail -1`
sum2=`expr $sum1 + $RUNNING_TIME3`
RUNNING_TIME4=`./a.out | tail -1`
sum3=`expr $sum2 + $RUNNING_TIME4`
RUNNING_TIME5=`./a.out | tail -1`
sum4=`expr $sum3 + $RUNNING_TIME5`
#prints out the average of the sums
echo $(($sum4/5))
# Tax-Calculator
Tax Calculator Machine Project - in CCPROG1


Greeting!!!!

The Machine Project is a Tax calculator which is programmed to compute the tax of the user on train law tax code and the NIRC old tax code of the Philippines, the Tax calculator prompts the user to input values which will be utilized by the program in order to produce the desired output which is the tax of the user both “Train Law Tax” and “NIRC Tax”. The values which will be asked from the user are as follows: 

The amount of Gross Salary of the User monthly which is denoted by the variable “monthly” 


The Civil Status of the User given two options: [M] for Married and [S] for Single which is denoted by the variable “status” 


The number of dependents of the User which is denoted by the variable “dependents” 

The Tax calculator has several functions which support its calculations, some these functions are utilized in order to determine the insurance bracket of the user, thus computing the users monthly contribution. 

1. double getSSS(double monthly); (Receives the value of the monthly salary and returns the monthly SSS contribution of the user)  

2. double getPAGIBIG (double monthly);(Receives the value of the monthly salary and returns the monthly Pagibig contribution of the user) 

3. double getPhilhealth (double monthly);(Receives the value of the monthly salary and returns the monthly Philhealth contribution of the user) 

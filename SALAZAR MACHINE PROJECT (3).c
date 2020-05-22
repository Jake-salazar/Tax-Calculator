#include <stdio.h>
/// Greeting!!!!

/*The Machine Project is a Tax calculator which is programmed to compute the tax of the user on train law tax code and the NIRC old tax code of the Philippines, the Tax calculator prompts the user to input values which will be utilized by the program in order to produce the desired output which is the tax of the user both “Train Law Tax” and “NIRC Tax”. The values which will be asked from the user are as follows: 

The amount of Gross Salary of the User monthly which is denoted by the variable “monthly” 


The Civil Status of the User given two options: [M] for Married and [S] for Single which is denoted by the variable “status” 


The number of dependents of the User which is denoted by the variable “dependents” 

The Tax calculator has several functions which support its calculations, some these functions are utilized in order to determine the insurance bracket of the user, thus computing the users monthly contribution. 

1. double getSSS(double monthly); (Receives the value of the monthly salary and returns the monthly SSS contribution of the user)  

2. double getPAGIBIG (double monthly);(Receives the value of the monthly salary and returns the monthly Pagibig contribution of the user) 

3. double getPhilhealth (double monthly);(Receives the value of the monthly salary and returns the monthly Philhealth contribution of the user) */



/// all of the functions that will be used in the program:

double getSSS(double monthly);	
double getPAGIBIG (double monthly); 
double getPhilhealth (double monthly);
double getTrain (double taxable, double monthly);
double gettold (double taxable,double monthly, char status, int dependents);
double getTrainTaxable (double taxable, double monthly);
double getOldTaxable (double taxable, double monthly);

int main ()

{
    double salary;	///The monthly gross salary of the user
	int dependents; ///Variable that stores the number of dependents of the user
	double taxable;
	double monthly; /// The total income of the user per month.
	double traintax;
	double oldtax;
	double deductions;
	double trainTaxable;
	double oldTaxable;
	double sources;
	char answersources;
	char answer;
	char answerSSS;
	char answerPAGIBIG;
	char answerph;
	char status;

	
	do {
	
	printf("HELLO! THIS PROGRAM CALCULATES THE NET ANNUAL TAXABLE INCOME AND  ANNUAL TAX (TRAIN LAW & NIRC) \n\n"); /// Gives an overview of the main purpose of the program

do {

	printf("Please enter your monthly salary: \n"); /// Prompts the User to input the needed monthly salary to calculate the desired ouput
	scanf(" %lf",&salary);

	if (salary < 0)
	printf("Invalid input please try again \n \n");

}while (salary < 0);
 


do {

	printf("\n Enter [M] if Married or [S] if Single: \n");	
	scanf(" %c",&status);

	if (status != 'M' && status != 'm' && status != 'S' && status != 's')
	printf("Invalid input please try again \n \n");

}while (status != 'M' && status != 'm' && status != 'S' && status != 's');

do {

	
	printf("Enter number of dependents (if none enter 0): \n");
	scanf(" %d", &dependents);
	
	
	if (dependents != 0 && dependents != 1 && dependents != 2 && dependents != 3 && dependents != 4)
	printf("Invalid input please try again \n \n");
	
}while (dependents != 0 && dependents != 1 && dependents != 2 && dependents != 3 && dependents != 4);

double sss = 0;
printf("Do you contribute to SSS insurance? \n");
printf("Enter [Y] if yes, if no press any key \n");
scanf(" %c",&answerSSS);
if (answerSSS == 'Y' || answerSSS == 'y' )
{
		
	sss = getSSS(salary);
	printf("Your monthly SSS contribution: %.4lf \n\n", sss);
}
else
{
	sss = 0;
	printf("Your monthly SSS contribution: %.4lf \n\n", sss);
}

double PAGIBIG = 0;
	
printf("Do you contribute to PAGIBIG insurance? \n");
printf("Enter [Y] if yes, if no press any key \n");
scanf(" %c",&answerPAGIBIG);	
	
if (answerPAGIBIG == 'Y' || answerPAGIBIG == 'y' ) 
{
	PAGIBIG = getPAGIBIG (salary);
	printf("Your monthly PAGIBIG contribution: %.4lf \n\n", PAGIBIG);
}
else
{
	PAGIBIG = 0;	
	printf("Your monthly PAGIBIG contribution: %.4lf \n\n", PAGIBIG);
}
	
	double ph = 0;
	

printf("Do you contribute to PHILHEALTH insurance? \n");
printf("Enter [Y] if yes, if no press any key \n");
scanf(" %c",&answerph);	
	
if (answerph == 'Y' || answerph== 'y' ) 
{

	ph = getPhilhealth (salary);
	printf("Your monthly Philhealth contribution: %.4lf \n\n", ph);
}
else
{
	ph = 0;
	printf("Your monthly Philhealth contribution: %.4lf \n\n", ph);
	
}	
	

	deductions = sss+PAGIBIG+ph;

	do {
	/// This Do while Loop enables the user to add other monthly sources of income 
	/// 

	printf("Enter other sources of income: \n");
	scanf(" %lf",&sources);

	if (sources < 0)
	printf("Invalid input please try again \n \n");
	else
	{
	printf("Valid Input. Do you want to add another monthly source of income? Press [Y] if yes or anykey to exit \n");	
	scanf(" %c",&answersources);
	monthly = salary + sources;
	}

}while (answersources == 'Y' || answersources == 'y' );

taxable = monthly - deductions;
	
	
	
	
	
	trainTaxable = getTrainTaxable (taxable, monthly);
	oldTaxable = getOldTaxable (taxable, monthly);
	
	
	traintax = getTrain (taxable,monthly);
	
	oldtax =  gettold (taxable,monthly,status,dependents);
	
	
printf("deductions = %.2lf \n\n", deductions);	

printf("YOUR monthly taxable income for train law = %.2lf \n", trainTaxable);	
printf("NET annual taxable income for train law = %.2lf \n", trainTaxable*12);	
printf("YOUR TAX (TRAIN LAW 2018) = %.2lf \n",traintax);
printf("YOUR ANNUAL TAX IN (TRAIN LAW 2018) = %.2lf \n \n \n",traintax*12);

printf("YOUR monthly taxable income for NIRC Old tax law  = %.2lf \n", oldTaxable);
printf("NET annual taxable income for NIRC Old tax law  = %.2lf \n", oldTaxable*12);
printf("YOUR TAX (NIRC OLD TAX LAW) = %.2lf \n",oldtax);
printf("YOUR ANNUAL TAX (NIRC OLD TAX LAW) = %.2lf",oldtax*12);	


printf("\n DO YOU WANT TO CALCULATE AGAIN Press [Y] to continue. Press any Key To Exit \n");
scanf(" %c",&answer); 
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}while(answer == 'y' || answer == 'Y');

printf("THANK YOU FOR USING INCOME TAX CALCULATOR 2018");



}





double getSSS(double monthly)
{
	
	double sss;	
	
	if (monthly >= 1000 && monthly <= 1249.99)
		sss = 36.30;
	else if (monthly >= 1250 && monthly <= 1749.99)
		sss = 54.50;
	else if (monthly >= 1750 && monthly <= 2249.99)
		sss = 72.20;
	else if (monthly >= 2250 && monthly <= 2749.99)
		sss =  90.80;
	else if (monthly >= 2750 && monthly <= 3249.99)
		sss = 109.00;
	else if (monthly >= 3250 && monthly <= 3749.99)
		sss = 127.20;
	else if (monthly >= 3750 && monthly <= 4249.99)
		sss = 145.30;
	else if (monthly >= 4250 && monthly <= 4749.99)
		sss = 163.50;
	else if (monthly >= 4750 && monthly <= 5249.99)
		sss = 181.70;
	else if (monthly >= 5250 && monthly <= 5749.99)
		sss =  199.80;
	else if (monthly >= 5750 && monthly <= 6249.99)
		sss = 218.00;
	else if (monthly >= 6250 && monthly <= 6749.99)
		sss = 236.20;
	else if (monthly >= 6750 && monthly <= 7249.99)
		sss= 254.30;
	else if (monthly >= 7250 && monthly <= 7749.99)
		sss = 272.50;
	else if (monthly >= 7750 && monthly <= 8249.99)
		sss = 290.70;
	else if (monthly >= 8250 && monthly <= 8749.99)
		sss = 308.80;
	else if (monthly >= 8750 && monthly <= 9249.99)
		sss = 327.00;
	else if (monthly >= 9250 && monthly <= 9749.99)
		sss = 345.20;
	else if (monthly >= 9750 && monthly <= 10249.99)
		sss = 363.30;
	else if (monthly >= 10250 && monthly <= 10749.99)
		sss = 381.50;
	else if (monthly >= 10750 && monthly <= 11249.99)										 			
		sss = 399.70;
	else if (monthly >= 11250 && monthly <= 11749.99)
		sss = 417.80;
	else if (monthly >= 11750 && monthly <= 12249.99)				
		sss = 436.00;
	else if (monthly >= 12250 && monthly <= 12749.99)
		sss = 454.20;
	else if (monthly >= 12750 && monthly <= 13249.99)
		sss = 472.30;
	else if (monthly >= 13250 && monthly <= 13749.99)
		sss = 490.50;
	else if (monthly >= 13750 && monthly <= 14249.99)
		sss = 508.70;
	else if (monthly >= 14250 && monthly <= 14749.99)
		sss = 526.80;
	else if (monthly >= 14750 && monthly <= 15249.99)
		sss = 545.00;
	else if (monthly >= 15250 && monthly <= 15749.99)
		sss= 563.20;
	else if (monthly >= 15250)
		sss = 581.30;		
	else 
		sss = 0;
		
		
									
	return sss;
}



double getPAGIBIG (double monthly)
{
	double PAGIBIG;
	
		if (monthly <= 1500)
		PAGIBIG = monthly * 0.01;
	else if (monthly > 1500 && monthly < 5000)
		PAGIBIG = monthly * 0.02;
	else 
		PAGIBIG = 100;		
	
	return PAGIBIG;	
}


double getPhilhealth (double monthly)
{
	double ph;
	
		if (monthly >= 0 && monthly <= 10000)
		ph = 137.50;
		else if (monthly >= 10000.01 && monthly < 39999)
		ph = (monthly*0.0275)/2;
		else 
		ph = 550;		
	
	return ph;	
}



double getTrain (double taxable,double salary)
{
	double tax;
	
	if (salary > 90000)
		taxable = taxable + ( (salary - 90000)/12 );
	else 
		taxable = taxable;
		
	if (taxable > 0 && taxable < 20833 )
		tax = 0;
	else if (taxable >= 20833 && taxable <= 33332)
		tax =  (taxable- 20833)*0.20; 
	else if (taxable >= 33333 && taxable <= 66666)
		tax =  ((taxable- 33333)*0.25)+2500;		
	else if (taxable >= 66667 && taxable <= 166666)
		tax =  ((taxable - 66667)*0.30)+10833;
	else if (taxable >= 166667 && taxable <= 666666)
		tax =  ((taxable - 166667)*0.32)+40833.33;
	else if (taxable >= 666667)
		tax =  ((taxable - 666667)*0.35)+200833.33;
		
		return tax;		
}

double getTrainTaxable (double taxable, double salary)
{
	double taxableTrain;
	if (salary > 90000)
		taxableTrain = taxable + ( (salary - 90000)/12 );
	else 
		taxableTrain = taxable;
		
		
		return taxableTrain;
	
}

double getOldTaxable (double taxable, double salary)
{
	double taxOld;
	
	if (salary > 82000)
		taxOld = taxable + ( (salary - 82000)/12 );
	else 
		taxOld = taxable;
	
	return taxOld;
}

double gettold (double taxable,double salary, char status, int dependents)
{
	double tax;
	
	if (salary > 82000)
		taxable = taxable + ( (salary - 82000)/12 );
	else 
		taxable = taxable;
		
	if (dependents == 0)
	{
	
	if (taxable >= 1 && taxable <= 4167 )
		tax = 0;
	else if (taxable >= 4167 && taxable < 5000)
		tax =  (taxable- 4167)*0.05; 
	else if (taxable >= 5000 && taxable < 6667)
		tax =  ((taxable- 5000)*0.10)+41.67;		
	else if (taxable >= 6667 && taxable < 10000)
		tax =  ((taxable - 6667)*0.15)+208.33;
	else if (taxable >= 10000 && taxable < 15833)
		tax =  ((taxable - 10000)*0.20)+ 708.33;
	else if (taxable >= 15833 && taxable < 25000)
		tax =  ((taxable - 15833)*0.25)+ 1875.0;	
	else if (taxable >= 25000 && taxable < 45833)
		tax =  ((taxable - 25000)*0.30)+ 4166.67;
	else 
		tax =  ((taxable - 45833)*0.32)+ 10416.67;
}
else if (dependents ==1)
{
		
	if (taxable >= 1 && taxable <= 6250)
		tax = 0;
	else if (taxable >= 6250 && taxable < 7083)
		tax =  (taxable- 6250)*0.05; 
	else if (taxable >= 7083 && taxable < 8750)
		tax =  ((taxable- 7083)*0.10)+41.67;		
	else if (taxable >= 8750 && taxable < 12083)
		tax =  ((taxable - 8750)*0.15)+208.33;
	else if (taxable >= 12083 && taxable < 17917)
		tax =  ((taxable - 12083)*0.20)+ 708.33;
	else if (taxable >= 17917 && taxable < 27083)
		tax =  ((taxable - 17917)*0.25)+ 1875.0;	
	else if (taxable >= 27083 && taxable < 47917)
		tax =  ((taxable - 27083)*0.30)+ 4166.67;
	else 
		tax =  ((taxable - 47917)*0.32)+ 10416.67;	
}
else if (dependents == 2)	
{
		
	if (taxable >= 1 && taxable <= 8333)
		tax = 0;
	else if (taxable >= 8333 && taxable < 9167 )
		tax =  (taxable- 8333)*0.05; 
	else if (taxable >= 9167 && taxable < 10833)
		tax =  ((taxable- 9167)*0.10)+41.67;		
	else if (taxable >= 10833 && taxable < 14167)
		tax =  ((taxable - 10833)*0.15)+208.33;
	else if (taxable >= 14167 && taxable < 20000)
		tax =  ((taxable - 14167)*0.20)+ 708.33;
	else if (taxable >= 20000 && taxable < 29167)
		tax =  ((taxable - 20000)*0.25)+ 1875.0;	
	else if (taxable >= 29167 && taxable < 50000)
		tax =  ((taxable - 29167)*0.30)+ 4166.67;
	else 
		tax =  ((taxable - 50000)*0.32)+ 10416.67;	
}
	
	else if (dependents ==3)
	{
	
	if (taxable >= 1 && taxable <= 10417)
		tax = 0;
	else if (taxable >= 10417 && taxable < 11250 )
		tax =  (taxable- 10417)*0.05; 
	else if (taxable >= 11250 && taxable < 12917)
		tax =  ((taxable- 11250)*0.10)+41.67;		
	else if (taxable >= 12917 && taxable < 16250)
		tax =  ((taxable - 12917)*0.15)+208.33;
	else if (taxable >= 16250 && taxable < 22083)
		tax =  ((taxable - 16250)*0.20)+ 708.33;
	else if (taxable >= 22083 && taxable < 31250)
		tax =  ((taxable - 22083)*0.25)+ 1875.0;	
	else if (taxable >= 31250 && taxable < 52083)
		tax =  ((taxable - 31250)*0.30)+ 4166.67;
	else 
		tax =  ((taxable - 52083)*0.32)+ 10416.67;
}
	
else if (dependents ==4)
{
	if (taxable >= 1 && taxable <= 12500)
		tax = 0;
	else if (taxable >= 12500 && taxable < 13333 )
		tax =  (taxable- 12500)*0.05; 
	else if (taxable >= 13333 && taxable < 15000)
		tax =  ((taxable- 13333)*0.10)+41.67;		
	else if (taxable >= 15000 && taxable < 18333)
		tax =  ((taxable - 15000)*0.15)+208.33;
	else if (taxable >= 18333 && taxable < 24167)
		tax =  ((taxable - 18333)*0.20)+ 708.33;
	else if (taxable >= 24167 && taxable < 33333)
		tax =  ((taxable - 24167)*0.25)+ 1875.0;	
	else if (taxable >= 33333 && taxable < 54167)
		tax =  ((taxable - 33333)*0.30)+ 4166.67;
	else 
		tax =  ((taxable - 54167)*0.32)+ 10416.67;
}
else
	tax = 0;	
	return tax;		

}



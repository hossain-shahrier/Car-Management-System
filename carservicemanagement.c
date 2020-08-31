
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main(){
    // Creating variables of Customer :
    char serviceDate[100],CarRegistrationNumber[200];
    int servieSerialNumber,typeofServiceNo,invoiceNumber;

    // Confirmation of Service
    char* confirm;

    // Creating variables of Service :
    char* customerName;
    int serialNo[8] ={1,2,3,4,5,6,7,8};
    char* serviceType[8] = {"Repair punctured car tyre / piece", "Car tyre change / piece" ,
     "Mineral Oil Change", "Synthetic Oil Change", "Battery Change", "Head light bulb change / piece",
     "Taillight bulb change / piece", "Car wash"};
    int time[8] = {10,15,20,20,5,5,5,10};
    int normal[8] ={5,150,80,130,200,6,6,10},urgent[8] ={6,160,90,140,210,8,8,12};
    int ServiceFee;

    for (int i = 0; i <8; i++)
    {
            printf("\n");     
            printf("%d .",serialNo[i] );
            printf("%s " , serviceType[i]);
            printf("%s",",");
            printf("%s ","Time Needed :");
            printf("%d",time[i]);
            printf("%s"," days");
            printf("%s",",");
            printf("%s "," Service Fee :: ");
            printf("%s ","Normal :");
            printf("%s","RM");
            printf("%d ",normal[i]);
            printf("%s "," Urgent :");
            printf("%s","RM");
            printf("%d ",urgent[i]);
        };
        
        // Confirmation Processing
        printf("\n");
        printf("%s","Are you confirm to take service?(Y/N):");
        gets(confirm);


        FILE *fptr;

        fptr = fopen("file.txt","w");
        char data[DATA_SIZE];

        if(fptr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
        int count =0;
        if (*confirm == 'y'||'Y')
        {
            /* Registration */
            // Name Input
            count++;
            // Invoice Number
            printf("%s","Invoice Number :");
            printf("%d",count);
            printf("\n");
            // Customer Name
            printf("%s","Customer Name :");
            scanf("%s", &*customerName);
            // Service Date Input as String
            printf("%s","Service Date : ");
            scanf("%d",&serviceDate);
            // CarRegistrationNumber as String
            printf ("%s","Car Registration Number :");
            scanf("%d", &CarRegistrationNumber);

            // Service Serial Number as Int
            printf ("%s","Service Needed (Use Serial Number) : ");
            scanf("%d", &servieSerialNumber);

            // Type of Service as Int
            printf("%s","Type of Service (1.Normal/2.Urgent) :");
            scanf("%d", &typeofServiceNo);

            //Service Fee
            printf("%s","Service Fee :");
            scanf("%d", &ServiceFee);

            //File Invoice Number
            fprintf(fptr,"%s %d %s %d %s %d %s %d %s %d %s %d %s %s","Invoice Number : ",count,"\nService Date :",*serviceDate,"\nCar Registration Number :"
            ,*CarRegistrationNumber,"\nService Needed (Serial Number) : ",servieSerialNumber,"\nType of Service (1.Normal/2.Urgent) :",typeofServiceNo
            ,"\nService Fee :",ServiceFee,"\nCustomer Name :",customerName);
            fgets(data, DATA_SIZE, stdin);
            fclose(fptr);

            printf("\nFile created and saved successfully. :) \n");

            
        }
        else
        {
            printf("Thank you!");
        }
        
    
    

        return 0;

}

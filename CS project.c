//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Project - 19MS069[AS], 10MS070[FA], 19MS105[AJ], 19MS067[SG]
//            Animesh       Firoz       Aritra      Sidharth
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Global Structure Declarations:
typedef struct credentilas
{
        char name[50];
        char uname[50];
        char pswd[50];
} CREDENTIALS;

typedef struct product
{
        char id[12];
        char name[50];
        float price;
        char color[12];
        int quantity;
        char description[200];
} PRODUCT;

typedef struct van
{
  char id[5];
  float date;   // Format: MM.DD
} VAN;

typedef struct purchase
{
	char id[12];
	int quant;
} PURCHASE;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Global Variable Declarations:
float real_Date;
char global_van_id[5];
int prods_in_cart=0;
char global_uname[20];
PURCHASE products[50];
PRODUCT purchased[50];
char *chosen_address, *chosen_time;
int diff;
char addressx[800];
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Functions/Modules:
void real_date(); //0                                                                    >> [SG]
void frontpage(); //1                                                                    >> [AS], [FA], [AJ], [SG]
void selectionpage(); //2                                                                >> [FA]
int check_credentials(char* filename, char* uname, char* pswd); //3                      >> [AS]
void fileWrite(char* filename, CREDENTIALS* info, int no_of_fields); //4                 >> [AS]
void fileWrite1(char* filename, CREDENTIALS* info, int nof); //5                         >> [AJ]
void fileWrite2(char* filename, PRODUCT* info, int no_of_fields); //6                    >> [SG]
int checkID(char* filename, char* id); //7                                               >> [AS]
void load_admin(); //8                                                                   >> [AJ]
void load_userInfo(); //9                                                                >> [FA]
void load_products(); //10                                                               >> [SG]
void loginpage(); //11                                                                   >> [AJ]
void adminpage(); //12                                                                   >> [FA]
void adminpage2(); //13                                                                  >> [AS], [FA]
void signup(); //14                                                                      >> [AJ]
void new_user(char* fname, CREDENTIALS* info, int nof); //15                             >> [SG], [AJ]
void updatePage(); //16                                                                  >> [AS], [AJ]
void updatePage2(char* filename, char* id);  //17                                        >> [AS]
void updateProduct(char *filename, char *id, int new_stock, float new_price); //18       >> [AS]
void deletionPg(); //19                                                                  >> [AJ]
void deletion(char* filename, char* id); //20                                            >> [SG]
const char* timing(); //21                                                               >> [FA]
void load_vans(); //22                                                                   >> [SG]
void fileWrite3(char* filename, VAN* info, int no_of_fields); //23                       >> [SG]
void update_vans(); //24                                                                 >> [SG], [AJ]
int van_avail_check(); //25                                                              >> [SG], [FA]
void reserve_van(char* id); //26                                                         >> [SG]
int modeofpurchase(); //27                                                               >> [AJ]
const char* address(); //28                                                              >> [AJ]
void browse_products(); //29                                                             >> [FA]
void cart(PRODUCT* info, int len_of_info); //30                                          >> [AS], [SG]
PURCHASE buyProduct(); //31                                                              >> [AS]
void fileWrite4(char* filename, PRODUCT* info, int no_of_fields);  //32                  >> [FA]
void addition_products(); //33                                                           >> [FA]
PRODUCT checkID2(char* filename, char* id);	//34                                         >> [AS]
void search(char* filename, char* id); //35                                              >> [AS], [FA]
void checkout(PRODUCT *info, int len_of_info); //36                                      >> [AS], [SG]
void checkout2(PRODUCT *info, int len_of_info); //37                                     >> [AS], [SG]
void thankyou1(); //38                                                                   >> [SG]
void updateProduct2(char *filename, char *id, int user_stock); //39                      >> [AS]
void read_vans(); //40                                                                   >> [SG], [FA]
void unique_id_check(); //41                                                             >> [AS], [AJ]
void thankyou2(); //42                                                                   >> [AJ], [FA]
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void real_date() //0
{
  float month, day;
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  month = 1.0*(tm.tm_mon + 1);
  day = 0.01*(tm.tm_mday);
  real_Date = month + day;
  //printf("%f", real_Date); //test case
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void frontpage()  //1 Homepage
{
        system("clear");
        char x, y;
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("     https://www.biggsalez.com                                                                                                                      \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("                                                                                                                                                    \n");
        printf("     >> Special student-discount on Laptops, Kindles and Tablets!!                                                                                  \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                      + + + + + + + + + + + + + + + + + + + +                                                       \n");
        printf("                                                      +             BIGG SALEZ              +                                                       \n");
        printf("                                                      + + + + + + + + + + + + + + + + + + + +                                                       \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                              FIND IT, LOVE IT, BUY IT!                             \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("     __________________________________________________                                                                                             \n");
        printf("                                                                                                                                                    \n");
        printf("         > We are extremely excited to serve you!                                                                                                   \n");
        printf("         > We ensure cheapest online prices!                                                                                                        \n");
        printf("         > Your smile is most valuable :D                                                                                                           \n");
        printf("     __________________________________________________                                                                                             \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                     >> Use Code:AFSA for discount upto 50 percent.                 \n");
        printf("    For Customer Support e-mail at: support@biggsalez.com                            * Terms and Conditions apply.                                  \n");
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("\n\n                               >> Press Enter/Return to go to log in/sign up page.\n");
        printf("                                   >>>");
        x = getchar();
        selectionpage();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void selectionpage()  //2 //Login/Signup page
{
        system("clear");
        char x, y;
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("                                                    +             BIGG SALEZ              +                                                         \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("          ________________________________________________________________________________________________________________________________          \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                         _____________________________                                                              \n");
        printf("                                                          >> User Log-in          [1]                                                               \n");
        printf("                                                                                                                                                    \n");
        printf("                                                          >> New User Sign-up     [2]                                                               \n");
        printf("                                                                                                                                                    \n");
        printf("                                                          >> Admin Log-in         [3]                                                               \n");
        printf("                                                         _____________________________                                                              \n");
        printf("                                                          >> Go to Home Page      [0]                                                               \n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("       >>> Enter Choice: ");
        inp:
        x = getchar();
        y = getchar();
        printf(".__________________________________________________________________________________________________________________________________________________.\n\n");
        switch (x)
        {
                case '1':
                        system("clear");
                       loginpage();//login();
                        break;
                case '2':
                        system("clear");
                        signup();           //signup();
                        break;
                case '3':
                        system("clear");
                        adminpage();        //adminlogin();
                        break;
                case '0':
                        system("clear");
                        frontpage();
                        break;
                default:
                        printf("Invalid input, choose from the given list!:\n");
                        goto inp;
                        break;
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int check_credentials(char* filename, char* uname, char* pswd)  //3 //Returns one if login credentials match else returns zero
{
        FILE *fptr;
        CREDENTIALS read_info, info_stored[50];
        int i=0, j;

        fptr = fopen(filename,"r");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        while(fread(&read_info, sizeof(CREDENTIALS), 1, fptr))
        {
                strcpy(info_stored[i].name, read_info.name);
                strcpy(info_stored[i].uname, read_info.uname);
                strcpy(info_stored[i].pswd, read_info.pswd);
                i++;
        }
        fclose(fptr);
        for(j=0; j<i; j++)
        {
                if(!strcmp(info_stored[j].uname, uname))
                {
                        if(!strcmp(info_stored[j].pswd, pswd))
                        {
                                printf("\n\tWelcome %s!!", info_stored[j].name);
                                strcpy(global_uname, info_stored[j].name);
                                return 1;
                        }
                        else
                        {
                                printf("\n\tIncorrect password, please try again!!\n");
                                return 0;
                        }
                }
        }
        printf("\n\tInvalid User!!\n");
        return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fileWrite(char* filename, CREDENTIALS* info, int no_of_fields)  //4
{
        FILE *fptr;
        int x;

        fptr = fopen(filename,"w");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        for(x = 0; x< no_of_fields; x++)
        {
                fwrite(&info[x], sizeof(CREDENTIALS), 1, fptr);
        }

        fclose(fptr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fileWrite1(char* filename, CREDENTIALS* info, int nof)  //5
{
        FILE *fptr;
        int x;

        fptr = fopen(filename,"a");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }
        fwrite(&info[0], sizeof(CREDENTIALS), 1, fptr);
        fclose(fptr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fileWrite2(char* filename, PRODUCT* info, int no_of_fields)  //6
{
        FILE *fptr;
        int x;

        fptr = fopen(filename,"w");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        for(x = 0; x < no_of_fields; x++)
        {
                fwrite(&info[x], sizeof(PRODUCT), 1, fptr);
        }

        fclose(fptr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int checkID(char* filename, char* id)  //7 checks for a product and prints its current details
{
        FILE *fptr;
        PRODUCT read_info, info_stored[50];
        int i=0 ,x = -1;

        fptr = fopen(filename,"r");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }
        //printf("Hi");

        while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
        {
            if(!strcmp(read_info.id,id))
            {
            	x = i;
			      }
                strcpy(info_stored[i].id, read_info.id);
                strcpy(info_stored[i].name, read_info.name);
                info_stored[i].price = read_info.price;
                strcpy(info_stored[i].color, read_info.color);
                strcpy(info_stored[i].description, read_info.description);
                info_stored[i].quantity= read_info.quantity;
                //printf ("id = %s quantity = %d stock = %s\n", read_info.id, read_info.quantity, read_info.description);
                i++;
          }
		if(x!=-1)
		{
			printf("\t\tCurrent product details:\n\t\t1. Product ID = %s\n\t\t2. Product Name = %s\n\t\t3. Product Price = %.2f\n\t\t4. Product Color = %s\n\t\t5. Product Description = %s\n\t\t6. Product Quantity = %d\n",
			info_stored[x].id, info_stored[x].name, info_stored[x].price, info_stored[x].color, info_stored[x].description, info_stored[x].quantity );
			return 1;
		}
		else
		{
			printf("\n\t\tInvalid ID!!\n");
			return 0;
		}
        //printf("%.2f\n", info_stored[1].price);
        //printf("%s", info_stored[1].description);

        fclose(fptr);
        //return *info_stored;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void load_admin()  //8
{
        CREDENTIALS admins[4];

        FILE *fptr;
        char *filename = "admin_credentials.txt";

        //loading the data
        strcpy(admins[0].name, "Animesh Sanjay Sinha");
        strcpy(admins[0].uname, "Animesh");
        strcpy(admins[0].pswd, "anime134");

        strcpy(admins[1].name, "Sidharth Gupta");
        strcpy(admins[1].uname, "Sidharth");
        strcpy(admins[1].pswd, "sid123");

        strcpy(admins[2].name, "Aritra Jana");
        strcpy(admins[2].uname, "Aritra");
        strcpy(admins[2].pswd, "arit456");

        strcpy(admins[3].name, "Firoz Alam");
        strcpy(admins[3].uname, "Firoz");
        strcpy(admins[3].pswd, "firoz147");

        //writing
        fileWrite(filename, admins, 4);
        //fileRead(filename);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void load_userInfo()  //9
{
        CREDENTIALS user[1];
        FILE *fptr;
        char *filename = "userInfo.txt";

        //loading the data
        strcpy(user[0].name, "Sid");
        strcpy(user[0].uname, "sgx");
        strcpy(user[0].pswd, "sgx123");
        //writing
        fileWrite(filename, user, 1);
        //fileRead(filename);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void load_products()  //10
{
        PRODUCT prods[3];
        FILE *fptr;
        char *filename = "products.txt";

        //loading the data
        strcpy(prods[0].id, "WATCH00001");
        strcpy(prods[0].name, "SWATCH X1 Ultra slim watch");
        prods[0].price = 2799;
        strcpy(prods[0].color, "BLACK");
        prods[0].quantity= 40;
        strcpy(prods[0].description, "Elegant, ultra slim, black round-dial watch for men with date and day dial.");

        strcpy(prods[1].id, "MACBO00001");
        strcpy(prods[1].name, "MacBook Pro 13-inch, intel core-i5");
        prods[1].price = 157000;
        strcpy(prods[1].color, "SILVER");
        prods[1].quantity=401;
        strcpy(prods[1].description, "Apple authorised online reseller.");

        strcpy(prods[2].id, "BOOKS00001");
        strcpy(prods[2].name, "Classical Mechanics [Goldstein]");
        prods[2].price = 849;
        strcpy(prods[2].color, "-");
        prods[2].quantity=85;
        strcpy(prods[2].description, "Paper-back 3rd edition.");

        //writing
        fileWrite2(filename, prods, 3);
        //fileRead(filename);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loginpage()  //11
{
	system("clear");
        char uname[50], pswd[50], *filename = "userInfo.txt", id[12];
        int ch, x;
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("                                                    +             BIGG SALEZ              +                                                         \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("          ________________________________________________________________________________________________________________________________          \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                   USER LOGIN                                                                       \n");
        printf("                                                         _____________________________                                                              \n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("                                                                                                                                                    \n");
        printf("                                           >>> Username: ");
        //getchar();
        gets(uname);
        printf("\n                                           >>> Password: ");
        gets(pswd);
        ch = check_credentials(filename, uname, pswd);
		//getchar();
        if(ch == 0)
        {
        	    printf("\n\t\tPress Enter/Return to try again: ");
        	    getchar();
                loginpage();
        }
        else
        {
        	come:
          printf("\n\t\tPress 1 to Search products using 'Product ID' OR press 2 to go to browse page: ");
          scanf("%d",&x);
          printf("\n");
          if(x==1)
		  {
		  	printf("\t\tEnter Product ID: ");
		  	scanf("%s",id);
		  	search("products.txt",id);
		  	printf("\n\n\t\tPress Enter/Return to choice selection: ");
			getchar();
			getchar();
			goto come;
		  }
		  else
		  {
		  	browse_products();
		  }
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void adminpage()  //12
{
		system("clear");
        char uname[50], pswd[50], x, *filename = "admin_credentials.txt";
        int ch;
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("                                                    +             BIGG SALEZ              +                                                         \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("          ________________________________________________________________________________________________________________________________          \n");
        printf("                                                                                                                                                    \n");
        printf("                                                                  ADMIN LOGIN                                                                       \n");
        printf("                                                         _____________________________                                                              \n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("                                                                                                                                                    \n");
        printf("                                           >>> Username: ");
        //getchar();
        gets(uname);
        printf("                                           >>> Password: ");
        gets(pswd);
        ch = check_credentials(filename, uname, pswd);
        if(ch == 0)
        {
        		printf("\n\t\tPress Enter/Return to try again: ");
        		getchar();
                adminpage();
        }
        if(ch == 1)
        {
        	adminpage2();
		}
        x = getchar();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void adminpage2() //13
{
	system("clear");
	char x, y, idd[12];
	int i = 1;
	printf("\n\n");
        printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n");
        printf("                                                                                                                  Hi %s!                          \n\n", global_uname);
        printf("                                                        _____________________________                                                             \n");
        printf("                                                         >> Browse Products      [1]                                                              \n");
        printf("                                                                                                                                                  \n");
        printf("                                                         >> Search Products      [2]                                                              \n");
        printf("                                                                                                                                                  \n");
		printf("                                                         >> Add Products         [3]                                                              \n");
        printf("                                                                                                                                                  \n");
        printf("                                                         >> Delete Products      [4]                                                              \n");
        printf("                                                                                                                                                  \n");
        printf("                                                         >> Update Products      [5]                                                              \n");
		    printf("                                                        _____________________________                                                             \n");
        printf("                                                         >> Go to Home Page      [0]                                                              \n");
        printf("                                                                                                                                                  \n");
        printf("__________________________________________________________________________________________________________________________________________________\n");
        printf("       >>> Enter Choice: ");
    inp:
	x = getchar();
    y = getchar();
    printf(".__________________________________________________________________________________________________________________________________________________.\n\n");

    switch(x)
    {
    	case '1' :  system("clear");
    				browse_products();
					break;
		case '2' :  printf("\t\tEnter Product ID: ");
		  			scanf("%s",idd);
		  			search("products.txt",idd);
		  			printf("\n\n\t\tPress Enter/Return to go to admin page: ");
					getchar();
					getchar();
					adminpage2();
  					break;
		case '3' :	system("clear");
					//printf("Add products\n");
					addition_products();
					break;
		case '4' :  system("clear");
					deletionPg();
					break;
		case '5' :  system("clear");
					updatePage();
					break;
		case '0' :  system("clear");
					frontpage();
					break;
		default:	printf("Invalid input, choose from the given list:\n");
					goto inp;
					break;

	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void signup()  //14
{
  char name[50],uname[50], pswd[50], x, *filename = "userInfo.txt";
  char ch;
  CREDENTIALS a[1];
  printf(".__________________________________________________________________________________________________________________________________________________.\n");
  printf("                                                                                                                                                    \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("                                                    +             BIGG SALEZ              +                                                         \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("          ________________________________________________________________________________________________________________________________          \n");
  printf("                                                                                                                                                    \n");
  printf("                                                               New User Sign-up                                                                     \n");
  printf("                                                         _____________________________                                                              \n");
  printf("                                                                                                                                                    \n");
  printf(" __________________________________________________________________________________________________________________________________________________ \n");
  printf("                                                                                                                                                    \n");
  printf("\n            >>Input the following credentials:                                                                                                    \n\n");
  printf("\n                                           >> Name: ");
  gets(name);
  printf("\n                                           >> Username: ");
  scanf("%s", uname);
  printf("\n                                           >> Password: ");
  scanf("%s", pswd);
  //ch = check_credentials(filename, uname, pswd);
  ch = getchar();
  strcpy(a[0].name, name);
  strcpy(a[0].uname, uname);
  strcpy(a[0].pswd, pswd);
  printf("Your chosen log-in credentials are:\n");
  printf("Username: %s\n", a[0].uname);
  printf("Password: %s\n", a[0].pswd);
  //x = scanf("%c\n");
  new_user(filename, a, 1);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void new_user(char* fname, CREDENTIALS* info, int nof)  //15 //This module is called during signup
{
  FILE *fptr;
  char x;
  int y=0;
  CREDENTIALS user;

  fptr = fopen(fname,"r+");
  /*if(fptr == NULL)
  {
    printf("Error opening the file\n");
    exit(1);
  }*/
  //printf("Tag 1\n");
  while(fread(&user, sizeof(CREDENTIALS), 1, fptr))
  {
    if(!strcmp(info[0].uname, user.uname))
    {
      printf("\n\n       >>> This username is taken. Kindly choose another, Press Enter/Return to continue: \n");
      y++;
      char h = getchar();
      signup();
      //printf("Press enter to continue:");
      //scanf("%c", x);
      break;
    }
  }
  if(y==0)
  {
    fclose(fptr);
    //printf("I reached y=0 condition\n");
    fileWrite1(fname, info, nof);
    frontpage();
  }
  else
  {
    signup();
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void updatePage() //16
{
	system("clear");
	char id[12], *filename = "products.txt";
	int ch;
		    printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("                                                    +             BIGG SALEZ              +                                                         \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("          ________________________________________________________________________________________________________________________________          \n");
        printf("                                                                                                                  Hi %s!                            \n\n", global_uname);
        printf("                                                                                                                                                    \n");
        printf("                                                                  UPDATE PAGE                                                                       \n");
        printf("                                                         _____________________________                                                              \n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("\n\n\t\t>> Enter Product ID: ");
        scanf("%s",id);
        getchar();

  ch = checkID(filename, id);
  if(ch == 1)
  {
  		printf("\n\t\tPress enter to continue: ");
  		getchar();
    	updatePage2(filename, id);
	}
	else
	{
		printf("\n\t\tPress Enter to Try Again!!\n\n");
    getchar();
		updatePage();
	}
    //printf("%d", ch);
    //printf("Hi %d",strlen(id));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void updatePage2(char* filename, char* id) //17 //Updates product by calling updateProduct module for each specific case
{
	system("clear");
	char x, y;
	int i = 1;
	int new_stocks, ch2;
	float price;
	printf("\n\n");
        printf(".__________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                    \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("                                                    +             BIGG SALEZ              +                                                         \n");
        printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
        printf("          ________________________________________________________________________________________________________________________________          \n");
        printf("                                                                                                                  Hi %s!                          \n\n", global_uname);
        printf("                                                                                                                                                    \n");
        printf("                                                                                                                                                    \n");
        printf("                                                      ______________________________________                                                        \n");
        printf("                                                      >> Update Stocks                  [1]                                                         \n");
        printf("                                                                                                                                                    \n");
        printf("                                                      >> Update Price                   [2]                                                         \n");
        printf("                                                                                                                                                    \n");
        printf("                                                      >> Update Both Stock & Price      [3]                                                         \n");
		    printf("                                                      _____________________________________                                                         \n");
        printf("                                                          >> Go to Home Page      [0]                                                               \n");
        printf("                                                                                                                                                    \n");
        printf(" __________________________________________________________________________________________________________________________________________________ \n");
        printf("\t\t>>> Enter Choice: ");
    inp:
	  x = getchar();
    y = getchar();
    printf(".__________________________________________________________________________________________________________________________________________________.\n\n\t\t");

    switch(x)
    {
    	case '1' :
    				new_stocks, price = -1;
    				printf("Enter New Stocks: ");
    				scanf("%d", &new_stocks);
    				getchar();
    				updateProduct(filename, id, new_stocks, price);
    				ch2 = checkID(filename, id);
    				printf("\n\n\t\tPress Enter/Return to go back to Update Page: ");
    				getchar();
    				updatePage();
					break;
		case '2' :
					new_stocks = -1, price;
					printf("Enter New Price: ");
    				scanf("%f", &price);
    				getchar();
    				updateProduct(filename, id, new_stocks, price);
    				ch2 = checkID(filename, id);
    				printf("\n\n\t\tPress Enter/Return to go back to Update Page: ");
    				getchar();
    				updatePage();
					break;
		case '3' :
					new_stocks, price;
					printf("Give new stocks and new price (space separated): ");
    				scanf("%d %f", &new_stocks, &price);
    				getchar();
    				updateProduct(filename, id, new_stocks, price);
    				ch2 = checkID(filename, id);
    				printf("\n\n\t\tPress Enter/Return to go back to Update Page: ");
    				getchar();
    				updatePage();
					break;
		case '0' :  system("clear");
					frontpage();
					break;
		default:	printf("Invalid input, choose from the given list:\n");
					goto inp;
					break;

	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void updateProduct(char *filename, char *id, int new_stock, float new_price) //18 //This module is called while updating a product
{
	FILE *fptr;
	PRODUCT read_info, *products;
	int no_of_rec = 0, x;
	fptr = fopen(filename, "r+");
	//printf("%s %s %d %0.2f", filename, id, new_stock, new_price);
	if(fptr == NULL)
	{
		printf("ERROR, can't open file'");
		exit(1);
	}
	while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
	{
		no_of_rec++; //Counting number of records of type 'PRODUCT' in file.
	}

	products = (PRODUCT*)malloc(no_of_rec*sizeof(PRODUCT)); //allocating dynamically space for the number of records in the file to be read.
	rewind(fptr); //Going to the beginnig of the file.

	x = 0;
	while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
	{
		strcpy(products[x].id, read_info.id);
		strcpy(products[x].name, read_info.name);
		strcpy(products[x].color, read_info.color);
		strcpy(products[x].description, read_info.description);
		products[x].price = read_info.price;
		products[x].quantity = read_info.quantity;
		if(!strcmp(read_info.id,id))	//Check if this is the record to be updated
		{
			if(new_stock!=-1) //Updating
			{
				products[x].quantity = new_stock;
				//printf("Hi");
			}
			if(new_price!=-1)
			{
				products[x].price = new_price;
			}
		}
		x++;
	}

	fclose(fptr);

	//writing afresh in the file with updated data
	fptr = fopen(filename, "w");
	for(x = 0; x<no_of_rec; x++)
	{
		fwrite(&products[x], sizeof(PRODUCT), 1, fptr);
	}
	fclose(fptr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void deletionPg() //19
{
  system("clear");
  char id[12], *filename = "products.txt";
  char a;
	int x;
		printf(".__________________________________________________________________________________________________________________________________________________.\n");
    printf("                                                                                                                                                    \n");
    printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
    printf("                                                    +             BIGG SALEZ              +                                                         \n");
    printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
    printf("          ________________________________________________________________________________________________________________________________          \n");
    printf("                                                                                                                  Hi %s!                          \n\n", global_uname);
    printf("                                                                                                                                                    \n");
    printf("                                                             PRODUCT DELETION PAGE                                                                  \n");
    printf("                                                         _____________________________                                                              \n");
    printf("                                                                                                                                                    \n");
    printf("                                                                                                                                                    \n");
    printf("                                                                                                                                                    \n");
    printf(" __________________________________________________________________________________________________________________________________________________ \n");
    printf("\n\n\t\t>> Enter the ID of the Product to be deleted: ");
    scanf("%s",id);
    getchar();

    x = checkID(filename, id);
    if(x == 1)
    {
    	printf("\n\t\tPress Enter to continue: ");
    	getchar();
      	deletion(filename, id);
    }
  	else
  	{
  		//printf("\n\t\t>> Incorect ID...!!\n\n");
      printf("\t\t>> Press Enter to try again.");
      a = getchar();
  		deletionPg();
  	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void deletion(char* filename, char* id) //20 //This module is called while deleting a product
{
  FILE *fptr;
  PRODUCT info, productsx[20], *prods;
  fptr = fopen(filename, "r+");
  int nop=0, x;
  char t1, t2, idd[12];
  if(fptr == NULL)
  {
    printf("ERROR! Could not open the file!");
    exit(1);
  }
  while(fread(&info, sizeof(PRODUCT), 1, fptr))
  {
    nop++;  //Total number of products
  }

  prods = (PRODUCT*)malloc((nop-1)*sizeof(PRODUCT));
  rewind(fptr);
  x = 0;
  while(fread(&info, sizeof(PRODUCT), 1, fptr))
  {
    if(!strcmp(info.id, id))
    {
      printf("           >> Deleting....\n\n");
    }
    else
    {
       //printf("Hi");
      strcpy(prods[x].id, info.id);
      strcpy(prods[x].name, info.name);
      strcpy(prods[x].color, info.color);
      strcpy(prods[x].description, info.description);
      prods[x].price = info.price;
      prods[x].quantity = info.quantity;
      x++;
    }
  }

  fclose(fptr);
  //printf("%s",products[1].description);
  fptr = fopen(filename, "w");
	for(x = 0; x<(nop-1); x++)
	{
		fwrite(&prods[x], sizeof(PRODUCT), 1, fptr);
	}
	fclose(fptr);

  system("clear");

  printf("\n\t\t\t >> The product was succesfully deleted!\n\n");
  printf(".__________________________________________________________________________________________________________________________________________________.\n");
  printf("                                                                                                                                                    \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("                                                    +             BIGG SALEZ              +                                                         \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("          ________________________________________________________________________________________________________________________________          \n");
  printf("                                                                                                                  Hi %s!                          \n\n", global_uname);
  printf("                                                                                                                                                    \n");
  printf("                                                                                                                                                    \n");
  printf("                                                         _____________________________                                                              \n");
  printf("                                                          >> Browse Products      [1]                                                               \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> Search Products      [2]                                                               \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> Add Products         [3]                                                               \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> Delete Products      [4]                                                               \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> Update Products      [5]                                                               \n");
  printf("                                                         _____________________________                                                              \n");
  printf("                                                          >> Go to Home Page      [0]-----(Log Out)                                                 \n");
  printf("                                                                                                                                                    \n");
  printf(" __________________________________________________________________________________________________________________________________________________ \n");
  printf("       >>> Enter Choice: ");
  inp:
  t1 = getchar();
  t2 = getchar();
  printf(".__________________________________________________________________________________________________________________________________________________.\n\n");

  switch(t1)
  {
  case '1' :  system("clear");
          browse_products();
        break;
  case '2' :printf("\t\tEnter Product ID: ");
		  	scanf("%s",idd);
		  	search("products.txt",idd);
		  	printf("\n\n\t\tPress Enter/Return to go to admin page: ");
			getchar();
			getchar();
			adminpage2();

  		break;
  case '3' :	system("clear");
        addition_products();
        break;
  case '4' :  system("clear");
        deletionPg();
        break;
  case '5' :  system("clear");
        updatePage();
        break;
  case '0' :  system("clear");
        frontpage();
        break;
  default:	printf("Invalid input, choose from the given list:\n");
        goto inp;
        break;
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const char* timing() //21 //returns time slot selected by customer
{
  system("clear");
  char x, y, time[30];

  printf(".__________________________________________________________________________________________________________________________________________________.\n");
  printf("                                                                                                                                                    \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("                                                    +             BIGG SALEZ              +                                                         \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("          ________________________________________________________________________________________________________________________________          \n");
  printf("                                                                                                                  Hi %s!                          \n\n", global_uname);
  printf("                                                                                                                                                    \n");
  printf("                          >> Choose your preferred timing of delivery:                                                                              \n");
  printf("                                                         _____________________________                                                              \n");
  printf("                                                          >> 09:00 a.m. to 01:00 p.m.     [1]                                                       \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> 12:00 noon to 05:00 p.m.     [2]                                                       \n");
  printf("                                                                                                                                                    \n");
  printf("                                                          >> 03:00 p.m. to 07:00 p.m.     [3]                                                       \n");
  printf("                                                         _____________________________                                                              \n");
  //printf("                                                          >> Go to the previous page      [0]                                                       \n");
  printf("                                                                                                                                                    \n");
  printf(" __________________________________________________________________________________________________________________________________________________ \n");
  printf("       >>> Enter Choice: ");

  inp:
          x = getchar();
          y = getchar();
  printf("\n.__________________________________________________________________________________________________________________________________________________.\n\n");
  switch (y)
  {
          case '1':
                  return "09:00 a.m. to 01:00 p.m.";
                  break;
          case '2':
                  return "12:00 noon to 05:00 p.m.";
                  break;
          case '3':
                  return "03:00 p.m. to 07:00 p.m.";
                  break;
          /*case '0':
                  printf("Going back lol\n");
                  break;*/
          default:
                  printf("Invalid input!:\n");
                  goto inp;
                  break;
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void load_vans() //22  //Initialising vans data
{
  VAN vans[7];

  FILE *fptr;
  char *fname = "vans.txt";

  strcpy(vans[0].id, "FA001");
  vans[0].date = 0.0;

  strcpy(vans[1].id, "AS001");
  vans[1].date = 0.0;

  strcpy(vans[2].id, "AJ001");
  vans[2].date = 0.0;

  strcpy(vans[3].id, "SG001");
  vans[3].date = 0.0;

  strcpy(vans[4].id, "AB001");
  vans[4].date = 0.0;

  strcpy(vans[5].id, "CD001");
  vans[5].date = 0.0;

  fileWrite3(fname, vans, 6);

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fileWrite3(char* filename, VAN* info, int no_of_fields)  //23
{
        FILE *fptr;
        int x;

        fptr = fopen(filename,"w");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        for(x = 0; x < no_of_fields; x++)
        {
                fwrite(&info[x], sizeof(VAN), 1, fptr);
        }

        fclose(fptr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void update_vans() //24 //Runs everytime the program is used and updates vans for present date
{
  int i=0;
  FILE *fptr;
  VAN read_info, info[6];
  fptr = fopen("vans.txt","r+");
  while(fread(&read_info, sizeof(VAN), 1, fptr))
  {
    strcpy(info[i].id, read_info.id);
    if((real_Date - (read_info.date) > 0.0))
    {
      info[i].date = 0.0;
    }
    else
    {
      info[i].date = read_info.date;
    }
    i++;
  }
  fclose(fptr);

  fileWrite3("vans.txt", info, 6);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int van_avail_check() //25 //If the returned integer is 1, a van is available.
{
  int i=0, a=0;
  char van_id[5];
  FILE *fptr;
  VAN read_info;
  fptr = fopen("vans.txt","r+");
  while(fread(&read_info, sizeof(VAN), 1, fptr))
  {
    if(read_info.date == 0.0)
    {
      a = 1;
      strcpy(global_van_id, read_info.id);
      break;
    }
  }
  fclose(fptr);
  return a;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void reserve_van(char* id) //26 //Function for updating van status during checkout.
{
  int i=0;
  FILE *fptr;
  VAN read_info, info[6];
  fptr = fopen("vans.txt","r+");
  while(fread(&read_info, sizeof(VAN), 1, fptr))
  {
    strcpy(info[i].id, read_info.id);
    if(!strcmp(id, read_info.id))
    {
      info[i].date = real_Date;
    }
    else
    {
      info[i].date = read_info.date;
    }
    i++;
  }
  fileWrite3("vans.txt", info, 6);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int modeofpurchase() //27
{
	system("clear");
	char *s1 = "Take-away/collect-from-store";
	char *s2 = "Home delivery", x, y;

	printf(".__________________________________________________________________________________________________________________________________________________.\n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  	printf("                                                    +             BIGG SALEZ              +                                                         \n");
  	printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  	printf("          ________________________________________________________________________________________________________________________________          \n");
    printf("                                                                                                                  Hi %s!                            \n", global_uname);
  	printf("                                                                                                                                                    \n");
  	printf("                        >> Choose your preferred mode of purchase:                                                                                  \n");
  	printf("                                                      _______________________________________                                                       \n");
  	printf("                                                                                                                                                    \n");
	printf("                                                      >> Take-away/collect-from-store    [1]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                      >> Home delivery                   [2]                                                        \n");
  	printf("                                                      _______________________________________                                                       \n");
  	//printf("                                                      >> Go to the previous page         [0]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf(" __________________________________________________________________________________________________________________________________________________ \n");
  	printf("       >>> Enter Choice: ");

	 inp:
	  x = getchar();
    y = getchar();
    printf(".__________________________________________________________________________________________________________________________________________________.\n\n\t\t");

    switch(y)
    {
    	case '1' :  system("clear");
    				return 0;
					break;
		case '2' :  system("clear");
					return 1;
					break;
		/*case '0' :  system("clear");
					printf("previous page"); //needs to be updated
					break;*/
		default:	printf("Invalid input, choose from the given list:\n");
					goto inp;
					break;

	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const char* address() //28 //returns address area selected by customer
{
	system("clear");
	char x, y;
	printf(".__________________________________________________________________________________________________________________________________________________.\n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  	printf("                                                    +             BIGG SALEZ              +                                                         \n");
  	printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  	printf("          ________________________________________________________________________________________________________________________________          \n");
    printf("                                                                                                                  Hi %s!                            \n", global_uname);
  	printf("                                                                                                                                                    \n");
  	printf("                         >> Choose your preferred address for delivery:                                                                             \n");
  	printf("                                                      _______________________________________                                                       \n");
  	printf("                                                                                                                                                    \n");
	  printf("                                                      >> Boring Road, Patna              [1]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                      >> Sector 62, Noida                [2]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                      >> Vasant Vihar, New Delhi         [3]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf("                                                      >> Howrah, Kolkata                 [4]                                                        \n");
  	printf("                                                      _______________________________________                                                       \n");
  //printf("                                                      >> Go to the previous page         [0]                                                        \n");
  	printf("                                                                                                                                                    \n");
  	printf(" __________________________________________________________________________________________________________________________________________________ \n");
  	printf("       >>> Enter Choice: ");

	 inp:
	  x = getchar();
      y = getchar();
    printf(".__________________________________________________________________________________________________________________________________________________.\n\n\t\t");

    switch(y)
    {
    	case '1' :  system("clear");
    				return "Boring Road, Patna";
					break;
		case '2' :  system("clear");
					return "Sector 62, Noida";
					break;
		case '3' :  system("clear");
					return "Vasant Vihar, New Delhi";
					break;
		case '4' :  system("clear");
					return "Howrah, Kolkata";
					break;
		/*case '0' :  system("clear");
					printf("previous page"); //needs to be updated
					break;*/
		default:	printf("Invalid input, choose from the given list:\n");
					goto inp;
					break;

	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void browse_products() //29
{
  system("clear");
	FILE *fp;
	PRODUCT prds[3];
	fp=fopen("products.txt","r");
  printf(".__________________________________________________________________________________________________________________________________________________.\n");
  printf("                                                                                                                                                    \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("                                                    +             BIGG SALEZ              +                                                         \n");
  printf("                                                    + + + + + + + + + + + + + + + + + + + +                                                         \n");
  printf("          ________________________________________________________________________________________________________________________________          \n");
  printf("                                                                                                                  Hi %s!                            \n", global_uname);
	while(fread(&prds,sizeof(PRODUCT),1,fp))
	{
		if(prds[0].quantity>0)
		{
		printf("______________________________________________________________________________________________________\n");
		printf(" \n");
		printf(" Product ID = %s\n",prds[0].id);
		printf(" Product Name = %s\n",prds[0].name);
		printf(" Product Price = %0.2f\n",prds[0].price);
		printf(" Products Remaining = %d\n",prds[0].quantity);
    printf(" Product Colour = %s\n",prds[0].color);
		printf(" Product Description = %s\n",prds[0].description);
		printf("______________________________________________________________________________________________________");
		printf("\n");
		}


	}
	fclose(fp);

	printf("\nEnter the number of different products you want to purchase: ");
	scanf("%d", &diff);
	printf("\n");
	if(diff == 0)
	{
		getchar();
		frontpage();
	}
	//PURCHASE products[diff]; //Made Global
	int x;
	for(x=0; x<diff; x++)
	{
		products[x] = buyProduct();
		printf("\n");
	}

	//printf("%s", products[1].id); //test case
	if(diff>0)
	{
		for(x=0; x<diff; x++)
		{
		purchased[x] = checkID2("products.txt",products[x].id);
		}
		cart(purchased, diff);
	}

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void cart(PRODUCT* info, int len_of_info) //30
{
  system("clear");
  printf(".__________________________________________________________________________________________________________________________________________________.\n");
  printf("                                                                                                                                                    \n");
  printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                          \n");
  printf("                                                   +             BIGG SALEZ              +                                                          \n");
  printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                          \n");
  printf("          ________________________________________________________________________________________________________________________________          \n");
  printf("                                                                                                                  Hi %s!                            \n", global_uname);
  printf("                                                                                                                                                  \n");
  printf("     >>> Products in your cart are:\n\n");
  int i=0, y;
  float tot_price = 0.0;
  while(i < len_of_info)
  {
    printf("     >> Product [%d]:\n", (i+1));
    printf("           > ID: %s\n", info[i].id);
    printf("           > Name: %s\n", info[i].name); //will discuss
    printf("           > Quantity: %d\n", products[i].quant);
    printf("           > Price for %d: %0.2f\n", products[i].quant, ((info[i].price)*(products[i].quant)));
    printf("_________________________________________________________________________________________________________\n\n");
    tot_price = tot_price + (info[i].price)*(products[i].quant);
    i++;
  }
  printf("     >> Subtotal: %0.2f\n", tot_price);
  printf("     >> GRAND TOTAL: %0.2f  [Inclusive of 12 percent Tax and all charges.]\n\n\n", (tot_price + 0.12*tot_price));
  printf(">>> Press 1 <followed by enter/return> to proceed or any other key to go back to browsing:\n");
  char x,y2;
  getchar();
  x=getchar();
  int v;
  switch (x)
  {
    case ('1'):
        y2 = modeofpurchase();
        //prinf("%d", y); //test case
		if(y2==1)
		{
			chosen_address = address();
			//printf("%s", chosen_address); //test case
			chosen_time = timing();
			//printf("%s", chosen_time); //test case
			//Availability of van to be checked, after which I will update the stocks in products databse.
      		printf("\t\tPress Enter/Return to check availability of a van.\n");
      		getchar();
      		v = van_avail_check();

      if(v)
      {
      	getchar();
        printf("\t\tA van is available!\n");
        printf("\t\tPress 1 to proceed to checkout or anything else to go to browse products.\n");
        y = getchar();
        getchar();
        if(y=='1')
        {
          //printf("CHECKOUT");
          if(y2)
          {
          	checkout2(purchased, diff);
		  }

    	}
        else
		{
			browse_products();
		}
     }
      else
      {
      	getchar();
        printf("\t\tWe are extremely sorry but no van is available at the moment.\n\t\tKindly try on another day.\n");
        printf("\n\n\t\tPress Enter/Return to go to home page.");
        getchar();
        frontpage();
      }
    }
  	if(y2 == 0)
  	{
  		chosen_time = timing();
		checkout(purchased, diff);
	}
    break;
    default:
        browse_products();
        //printf("LOL");
        break;

  }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
PURCHASE buyProduct() //31 //returns a struct of purchase type containing the info of items to be purchased
{
	PURCHASE goods;

	char pid[12];
	int quantity;

	printf("Enter Product ID: ");
	scanf("%s", pid);
	printf("Enter Quantity: ");
	scanf("%d", &quantity);
	strcpy(goods.id,pid);
	goods.quant = quantity;

	return goods;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fileWrite4(char* filename, PRODUCT* info, int no_of_fields)  //32
{
        FILE *fptr;
        int x;

        fptr = fopen(filename,"a");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        for(x = 0; x< no_of_fields; x++)
        {
                fwrite(&info[x], sizeof(PRODUCT), 1, fptr);
        }

        fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void addition_products() //33
{
	system("clear");
		printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n");
        printf("                                                                                                                  Hi %s!                          \n", global_uname);
        printf("                                                                                                                                                   \n");
	char id[20],name[30],color[30],description[100];
	int stock,choice,x=0,num;
	float price;

	char *filename="products.txt";

	printf("\n\n\t\tEnter no of new products: ");
	scanf("%d",&num);
	getchar();

	PRODUCT add_prds[num];
	for(x=0;x<num;x++)
	{
		printf("\n\t\tEnter the product id to add: ");
	    gets(id);
	    unique_id_check(id);
		strcpy(add_prds[x].id,id);
		printf("\t\tEnter product name: ");
		gets(name);
		strcpy(add_prds[x].name,name);
		printf("\t\tEnter price of product: ");
		scanf("%f",&price);
		add_prds[x].price=price;
		printf("\t\tEnter available stock: ");
		scanf("%d",&stock);
		add_prds[x].quantity=stock;
		getchar();
		printf("\t\tMention the color of the product: ");
		gets(color);
		strcpy(add_prds[x].color,color);
		printf("\t\tDescription of product: ");
		gets(description);
		strcpy(add_prds[x].description,description);
	}
	fileWrite4(filename,add_prds,num);

	printf("\n\t\tThe product was added successfully!! \n\t\tPress Enter/Return to go to admin page: ");
	getchar();
	adminpage2();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
PRODUCT checkID2(char* filename, char* id)  //34 Returns a PRODUCT type struct for each entry of PURCHASE type struct stored in products array
{
        FILE *fptr;
        PRODUCT read_info, info_stored;
        int i=0 ,x = -1;

        fptr = fopen(filename,"r");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }


        while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
        {
            if(!strcmp(read_info.id,id))
            {
            	x = i;

                strcpy(info_stored.id, read_info.id);
                strcpy(info_stored.name, read_info.name);
                info_stored.price = read_info.price;
                strcpy(info_stored.color, read_info.color);
                strcpy(info_stored.description, read_info.description);
                info_stored.quantity= read_info.quantity;
                //printf ("id = %s quantity = %d stock = %s\n", read_info.id, read_info.quantity, read_info.description); //test case
        	}
          }
		if(x!=-1)
		{
			return info_stored;
		}
		else
		{
			printf("\n\t\tInvalid ID!!\n");
		}
        //printf("%.2f\n", info_stored.price);
        //printf("%s", info_stored.description);

        fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void search(char* filename, char* id) //35 //Module called for search facility
{
        FILE *fptr;
        PRODUCT read_info, info_stored[50];
        int i=0 ,x = -1;

        fptr = fopen(filename,"r");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }

        while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
        {
            if(!strcmp(read_info.id,id))
            {
            	x = i;
			      }
                strcpy(info_stored[i].id, read_info.id);
                strcpy(info_stored[i].name, read_info.name);
                info_stored[i].price = read_info.price;
                strcpy(info_stored[i].color, read_info.color);
                strcpy(info_stored[i].description, read_info.description);
                info_stored[i].quantity= read_info.quantity;
                i++;
          }
		if(x!=-1)
		{
			printf("\t\tProduct details:\n\t\t1. Product ID = %s\n\t\t2. Product Name = %s\n\t\t3. Product Price = %.2f\n\t\t4. Product Color = %s\n\t\t5. Product Description = %s\n\t\t6. Product Quantity = %d\n",
			info_stored[x].id, info_stored[x].name, info_stored[x].price, info_stored[x].color, info_stored[x].description, info_stored[x].quantity );
		}
		else
		{
			printf("\n\t\tInvalid ID!!\n");
		}

        fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void checkout(PRODUCT *info, int len_of_info) //36 confirms checkout and updates the products and vans file
{
	getchar();
	int i = 0, x;
	float tot_price;
  system("clear");
		printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n");
        printf("                                                                                                                  Hi %s!                          \n", global_uname);
        printf("                                                                                                                                                   \n");
        printf("Your chosen time for in-store pickup is: %s", chosen_time);
        printf("\t\t\t >> Your final bill is as displayed:\n\n");
        printf("________________________________________________________________________________________________________\n\n");
        while(i < len_of_info)
        {
          printf("     >> Product [%d]:\n", (i+1));
          printf("           > ID: %s\n", info[i].id);
          printf("           > Name: %s\n", info[i].name); //will discuss
          printf("           > Quantity: %d\n", products[i].quant);
          printf("           > Price for %d: %0.2f\n", products[i].quant, ((info[i].price)*(products[i].quant)));
          printf("_________________________________________________________________________________________________________\n");
          tot_price = tot_price + (info[i].price)*(products[i].quant);
          i++;
        }
        printf("     >> Subtotal: %0.2f\n", tot_price);
        printf("     >> GRAND TOTAL: %0.2f  [Inclusive of 12 percent Tax and all charges.]\n\n\n", (tot_price + 0.12*tot_price));
        printf("________________________________________________________________________________________________________\n\n");
        char final;
        printf("     >> Press 1 to confirm Checkout or any other key to go to home page.\n     >>");
        final = getchar();
        if(final=='1')
        {
          getchar();
          for(x=0;x<diff; x++)
          {
          	updateProduct2("products.txt", purchased[x].id, products[x].quant);
		  }
          //reserve_van(global_van_id);
          thankyou2();
        }
        else
        {
          frontpage();
        }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void checkout2(PRODUCT *info, int len_of_info) //37 confirms checkout and updates the products and vans file
{
	int i = 0, x;
	float tot_price;
  system("clear");
		printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n");
        printf("                                                                                                                                            \n");
        printf(" Hi %s                                                                                                                                                   \n", global_uname);
        printf("\n\t\t>> Input your complete address: ");
        gets(addressx);
        printf("Your chosen time of delivery is: %s\n", chosen_time);
        printf("Your chosen area of delivery is: %s\n", chosen_address);

        printf("\t\t\t >> Your final bill is as displayed:\n\n");
        printf("________________________________________________________________________________________________________\n\n");
        while(i < len_of_info)
        {
          printf("     >> Product [%d]:\n", (i+1));
          printf("           > ID: %s\n", info[i].id);
          printf("           > Name: %s\n", info[i].name); //will discuss
          printf("           > Quantity: %d\n", products[i].quant);
          printf("           > Price for %d: %0.2f\n", products[i].quant, ((info[i].price)*(products[i].quant)));
          printf("_________________________________________________________________________________________________________\n");
          tot_price = tot_price + (info[i].price)*(products[i].quant);
          i++;
        }
        printf("     >> Subtotal: %0.2f\n", tot_price);
        printf("     >> GRAND TOTAL: %0.2f  [Inclusive of 12 percent Tax and all charges.]\n\n\n", (tot_price + 0.12*tot_price));
        printf("________________________________________________________________________________________________________\n\n");
        char final;
        printf("     >> Press 1 to confirm Checkout or any other key to go to home page.\n     >>");
        final = getchar();
        if(final=='1')
        {
          getchar();
          for(x=0;x<diff; x++)
          {
          	updateProduct2("products.txt", purchased[x].id, products[x].quant);
		  }
          reserve_van(global_van_id);
          thankyou1();
        }
        else
        {
          frontpage();
        }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void thankyou1() //38 //Thankyou page
{
        system("clear");
		    printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n\n");
        printf("               >> Thank You for using our services. We are happy to serve you! Hope to see you soon again :D\n\n\n");
        printf("               >> The product(s) will be delivered at %s by tomorrow \n                  during %s.\n\n", addressx, chosen_time);
        printf("    Your smile is most precious :D                                                                                     FIND IT. LOVE IT. BUY IT.\n\n");
        printf(".________________________________________________________________________________________________________________________________________________.\n");
        getchar();
        frontpage();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void updateProduct2(char *filename, char *id, int user_stock) //39 //This module is called to update the product file after checkout confirmation
{
	FILE *fptr;
	PRODUCT read_info, *productss;
	int no_of_rec = 0, x;
	fptr = fopen(filename, "r+");
	//printf("%s %s %d %0.2f", filename, id, new_stock, new_price);
	if(fptr == NULL)
	{
		printf("ERROR, can't open file'");
		exit(1);
	}
	while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
	{
		no_of_rec++; //Counting number of records of type 'PRODUCT' in file.
	}

	productss = (PRODUCT*)malloc(no_of_rec*sizeof(PRODUCT)); //allocating dynamically space for the number of records in the file to be read.
	rewind(fptr); //Going to the beginnig of the file.

	x = 0;
	while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
	{
		strcpy(productss[x].id, read_info.id);
		strcpy(productss[x].name, read_info.name);
		strcpy(productss[x].color, read_info.color);
		strcpy(productss[x].description, read_info.description);
		productss[x].price = read_info.price;
		productss[x].quantity = read_info.quantity;
		if(!strcmp(read_info.id,id))	//Check if this is the record to be updated
		{
			if(user_stock!=-1 && user_stock<= productss[x].quantity) //Updating
			{
				productss[x].quantity = productss[x].quantity - user_stock;
				//printf("Hi");
			}
			else
			{
				printf("\n\t\tProducts requested is more than the stock currently available!! \n\t\tPress Enter to start browsing again: ");
				getchar();
				browse_products();
			}
		}
		x++;
	}

	fclose(fptr);

	//writing afresh in the file with updated data
	fptr = fopen(filename, "w");
	for(x = 0; x<no_of_rec; x++)
	{
		fwrite(&productss[x], sizeof(PRODUCT), 1, fptr);
	}
	fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void read_vans() //40
{
  VAN user;
  FILE *fptr;
  fptr = fopen("vans.txt","r+");
  while(fread(&user, sizeof(VAN), 1, fptr))
  {
    printf("\n id: %s", user.id);
    printf("\n date: %0.2f", user.date);
  }
  fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void unique_id_check(char *id) //41 //During addition of products, it checks whether the product ID is unique or not.
{
	FILE *fptr;
        PRODUCT read_info, info_stored;
        int i=0 ,x = -1;

        fptr = fopen("products.txt","r");
        if(fptr == NULL)
        {
                printf("Error opening the file\n");
                exit(1);
        }


        while(fread(&read_info, sizeof(PRODUCT), 1, fptr))
        {
            if(!strcmp(read_info.id,id))
            {
            	printf("\n\t\tID is already taken, please use a unique ID. \n\t\tPress Return to go to addition page again!!: ");
            	getchar();
            	addition_products();
            }

	   }

        fclose(fptr);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void thankyou2() //42 //Thankyou page 2
{
        system("clear");
		    printf(".________________________________________________________________________________________________________________________________________________.\n");
        printf("                                                                                                                                                  \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("                                                   +             BIGG SALEZ              +                                                        \n");
        printf("                                                   + + + + + + + + + + + + + + + + + + + +                                                        \n");
        printf("         ________________________________________________________________________________________________________________________________         \n\n");
        printf("               >> Thank You for using our services. We are happy to serve you!\n\n\n");
        printf(" Your smile is most precious :D                                                                                   FIND IT. LOVE IT. BUY IT.\n");
        printf(".________________________________________________________________________________________________________________________________________________.\n");
        getchar();
        frontpage();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
        /*//These functions create the files initially!
        load_vans();
        load_admin();
        load_userInfo();
        load_products();*/


        real_date(); //-- ALWAYS ON
        update_vans(); //-- ALWAYS ON
        frontpage(); //-- ALWAYS ON

        //read_vans();  //This is just to confirm if vans are being reserved.
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

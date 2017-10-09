	//Header files used

#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>


class cust                                                        //records maintained through class
   {
     public:
      int id;
      char name[50];
      char doc[500];
      char des[50];
      unsigned int room_no;
      char mob[10];

      public:
      void getdata()                                             //Input function
      {
	 cout<<"\nEnter your details";
	 cout<<"\nEnter patient id no.";
	 cin>>id;
	 cout<<"\nEnter your name";
	 gets(name);
	 cout<<"\nEnter your disease/symptom";
	 cin>>des;
	 cout<<"\nEnter your contact no.";
	 cin.getline(mob,10);
	 cout<<"\nEnter room allotted";
	 cin>>room_no;
   cout<<"\nName of Doctor allotted";
   cin>>doc;
      }
      void putdata()                                            //output function
      {
	 cout<<"\n\nYour details are";
	 cout<<"\nPatient id ";
	 cout<<id;
	 cout<<"\nName ";
	 puts(name);
	 cout<<"\nDoctor assigned ";
	 puts(doc);
	 cout<<"\nDesease ";
	 cout<<des;
	 cout<<"\nContact no. ";
	 cout.write(mob,10);
	 cout<<"\nRoom_no";
	 cout<<room_no;
      }
      int getacc()                                               //to return Patient id.
      {
	 return id;
      }
  //     void wit(int amt)                                          //To withdraw amount
  //     {
	//  room_no=room_no-amt;

  //     }
  //     void dep(int amt)                                          //To deposit amount
  //     {
	//  room_no=room_no+amt;
  //     }
      void new_patient()                                         //Enter new account details
      {
	 cout<<"\nEnter your details";
	 cout<<"\nChoose your Patient id.";
	 cin>>id;
	 cout<<"\nEnter your name";
	 gets(name);
	 cout<<"\nDoctor assigned";
	 gets(doc);
	 cout<<"\nDesease";
	 cin>>des;
	 cout<<"\nEnter your contact no.";
	 cin>>mob;
	 cout<<"\nRoom allotted";
	 cin>>room_no;
      }
      void modify()                                              //Modify account details
     {
	 cout<<"\nEnter your details to be modified";
	 cout<<"\nEnter your name";
	 gets(name);
	 cout<<"\nDoctor allotted";
	 gets(doc);
	 cout<<"\nDesease:";
	 cin>>des;
	 cout<<"\nEnter your contact no.";
	 gets(mob);

     }


   };

void exacc();
void main();

void newacc()                                                     //function for creating new account
 {
	cust s;
	ofstream fo;
	fo.open("cust.dat",ios::binary|ios::app);
	s.new_patient();
	fo.write((char *) &s,sizeof(s));
	fo.close();
	cout<<"\nPatient added successfully";
	getch();
	main();

 }
void accdet(int ac)                                             //function to search Patient by given Patient id no.
 {   cust s;
     int f=0;
     ifstream fi;
     fi.open("cust.dat",ios::binary);
     if(!fi)
     {
	cout<<"File can't be opened. Press any Key to continue";
	return;
     }
     cout<<"\nPatient details\n";
     while(fi.read((char *) &s, sizeof(s)))
     {
	 if(s.getacc()==ac)
	 {
	     s.putdata();
	     f=1;
	 }
     }
     fi.close();
     if(f==0)
	cout<<"\nPatient not found";
 getch();
}
void mod(int n)                                                 //function to modify account details
{

   cust s;
   fstream fio;
   fio.open("cust.dat",ios::binary|ios::in|ios::out);
   if(!fio)
   {
      cout<<"File can't be opened. Press any Key to continue";
      return;
   }
   int f=0;
   while(fio.read((char *) &s, sizeof(s)) && f==0)
   {
	if(s.getacc()==n)
	{
	   s.putdata();
	   cout<<"\nEnter modified details\n";
	   s.modify();
	   int pos=(-1)*sizeof(s);
	   fio.seekp(pos,ios::cur);
	   fio.write((char *) &s, sizeof(s));
	   cout<<"\n\nPatient Details modified";
	   f=1;
	}
   }
   fio.close();
   if(f==0)
      cout<<"\n Record Not Found ";
getch();
}
void del(int n)                                                     //function to delete account
{
   ifstream fi;
   fi.open("cust.dat",ios::binary);
   cust s;
   if(!fi)
   {
      cout<<"File can't be opened. Press any Key to continue";
      return;
   }
   ofstream fo;
   fo.open("temp.dat",ios::binary);
   fi.seekg(0,ios::beg);
   while(fi.read((char *) &s, sizeof(s)))
   {
      if(s.getacc()!=n)
      {
	  fo.write((char *) &s, sizeof(s));
      }
   }
   fi.close();
   fo.close();
   remove("cust.dat");
   rename("temp.dat","cust.dat");
   cout<<"\nPatient has been discharged";
getch();
}

// void withdraw(int n)                                                //function to withdraw amount
// {
//    int amt,f=0;
//    cust s;
//    fstream fio;
//    fio.open("cust.dat", ios::binary|ios::in|ios::out);
//    if(!fio)
//    {
// 	cout<<"File cant be opened. Press any key to contine.";
// 	return;
//    }
//    while(fio.read((char *) &s, sizeof(s)) && f==0)
//    {
//      if(s.getacc()==n)
//      {
// 	 s.putdata();
// 	 cout<<"\n\nEnter The amount to be withdrawn";
// 	 cin>>amt;
// 	 s.wit(amt);

//        int pos=(-1)* sizeof(s);
//        fio.seekp(pos,ios::cur);
//        fio.write((char *) &s, sizeof(s));
//        cout<<"\nRecord updated";
//        f=1;
//        cout<<"\nMoney withdrawn";

//      }
//    }
//    fio.close();
//    if(f==0)
//    cout<<"\nRecord Not Found ";
// getch();
// exacc();
// }

// void deposit(int n)                                                  //function to deposit amount
// {
//    int amt,f=0;
//    cust s;
//    fstream fio;
//    fio.open("cust.dat", ios::binary|ios::in|ios::out);
//    if(!fio)
//    {
//        cout<<"File cant be opened. Press any key to contine.";
//        return;
//    }
//    while(fio.read((char *) &s, sizeof(s)) && f==0)
//    {
//      if(s.getacc()==n)
//      {
// 	 s.putdata();
// 	 cout<<"\nEnter The amount to be deposited";
// 	 cin>>amt;
// 	 s.dep(amt);
// 	 int pos=(-1)* sizeof(s);
// 	 fio.seekp(pos,ios::cur);
// 	 fio.write((char *) &s, sizeof(s));
// 	 cout<<"\nMoney deposited";
// 	 f=1;
//      }
//    }
//    fio.close();
//    if(f==0)
//    cout<<"\nRecord Not Found ";
// getch();
// exacc();
// }
void disp()                                                 //function to show all account holders(pass=1111)
{
   cust s;
   ifstream fi;
   fi.open("cust.dat",ios::binary);
   cout<<"\n\nPatients presently in STAR CITY HOSPITAL\n\n";
   while(fi.read((char *) &s, sizeof(s)))
   {
      s.putdata();
   }
   fi.close();
 getch();
 exacc();
}


void exacc()                                               //function to perform operations on existing accounts
 {
   int ch;
   int n;
   int p;
   cout<<"\nStar City Hospital welcomes you";
   do
   {
   clrscr();
   cout<<"\nWhat do you want to do?";
   cout<<"\n1.Patient details";
   cout<<"\n2.Modify patient details\n3.Discharge Patient\n4.Patient's list\n5.Exit";
   cin>>ch;
   switch(ch)
       {
	case 1: cout<<"\nEnter The Patient id No.";
		cin>>n;
		accdet(n);
		break;
	case 2: cout<<"\nEnter The Patient id No.";
		cin>>n;
		mod(n);
		break;
	case 3: cout<<"\nEnter The Patient id No.";
		cin>>n;
		del(n);
		break;
	case 4: cout<<"\nYou are about to see the list of all the account holders";
		cout<<"\nEnter the security password";
		cin>>p;
		if(p==1111)
		disp();
		else
		cout<<"\nWrong password.\nAccess denied";
    getch();
		break;
	case 5: cout<<"\nTHANKS FOR CHOOSING OUR HOSPITAL\n";
		getch();
		exit(0);
		break;
	default :cout<<"\nInvalid Input";
	}
   }
   while(ch!=5);
 }
//Start of main function


void main()
{
    clrscr();
    int choice;
    cout<<"\nWelcome to Star City Hospital";
    cout<<"\nChoose what do you want to do";
    cout<<"\n1.Admit New Patient \n2.Existing patient operations\n3.Exit";
    cin>>choice;
    switch(choice)
    {
       case 1:cout<<"\nThank you for choosing our hospital";
	      newacc();
	      break;
       case 2:cout<<"\nWelcome";
	      exacc();
	      break;
       case 3:exit(0);
	      break;
       default:cout<<"\nwrong input";
    }

   getch();


}



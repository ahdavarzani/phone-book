/*40111360017
amirhossein davarzani
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "struct.cpp"
using namespace std;

int main() 
{
	cout<<"welcome to the phone book of mr Kyomars!\n\n";
	class_string obj;
	
	while(true)
	{
    	cout<<":::::::::::program menu:::::::::::\n"
		<<"1.save contact\n"
		<<"2.show all contact\n"
		<<"3.search contact\n"
		<<"4.update contact\n"  
		<<"5.delete a contact\n"
		<<"6.delete all contacts\n"
		<<"7.exit from program\n\n";

		cout<<"enter your choice:\n";
		char choice;
		cin>>choice;
		
		switch(choice)
		{
			case '1':	
			{
				ofstream save("testp.txt",ios::app);
				cout<<"please enter number:\n";
				cin>>obj.number;
				save<<obj.number<<"\n";	
				cout<<"please enter first name:\n";
				cin>>obj.name;
				save<<obj.name<<"\n";
				cout<<"please enter last name:\n";
				cin>>obj.family;
				save<<obj.family<<"\n";	
				cout<<"please enter email:\n";
				cin>>obj.email;
				save<<obj.email<<"\n";	
				cout<<"please enter address:\n";
				cin>>obj.address;
				save<<obj.address<<"\n";			
				save.close();	
				cout<<"a contact has been saved successfully!\n\n";
				break;
			}
			
			case '2':
			{	
				ifstream show("testp.txt");
				if(show.peek()==ifstream::traits_type::eof())
				{
					cout<<"there is no contact!\n\n";					
					break;
				}
				else
				{
					cout<<"contacts:\n";
					char number_array[100][12];
					char name_array[100][30];
					char family_array[100][30];
					char email_array[100][30];
					char address_array[100][30];
					int i=0;
					show>>number_array[i];
					while(!show.eof())
					{
						show>>name_array[i]; 
						show>>family_array[i]; 
						show>>email_array[i];
						show>>address_array[i];
						{
							i++;
							show>>number_array[i];
						}
					}
					show.close();
					
					for(int j=0;j<i;j++)
					{
					cout<<"number "<<j+1<<":"<<number_array[j]<<"\n";
					cout<<"name "<<j+1<<":"<<name_array[j]<<" "<<family_array[j]<<"\n";
					cout<<"email "<<j+1<<":"<<email_array[j]<<"\n";
					cout<<"address "<<j+1<<":"<<address_array[j]<<"\n";
					cout<<"<<<<<>>>>>\n";
					}
					cout<<"end of the show!\n\n";	
					break;
				}
			}
			
			case '3':
			{
				ifstream search("testp.txt");
				bool found=false;
				cout<<"please enter your first name for findind it's data:\n";
				cin>>obj.search_name;
				cout<<"\n";
				while (search>>obj.number,search>>obj.name,search>>obj.family,search>>obj.email,search>>obj.address)
				{ 
					if(obj.search_name==obj.name)
					{ 
						cout<<obj.name<<" "<<obj.family<<":"<<" "<<obj.number<<", "<<obj.email<<", "<<obj.address<<"\n\n";
						found=true;
					}
				}
				if(!found)
				{
					cout<<"the entered name does not exist in the phone book\n\n";
				}
				break;	
			}
			
			case '4':
			{
				ifstream read("testp.txt");
				ofstream write("testup.txt");
				string name_f_u; //name for update
				bool found=false;
				cout<<"please enter the first name to update the contact:\n";
				cin>>name_f_u;
				cout<<"\n";
				while(read>>obj.number,read>>obj.name,read>>obj.family,read>>obj.email,read>>obj.address)
				{ 
					if(name_f_u==obj.name)
					{
						cout<<"Do you really want to do this?(y/n)\n";
						cin>>obj.confirmation;
						if(obj.confirmation=="y" or obj.confirmation=="Y")
						{
							cout<<"please enter new number:\n";
							cin>>obj.new_number;
							cout<<"please enter new email:\n";
							cin>>obj.new_email;
							cout<<"please enter new address:\n";
							cin>>obj.new_address;
							write<<obj.new_number<<" "<<obj.name<<" "<<obj.family<<" "<<obj.new_email<<" "<<obj.new_address<<"\n";
							cout<<"the contact has been successfully updated"<<"\n\n";
							found=true;
						}
						else
						{
							goto exit1;
						}
					}
					else
       				{
          				write<<obj.number<<" "<<obj.name<<" "<<obj.family<<" "<<obj.email<<" "<<obj.address<<"\n";
       				}
				}	
					
				read.close();
    			write.close();
    			remove("testp.txt");
   				rename("testup.txt","testp.txt");
			
				if(!found)
				{
					cout<<"the entered name does not exist in the phone book\n\n";
				}
				exit1:break;			
			}

			case '5':
			{
				ifstream read("testp.txt");
				ofstream write("testdp.txt");
				string name_f_d; //name for delete
				bool found=false;
				cout<<"please enter the first name to delete the contact:\n";
				cin>>name_f_d;
				cout<<"\n";
				while(read>>obj.new_number,read>>obj.name,read>>obj.family,read>>obj.email,read>>obj.address)
				{ 
					if(name_f_d==obj.name)
					{
						cout<<"Do you really want to do this?(y/n)\n";
						cin>>obj.confirmation;
						if(obj.confirmation=="y" or obj.confirmation=="Y")
						{
							cout<<"the contact has been successfully deleted"<<"\n\n";
							found=true;
							continue;
						}
						else
						{
							goto exit2;
						}
					}
					else
       				{
          				write<<obj.number<<" "<<obj.name<<" "<<obj.family<<" "<<obj.email<<" "<<obj.address<<"\n";
       				}
				}	
					
				read.close();
    			write.close();
    			remove("testp.txt");
   				rename("testdp.txt","testp.txt");
			
				if(!found)
				{
					cout<<"the entered name does not exist in the phone book\n\n";
				}
				exit2:break;			
			}

			case '6':
			{
				cout<<"Do you really want to do this?(y/n)\n";
				cin>>obj.confirmation;
				if(obj.confirmation=="y" or obj.confirmation=="Y")
				{
					ofstream delete_all("testp.txt");
					delete_all.close();
					cout<<"all existing contacts have been deleted!\n\n";				
				}
				else
				{
					goto exit3;
				}	
				exit3:break;
			}
			
			case '7':	
			{
				cout<<"the creator of this program is amir hossein davarzni \nI hope you enjoyed it ;-)\n";
				cout<<"have a nice day !";
				exit(0);
			}

			default:
			{
				cout<<"please enter correct number!\n";
				continue;
			}
		}
	}
}

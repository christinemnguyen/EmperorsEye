//
//  main.cpp
//  CMPE130Proj
//
//  Created by Christine Nguyen, Carmen Yoc, and West Steinacker on 11/27/19.
//

// reference: https://www.go4expert.com/articles/phonebook-sample-cpp-using-objects-t30212/

#include <iostream>
#include <string>
using namespace std;


// function call
bool name_valid(string);
bool adrs_valid(string);

// contact class
class contact {
    string name;
    string num_street;
    string name_street;
    string city;
    string zip;
        
    public:
        // initializes blank contact values
        contact(): name(""), num_street(""), name_street(""), city(""), zip(""){}
        
        // FUNCTION: Shows all the contacts
        bool show() {
            if(name != "") {
                cout << name << "\t\t\t" << num_street << "\t\t\t" << name_street << "\t\t\t" << city << "\t\t\t" << zip << endl;
                return 1; // SUCCESS!
            }
            else
                return 0; // FAILURE!
        }
        
        
        // FUNCTION: To validate if a name exists
        bool name_exists(string tname) {
            if(tname == name)
                return 1;
            else
                return 0;
        }
        
        // validates values
        bool add(string new_name, string new_num_street, string new_name_street, string new_city, string new_zip) {
            if(name=="") {
                name = new_name;
                num_street = new_num_street;
                name_street = new_name_street;
                city = new_city;
                zip = new_zip;
                
                return 1; // Success
            }
            else
                return 0; // Failure
    
        }
        
        // calls function to edit string
        bool edit(string);
        
        // FUNCTION: To delete/erase the string
        bool erase(string new_name) {
            if(new_name==name) {
                name = "";
                num_street = "";
                name_street = "";
                city = "";
                zip = "";
                return 1;
            }
            else
                return 0;
        }
};


// FUNCTION to edit contacts
bool contact :: edit(string new_name) {
    string new_num_street, new_name_street, new_city, new_zip;
    
    if(new_name==name) {
        cout << "Enter new name: "; cin >> new_name;
        cout << "Enter new street number: "; cin >> new_num_street;
        cout << "Enter new street name: "; cin >> new_name_street;
        cout << "Enter new city: "; cin >> new_city;
        cout << "Enter new zip: "; cin >> new_zip;
        
        name = new_name;
        num_street = new_num_street;
        name_street = new_name_street;
        city = new_city;
        zip = new_zip;
        
        return 1;
    }
    else
        return 0;
}



int main() {
    contact person[100];
    
    // Default Contacts
    for(int z=0; z<100; z++)
    if(person[z].add("John", "12345", "Wow_Way", "San_Jose", "95116")) {
        break;
    }
    for(int z=0; z<100; z++)
    if(person[z].add("Martha", "54321", "Hello_Way", "Campbell", "95008")) {
        break;
    }
            
    string temp_name, temp_num_street, temp_name_street, temp_city, temp_zip;
    int choice, i, counter;
    bool flag;
    bool cancel_flag;
    
    cout << "----- ADDRESS BOOK -----" << endl;
    
    
    do {
        cout << endl << "0. Show contacts" << endl
        << "1. Add Contact" << endl
        << "2. Delete Contact" << endl
        << "3. Quit" << endl << endl
        << "Your choice: ";
        cin >> choice;
        
        cancel_flag = 0;
        flag = 0;
        counter = 0;
        
        switch(choice) {
            case 0:
                cout << endl << "Showing Contacts" << endl;
                
                for(i=0; i<100; i++)
                    if(person[i].show())
                        flag = 1;
                
                if(!flag)
                    cout << endl << "No contacts found!" << endl;
                break;
                
            case 1:
                cout << endl << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
                counter = 0;
                
                // loops to fill in all contact information for contact
                do {
                    flag = 0;
                    if(counter)
                        cout << endl << "Try again\t\t\t\tpress $ to cancel"
                        << endl;
                        
                    // counter dor do-while
                    counter++;
                        
                    cout << "Name: "; cin >> temp_name;
                    
                    //Cancel operation
                    if(temp_name=="$") {
                        cancel_flag = 1;
                        break;
                    }
                    
                    cout << "Street number: "; cin >> temp_num_street;
                    
                    //Cancel operation
                    if(temp_num_street=="$") {
                        cancel_flag = 1;
                        break;
                    }
                    
                    cout << "Street name: "; cin >> temp_name_street;
                    
                    //Cancel operation
                    if(temp_name_street=="$") {
                        cancel_flag = 1;
                        break;
                    }
                    
                    cout << "City: "; cin >> temp_city;
                    
                    //Cancel operation
                    if(temp_city=="$") {
                        cancel_flag = 1;
                        break;
                    }
                    
                    cout << "Zip: "; cin >> temp_zip;
                    
                    //Cancel operation
                    if(temp_zip=="$") {
                        cancel_flag = 1;
                        break;
                    }
                    
                    //Check whether name exists
                    for(i=0; i<100; i++)
                        if(person[i].name_exists(temp_name)) {
                            cout << "The name you entered is already there in the address book, enter a different name." << endl;
                            flag = 1;
                            break;
                        }
                    
                }while(!name_valid(temp_name) || flag || !adrs_valid(temp_num_street));
                
                if(cancel_flag) {
                    break;
                }
            
                
                //This code adds the contact to phonebook
                for(i=0; i<100; i++)
                    if(person[i].add(temp_name, temp_num_street, temp_name_street, temp_city, temp_zip)) {
                        cout << "Contact added successfully!" << endl;
                        flag = 1;
                        break;
                    }
                
                if(!flag)
                    cout << "Memory full! Delete some contacts first."
                    << endl;
                break;
                
                
            case 2:
                do
                {
                    if(counter)
                        cout << "Try again" << endl;
                    counter++;
                    cout << "Detele Existing Contact\t\t\tpress $ to cancel\n" << "Name to delete: ";
                    cin >> temp_name;
                
                    //Cancel Operation
                    if(temp_name=="$") {
                        break;
                    }
                
                
                    //Final Confirmation
                    for(i=0; i<100; i++)
                    if(person[i].name_exists(temp_name)) {
                        flag = 1;
                        cout << "Are you sure you want to delete? (1/0)" << endl;
                        int yes;
                        cin >> yes;
                        if(!yes) {
                            cancel_flag = 1;
                        }
                        break;
                    }
                
                    if(!flag)
                        cout << "Contact name not found!" << endl;
                    
                    if(cancel_flag)
                        break;
                
                    // code to delete contact
                    if(flag) {
                        for(i=0; i<100; i++)
                            if(person[i].erase(temp_name)) {
                                cout << "Deleted successfully!" << endl;
                                break;
                            }
                    }
                    
                }while(!flag);
                break;
                
            case 3:
                return 0;
                break;
            
        }
    } while(1);
    
   // getch();
    return 0;
}


// FUNCTION: contact name validator
bool name_valid(string tname) {
    if(tname.size()>20) {
        cout << "Error: Enter a name within 20 characters!"
        << endl;
        return 0;
    }
    else if(tname == "") {
        cout << "Error: Name cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

// FUNCTION: street number validator
bool adrs_valid(string tadrs) {
    if(tadrs.size()>6 || tadrs.size()<3) {
        cout << "Error: Enter a valid number between 3 and 6 digits!" << endl;
        return 0;
    }
    else if(tadrs == "") {
        cout << "Error: street number cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

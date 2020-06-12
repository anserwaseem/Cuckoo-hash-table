#include "cuckoo.cpp"


void cases(char n, cuckoo* &cucko)
{
    string key;
    int nn=n;
    nn-=48;//subtract ascii value

    switch(nn)
    {
        case 1:
        {
            string number_of_elements;
            cout<<"How much elements do you want to insert?\n";

            do{
                try { cin>>number_of_elements; }
                catch(...) { cout<<"unhandled exception";   break; }
                
                cout<<"\t your choice: "<<number_of_elements<<endl;

                size_t point = number_of_elements.find('.');

                //check if user entered 'char' or 'string' or 'float'
                if(number_of_elements.at(0)<48 || point!=string::npos ||number_of_elements.size()>1)
                    cout<<"Please enter a valid input.\n";  
                else
                    break;

            }while(1);

            while(number_of_elements.at(0)>48)//number_of_elements > 0
            {
                cout<<"Enter key.\n";

                do{
                try { cin>>key; }
                catch(...) { cout<<"unhandled exception";   break; }

                size_t point = key.find('.');

                //check if user entered 'char' or 'string' or 'float'
                if(key.at(0)<48 || point!=string::npos)
                    cout<<"Please enter a valid input.\n";  
                else
                    break;

                }while(1);

                cucko->insert(stoi(key));
                --number_of_elements.at(0);
            }
            break;
        }
        case 2:
        {
            cout<<"Which element do you want to search.\n";
            do{
                try { cin>>key; }
                catch(...) { cout<<"unhandled exception";   break; }
                
                cout<<"\t your choice: "<<key<<endl;

                size_t point = key.find('.');

                //check if user entered 'char' or 'string' or 'float'
                if(key.at(0)<48 || point!=string::npos)
                    cout<<"Please enter a valid input.\n";  
                else
                    break;

            }while(1);

            if( cucko->search(stoi(key)) )
                cout<<key<<" found\n";
            else
                cout<<key<<" not found\n";

            break;
        }
        case 3:
        {
            string number_of_elements;
            cout<<"How much elements do you want to delete?\n";

            do{
                try { cin>>number_of_elements; }
                catch(...) { cout<<"unhandled exception";   break; }
                
                cout<<"\t your choice: "<<number_of_elements<<endl;

                size_t point = number_of_elements.find('.');

                //check if user entered 'char' or 'string' or 'float'
                if(number_of_elements.at(0)<48 || point!=string::npos)
                    cout<<"Please enter a valid input.\n";  
                else
                    break;

            }while(1);

            while(number_of_elements.at(0)>48)//number_of_elements > 0
            {
                cout<<"Enter key.\n";

                do{
                try { cin>>key; }
                catch(...) { cout<<"unhandled exception";   break; }

                size_t point = key.find('.');

                //check if user entered 'char' or 'string' or 'float'
                if(key.at(0)<48 || point!=string::npos)
                    cout<<"Please enter a valid input.\n";  
                else
                    break;

                }while(1);

                cucko->Delete(stoi(key));
                --number_of_elements.at(0);
            }
            break;
        }
        case 4:
        {
            cout<<"Total capacity = "<<cucko->capacity()<<endl;
            break;
        }
        case 5:
        {
            cout<<"Load Factor = "<<cucko->loadFactor()<<endl;
            break;
        }
        case 6:
        {
            cucko->print();
            break;
        }
        case 7:
        {
            cout<<"Filled Capacity = "<<cucko->getSize()<<endl;
            break;
        }
        default:
        {
            cout<<"No scuch choice exists.\n";
            break;
        }
    }
}

char printChoices(cuckoo* &cucko)
{
    string Choice;
    
    cout<<"Please press one of the given choices:\n";
    cout<<"1 : Insert\n";
    cout<<"2 : Search\n";
    cout<<"3 : Delete\n";
    cout<<"4 : Total Capacity\n";
    cout<<"5 : Load Factor\n";
    cout<<"6 : Print\n";
    cout<<"7 : Filled Capacity\n";

    do{
    
    try { cin>>Choice; }
    catch(...) { cout<<"unhandled exception";   return -1; }

    cout<<"\t your choice: "<<Choice<<endl;

    size_t point = Choice.find('.');

    //check if user entered 'char' or 'string' or 'float'
    if(Choice.at(0)<48 || Choice.at(0)>57 || point!=string::npos)
        cout<<"Please enter a valid input.\n";

    //check if user entered integer in range 1-7
    else if(Choice.at(0)<=48 || Choice.at(0)>56 || Choice.size()>1)
        cout<<"Please enter within given choices.\n";

    else
        break;
    
    }while(1);

    //now it's time to deal with respective cases
    cases(Choice.at(0), cucko);

    do{
    cout<<"Press 8 to continue\n";
    cout<<"Press 9 to exit\n";

    try { cin>>Choice; }
    catch(...) { cout<<"unhandled exception";   return -1; }
    
    cout<<"\t your choice: "<<Choice<<endl;

    //if user entered anything other than 8 or 9, show error message and take input agian
    if( Choice.at(0)<56 || Choice.at(0)>57 || Choice.size()>1)
        cout<<"Please enter within given choices.\n";  
    else
        break;

    }while(1);

    return Choice.at(0);
}

int main()
{
    char choice = 0;
    cuckoo* cucko = new cuckoo;

    cout<<"Welcome\n\n";

    do{
        choice = printChoices(cucko);

        if(choice==-1)
            break;
    }while(choice != 57);

    cout<<"End of program\n";

    return 0;
}
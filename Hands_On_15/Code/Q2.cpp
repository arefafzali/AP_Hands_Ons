#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool is_email_valid(const std::string& email)
{
   // define a regular expression
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

   return std::regex_match(email, pattern);
}


int main()
{
    string input;
    cin >> input;
    
    //TODO: Write a regex to check input is email or not

    bool inputIsEmail = false;
    inputIsEmail = is_email_valid(input);
    //TODO: Set input is Email

    if(inputIsEmail)
        cout << "Matched" << endl;
    else
        cout << "Not Matched" << endl;
    return 0;
}

/*
file has the format:

    79624470224;m1;300;
    79829388180;m2;700;
    79624470224;m1;200;
....
Number of various m is unlimited

output file has the format:
    key;m1;m2;...
    79624470224;500;0;...
    79829388180;0;700;...
*/

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* atof */
#include <set>
#include <map>

using std::string;
using std::stringstream;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::set;
using std::map;
using std::cout;

int main(int args, char** argv)
{
   ifstream userInput(argv[1]);
   set<string> merchantSet;
   map<string,map<string,double>* > phoneToMerchantAmount;

  while (userInput.good())
    {
      string userFileLine;
      getline(userInput, userFileLine);
      stringstream lineStream(userFileLine);
      string phone, merchant, amount;
      getline(lineStream,phone,';');
      if (phone=="") continue;
      getline(lineStream,merchant,';');
      merchantSet.insert(merchant);

      getline(lineStream,amount,';');

      double a = atof(amount.c_str());

      map<string,map<string,double>* >::iterator i = phoneToMerchantAmount.find(phone);
      map<string,double>* m;
      if (i==phoneToMerchantAmount.end())
	{  m = new map<string,double>(); phoneToMerchantAmount[phone] = m;  } else 	{ m = i->second;}
      (*m)[merchant] += a;

    }

  userInput.close();
  ofstream out(argv[2]);
  out << "key;";
for (set<string>::iterator j = merchantSet.begin(); j!=merchantSet.end(); ++j)
  {
    out << *j << ";";
  }
out << "\n";

  for (map<string,map<string,double>* >::iterator i = phoneToMerchantAmount.begin(); i!=phoneToMerchantAmount.end(); ++i)
    {
      out << i->first << ";" ;
      for (set<string>::iterator j = merchantSet.begin(); j!=merchantSet.end(); ++j)
	{

	  if (i->second->find(*j)!= i->second->end())
	    {
	      out <<  (*(i->second))[*j] <<";";
	    }
	  else
	    {
	      out << 0 << ";";
	    }
	}
      out << "\n";
    }
  out.close();
}

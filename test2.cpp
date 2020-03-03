#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"

using namespace std;

int main() {
 cout << "Running tests from: " << __FILE__ << endl;
 WordCount sr; 
//  std::ostream &out;
 // std::ostringstream foo;
 //  foo.str("Apple,1\n Bob,1\n") ;
//  sr.addAllWords("Apple Bob");
 sr.addAllWords("A A A A C c c c B B B B\n i L L\nSam sam Rich Rich Ball ball\nRaj Sai Kathika Chand Bob Baa Bcc Bcc");
  //sr.addAllWords("Sam sam Rich Rich Ball ball\n Raj Sai Kathika Chand Bob Baa Bcc Bcc");
// ASSERT_EQUALS(foo.str(), sr.dumpWordsSortedByWord(std::cout));
  sr.dumpWordsSortedByWord(std::cout);
  cout << endl;
  sr.dumpWordsSortedByOccurence(std::cout);
}
#include "flatconfig.hpp"

#include <cassert>
#include <iostream>
using namespace std;

int main()
{
  farfetchd::ConfigReader config;
  assert(config.parseFile("test.cfg"));

  cout << "nospace is: " << config.getInt("nospace").value() << endl;
  cout << "nospace_str is: " << config.getString("nospace_str").value() << endl;
  cout << "space is: " << config.getFloat("space").value() << endl;
  cout << "space_str is: " << config.getString("space_str").value() << endl;
  cout << "bigspace is: " << config.getDouble("bigspace").value() << endl;
  cout << "bigspace_str is: " << config.getString("bigspace_str").value() << endl;

  cout << "nonexistentkey is: " << config.getString("nonexistentkey").value_or("[nullopt]") << endl;

  cout << "By the way, *trailing* spaces are not stripped. Here is the value of "
          "bigspace_str, surrounded by quotes:'"<<config.getString("bigspace_str").value()<<"'"<<endl;

  cout << "after_some_blank_lines is: " << config.getString("after_some_blank_lines").value() << endl;
  cout << "after_a_comment is: " << config.getString("after_a_comment").value() << endl;
  cout << "inline_comment is: " << config.getString("inline_comment").value() << endl;
  cout << "numeric_inline_comment is: " << config.getDouble("numeric_inline_comment").value() << endl;

  farfetchd::ConfigReader config2;
  config2.parseStringBlob("hello: goodbye\na_number:2");
  cout << "from blob: " << config2.getString("hello").value() << "," << config2.getInt("a_number").value() << endl;
}

#include "Password.h"
#include <string>

using namespace std;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  if(phrase.size() == 0){
    return 0;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool has_lower = false;
  bool has_upper = false;

  for (char ch : pass){
    if(islower(ch)){
      has_lower = true;
    }
    else if(isupper(ch)){
      has_upper = true;
    }
  }
  return has_lower && has_upper;
}

bool Password::is_too_long(string pass){
  int MAX_SIZE = 10;
  return pass.size() >= MAX_SIZE;
}

bool Password::is_too_short(string pass){
  int MIN_SIZE = 5;
  return pass.size() < MIN_SIZE;
}

bool Password::is_alpha_num(string pass){
  bool has_num = false;
  bool has_alpha = false;

  for(char ch : pass){
    if(isdigit(ch)){
      has_num = true;
    }
    else if(isalpha(ch)){
      has_alpha = true;
    }
  }
  return has_num && has_alpha;
}
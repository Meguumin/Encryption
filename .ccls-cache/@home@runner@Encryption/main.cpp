#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
//Encrypt works but decrypt doesnt
void XorEN(std::ofstream &MyFile, char *key, std::string x) {
      int t = strlen(key);
      int b = 0;
       for (int i = 0; i < x.size(); ++i)
        {
        x[i] = x[i] ^ key[b];
        MyFile << x[i];
          //std::cout<<key[b];
          b++;
          if(b >= t)
          {
            b = 0;
          }
        }    
}

void encrypt(char *xorKey, std::string x) {
  std::ofstream MyFile;
  std::ifstream read("target.txt");
  MyFile.open("Encrypted.txt");
  const char *c = x.c_str();
  x.assign( (std::istreambuf_iterator<char>(read) ),
  (std::istreambuf_iterator<char>()    ) );
    // std::cout << x << "\n";
       XorEN(MyFile, xorKey, x);
  // std::puts(c);
  // std:: cout << std::endl;
    printf("Encrypted!");
  MyFile.close();
}

void decrypt(char *key, std::string x) {
  std::ifstream geten("Encrypted.txt");
   x.assign( (std::istreambuf_iterator<char>(geten) ),
  (std::istreambuf_iterator<char>()    ) );
   //std::cout << x << "\n";
  std::ofstream MyFile;
  MyFile.open("Decrypted.txt");
  XorEN(MyFile, key, x);
  printf("Decrypted!");
  MyFile.close();
}

int main() {
  char xorKey[] = "Secure Key";
  std::string Input;
  std::string Output;
  std::string keypath;
  std::string tmp;
  std::string targetfile;
  int userinput;
  printf("Type in Key(1) or Load from Text File?(2)\n");
  scanf("%d", &userinput);
  clear();
  if(userinput == 1)
  {
     printf("Enter Key:\n");
     fgets(xorKey, 1000, stdin);
     clear();
  }
  else if(userinput == 2)
  {
    printf("Enter Keypath:\n");
    std::cin >> keypath;
    std::ifstream getkey(keypath); 
    tmp.assign( (std::istreambuf_iterator<char>(getkey) ),
  (std::istreambuf_iterator<char>()    ) );
    strcpy(xorKey, tmp.c_str());
    clear();
  }
  //printf("%s\n", xorKey);
  printf("Encrypt(1) or Decrypt(2)?\n");
  scanf("%d", &userinput);
  clear();
  switch(userinput) {
  case 1:
    encrypt(xorKey, Input);
    break;
  case 2:
    decrypt(xorKey, Output);
    break;
}      
}
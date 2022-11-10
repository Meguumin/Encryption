#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>

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
  getline(read, x);
  // std::puts(c);
  XorEN(MyFile, xorKey, x);
  // std:: cout << std::endl;
    printf("Encrypted!");
  MyFile.close();
}

void decrypt(char *key, std::string x) {
  std::ifstream geten("Encrypted.txt");
  getline(geten, x);
  std::ofstream MyFile;
  MyFile.open("Decrypted.txt");
  XorEN(MyFile, key, x);
  printf("Decrypted!");
  MyFile.close();
}
int main() {
  char xorKey[] = "Ching chong chinaman";
  std::string Input;
  std::string Output;
  int userinput;

  printf("Encrypt(1) or Decrypt(2)?\n");
  scanf("%d", &userinput);
  switch(userinput) {
  case 1:
    encrypt(xorKey, Input);
    break;
  case 2:
    decrypt(xorKey, Output);
    break;
}      
}
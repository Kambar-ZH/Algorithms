#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int BMSearch(char *string, char *substring){
  int  sl = 0; // string length
  int ssl = 0; // substring length
  int res = -1; // result
  while (string[sl] != NULL) {
  		sl++;
  }
  printf("Sl = %d\n", sl);
  while (substring[ssl] != NULL) {
  		ssl++;
  }
  if (sl == 0) 
    printf("Incorrect string\n");
  else if (ssl == 0) 
    printf("Incorrect substring\n"); 
  else {
    int  i, Pos; // iterator, position
    int  BMT[256];
    for (i = 0; i < 256; i ++)
      BMT[i] = ssl; // Fill with substring size
    printf("BMT = %d\n", BMT[0]);
    for (i = ssl-1; i >= 0; i--) // going throw substring length on backward
      if (BMT[(short)(substring[i])] == ssl) // 
        BMT[(short)(substring[i])] = ssl - i - 1; // 
    Pos = ssl - 1; // 3
    while (Pos < sl)
      if (substring[ssl - 1] != string[Pos])
        Pos = Pos + BMT[(short)(string[Pos])]; // displace for the closest letter
      else 
        for (i = ssl - 2; i >= 0; i--){ // 2, 1, 0 looking for the rest of letters
          if (substring[i] != string[Pos - ssl + i + 1]) { // if sstr[2] != str[position for the last letter of word minus the length of word + 1 + the looking letter]
            Pos += BMT[(short)(string[Pos - ssl + i + 1])] - 1; // then we add for the position the letter 
            break;
          }
          else
            if (i == 0) // else if we get to the last itterattion, that means that it is the first letter of our word
              return Pos - ssl + 1; // then we return the position minus length + 1
        }
  }
  printf("\n");
  return res;
}

int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "Rus");
	char str[30];
	char substr[30];
	printf("Input string: ");
	scanf("%s", str);
	printf("Input substring: ");
	scanf("%s", substr);
	
	int pos = BMSearch(str, substr);
	printf("Displacement = %d", pos);
		
	return 0;
}



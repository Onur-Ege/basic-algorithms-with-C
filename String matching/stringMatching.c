#include <stdio.h>
#include <string.h>


int stringMatching(char str[], char pattern[] ,int lengthOfPattern,int lengthOfStr){
	int i;
	
	for(i=0;i<lengthOfStr-lengthOfPattern;i++){
		int j=0;
		
		while(j<lengthOfPattern & pattern[j] == str[i+j]){					// if charecter in pattern match with character in string
			j += 1;															// control next character in both pattern and string
		}																	// if match control until the last character in the pattern
		if(j == lengthOfPattern){											// if doesnt match assign zero to j and continue to control
			return i;
		}
	}
	return 0;
}
int main(){
	char str[] = "federico_fellini";
	char pattern[3];
	
	printf("please enter the pattern that want to search:\n");
	scanf("%s",&pattern[0]); 
	
	int lengthOfPattern = strlen(pattern);									//lengths of pattern and string
	int lengthOfStr = strlen(str);
	
	int index;
	index = stringMatching(str, pattern, lengthOfPattern, lengthOfStr);		//begining index of pattern in str

	if (index){
		printf("beggining index of pattern in str: %d\n",index);
	}else{
		printf("pattern cannot found!\n");
	}
}

#include<iostream>

// Question no 01
int sum(int n){	
	if(n > 0)
		return n + sum(n - 1);
	else
		return 0;
}

// Question no 02
int sumdigits(int n){	
	if(n > 0)
		return (n % 10) + sumdigits(n / 10);
	else
		return 0;
}

// Question no 03
bool ispalindrome(const std::string& check, int left, int right){
	if(left >= right)
		return true;
	if(check[left] != check[right])
		return false;
	ispalindrome(check, left + 1, right - 1);
}

// Question no 04





int main(){
	
	std::cout << "Sum: "<< sum(5) << std::endl;
	std::cout << "\n";
	
	std::cout << "Digits Sum: " << sumdigits(5436) << std::endl;
	std::cout << "\n";
	
	std::string n = "PappaP";
	std::cout << "String Comparison: " << ispalindrome(n, 0, n.length()-1) << std::endl;
	std::cout << "\n";
	
	
	
}

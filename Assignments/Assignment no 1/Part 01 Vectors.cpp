#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<cstdlib>
#include<ctime>


// ==================================== PART 1 =======================================
int main(){
	
    std::vector<int> A, B, C;
    std::vector<int> E, F, G;
    
    // Question a)
//    const auto start{std::chrono::steady_clock::now()};
//    
//	int i;
//	for(i=1; i<=100000; ++i)
//		A.push_back(i);
//	
//	const auto finish{std::chrono::steady_clock::now()};
//	const std::chrono::duration<double> elapsed_seconds{finish - start};
//	
//	std::cout << "Values 1 - 100,000 stored in vector A in " << elapsed_seconds.count() << "s" << std::endl;
	
	// Question b)
//	const auto start{std::chrono::steady_clock::now()};
//    
//	int i;
//	for(i=100000; i>=1; --i)
//		A.push_back(i);
//	
//	const auto finish{std::chrono::steady_clock::now()};
//	const std::chrono::duration<double> elapsed_seconds{finish - start};
//	
//	std::cout << "Values 100,000 - 1 stored in vector B in " << elapsed_seconds.count() << "s" << std::endl;

	// Question c)
	std::srand(std::time(0));
	const auto start{std::chrono::steady_clock::now()};

	int i;
	for(i=1; i<=100000; ++i)
		C.push_back(rand() % 100000 + 1);
	
	const auto finish{std::chrono::steady_clock::now()};
	const std::chrono::duration<double> elapsed_seconds{finish - start};
	
	std::cout << "100,000 random values stored in vector C in " << elapsed_seconds.count() << "s" << std::endl;
    return 0;
}
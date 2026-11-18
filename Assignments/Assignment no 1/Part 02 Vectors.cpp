#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<cstdlib>
#include<ctime>

// =========================================== Part 2 for Vectors Only==========================================
template<typename T>
// ReheapDown function remove top element form priority_queue, actually it is a helper of pop
void Reheapdown(std::vector<T> &v, int first, int last){
		int left, right, max;
		left = first * 2 + 1;
		right = first * 2 + 2;
		max = left;
		while(left <= last){
			if(right <= last){
				if(v[right] > v[left])
					max = right;
			}
			if(v[first] < v[max]){
				std::swap(v[first], v[max]);
				first = max;
				left = first * 2 + 1;
				right = first * 2 + 2;
				max = left;
			}else{
				break;
			}
		}
	}

// Question a)
// Heap sort Function
template <typename T>
void heapsort(std::vector<T>& v){
	int n = v.size();
	for(int i = n / 2 - 1; i >= 0; --i){
		Reheapdown(v, i, n - 1);
	}
	for (int i = n - 1; i > 0; --i){
		std::swap(v[0], v[i]);
		Reheapdown(v, 0, i - 1);
	}
}

// Question b)
// Insertion Sorting
template<typename T>
void insertionsorting(std::vector<T>& v){
	int i, j, n = v.size();
	for(i=1; i<n; ++i){
		int temp = v[i];
		for(j=i-1; j>=0 && v[j] > temp; --j){
			v[j+1] = v[j];
		}
		v[j+1] = temp;
	}
}
// -------------------------------------------------------------------------------------------------------------------

int main(){
	
    std::vector<int> A, B, C;
    std::vector<int> E, F, G;
	int i;
	std::srand(std::time(0));
    
    // Question a)
	for(i=1; i<=100000; ++i)
		A.push_back(i);
	
	// Question b)
	for(i=100000; i>=1; --i)
		B.push_back(i);

	// Question c)
	for(i=1; i<=100000; ++i)
		C.push_back(rand() % 100000 + 1);
	
	// Question e)
	for(i=1; i<=100000; ++i)
		E.push_back(i);
	
	// Question f)
	for(i=100000; i>=1; --i)
		F.push_back(i);
	
	// Question g)
	for(i=1; i<=100000; ++i)
		G.push_back(rand() % 100000 + 1);


// ====================== part 02 Implementation =================================
	// Question c)
    const auto start_cHA{std::chrono::steady_clock::now()};
    heapsort(A);
    const auto finish_cHA{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_cHA{finish_cHA - start_cHA};
    std::cout << "Heap Sorting Time of Vector A is " << elapsed_cHA.count() << "s" << std::endl;
    // -------------
    const auto start_cHB{std::chrono::steady_clock::now()};
    heapsort(B);
    const auto finish_cHB{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_cHB{finish_cHB - start_cHB};
    std::cout << "Heap Sorting Time of Vector B is " << elapsed_cHB.count() << "s" << std::endl;
    // -------------
    const auto start_cHC{std::chrono::steady_clock::now()};
    heapsort(C);
    const auto finish_cHC{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_cHC{finish_cHC - start_cHC};
    std::cout << "Heap Sorting Time of Vector C is " << elapsed_cHC.count() << "s" << std::endl;

    // Question d)
    const auto start_dIE{std::chrono::steady_clock::now()};
    insertionsorting(E);
    const auto finish_dIE{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dIE{finish_dIE - start_dIE};
    std::cout << "Insertion Sorting Time of Vector E is " << elapsed_dIE.count() << "s" << std::endl;
    // -------------
    const auto start_dIF{std::chrono::steady_clock::now()};
    insertionsorting(F);
    const auto finish_dIF{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dIF{finish_dIF - start_dIF};
    std::cout << "Insertion Sorting Time of Vector F is " << elapsed_dIF.count() << "s" << std::endl;
    // -------------
    const auto start_dIG{std::chrono::steady_clock::now()};
    insertionsorting(G);
    const auto finish_dIG{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dIG{finish_dIG - start_dIG};
    std::cout << "Insertion Sorting Time of Vector G is " << elapsed_dIG.count() << "s" << std::endl;


	return 0;
	
}

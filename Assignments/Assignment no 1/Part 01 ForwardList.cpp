#include<iostream>
#include<forward_list>
#include<algorithm>
#include<chrono>
#include<cstdlib>
#include<ctime>


// ==================================== PART 1 For Forward_list =======================================
int main(){

    std::forward_list<int> A, B, C;
    std::forward_list<int> E, F, G;
    int i;
    std::srand(std::time(0));

    // Question a)
    const auto start_a{std::chrono::steady_clock::now()};
    auto tail_a = A.before_begin();
    for(i=1; i<=100000; ++i)
        tail_a = A.insert_after(tail_a, i);
    const auto finish_a{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_a{finish_a - start_a};
    std::cout << "Values 1 - 100,000 stored in forward_list A in " << elapsed_a.count() << "s" << std::endl;

    // Question b)
    const auto start_b{std::chrono::steady_clock::now()};
    auto tail_b = B.before_begin();
    for(i=100000; i>=1; --i)
        tail_b = B.insert_after(tail_b, i);
    const auto finish_b{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_b{finish_b - start_b};
    std::cout << "Values 100,000 - 1 stored in forward_list B in " << elapsed_b.count() << "s" << std::endl;

    // Question c)
    const auto start_c{std::chrono::steady_clock::now()};
    auto tail_c = C.before_begin();
    for(i=1; i<=100000; ++i)
        tail_c = C.insert_after(tail_c, rand() % 100000 + 1);
    const auto finish_c{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_c{finish_c - start_c};
    std::cout << "100,000 random values stored in forward_list C in " << elapsed_c.count() << "s" << std::endl;

    // Question d)
    const auto start_dA{std::chrono::steady_clock::now()};
    A.sort();
    const auto finish_dA{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dA{finish_dA - start_dA};
    std::cout << "Sorting Time of Forward List A is " << elapsed_dA.count() << "s" << std::endl;
    // -------------
    const auto start_dB{std::chrono::steady_clock::now()};
    B.sort();
    const auto finish_dB{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dB{finish_dB - start_dB};
    std::cout << "Sorting Time of Forward List B is " << elapsed_dB.count() << "s" << std::endl;
    // -------------
    const auto start_dC{std::chrono::steady_clock::now()};
    C.sort();
    const auto finish_dC{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_dC{finish_dC - start_dC};
    std::cout << "Sorting Time of Forward List C is " << elapsed_dC.count() << "s" << std::endl;

    // Question e)
    const auto start_e{std::chrono::steady_clock::now()};
    auto tail_e = E.before_begin();
    for(i=1; i<=100000; ++i)
        tail_e = E.insert_after(tail_e, i);
    const auto finish_e{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_e{finish_e - start_e};
    std::cout << "Values 1 - 100,000 stored in forward_list E in " << elapsed_e.count() << "s" << std::endl;

    // Question f)
    const auto start_f{std::chrono::steady_clock::now()};
    auto tail_f = F.before_begin();
    for(i=100000; i>=1; --i)
        tail_f = F.insert_after(tail_f, i);
    const auto finish_f{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_f{finish_f - start_f};
    std::cout << "Values 100,000 - 1 stored in forward_list F in " << elapsed_f.count() << "s" << std::endl;

    // Question g)
    const auto start_g{std::chrono::steady_clock::now()};
    auto tail_g = G.before_begin();
    for(i=1; i<=100000; ++i)
        tail_g = G.insert_after(tail_g, rand() % 100000 + 1);
    const auto finish_g{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_g{finish_g - start_g};
    std::cout << "100,000 random values stored in forward_list G in " << elapsed_g.count() << "s" << std::endl;

    // Question h)
    const auto start_hE{std::chrono::steady_clock::now()};
    erase_if(E, [](int x){
        return x % 2 != 0;
    });
    const auto finish_hE{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_hE{finish_hE - start_hE};
    std::cout << "Odd Deletion Time for forward_list E is " << elapsed_hE.count() << "s" << std::endl;
    // -------------
    const auto start_hF{std::chrono::steady_clock::now()};
    erase_if(F, [](int x){
        return x % 2 != 0;
    });
    const auto finish_hF{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_hF{finish_hF - start_hF};
    std::cout << "Odd Deletion Time for forward_list F is " << elapsed_hF.count() << "s" << std::endl;
    // -------------
    const auto start_hG{std::chrono::steady_clock::now()};
    erase_if(G, [](int x){
        return x % 2 != 0;
    });
    const auto finish_hG{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_hG{finish_hG - start_hG};
    std::cout << "Odd Deletion Time for forward_list G is " << elapsed_hG.count() << "s" << std::endl;


    return 0;
}

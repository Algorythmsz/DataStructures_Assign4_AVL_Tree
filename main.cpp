/**
 * Assignment 4 for COSE213 Data Structures
 *
 * Won-Ki Jeong (wkjeong@korea.ac.kr)
 *
 * 2022. 5. 22
 *
 */

#include "LinkedBinaryTree.h"
#include "SearchTree.h"
#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#include <iostream>

using namespace std;

int main()
{
    typedef Entry<int, float> EntryType;

    LinkedBinaryTree<EntryType> t;

    std::cout << "Size : " << t.size() << std::endl;

    t.addRoot();

    std::cout << "Size : " << t.size() << std::endl;


    //
    //
    //
    SearchTree<EntryType>    st;

    std::cout << "Size : " << st.size() << std::endl;
    st.insert(1, 2.5);
    st.insert(3, 4.5);
    st.insert(7, 5.5);
    st.insert(2, 1.5);
    st.insert(3, 8.5);
    std::cout << "Size : " << st.size() << std::endl;

    for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
    {
        std::cout << (*it).key() << " , " << (*it).value() << std::endl;
    }

    st.erase(3);
    std::cout << "Size : " << st.size() << std::endl;
    for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
    {
        std::cout << (*it).key() << " , " << (*it).value() << std::endl;
    }

    std::cout << "------------" << std::endl;


    //
    //
    AVLTree<EntryType>    avl;
    //
    // random test
    int nElem = 100000; //100000000;

    int *key = new int[nElem*2];
    float *val = new float[nElem*2];

    std::srand((unsigned int)time(NULL)); // use current time as seed for random generator


    // initialize
    for(int i=0; i<nElem*2; i++)
    {
        key[i] = i+1;
        val[i] = (float) std::rand()/RAND_MAX * 20000;
    }


    //
    // AVL tree Insert test
    //
    clock_t tm;
    tm = clock();
    for(int i=0; i<nElem; i++)
    {
        avl.insert(key[i], val[i]);
    }
    tm = clock() - tm;
    printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);


    //
    // AVL tree Find test
    //
    tm = clock();
    for(int i=nElem; i<nElem*2; i++)
    {
        avl.find(key[i]);
    }
    tm = clock() - tm;
    printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);
    delete[] key;
    delete[] val;
    std::cout << "------------" << std::endl;

    //
    //Test Cases Implementation
    //
    std::cout << "Test Cases Implementation" << std::endl;
    //1) size = 1000
    std::cout << " 1. size = 1000" << std::endl;
    //In skewed order(increasing order)
    std::cout << " " << std::endl;
    std::cout << "  1-(1). Skewed Order(Increasing Order)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int n1Elem = 1000;
    int *n11key = new int[n1Elem];
    float *n11val = new float[n1Elem];

    for(int i=0; i<n1Elem; i++)    //initialize
    {
        n11key[i] = i+1;   //keys are initialized in increasing order.
        n11val[i] = (float) std::rand()/RAND_MAX * 20000;  //value doesn't matter, so I will use it repeatedly
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test1_1;

    tm = clock();
    for(int i=0; i<n1Elem; i++)
        st_test1_1.insert(n11key[i], n11val[i]);
    tm = clock() - tm;
    float st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test1_1;
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        avl_test1_1.insert(n11key[i], n11val[i]);
    tm = clock() - tm;
    float avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;

    //Comparison
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;

    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        st_test1_1.find(n11key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        avl_test1_1.find(n11key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n11key;
    delete[] n11val;

    std::cout << " " << std::endl;

    std::cout << "  1-(2). Random Order" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int* n12key = new int[n1Elem];
    float* n12val = new float[n1Elem];

    for(int i=0; i<n1Elem; i++)    //randomly initialize
    {
        n12key[i] = std::rand();
        n12val[i] = (float) std::rand()/RAND_MAX * 20000;
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test1_2;
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        st_test1_2.insert(n12key[i], n12val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test1_2;
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        avl_test1_2.insert(n12key[i], n12val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        st_test1_2.find(n12key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n1Elem; i++)
        avl_test1_2.find(n12key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n12key;
    delete[] n12val;

    std::cout << " ------------" << std::endl;
    std::cout << " 2. size = 10000" << std::endl;
    //In skewed order(increasing order)
    std::cout << " " << std::endl;
    std::cout << "  2-(1). Skewed Order(Increasing Order)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int n2Elem = 10000;
    int* n21key = new int[n2Elem];
    float* n21val = new float[n2Elem];

    for(int i=0; i<n2Elem; i++)    //initialize
    {
        n21key[i] = i+1;   //keys are initialized in increasing order.
        n21val[i] = (float) std::rand()/RAND_MAX * 20000;  //value doesn't matter, so I will use it repeatedly
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test2_1;

    tm = clock();
    for(int i=0; i<n2Elem; i++)
        st_test2_1.insert(n21key[i], n21val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test2_1;

    tm = clock();
    for(int i=0; i<n2Elem; i++)
        avl_test2_1.insert(n21key[i], n21val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i<n2Elem; i++)
        st_test2_1.find(n21key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n2Elem; i++)
        avl_test2_1.find(n21key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n21key;
    delete[] n21val;

    std::cout << " " << std::endl;

    std::cout << "  2-(2). Random Order" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int* n22key = new int[n2Elem];
    float* n22val = new float[n2Elem];

    for(int i=0; i<n2Elem; i++)    //randomly initialize
    {
        n22key[i] = std::rand();
        n22val[i] = (float) std::rand()/RAND_MAX * 20000;
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test2_2;

    tm = clock();
    for(int i=0; i<n2Elem; i++)
        st_test2_2.insert(n22key[i], n22val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test2_2;

    tm = clock();
    for(int i=0; i<n2Elem; i++)
        avl_test2_2.insert(n22key[i], n22val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i<n2Elem; i++)
        st_test2_2.find(n22key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n2Elem; i++)
        avl_test2_2.find(n22key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n22key;
    delete[] n22val;

    std::cout << " ------------" << std::endl;

    std::cout << " 3. size = 100000" << std::endl;
    //In skewed order(increasing order)
    std::cout << " " << std::endl;

    std::cout << "  3-(1). Skewed Order(Increasing Order)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int n3Elem = 100000;
    int *n31key = new int[n3Elem];
    float *n31val = new float[n3Elem];
    
    for(int i=0; i<n3Elem; i++)    //initialize
    {
        n31key[i] = i+1;   //keys are initialized in increasing order.
        n31val[i] = (float) std::rand()/RAND_MAX * 20000;  //value doesn't matter, so I will use it repeatedly
    }
    
    //Search Tree Insertion
    SearchTree<EntryType>    st_test3_1;

    tm = clock();
    for(int i=0; i<n3Elem; i++)
        st_test3_1.insert(n31key[i], n31val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test3_1;

    tm = clock();
    for(int i=0; i<n3Elem; i++)
        avl_test3_1.insert(n31key[i], n31val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i< n3Elem; i++)
        st_test3_1.find(n31key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n3Elem; i++)
        avl_test3_1.find(n31key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n31key;
    delete[] n31val;

    std::cout << " " << std::endl;
    std::cout << "  3-(2). Random Order" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;

    int *n32key = new int[n3Elem];
    float *n32val = new float[n3Elem];

    for(int i=0; i<n3Elem; i++)    //randomly initialize
    {
        n32key[i] = std::rand();
        n32val[i] = (float) std::rand()/RAND_MAX * 20000;
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test3_2;

    tm = clock();
    for(int i=0; i<n3Elem; i++)
        st_test3_2.insert(n32key[i], n32val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test3_2;

    tm = clock();
    for(int i=0; i<n3Elem; i++)
        avl_test3_2.insert(n32key[i], n32val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i=0; i<n3Elem; i++)
        st_test3_2.find(n32key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n3Elem; i++)
        avl_test3_2.find(n32key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n32key;
    delete[] n32val;
    
    std::cout << " ------------" << std::endl;
    std::cout << " 4. size = 1000000" << std::endl;
    
    //In skewed order(increasing order)
    std::cout << " " << std::endl;
    
    std::cout << "  4-(1). Skewed Order(Increasing Order)" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;
    
    int n4Elem = 1000000;
    int *n41key = new int[n4Elem];
    float *n41val = new float[n4Elem];
    
    for(int i = 0; i < n4Elem; i++)    //initialize
    {
        n41key[i] = i+1;   //keys are initialized in increasing order.
        n41val[i] = (float) std::rand()/RAND_MAX * 20000;  //value doesn't matter, so I will use it repeatedly
    }

    //Search Tree Insertion
    SearchTree<EntryType>    st_test4_1;

    tm = clock();
    for(int i = 0; i < n4Elem; i++)
        st_test4_1.insert(n41key[i], n41val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    
    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test4_1;
    
    tm = clock();
    for(int i = 0; i < n4Elem; i++)
        avl_test4_1.insert(n41key[i], n41val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;

    //Search Tree Find
    tm = clock();
    for(int i = 0; i < n4Elem; i++)
        st_test4_1.find(n41key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;

    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n4Elem; i++)
        avl_test4_1.find(n41key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;

    delete[] n41key;
    delete[] n41val;
    
    std::cout << " " << std::endl;
    std::cout << "  4-(2). Random Order" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (a). Insert Operation" << std::endl;
    
    int *n42key = new int[n4Elem];
    float *n42val = new float[n4Elem];
    
    for(int i = 0; i < n4Elem; i++)    //randomly initialize
    {
        n42key[i] = std::rand();
        n42val[i] = (float) std::rand()/RAND_MAX * 20000;
    }
    
    //Search Tree Insertion
    SearchTree<EntryType>    st_test4_2;
    
    tm = clock();
    for(int i=0; i<n4Elem; i++)
        st_test4_2.insert(n42key[i], n42val[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //AVL Tree Insertion
    AVLTree<EntryType>    avl_test4_2;
    
    tm = clock();
    for(int i=0; i<n4Elem; i++)
        avl_test4_2.insert(n42key[i], n42val[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Insertion was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Insertion was faster than Search Tree's." << std::endl;
    std::cout << " " << std::endl;
    std::cout << "    (b). Find Operation" << std::endl;
    
    //Search Tree Find
    tm = clock();
    for(int i=0; i<n4Elem; i++)
        st_test4_2.find(n42key[i]);
    tm = clock() - tm;
    st_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (i)  Search Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //AVL Tree Find
    tm = clock();
    for(int i=0; i<n4Elem; i++)
        avl_test4_2.find(n42key[i]);
    tm = clock() - tm;
    avl_Clock = ((float)tm)/(float)CLOCKS_PER_SEC;
    std::cout << "       (ii) AVL Tree : " << ((float)tm)/(float)CLOCKS_PER_SEC << " seconds." << std::endl;
    
    //comparison
    if(st_Clock < avl_Clock)
        std::cout << "          -> Search Tree Find was faster than AVL Tree's." << std::endl;
    else
        std::cout << "          -> AVL Tree Find was faster than Search Tree's." << std::endl;
    
    delete[] n42key;
    delete[] n42val;
    std::cout << " ------------" << std::endl;

    return 0;
    
}


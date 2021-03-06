/*
 *  test_math.cpp
 *  cpputils
 *
 *  Created by Bowen Liang.
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>

#include "utils.hpp"

using std::cout;
using std::endl;
using namespace algorithm;

int main(int argc, char *argv[]) {
    cout<<"Test utility functions"<<endl;
    
    // set seed for random number generator
    srand(1);
    std::vector<int> random_vecs;
    random_vecs.reserve(100);
    for (int i=0; i<100; ++i)
    {
        random_vecs.push_back(rand() % 100);
    }
    std::sort(random_vecs.begin(), random_vecs.end());
    for (int i=0; i<20; ++i)
    {
        int key = rand() % 100;
        int index = BinarySearchRank<int>(key, random_vecs);
        if (index > -1)
            std::cout << "Key " << key << " found with id " << index << std::endl;
        else
            std::cout << "Key " << key << " not found! "<< std::endl;
    }
    
    // white list and black list two sets of text files
    std::vector<int> int_vectors_T, int_vectors_W;
    std::string filename_T = "/home/bowen/workspace/Algorithms/examples/input/tinyT.txt";
    std::string filename_W = "/home/bowen/workspace/Algorithms/examples/input/tinyW.txt";
    FileReader::ReadFileWithAllInts(filename_T, int_vectors_T);
    FileReader::ReadFileWithAllInts(filename_W, int_vectors_W);

    std::cout << "************************************************************" << std::endl;
    std::cout << "Test whilte list" << std::endl;
    
    std::sort(int_vectors_W.begin(), int_vectors_W.end());
    for (auto key : int_vectors_T)
    {
        int index = BinarySearchRank<int>(key, int_vectors_W);
        if (index < 0)
            std::cout << "Key " << key << " not found! "<< std::endl;
    }
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test singly linked list" << std::endl;
    
    SingleLinkedList<double> linked_list;
    linked_list.AddNode(0.2);
    linked_list.AddNode(0.8);
    linked_list.AddNode(1.6);
    linked_list.AddNode(6.4);
    linked_list.Display();
    
    linked_list.AddAtFront(3.2);
    linked_list.AddAtPos(1.2, 3);
    linked_list.Display();
    
    linked_list.RemoveAtFront();
    linked_list.Display();
    linked_list.RemoveAtPos(2);
    linked_list.Display();
    linked_list.RemoveAtBack();
    linked_list.Display();
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Two sum and three sum" << std::endl;
    std::vector<int> ints_vector;
    std::string filename = "/home/bowen/workspace/Algorithms/examples/input/1Kints.txt";
    FileReader::ReadFileWithAllInts(filename, ints_vector);
    std::clock_t start = std::clock();
    std::cout << "The number of pairs: " << BasicUtils::TwoSumBrute(ints_vector) << std::endl;
    double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    start = std::clock();
    std::cout << "The number of pairs: " << BasicUtils::TwoSumFast(ints_vector) << std::endl;
    double duration1 = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    
    std::cout << "TwoSumBrute use time: " << duration << "s." << std::endl;
    std::cout << "TwoSumFast use time: " << duration1 << "s." << std::endl;
    
    start = std::clock();
    //std::cout << "ThreeSum: The number of pairs: " << BasicUtils::ThreeSumBrute(ints_vector) << std::endl;
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    start = std::clock();
    std::cout << "The number of pairs: " << BasicUtils::ThreeSumFast(ints_vector) << std::endl;
    duration1 = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    
    //std::cout << "ThreeSumBrute use time: " << duration << "s." << std::endl;
    std::cout << "ThreeSumFast use time: " << duration1 << "s." << std::endl;
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test priority queue" << std::endl;
    
    std::vector<std::string> vec_strs;
    vec_strs.reserve(11);
    vec_strs.push_back("A");
    vec_strs.push_back("E");
    vec_strs.push_back("C");
    vec_strs.push_back("Z");
    vec_strs.push_back("D");
    vec_strs.push_back("M");
    vec_strs.push_back("Q");
    vec_strs.push_back("F");
    vec_strs.push_back("N");
    vec_strs.push_back("L");
    vec_strs.push_back("J");
    PriorityQueue<std::string> pq(vec_strs);
    pq.display();
    
    pq.delMax();
    pq.display();
    
    pq.insert("S");
    pq.insert("O");
    pq.display();
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test binary search tree" << std::endl;
    
    std::string all_strs = "SEARCHEXAMPLE";
    BinarySearchTree<std::string, int> bst;
    for (int i = 0; i < all_strs.size(); i++)
    {
        std::string str(all_strs.begin() + i, all_strs.begin() + i + 1);
        bst.put(str, i);
    }
    for (auto s : bst.levelOrder())
    {
        std::cout<<s<<": "<<bst.get(s)<< "\t";
    }
    std::cout<<std::endl;
    for (auto s : bst.keys())
    {
        std::cout<<s<<": "<<bst.get(s)<<"\t";
    }
    std::cout<<std::endl;


    std::cout << "************************************************************" << std::endl;
    std::cout << "Test red black BST" << std::endl;
    
    RedBlackBST<std::string, int> RBbst;
    for (int i = 0; i < all_strs.size(); i++)
    {
        std::string str(all_strs.begin() + i, all_strs.begin() + i + 1);
        RBbst.put(str, i);
    }
    
    std::cout<<"size = "<<RBbst.size()<<"\n";
    std::cout<<"min = "<<RBbst.minKey()<<"\n";
    std::cout<<"max = "<<RBbst.maxKey()<<"\n";
    std::cout<<"height = "<<RBbst.height()<<"\n";
    
    for (auto s : RBbst.keys())
    {
        std::cout<<s<<": "<<RBbst.get(s)<<"\t";
    }
    std::cout<<std::endl;
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test separate chaining Hash table" << std::endl;
    
    HashSTSeparateChain<std::string, int> seperate_chain_HT;
    for (int i = 0; i < all_strs.size(); i++)
    {
        std::string str(all_strs.begin() + i, all_strs.begin() + i + 1);
        seperate_chain_HT.put(str, i);
    }
    
    std::cout<<"size = "<<seperate_chain_HT.size()<<"\n";
    
    for (auto s : seperate_chain_HT.keys())
    {
        std::cout<<s<<": "<<seperate_chain_HT.get(s)<<"\t";
    }
    std::cout<<std::endl;
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test linear probing Hash table" << std::endl;
    
    HashSTLinearProbing<std::string, int> linear_probe_HT;
    for (int i = 0; i < all_strs.size(); i++)
    {
        std::string str(all_strs.begin() + i, all_strs.begin() + i + 1);
        linear_probe_HT.put(str, i);
    }
    
    std::cout<<"size = "<<linear_probe_HT.size()<<"\n";
    
    for (auto s : linear_probe_HT.keys())
    {
        std::cout<<s<<": "<<linear_probe_HT.get(s)<<"\t";
    }
    std::cout<<std::endl;
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test undirected graphs " << std::endl;
    
    std::string filename_G = "/home/bowen/workspace/Algorithms/examples/input/tinyG.txt";
    Graph G = FileReader::ReadFileToBuildGraph(filename_G);
    G.print();
    
    std::cout << "************************************************************" << std::endl;
    std::cout << "Test depth first search and path for undirected graph" << std::endl;
    
    DepthFirstSearch search0(G, 0);
    DepthFirstSearch search1(G, 9);
    for (int i = 0; i < G.V(); i++)
    {
        if (search0.marked(i))
            std::cout<<i<<" ";
    }
    std::cout<<" \n";
    
    if (search0.count() != G.V())
        std::cout<<"NOT connected \n";
    else
        std::cout<<"connected \n";
    
    for (int i = 0; i < G.V(); i++)
    {
        if (search1.marked(i))
            std::cout<<i<<" ";
    }
    std::cout<<" \n";
    
    if (search1.count() != G.V())
        std::cout<<"NOT connected \n";
    else
        std::cout<<"connected \n";
        
    for (int i = 0; i < G.V(); i++)
    {
        if (search0.hasPathTo(i))
        {
            std::cout<<"0 to "<<i<<": ";
            for (auto w : search0.pathTo(i))
            {
                std::cout<<"-"<<w;                    
            }
            std::cout<<"\n";
        }
        else
        {
            std::cout<<"0 to "<<i<<": not connected \n";
        }
    }
    
    
    return 0;
}

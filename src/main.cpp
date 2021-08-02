#include <iostream>
#include <cstdlib>
#include <huffman.hpp>
#include <utils.hpp>


int main(){

    int numObjects = 10;
    int valRange = 10;

    int *frequencies = util::randomFrequencies(numObjects, valRange);
    std::vector <node*> freqs = sortObjects(frequencies, numObjects);

    //util::printVector(freqs);
    //std::cout<<std::endl;

    int n = freqs.size();
    node *root = new node;
    root = huffmanTree(freqs, n);
    traverseHuffmanTree(root);

}
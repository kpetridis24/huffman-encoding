#ifndef __HUFFMAN_HPP__
#define __HUFFMAN_HPP__

#include <iostream>
#include <cstdlib>
#include <utils.hpp>


std::vector <node*> sortObjects(int *frequencies, int len){

    std::vector <node*> freqs;
    util::quickSort(frequencies, 0, len - 1);
    for(int i = 0; i < len; i++) {
        
        node *temp = new node;
        temp->frequency = frequencies[i];
        freqs.push_back(temp);
    }

    return freqs;
}


// Frequencies must be already sorted.
node *huffmanTree(node *root, std::vector <node*> frequencies, int n){

    //std::cout<<std::endl;
    if(n <= 1) return root;
    
    node *newNode = new node;
    newNode->frequency = 0;

    newNode->left = frequencies.at(0);
    newNode->frequency += frequencies.at(0)->frequency;
    frequencies.erase(frequencies.begin());
    newNode->right = frequencies.at(0);
    newNode->frequency += frequencies.at(0)->frequency;
    frequencies.erase(frequencies.begin());

    //std::cout<<"Before"<<std::endl;
    //util::printVector(frequencies);

    //std::cout<<"Target="<<newNode->frequency<<std::endl;
    int newNodePosition = util::linearSearch(frequencies, newNode->frequency);//linearSearch(frequencies, newNode->frequency);
    //std::cout<<"pos="<<newNodePosition<<std::endl;
    frequencies.insert(frequencies.begin() + newNodePosition, newNode);

    //std::cout<<"After"<<std::endl;
    //util::printVector(frequencies);

    huffmanTree(newNode, frequencies, frequencies.size());
    return newNode;
}


void traverseHuffmanTree(node *root){
    
    if(root->left != NULL){
        root->left->code = 0;
        traverseHuffmanTree(root->left);
    }

    if(root->right != NULL){
        root->right->code = 1;
        traverseHuffmanTree(root->right);
    }
}


#endif
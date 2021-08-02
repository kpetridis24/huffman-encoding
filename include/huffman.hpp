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


node *huffmanTree(std::vector <node*> frequencies, int n){

    while(frequencies.size() > 1){

        node *newNode = new node;
        newNode->frequency = 0;

        newNode->left = frequencies.at(0);
        newNode->frequency += frequencies.at(0)->frequency;
        frequencies.erase(frequencies.begin());
        newNode->right = frequencies.at(0);
        newNode->frequency += frequencies.at(0)->frequency;
        frequencies.erase(frequencies.begin());

        int newNodePosition = util::linearSearch(frequencies, newNode->frequency);
        frequencies.insert(frequencies.begin() + newNodePosition, newNode);
    }

    return frequencies.at(0);
}


void traverseHuffmanTree(node *root){
    
    if(root->left != NULL){
        //std::cout<<"left of "<<root->frequency<<" is "<<root->left->frequency<<std::endl;
        root->left->code = 0;
        traverseHuffmanTree(root->left);
    }

    if(root->right != NULL){
        //std::cout<<"right of "<<root->frequency<<" is "<<root->right->frequency<<std::endl;
        root->right->code = 1;
        traverseHuffmanTree(root->right);
    }
}


#endif
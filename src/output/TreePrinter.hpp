#pragma once
#include<iostream>
#include<string>
#include"../core/Node.hpp"

void printTree(const std::shared_ptr<Node>& node,
    const std::string& prefix = "",
    bool isLeft = true)
{
    if(node == nullptr)
    {
        return;
    }
    std::cout << prefix;
    if(isLeft)
    {
        std::cout << "|---> ";
    }
    else
    {
        std::cout << "|---> ";
    }
    switch(node->type)
    {
        case NodeType::CONSTANT:
            std::cout << "CONSTANT: " << node->value << "\n";
            break;
        
        case NodeType::VARIABLE:
            std::cout << "VARIABLE: " << node->name << "\n";
            break;
        case NodeType::ADD:
            std::cout << "ADD\n";
            break;
        case NodeType::MULTIPLY:
            std::cout << "MULTIPLY\n";
            break;
        case NodeType::POWER:
            std::cout << "POWER\n";
            break;
    }
    printTree(node->left, prefix+"|  ", true);
    printTree(node->right, prefix+"|  ", false);
}
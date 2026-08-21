#pragma once
#include<iostream>
#include"../core/Node.hpp"

void printExpression(const std::shared_ptr<Node>& node)
{
    if(node->type == NodeType::CONSTANT)
    {
        std::cout << node->value;
    }
    else if (node->type == NodeType::VARIABLE)
    {
        std::cout << node->name;
    }
    else if(node->type == NodeType::POWER)
    {
        printExpression(node->left);
        std::cout << "^";
        printExpression(node->right);
    }
    else if(node->type == NodeType::ADD)
    {
        printExpression(node->left);
        std::cout << " + ";
        printExpression(node->right);
    }
    else if(node->type == NodeType::MULTIPLY)
    {
        printExpression(node->left);
        std::cout << "*";
        printExpression(node->right);
    }
}
#pragma once

#include<memory>
#include<string>

enum class NodeType
{
    CONSTANT,
    VARIABLE,
    ADD,
    MULTIPLY,
    POWER,
};

struct Node
{
    NodeType type;
    double value = 0;
    std::string name;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    //constant constructor
    Node(double number)
    {
        type = NodeType::CONSTANT;
        value = number;
    }

    //Variable Constructor
    Node(std::string variable)
    {
        type = NodeType::VARIABLE;
        name = variable;
    }

    //Operator Constructor
    Node(NodeType operation, std::shared_ptr<Node> leftNode, std::shared_ptr<Node> rightNode)
    {
        type = operation;
        left = leftNode;
        right = rightNode;
    }
};
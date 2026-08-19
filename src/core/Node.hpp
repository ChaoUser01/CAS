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
};
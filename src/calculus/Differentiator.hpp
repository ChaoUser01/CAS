#pragma once
#include"../core/Node.hpp"
#include<stdexcept>

std::shared_ptr<Node> differentiate(
    const std::shared_ptr<Node>& node,
    const std::string& variable

)
{
    if(node->type == NodeType::CONSTANT)
    {
        return std::make_shared<Node>(0);
    }

    if(node->type == NodeType::VARIABLE)
    {
        if(node->name == variable)
        {
            return std::make_shared<Node>(1);
        }
        return std::make_shared<Node>(0);
    }
    if(node->type == NodeType::POWER)
    {
        auto exponent = node->right;
        auto newExponent = std::make_shared<Node>(
            exponent->value - 1
        );
        auto newPower = std::make_shared<Node>(
            NodeType::POWER,
            node->left,
            newExponent
        );
        return std::make_shared<Node>(
            NodeType::MULTIPLY,
            exponent,
            newPower
        );
    }
    if(node->type == NodeType::ADD)
    {
        auto leftDerivative = differentiate(node->left, variable);
        auto rightDerivative = differentiate(node->right, variable);

        return std::make_shared<Node>(
            NodeType::ADD,
            leftDerivative,
            rightDerivative
        );
    }
    throw std::runtime_error("Unsupported expression type");
}
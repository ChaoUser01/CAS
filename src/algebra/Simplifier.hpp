#pragma once
#include"../core/Node.hpp"

std::shared_ptr<Node> simplify(const std::shared_ptr<Node>& node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(node->left)
    {
        node->left = simplify(node->left);
    }
    if(node->right)
    {
        node->right = simplify(node->right);
    }
    if(node->type == NodeType::POWER)
    {
        auto exponent = node->right;
        if(exponent->type == NodeType::CONSTANT && exponent->value == 1)
        {
            return simplify(node->left);
        }
    }

    return node;
}
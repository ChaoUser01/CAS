#include<iostream>
#include "core/Node.hpp"

int main()
{
    auto x = std::make_shared<Node>("x");
    auto two = std::make_shared<Node>(2);
    auto power = std::make_shared<Node>(
        NodeType::POWER,
        x,
        two
    );

    std::cout << "Created x^2 tree\n";
    return 0;
}
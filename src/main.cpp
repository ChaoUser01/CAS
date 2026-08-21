#include<iostream>
#include "core/Node.hpp"
#include"output/printer.hpp"
#include"calculus/Differentiator.hpp"

int main()
{
    auto x = std::make_shared<Node>("x");
    auto two = std::make_shared<Node>(2);
    auto power = std::make_shared<Node>(
        NodeType::POWER,
        x,
        two
    );

    std::cout << "Original: ";
    printExpression(power);
    std::cout <<"\n";

    auto derivative = differentiate(power, "x");
    std::cout << "Derivative: ";
    printExpression(derivative);
    std::cout << "\n";

    return 0;
}
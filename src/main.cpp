#include<iostream>
#include "core/Node.hpp"
#include"output/printer.hpp"
#include"calculus/Differentiator.hpp"
#include"algebra/Simplifier.hpp"
#include "output/TreePrinter.hpp"
int main()
{
    auto x = std::make_shared<Node>("x");
    auto two = std::make_shared<Node>(2);
    auto xSqd = std::make_shared<Node>(
        NodeType::POWER,
        x,
        two
    );
    auto three = std::make_shared<Node>(3);
    auto expression = std::make_shared<Node>(
        NodeType::ADD,
        xSqd,
        three
    );

    std::cout << "\nExpression Tree: \n";
    printTree(expression);

    std::cout << "\nOriginal: ";
    printExpression(expression);
    std::cout <<"\n";

    auto derivative = differentiate(expression, "x");
    std::cout << "Before Simplification: ";
    printExpression(derivative);
    std::cout << "\n";

    auto simplified = simplify(derivative);
    std::cout << "After simplification: ";
    printExpression(simplified);

    return 0;
}
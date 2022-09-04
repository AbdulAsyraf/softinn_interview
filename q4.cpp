#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <regex>

//using namespace std;

int main(){
    std::stack<std::string> oper, working;
    std::queue<std::string> out;
    std::string input;
    std::string first, second;

    std::map<std::string,int> precedence={
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };

    std::cout << "This is calculator\n>";

    while(input != "="){
        std::cin >> input;
        if (input == "+" || input == "-" || input == "*" || input == "/"){
            if (oper.empty() || precedence.at(input) > precedence.at(oper.top())){
                // std::cout << "Higher precedence, pushing " << input << " to operator\n";
                oper.push(input);
            }else{
                while (!oper.empty() && precedence.at(input) <= precedence.at(oper.top())){
                    if (!oper.empty()){
                        // std::cout << "Lower or equal precedence, popping " << oper.top() << " and pushing " << input << " to operator\n";
                        out.push(oper.top());
                        oper.pop();
                    }
                }
                oper.push(input);
            }
        }else if (input != "="){
            // std::cout << "pushing " << input << " to output" << std::endl;
            out.push(input);
        }
        
    }
    out.push(oper.top());
    oper.pop();

    // start calculating
    while (!out.empty()){
        if (out.front() == "+"){
            // std::cout << "adding\n";
            second = working.top();
            working.pop();
            first = working.top();
            working.pop();
            working.push(std::to_string(std::stof(first) + std::stof(second)));
            out.pop();
        }else if (out.front() == "-"){
            // std::cout << "subtracting\n";
            second = working.top();
            working.pop();
            first = working.top();
            working.pop();
            working.push(std::to_string(std::stof(first) - std::stof(second)));
            out.pop();
        }else if (out.front() == "*"){
            // std::cout << "multiplying\n";
            second = working.top();
            working.pop();
            first = working.top();
            working.pop();
            working.push(std::to_string(std::stof(first) * std::stof(second)));
            out.pop();
        }else if (out.front() == "/"){
            // std::cout << "dividing\n";
            second = working.top();
            working.pop();
            first = working.top();
            working.pop();
            working.push(std::to_string(std::stof(first) / std::stof(second)));
            out.pop();
        }else{
            working.push(out.front());
            // std::cout << out.front() << std::endl;
            out.pop();
        }
    }

    std::cout << "Result is:\t" << working.top() << std::endl;

    return 0;
}
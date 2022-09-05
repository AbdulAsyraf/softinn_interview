#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <regex>
#include <vector>

//using namespace std;

int main(){
    std::stack<std::string> oper, working;
    std::queue<std::string> out;
    std::string input, input_expression, first, second;
    std::vector<std::string> chopped;

    std::map<std::string,int> precedence={
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };

    std::cout << "This is a calculator\n>";
    getline(std::cin, input_expression);

    std::regex chopper("([0-9]?*[.])?[0-9]+|[\\+\\-\\*\\/]");
    auto parts_begin = std::sregex_iterator(input_expression.begin(), input_expression.end(), chopper);
    auto parts_end = std::sregex_iterator();

    for (std::sregex_iterator i = parts_begin; i != parts_end; i++){
        chopped.push_back((*i).str());
    }

    for (std::vector<std::string>::iterator it = chopped.begin(); it != chopped.end(); it++){
        input = *it;
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
        }
        else{
            out.push(input);
        }
        
    }
    while(!oper.empty()){
        out.push(oper.top());
        oper.pop();
    }
    
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
            out.pop();
        }
    }

    std::cout << "Result is:\t" << working.top() << std::endl;
    

    return 0;
}
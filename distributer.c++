
#include <iostream>
#include <vector>

typedef struct cup_state{
    int current;
    int capacity;
};

bool solver(std::vector<std::vector<cup_state>> queue, std::vector<std::vector<cup_state>> explored){
    //convert psuedocode to real code here
}

int main(){

    std::vector<std::vector<cup_state>> queue;
    cup_state a;
    cup_state b;
    cup_state c;

    std::cout<<"Enter initial level and capacity for the three glasses, first initial then capacity and then do it for the other two cups\n";
    std::cin>>a.current>>a.capacity;
    std::cin>>b.current>>b.capacity;
    std::cin>>c.current>>c.capacity;

    if (a.capacity < a.current || b.capacity < b.current || c.capacity < c.current){
        std::cout<<"Invalid input\n";
        return 0;
    }

    std::vector<cup_state> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    queue.push_back(temp);

    std::vector<std::vector<cup_state>> explored;
    return 0;
}
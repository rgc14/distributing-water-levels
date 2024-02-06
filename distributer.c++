
#include <iostream>
#include <vector>

typedef struct cup_state{
    int current;
    int capacity;
};

bool solver(std::vector<std::vector<cup_state>> queue, std::vector<std::vector<cup_state>> explored){
    //implement bfs

    if (queue.empty()){
        return false;
    }

    cup_state a = queue[0][0];
    cup_state b = queue[0][1];
    cup_state c = queue[0][2];

    queue.erase(queue.begin());

    std::vector<cup_state> current_state;
    current_state.push_back(a);
    current_state.push_back(b);
    current_state.push_back(c);

    for (int i = 0; i < explored.size(); i++){
        if (a.current == explored[i][0].current && b.current == explored[i][1].current && c.current == explored[i][2].current){
            return solver(queue, explored);
        }else{
            explored.push_back(current_state);
        }
    }

    

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
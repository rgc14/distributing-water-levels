
#include <iostream>
#include <vector>

struct cup_state{
    int current;
    int capacity;
};

bool solver(std::vector<std::vector<struct cup_state>> queue, std::vector<std::vector<struct cup_state>> explored, int target){
    //implement bfs

    if (queue.empty()){
        return false;
    }

    std::cout<<queue.size()<<"\t"<<explored.size()<<"\t"<<target<<std::endl;

    struct cup_state a = queue[0][0];
    struct cup_state b = queue[0][1];
    struct cup_state c = queue[0][2];

    queue.erase(queue.begin());

    std::vector<struct cup_state> current_state;
    current_state.push_back(a);
    current_state.push_back(b);
    current_state.push_back(c);

    for (int i = 0; i < explored.size(); i++){
        if (a.current == explored[i][0].current && b.current == explored[i][1].current && c.current == explored[i][2].current){
            return solver(queue, explored, target);
        }
    }

    explored.push_back(current_state);

    if (a.current == target || b.current == target || c.current == target){
        return true;
    }

    int a_space = a.capacity - a.current;
    int b_space = b.capacity - b.current;
    int c_space = c.capacity - c.current;

    std::vector<struct cup_state> format;
    if (a_space != 0){
        struct cup_state new_a = a;
        struct cup_state new_b = b;

        while (new_a.current < new_a.capacity and new_b.current > 0){
            new_a.current += 1;
            new_b.current -= 1;
        }

        format.clear();
        format.push_back(new_a);
        format.push_back(new_b);
        format.push_back(c);
        queue.push_back(format);

        new_a = a;
        struct cup_state new_c = c;

        while (new_a.current < new_a.capacity and new_c.current > 0){
            new_a.current += 1;
            new_c.current -= 1;
        }

        format.clear();
        format.push_back(new_a);
        format.push_back(b);
        format.push_back(new_c);
        queue.push_back(format);
    }
    
    if (b_space != 0){
        struct cup_state new_b = b;
        struct cup_state new_a = a;

        while (new_b.current < new_b.capacity and new_a.current > 0){
            new_b.current += 1;
            new_a.current -= 1;
        }

        format.clear();
        format.push_back(new_a);
        format.push_back(new_b);
        format.push_back(c);
        queue.push_back(format);

        new_b = b;
        struct cup_state new_c = c;

        while (new_b.current < new_b.capacity and new_c.current > 0){
            new_b.current += 1;
            new_c.current -= 1;
        }

        format.clear();
        format.push_back(a);
        format.push_back(new_b);
        format.push_back(new_c);
        queue.push_back(format);
    }

    if (c_space != 0){
        struct cup_state new_c = c;
        struct cup_state new_a = a;

        while (new_c.current < new_c.capacity and new_a.current > 0){
            new_c.current += 1;
            new_a.current -= 1;
        }

        format.clear();
        format.push_back(new_a);
        format.push_back(b);
        format.push_back(new_c);
        queue.push_back(format);

        new_c = c;
        struct cup_state new_b = b;

        while (new_c.current < new_c.capacity and new_b.current > 0){
            new_c.current += 1;
            new_b.current -= 1;
        }

        format.clear();
        format.push_back(a);
        format.push_back(new_b);
        format.push_back(new_c);
        queue.push_back(format);
    }

    return solver(queue, explored, target);

}

int main(){

    std::vector<std::vector<struct cup_state>> queue;
    struct cup_state a;
    struct cup_state b;
    struct cup_state c;

    std::cout<<"Enter initial level and capacity for the three glasses, first initial then capacity and then do it for the other two struct cup_states\n";
    std::cin>>a.current>>a.capacity;
    std::cin>>b.current>>b.capacity;
    std::cin>>c.current>>c.capacity;

    if (a.capacity < a.current || b.capacity < b.current || c.capacity < c.current){
        std::cout<<"Invalid input\n";
        return 0;
    }

    std::cout<<"Enter Target: ";
    int target;
    std::cin>>target;

    std::vector<struct cup_state> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    queue.push_back(temp);

    std::vector<std::vector<struct cup_state>> explored;

    std::cout<<solver(queue, explored, target)<<std::endl;

    return 0;
}
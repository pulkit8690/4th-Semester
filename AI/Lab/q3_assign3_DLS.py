import sys
import copy
from generating_children import *
import copy
import config

def generate_children(t):
    
    s = t[0]
    curr_depth = t[1]
    
    #global visited
    
    children = []
    for i in range(len(s)):
        temp = copy.deepcopy(s)
        if len(temp[i]) > 0:
            elem = temp[i].pop()
            for j in range(len(temp)):
                temp1 = copy.deepcopy(temp)
                if j != i:
                    temp1[j] = temp1[j] + [elem]
                    
                    if (temp1 not in config.visited) and (temp1 not in config.temp_q):
                        config.temp_q += [temp1]
                        children += [(temp1,curr_depth+1)]
                        
    return children

import config   
q = []
visited = []
temp_q = []

depth = 1

def search(initial_state,final_state):
    
    if (initial_state[0] in final_state):
        print(final_state)
        print("solution found at the depth:-",initial_state[1])
        print("total number of states visited:-",len(config.visited))
        return
    
    curr_state = copy.deepcopy(initial_state)
    global depth
    while(1):

        if curr_state[1] <= depth:
            children = generate_children(curr_state)
            print(curr_state)
            print("------------")
        
            if (curr_state[0] == final_state):
                print(final_state)
                print("solution found at the depth:-",curr_state[1])
                print("total number of states visited:-",len(config.visited))
                return
        
            else:
                config.q += children
                
        if len(config.q) == 0:
            print("solution does not exists")
            print("current depth is",curr_state[1])
            print("total number of states visited:-",len(config.visited))
            return
        else:

            curr_state = config.q[len(config.q)-1]
            config.visited = config.visited + [curr_state]
            del config.q[len(config.q)-1]
            

def main():
    
    num_of_blocks = 3
    state = [[]]*num_of_blocks
    initial_state = [['B'],['A','C'],[]]
    final_state = [['A','B','C'],[],[]]

    config.visited = config.visited + [initial_state]
    
    search((initial_state,0),final_state)
    
    

if __name__ == "__main__":
    
    main()

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



def search(initial_state,final_state,depth):
    print("=========", depth)
    if (initial_state[0] in final_state):
        print(final_state)
        print("solution found at the depth:-",initial_state[1])
        print("total number of states visited:-",len(config.visited))
        return (1)
    
    curr_state = copy.deepcopy(initial_state)
    
    while(1):
        
        if curr_state[1] <= depth:
            children = generate_children(curr_state)
            print(curr_state)
            print("------------")
        
            if (curr_state[0] == final_state):
                print(final_state)
                print("solution found at the depth:-",curr_state[1])
                #print("total number of states visited:-",len(config.visited))
                return [1,len(config.visited)]
            else:
                config.q += children
        
        if len(config.q) == 0:
            print("solution does not exists")
            print("current depth is",curr_state[1])
            #print("total number of states visited:-",len(config.visited))
            return [0,len(config.visited)]
        else:

            curr_state = config.q[len(config.q)-1]
            config.visited = config.visited + [curr_state]
            del config.q[len(config.q)-1]
        

def main():
    
    num_of_blocks = 3
    state = [[]]*num_of_blocks
    initial_state = [['B'],['A','C'],[]]
    final_state = [['A','B','C'],[],[]]

    config.visited = config.visited + [(initial_state,0)]
    depth = 0
    total_states = 0
    
    while (1):
        config.q = []
        config.temp_q = []
        config.visited = []
        ans = search((initial_state,0),final_state,depth)
        if ans[0] == 1:
            print("total states visited",total_states+ans[1])
            exit()
        else:
            total_states += ans[1]
            depth += 1
        
    

if __name__ == "__main__":
    
    main()

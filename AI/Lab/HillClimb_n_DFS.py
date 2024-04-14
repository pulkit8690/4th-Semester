#Solve the following blocks world problem using Simple Hill Climbing Algorithm.
#Take the following heuristic function:
#+n for block which is resting on the current support structure and n is equal to number
# of blocks below it.
#-n for block which is resting on the incurrent support structure and n is equal to
# number of blocks below it.





import copy

visitedStates = []

countSteps = 0


def heuristic(curr_state,goalState):

    Target=goalState[3]
    
    val=0
    for i in range(len(curr_state)):
        check_val=curr_state[i]
        if len(check_val)>0:
            for j in range(len(check_val)):
                if check_val[j]!=Target[j]:
                    val-=j
                else:
                    val+=j
    return val          
def generate_next(curr_state,prev_heu,goalState):
    state = copy.deepcopy(curr_state)
    for i in range(len(state)):
    
        temp = copy.deepcopy(state)
        
        if len(temp[i]) > 0:
            elem = temp[i].pop()
            for j in range(len(temp)):
                
                temp1 = copy.deepcopy(temp)
                if j != i:
                
                    temp1[j].append(elem)
                    
                    if (temp1 not in visitedStates):
            
                        curr_heu=heuristic(temp1,goalState)
                        if curr_heu>prev_heu:
                            return temp1
    return 0

def solution_(init_state,goalState):
    global countSteps
    global visitedStates
    if (init_state == goalState):
        print (goalState)
        print("solution found!")
        return
    
    currentState = copy.deepcopy(init_state)
    
    while(True):
        visitedStates.append(copy.deepcopy(currentState))
        countSteps+=1
        display(currentState)
        prev_heu=heuristic(currentState,goalState)
        child = generate_next(currentState,prev_heu,goalState)
        if child==0:
            print("Final state - ",currentState)
            print("The procedure took ", countSteps, " steps")
            return
        currentState = copy.deepcopy(child)  

def display(curr):
    global countSteps
    print("Printing the step ",countSteps)
    for i in curr:
        for j in i:
            if len(j) > 0:
                print ( j ,end =' ')
        print()
    print("End of state")
    print ()

# inputs
init_state = [[],[],[],['B','C','D','A']]
goalState = [[],[],[],['A','B','C','D']]
    
solution_(init_state,goalState)
print ("*********END*********")

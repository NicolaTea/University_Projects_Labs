import numpy as np

def reward(s,a,snew):
    """
    Calculeaza recompensa pt o tranzitie intre stari

    :param s: starea initiala
    :param a: actiunea aleasa, tuplu (actiune aleasa,actiune executata)
    :param snew: noua stare dupa tranzitie
    :return: Recompensa asociata tranzitiei (s,a,snew)
    """

    if s==2 and a[1]=="left":
        return -100
    if s==4 and a[1]=="left":
        return 10

    if s==snew:
        return -1

    return 0

print(reward(2, ("left", "left"), 2))  # -100
print(reward(4, ("left", "left"), 4))  # 10
print(reward(0, ("right", "right"), 1))  # 0
print(reward(1, ("up", "upC"), 1)) # -1

print("----------------------------------------")

def performAction(s,a1):
    """
    Determina actiunea efectiv executata si noua stare

    :param s: starea initiala (0-5)
    :param a1: actiunea aleasa ("up","upC","left","right")
    :return: (actiunea executata,noua stare)
    """
    if a1 == "up":
        a_exec = np.random.choice(["upC", "left", "right"], p=[0.8, 0.1, 0.1])
    else:
        a_exec = a1

    transaction = {
        "upC": {0: 2, 1: 3, 2: 4, 3: 5, 4: 4, 5: 5},
        "left": {1: 0, 3: 2, 5: 4, 2: 2, 0: 0, 4: 4},
        "right": {0: 1, 2: 3, 4: 5, 1: 1, 3: 3, 5: 5}
    }

    snew = transaction[a_exec].get(s, s)
    return (a_exec, snew)



print(performAction(0, "up"))
print(performAction(2, "left"))
print(performAction(4, "right"))

print("----------------------------------------")

#gleichverteilt 100 Aktionen auswählen
a1s = np.random.choice(np.array(["up","upC","left","right"]),size=100,replace=True)

a1s
states = [0]
actions = []

#Berechne und speichere tatsächlich ausgeführte Aktionen, und Zustands-Folge
for i in range(len(a1s)):
    sanew = performAction(states[i],a1s[i])
    actions = actions + [(a1s[i],sanew[0])]
    states = states + [sanew[1]]

print(states)
print(actions)

print("----------------------------------------")

def qLearn(actions,states,gamma=0.5):
    """
    Aplica algoritmul Q-learning pt a invata o Q-Matrix

    :param actions: lista de perechi (actiune aleasa, actiune executata)
    :param states: lista de stari vizitate
    :param gamma: factorul de discount
    :return:  Matricea Q invatata
    """
    num_states=6
    num_actions=4
    action_map={"up":0,"upC":1,"left":2,"right":3}
    Q=np.zeros((num_states,num_actions))

    for i in range(len(actions)-1):
        s=states[i]
        a=actions[i][1]
        s_next=states[i+1]
        r=reward(s,actions[i],s_next)

        a_index=action_map[a]
        max_Q_next=np.max(Q[s_next])

        Q[s, a_index] = (1 - 0.1) * Q[s, a_index] + 0.1 * (r + gamma * max_Q_next)
    return Q
Q = qLearn(actions,states)
print(Q)
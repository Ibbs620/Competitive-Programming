graph = [[],[6],[6],[4,5,6,15],[3,5,6],[3,4,6],[1,2,3,4,5,7],[6,8],[7,9],[8,10,12],[9,11],[10,12],[9,11,13],[12,14,15],[13],[3,13],[17,18],[16,18],[16,17]]

def checkGraphTooSmall(x, y = 0):
    while max(x, y) >= len(graph):
        graph.append([])

def addFriend(x, y):
    checkGraphTooSmall(x,y)
    if y in graph[x]: return 1
    graph[x].append(y)
    graph[y].append(x)

def removeFriend(x, y):
    checkGraphTooSmall(x,y)
    if y not in graph[x]: return 1
    graph[x].remove(y)
    graph[y].remove(x)

def countFriends(x):
    checkGraphTooSmall(x)
    print(len(graph[x]))

def countFriendsOfFriends(x):
    checkGraphTooSmall(x)
    count = 0
    checked = []
    for i in graph[x]:
        for j in graph[i]:
            if j not in graph[x] and j != x and j not in checked:
                count += 1
                checked.append(j)
    print(count)

def degreesOfSeperation(x, y):
    checkGraphTooSmall(x,y)
    q = [x]
    visited = [False] * len(graph)
    visited[x] = True
    dist = [0] * len(graph)
    while(len(q) > 0 and not dist[y]):
        x = q[0]
        q.pop(0)
        for i in graph[x]:
            if not visited[i]:
                q.append(i)
                visited[i] = True
                dist[i] = dist[x] + 1
    print(dist[y] if dist[y] else "Not connected")

task = input()
while(task != 'q'):
    if task == 'i':
        x = int(input())
        y = int(input())
        addFriend(x,y)
    elif task == 'd':
        x = int(input())
        y = int(input())
        removeFriend(x,y)
    elif task == 'n':
        x = int(input())
        countFriends(x)
    elif task == 'f':
        x = int(input())
        countFriendsOfFriends(x)
    elif task == 's':
        x = int(input())
        y = int(input())
        degreesOfSeperation(x, y)
    elif task == 'l':
        x = int(input())
        checkGraphTooSmall(x)
        print(*graph[x])
    task = input()

import sys
import random
import os
from datetime import datetime
import math

def euclidean_distance(v1, v2):
    return math.sqrt((v1[0] - v2[0]) ** 2 + (v1[1] - v2[1]) ** 2)

def main():
    if len(sys.argv) != 4:
        print("Use: python3 generator.py <vertices> <edges> <portals>")
        return
    
    verticesNumber = int(sys.argv[1])
    edgesNumber = int(sys.argv[2])
    portalsNumber = int(sys.argv[3])
    
    maxEdgesAllowed = verticesNumber * (verticesNumber - 1)
    
    if (edgesNumber + portalsNumber) > maxEdgesAllowed:
        print("Use: max numbers of edges in a simple graph exceded")
        return
    
    # if (edgesNumber) < verticesNumber:
    #     print("Use: min number of edges allowed exceded")
    #     return
    
    vertices = set()
    
    min_distance = 5
    
    while len(vertices) < verticesNumber:
        x = verticesNumber * random.random()
        y = verticesNumber * random.random()
        if (x, y) not in vertices and all(euclidean_distance((x, y), v) >= min_distance for v in vertices):
            vertices.add((x,y))
            
    portals = set()
            
    while len(portals) < portalsNumber:
        v1 = random.randint(0, verticesNumber - 2)
        v2 = random.randint(1, verticesNumber - 1)
        if (v1, v2) not in portals and v1 != v2:
            portals.add((v1,v2))
            
    vertices = list(vertices)
    
    possible_edges = []
    for i in range(verticesNumber):
        for j in range(verticesNumber):
            if i != j and (i, j) not in portals:
                distance = euclidean_distance(vertices[i], vertices[j])
                possible_edges.append((distance, i, j))
    
    possible_edges.sort()
    
    edges = set()
    
    for i in range(0, len(possible_edges), 2):
        _, v1, v2 = possible_edges[i + random.randint(0, 1)]
        if len(edges) >= edgesNumber:
            break
        edges.add((v1, v2))
        
    while len(edges) < edgesNumber:
        v1 = random.randint(0, verticesNumber - 2)
        v2 = random.randint(1, verticesNumber - 1)
        if (v1, v2) not in edges and v1 != v2:
            edges.add((v1,v2))
    
            
    directory = 'tests/'
    
    os.makedirs(directory, exist_ok=True)

    # Obter a data atual e formatar
    date = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
    file = f'{directory}test_{date}.txt'


    with open(file, 'w') as f:
        f.write(f"{verticesNumber} {edgesNumber} {portalsNumber}\n")
        for vert in vertices:
            print(f"{vert[0]:.3f} {vert[1]:.3f}")
            f.write(f"{vert[0]:.3f} {vert[1]:.3f}\n")
        
        for edge in edges:
            print(f"{edge[0]} {edge[1]}")
            f.write(f"{edge[0]} {edge[1]}\n")
        
        for portal in portals:
            print(f"{portal[0]} {portal[1]}")
            f.write(f"{portal[0]} {portal[1]}\n")
        
if __name__ == "__main__":
    main()
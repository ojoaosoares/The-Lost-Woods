import sys
import random
import os
from datetime import datetime
import math

def euclidean_distance(v1, v2):
    return math.sqrt((v1[0] - v2[0]) ** 2 + (v1[1] - v2[1]) ** 2)

def generate_random_point_near(v, min_distance, max_distance):
    angle = random.uniform(0, 2 * math.pi)
    distance = random.uniform(min_distance, max_distance)
    x = v[0] + distance * math.cos(angle)
    y = v[1] + distance * math.sin(angle)
    return (x, y)

def main():
    if len(sys.argv) != 6 or (sys.argv[1] != 't' and sys.argv[1] != 'd'):
        print("Use: python3 generator.py <mode = i/d> <vertices> <edges> <portals> <seed>")
        print("Use: if you chose <i> the values of <edges> and <portals> must be integers values")
        print("Use: if you chose <d> the values of <edges> and <portals> must be percentage (between 0 and 1)")
        return
    
    seed = int(sys.argv[5])
    random.seed(seed)
    
    verticesNumber = int(sys.argv[2])
    maxEdgesAllowed = verticesNumber * (verticesNumber - 1)
    
    if (sys.argv[1] == 't'):
        edgesNumber = int(sys.argv[3]) - int(sys.argv[4])
        portalsNumber = int(sys.argv[4])
        
    elif (sys.argv[1] == 'd'):
        edgesNumber = int(float(sys.argv[3]) * maxEdgesAllowed * float((1 - float(sys.argv[4]))))
        portalsNumber = int(float(sys.argv[3]) * maxEdgesAllowed * float(sys.argv[4]))
        
    
        
    if (edgesNumber + portalsNumber) > maxEdgesAllowed:
        print("Use: max numbers of edges in a simple graph exceded")
        return
    
    vertices = list()
    
    min_distance = 20
    max_distance = 40
    
    x = verticesNumber * random.random()
    y = verticesNumber * random.random()
    vertices.append((x, y))
    
    while len(vertices) < verticesNumber:
        
        base_vertex = random.choice(vertices)
        # Gerar um novo ponto próximo ao vértice existente
        new_vertex = generate_random_point_near(base_vertex, min_distance, max_distance)
        
        if all(euclidean_distance(new_vertex, v) >= min_distance for v in vertices):
            vertices.append(new_vertex)
            
    portals = set()
    
    edges_count = list()
    
    for i in range(verticesNumber):
        edges_count.append((0, 0))
            
    while len(portals) < portalsNumber:
        v1 = random.randint(0, verticesNumber - 2)
        v2 = random.randint(1, verticesNumber - 1)
        if (v1, v2) not in portals and v1 != v2:
            portals.add((v1,v2))
            edges_count[v1] =  (edges_count[v1][0] + 1, edges_count[v1][1])
            edges_count[v2] = (edges_count[v2][0], edges_count[v2][1] + 1)
    
    possible_edges = []
    for i in range(verticesNumber):
        for j in range(i):
            if (i, j) not in portals:
                distance = euclidean_distance(vertices[i], vertices[j])
                possible_edges.append((distance, i, j))
            elif (j, i) not in portals:
                distance = euclidean_distance(vertices[j], vertices[i])
                possible_edges.append((distance, j, i))
    
    possible_edges.sort()
    
    edges = set()
    
    for i in range(len(possible_edges)):
        _, v1, v2 = possible_edges[i]
        if len(edges) >= edgesNumber:
            break
        if (abs(edges_count[v1][0] - edges_count[v1][1] + 1) + abs(edges_count[v2][0] - edges_count[v2][1] - 1) < abs(edges_count[v1][0] - edges_count[v1][1] - 1) + abs(edges_count[v2][0] - edges_count[v2][1] + 1)) or (v2, v1) in portals:
            edges.add((v1, v2))
            edges_count[v1] =  (edges_count[v1][0] + 1, edges_count[v1][1])
            edges_count[v2] = (edges_count[v2][0], edges_count[v2][1] + 1)
        else:
            edges.add((v2, v1))
            edges_count[v2] =  (edges_count[v2][0] + 1, edges_count[v2][1])
            edges_count[v1] = (edges_count[v1][0], edges_count[v1][1] + 1)
            
    
    for i in range(len(possible_edges)):
        
        _, v1, v2 = possible_edges[i]
        if len(edges) >= edgesNumber:
            break
        if (v1, v2) not in edges and (v1, v2) not in portals:
            edges.add((v1, v2))
            edges_count[v1] =  (edges_count[v1][0] + 1, edges_count[v1][1])
            edges_count[v2] = (edges_count[v2][0], edges_count[v2][1] + 1)
        elif (v2, v1) not in edges and (v2, v1) not in portals:
            edges.add((v2, v1))
            edges_count[v2] =  (edges_count[v2][0] + 1, edges_count[v2][1])
            edges_count[v1] = (edges_count[v1][0], edges_count[v1][1] + 1)
        
    
    
            
    directory = 'tests/'
    
    os.makedirs(directory, exist_ok=True)

    # Obter a data atual e formatar
    date = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
    file = f'{directory}test_{verticesNumber}_{edgesNumber}_{portalsNumber}_{date}.txt'


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
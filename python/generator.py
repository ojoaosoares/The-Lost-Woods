import sys
import random

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
    
    vertices = set()
    
    while len(vertices) < verticesNumber:
        x = verticesNumber * random.random()
        y = verticesNumber * random.random()
        if (x, y) not in vertices:
            vertices.add((x,y))
            
    edges = set()
    
    while len(edges) < edgesNumber:
        v1 = random.randint(0, verticesNumber - 1)
        v2 = random.randint(0, verticesNumber - 1)
        if (v1, v2) not in edges:
            edges.add((v1,v2))
            
    portals = set()
            
    while len(portals) < portalsNumber:
        v1 = random.randint(0, verticesNumber - 1)
        v2 = random.randint(0, verticesNumber - 1)
        if (v1, v2) not in edges and (v1, v2) not in portals:
            portals.add((v1,v2))
            
    for vert in vertices:
        print(f"{vert[0]:.3f} {vert[1]:.3f}")
        
    for edge in edges:
        print(f"{edge[0]} {edge[1]}")
    
    for portal in portals:
        print(f"{portal[0]} {portal[1]}")
        
if __name__ == "__main__":
    main()
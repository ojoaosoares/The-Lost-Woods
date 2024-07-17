import sys
import networkx as nx
import matplotlib.pyplot as plt
import os
from datetime import datetime

def main():
    if len(sys.argv) != 2:
        print("Use: python3 creategraph.py <filename>")
        return
    
    with open(sys.argv[1], 'r') as file:
        lines = file.readlines()
        
    verticesNumber, edgesNumber, portalsNumber = map(int, lines[0].split())
    
    G = nx.DiGraph()
    
    for i in range(1, verticesNumber + 1):
        x, y = map(float, lines[i].split())
        G.add_node(i - 1, pos=(x, y))
        
    for i in range(verticesNumber + 1, verticesNumber + 1 + edgesNumber):
        v1, v2 = map(float, lines[i].split())
        G.add_edge(v1, v2, color='blue')
        
    for i in range(verticesNumber + 1 + edgesNumber, verticesNumber + 1 + edgesNumber + portalsNumber):
        v1, v2 = map(float, lines[i].split())
        G.add_edge(v1, v2, color='red')
        
        
        
    pos = nx.get_node_attributes(G, 'pos')

    # Obter cores das arestas para visualização
    cores = [G[u][v]['color'] for u, v in G.edges()]

    # Desenhar o grafo
    plt.figure(figsize=(8, 6))
    nx.draw(G, pos, with_labels=True, edge_color=cores, node_color='lightblue', node_size=500, font_size=10, font_color='black')
    nx.draw_networkx_edges(G, pos, edge_color=cores, arrowstyle='->', arrowsize=20)
    plt.title('Graph')
    # plt.show()
    
    directory = 'graphs/'

    os.makedirs(directory, exist_ok=True)

    # Obter a data atual e formatar
    date = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
    file = f'{directory}graph_{verticesNumber}_{edgesNumber}_{portalsNumber}_{date}.png'
        
    plt.savefig(file)

if __name__ == "__main__":
    main()        
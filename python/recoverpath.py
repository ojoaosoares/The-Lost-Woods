import sys
import networkx as nx
import matplotlib.pyplot as plt
import os
from datetime import datetime

def main():
    if len(sys.argv) != 2:
        print("Use: python3 recoverpath.py  ")
        return
    
    with open(sys.argv[1], 'r') as file:
        lines = file.readlines()
        
    verticesNumber, edgesNumber, portalsNumber = map(int, lines[0].split())
    
    G = nx.DiGraph()
    
    for i in range(1, verticesNumber + 1):
        x, y = map(float, lines[i].split())
        G.add_node(i - 1, pos=(x, y))
        
    for i in range(verticesNumber + 1, verticesNumber + 1 + edgesNumber):
        v1, v2 = map(int, lines[i].split())
        G.add_edge(v1, v2, color='blue')
        
    for i in range(verticesNumber + 1 + edgesNumber, verticesNumber + 1 + edgesNumber + portalsNumber):
        v1, v2 = map(int, lines[i].split())
        G.add_edge(v1, v2, color='red')
        
    # Supondo que o caminho é a última linha do arquivo
    path = list(map(int, lines[verticesNumber + 1 + edgesNumber + portalsNumber].split()))
    
    # Criar um subgrafo que contém apenas os nós e arestas no caminho
    path_edges = [(path[i], path[i+1]) for i in range(len(path) - 1)]
    subgraph = G.edge_subgraph(path_edges).copy()
    
    pos = nx.get_node_attributes(G, 'pos')
    subgraph_pos = {node: pos[node] for node in subgraph.nodes()}
    
    # Obter cores das arestas do subgrafo a partir do grafo original
    cores = [G[u][v]['color'] for u, v in subgraph.edges()]
    
    # Desenhar o subgrafo
    plt.figure(figsize=(8, 6))
    nx.draw(subgraph, subgraph_pos, with_labels=True, edge_color=cores, node_color='lightblue', node_size=500, font_size=10, font_color='black')
    nx.draw_networkx_edges(subgraph, subgraph_pos, edge_color=cores, arrowstyle='->', arrowsize=20)
    plt.title(f'Subgraph with path from {verticesNumber} vertices, {edgesNumber} edges, and {portalsNumber} portals')
    
    directory = 'graphs/'

    os.makedirs(directory, exist_ok=True)

    # Obter a data atual e formatar
    date = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
    file = f'{directory}path_{verticesNumber}_{edgesNumber}_{portalsNumber}_{date}.png'
        
    plt.savefig(file)

if __name__ == "__main__":
    main()

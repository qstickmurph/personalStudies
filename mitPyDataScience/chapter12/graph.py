class Node(object):
    def __init__(self, name):
        """Assumes name is string"""
        self.name = name

    def getName(self):
        return self.name

    def __str__(self):
        return self.name

class Edge(object):
    def __init__(self, src, dest):
        """Assumes src and dest are Nodes"""
        self.src = src
        self.dest = dest
    
    def getSource(self):
        return self.src

    def getDestination(self):
        return self.dest

    def __str__(self):
        return self.src.getName() + '->' + self.dest.getName()

class WeightedEdge(Edge):
    def __init__(self, src, dest, weight):
        super().__init__(self, src, dest)
        self.weight = weight

    def getWeight(self):
        return self.weight

    def __str__(self):
        return self.src.getName() + '-(' + str(self.weight) + '->' + self.dest.getName()

class Digraph(object):
    """Nodes is a list of the notes in the graph
        Edges is a dict mapping each node to a list of it's children"""
    
    def __init__(self, nodes = [], edges = {}):
        self.nodes = nodes
        self.edges = edges

    def addNode(self, node):
        if node in self.nodes:
            raise ValueError('Duplicate Node')
        else:
            self.nodes.append(node)
            self.edges[node] = []

    def addEdge(self, edge):
        src = edge.getSource()
        dest = edge.getDestination()
        if not (src in self.nodes and dest in self.nodes):
            raise ValueError('Node not in graph')
        self.edges[src].append(dest)

    def getChildren(self, node):
        return self.edges[node]

    def hasNode(self, node):
        return node in self.nodes

    def __str__(self):
        result = ''
        for src in self.nodes:
            for dest in self.edges[src]:
                result = result + src.getName() + '->' + dest.getName() + '\n'
        return result[:-1]

class Graph(Digraph):
    def addEdge(self, edge):
        super().addEdge(self, edge)
        rev = Edge(edge.getDestination(), edge.getSource())
        super().addEdge(self, rev)

from collections import defaultdict

class Graph:

	def __init__(self,vertices):
		self.S= vertices
		self.graph = defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def find_parent(self, parent,i):
		if parent[i] == -1:
			return i
		if parent[i]!= -1:
			return self.find_parent(parent,parent[i])

	def union(self,parent,a,b):
		parent[a] = b

	def isCyclic(self):
		
	
		parent = [-1]*(self.S)

		for i in self.graph:
			for j in self.graph[i]:
				a = self.find_parent(parent, i)
				b = self.find_parent(parent, j)
				if a == b:
					return True
				self.union(parent,a,b)



g = Graph(5)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 1)
g.addEdge(0, 2)


if g.isCyclic():
	print ("Graph it contains cycle")
else :
	print ("Graph it does not contain cycle ")



## Disjoint Set

class disjoint_set:
    def __init__(self, n):
        self.parent = [i for i in range(n)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        
        ## Path compression
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        a = self.find(x)
        b = self.find(y)
        self.parent[b] = a

class Disjoint_Set:
    def __init__(self,)
        
def main():
    ds_obj = disjoint_set(5)
    ds_obj.union(1, 2)
    ds_obj.union(1, 3)
    ds_obj.union(0, 4)
    print(ds_obj.find(4))
    print(ds_obj.parent)

main()



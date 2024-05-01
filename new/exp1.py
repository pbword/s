class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def _hash(self, key):
        return key % self.size

    # Separate Chaining
    def insert_sc(self, key):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = [key]
        else:
            if key not in self.table[index]:
                self.table[index].append(key)

    def lookup_sc(self, key):
        index = self._hash(key)
        comparisons = 0
        if self.table[index] is not None:
            for k in self.table[index]:
                comparisons += 1
                if k == key:
                    return key, comparisons
        return None, comparisons


    # Linear Probing (Open Addressing)
    def insert_lp(self, key):
        index = self._hash(key)
        while self.table[index] is not None:
            if self.table[index] == key:
                return
            index = (index + 1) % self.size
        self.table[index] = key

    def lookup_lp(self, key):
        index = self._hash(key)
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index] == key:
                return key, comparisons
            index = (index + 1) % self.size
        return None, comparisons


    def print_table(self):
        for i, entry in enumerate(self.table):
            print(f"Index {i}: {entry}")

SIZE = 100

method = int(input("Enter 1 for chaining method \nEnter 2 for linear probing method\n"))

if (method == 1):
    ht = HashTable(SIZE)
    insert = ht.insert_sc
    lookup = ht.lookup_sc

elif (method == 2):
    ht = HashTable(SIZE)
    insert = ht.insert_lp
    lookup = ht.lookup_lp
else:
    print("Please enter a valid method!")
        
while (1):
    choice = int(input("Enter 1 to insert a Phone Number in the directory \nEnter 2 to search a Phone Number in the directory \nEnter 3 to Print the directory \nEnter 4 to quit \n"))
    
    if (choice == 1):
        n = int(input("Enter the count of Phone Numbers to be inserted-\n"))
        for i in range(n):
            x = int(input("Enter the Phone Number to be inserted-\n"))
            if (len(str(x)) != 10):
                print("Please enter a valid number!")
            else:
                insert(x)
    
    elif (choice == 2):
        x = int(input("Enter the Phone Number to be searched in the directory-\n"))
        result = lookup(x)
        if result is not None:
            print("Phone Number found in the directory! Number of comparisons made: ", result[1])
        else:
            print("Phone Number not present in the directory!")

    elif (choice == 3):
        ht.print_table()

    elif (choice == 4):
        break
    else:
        print("Please Enter a valid choice!")

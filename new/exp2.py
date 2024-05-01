class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def _hash(self, key):
        return key % self.size

    def insert_without_replacement(self, key, value):
        index = self._hash(key)
        node = self.table[index]
        if node is None:
            self.table[index] = Node(key, value)
            return
        while node:
            if node.key == key:
                node.value = value
                return
            prev = node
            node = node.next
        prev.next = Node(key, value)

    def insert_with_replacement(self, key, value):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = Node(key, value)
            return
        elif self.table[index].key == key:
            self.table[index].value = value
            return
        else:
            old_key, old_value = self.table[index].key, self.table[index].value
            self.table[index].key, self.table[index].value = key, value
            self.insert_with_replacement(old_key, old_value)

    def find(self, key):
        index = self._hash(key)
        node = self.table[index]
        if node and node.key == key:
            return node.value
        return None

    def delete(self, key):
        index = self._hash(key)
        if self.table[index] and self.table[index].key == key:
            self.table[index] = None


# Driver code
def print_hash_table(hash_table):
    for i, node in enumerate(hash_table.table):
        print(f'Index {i}:', end=' ')
        while node:
            print(f'({node.key}, {node.value})', end=' -> ')
            node = node.next
        print('None')

hash_table = HashTable(10)

while True:
    print("\n1. Use chaining with replacement")
    print("2. Use chaining without replacement")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        insert_method = hash_table.insert_with_replacement
        break
    elif choice == 2:
        insert_method = hash_table.insert_without_replacement
        break
    else:
        print("Invalid choice. Please enter a valid option.")

while True:
    print("\n1. Insert key-value pair")
    print("2. Find value by key")
    print("3. Delete by key")
    print("4. Print HashTable")
    print("5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        key = int(input("Enter key: "))  # keys are integers
        value = int(input("Enter value: "))
        insert_method(key, value)
    elif choice == 2:
        key = int(input("Enter key: "))  # keys are integers
        print(f'Value: {hash_table.find(key)}')
    elif choice == 3:
        key = int(input("Enter key: "))  # keys are integers
        hash_table.delete(key)
    elif choice == 4:
        print_hash_table(hash_table)
    elif choice == 5:
        break
    else:
        print("Invalid choice. Please enter a valid option.")

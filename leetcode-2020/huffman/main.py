import sys

class Letter:
    def __init__(self,letter, freq):
        self.letter=letter
        self.freq=freq
        self.bitstring=""
    
class TreeNode:
    def __init__(self, freq, left, right):
        super().__init__()
        self.freq=freq
        self.left=left
        self.right=right

def parse_file(file_path):
    chars = {}

    with open(file_path) as f:
        while True:
            c = f.read(1)
            if not c:
                break
            chars[c] = chars[c]+1 if c in chars.keys() else 1
    
    return sorted([Letter(l,f) for l,f in chars.items()], key= lambda l: l.freq)

def build_tree(letters):
    while len(letters)>1:
        left = letters.pop(0)
        right = letters.pop(0)
        node = TreeNode(left.freq+right.freq,left, right)
        letters.append(node)
        letters.sort(key = lambda node: node.freq)
    return letters[0]

def encode(node, bitstring):
    if type(node) is Letter:
        return node.bitstring
    
    ans = []
    ans += encode(node.left, bitstring+'0')
    ans += encode(node.right, bitstring+'1')
    return ans

def huffman(file_path):
    letters = parse_file(file_path)
    root = build_tree(letters)
    encode_table = encode(root, "")
    print(f"Huffman Coding of {file_path}: ")

    with open(file_path) as f:
        while True:
            c = f.read(1)
            if not c:
                break
            le = list(filter(lambda l: l.letter == c, encode_table))[0]
            print(le.bitstring, end=" ")

if __name__ == "__main__":
    huffman(sys.argv[1])


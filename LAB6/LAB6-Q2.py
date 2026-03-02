import random
import string
import heapq
import matplotlib.pyplot as plt
from collections import Counter


class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_huffman_tree(freq_dict):
    heap = []

    for ch, fr in freq_dict.items():
        heapq.heappush(heap, Node(ch, fr))

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(heap, merged)

    return heap[0]

def generate_codes(node, prefix="", codebook={}):
    if node is None:
        return

    if node.char is not None:
        codebook[node.char] = prefix
        return

    generate_codes(node.left, prefix + "0", codebook)
    generate_codes(node.right, prefix + "1", codebook)

def huffman_bits(freq_dict, codebook):
    bits = 0
    for ch, fr in freq_dict.items():
        bits += fr * len(codebook[ch])
    return bits

def generate_random_text(size):
    alphabet = string.ascii_lowercase + " "
    return ''.join(random.choice(alphabet) for _ in range(size))


sizes = [50, 100, 200, 400, 800, 1600]

huffman_results = []
fixed_results = []

for s in sizes:
    text = generate_random_text(s)

    freq = Counter(text)
    tree = build_huffman_tree(freq)

    codebook = {}
    generate_codes(tree, "", codebook)

    huff_bits = huffman_bits(freq, codebook)

    fixed_bits = s * 5

    huffman_results.append(huff_bits)
    fixed_results.append(fixed_bits)

    print(f"Text size: {s}")
    print(f"Huffman bits: {huff_bits}")
    print(f"Fixed bits: {fixed_bits}")
    print("-" * 40)

plt.figure(figsize=(12, 10))
plt.plot(sizes, huffman_results, marker='o', label="Huffman Bits")
plt.plot(sizes, fixed_results, marker='s', label="Fixed-Length Bits")

plt.xlabel("Text Size")
plt.ylabel("Bits Required")

plt.title("Huffman Encoding vs Fixed-Length Encoding")
plt.grid(True, linestyle="--")
plt.legend()
plt.show()

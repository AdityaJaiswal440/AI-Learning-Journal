import pandas as pd
import matplotlib.pyplot as plt

# Load the data
df = pd.read_csv('sort_results.csv')

# Create a 2x2 grid for the 4 required parameters
fig, axes = plt.subplots(2, 2, figsize=(14, 10))
fig.suptitle('DAA Lab 1: Performance Comparison of Sorting Algorithms', fontsize=16)

metrics = [
    ('Passes', axes[0, 0]),
    ('Comparisons', axes[0, 1]),
    ('Swaps', axes[1, 0]),
    ('Time', axes[1, 1])
]

for label, ax in metrics:
    for algo in df['Algorithm'].unique():
        data = df[df['Algorithm'] == algo]
        ax.plot(data['Size'], data[label], marker='o', label=algo)
    
    ax.set_title(f'{label} vs Array Size')
    ax.set_xlabel('Array Size')
    ax.set_ylabel(label)
    ax.legend()
    ax.grid(True, linestyle='--', alpha=0.6)

plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.savefig('sorting_graphs.png')
print("Graphs generated and saved as 'sorting_graphs.png'")
plt.show()
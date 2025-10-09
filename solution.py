# Python 3 — Corrected HLD + Binary Search Solution for 2155F
import sys
from collections import defaultdict
import bisect


def main():
    input_data = sys.stdin.read().split()
    index = 0
    if index >= len(input_data):
        raise IndexError("No input data")
    t = int(input_data[index])
    index += 1
    outputs = []

    for _ in range(t):
        # Read test case parameters
        if index + 3 >= len(input_data):
            raise IndexError("Insufficient input for n, k, s, q")
        n = int(input_data[index])
        k = int(input_data[index + 1])
        s = int(input_data[index + 2])
        q = int(input_data[index + 3])
        index += 4

        # Build adjacency list
        adj = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            if index + 1 >= len(input_data):
                raise IndexError("Insufficient input for edges")
            u = int(input_data[index])
            v = int(input_data[index + 1])
            index += 2
            adj[u].append(v)
            adj[v].append(u)

        # Read color assignments
        node_colors = [set() for _ in range(n + 1)]
        color_nodes = defaultdict(list)
        for _ in range(s):
            if index + 1 >= len(input_data):
                raise IndexError("Insufficient input for colors")
            v = int(input_data[index])
            c = int(input_data[index + 1])
            index += 2
            node_colors[v].add(c)
            color_nodes[c].append(v)

        # HLD preparation
        parent = [0] * (n + 1)
        depth = [0] * (n + 1)
        size = [0] * (n + 1)
        heavy = [0] * (n + 1)

        def dfs_size(u, p):
            parent[u] = p
            depth[u] = depth[p] + 1
            size[u] = 1
            max_size = 0
            for v in adj[u]:
                if v != p:
                    dfs_size(v, u)
                    size[u] += size[v]
                    if size[v] > max_size:
                        max_size = size[v]
                        heavy[u] = v

        dfs_size(1, 0)

        head = [0] * (n + 1)
        pos = [0] * (n + 1)
        cur_pos = 0

        def hld(u, p, chain):
            nonlocal cur_pos
            head[u] = chain
            pos[u] = cur_pos
            cur_pos += 1
            if heavy[u]:
                hld(heavy[u], u, chain)
            for v in adj[u]:
                if v != p and v != heavy[u]:
                    hld(v, u, v)

        hld(1, 0, 1)

        # Store sorted positions for each color
        color_pos = {}
        for c, nodes in color_nodes.items():
            color_pos[c] = sorted(pos[node] for node in nodes)

        # Binary lifting for LCA
        LOG = 20  # log2(3e5) ~ 18
        up = [[0] * (n + 1) for _ in range(LOG)]
        up[0] = parent[:]
        for j in range(1, LOG):
            for i in range(1, n + 1):
                up[j][i] = up[j - 1][up[j - 1][i]]

        def get_lca(u, v):
            if depth[u] > depth[v]:
                u, v = v, u
            diff = depth[v] - depth[u]
            for j in range(LOG):
                if diff & (1 << j):
                    v = up[j][v]
            if u == v:
                return u
            for j in range(LOG - 1, -1, -1):
                if up[j][u] != up[j][v]:
                    u = up[j][u]
                    v = up[j][v]
            return parent[u]

        # Count nodes with color c on path u-v
        def count_on_path(u, v, c_positions):
            count = 0
            while head[u] != head[v]:
                if depth[head[u]] < depth[head[v]]:
                    u, v = v, u
                l = pos[head[u]]
                r = pos[u]
                left = bisect.bisect_left(c_positions, l)
                right = bisect.bisect_right(c_positions, r)
                count += right - left
                u = parent[head[u]]
            l = min(pos[u], pos[v])
            r = max(pos[u], pos[v])
            left = bisect.bisect_left(c_positions, l)
            right = bisect.bisect_right(c_positions, r)
            count += right - left
            return count

        # Process queries
        answers = [0] * q
        for qi in range(q):
            if index + 1 >= len(input_data):
                raise IndexError("Insufficient input for queries")
            u = int(input_data[index])
            v = int(input_data[index + 1])
            index += 2
            lca_node = get_lca(u, v)
            path_len = depth[u] + depth[v] - 2 * depth[lca_node] + 1
            colors = node_colors[u] & node_colors[v]
            count = 0
            for c in colors:
                if count_on_path(u, v, color_pos.get(c, [])) == path_len:
                    count += 1
            answers[qi] = count

        outputs.append(" ".join(map(str, answers)))

    print("\n".join(outputs))

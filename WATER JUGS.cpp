#PYTHON 
from collections import deque

def min_steps_to_reach_target(a, b, c):
    visited = set()
    q = deque([(0, 0, 0)])  # (jug A, jug B, steps)

    while q:
        jug_a, jug_b, steps = q.popleft()

        if jug_a == c or jug_b == c:
            return steps

        if (jug_a, jug_b) in visited:
            continue

        visited.add((jug_a, jug_b))

        # Fill jug A
        q.append((a, jug_b, steps + 1))
        # Fill jug B
        q.append((jug_a, b, steps + 1))
        # Empty jug A
        q.append((0, jug_b, steps + 1))
        # Empty jug B
        q.append((jug_a, 0, steps + 1))
        # Pour from A to B
        pour = min(jug_a, b - jug_b)
        q.append((jug_a - pour, jug_b + pour, steps + 1))
        # Pour from B to A
        pour = min(jug_b, a - jug_a)
        q.append((jug_a + pour, jug_b - pour, steps + 1))

    return -1

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    result = min_steps_to_reach_target(a, b, c)
    print(result)


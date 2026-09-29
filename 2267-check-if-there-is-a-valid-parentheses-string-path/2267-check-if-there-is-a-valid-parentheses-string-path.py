class Solution:
    def hasValidPath(self, grid):
        m = len(grid)
        n = len(grid[0])

        # Path length must be even
        if (m + n - 1) % 2 != 0:
            return False

        # Start must be '(' and end must be ')'
        if grid[0][0] != '(' or grid[m - 1][n - 1] != ')':
            return False

        memo = {}

        def dfs(i, j, balance):

            # Update balance
            if grid[i][j] == '(':
                balance += 1
            else:
                balance -= 1

            # Invalid balance
            if balance < 0:
                return False

            # Remaining cells are not enough to close '('
            remaining = (m - 1 - i) + (n - 1 - j)

            if balance > remaining:
                return False

            # Destination
            if i == m - 1 and j == n - 1:
                return balance == 0

            state = (i, j, balance)

            if state in memo:
                return memo[state]

            # Move down
            down = False
            if i + 1 < m:
                down = dfs(i + 1, j, balance)

            # Move right
            right = False
            if j + 1 < n:
                right = dfs(i, j + 1, balance)

            memo[state] = down or right

            return memo[state]

        return dfs(0, 0, 0)
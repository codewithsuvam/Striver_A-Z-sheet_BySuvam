class Solution:
    def validSequence(self, word1: str, word2: str):
        n = len(word1)
        m = len(word2)

        # suffix[i] = maximum number of characters of word2
        # that can be matched starting from word1[i:]
        suffix = [0] * (n + 1)

        j = m - 1
        for i in range(n - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                suffix[i] = suffix[i + 1] + 1
                j -= 1
            else:
                suffix[i] = suffix[i + 1]

        ans = []
        j = 0
        changed = False

        for i in range(n):
            if j == m:
                break

            # If current character matches
            if word1[i] == word2[j]:
                ans.append(i)
                j += 1

            # Use our one allowed modification
            elif not changed:
                # After changing word1[i] to word2[j],
                # the remaining characters must be matchable.
                if suffix[i + 1] >= m - j - 1:
                    ans.append(i)
                    j += 1
                    changed = True

        if j == m:
            return ans

        return []
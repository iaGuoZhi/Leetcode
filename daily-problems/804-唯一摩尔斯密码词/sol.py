MORSE = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
         "....", "..", ".---", "-.-", ".-..", "--", "-.",
         "---", ".--.", "--.-", ".-.", "...", "-", "..-",
         "...-", ".--", "-..-", "-.--", "--.."]

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        return len(set("".join(MORSE[ord(c) - ord('a')] for c in word) for word in words))

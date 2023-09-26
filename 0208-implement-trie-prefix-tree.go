// NOTE
// 1. Ensure terminal flag is set properly.
// 2. Avoid overwriting terminal flag.
// 3. Distinguish  prefix and target.
// 4. Keep the relationship between Trie tree and the word.

type Trie struct {
	children map[rune]*Trie
	terminal bool
}

func Constructor() Trie {
	return Trie{
		children: make(map[rune]*Trie, 26),
	}
}
func (this *Trie) Insert(word string) {
	for _, ch := range word {
		if this.children[ch] == nil {
			this.children[ch] = &Trie{
				children: make(map[rune]*Trie, 26),
				// PROBLEM: Inserted Trie node leads to unset terminal flag.
				// this.terminal = len(word) == 1
				terminal: false,
			}
		}
		// Ensure terminal flag is set.
		// Corner Cache:
		//     1. Insert(Apple)
		//     2. Insert(App)

		// PROBLEM: Overwrite the terminal falg.
		// this.children[ch].terminal = len(word) == 1
		if len(word) == 1 {
			this.children[ch].terminal = true
		}
		this.children[ch].Insert(word[1:])
		break
	}
}

func (this *Trie) Search(word string) bool {
	for _, ch := range word {
		child := this.children[ch]
		if child == nil {
			return false
		}
		return child.Search(word[1:])
	}
	return this.terminal
}

func (this *Trie) StartsWith(prefix string) bool {
	for _, ch := range prefix {
		child := this.children[ch]
		if child == nil {
			return false
		}
		return child.StartsWith(prefix[1:])
	}
  // terminal(target) or non-terminal(prefix)
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */

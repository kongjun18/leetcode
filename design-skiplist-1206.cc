class Skiplist {
private:
    static const int max_level = 12;
    int level_;
    int vector<Skiplist*> forward_;
    int val_;
public:
    explicit Skiplist() : level_(0), forward({nullptr}), val_(0) {

    }
    SKiplist(int level, Skiplist* forward, int val): level_(level), forward_(forward), val_(val)
    {

    }

    bool searchImpl(int target) pair<Skiplist*, Skiplist*>{
        int level = level_;
        Skiplist *presessor = this;
        Skiplist *curr = presessor->forward_[level];
        while (level) {
            if (!curr || curr->val_ >= target) {
                level--;
                continue;
            }
            curr = curr->forward_[level];
        }
        return {presessor, curr};
    }
    bool search(int target) {
        const auto [_, curr] = searchImpl(target);
        return curr != nullptr;
    }

    void add(int num) {
        const auto [presessor, target] = searchImpl(num);
        //  不存在
        if (!target || target->val_ > num) {

        }
        // 存在多个相同值，正常插入
    }

    bool erase(int num) {

    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

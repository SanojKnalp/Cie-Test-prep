class ObjectTracker {
private:
    // Static member to track total instances (Topic 5)
    static int globalCount;
    
    // Mutable member to track reads even in 'const' functions (Lecture 6, p. 1)
    mutable int accessCount;
    int id;

public:
    ObjectTracker(int i) : id(i), accessCount(0) {
        // TODO: Increment globalCount
    }

    ~ObjectTracker() {
        // TODO: Decrement globalCount
    }

    // Const function that modifies a mutable member
    int getId() const {
        // TODO: Increment accessCount and return id
        return id;
    }

    int getAccessCount() const { return accessCount; }
    static int getGlobalCount() { return globalCount; }
};

// Initialize static member outside class (Important for Exam!)
int ObjectTracker::globalCount = 0;
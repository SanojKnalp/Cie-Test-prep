#include <iostream>
#include <algorithm>

class Particle {
protected:
    int id;
public:
    Particle(int i) : id(i) {}
    virtual ~Particle() {}
    virtual double getWeight() const = 0;
    int getId() const { return id; }
};

class HeavyParticle : public Particle {
private:
    double mass;
public:
    HeavyParticle(int i, double m) : Particle(i), mass(m) {}
    double getWeight() const override { return mass * 9.81; }
};

class System {
private:
    Particle** list;
    int count;
    int capacity;

public:
    System(int cap) : capacity(cap), count(0) {
        list = new Particle*[capacity];
    }

    // --- TASK: IMPLEMENT THE RULE OF THREE ---
    
    // 1. Destructor
    ~System() {
        // TODO: Delete each particle AND the list itself
    }

    // 2. Copy Constructor (Deep Copy)
    System(const System& other) : capacity(other.capacity), count(other.count) {
        list = new Particle*[capacity];
        for (int i = 0; i < count; ++i) {
            // For the exam: Assume all particles are HeavyParticles.
            // Create a NEW HeavyParticle based on the old one's data.
            // Hint: You'd need a getter for 'mass' or a clone() method, 
            // but for this test, just copy the logic.
        }
    }

    // 3. Assignment Operator
    System& operator=(const System& other) {
        if (this != &other) {
            // TODO: Delete old memory, allocate new, copy data
        }
        return *this;
    }

    void addHeavy(int id, double m) {
        if (count < capacity) {
            list[count++] = new HeavyParticle(id, m);
        }
    }

    double calcTotalWeight() const {
        double total = 0;
        for (int i = 0; i < count; ++i) {
            total += list[i]->getWeight();
        }
        return total;
    }
};
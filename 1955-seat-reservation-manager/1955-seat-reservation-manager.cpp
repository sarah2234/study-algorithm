class SeatManager {
private:
    int seatPointer;
    vector<bool> seats;
    std::priority_queue<int, std::vector<int>, std::greater<int>> unresearvedSeats;

public:
    SeatManager(int n) {
        seatPointer = 1;
        seats.resize(n + 1);
    }
    
    int reserve() {
        if (!unresearvedSeats.empty()) {
            int num = unresearvedSeats.top();
            unresearvedSeats.pop();
            seats[num] = true;
            return num;
        }
        
        seats[seatPointer] = true;
        
        return seatPointer++;
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber] = false;
        unresearvedSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
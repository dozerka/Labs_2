class Animal {
private:
    std::string type, size, color;
    int pawsCount;
public:
    void setData();
    int mutation();
    void getData();
    void rename();
    bool checkMutation();
};

struct RopeNode {
	RopeNode
}

struct Leaf {
	string value;
	int length;
	Leaf(string value, int length): value(value), length(length) {}
};
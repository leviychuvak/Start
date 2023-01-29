#include <iostream>
#include <memory>

template<typename T>
struct Node
{
	T value;
	std::unique_ptr<Node<T>> left;
	std::unique_ptr<Node<T>> right;
	Node(T aValue) : value{ std::move(aValue) } {}
};

template<typename T>
class Tree {
private:
	std::unique_ptr<Node<T>> root;
	void add(T arg, std::unique_ptr<Node<T>>& node) {
		if (!node) {
			node = std::make_unique<Node<T>>(arg);
			return;
		}
		if (arg < node->value)
			add(arg, node->left);
		else if (arg > node->value)
			add(arg, node->right);
	}
	template<typename Func>
	void traverse(Func funct, std::unique_ptr<Node<T>>& node) {
		if (!node) return;
		funct(node->value);
		traverse(funct, node->left);
		traverse(funct, node->right);
	}
public:
	Tree() = default;
	void add(T arg) {
		add(arg, root);
	}
	template<typename Func>
	void traverse(Func funct) {
		traverse(funct, root);
	}
};

int main()
{
	srand(time(0));
	Tree<int> t;

	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 10;
		std::cout << temp << " ";
		t.add(temp);
	}
	std::cout << std::endl;
	t.traverse([](const auto& x) {
		std::cout << x << " ";
		});

	return 0;
}

class Node{
	public:
		float data;
		float grad;
		set<Node*> children;
		char op;
		Node* res;

		Node(float dataval){
			data = dataval;
			grad = 0.0;
			children = set<Node*>();
			op = '\0';
		}

		Node(float dataval, set<Node*> s){
			data = dataval;
			grad = 0.0;
			children = s;
			op = '\0';
		}
		Node(){
			data = 0.0;
			grad = 0.0;
			children = set<Node*>();
			op = '\0';
		}
		void display(){
			cout<<"Data : "<<data<<endl;
			cout<<"Grad : "<<grad<<endl;
			if(children.empty()){
				cout<<"Has no children"<<endl;
			}else{
				cout<<"Has "<<children.size()<<" children"<<endl;

			}
		}
		Node operator+(Node &n){
			Node *result = new Node();
			result->data = data + n.data;
			result->children.insert(new Node(this->data, this->children));
			result->children.insert(new Node(n.data, n.children));
			op = '+';
			n.op = '+';
			grad += 1;
			n.grad += 1;
			return *result;
		}

		Node operator*(Node &n){
			Node* result = new Node();
			result->data = data * n.data;
			result->children.insert(new Node(this->data, this->children));
			result->children.insert(new Node(n.data, n.children));
			op = '*';
			n.op = '*';

			grad += n.data;
			n.grad += data;

			return *result;
		}


		Node operator+(float n){
			Node *result = new Node();
			result->data = data + n;
			result->children.insert(new Node(this->data, this->children));
			result->children.insert(new Node(n));
			op = '+';
			grad += 1;
			// n.grad += 1;
			return *result;
		}


		Node operator*(float n){
			Node* result = new Node();
			result->data = data * n;
			result->children.insert(new Node(this->data, this->children));
			result->children.insert(new Node(n));
			op = '*';

			grad += n;
			return *result;
		}
		


		void setgrad(float back_grad){
			grad += back_grad;
		}

		void back_propagate(){
			set<Node*> s;
			float back_grad = 1;
			backward(s,back_grad);
		}

		void backward(set<Node*> visited, float back_grad){
			if(visited.find(this) != visited.end())return; //found in set
			if(visited.empty()){ //op node
				grad = 1.0;
			}else{
				setgrad(back_grad);
			}
			visited.insert(this);
			if(!children.empty()){
				(*(children.begin()))->backward(visited, grad);
				(*(++children.begin()))->backward(visited, grad);
			}
			
		}
};
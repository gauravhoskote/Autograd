#include <bits/stdc++.h>
#include "Node.cpp"
#include "FullyConnectedLayer.cpp"

using namespace std;


void displayChildren(Node m){
	if(!m.children.empty()){
		cout<<"The children are :"<<endl;
		cout<<(*(++m.children.begin()))->data<<endl;
		cout<<(*(m.children.begin()))->data<<endl;
	}else{
		cout<<"This node has no children."<<endl;
	}
	
}

int main(){
	// cout<<"1-- "<<endl;
	// Node n1 = Node(4.0);//, s);
	// Node n2 = Node(8.0);//, s);
	// Node n3 = Node(3.0);//, s);
	// Node n4 = Node(7.0);//, s);
	// Node x1 =  n2*n1*n3;
	// Node x2 =  n3+n4;
	// Node y = x1 * x2;
	// y.back_propagate();
	// displayChildren(n1);
	// n1.display();
	// displayChildren(n2);
	// n2.display();
	// displayChildren(n3);
	// n3.display();
	// displayChildren(n4);
	// n4.display();
	// displayChildren(x1);
	// x1.display();
	// displayChildren(x2);
	// x2.display();
	// displayChildren(y);
	// y.display();

	cout<<"2-- "<<endl;

	vector<Node> x;
	x.push_back(Node(4.0));
	x.push_back(Node(8.0));
	x.push_back(Node(3.0));
	x.push_back(Node(7.0));
	
	vector<Node> w;
	vector<Node> b;
	w.push_back(Node(1.0));
	w.push_back(Node(1.0));
	w.push_back(Node(1.0));
	w.push_back(Node(1.0));

	b.push_back(Node(1.0));
	b.push_back(Node(1.0));
	b.push_back(Node(1.0));
	b.push_back(Node(1.0));

    vector<Node> ans;
	for(int i = 0; i < w.size(); i++){
		ans.push_back(w[i]*x[i] + b[i]);
	}
	for(int i = 0; i < w.size(); i++){
		cout<<ans[i].data<<endl;
	}


	FullyConnectedLayer f = FullyConnectedLayer(2,4);
	cout<<f.weights.size();
	cout<<f.weights[0].size();




	return 0;
}
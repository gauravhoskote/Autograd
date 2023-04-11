
class FullyConnectedLayer{
	// implements a class for creating a fully connected layer with weights and biases

	public:
	vector< vector < Node > > weights;
	vector< Node > bias;

	FullyConnectedLayer(int input, int output){
		weights.assign(output, vector<Node>(input, Node(randomFloat())));
		bias.assign(output, Node(randomFloat()));
	}


	float randomFloat()
	{
	    return (float)(rand()) / (float)(rand());
	}




};
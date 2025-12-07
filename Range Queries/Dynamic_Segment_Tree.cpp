struct Node{
	int left,right;
	int value=INF;
	Node *left_child=nullptr,*right_child=nullptr;
	Node(int lb,int rb){
		left=lb; right=rb;
	}
	void add(int k,int x){
		if(left==right){
			value=x;
			return;
		}
		int mid=(left+right)/2;
		if(k<=mid){
			if(!left_child)left_child=new Node(left,mid);
			left_child->add(k,x);
		}else{
			if(!right_child)right_child=new Node(mid+1,right);
			right_child->add(k,x);
		}
		int a=left_child?left_child->value:INF;
        int b=right_child?right_child->value:INF;
		value=min(a,b);
	}
	int query(int lq,int rq){
		if(lq<=left&&right<=rq){
			return value;
		}else if(rq<left||right<lq){
			return INF;
		}
		int a=left_child?left_child->query(lq, rq):INF;
        int b=right_child?right_child->query(lq, rq):INF;
        return min(a,b);
	}
};

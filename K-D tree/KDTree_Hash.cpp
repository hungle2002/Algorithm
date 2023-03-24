#include<bits/stdc++.h>
using namespace std;

// KD tree
struct Node{
    double point[3];
    Node* left;
    Node* right;
    Node(double _point[3]){
        point[0] = _point[0];
        point[1] = _point[1];
        point[2] = _point[2];
        left = NULL;
        right = NULL;
    }
};
struct Point{
    double point[3];
    Point(double _point[]){
        this->point[0] = _point[0];
        this->point[1] = _point[1];
        this->point[2] = _point[2];
    }
};
struct compareX {
    bool operator ()(const Point& left, const Point& right) const {
        return left.point[0] < right.point[0];
    }
};
struct compareY {
    bool operator ()(const Point& left, const Point& right) const {
        return left.point[1] < right.point[1];
    }
};
struct compareZ {
    bool operator ()(const Point& left, const Point& right) const {
        return left.point[2] < right.point[2];
    }
};
Node* insert(Node* root, int depth, vector<Point>::iterator _begin, vector<Point>::iterator _end){
    if(_begin == _end){
        return NULL;
    }
    if(_end - _begin == 1){
        return new Node((*_begin).point);
    }
    if(depth % 3 == 0){
        sort(_begin, _end, compareX());
    }
    else if(depth % 3 == 1){
        sort(_begin, _end, compareY());
    }
    else{
        sort(_begin, _end, compareZ());
    }

    int median = 0;
    for(vector<Point>::iterator i = _begin; i<_end; i++){
        median++;
    }
    median/=2;

    root = new Node((*(_begin + median)).point);
    if(_begin != _begin+median){
        root->left = insert(root->left, depth+1,_begin, _begin+median );
    }
    if((_begin + median +1) != _end){
        root->right = insert(root->right, depth+1,_begin+ median +1, _end );
    }
    return root;
}
bool search_rec(Node* root, double _point[], int depth){
    if(root == NULL){
        return 0;
    }
    else{
        if(root->point[0] == _point[0] && root->point[1] == _point[1] && root->point[2] == _point[2]){
            return 1;
        }
        else{
             int truc = depth % 3;
             if(root->point[truc] > _point[truc]){
                 return search_rec(root->left, _point, depth+1);
             }
             else{
                 return search_rec(root->right, _point, depth+1);
             }
        }
    }
    return 0;
}
bool search(Node* root, double _point[]){
    return search_rec(root, _point, 0);
}
double dist_pow_2(double p1[], double p2[]){
    double ans=0;
    for(int i=0; i<3; i++){
        ans += (p1[i] - p2[i])*(p1[i] - p2[i]);
    }
    return ans;
}
Node* closest( Node* tmp, Node* root, double _point[]){
    if(tmp == NULL){
        return root;
    }
    if(root == NULL){
        return tmp;
    }
    double d1 = dist_pow_2(_point, root->point);
    double d2 = dist_pow_2(_point, tmp->point);
    if(d1 - d2 >0){
        return  tmp;
    }
    return root;
}
Node* nearest_kd(Node* root, double _point[], int depth){
    if(root == NULL){
        return NULL;
    }
    Node* nextBranch = NULL;
    Node* otherBranch = NULL;

    int cd = depth%3;
    if(_point[cd] < root->point[cd]){
        nextBranch = root->left;
        otherBranch = root->right;
    }
    else{
        nextBranch = root->right;
        otherBranch = root->left;
    }

    Node* tmp = nearest_kd(nextBranch, _point, depth+1);
    Node* best = closest(root, tmp, _point);
    
    long r_2 = dist_pow_2(_point, best->point);
    long dist = abs(_point[cd] - root->point[cd]);
    if(r_2 >= dist*dist){
        tmp = nearest_kd(otherBranch, _point, depth+1);
        best = closest(tmp, best, _point);
    }
    return best;
}
void print(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->point[0]<<" "<< root->point[1] <<" "<<root->point[2]<< endl;
    print(root->left);
    print(root->right);
}

// Hash
int size_hash=0;
struct Hash_node{
    double point[3];
    Hash_node(double _point[]){
        point[0] = _point[0];
        point[1] = _point[1];
        point[2] = _point[2];
    }
    Hash_node(double x, double y, double z){
        point[0] = x;
        point[1] = y;
        point[2] = z;       
    }
};
struct Z_arr{
    bool check;
    vector<Hash_node> vec;
    Z_arr(){
        this->check = 0;
    }
};
struct Y_arr{
    int y;
    Z_arr* z_arr;

    Y_arr(){
        this->y = -1;
        this->z_arr = new Z_arr[100];
    }
};
struct X_arr{
    int x;
    Y_arr* y_arr;

    X_arr(){
        this->x=-1;
        this->y_arr = new Y_arr[100];
    }
};
struct Hash{
    X_arr* x_arr;
    int size;
    Hash(){
        x_arr = new X_arr[100];
        size=0;
    }
};
void hash_funct(double _point[3], Hash h){
    int _x = _point[0];
    int _y = _point[1];
    int _z = _point[2];

    h.x_arr[_x].x = _x;
    h.x_arr[_x].y_arr[_y].y = _y;
    h.x_arr[_x].y_arr[_y].z_arr[_z].vec.push_back(Hash_node(_point));
    size_hash++;
}
bool search_hash(double _point[3], Hash h){
    int _x = _point[0];
    if(h.x_arr[_x].x == -1){
        return 0;
    }

    int _y = _point[1];
    if(h.x_arr[_x].y_arr[_y].y == -1){
        return 0;
    }

    int _z = _point[2];
    for(auto i : h.x_arr[_x].y_arr[_y].z_arr[_z].vec){
        if(i.point[0] == _point[0] && i.point[1] == _point[1] && i.point[2] == _point[2]){
            return 1;
        }
    }
    return 0;
}
Hash_node nearest_hash(double _point[], Hash &h){
    bool flag=1;
    int dist_block=0;
    int step[3] = {-1, 0, 1};
    int r_x[26];
    int r_y[26];
    int r_z[26];
    int cur_step=0;
    // init the arr to check around
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(i==0 && j==0 && k==0){
                    continue;
                }
                r_x[cur_step] = step[i];
                r_y[cur_step] = step[j];
                r_z[cur_step] = step[k];
                cur_step++;
            }
        }
    }
    double min_dist = 100000000;
    double ans[3];
    vector<Hash_node> vec;
    vec.push_back(Hash_node((int)_point[0], (int)_point[1], (int)_point[2]));
    while(flag && size_hash){
        vector<Hash_node> tmp;
        dist_block++;
        for( auto i : vec){
            for(int j=0; j<26; j++){
                int _x = i.point[0] + r_x[j];
                int _y = i.point[1] + r_y[j];
                int _z = i.point[2] + r_z[j];
                if(_x >=0 && _y>=0 && _z >=0 && _x<=100 && _y<=100 && _z<=100 && h.x_arr[_x].y_arr[_y].z_arr[_z].check == 0){
                    h.x_arr[_x].y_arr[_y].z_arr[_z].check = 1;
                    tmp.push_back(Hash_node(_x, _y, _z));
                    for(auto k : h.x_arr[_x].y_arr[_y].z_arr[_z].vec){
                        size_hash--;
                        double distance = dist_pow_2(_point, k.point);
                        if(distance < min_dist ){
                            min_dist = distance;
                            ans[0] = k.point[0];
                            ans[1] = k.point[1];
                            ans[2] = k.point[2];
                        }
                    } 
                    if(h.x_arr[_x].y_arr[_y].z_arr[_z].vec.size()>0){
                        flag=0;
                    }                                    
                }
            }
        }
        if(min_dist > dist_block*dist_block){
            flag=1;
        }
        vec = tmp;
    }
    return ans;
}
int main()
{
    srand(time(NULL));
	struct Node *root = NULL;
    vector<Point>vec;
    int k;
    cin>>k;
	double points[k][3] ;

    for(int i=0; i<k; i++){
        points[i][0] = rand()%100 + (rand()%1000)*1.0/1000;
        points[i][1] = rand()%100 + (rand()%1000)*1.0/1000;
        points[i][2] = rand()%100 + (rand()%1000)*1.0/1000;
        vec.push_back(points[i]);
    }
    double target[3] = {50,50,50};

	// check for kd tree
	root = insert(root, 0, vec.begin(), vec.end());
    clock_t begin = clock();
    Node* a = nearest_kd(root, target, 0);
    cout << a->point[0] <<" "<< a->point[1] << " "<<a->point[2]<<endl;   
    clock_t end = clock();
    cout<<"Time run for KD-Tree: "<<(float)(end-begin)<<" ms\n"<<endl;

	// check for hash
	Hash h;
	for (int i=0; i<k; i++){
        hash_funct(points[i], h);
    }    
    begin = clock();
    Hash_node tmp = nearest_hash(target, h);
    cout << tmp.point[0] << " "<< tmp.point[1] <<" "<< tmp.point[2]<<endl;
    end = clock();
    cout<<"Time run for Hash: "<<(float)(end-begin)<<" ms"<<endl;
	return 0;
}




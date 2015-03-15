#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi dijkstra(vector<vii> AdjList, int s) {
	vi dist(AdjList.size(), INT_MAX);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		//guloso: escolhe o menor vértice não visitado
		ii front = pq.top();
		pq.pop();
		// d = custo da aresta e u = id da aresta
		int d = front.first, u = front.second;
		// se o que eu tenho já é melhor, não há necessidade continuar verificando esse vértice;
		if (d > dist[u])
			continue;
		for (int i = 0; i < (int) AdjList[u].size(); ++i) {
			ii v = AdjList[u][i]; //vértices adjacentes a u
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first; //relaxamento
				pq.push(ii(dist[v.second], v.second));
			}
		}
	}
	return dist;
}

void printG(vector<vii> G) {
	for (int i = 0; i < G.size(); i++) {
		for (int j = 0; j < G[i].size(); ++j) {
			cout << "(" << G[i][j].first << ", " << G[i][j].second << ") ";
		}
		cout << endl;
	}
}

void printPath(vii path) {
	for (int j = 0; j < path.size(); ++j) {
		cout << "(" << path[j].first << ", " << path[j].second << ") ";
	}
	cout << endl;
}

void printPathVi(vi path) {
	for (int j = 0; j < path.size(); ++j) {
		cout << j << ":" << path[j] << " ";
	}
	cout << endl;
}

int main() {

	vector<vii> G;
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		int n;
		cin >> n;
		vii line;
		//cout << n;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			line.push_back(ii(a, b));
			//cout << "(" << G[i][j].first << ", " << G[i][j].second << ") " ;
		}
		G.push_back(line);
		line.clear();
	}
	//cout << "wtf?";
	printG(G);

	vi res;
	cout << "aqui\n";
	res = dijkstra(G, 2);
	cout << "aqui2\n";
	printPathVi(res);

	return 0;
}

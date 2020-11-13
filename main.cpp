#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
ld dist(pair< ld, ld > vertex[], ll i, ll j)
{
	return sqrt(((vertex[i].first - vertex[j].first)*(vertex[i].first - vertex[j].first)) + ((vertex[i].second - vertex[j].second)*(vertex[i].second - vertex[j].second)));
}


int main()
{
	time_t s_time;
	s_time = time(NULL);
	
	ifstream infile;
	infile.open("input.txt");
	infile>>n;

	pair < ld, ld > vertex[n];
	ll route[n], used[n];
	ld route_sum = 0;

	for(ll i = 0; i < n; i++)
	{	
		used[i] = 0;
		infile>>vertex[i].first>>vertex[i].second;
		// fprintf(stderr, "%Lf %Lf %lli\n", vertex[i].first, vertex[i].second, i);
	}
	infile.close();
	route[0] = 0;
	used[0] = 1;
	for(ll i = 0; i < n - 1; i++)
	{
		ld min = -1;
		ll ind = -1;
		// for(ll j = 0; j < n; j++)
		// {
		// 	if(!used[j])
		// 	{
		// 		if(min == -1)
		// 		{
		// 			min = dist(vertex, route[i], j);
		// 			ind = j;
		// 			continue;
		// 		}
		// 		if(dist(vertex, route[i], j) < min)
		// 		{
		// 			min = dist(vertex, route[i], j);
		// 			ind = j;
		// 		}
		// 	}
		// }
		// route[i + 1] = ind;
		// used[ind] = 1;
		// route_sum += min;
		route[i + 1] = i + 1;
		used[i + 1] = 1;
		route_sum += dist(vertex, i, i + 1);
	}
	route_sum += dist(vertex, 0, route[n-1]);


	ll improved = 0;

	while(improved < 10 && n < 10000)
	{
		for(ll i = 0; i < n - 1; i++)
		{
			for(ll j = i + 1; j < n; j++)
			{
				ll new_route[n];
				ld new_route_sum = 0;
				
				for(ll k = 0; k <= i - 1; k++)
				{
					new_route[k] = route[k];
				}
				for(ll k = i; k <= j; k++)
				{
					new_route[k] = route[j - (k - i)];
				}
				for(ll k = j + 1; k < n; k++)
				{
					new_route[k] = route[k];
				}
				for(ll k = 0; k < n - 1; k++)
				{
					new_route_sum += dist(vertex, new_route[k], new_route[k+1]);
				}
				new_route_sum += dist(vertex, new_route[0], new_route[n-1]);
				
				
				if(new_route_sum < route_sum)
				{
					for(ll k = 0; k < n; k++)
						route[k] = new_route[k];
					improved = 0;
					route_sum = new_route_sum;
				}
			}
		}
		time_t e_time;
		e_time = time(NULL);
		if(e_time - s_time > 600)
			break;
		improved++;
	}

	ofstream outfile;
	outfile.open("output.txt");
	outfile<<route_sum<<" 0\n";
	for(ll i = 0; i < n; i++)
	{
		outfile<<route[i]<<" ";
	}
	outfile<<endl;
	
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int addr;
	int r;
	struct Node *destinations;
};

int ComputeR(int r, int g, int seed, int p){
	return (r*g+seed)%p;
}

struct Node *ComputeJumps(int *Rvalues, int addr, int r){
	if(r == 0){
		return NULL;
	}else{
	int i,j;
	struct Node *jumps = (struct Node *)malloc(sizeof(struct Node)*2*r);
	i = -r;
	j = 0;
	while(i<=r){
		if(i!=0){
			if((addr + i)%9 < 0)
				jumps[j].addr = (9+(addr + i))%9;
			else
				jumps[j].addr = (addr + i)%9;
			jumps[j].r = Rvalues[jumps[j].addr];
			j++;
		}
		i++;
		
	}
	return jumps;
		}
}

int CircularWalk(int *Rvalues, int s, int t){
		int i, bestjumpAddr,jumpAddr;
	if(s==t){
		return 0;
	}else if(current->r == 0){
		return -1;
	}else{
	struct Node *current = (struct Node *)malloc(sizeof(struct Node));
	current->addr = s;
	current->r = Rvalues[s];
	current->destinations = ComputeJumps(Rvalues, s, Rvalues[s]);

		if(current->destinations!=NULL){
			bestjumpAddr = current->destinations[0].addr;
			i = 1;
			while(i<2*current->r){
				jumpAddr = current->destinations[i].addr;
				if(abs(t-jumpAddr)<abs(t-bestjumpAddr) && current->destinations[i].r!=0)
					bestjumpAddr = jumpAddr;
				i++;
			}
			return 1 + CircularWalk(Rvalues, bestjumpAddr, t);
		}
	}
}



int main(){
	int n,i; 
    int s; 
    int t; 
    scanf("%d %d %d", &n, &s, &t);
    int r_0; 
    int g; 
    int seed; 
    int p; 
    scanf("%d %d %d %d", &r_0, &g, &seed, &p);
    int *Rvalues =  malloc(sizeof(int)*n);
    Rvalues[0] = r_0;
    i =1;
    while(i<n){
    	Rvalues[i] =  ComputeR(Rvalues[i-1], g, seed, p);
    	i++;
    }

	int result = CircularWalk(Rvalues, s, t);
	printf("%d\n",result );

	return 0;
}


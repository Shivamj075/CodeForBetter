#define ll long long
#define MAX 100002
/*
ll bit[MAX];
void update(int i,ll x){
    while(i<=MAX){
        bit[i]+=x;
        i+=(i&-i);
    }
}
ll query(int i){
    ll r=0;
    while(i>0){
        r+=bit[i];
        i-=(i&-i);
    }
    return r;
}
int Solution::countInversions(vector<int> &A) {
    memset(bit,0,sizeof(bit));
    ll r=0;
    pair<int,int>v[A.size()+1];
    for(int i=0;i<A.size();i++){
        v[i].first=A[i];
        v[i].second=i+1;
    }
    sort(v,v+A.size());
    for(int i=0;i<A.size();i++){
        r+=(i-query(v[i].second));
        update(v[i].second,1);
    }
    return r;
}
*/
int Merge(vector<int>&a,vector<int>&temp,int s,int e){
	int mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s,inv_count=0;
	//int temp[100];
	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else if(a[i]>a[j]){
			temp[k++]=a[j++];
			//cout<<"mid: "<<mid<<" i: "<<i<<endl;
			inv_count+=(mid-i+1);  //ans=mid-i+1;
		
		}
		
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=e){
		temp[k++]=a[j++];
	}
	for(int i=s;i<=e;i++)
		a[i]=temp[i];
	
	return inv_count;
	
}

int Inversion_Count(vector<int>&A,vector<int>&temp,int s,int e,int n){
	
	int inv_count=0;
	if(s>=e){
		return 0;
	}
	int mid=(s+e)/2;
	inv_count=Inversion_Count(A,temp,s,mid,n);
	inv_count+=Inversion_Count(A,temp,mid+1,e,n);
	inv_count+=Merge(A,temp,s,e);
	
	return inv_count;
}

int Solution::countInversions(vector<int> &A) {
    vector<int>temp(A.size());
    
    return Inversion_Count(A,temp,0,A.size()-1,A.size());
}

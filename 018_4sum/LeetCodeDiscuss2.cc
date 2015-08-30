/*
the O(n^2) time complexity solution. using hash map.

if we remove the duplicate number more than 4, we have the worst time complexity O(n^2).
*/
    struct nd{
      int val;
      int i,j;
      nd(int ii,int jj,int vv){
          i=ii;
          j=jj;
          val=vv;
      }
      nd(int v){
         val=v;
      }
      bool operator <(const nd& n) const{
          return val<n.val;
      }
      operator int() const{
          return val;
      }
    };
    bool valid(int a,int b,int c,int d){
        return a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d;
    }

    struct hs{
        size_t operator ()(const vector<int> &v)const {
            int t=0;
            for(int i=0;i<4;i++){
                t*=9997;
                t+=v[i];
            }
            return t;
        }
    };

    struct eq{
        bool operator ()(const vector<int> &v1,const vector<int> &v2) const
        {
            for(int i=0;i<4;i++){
                if(v1[i]!=v2[i])
                    return false;
            }
            return 1;
        }
    };

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<nd> pair;
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                pair.push_back(nd(i,j,num[i]+num[j]));
            }
        }
        unordered_map<int,vector<nd> > hash;
        unordered_map<int,vector<nd> >::iterator it;
        vector<vector<int> > vvi;
        unordered_set<vector<int>,hs,eq> hash_ret;
        for(int i=0;i<pair.size();i++){
            if((it=hash.find(target-pair[i].val))==hash.end()){
                hash[pair[i].val].push_back(pair[i]);
            }
            else
            {
                for(int k=0;k<it->second.size();k++){

                    if(valid(pair[i].i,pair[i].j,it->second[k].i,it->second[k].j))
                    {
                        vector<int> v(4);
                        v[0]=num[pair[i].i];
                        v[1]=num[pair[i].j];
                        v[2]=num[it->second[k].i];
                        v[3]=num[it->second[k].j];
                        sort(v.begin(),v.end());
                        if(hash_ret.find(v)==hash_ret.end()){
                            vvi.push_back(v);
                            hash_ret.insert(v);
                        }
                    }
                }
                hash[pair[i].val].push_back(pair[i]);
            }
        }
        return vvi;
    }

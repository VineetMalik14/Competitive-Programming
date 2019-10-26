vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> v;
      for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            for(int k=j+1;k<A.size()-1;k++){
                string temp;
                int ch=0;
                int a,b,c,d;
                temp+=A.substr(0,i+1);
                a=stoi(A.substr(0,i+1));
                if(a==0 && A.substr(0,i+1).size()>1)continue;
                for(int l=0;l<=i;l++){
                    if(A[l]!='0')break;
                    if(A[l]=='0' && a!=0){
                        ch=1;
                        break;
                    }
                }
                if(ch==1)continue;
                temp+=".";
                temp+=A.substr(i+1,j-i);
                b=stoi(A.substr(i+1,j-i));
                if(b==0 && A.substr(i+1,j-i).size()>1)continue;
                for(int l=i+1;l<=j;l++){
                    if(A[l]!='0')break;
                    if(A[l]=='0' && b!=0){
                        ch=1;
                        break;
                    }
                }
                if(ch==1)continue;
                temp+=".";
                temp+=A.substr(j+1,k-j);
                c=stoi(A.substr(j+1,k-j));
                if(c==0 && A.substr(j+1,k-j).size()>1)continue;
                 for(int l=j+1;l<=k;l++){
                    if(A[l]!='0')break;
                    if(A[l]=='0' && c!=0){
                        ch=1;
                        break;
                    }
                }
                if(ch==1)continue;
                temp+=".";
                temp+=A.substr(k+1);
                d=stoi(A.substr(k+1));
                if(d==0 && A.substr(k+1).size()>1)continue;
                 for(int l=k+1;l<=A.size()-1;l++){
                    if(A[l]!='0')break;
                    if(A[l]=='0' && d!=0){
                        ch=1;
                        break;
                    }
                }
                if(ch==1)continue;
                
                if(a>255 || b>255 || c>255 || d>255 || a<0 || b<0 || c<0 || d<0){
                    continue;
                }
                
                
                v.push_back(temp);
            }
        }
    }
    
    
    sort(v.begin(),v.end());
    return v;
}

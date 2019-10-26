pair<string,int> divideby2(string a){
    string ans;
    int c=0;
    for(int i=0;i<a.size();i++){
        int num=c*10+a[i]-'0';
        if(num<2){
            ans+='0';
            c=num;
            continue;
        }else{
            c=num%2;
            ans+=num/2 +'0';
        }
    }
    int z=0;
    while(z<ans.size() && ans[z]=='0'){
        z++;
    }
    ans=ans.substr(z);
    return {ans,c};
}

int Solution::power(string A) {
    if(A=="1"){                       //doesn't need power=0;
        return 0;
    }
    if(A==""){
        return 0;
    }
    
    int cnt=0;
    while(A!=""){
        cnt+=divideby2(A).second;
        A=divideby2(A).first;
        
        if(cnt==1 && A!=""){
            return 0;
        }
    }
    
    return 1;
}


stack<char> s;
    string str;
    cin>>str;
    for(auto value : str){
        if(value=='('||'{'||'['||'}'||']'||')'){
            if(s.empty()){
                s.push(value);
            }else{
                char ch=s.top();
                if(value==')'){
                    if(ch=='('){
                        s.pop();
                    }
                }else{
                    if(value=='}'){
                        if(ch=='{'){
                            s.pop();
                        }
                    }else{
                        if(value==']'){
                            if(ch=='['){
                                s.pop();
                            }
                        }
                    }
                }
                
            }
        }
    }
    if(s.empty()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
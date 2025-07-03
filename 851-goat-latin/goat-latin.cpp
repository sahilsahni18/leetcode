class Solution {
private :
    bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        return true;
    }
    return false;
}
public:
    string toGoatLatin(string sentence) {
    int len = sentence.length();
    string str = "ma";
    int count=2;
    for(int i=0; i<sentence.length(); i++){
        int j=i;
        
        while( j<sentence.length() && sentence[j]!=' ' ){
            j++;
        }
        
        str+='a';
        if(isVowel(sentence[i])){
            sentence.insert(j,str);
        }
        else{
            string ch = sentence[i]+str;
            sentence.insert(j,ch);
            sentence.erase(i,1);
        }
        count++;
        i=j+count;//becuase old string is modified so we cant just do i=j;each word is modified with one a evertime so count ++ 
    }
    return sentence;
}
};
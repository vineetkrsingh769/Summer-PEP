public class countFrequency {

}
int hashFunction(char c){
    if(c>='A'&& c<='Z')
        return(c-65);
    else
        return(c-70);
}

void countFrequency(string s){
    int frequency[52];
    for(int i=0; i<s.lenght(); i++){
        int index=hashFunction(s[i]);
        frequency[index]++;
    }
    for (int i=0; i<52; i++){
        if frequency[i]!=0{
            if(i<=26)
                count<<(char)i+65<<" - "<<frequency[i];
            else
                cout<<(char)i+70<<" - "<<frequency[i];
            cout<<endl;

        }
    }
}

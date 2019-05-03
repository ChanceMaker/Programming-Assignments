#include <iostream>
#include <string>
#include <vector>
#include <new>
struct uniWrd{
    std::string wrd;
    int freq;
    uniWrd(): wrd(""),freq(0){}
    uniWrd(std::string x, int y): wrd(x), freq(y){}
    void addFreq(){
        freq++;
    }
    void addWrd(std::string x){
        wrd = x;
    }
};
void printUniVect(std::vector<uniWrd> x){
    for(auto itr = x.begin(); itr != x.end(); itr++){
        std::cout <<"\n Word : "<< (*itr).wrd;
        std::cout <<"\n Frequency: "<<(*itr).freq;
    }
    std::cout << "\n";
}

void printVect(std::vector<std::string> x){
    for(auto itr = x.begin(); itr != x.end(); itr++){
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}
bool inParagraph(std::string paragraph, std::string word){
    std::string buildWord;
    std::vector<std::string> paragraphVect;
    for(int i = 0; i < paragraph.size();i++){
        if(paragraph.at(i) != ' ' && paragraph.at(i) != ','){
            buildWord.push_back(paragraph.at(i));
        }else if(paragraph.at(i) == ' ' ){
            paragraphVect.push_back(buildWord);
            buildWord = "";    
        }
    }
    for(auto itr = paragraphVect.begin(); itr != paragraphVect.end(); itr++){
        if(*itr == word)
            return true;
        
    }
    return false;
}
bool inUniVect(std::vector<uniWrd> x, std::string wrd){
    for(auto itr = x.begin(); itr != x.end(); itr++ ){
        if((*itr).wrd == wrd){
           return true;
        }
    }
    return false;
}
std::vector<uniWrd> buildUniHelp(std::vector<std::string> x){
    std::vector<uniWrd> ans;
    int cnt = 0;
    for(auto itr = x.begin(); itr != x.end(); itr++){
        uniWrd var;
      
        std::string y = *itr;
       
        if(!inUniVect(ans,*itr)){
            var.addFreq();
            var.addWrd(*itr);
            cnt++;
            ans.push_back(var);
        }else{
            for(auto itr2 = ans.begin(); itr2 != ans.end(); itr2++){
                if(*itr == (*itr2).wrd){
                    (*itr2).freq += 1;
                }
            }

        }
        
    }
    printUniVect(ans);

    return ans;
    
}
std::vector<std::string> buildUniqueWordVect(std::string paragraph){
    std::vector<std::string> uniqueWords;
    std::vector<uniWrd> uniqueFreq;
    int cnt = 0;
    std::string wrdBuild;//building a word to attach throught the unique word std::vector.
    for(int i = 0 ; i < paragraph.size(); ++i){
        if(i == paragraph.size() - 1){//Case for when you hit the last word
            wrdBuild.push_back(paragraph.at(i));
            uniqueWords.push_back(wrdBuild);
        }
        if(paragraph.at(i) != ' ' && paragraph.at(i) != ','&& paragraph.at(i) != '.' ){ 
            wrdBuild.push_back(paragraph.at(i));
        }
        else if(paragraph.at(i) == ' ')
        {
            if(inParagraph(paragraph,wrdBuild)){
                uniqueWords.push_back(wrdBuild);
            }
                
            wrdBuild = "";
        }
    }
    buildUniHelp(uniqueWords);
    return uniqueWords;
    
}
class Solution {
public:
    std::vector<std::string> mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::string ans;
        std::vector<std::string> unique;
        unique = buildUniqueWordVect(paragraph);
        
        
        return unique;
    }
};
int getNumWords(std::string x){
    int val = 0;
    for(int i = 0 ; i < x.size(); i++){
        if(x.at(i) = ' '){
            val++;
        }
    }
    return val++;
}
int main(){
    Solution ans;
    std::vector<std::string> banned;
    std::string bannedPara;
    int bannedParaSize = 0;
    bannedPara = "still dog happpy sitting";
    bannedParaSize = getNumWords(bannedPara);
    std::string * bannedList;
    std::cout <<"NUMBER OF WORDS "<< bannedParaSize<< "\n";
    bannedList = new std::string[bannedParaSize];
 

    std::string paragraph = "there can only be one highlander, that there is only one there must be, can you see";
    
    ans.mostCommonWord(paragraph,banned);
    delete  [] bannedList;
    return 0;
}
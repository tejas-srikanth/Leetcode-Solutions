class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> s;
        int numR = 0, numC = 0;
        int rLost = 0, cLost = 0;
        for (char c: senate){
            if (c == 'R'){
                numR++;
            } else {
                numC++;
            }
            s.push(c);
        }
        while (!s.empty()){
            if (numR == 0){
                return "Dire";
            } 

            if (numC == 0){
                return "Radiant";
            }

            char c = s.front();
            s.pop();
            if (c == 'R' && rLost > 0){
                rLost--;
                numR--;
                continue;
            }
            else if (c == 'D' & cLost > 0){
                cLost--;
                numC--;
                continue;
            } else if (c == 'R'){
                cLost++;
                s.push(c);
            } else if (c == 'D'){
                rLost++;
                s.push(c);
            }

        }
        return "Radiant";

    }
};
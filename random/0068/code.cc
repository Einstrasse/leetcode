class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<pair<int, int>> arrangements;
        vector<string> answer;
        // pair(num_of_words, num_of_blanks)
        
        // calculate number of words for each line
        int num_words = 0;
        int total_length = 0;
        for (string word : words) {
            if (total_length + num_words + word.length() > maxWidth) {
                arrangements.push_back(make_pair(num_words, total_length));
                num_words = total_length = 0;
            }
            num_words++;
            total_length += word.length();
        }
        if (num_words) {
            arrangements.push_back(make_pair(num_words, total_length));
        }
        
        //arrange blank
        int index = 0;
        for (int i=0; i < arrangements.size(); i++) {
            auto arrangement = arrangements[i];
            string line = "";
            int slots_left = maxWidth - arrangement.second;
            int num_blanks = arrangement.first - 1;
            while (arrangement.first--) {
                //add word
                line += words[index++];
                
                //divide blank evently, add more for left blank when not evently separatable
                if (num_blanks > 0) { //prevent divide by zero
                    int blank_num = slots_left / num_blanks + (slots_left % num_blanks == 0 ? 0 : 1);
                    if (i + 1 == arrangements.size()) { //left justification for last line
                        blank_num = 1;
                    }
                    num_blanks--;
                    slots_left -= blank_num;
                    while (blank_num--) {
                        line += " ";
                    }    
                }
            }
            
            //adding leftover
            while (slots_left--) {
                line += " ";
            }
            answer.push_back(line);
        }
        return answer;
        
    }
};
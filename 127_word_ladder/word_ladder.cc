/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence 

from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

// Star: 9.3.
// Info.: A good exercise of Graph.
// TODO: Try two-end search method.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> & wordList) = 0; // Pure virtual, or Solutionx may not have data members.
};

/* A inconnect solution, at least not the shortest transformation.
 * Test case: cet; ism; kid, tag, pup, ail, tun, woo, erg, luz, brr, gay, sip, kay, per, val, mes, ohs, now, boa, cet, pal, bar, die, war, hay, eco, pub, lob, rue, fry, lit, rex, jan, cot, bid, ali, pay, col, gum, ger, row, won, dan, rum, fad, tut, sag, yip, sui, ark, has, zip, fez, own, ump, dis, ads, max, jaw, out, btu, ana, gap, cry, led, abe, box, ore, pig, fie, toy, fat, cal, lie, noh, sew, ono, tam, flu, mgm, ply, awe, pry, tit, tie, yet, too, tax, jim, san, pan, map, ski, ova, wed, non, wac, nut, why, bye, lye, oct, old, fin, feb, chi, sap, owl, log, tod, dot, bow, fob, for, joe, ivy, fan, age, fax, hip, jib, mel, hus, sob, ifs, tab, ara, dab, jag, jar, arm, lot, tom, sax, tex, yum, pei, wen, wry, ire, irk, far, mew, wit, doe, gas, rte, ian, pot, ask, wag, hag, amy, nag, ron, soy, gin, don, tug, fay, vic, boo, nam, ave, buy, sop, but, orb, fen, paw, his, sub, bob, yea, oft, inn, rod, yam, pew, web, hod, hun, gyp, wei, wis, rob, gad, pie, mon, dog, bib, rub, ere, dig, era, cat, fox, bee, mod, day, apr, vie, nev, jam, pam, new, aye, ani, and, ibm, yap, can, pyx, tar, kin, fog, hum, pip, cup, dye, lyx, jog, nun, par, wan, fey, bus, oak, bad, ats, set, qom, vat, eat, pus, rev, axe, ion, six, ila, lao, mom, mas, pro, few, opt, poe, art, ash, oar, cap, lop, may, shy, rid, bat, sum, rim, fee, bmw, sky, maj, hue, thy, ava, rap, den, fla, auk, cox, ibo, hey, saw, vim, sec, ltd, you, its, tat, dew, eva, tog, ram, let, see, zit, maw, nix, ate, gig, rep, owe, ind, hog, eve, sam, zoo, any, dow, cod, bed, vet, ham, sis, hex, via, fir, nod, mao, aug, mum, hoe, bah, hal, keg, hew, zed, tow, gog, ass, dem, who, bet, gos, son, ear, spy, kit, boy, due, sen, oaf, mix, hep, fur, ada, bin, nil, mia, ewe, hit, fix, sad, rib, eye, hop, haw, wax, mid, tad, ken, wad, rye, pap, bog, gut, ito, woe, our, ado, sin, mad, ray, hon, roy, dip, hen, iva, lug, asp, hui, yak, bay, poi, yep, bun, try, lad, elm, nat, wyo, gym, dug, toe, dee, wig, sly, rip, geo, cog, pas, zen, odd, nan, lay, pod, fit, hem, joy, bum, rio, yon, dec, leg, put, sue, dim, pet, yaw, nub, bit, bur, sid, sun, oil, red, doc, moe, caw, eel, dix, cub, end, gem, off, yew, hug, pop, tub, sgt, lid, pun, ton, sol, din, yup, jab, pea, bug, gag, mil, jig, hub, low, did, tin, get, gte, sox, lei, mig, fig, lon, use, ban, flo, nov, jut, bag, mir, sty, lap, two, ins, con, ant, net, tux, ode, stu, mug, cad, nap, gun, fop, tot, sow, sal, sic, ted, wot, del, imp, cob, way, ann, tan, mci, job, wet, ism, err, him, all, pad, hah, hie, aim, ike, jed, ego, mac, baa, min, com, ill, was, cab, ago, ina, big, ilk, gal, tap, duh, ola, ran, lab, top, gob, hot, ora, tia, kip, han, met, hut, she, sac, fed, goo, tee, ell, not, act, gil, rut, ala, ape, rig, cid, god, duo, lin, aid, gel, awl, lag, elf, liz, ref, aha, fib, oho, tho, her, nor, ace, adz, fun, ned, coo, win, tao, coy, van, man, pit, guy, foe, hid, mai, sup, jay, hob, mow, jot, are, pol, arc, lax, aft, alb, len, air, pug, pox, vow, got, meg, zoe, amp, ale, bud, gee, pin, dun, pat, ten, mob;
 * It probably takes a roundabout route from 'cet' to 'ism'(Especially the wordList is large). */
class Solution0 : public Solution {
  public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> & wordList) {
      int length = 1;
      wordList.insert(endWord);
      if (bfs(beginWord, endWord, wordList, &length)) return length;
      else return 0;
    }
    // However, it is DFS indeed.
    bool bfs(std::string & word, std::string & endWord, std::unordered_set<std::string> & wordList, int * length, bool the_last_one = false) {
      if (word == endWord) return true;
      if (the_last_one && wordList.empty()) return false;
      std::vector<std::string> to_be_visited;
      for (size_t i=0; i<word.length(); ++i) {
        std::string wd(word);
        for (size_t j=0; j<26; ++j) {
          wd[i] = 'a' + j;
          if (wd[i]!=word[i] && wordList.find(wd)!=wordList.end()) {
            to_be_visited.push_back(wd);
            wordList.erase(wd);
          }
        }
      }
      for (auto itr=to_be_visited.begin(), end=to_be_visited.end(); itr!=end; ) {
        std::string wd(*itr);
        if (bfs(wd, endWord, wordList, length, ++itr==end)) {
          std::cout << wd << std::endl;
          ++ *length;
          return true;
        }
      }
      return false;
    }
};

// A solution has most votes on LeetCode Discuss.
class Solution1 : public Solution {
  public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordDict) {
      wordDict.insert(endWord);
      std::queue<std::string> toVisit;
      addNextWords(beginWord, wordDict, toVisit);
      int dist = 2;
      while (!toVisit.empty()) {
        int num = toVisit.size();
        for (int i = 0; i < num; i++) {
          std::string word = toVisit.front();
          toVisit.pop();
          if (word == endWord) return dist;
          addNextWords(word, wordDict, toVisit);
        }
        dist++;
      }
    }
private:
  void addNextWords(std::string word, std::unordered_set<std::string>& wordDict, std::queue<std::string>& toVisit) {
    wordDict.erase(word);
    for (int p = 0; p < (int)word.length(); p++) {
      char letter = word[p];
      for (int k = 0; k < 26; k++) { 
        word[p] = 'a' + k;
        if (wordDict.find(word) != wordDict.end()) {
          toVisit.push(word);
          wordDict.erase(word);
        }
      }
      word[p] = letter;
    } 
  } 
};

/* Let the begin word be the "center", and search the end word "circle" by "circle" in BFS manner.
 * I tried it using recursion, but it turns out to be in vain. So I redo it as Solution1. */
class Solution2 : public Solution {
  public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> & wordList) {
      int length = 1;
      wordList.insert(endWord);
      std::queue<std::string> to_be_visited;
      to_be_visited.push(beginWord);
      while (!to_be_visited.empty()) {
        size_t tbvs = to_be_visited.size();
        for (size_t i=0; i<tbvs; ++i) {
          std::string word = to_be_visited.front();
          to_be_visited.pop();
          if (word == endWord) return length;
          findNextCircle(word, to_be_visited, wordList);
        }
        ++ length;
      }
      return 0;
    }
  private:
    void findNextCircle(std::string & word, std::queue<std::string> & to_be_visited, std::unordered_set<std::string> & wordList) {
      for (size_t i=0; i<word.size(); ++i) {
        std::string wd(word);
        for (size_t j=0; j<26; ++j) {
          wd[i] = 'a' + j;
          if (wd[i]!=word[i] && wordList.find(wd)!=wordList.end()) {
            to_be_visited.push(wd);
            wordList.erase(wd);
          }
        }
      }
    }
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get an array.
  std::string beginWord, endWord;
  std::cout << "Please input the begin word: ";
  std::cin >> beginWord;
  std::cout << "Please input the end word: ";
  std::cin >> endWord;
  std::cout << "Please input the word list(Press Enter after each word and Ctrl+z to stop): ";
  std::unordered_set<std::string> ss;
  std::string s;
  while (std::cin >> s)
    ss.insert(s);
  std::cout << "The word list you input is:";
  for (auto itr=ss.begin(); itr!=ss.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  Solution2 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::unordered_set<std::string> word_list(ss);
    std::cout << "The length of the word ladder is " << solutions[si]->ladderLength(beginWord, endWord, word_list) << '.' << std::endl << std::endl;
  }

  return 0;
}

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

// Star: 8.
// Info.: My own idea and one-time pass; Quite interesting.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void generateParenthesisRecursively(std::vector<std::string> & result, std::string one_solution, int l, int r, int & n) {
  if (l+r == 2*n) {
    result.push_back(one_solution);
    return;
  }

  if (l < n) {
    std::string os = one_solution;
    os.push_back('(');
    generateParenthesisRecursively(result, os, l+1, r, n);
  }
  if (l > r) {
    std::string os = one_solution;
    os.push_back(')');
    generateParenthesisRecursively(result, os, l, r+1, n);
  }
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> result;
  if (n == 0) return result;
  std::string one_solution;
  int l = 0;
  int r = 0;
  generateParenthesisRecursively(result, one_solution, l, r, n);
  return result;
}

// Solution 1: Iterative method, from LeetCode Discuss.
// Why just putting the '(' at the head is OK?
std::vector<std::string> generateParenthesisIteratively(int n) {
  std::vector<std::vector<std::string> > results;
  std::vector<std::string> result;
  if (n <= 0) return result;
  results.push_back(std::vector<std::string>({""}));
  for (int i=1; i<=n; ++i) {
    result.clear();
    for (int j=0; j<i; ++j) {
      std::vector<std::string> first = results[j];
      std::vector<std::string> second = results[i-1-j];
      for (int k=0; k<first.size(); ++k)
        for (int l=0; l<second.size(); ++l)
          // Why just putting the '(' at the head is OK?
          result.push_back("("+first[k]+")"+second[l]);
    }
    results.push_back(result);
  }
  result = results[n];
  return result;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n = atoi(argv[1]);

  std::vector<std::string> valid_parentheseses = generateParenthesis(n);
  //std::vector<std::string> valid_parentheseses = generateParenthesisIteratively(n);
  std::cout << "All combinations of well-formed parentheses are(From " << n << " pairs of parentheses, total " << valid_parentheseses.size() << "): " << std::endl;
  for (size_t i=0; i<valid_parentheseses.size(); ++i)
    std::cout << valid_parentheseses[i] << std::endl;

  return 0;
}

// An iterative method form LeetCode Discuss.
/*
My method is DP. First consider how to get the result f(n) from previous result f(0)...f(n-1). 

Actually, the result f(n) will be put an extra () pair to f(n-1). Let the "(" always at the 

first position, to produce a valid result, we can only put ")" in a way that there will be 

i pairs () inside the extra () and n - 1 - i pairs () outside the extra pair.

Let us consider an example to get clear view:

f(0): ""

f(1): "("f(0)")"

f(2): "("f(0)")"f(1), "("f(1)")"

f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"

So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"

Below is my code:
*/
/*
public class Solution
{
    public List<String> generateParenthesis(int n)
    {
        List<List<String>> lists = new ArrayList<>();
        lists.add(Collections.singletonList(""));

        for (int i = 1; i <= n; ++i)
        {
            final List<String> list = new ArrayList<>();

            for (int j = 0; j < i; ++j)
            {
                for (final String first : lists.get(j))
                {
                    for (final String second : lists.get(i - 1 - j))
                    {
                        list.add("(" + first + ")" + second);
                    }
                }
            }

            lists.add(list);
        }

        return lists.get(lists.size() - 1);
    }
}
*/

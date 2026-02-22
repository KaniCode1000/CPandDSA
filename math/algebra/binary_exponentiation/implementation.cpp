#include <iostream>
using namespace std;

//implementation
long long binexpo(long long a,long long b){
  long long res = 1;
  while (b>0)
  {
    if (b&1)
      res = res*a;
    a = a*a;
    b >>= 1;
  }
  return res;
}

//large exponents modulo a number
long long binexpo(long long a,long long b,long long m){
  a %=m;
  long long res = 1;
  while (b>0)
  {
    if (b&1)
      res = res*a % m;
    a = a*a % m;
    b >>= 1;
  }
  return res;
}

//For Computing Fibonacci number



//Applying a permutation k times - Simply raise the permutation to the kth power using binary exponentiation and then apply it to the sequence
//Complexity - O(n*log(k)) 
//can be done faster using permutation graph and considering each cycle independently
vector <int> applyPermutation(vector<int> sequence, vector<int> permutation)
{
  vector<int> newSeq(sequence.size());
  for (int i =0; i< sequence.size(); i++)
  {
    newSeq[i] = sequence[permutation[i]];
  }
  return newSeq;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long k)
{
  while (k>0){
    if (k&1)
      sequence = applyPermutation(sequence,permutation);
    permutation = applyPermutation(permutation,permutation);
    k >>= 1;
  }
  return sequence;
}


//Fast application of a set of geometric operations to a set of points 
//Idea - The process can be exponentiated as transforming matrices multiplying themselves and the rest is simple the algorithm itself only
//Can be calculated in O(m*log(k) + n) time where O(m*log(k)) is the required to compute the tranformation matrices and O(n) is the 
//number of points and k is the number of looping iterations. 

//Number of paths of length k in a graph

//Variation of binary exponentiation: multiplying two numbers modulo m 
uint64_t multiply(uint64_t a, uint64_t b,uint64_t m)
{
  uint64_t ans = 0;
  while (b)
  {
    if (b&1)
      ans = (ans + a) % m;
    a = (a+a)%m;
    b>>=1;
  }
  return ans;
}

//main function
int main(){

}

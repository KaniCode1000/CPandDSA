deque<int> q;

//finding minimum
int minimum = q.front();

//adding an element
while (!q.empty() && q.back() > new_element)
    q.pop_back();
q.push_back(new_element);

//removing an element
if (!q.empty() && q.front() == remove_element)
    q.pop_front();
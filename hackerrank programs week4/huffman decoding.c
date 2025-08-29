
void decode_huff(node*root, string s)
 {
    string answer = "";
    int sLength = s.length();
    node*currentNode = root;
  for (int i=0; i<sLength;i++) 
{
   if (s[i] == '0') 
 {
     currentNode = currentNode->left;
    } 
    else
 {
    currentNode = currentNode->right;
 }
if(currentNode->left == NULL && currentNode->right == NULL)
 {
     answer += currentNode->data;
    currentNode = root;
     }
}
    cout << answer << endl;
}

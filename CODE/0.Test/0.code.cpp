int BF(const string& s , const string& t)
{
  int i=0 , j=0 , n=0;
  while(i < s.length())
  {
    if(s[i]!=t[i])
    {
      j=0;
      i++;
    }
    else if(j = t.length())
    {
      j=0;
      n++;
    }
    else
    {
      j++;
      i++;
    }
    return n;
  }
}

string get(const struct node* s , const string& t)
{
  struct node* p = s->temp==1 ? s->sub : s->list;
  while(p!=nullptr)
  {
    if((BF(s->data , t)) && (s->temp==0))
    {
      return t;
      break;
    }
    else
    {
      p = p->temp == 1 ？ s->sub : s->list;
    }
  }

  return nullptr;
}

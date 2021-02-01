bool search(vector<int> piece, vector<int> arr)
{
    int index = -1;
    for(int i=0;i<arr.size();i++)
    {
        if(piece[0] == arr[i])
        {
            index = i;
            break;   
        }
    }
    if(index == -1)
        return false;
    for(int i=0;i<piece.size();i++)
    {
        if(arr[index]==piece[i])
            index++;
        else
        {
            return false;
        }
    }
    return true;
}
bool shuffleThePieces(std::vector<int> arr, std::vector<std::vector<int>> pieces) {
    int siz = 0;
    for(int i=0;i<pieces.size();i++)
    {
        siz += pieces[i].size();
    }
    if(siz != arr.size())
        return false;
    for(int i=0;i<pieces.size();i++)
    {
        if(search(pieces[i],arr) == false)
        {
            return false;
        }
    }
    return true;
}

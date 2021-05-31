/*
N candles are placed in a row, some of them are initially lit. For each candle from the 1st to the Nth the following algorithm is applied: 
if the observed candle is lit then states of this candle and all candles before it are changed to the opposite. 
Which candles will remain lit after applying the algorithm to all candles in the order they are placed in the line?

Example

For a = [1, 1, 1, 1, 1], the output should be
switchLights(a) = [0, 1, 0, 1, 0].
*/

void opposited(vector<int>& vec)
{
    if (vec.empty())
        return;
    int sz = vec.size();
    for (int index = 0; index < sz; index++)
    {
        vec[index] = (vec[index] == 1) ? 0 : 1;
    }
}

vector<int> switchLights(vector<int> a) {
    vector<int> res;
    int size = a.size();
    for (int index = 0; index < size; index++)
    {
        if (a[index] == 1)
        {
            opposited(res);
            res.push_back(0);
        }
        else{

            res.push_back(0);
        }
    }
    return res;
}

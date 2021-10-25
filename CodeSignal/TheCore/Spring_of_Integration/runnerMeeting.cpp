/**
 * @file runnerMeeting.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief Some people run along a straight line in the same direction. They start simultaneously at pairwise distinct positions and run with constant speed (which may differ from person to person).
 * If two or more people are at the same point at some moment we call that a meeting. The number of people gathered at the same point is called meeting cardinality.
 * For the given starting positions and speeds of runners find the maximum meeting cardinality assuming that people run infinitely long. If there will be no meetings, return -1 instead.
 * Example
 * For startPosition = [1, 4, 2] and speed = [27, 18, 24], the output should be
 * runnersMeetings(startPosition, speed) = 3.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;


int isMeeting(int _pos1, int _speed1, int _pos2, int _speed2);
int isCheckingMeeting(int _pos1, int _speed1, int _pos2, int _speed2, int& meetingTimes);
int runnersMeetings(vector<int> startPosition, vector<int> speed);

int runnersMeetings(vector<int> startPosition, vector<int> speed) {
    int countMeeting = 0;
    int _sizeOfParticipants = startPosition.size();
    cout << "line: " << __LINE__ << " - Line 9: " << endl;
    for (int curr_person = 0; curr_person < _sizeOfParticipants - 1; curr_person++)
    {
        cout << "line: " << __LINE__ << " - Line 12: " << endl;
        for (int next_person = curr_person + 1; next_person < _sizeOfParticipants; next_person++)
        {
            cout << "line: " << "14 - starting new elems" << endl;
            int meetingTimes = isMeeting(startPosition[curr_person], speed[curr_person], startPosition[next_person], speed[next_person]);
            cout << "line: " << "16" << " - meetingTimes_var : " << meetingTimes << endl;
            if (meetingTimes != 0)
            {
                countMeeting += meetingTimes;
                cout << "line: " << __LINE__ << " - _CountMeeting: " << countMeeting << endl;
            }
        }
    }
    
    return countMeeting == 0 ? -1 : countMeeting;   
}

int isMeeting(int _pos1, int _speed1, int _pos2, int _speed2)
{
    cout << "_pos: " << _pos1 << endl;
    cout << "_speed1: " << _speed1 << endl;
    cout << "_pos2: " << _pos2 << endl;
    cout << "_speed2: " << _speed2 << endl;
    
    bool _endingLoop = false;
    int meetingTimes = 0;
    
    // nerver meeting when the same pos but different speed
    if (isCheckingMeeting(_pos1,_speed1,_pos2,_speed2,meetingTimes) == -1)
    {
        cout << "line: " << "36" << " - FUNC: " << __FUNCTION__ << " -- same pos and speed" << endl;
        return meetingTimes;
    }

    if (isCheckingMeeting(_pos1,_speed1,_pos2,_speed2,meetingTimes) == 0)
    {
        cout << "line: " << "42" << " - FUNC: " << __FUNCTION__ << " -- could not have meeting" << endl;
        // return 0 for no adding
        return 0;
    }

    bool _flagBigerOfPos1 = _pos1 > _pos2 ? true : false;
    cout << "_flagBigerOfPos1: " << _flagBigerOfPos1 << endl;
    double speedInSecond_1 = static_cast<double>(_speed1 / 60.0);
    double speedInSecond_2 = static_cast<double>(_speed2 / 60.0);
    double _posInDouble1 = static_cast<double>(_pos1);
    double _posInDouble2 = static_cast<double>(_pos2);
    int seconds = 1;

    do
    {
        // upgrade value - for default we already know that they are elems that we need to check because of different pos and speed
        _posInDouble1 += seconds*speedInSecond_1;
        _posInDouble2 += seconds*speedInSecond_2;
        
        cout << "line: " << "60" << " - FUNC: " << __FUNCTION__ << " -- Pos: " << _posInDouble1 << endl;
        cout << "line: " << "61" << " - FUNC: " << __FUNCTION__ << " -- Pos2: " << _posInDouble2 << endl;
        
        if (_posInDouble1 == _posInDouble2)
        {
            cout << "line: " << "65" << " - FUNC: " << __FUNCTION__ << " -- have meeting" << endl;
            return 1;
        }
        
        if (_flagBigerOfPos1 == true)
        {
            cout << "_flagBigerOfPos1: " << _flagBigerOfPos1 << endl;
            if (_posInDouble1 < _posInDouble2)
            {
                cout << "line: " << "73" << " - FUNC: " << __FUNCTION__ << " -- could not have meeting" << endl;
                _endingLoop = true;
            }            
        }
        seconds++;
    } while (_endingLoop);


    // if no meeting we will return 0
    return 0;
}

int isCheckingMeeting(int _pos1, int _speed1, int _pos2, int _speed2, int& meetingTimes)
{
    cout << "line: " << "87" << endl;
    int _isMeeting;
    if (_pos1 == _pos2)
    {
        cout << "line: " << "91" << endl;
        if (_speed1 == _speed2)
        {
            cout << "line: " << "94" << endl;
            // this case for 2 persons who runs in the same speed and start from same position
            // so this will have infinite times for meeting 
            // but we have limit from length of road <= 10^4
            // so we can calculate times for repeating that one
            // maxRoad = road_per_second * times
            // => times = maxRoad / road_per_second;
            meetingTimes = static_cast<int>(std::pow(10,4)/(_speed1/60));
            // no need
            _isMeeting = -1;
        }
        else
        {
            cout << "line: " << "107" << endl;
            _isMeeting = 0;
        }
    }
    else if (_pos1 > _pos2)
    {
        cout << "line: " << "113" << endl;
        if (_speed1 >= _speed2)
        {
            cout << "line: " << "116" << endl;
            // never meeting
            _isMeeting = 0;
        }
        else
        {
            cout << "line: " << "122" << endl;
            // needing for checking
            _isMeeting = 1;
        }
    }
    else
    {
        cout << "line: " << "129" << endl;
        if (_speed1 <= _speed2)
        {
            cout << "line: " << "132" << endl;
            // never meeting
            _isMeeting = 0;
        }
        else
        {
            cout << "line: " << "138" << endl;
            // need for checking
            _isMeeting = 1;
        }
    }
    
    return _isMeeting;
}
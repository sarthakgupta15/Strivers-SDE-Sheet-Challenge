 #include<iostream>
 #include<vector>
 using namespace std;

 /*
    Time Complexity: O(N * log(N)).
    Space Complexity: O(N).

    Where 'N' is the number of meetings.
*/

struct meet
{
    int meetingID;
    int startTime;
    int endTime;
};

bool compare(struct meet a, struct meet b)
{
    if (a.endTime == b.endTime)
    {
        return a.meetingID < b.meetingID;
    }
    else
    {
        return a.endTime < b.endTime;
    }
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    // Creating meeting array of size N.
    struct meet meeting[n];

    for (int i = 0; i < n; i++)
    {
        meeting[i].meetingID = i + 1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];
    }

    // Sorting the meeting array in increasing order of end time using customized comparator.
    sort(meeting, meeting + n, compare);

    // Taking the first meeting of sorted array as our first meeting.
    int ans = 1;
    int currentTime = meeting[0].endTime;

    for (int i = 1; i < n; i++)
    {
        // If startTime of current meeting is greater than our currentTime.

        // Then we will perform this meeting and update currentTime with endTime of the meeting.
        if (meeting[i].startTime > currentTime)
        {
            ans++;
            currentTime = meeting[i].endTime;
        }
    }

    return ans;
} 
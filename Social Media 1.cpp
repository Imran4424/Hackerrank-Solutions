#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

#define MAX_TIMELINE_LENGTH 500
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

double getTweetRank(int timestamp, int followerCount) {
	return timestamp * (0.8 + 0.2 * MIN(followerCount / 10.0, 2.0));
}

void copyString(char *source, char* destination) {
	int i;
	for(i = 0; source[i]; i++) {
		destination[i] = source[i];
	}

	destination[i] = '\0';
}

struct TweetNode
{
	bool tweetStatus = false;
	int tweetID;
	int timestamp
	char tweet_str[142];
	double tweetRank;
};

TweetNode tweetArray[100100];

class User;
User *userArray;

class User {
public:
	// int userID;
	char user_name[33];
	bool active = false;
	int followerCount = 0;

	struct FollowerNode
	{
		int followerID;
		FollowerNode *next;

		FollowerNode() {}
		FollowerNode(int followerID) {
			this -> followerID = followerID;
			next = NULL;
		}
	};

	struct TweetListNode
	{
		int tweetID;
		TweetListNode *next;

		TweetNode() {}
		TweetNode(int tweetID) {
			this -> tweetID = tweetID;
			next = NULL;
		}
	};

	FollowerNode* followerHead = NULL;
	followerHead* myFollowingHead = NULL;
	TweetNode* tweetHead = NULL;

	bool followedBy(int followerID) {
		FollowerNode *temp = new FollowerNode(followerID);

		if(NULL == followerHead) {
			followerHead = temp;
			return true;
		}

		FollowerNode* travel = followerHead;

		while(NULL != travel) {
			if(travel -> followerID == followerID) {
				return false;
			}

			travel = travel -> next;
		}

		temp -> next = followerHead;
		followerHead = temp;

		return true;
	}

	void follow(int followerID) {
		FollowerNode *temp = new FollowerNode(followerID);

		if(NULL == followerHead) {
			followerHead = temp;
			return;
		}

		FollowerNode* travel = followerHead;

		temp -> next = followerHead;
		followerHead = temp;

		followerCount++;
	}

	int tweet(int tweetID, int timestamp, char* tweet_str, double tweetRank) {
		if(tweetArray[tweetID].tweetStatus) {
			return -1;
		}

		tweetArray[tweetID].tweetStatus = true;
		tweetArray[tweetID].tweetID = tweetID;
		tweetArray[tweetID].timestamp = timestamp;
		tweetArray[tweetID].tweetRank = tweetRank;
		copyString(tweet_str, tweetArray[tweetID].tweet_str);

		TweetNode *temp = new TweetNode(tweetID);

		if(NULL == tweetHead) {
			tweetHead = temp;
			return 0;
		}

		TweetNode *travel = tweetHead;

		temp -> next = tweetHead;
		tweetHead = temp;
		return 0;
	}

	void getSortedTimeline() {

	}
};

void init() {
	userArray = new User[1010];
}

int createUser(int userID, const char* name) {
	if(userArray.active) {
		return -1;
	}

	userArray[userID].active = true;
	copyString(name, userArray[userID].user_name);

	return 0;
}

void followUser(int followerID, int followeeID) {
	int status = userArray[followeeID].followedBy(followerID);

	if(status) {
		userArray[followerID].follow(followeeID);
	}
}

int createTweet(int tweetID, int userID, int timestamp, const char* tweet_str) {
	double tweetRank = getTweetRank(timestamp, userArray[userID].followerCount);

	return userArray[userID].tweet(tweetID, timestamp, tweet_str, tweetRank);
}

int getTimeline(int userID, int res[]) {
  	return 0;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		init();
		int N;
		cin >> N;
		while (N--) {
			int event;
			cin >> event;
			if (event == 1) {
				int user_id;
				string user_name;
				cin >> user_id;
				getline(cin, user_name);
				int create_user_result = createUser(user_id, user_name.c_str());
				cout << create_user_result << endl;
			}
			else if (event == 2) {
				int follower, followee;
				cin >> follower;
				cin >> followee;
				followUser(follower, followee);
			}
			else if (event == 3) {
				int tweet_id, user_id, timestamp;
				string tweet_str;
				cin >> tweet_id;
				cin >> user_id;
				cin >> timestamp;
				getline(cin, tweet_str);
				int create_tweet_result = createTweet(tweet_id, user_id, timestamp, tweet_str.c_str());
				cout << create_tweet_result << endl;
			}
			else if (event == 4) {
				int user_id;
				int timeline_result[MAX_TIMELINE_LENGTH];
				cin >> user_id;
				int timeline_size = getTimeline(user_id, timeline_result);
				cout << "[";
				for (int i = 0; i < timeline_size - 1; i++) {
					cout << timeline_result[i] << ", ";
				}
				if (timeline_size > 0)
					cout << timeline_result[timeline_size - 1];
				cout << "]" << endl;
			}
			else {
				assert(false);
			}
		}
	}
	return 0;
}


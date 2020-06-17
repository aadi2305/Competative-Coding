#include <iostream>

using namespace std;

class Hash
{
    private:
        static const int tableSize = 10;
        
        
    public:
        struct item
        {
            string name;
            int goaldiff;
            int points;
            item* next;
        };
        item* HashTable[tableSize];
        Hash()
        {
            for(int i= 0; i< tableSize; i++)
            {
                HashTable[i] = new item;
                HashTable[i]->name = "empty";
                HashTable[i]->goaldiff = 0;
                HashTable[i]->points = 0;
                HashTable[i]->next = NULL;
            }
        }
        int hash(string key)
        {
            int hash_value = 0, index;
            for(int i = 0; i< key.length(); i++)
            {
                hash_value += key[i];
                hash_value = hash_value*(hash_value+key[i]);
            }
            index = hash_value % tableSize;
            if(index <0)
            {
                index = -(index);
            }
            return index;
        };
        void insert(string name, int goaldiff,int points)
        {
            int hash_index = hash(name);
            if(HashTable[hash_index]->name == "empty")
            {
                HashTable[hash_index]->name = name;
                HashTable[hash_index]->goaldiff = goaldiff;
                HashTable[hash_index]->points = points;
            }
            else
            {
                item* temp = HashTable[hash_index];
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                item* ptr = new item;
                ptr->name = name;
                ptr->goaldiff = goaldiff;
                ptr->points = points;
                ptr-> next= NULL;
                temp->next = ptr;
            }
            
        }
        void ShowTheTable()
        {
            for(int i = 0 ; i<tableSize ; i++)
            {
                if(HashTable[i]->name != "empty" && HashTable[i]->next == NULL)
                {
                    cout << "[" << HashTable[i]->name << ", " << HashTable[i]->goaldiff<< ", " << HashTable[i]->points << "]"<< endl;
                    cout << "    |"<< endl;
                }
                else if(HashTable[i]->name != "empty" && HashTable[i]->next != NULL)
                {
                    item* temp = HashTable[i];
                    while(temp!=NULL)
                    {
                       cout << "[" << temp->name << ", " << temp->goaldiff<< ", " << temp->points << "]"<< "--";
                       temp = temp->next; 
                    }
                    cout<< endl;

                    
                }
            }
        }
        bool contains(string name)
        {
            int index = hash(name);
            item* temp = HashTable[index];
            while(temp != NULL)
            {
                if(temp->name == name)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
            
        }
        item* search(string name)
        {
            int index = hash(name);
            item* temp = HashTable[index];
            while(temp->name!= name)
            {
                temp = temp->next;
            }
            return temp;

        }
        void ans()
        {

        }
        int numberOfIndex()
        {
            int counter = 0;
            for(int i=0; i<tableSize; i++)
            {
                if(HashTable[i]->name != "empty" && HashTable[i]->next ==NULL)
                {
                    counter++;
                }
                else if(HashTable[i]->name != "empty" && HashTable[i]->next !=NULL)
                {
                    item* temp = HashTable[i];
                    while(temp!= NULL)
                    {
                        counter++;
                        temp= temp->next;
                    }
                }
            }
            return counter;
        };
};

int main()
{
    int Testcases, homegoal, awaygoal, k=0;
    string team1, team2 ,vs;
    cin >> Testcases;
    string arr[2*Testcases];
    for(int i=0; i<Testcases ; i++)
    {
        Hash a;
        for(int j=0; j<12; j++)
        {
            
            cin >> team1>> homegoal>> vs >> awaygoal>> team2;
            if(!a.contains(team1))
            { 
                    int total = homegoal - awaygoal;
                    if(total > 0)
                    {
                        a.insert(team1, total, 3);  
                    }
                    else if(total == 0)
                    {
                        a.insert(team1, total, 1);  
                    }
                    else
                    {
                        a.insert(team1, total, 0);
                    }
            }
            else
            {
                Hash::item* team1ptr = a.search(team1);
                team1ptr->goaldiff += homegoal;
                team1ptr->goaldiff -= awaygoal;
                if(homegoal - awaygoal > 0)
                {
                    team1ptr->points += 3;
                }
                else if(homegoal - awaygoal == 0)team1ptr->points += 1;
            }
            if(!a.contains(team2))
            { 
                    int total = awaygoal - homegoal;
                    if(total > 0)
                    {
                        a.insert(team2, total, 3);  
                    }
                    else if(total == 0)
                    {
                        a.insert(team2, total, 1);  
                    }
                    else
                    {
                        a.insert(team2, total, 0);
                    }
            
            }
            else
            {
                Hash::item* team1ptr ;
                team1ptr = a.search(team2);
                team1ptr->goaldiff -= homegoal;
                team1ptr->goaldiff += awaygoal;
                if(awaygoal- homegoal> 0)
                {
                    team1ptr->points += 3;
                }
                else if(awaygoal- homegoal == 0)team1ptr->points += 1;
            }
            
        }
        Hash::item* rank1 = new Hash::item;
        Hash::item* rank2 =  new Hash::item;;
        rank1->name = "empty";
        rank2->name = "empty";
        rank1->goaldiff = 0;
        rank2->goaldiff = 0;
        rank1->points = 0;
        rank2->points = 0;

        int max_score = 0;
        for(int i = 0; i< 10; i++)
        {
            Hash::item* temp = a.HashTable[i];
            do
            {
                if(max_score < temp->points)
                {
                    max_score = temp->points;
                    rank2 = rank1;
                    rank1 = temp;
                }
                else if(max_score == temp-> points && max_score != 0)
                {
                    if(rank1->goaldiff < temp->goaldiff)
                    {
                        rank2 = rank1;
                        rank1 = temp;
                    }
                    else if(rank2-> goaldiff < temp->goaldiff)
                    {
                        rank2 = temp;
                    }
                }
                temp = temp->next;
            }while(temp !=NULL);
            
        }
        arr[k] = rank1->name;
        k++;
        arr[k] = rank2->name; 
        k++;
    }
    k = 0;
    for(int i=0; i<Testcases ; i++)
    {
        cout<< arr[k];
        k++;
        cout<< " "<< arr[k]<< endl;
        k++;
        
    }
}
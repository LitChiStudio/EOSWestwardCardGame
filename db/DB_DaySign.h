#ifndef TEMPLET_DB_DaySign_H
#define TEMPLET_DB_DaySign_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_DaySign_Data
{
int id;
string rewards;
};
class DB_DaySign;
static DB_DaySign* DB_DaySign_instanse = nullptr;
class DB_DaySign
{
public:
static DB_DaySign* getInstanse()
{
    if(DB_DaySign_instanse)
        return  DB_DaySign_instanse;
        DB_DaySign_instanse = new DB_DaySign();
    return  DB_DaySign_instanse;
}
int getCount()
{
    return db_data.size();
}
vector<int> getAllIds()
{
    vector<int> ids;
    for(auto &it : db_data)
    {
        ids.push_back(it.first);
    }
    return ids;
}
const DB_DaySign_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_DaySign_Data> db_data;
public:
DB_DaySign()
{
    db_data[1] = {1,"2,100|1,100000|18000,6|16000,10"};
    db_data[2] = {2,"2,100|1,100000|18000,6|16000,10"};
    db_data[3] = {3,"2,200|1,100000|18000,6|16000,10"};
    db_data[4] = {4,"2,300|1,100000|18000,6|16000,10"};
    db_data[5] = {5,"2,400|1,100000|18000,6|16000,10"};
    db_data[6] = {6,"2,450|1,100000|18000,6|16000,10"};
    db_data[7] = {7,"2,500|1,200000|18000,6|16000,10"};
}
};
#endif //TEMPLET_DB_BATTLEAI_H

# Manuel-Project3
vg101 project 3
Singleton 是单例， 但我还不清楚怎么用，先放在那里
Vehicle 这个类我把index(size)这个attribute取消了，原因是我有一个map来联系一辆车和它停车的单价。
Map：
map是这样的，map<key, value> 在map中每个key都对应唯一的一个value. 有一个find函数 find(key),返回的是指向那一组的迭代器的指针（iterator），可以被理解为
一个结构体，里面有两个成员，first和second。
而iterator.first 就是key，iterator.second就是value。

范围for：
for(auto & iter: typePrice) 被称为范围for语句，用处是遍历某个对象， iter是迭代器的名字， typePrice是我要遍历的对象，&是引用（reference）的标志，
auto代表编译器自动帮我判断iter的类型， 它如果被完整地写出来应该是TypePrice::iterator, 由于这个名字太长了，所以用auto。

Vehicle里面

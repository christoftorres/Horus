
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_2__1_0__2__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__1_0__2__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [1,0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_2__0_1__1__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1__1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_1__0__1 {
using t_tuple = Tuple<RamDomain, 1>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[1];
std::copy(ramDomain, ramDomain + 1, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0) {
RamDomain data[1] = {a0};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_1__0__1& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_9__2_8_1_3_4_6__1_2_3_6_8_0_4_5_7__4__260__286__334__350__511 {
using t_tuple = Tuple<RamDomain, 9>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,8,1,3,4,6>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,3,6,8,0,4,5,7>>>;
t_ind_1 ind_1;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator = iterator_1;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
const t_tuple* masterCopy = nullptr;
{
auto lease = insert_lock.acquire();
if (contains(t, h)) return false;
masterCopy = &dataTable.insert(t);
ind_1.insert(masterCopy, h.hints_1);
}
ind_0.insert(masterCopy, h.hints_0);
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[9];
std::copy(ramDomain, ramDomain + 9, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7,RamDomain a8) {
RamDomain data[9] = {a0,a1,a2,a3,a4,a5,a6,a7,a8};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_1.contains(&t, h.hints_1);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_1.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_1.find(&t, h.hints_1);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator_0> equalRange_4(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
low[8] = MIN_RAM_DOMAIN;
high[8] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_4(const t_tuple& t) const {
context h; return equalRange_4(t, h);
}
range<iterator_0> equalRange_260(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_260(const t_tuple& t) const {
context h; return equalRange_260(t, h);
}
range<iterator_0> equalRange_286(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_286(const t_tuple& t) const {
context h; return equalRange_286(t, h);
}
range<iterator_1> equalRange_334(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_334(const t_tuple& t) const {
context h; return equalRange_334(t, h);
}
range<iterator_0> equalRange_350(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_350(const t_tuple& t) const {
context h; return equalRange_350(t, h);
}
range<iterator_1> equalRange_511(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_1> equalRange_511(const t_tuple& t) const {
context h; return equalRange_511(t, h);
}
bool empty() const {
return ind_1.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_1.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
dataTable.clear();
}
iterator begin() const {
return ind_1.begin();
}
iterator end() const {
return ind_1.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,8,1,3,4,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,2,3,6,8,0,4,5,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_2_3__15 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_2__0_1__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_3__0_1_2__7 {
using t_tuple = Tuple<RamDomain, 3>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2__7& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__0_1_2_3_4__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3,4>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[5];
std::copy(ramDomain, ramDomain + 5, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4) {
RamDomain data[5] = {a0,a1,a2,a3,a4};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_5__0_1_2_3_4__31& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t) const {
context h;
return equalRange_31(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 5 direct b-tree index [0,1,2,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__0_4_1_2_3__1__17__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,4,1,2,3>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[5];
std::copy(ramDomain, ramDomain + 5, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4) {
RamDomain data[5] = {a0,a1,a2,a3,a4};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_5__0_4_1_2_3__1__17__31& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_0::iterator> equalRange_17(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_17(const t_tuple& t) const {
context h;
return equalRange_17(t, h);
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t) const {
context h;
return equalRange_31(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 5 direct b-tree index [0,4,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__3_0_1_2__8__15 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<3,0,1,2>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__3_0_1_2__8__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_8(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_8(const t_tuple& t) const {
context h;
return equalRange_8(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [3,0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_6__1_0_2_3_4_5__2__63 {
using t_tuple = Tuple<RamDomain, 6>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,2,3,4,5>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[6];
std::copy(ramDomain, ramDomain + 6, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5) {
RamDomain data[6] = {a0,a1,a2,a3,a4,a5};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_6__1_0_2_3_4_5__2__63& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t) const {
context h;
return equalRange_63(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [1,0,2,3,4,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_6__0_1_2_3_4_5__63 {
using t_tuple = Tuple<RamDomain, 6>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3,4,5>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[6];
std::copy(ramDomain, ramDomain + 6, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5) {
RamDomain data[6] = {a0,a1,a2,a3,a4,a5};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_6__0_1_2_3_4_5__63& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t) const {
context h;
return equalRange_63(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [0,1,2,3,4,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_7__1_4_5_6__1_2_5_6_0_3_4__2__102__114__127 {
using t_tuple = Tuple<RamDomain, 7>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,4,5,6>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,5,6,0,3,4>>>;
t_ind_1 ind_1;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator = iterator_1;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
const t_tuple* masterCopy = nullptr;
{
auto lease = insert_lock.acquire();
if (contains(t, h)) return false;
masterCopy = &dataTable.insert(t);
ind_1.insert(masterCopy, h.hints_1);
}
ind_0.insert(masterCopy, h.hints_0);
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[7];
std::copy(ramDomain, ramDomain + 7, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6) {
RamDomain data[7] = {a0,a1,a2,a3,a4,a5,a6};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_1.contains(&t, h.hints_1);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_1.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_1.find(&t, h.hints_1);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator_1> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_2(const t_tuple& t) const {
context h; return equalRange_2(t, h);
}
range<iterator_1> equalRange_102(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_102(const t_tuple& t) const {
context h; return equalRange_102(t, h);
}
range<iterator_0> equalRange_114(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_114(const t_tuple& t) const {
context h; return equalRange_114(t, h);
}
range<iterator_1> equalRange_127(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_1> equalRange_127(const t_tuple& t) const {
context h; return equalRange_127(t, h);
}
bool empty() const {
return ind_1.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_1.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
dataTable.clear();
}
iterator begin() const {
return ind_1.begin();
}
iterator end() const {
return ind_1.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [1,4,5,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [1,2,5,6,0,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__1_0_2_3__2__15 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,2,3>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__1_0_2_3__2__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [1,0,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

class Sf_analyzer : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
private:
static inline RamDomain wrapper_tonumber(const std::string& str) {
   RamDomain result=0; 
   try { result = stord(str); } catch(...) { 
     std::cerr << "error: wrong string provided by to_number(\"";
     std::cerr << str << "\") functor.\n";
     raise(SIGFPE);
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable
{
	R"_(CALLER)_",
	R"_(SLOAD)_",
	R"_(JUMPI)_",
	R"_(CALL)_",
	R"_(0)_",
	R"_(DELEGATECALL)_",
	R"_(CREATE)_",
	R"_(CALLDATALOAD)_",
	R"_(ADD)_",
	R"_(SSTORE)_",
	R"_(MUL)_",
	R"_(SUB)_",
	R"_(AND)_",
	R"_(1461501637330902918203684832716283019655932542975)_",
	R"_(out of gas)_",
	R"_(TIMESTAMP)_",
	R"_(ORIGIN)_",
	R"_(BLOCKHASH)_",
	R"_(COINBASE)_",
	R"_(NUMBER)_",
	R"_(DIFFICULTY)_",
	R"_(GASLIMIT)_",
};// -- Table: def
std::unique_ptr<t_btree_2__1_0__2__3> rel_1_def = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<0,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_1_def;
// -- Table: use
std::unique_ptr<t_btree_2__1_0__2__3> rel_2_use = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<1,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_2_use;
// -- Table: data_flow
std::unique_ptr<t_btree_2__0_1__1__3> rel_3_data_flow = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<2,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_3_data_flow;
// -- Table: @delta_data_flow
std::unique_ptr<t_btree_2__0_1__1__3> rel_4_delta_data_flow = std::make_unique<t_btree_2__0_1__1__3>();
// -- Table: @new_data_flow
std::unique_ptr<t_btree_2__0_1__1__3> rel_5_new_data_flow = std::make_unique<t_btree_2__0_1__1__3>();
// -- Table: caller_check
std::unique_ptr<t_btree_1__0__1> rel_6_caller_check = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<3,t_btree_1__0__1,Tuple<RamDomain,1>,1,1> wrapper_rel_6_caller_check;
// -- Table: +disconnected0
std::unique_ptr<t_nullaries> rel_7_disconnected0 = std::make_unique<t_nullaries>();
souffle::RelationWrapper<4,t_nullaries,Tuple<RamDomain,0>,0,1> wrapper_rel_7_disconnected0;
// -- Table: +disconnected1
std::unique_ptr<t_nullaries> rel_8_disconnected1 = std::make_unique<t_nullaries>();
souffle::RelationWrapper<5,t_nullaries,Tuple<RamDomain,0>,0,1> wrapper_rel_8_disconnected1;
// -- Table: call
std::unique_ptr<t_btree_9__2_8_1_3_4_6__1_2_3_6_8_0_4_5_7__4__260__286__334__350__511> rel_9_call = std::make_unique<t_btree_9__2_8_1_3_4_6__1_2_3_6_8_0_4_5_7__4__260__286__334__350__511>();
souffle::RelationWrapper<6,t_btree_9__2_8_1_3_4_6__1_2_3_6_8_0_4_5_7__4__260__286__334__350__511,Tuple<RamDomain,9>,9,1> wrapper_rel_9_call;
// -- Table: BlockStateDependence
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_10_BlockStateDependence = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<7,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_10_BlockStateDependence;
// -- Table: CallStackDepth
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_11_CallStackDepth = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<8,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_11_CallStackDepth;
// -- Table: CreateBasedReentrancy
std::unique_ptr<t_btree_2__0_1__3> rel_12_CreateBasedReentrancy = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<9,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_12_CreateBasedReentrancy;
// -- Table: CrossFunctionReentrancy
std::unique_ptr<t_btree_2__0_1__3> rel_13_CrossFunctionReentrancy = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<10,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_13_CrossFunctionReentrancy;
// -- Table: DelegatedReentrancy
std::unique_ptr<t_btree_3__0_1_2__7> rel_14_DelegatedReentrancy = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<11,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_14_DelegatedReentrancy;
// -- Table: Reentrancy
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_15_Reentrancy = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<12,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_15_Reentrancy;
// -- Table: TimestampDependence
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_16_TimestampDependence = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<13,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_16_TimestampDependence;
// -- Table: UncheckedDelegatecall
std::unique_ptr<t_btree_3__0_1_2__7> rel_17_UncheckedDelegatecall = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<14,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_17_UncheckedDelegatecall;
// -- Table: UnhandledException
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_18_UnhandledException = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<15,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_18_UnhandledException;
// -- Table: block
std::unique_ptr<t_btree_3__0_1_2__7> rel_19_block = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<16,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_19_block;
// -- Table: error
std::unique_ptr<t_btree_2__0_1__3> rel_20_error = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<17,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_20_error;
// -- Table: transaction
std::unique_ptr<t_btree_5__0_4_1_2_3__1__17__31> rel_21_transaction = std::make_unique<t_btree_5__0_4_1_2_3__1__17__31>();
souffle::RelationWrapper<18,t_btree_5__0_4_1_2_3__1__17__31,Tuple<RamDomain,5>,5,1> wrapper_rel_21_transaction;
// -- Table: DoSWithBlockGasLimit
std::unique_ptr<t_btree_3__0_1_2__7> rel_22_DoSWithBlockGasLimit = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<19,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_22_DoSWithBlockGasLimit;
// -- Table: TransactionStateDependence
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_23_TransactionStateDependence = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<20,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_23_TransactionStateDependence;
// -- Table: throw
std::unique_ptr<t_btree_4__3_0_1_2__8__15> rel_24_throw = std::make_unique<t_btree_4__3_0_1_2__8__15>();
souffle::RelationWrapper<21,t_btree_4__3_0_1_2__8__15,Tuple<RamDomain,4>,4,1> wrapper_rel_24_throw;
// -- Table: DoSWithUnexpectedThrow
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_25_DoSWithUnexpectedThrow = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<22,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_25_DoSWithUnexpectedThrow;
// -- Table: arithmetic
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_26_arithmetic = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<23,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_26_arithmetic;
// -- Table: IntegerOverflow
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_IntegerOverflow = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_27_IntegerOverflow;
// -- Table: IntegerUnderflow
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_28_IntegerUnderflow = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<25,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_28_IntegerUnderflow;
// -- Table: storage
std::unique_ptr<t_btree_7__1_4_5_6__1_2_5_6_0_3_4__2__102__114__127> rel_29_storage = std::make_unique<t_btree_7__1_4_5_6__1_2_5_6_0_3_4__2__102__114__127>();
souffle::RelationWrapper<26,t_btree_7__1_4_5_6__1_2_5_6_0_3_4__2__102__114__127,Tuple<RamDomain,7>,7,1> wrapper_rel_29_storage;
// -- Table: ParityWalletHack1
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_30_ParityWalletHack1 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<27,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_30_ParityWalletHack1;
// -- Table: TransactionOrderDependency
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_31_TransactionOrderDependency = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<28,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_31_TransactionOrderDependency;
// -- Table: selfdestruct
std::unique_ptr<t_btree_3__0_1_2__7> rel_32_selfdestruct = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<29,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_32_selfdestruct;
// -- Table: ParityWalletHack2
std::unique_ptr<t_btree_3__0_1_2__7> rel_33_ParityWalletHack2 = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<30,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_33_ParityWalletHack2;
// -- Table: UncheckedSuicide
std::unique_ptr<t_btree_3__0_1_2__7> rel_34_UncheckedSuicide = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<31,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_34_UncheckedSuicide;
// -- Table: bitwise_logic
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_35_bitwise_logic = std::make_unique<t_btree_4__1_0_2_3__2__15>();
souffle::RelationWrapper<32,t_btree_4__1_0_2_3__2__15,Tuple<RamDomain,4>,4,1> wrapper_rel_35_bitwise_logic;
// -- Table: ShortAddress
std::unique_ptr<t_btree_2__0_1__3> rel_36_ShortAddress = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<33,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_36_ShortAddress;
public:
Sf_analyzer() : 
wrapper_rel_1_def(*rel_1_def,symTable,"def",std::array<const char *,2>{{"i:number","s:Opcode"}},std::array<const char *,2>{{"step","opcode"}}),

wrapper_rel_2_use(*rel_2_use,symTable,"use",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"step1","step2"}}),

wrapper_rel_3_data_flow(*rel_3_data_flow,symTable,"data_flow",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"x","y"}}),

wrapper_rel_6_caller_check(*rel_6_caller_check,symTable,"caller_check",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"step"}}),

wrapper_rel_7_disconnected0(*rel_7_disconnected0,symTable,"+disconnected0",std::array<const char *,0>{{}},std::array<const char *,0>{{}}),

wrapper_rel_8_disconnected1(*rel_8_disconnected1,symTable,"+disconnected1",std::array<const char *,0>{{}},std::array<const char *,0>{{}}),

wrapper_rel_9_call(*rel_9_call,symTable,"call",std::array<const char *,9>{{"i:number","s:symbol","s:Opcode","s:Address","s:Address","s:symbol","s:Value","i:number","i:number"}},std::array<const char *,9>{{"step","hash","opcode","caller","callee","input_data","amount","depth","success"}}),

wrapper_rel_10_BlockStateDependence(*rel_10_BlockStateDependence,symTable,"BlockStateDependence",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_11_CallStackDepth(*rel_11_CallStackDepth,symTable,"CallStackDepth",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_12_CreateBasedReentrancy(*rel_12_CreateBasedReentrancy,symTable,"CreateBasedReentrancy",std::array<const char *,2>{{"s:symbol","s:Address"}},std::array<const char *,2>{{"hash","contract"}}),

wrapper_rel_13_CrossFunctionReentrancy(*rel_13_CrossFunctionReentrancy,symTable,"CrossFunctionReentrancy",std::array<const char *,2>{{"s:symbol","s:Address"}},std::array<const char *,2>{{"hash","contract"}}),

wrapper_rel_14_DelegatedReentrancy(*rel_14_DelegatedReentrancy,symTable,"DelegatedReentrancy",std::array<const char *,3>{{"s:symbol","s:Address","s:Address"}},std::array<const char *,3>{{"hash","caller","callee"}}),

wrapper_rel_15_Reentrancy(*rel_15_Reentrancy,symTable,"Reentrancy",std::array<const char *,5>{{"s:symbol","s:Address","s:Address","s:Value","i:number"}},std::array<const char *,5>{{"hash","caller","callee","amount","depth"}}),

wrapper_rel_16_TimestampDependence(*rel_16_TimestampDependence,symTable,"TimestampDependence",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_17_UncheckedDelegatecall(*rel_17_UncheckedDelegatecall,symTable,"UncheckedDelegatecall",std::array<const char *,3>{{"i:number","s:Address","s:Address"}},std::array<const char *,3>{{"step","caller","callee"}}),

wrapper_rel_18_UnhandledException(*rel_18_UnhandledException,symTable,"UnhandledException",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_19_block(*rel_19_block,symTable,"block",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"block","gasUsed","gasLimit"}}),

wrapper_rel_20_error(*rel_20_error,symTable,"error",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"hash","error_message"}}),

wrapper_rel_21_transaction(*rel_21_transaction,symTable,"transaction",std::array<const char *,5>{{"s:symbol","s:Address","s:Address","s:symbol","i:number"}},std::array<const char *,5>{{"hash","from","to","input_data","block"}}),

wrapper_rel_22_DoSWithBlockGasLimit(*rel_22_DoSWithBlockGasLimit,symTable,"DoSWithBlockGasLimit",std::array<const char *,3>{{"s:Address","s:Address","s:Value"}},std::array<const char *,3>{{"caller","callee","amount"}}),

wrapper_rel_23_TransactionStateDependence(*rel_23_TransactionStateDependence,symTable,"TransactionStateDependence",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_24_throw(*rel_24_throw,symTable,"throw",std::array<const char *,4>{{"i:number","s:Opcode","s:Address","i:number"}},std::array<const char *,4>{{"step","opcode","caller","depth"}}),

wrapper_rel_25_DoSWithUnexpectedThrow(*rel_25_DoSWithUnexpectedThrow,symTable,"DoSWithUnexpectedThrow",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_26_arithmetic(*rel_26_arithmetic,symTable,"arithmetic",std::array<const char *,6>{{"i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,6>{{"step","opcode","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_27_IntegerOverflow(*rel_27_IntegerOverflow,symTable,"IntegerOverflow",std::array<const char *,6>{{"i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,6>{{"step","opcode","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_28_IntegerUnderflow(*rel_28_IntegerUnderflow,symTable,"IntegerUnderflow",std::array<const char *,5>{{"i:number","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,5>{{"step","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_29_storage(*rel_29_storage,symTable,"storage",std::array<const char *,7>{{"i:number","s:Opcode","i:number","s:Value","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"step","opcode","block","transaction","caller","contract","storage_index"}}),

wrapper_rel_30_ParityWalletHack1(*rel_30_ParityWalletHack1,symTable,"ParityWalletHack1",std::array<const char *,4>{{"i:number","s:Address","s:Address","s:Value"}},std::array<const char *,4>{{"step","caller","callee","amount"}}),

wrapper_rel_31_TransactionOrderDependency(*rel_31_TransactionOrderDependency,symTable,"TransactionOrderDependency",std::array<const char *,4>{{"s:Value","s:Value","i:number","s:Value"}},std::array<const char *,4>{{"transaction1","transaction2","block","storage_index"}}),

wrapper_rel_32_selfdestruct(*rel_32_selfdestruct,symTable,"selfdestruct",std::array<const char *,3>{{"i:number","s:Address","s:Address"}},std::array<const char *,3>{{"step","caller","destination"}}),

wrapper_rel_33_ParityWalletHack2(*rel_33_ParityWalletHack2,symTable,"ParityWalletHack2",std::array<const char *,3>{{"i:number","s:Address","s:Address"}},std::array<const char *,3>{{"step","caller","destination"}}),

wrapper_rel_34_UncheckedSuicide(*rel_34_UncheckedSuicide,symTable,"UncheckedSuicide",std::array<const char *,3>{{"i:number","s:Address","s:Address"}},std::array<const char *,3>{{"step","caller","destination"}}),

wrapper_rel_35_bitwise_logic(*rel_35_bitwise_logic,symTable,"bitwise_logic",std::array<const char *,4>{{"i:number","s:Opcode","s:Value","s:Value"}},std::array<const char *,4>{{"step","opcode","first_operand","second_operand"}}),

wrapper_rel_36_ShortAddress(*rel_36_ShortAddress,symTable,"ShortAddress",std::array<const char *,2>{{"s:symbol","i:number"}},std::array<const char *,2>{{"hash","step"}}){
addRelation("def",&wrapper_rel_1_def,true,false);
addRelation("use",&wrapper_rel_2_use,true,false);
addRelation("data_flow",&wrapper_rel_3_data_flow,false,false);
addRelation("caller_check",&wrapper_rel_6_caller_check,false,false);
addRelation("+disconnected0",&wrapper_rel_7_disconnected0,false,false);
addRelation("+disconnected1",&wrapper_rel_8_disconnected1,false,false);
addRelation("call",&wrapper_rel_9_call,true,false);
addRelation("BlockStateDependence",&wrapper_rel_10_BlockStateDependence,false,true);
addRelation("CallStackDepth",&wrapper_rel_11_CallStackDepth,false,true);
addRelation("CreateBasedReentrancy",&wrapper_rel_12_CreateBasedReentrancy,false,true);
addRelation("CrossFunctionReentrancy",&wrapper_rel_13_CrossFunctionReentrancy,false,true);
addRelation("DelegatedReentrancy",&wrapper_rel_14_DelegatedReentrancy,false,true);
addRelation("Reentrancy",&wrapper_rel_15_Reentrancy,false,true);
addRelation("TimestampDependence",&wrapper_rel_16_TimestampDependence,false,true);
addRelation("UncheckedDelegatecall",&wrapper_rel_17_UncheckedDelegatecall,false,true);
addRelation("UnhandledException",&wrapper_rel_18_UnhandledException,false,true);
addRelation("block",&wrapper_rel_19_block,true,false);
addRelation("error",&wrapper_rel_20_error,true,false);
addRelation("transaction",&wrapper_rel_21_transaction,true,false);
addRelation("DoSWithBlockGasLimit",&wrapper_rel_22_DoSWithBlockGasLimit,false,true);
addRelation("TransactionStateDependence",&wrapper_rel_23_TransactionStateDependence,false,true);
addRelation("throw",&wrapper_rel_24_throw,true,false);
addRelation("DoSWithUnexpectedThrow",&wrapper_rel_25_DoSWithUnexpectedThrow,false,true);
addRelation("arithmetic",&wrapper_rel_26_arithmetic,true,false);
addRelation("IntegerOverflow",&wrapper_rel_27_IntegerOverflow,false,true);
addRelation("IntegerUnderflow",&wrapper_rel_28_IntegerUnderflow,false,true);
addRelation("storage",&wrapper_rel_29_storage,true,false);
addRelation("ParityWalletHack1",&wrapper_rel_30_ParityWalletHack1,false,true);
addRelation("TransactionOrderDependency",&wrapper_rel_31_TransactionOrderDependency,false,true);
addRelation("selfdestruct",&wrapper_rel_32_selfdestruct,true,false);
addRelation("ParityWalletHack2",&wrapper_rel_33_ParityWalletHack2,false,true);
addRelation("UncheckedSuicide",&wrapper_rel_34_UncheckedSuicide,false,true);
addRelation("bitwise_logic",&wrapper_rel_35_bitwise_logic,true,false);
addRelation("ShortAddress",&wrapper_rel_36_ShortAddress,false,true);
}
~Sf_analyzer() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(_OPENMP)
if (getNumThreads() > 0) {omp_set_num_threads(getNumThreads());}
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_1_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(data_flow(x,x) :- 
   use(x,_).
in file lib/horus.dl [5:1-6:13])_");
if(!(rel_2_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_2_use_op_ctxt,rel_2_use->createContext());
for(const auto& env0 : *rel_2_use) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[0])}};
rel_3_data_flow->insert(tuple,READ_OP_CONTEXT(rel_3_data_flow_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(data_flow(x,x) :- 
   def(x,_).
in file lib/horus.dl [8:1-9:13])_");
if(!(rel_1_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
for(const auto& env0 : *rel_1_def) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[0])}};
rel_3_data_flow->insert(tuple,READ_OP_CONTEXT(rel_3_data_flow_op_ctxt));
}
}
();}
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   def(x,_),
   use(y,x).
in file lib/horus.dl [11:1-13:13])_");
if(!(rel_2_use->empty()) && !(rel_1_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_2_use_op_ctxt,rel_2_use->createContext());
for(const auto& env0 : *rel_1_def) {
const Tuple<RamDomain,2> key{{0,env0[0]}};
auto range = rel_2_use->equalRange_2(key,READ_OP_CONTEXT(rel_2_use_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0])}};
rel_3_data_flow->insert(tuple,READ_OP_CONTEXT(rel_3_data_flow_op_ctxt));
}
}
}
();}
rel_4_delta_data_flow->insertAll(*rel_3_data_flow);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   data_flow(x,z),
   data_flow(z,y).
in file lib/horus.dl [15:1-17:19])_");
if(!(rel_3_data_flow->empty()) && !(rel_4_delta_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_delta_data_flow_op_ctxt,rel_4_delta_data_flow->createContext());
CREATE_OP_CONTEXT(rel_5_new_data_flow_op_ctxt,rel_5_new_data_flow->createContext());
for(const auto& env0 : *rel_4_delta_data_flow) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_3_data_flow->equalRange_1(key,READ_OP_CONTEXT(rel_3_data_flow_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) && !(rel_4_delta_data_flow->contains(Tuple<RamDomain,2>{{env0[1],env1[1]}},READ_OP_CONTEXT(rel_4_delta_data_flow_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_5_new_data_flow->insert(tuple,READ_OP_CONTEXT(rel_5_new_data_flow_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   data_flow(x,z),
   data_flow(z,y).
in file lib/horus.dl [15:1-17:19])_");
if(!(rel_4_delta_data_flow->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_delta_data_flow_op_ctxt,rel_4_delta_data_flow->createContext());
CREATE_OP_CONTEXT(rel_5_new_data_flow_op_ctxt,rel_5_new_data_flow->createContext());
for(const auto& env0 : *rel_3_data_flow) {
const Tuple<RamDomain,2> key{{env0[1],0}};
auto range = rel_4_delta_data_flow->equalRange_1(key,READ_OP_CONTEXT(rel_4_delta_data_flow_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[1]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_5_new_data_flow->insert(tuple,READ_OP_CONTEXT(rel_5_new_data_flow_op_ctxt));
}
}
}
}
();}
if(rel_5_new_data_flow->empty()) break;
rel_3_data_flow->insertAll(*rel_5_new_data_flow);
std::swap(rel_4_delta_data_flow, rel_5_new_data_flow);
rel_5_new_data_flow->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_4_delta_data_flow->purge();
if (!isHintsProfilingEnabled()) rel_5_new_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_2_use->purge();
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(caller_check(step3) :- 
   def(step1,"CALLER"),
   def(step2,"SLOAD"),
   def(step3,"JUMPI"),
   data_flow(step1,step3),
   data_flow(step2,step3).
in file lib/horus.dl [20:1-25:27])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_6_caller_check_op_ctxt,rel_6_caller_check->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(0)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(1)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env2 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt)) && rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
Tuple<RamDomain,1> tuple{{static_cast<RamDomain>(env2[0])}};
rel_6_caller_check->insert(tuple,READ_OP_CONTEXT(rel_6_caller_check_op_ctxt));
}
}
}
}
}
();}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(+disconnected0() :- 
   !caller_check(_).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [110:1-115:17])_");
if(rel_7_disconnected0->empty()) {
[&](){
CREATE_OP_CONTEXT(rel_7_disconnected0_op_ctxt,rel_7_disconnected0->createContext());
CREATE_OP_CONTEXT(rel_6_caller_check_op_ctxt,rel_6_caller_check->createContext());
if(!(!rel_6_caller_check->equalRange_0(Tuple<RamDomain,1>{{0}},READ_OP_CONTEXT(rel_6_caller_check_op_ctxt)).empty())) {
Tuple<RamDomain,0> tuple{{}};
rel_7_disconnected0->insert(tuple,READ_OP_CONTEXT(rel_7_disconnected0_op_ctxt));
}
}
();}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(+disconnected1() :- 
   !caller_check(_).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [100:1-105:17])_");
if(rel_8_disconnected1->empty()) {
[&](){
CREATE_OP_CONTEXT(rel_6_caller_check_op_ctxt,rel_6_caller_check->createContext());
CREATE_OP_CONTEXT(rel_8_disconnected1_op_ctxt,rel_8_disconnected1->createContext());
if(!(!rel_6_caller_check->equalRange_0(Tuple<RamDomain,1>{{0}},READ_OP_CONTEXT(rel_6_caller_check_op_ctxt)).empty())) {
Tuple<RamDomain,0> tuple{{}};
rel_8_disconnected1->insert(tuple,READ_OP_CONTEXT(rel_8_disconnected1_op_ctxt));
}
}
();}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_9_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(step1,caller,callee,amount) :- 
   def(step1,"BLOCKHASH"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [218:1-248:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt,rel_10_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(17)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_10_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(step1,caller,callee,amount) :- 
   def(step1,"COINBASE"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [218:1-248:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt,rel_10_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(18)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_10_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(step1,caller,callee,amount) :- 
   def(step1,"NUMBER"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [218:1-248:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt,rel_10_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(19)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_10_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(step1,caller,callee,amount) :- 
   def(step1,"DIFFICULTY"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [218:1-248:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt,rel_10_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(20)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_10_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(step1,caller,callee,amount) :- 
   def(step1,"GASLIMIT"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [218:1-248:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt,rel_10_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(21)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_10_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_10_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CallStackDepth(step,caller,callee,amount) :- 
   call(step,_,"CALL",caller,callee,_,amount,depth,_),
   depth > 1024.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [5:1-7:16])_");
if(!(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_11_CallStackDepth_op_ctxt,rel_11_CallStackDepth->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,0}};
auto range = rel_9_call->equalRange_4(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[7]) > (RamDomain(1024)))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_11_CallStackDepth->insert(tuple,READ_OP_CONTEXT(rel_11_CallStackDepth_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CreateBasedReentrancy(hash,caller) :- 
   call(_,hash,"CREATE",caller,_,_,amount,depth1,1),
   call(_,hash,"CREATE",caller,_,_,amount,depth2,1),
   depth1 < depth2.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [42:1-45:19])_");
if(!(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_12_CreateBasedReentrancy_op_ctxt,rel_12_CreateBasedReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(6),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(6),env0[3],0,0,env0[6],0,RamDomain(1)}};
auto range = rel_9_call->equalRange_334(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7]))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[3])}};
rel_12_CreateBasedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_12_CreateBasedReentrancy_op_ctxt));
break;
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcontract"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_12_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CrossFunctionReentrancy(hash,callee) :- 
   call(_,hash,"CALL",caller,callee,input_data1,amount1,depth1,1),
   call(_,hash,"CALL",callee,caller,_,amount2,depth2,1),
   call(_,hash,"CALL",caller,callee,input_data3,amount1,depth3,1),
   depth1 < depth2,
   depth2 < depth3,
   input_data1 != input_data3,
   "0" not_match amount2.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [21:1-28:24])_");
if(!(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_13_CrossFunctionReentrancy_op_ctxt,rel_13_CrossFunctionReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(3),env0[4],env0[3],0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_286(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(3),env0[3],env0[4],0,env0[6],0,RamDomain(1)}};
auto range = rel_9_call->equalRange_350(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[7]) < (env2[7])) && ((env0[5]) != (env2[5]))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[4])}};
rel_13_CrossFunctionReentrancy->insert(tuple,READ_OP_CONTEXT(rel_13_CrossFunctionReentrancy_op_ctxt));
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcontract"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_13_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DelegatedReentrancy(hash,caller,callee) :- 
   call(_,hash,"DELEGATECALL",caller,callee,_,amount,depth1,1),
   call(_,hash,"DELEGATECALL",caller,callee,_,amount,depth2,1),
   depth1 < depth2,
   "0" not_match amount.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [33:1-37:23])_");
if(!(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_14_DelegatedReentrancy_op_ctxt,rel_14_DelegatedReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(5),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(5),env0[3],env0[4],0,env0[6],0,RamDomain(1)}};
auto range = rel_9_call->equalRange_350(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7]))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4])}};
rel_14_DelegatedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_14_DelegatedReentrancy_op_ctxt));
break;
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcaller\tcallee"},{"filename","./DelegatedReentrancy.csv"},{"name","DelegatedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(Reentrancy(hash,caller,callee,amount,depth1) :- 
   call(_,hash,"CALL",caller,callee,_,amount,depth1,1),
   call(_,hash,"CALL",caller,callee,_,amount,depth2,1),
   depth1 < depth2,
   "0" not_match amount.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [12:1-16:23])_");
if(!(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_15_Reentrancy_op_ctxt,rel_15_Reentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(3),env0[3],env0[4],0,env0[6],0,RamDomain(1)}};
auto range = rel_9_call->equalRange_350(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7]))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6]),static_cast<RamDomain>(env0[7])}};
rel_15_Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_15_Reentrancy_op_ctxt));
break;
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcaller\tcallee\tamount\tdepth"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TimestampDependence(step1,caller,callee,amount) :- 
   def(step1,"TIMESTAMP"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,_,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [194:1-200:17])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_16_TimestampDependence_op_ctxt,rel_16_TimestampDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(15)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_16_TimestampDependence->insert(tuple,READ_OP_CONTEXT(rel_16_TimestampDependence_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(step2,caller,callee) :- 
   caller_check(step1),
   call(step2,_,"DELEGATECALL",caller,callee,_,_,_,_),
   step2 < step1.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [110:1-115:17])_");
if(!(rel_9_call->empty()) && !(rel_6_caller_check->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_6_caller_check_op_ctxt,rel_6_caller_check->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_17_UncheckedDelegatecall_op_ctxt,rel_17_UncheckedDelegatecall->createContext());
for(const auto& env0 : *rel_6_caller_check) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(5),0,0,0,0,0,0}};
auto range = rel_9_call->equalRange_4(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[0]) < (env0[0]))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_17_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_17_UncheckedDelegatecall_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(step2,caller,callee) :- 
   +disconnected0(),
   call(step2,_,"DELEGATECALL",caller,callee,_,_,_,_).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [110:1-115:17])_");
if(!(rel_9_call->empty()) && !(rel_7_disconnected0->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_17_UncheckedDelegatecall_op_ctxt,rel_17_UncheckedDelegatecall->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(5),0,0,0,0,0,0}};
auto range = rel_9_call->equalRange_4(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4])}};
rel_17_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_17_UncheckedDelegatecall_op_ctxt));
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_7_disconnected0->purge();
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UnhandledException(step1,caller,callee,amount) :- 
   call(step1,_,"CALL",caller,callee,_,amount,_,0),
   def(step2,"JUMPI"),
   !data_flow(step1,step2),
   "0" not_match amount,
   step1 < step2.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [50:1-55:28])_");
if(!(rel_1_def->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_18_UnhandledException_op_ctxt,rel_18_UnhandledException->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(0)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) && ((env0[0]) < (env1[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_18_UnhandledException->insert(tuple,READ_OP_CONTEXT(rel_18_UnhandledException_op_ctxt));
break;
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_19_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_20_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_21_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DoSWithBlockGasLimit(caller,callee,amount) :- 
   block(block,gasLimit,gasLimit),
   call(_,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,block),
   error(hash,"out of gas"),
   "0" not_match amount.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [183:1-189:29])_");
if(!(rel_20_error->empty()) && !(rel_21_transaction->empty()) && !(rel_9_call->empty()) && !(rel_19_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_19_block_op_ctxt,rel_19_block->createContext());
CREATE_OP_CONTEXT(rel_20_error_op_ctxt,rel_20_error->createContext());
CREATE_OP_CONTEXT(rel_21_transaction_op_ctxt,rel_21_transaction->createContext());
CREATE_OP_CONTEXT(rel_22_DoSWithBlockGasLimit_op_ctxt,rel_22_DoSWithBlockGasLimit->createContext());
for(const auto& env0 : *rel_19_block) {
if( ((env0[1]) == (env0[2]))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env1 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env1[6])) && rel_20_error->contains(Tuple<RamDomain,2>{{env1[1],RamDomain(14)}},READ_OP_CONTEXT(rel_20_error_op_ctxt)) && !rel_21_transaction->equalRange_17(Tuple<RamDomain,5>{{env1[1],0,0,0,env0[0]}},READ_OP_CONTEXT(rel_21_transaction_op_ctxt)).empty()) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[6])}};
rel_22_DoSWithBlockGasLimit->insert(tuple,READ_OP_CONTEXT(rel_22_DoSWithBlockGasLimit_op_ctxt));
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","caller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_20_error->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_19_block->purge();
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TransactionStateDependence(step1,caller,callee,amount) :- 
   def(step1,"ORIGIN"),
   def(step2,"JUMPI"),
   data_flow(step1,step2),
   call(step3,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,from,_,_,_),
   "0" not_match amount,
   step2 < step3,
   callee != from.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [205:1-213:18])_");
if(!(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty()) && !(rel_21_transaction->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_21_transaction_op_ctxt,rel_21_transaction->createContext());
CREATE_OP_CONTEXT(rel_23_TransactionStateDependence_op_ctxt,rel_23_TransactionStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(16)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,5> key{{env2[1],0,0,0,0}};
auto range = rel_21_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_21_transaction_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[4]) != (env3[1]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_23_TransactionStateDependence->insert(tuple,READ_OP_CONTEXT(rel_23_TransactionStateDependence_op_ctxt));
break;
}
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_24_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DoSWithUnexpectedThrow(step3,caller,callee,amount) :- 
   call(step1,_,"CALL",caller,callee,_,amount,depth3,0),
   throw(step2,_,_,depth2),
   throw(step3,_,_,depth3),
   "0" not_match amount,
   step1 < step2,
   depth3 < depth2,
   step1 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [170:1-178:19])_");
if(!(rel_9_call->empty()) && !(rel_24_throw->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_24_throw_op_ctxt,rel_24_throw->createContext());
CREATE_OP_CONTEXT(rel_25_DoSWithUnexpectedThrow_op_ctxt,rel_25_DoSWithUnexpectedThrow->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(0)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env0[6]))) {
for(const auto& env1 : *rel_24_throw) {
if( ((env0[7]) < (env1[3])) && ((env0[0]) < (env1[0]))) {
if( ((env0[7]) < (env1[3])) && ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,4> key{{0,0,0,env0[7]}};
auto range = rel_24_throw->equalRange_8(key,READ_OP_CONTEXT(rel_24_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env0[0]) < (env2[0]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_25_DoSWithUnexpectedThrow->insert(tuple,READ_OP_CONTEXT(rel_25_DoSWithUnexpectedThrow_op_ctxt));
}
}
}
break;
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_24_throw->purge();
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_26_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   def(step3,"SSTORE"),
   data_flow(step2,step3),
   arithmetic_result != evm_result,
   "ADD" match opcode.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [60:1-74:27])_");
if(!(rel_26_arithmetic->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_26_arithmetic_op_ctxt,rel_26_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_27_IntegerOverflow_op_ctxt,rel_27_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(7)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_26_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(8)),symTable.resolve(env1[1])) && rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(9)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env2 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5])}};
rel_27_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_27_IntegerOverflow_op_ctxt));
break;
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   def(step3,"SSTORE"),
   data_flow(step2,step3),
   arithmetic_result != evm_result,
   "MUL" match opcode.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [60:1-74:27])_");
if(!(rel_26_arithmetic->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_26_arithmetic_op_ctxt,rel_26_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_27_IntegerOverflow_op_ctxt,rel_27_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(7)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_26_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(10)),symTable.resolve(env1[1])) && rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(9)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env2 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5])}};
rel_27_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_27_IntegerOverflow_op_ctxt));
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(step2,first_operand,second_operand,arithmetic_result,evm_result) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   def(step3,"SSTORE"),
   data_flow(step2,step3),
   arithmetic_result != evm_result.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [79:1-85:27])_");
if(!(rel_26_arithmetic->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_26_arithmetic_op_ctxt,rel_26_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_28_IntegerUnderflow_op_ctxt,rel_28_IntegerUnderflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(7)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(11),0,0,0,0}};
auto range = rel_26_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_26_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_3_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(9)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env2 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5])}};
rel_28_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_28_IntegerUnderflow_op_ctxt));
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_29_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 26 */
/* BEGIN STRATUM 27 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ParityWalletHack1(step6,caller,callee,amount) :- 
   call(step1,_,"DELEGATECALL",_,_,_,_,_,_),
   storage(step2,"SSTORE",_,transaction1,from,contract,index),
   call(step3,_,"DELEGATECALL",_,_,_,_,_,_),
   storage(step4,"SLOAD",_,transaction2,from,contract,index),
   def(step5,"JUMPI"),
   data_flow(step4,step5),
   call(step6,_,"CALL",caller,callee,_,amount,_,1),
   step1 < step2,
   step3 < step4,
   step2 < step4,
   transaction1 != transaction2,
   step5 < step6,
   "0" not_match amount.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [120:1-133:23])_");
if(!(rel_29_storage->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_9_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_9_call_op_ctxt,rel_9_call->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_30_ParityWalletHack1_op_ctxt,rel_30_ParityWalletHack1->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(5),0,0,0,0,0,0}};
auto range = rel_9_call->equalRange_4(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(9),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(5),0,0,0,0,0,0}};
auto range = rel_9_call->equalRange_4(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(1),0,0,env1[4],env1[5],env1[6]}};
auto range = rel_29_storage->equalRange_114(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0])) && ((env1[0]) < (env3[0])) && ((env1[3]) != (env3[3]))) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env4 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env3[0],env4[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_9_call->equalRange_260(key,READ_OP_CONTEXT(rel_9_call_op_ctxt));
for(const auto& env5 : range) {
if( ((env4[0]) < (env5[0])) && !regex_wrapper(symTable.resolve(RamDomain(4)),symTable.resolve(env5[6]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env5[0]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env5[4]),static_cast<RamDomain>(env5[6])}};
rel_30_ParityWalletHack1->insert(tuple,READ_OP_CONTEXT(rel_30_ParityWalletHack1_op_ctxt));
}
}
}
}
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_9_call->purge();
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TransactionOrderDependency(transaction1,transaction2,block,index) :- 
   storage(step1,"SSTORE",block,transaction1,caller1,contract,index),
   storage(step2,"SLOAD",block,transaction2,caller2,contract,index),
   step1 < step2,
   transaction1 != transaction2,
   caller1 != caller2.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [90:1-95:22])_");
if(!(rel_29_storage->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_31_TransactionOrderDependency_op_ctxt,rel_31_TransactionOrderDependency->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
const Tuple<RamDomain,7> key{{0,RamDomain(9),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(1),env0[2],0,0,env0[5],env0[6]}};
auto range = rel_29_storage->equalRange_102(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[3]) != (env1[3])) && ((env0[4]) != (env1[4]))) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[6])}};
rel_31_TransactionOrderDependency->insert(tuple,READ_OP_CONTEXT(rel_31_TransactionOrderDependency_op_ctxt));
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","transaction1\ttransaction2\tblock\tstorage_index"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ParityWalletHack2(step4,caller,destination) :- 
   storage(step1,"SSTORE",_,transaction1,from,contract,index),
   storage(step2,"SLOAD",_,transaction2,from,contract,index),
   def(step3,"JUMPI"),
   data_flow(step2,step3),
   selfdestruct(step4,caller,destination),
   step1 < step2,
   transaction1 != transaction2,
   step3 < step4.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [138:1-146:17])_");
if(!(rel_29_storage->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty()) && !(rel_32_selfdestruct->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_32_selfdestruct_op_ctxt,rel_32_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_33_ParityWalletHack2_op_ctxt,rel_33_ParityWalletHack2->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
const Tuple<RamDomain,7> key{{0,RamDomain(9),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(1),0,0,env0[4],env0[5],env0[6]}};
auto range = rel_29_storage->equalRange_114(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[3]) != (env1[3]))) {
const Tuple<RamDomain,2> key{{0,RamDomain(2)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env2 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
for(const auto& env3 : *rel_32_selfdestruct) {
if( ((env2[0]) < (env3[0]))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env3[0]),static_cast<RamDomain>(env3[1]),static_cast<RamDomain>(env3[2])}};
rel_33_ParityWalletHack2->insert(tuple,READ_OP_CONTEXT(rel_33_ParityWalletHack2_op_ctxt));
}
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tdestination"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_29_storage->purge();
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(step2,caller,destination) :- 
   caller_check(step1),
   selfdestruct(step2,caller,destination),
   step2 < step1.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [100:1-105:17])_");
if(!(rel_32_selfdestruct->empty()) && !(rel_6_caller_check->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_6_caller_check_op_ctxt,rel_6_caller_check->createContext());
CREATE_OP_CONTEXT(rel_32_selfdestruct_op_ctxt,rel_32_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_34_UncheckedSuicide_op_ctxt,rel_34_UncheckedSuicide->createContext());
for(const auto& env0 : *rel_6_caller_check) {
for(const auto& env1 : *rel_32_selfdestruct) {
if( ((env1[0]) < (env0[0]))) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2])}};
rel_34_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_34_UncheckedSuicide_op_ctxt));
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(step2,caller,destination) :- 
   +disconnected1(),
   selfdestruct(step2,caller,destination).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [100:1-105:17])_");
if(!(rel_32_selfdestruct->empty()) && !(rel_8_disconnected1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_32_selfdestruct_op_ctxt,rel_32_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_34_UncheckedSuicide_op_ctxt,rel_34_UncheckedSuicide->createContext());
for(const auto& env0 : *rel_32_selfdestruct) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2])}};
rel_34_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_34_UncheckedSuicide_op_ctxt));
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tdestination"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_32_selfdestruct->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_6_caller_check->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_8_disconnected1->purge();
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./bitwise_logic.facts"},{"name","bitwise_logic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_35_bitwise_logic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,step5) :- 
   transaction(hash,_,_,input_data,_),
   def(step1,"CALLDATALOAD"),
   bitwise_logic(step2,"AND",_,second_operand),
   data_flow(step1,step2),
   def(step3,"SLOAD"),
   data_flow(step2,step3),
   arithmetic(step4,"ADD",_,_,_,_),
   data_flow(step3,step4),
   def(step5,"SSTORE"),
   data_flow(step4,step5),
   (strlen(input_data)/2) > 36,
   (strlen(input_data)/2) < 68,
   "1461501637330902918203684832716283019655932542975" match second_operand.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [151:1-165:27])_");
if(!(rel_21_transaction->empty()) && !(rel_35_bitwise_logic->empty()) && !(rel_26_arithmetic->empty()) && !(rel_1_def->empty()) && !(rel_3_data_flow->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_data_flow_op_ctxt,rel_3_data_flow->createContext());
CREATE_OP_CONTEXT(rel_1_def_op_ctxt,rel_1_def->createContext());
CREATE_OP_CONTEXT(rel_36_ShortAddress_op_ctxt,rel_36_ShortAddress->createContext());
CREATE_OP_CONTEXT(rel_35_bitwise_logic_op_ctxt,rel_35_bitwise_logic->createContext());
CREATE_OP_CONTEXT(rel_21_transaction_op_ctxt,rel_21_transaction->createContext());
CREATE_OP_CONTEXT(rel_26_arithmetic_op_ctxt,rel_26_arithmetic->createContext());
for(const auto& env0 : *rel_21_transaction) {
if( (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(68))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) > (RamDomain(36)))) {
const Tuple<RamDomain,2> key{{0,RamDomain(7)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{0,RamDomain(12),0,0}};
auto range = rel_35_bitwise_logic->equalRange_2(key,READ_OP_CONTEXT(rel_35_bitwise_logic_op_ctxt));
for(const auto& env2 : range) {
if( regex_wrapper(symTable.resolve(RamDomain(13)),symTable.resolve(env2[3])) && rel_3_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(1)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env3 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env2[0],env3[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{0,RamDomain(8),0,0,0,0}};
auto range = rel_26_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_26_arithmetic_op_ctxt));
for(const auto& env4 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env3[0],env4[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(9)}};
auto range = rel_1_def->equalRange_2(key,READ_OP_CONTEXT(rel_1_def_op_ctxt));
for(const auto& env5 : range) {
if( rel_3_data_flow->contains(Tuple<RamDomain,2>{{env4[0],env5[0]}},READ_OP_CONTEXT(rel_3_data_flow_op_ctxt))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env5[0])}};
rel_36_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_36_ShortAddress_op_ctxt));
}
}
}
}
}
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tstep"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_36_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_1_def->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_26_arithmetic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_35_bitwise_logic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_21_transaction->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_3_data_flow->purge();
}();
/* END STRATUM 33 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_def:\n";
rel_1_def->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_use:\n";
rel_2_use->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_data_flow:\n";
rel_3_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_delta_data_flow:\n";
rel_4_delta_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_new_data_flow:\n";
rel_5_new_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_caller_check:\n";
rel_6_caller_check->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_disconnected0:\n";
rel_7_disconnected0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_disconnected1:\n";
rel_8_disconnected1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_call:\n";
rel_9_call->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_BlockStateDependence:\n";
rel_10_BlockStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_CallStackDepth:\n";
rel_11_CallStackDepth->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_CreateBasedReentrancy:\n";
rel_12_CreateBasedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_CrossFunctionReentrancy:\n";
rel_13_CrossFunctionReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_DelegatedReentrancy:\n";
rel_14_DelegatedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_Reentrancy:\n";
rel_15_Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_TimestampDependence:\n";
rel_16_TimestampDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_UncheckedDelegatecall:\n";
rel_17_UncheckedDelegatecall->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_UnhandledException:\n";
rel_18_UnhandledException->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_block:\n";
rel_19_block->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_error:\n";
rel_20_error->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_transaction:\n";
rel_21_transaction->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_DoSWithBlockGasLimit:\n";
rel_22_DoSWithBlockGasLimit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_TransactionStateDependence:\n";
rel_23_TransactionStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_throw:\n";
rel_24_throw->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_DoSWithUnexpectedThrow:\n";
rel_25_DoSWithUnexpectedThrow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_arithmetic:\n";
rel_26_arithmetic->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_IntegerOverflow:\n";
rel_27_IntegerOverflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_IntegerUnderflow:\n";
rel_28_IntegerUnderflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_storage:\n";
rel_29_storage->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_30_ParityWalletHack1:\n";
rel_30_ParityWalletHack1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_31_TransactionOrderDependency:\n";
rel_31_TransactionOrderDependency->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_32_selfdestruct:\n";
rel_32_selfdestruct->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_ParityWalletHack2:\n";
rel_33_ParityWalletHack2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_UncheckedSuicide:\n";
rel_34_UncheckedSuicide->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_bitwise_logic:\n";
rel_35_bitwise_logic->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_ShortAddress:\n";
rel_36_ShortAddress->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override { runFunction(".", ".", stratumIndex, false); }
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override { runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcontract"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_12_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcontract"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_13_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcaller\tcallee"},{"filename","./DelegatedReentrancy.csv"},{"name","DelegatedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tcaller\tcallee\tamount\tdepth"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","caller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","transaction1\ttransaction2\tblock\tstorage_index"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tdestination"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","step\tcaller\tdestination"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tstep"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_36_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_1_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_9_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_19_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_20_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_21_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_24_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_26_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_29_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./bitwise_logic.facts"},{"name","bitwise_logic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_35_bitwise_logic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_def");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_1_def);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_use");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_use);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_9_call");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_9_call);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_19_block");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_block);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_20_error");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_error);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_21_transaction");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_transaction);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_24_throw");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_throw);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_26_arithmetic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_26_arithmetic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_29_storage");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_storage);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_32_selfdestruct");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_32_selfdestruct);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_35_bitwise_logic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_bitwise_logic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_BlockStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_11_CallStackDepth");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_12_CreateBasedReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_12_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_CrossFunctionReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_13_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_14_DelegatedReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_15_Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_TimestampDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_17_UncheckedDelegatecall");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_18_UnhandledException");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_22_DoSWithBlockGasLimit");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_23_TransactionStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_25_DoSWithUnexpectedThrow");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_27_IntegerOverflow");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_28_IntegerUnderflow");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_30_ParityWalletHack1");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_31_TransactionOrderDependency");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_33_ParityWalletHack2");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_34_UncheckedSuicide");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_36_ShortAddress");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_36_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
};
SouffleProgram *newInstance_analyzer(){return new Sf_analyzer;}
SymbolTable *getST_analyzer(SouffleProgram *p){return &reinterpret_cast<Sf_analyzer*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_analyzer: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_analyzer();
};
public:
factory_Sf_analyzer() : ProgramFactory("analyzer"){}
};
static factory_Sf_analyzer __factory_Sf_analyzer_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(../horus/analyzer/datalog/attacks.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_analyzer obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif

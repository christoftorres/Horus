
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_4__0_1_2_3__1__15 {
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
void insertAll(t_btree_4__0_1_2_3__1__15& other) {
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
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
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
struct t_btree_9__1_3_4_8__2_8_1_3_4__1_3_7_8_2__2_3_5_7_8__1_2_4_8_0_3_5_6_7__260__262__270__278__282__286__394__398__428__511 {
using t_tuple = Tuple<RamDomain, 9>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,3,4,8>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,8,1,3,4>>>;
t_ind_1 ind_1;
using t_ind_2 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,3,7,8,2>>>;
t_ind_2 ind_2;
using t_ind_3 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,3,5,7,8>>>;
t_ind_3 ind_3;
using t_ind_4 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,4,8,0,3,5,6,7>>>;
t_ind_4 ind_4;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator_2 = IterDerefWrapper<typename t_ind_2::iterator>;
using iterator_3 = IterDerefWrapper<typename t_ind_3::iterator>;
using iterator_4 = IterDerefWrapper<typename t_ind_4::iterator>;
using iterator = iterator_4;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
t_ind_3::operation_hints hints_3;
t_ind_4::operation_hints hints_4;
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
ind_4.insert(masterCopy, h.hints_4);
}
ind_0.insert(masterCopy, h.hints_0);
ind_1.insert(masterCopy, h.hints_1);
ind_2.insert(masterCopy, h.hints_2);
ind_3.insert(masterCopy, h.hints_3);
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
return ind_4.contains(&t, h.hints_4);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_4.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_4.find(&t, h.hints_4);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_4.begin(),ind_4.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_4.begin(),ind_4.end());
}
range<iterator_1> equalRange_260(const t_tuple& t, context& h) const {
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
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_260(const t_tuple& t) const {
context h; return equalRange_260(t, h);
}
range<iterator_1> equalRange_262(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
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
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_262(const t_tuple& t) const {
context h; return equalRange_262(t, h);
}
range<iterator_1> equalRange_270(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_270(const t_tuple& t) const {
context h; return equalRange_270(t, h);
}
range<iterator_4> equalRange_278(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_4>(ind_4.lower_bound(&low, h.hints_4), ind_4.upper_bound(&high, h.hints_4));
}
range<iterator_4> equalRange_278(const t_tuple& t) const {
context h; return equalRange_278(t, h);
}
range<iterator_0> equalRange_282(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_282(const t_tuple& t) const {
context h; return equalRange_282(t, h);
}
range<iterator_1> equalRange_286(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_286(const t_tuple& t) const {
context h; return equalRange_286(t, h);
}
range<iterator_2> equalRange_394(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_394(const t_tuple& t) const {
context h; return equalRange_394(t, h);
}
range<iterator_2> equalRange_398(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_398(const t_tuple& t) const {
context h; return equalRange_398(t, h);
}
range<iterator_3> equalRange_428(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_428(const t_tuple& t) const {
context h; return equalRange_428(t, h);
}
range<iterator_4> equalRange_511(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_4> equalRange_511(const t_tuple& t) const {
context h; return equalRange_511(t, h);
}
bool empty() const {
return ind_4.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_4.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
ind_2.clear();
ind_3.clear();
ind_4.clear();
dataTable.clear();
}
iterator begin() const {
return ind_4.begin();
}
iterator end() const {
return ind_4.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,3,4,8]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,8,1,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,3,7,8,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
const auto& stats_3 = ind_3.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,3,5,7,8]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_3.inserts.getHits() << "/" << stats_3.inserts.getMisses() << "/" << stats_3.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_3.contains.getHits() << "/" << stats_3.contains.getMisses() << "/" << stats_3.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_3.lower_bound.getHits() << "/" << stats_3.lower_bound.getMisses() << "/" << stats_3.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_3.upper_bound.getHits() << "/" << stats_3.upper_bound.getMisses() << "/" << stats_3.upper_bound.getAccesses() << "\n";
const auto& stats_4 = ind_4.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,2,4,8,0,3,5,6,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_4.inserts.getHits() << "/" << stats_4.inserts.getMisses() << "/" << stats_4.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_4.contains.getHits() << "/" << stats_4.contains.getMisses() << "/" << stats_4.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_4.lower_bound.getHits() << "/" << stats_4.lower_bound.getMisses() << "/" << stats_4.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_4.upper_bound.getHits() << "/" << stats_4.upper_bound.getMisses() << "/" << stats_4.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__1_4_0_2_3__18__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,4,0,2,3>>;
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
void insertAll(t_btree_5__1_4_0_2_3__18__31& other) {
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
range<t_ind_0::iterator> equalRange_18(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_18(const t_tuple& t) const {
context h;
return equalRange_18(t, h);
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
o << prefix << "arity 5 direct b-tree index [1,4,0,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_8__6_1_2__0_6_1_2_3_4_5_7__1__64__65__67__70__255 {
using t_tuple = Tuple<RamDomain, 8>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<6,1,2>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,6,1,2,3,4,5,7>>>;
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
RamDomain data[8];
std::copy(ramDomain, ramDomain + 8, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7) {
RamDomain data[8] = {a0,a1,a2,a3,a4,a5,a6,a7};
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
range<iterator_1> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
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
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_1(const t_tuple& t) const {
context h; return equalRange_1(t, h);
}
range<iterator_0> equalRange_64(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_64(const t_tuple& t) const {
context h; return equalRange_64(t, h);
}
range<iterator_1> equalRange_65(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_65(const t_tuple& t) const {
context h; return equalRange_65(t, h);
}
range<iterator_1> equalRange_67(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_67(const t_tuple& t) const {
context h; return equalRange_67(t, h);
}
range<iterator_0> equalRange_70(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_70(const t_tuple& t) const {
context h; return equalRange_70(t, h);
}
range<iterator_1> equalRange_255(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_1> equalRange_255(const t_tuple& t) const {
context h; return equalRange_255(t, h);
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
o << prefix << "arity 8 indirect b-tree index [6,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [0,6,1,2,3,4,5,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
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
struct t_btree_7__0_1_2_3_4_5_6__127 {
using t_tuple = Tuple<RamDomain, 7>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6>>>;
t_ind_0 ind_0;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator = iterator_0;
struct context {
t_ind_0::operation_hints hints_0;
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
ind_0.insert(masterCopy, h.hints_0);
}
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
return ind_0.contains(&t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(&t, h.hints_0);
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
range<iterator_0> equalRange_127(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_127(const t_tuple& t) const {
context h; return equalRange_127(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
dataTable.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [0,1,2,3,4,5,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_8__0_1_2_3_4_5_6_7__255 {
using t_tuple = Tuple<RamDomain, 8>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6,7>>>;
t_ind_0 ind_0;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator = iterator_0;
struct context {
t_ind_0::operation_hints hints_0;
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
ind_0.insert(masterCopy, h.hints_0);
}
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[8];
std::copy(ramDomain, ramDomain + 8, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7) {
RamDomain data[8] = {a0,a1,a2,a3,a4,a5,a6,a7};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(&t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(&t, h.hints_0);
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
range<iterator_0> equalRange_255(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_255(const t_tuple& t) const {
context h; return equalRange_255(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
dataTable.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [0,1,2,3,4,5,6,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,4,0,2,3>>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<t_tuple, index_utils::comparator<1,2,3,0,4>>;
t_ind_1 ind_1;
using iterator = t_ind_0::iterator;
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
if (ind_0.insert(t, h.hints_0)) {
ind_1.insert(t, h.hints_1);
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
void insertAll(t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31& other) {
ind_0.insertAll(other.ind_0);
ind_1.insertAll(other.ind_1);
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
range<t_ind_1::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_1::iterator> equalRange_6(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_6(const t_tuple& t) const {
context h;
return equalRange_6(t, h);
}
range<t_ind_1::iterator> equalRange_14(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_14(const t_tuple& t) const {
context h;
return equalRange_14(t, h);
}
range<t_ind_0::iterator> equalRange_18(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_18(const t_tuple& t) const {
context h;
return equalRange_18(t, h);
}
range<t_ind_1::iterator> equalRange_31(const t_tuple& t, context& h) const {
auto pos = ind_1.find(t, h.hints_1);
auto fin = ind_1.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_1::iterator> equalRange_31(const t_tuple& t) const {
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
ind_1.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 5 direct b-tree index [1,4,0,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 5 direct b-tree index [1,2,3,0,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
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
struct t_btree_8__1_3_5_6_7_0_2_4__2__234__255 {
using t_tuple = Tuple<RamDomain, 8>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,3,5,6,7,0,2,4>>>;
t_ind_0 ind_0;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator = iterator_0;
struct context {
t_ind_0::operation_hints hints_0;
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
ind_0.insert(masterCopy, h.hints_0);
}
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[8];
std::copy(ramDomain, ramDomain + 8, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7) {
RamDomain data[8] = {a0,a1,a2,a3,a4,a5,a6,a7};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(&t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(&t, h.hints_0);
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
range<iterator_0> equalRange_2(const t_tuple& t, context& h) const {
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
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_2(const t_tuple& t) const {
context h; return equalRange_2(t, h);
}
range<iterator_0> equalRange_234(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_234(const t_tuple& t) const {
context h; return equalRange_234(t, h);
}
range<iterator_0> equalRange_255(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_255(const t_tuple& t) const {
context h; return equalRange_255(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
dataTable.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [1,3,5,6,7,0,2,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095 {
using t_tuple = Tuple<RamDomain, 12>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6,7,8,9,10,11>>>;
t_ind_0 ind_0;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator = iterator_0;
struct context {
t_ind_0::operation_hints hints_0;
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
ind_0.insert(masterCopy, h.hints_0);
}
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[12];
std::copy(ramDomain, ramDomain + 12, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7,RamDomain a8,RamDomain a9,RamDomain a10,RamDomain a11) {
RamDomain data[12] = {a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(&t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(&t, h.hints_0);
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
range<iterator_0> equalRange_4095(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_4095(const t_tuple& t) const {
context h; return equalRange_4095(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
dataTable.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 12 indirect b-tree index [0,1,2,3,4,5,6,7,8,9,10,11]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047 {
using t_tuple = Tuple<RamDomain, 11>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6,7,8,9,10>>>;
t_ind_0 ind_0;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator = iterator_0;
struct context {
t_ind_0::operation_hints hints_0;
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
ind_0.insert(masterCopy, h.hints_0);
}
return true;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[11];
std::copy(ramDomain, ramDomain + 11, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7,RamDomain a8,RamDomain a9,RamDomain a10) {
RamDomain data[11] = {a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(&t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(&t, h.hints_0);
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
range<iterator_0> equalRange_2047(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_2047(const t_tuple& t) const {
context h; return equalRange_2047(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_0.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
dataTable.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 11 indirect b-tree index [0,1,2,3,4,5,6,7,8,9,10]: (hits/misses/total)\n";
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
	R"_(SSTORE)_",
	R"_(0)_",
	R"_(CALL)_",
	R"_(f39b5b9b)_",
	R"_(75ab9782)_",
	R"_(STATICCALL)_",
	R"_(0x538359785a8d5ab1a741a0ba94f26a800759d91d)_",
	R"_(70a082310000000000000000000000000eee3e3828a45f7601d5f54bf49bb01d1a9df5ea)_",
	R"_(0x0eee3e3828a45f7601d5f54bf49bb01d1a9df5ea)_",
	R"_(Ether)_",
	R"_(Token)_",
	R"_(CALLDATALOAD)_",
	R"_(ADD)_",
	R"_(MUL)_",
	R"_(SUB)_",
	R"_(DELEGATECALL)_",
	R"_(e46dcfeb)_",
	R"_(b61d27f6)_",
	R"_(cbf0b0c0)_",
	R"_(a9059cbb)_",
	R"_(23b872dd)_",
};// -- Table: block
std::unique_ptr<t_btree_4__0_1_2_3__1__15> rel_1_block = std::make_unique<t_btree_4__0_1_2_3__1__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_2_3__1__15,Tuple<RamDomain,4>,4,1> wrapper_rel_1_block;
// -- Table: call
std::unique_ptr<t_btree_9__1_3_4_8__2_8_1_3_4__1_3_7_8_2__2_3_5_7_8__1_2_4_8_0_3_5_6_7__260__262__270__278__282__286__394__398__428__511> rel_2_call = std::make_unique<t_btree_9__1_3_4_8__2_8_1_3_4__1_3_7_8_2__2_3_5_7_8__1_2_4_8_0_3_5_6_7__260__262__270__278__282__286__394__398__428__511>();
souffle::RelationWrapper<1,t_btree_9__1_3_4_8__2_8_1_3_4__1_3_7_8_2__2_3_5_7_8__1_2_4_8_0_3_5_6_7__260__262__270__278__282__286__394__398__428__511,Tuple<RamDomain,9>,9,1> wrapper_rel_2_call;
// -- Table: throw
std::unique_ptr<t_btree_5__1_4_0_2_3__18__31> rel_3_throw = std::make_unique<t_btree_5__1_4_0_2_3__18__31>();
souffle::RelationWrapper<2,t_btree_5__1_4_0_2_3__18__31,Tuple<RamDomain,5>,5,1> wrapper_rel_3_throw;
// -- Table: transaction
std::unique_ptr<t_btree_8__6_1_2__0_6_1_2_3_4_5_7__1__64__65__67__70__255> rel_4_transaction = std::make_unique<t_btree_8__6_1_2__0_6_1_2_3_4_5_7__1__64__65__67__70__255>();
souffle::RelationWrapper<3,t_btree_8__6_1_2__0_6_1_2_3_4_5_7__1__64__65__67__70__255,Tuple<RamDomain,8>,8,1> wrapper_rel_4_transaction;
// -- Table: DoSWithUnexpectedThrow
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_5_DoSWithUnexpectedThrow = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<4,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_5_DoSWithUnexpectedThrow;
// -- Table: ParityWalletHack1
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_6_ParityWalletHack1 = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<5,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_6_ParityWalletHack1;
// -- Table: UniswapHack
std::unique_ptr<t_btree_8__0_1_2_3_4_5_6_7__255> rel_7_UniswapHack = std::make_unique<t_btree_8__0_1_2_3_4_5_6_7__255>();
souffle::RelationWrapper<6,t_btree_8__0_1_2_3_4_5_6_7__255,Tuple<RamDomain,8>,8,1> wrapper_rel_7_UniswapHack;
// -- Table: transfer
std::unique_ptr<t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31> rel_8_transfer = std::make_unique<t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31>();
souffle::RelationWrapper<7,t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31,Tuple<RamDomain,5>,5,1> wrapper_rel_8_transfer;
// -- Table: ERC777Reentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_9_ERC777Reentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_9_ERC777Reentrancy;
// -- Table: LendfmeHack
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_10_LendfmeHack = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<9,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_10_LendfmeHack;
// -- Table: ShortAddress
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_ShortAddress = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<10,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_11_ShortAddress;
// -- Table: arithmetic
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_12_arithmetic = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<11,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_12_arithmetic;
// -- Table: use
std::unique_ptr<t_btree_2__0_1__3> rel_13_use = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<12,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_13_use;
// -- Table: data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_14_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<13,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_14_data_flow;
// -- Table: @delta_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_15_delta_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: @new_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_16_new_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: def
std::unique_ptr<t_btree_2__1_0__2__3> rel_17_def = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<14,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_17_def;
// -- Table: storage
std::unique_ptr<t_btree_8__1_3_5_6_7_0_2_4__2__234__255> rel_18_storage = std::make_unique<t_btree_8__1_3_5_6_7_0_2_4__2__234__255>();
souffle::RelationWrapper<15,t_btree_8__1_3_5_6_7_0_2_4__2__234__255,Tuple<RamDomain,8>,8,1> wrapper_rel_18_storage;
// -- Table: IntegerOverflow
std::unique_ptr<t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095> rel_19_IntegerOverflow = std::make_unique<t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095>();
souffle::RelationWrapper<16,t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095,Tuple<RamDomain,12>,12,1> wrapper_rel_19_IntegerOverflow;
// -- Table: IntegerUnderflow
std::unique_ptr<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047> rel_20_IntegerUnderflow = std::make_unique<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047>();
souffle::RelationWrapper<17,t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047,Tuple<RamDomain,11>,11,1> wrapper_rel_20_IntegerUnderflow;
// -- Table: Reentrancy
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_21_Reentrancy = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<18,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_21_Reentrancy;
// -- Table: selfdestruct
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_22_selfdestruct = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<19,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_22_selfdestruct;
// -- Table: ParityWalletHack2
std::unique_ptr<t_btree_8__0_1_2_3_4_5_6_7__255> rel_23_ParityWalletHack2 = std::make_unique<t_btree_8__0_1_2_3_4_5_6_7__255>();
souffle::RelationWrapper<20,t_btree_8__0_1_2_3_4_5_6_7__255,Tuple<RamDomain,8>,8,1> wrapper_rel_23_ParityWalletHack2;
// -- Table: condition
std::unique_ptr<t_btree_2__0_1__3> rel_24_condition = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<21,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_24_condition;
// -- Table: used_in_condition
std::unique_ptr<t_btree_2__0_1__1__3> rel_25_used_in_condition = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<22,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_25_used_in_condition;
// -- Table: caller_check
std::unique_ptr<t_btree_2__1_0__2__3> rel_26_caller_check = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<23,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_26_caller_check;
// -- Table: UncheckedDelegatecall
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_27_UncheckedDelegatecall = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<24,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_27_UncheckedDelegatecall;
// -- Table: UncheckedSuicide
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_28_UncheckedSuicide = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<25,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_28_UncheckedSuicide;
// -- Table: UnhandledException
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_29_UnhandledException = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<26,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_29_UnhandledException;
public:
Sf_analyzer() : 
wrapper_rel_1_block(*rel_1_block,symTable,"block",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"block","gas_used","gas_limit","timestamp"}}),

wrapper_rel_2_call(*rel_2_call,symTable,"call",std::array<const char *,9>{{"i:number","s:symbol","s:Opcode","s:Address","s:Address","s:symbol","s:Value","i:number","i:number"}},std::array<const char *,9>{{"step","transaction_hash","opcode","caller","callee","input_data","amount","depth","success"}}),

wrapper_rel_3_throw(*rel_3_throw,symTable,"throw",std::array<const char *,5>{{"i:number","s:symbol","s:Opcode","s:Address","i:number"}},std::array<const char *,5>{{"step","transaction_hash","opcode","caller","depth"}}),

wrapper_rel_4_transaction(*rel_4_transaction,symTable,"transaction",std::array<const char *,8>{{"s:symbol","s:Address","s:Address","s:symbol","i:number","i:number","i:number","i:number"}},std::array<const char *,8>{{"transaction_hash","from","to","input_data","gas_used","gas_limit","status","block"}}),

wrapper_rel_5_DoSWithUnexpectedThrow(*rel_5_DoSWithUnexpectedThrow,symTable,"DoSWithUnexpectedThrow",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_6_ParityWalletHack1(*rel_6_ParityWalletHack1,symTable,"ParityWalletHack1",std::array<const char *,7>{{"s:symbol","s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash1","hash2","timestamp1","timestamp2","caller","callee","amount"}}),

wrapper_rel_7_UniswapHack(*rel_7_UniswapHack,symTable,"UniswapHack",std::array<const char *,8>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value","s:Value"}},std::array<const char *,8>{{"hash","block","timestamp","caller","callee","attacker","amount","profit"}}),

wrapper_rel_8_transfer(*rel_8_transfer,symTable,"transfer",std::array<const char *,5>{{"i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,5>{{"step","transaction_hash","from","to","value"}}),

wrapper_rel_9_ERC777Reentrancy(*rel_9_ERC777Reentrancy,symTable,"ERC777Reentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","amount","asset"}}),

wrapper_rel_10_LendfmeHack(*rel_10_LendfmeHack,symTable,"LendfmeHack",std::array<const char *,5>{{"s:symbol","i:number","i:number","s:Address","s:Value"}},std::array<const char *,5>{{"hash","block","timestamp","token","amount"}}),

wrapper_rel_11_ShortAddress(*rel_11_ShortAddress,symTable,"ShortAddress",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","from","to","amount"}}),

wrapper_rel_12_arithmetic(*rel_12_arithmetic,symTable,"arithmetic",std::array<const char *,6>{{"i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,6>{{"step","opcode","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_13_use(*rel_13_use,symTable,"use",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"step1","step2"}}),

wrapper_rel_14_data_flow(*rel_14_data_flow,symTable,"data_flow",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"x","y"}}),

wrapper_rel_17_def(*rel_17_def,symTable,"def",std::array<const char *,2>{{"i:number","s:Opcode"}},std::array<const char *,2>{{"step","opcode"}}),

wrapper_rel_18_storage(*rel_18_storage,symTable,"storage",std::array<const char *,8>{{"i:number","s:Opcode","i:number","s:symbol","s:Address","s:Address","s:Value","i:number"}},std::array<const char *,8>{{"step","opcode","block","transaction_hash","caller","contract","storage_index","depth"}}),

wrapper_rel_19_IntegerOverflow(*rel_19_IntegerOverflow,symTable,"IntegerOverflow",std::array<const char *,12>{{"s:symbol","i:number","i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,12>{{"hash","timestamp","step","opcode","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount","asset"}}),

wrapper_rel_20_IntegerUnderflow(*rel_20_IntegerUnderflow,symTable,"IntegerUnderflow",std::array<const char *,11>{{"s:symbol","i:number","i:number","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,11>{{"hash","timestamp","step","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount","asset"}}),

wrapper_rel_21_Reentrancy(*rel_21_Reentrancy,symTable,"Reentrancy",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","caller","callee","depth","amount"}}),

wrapper_rel_22_selfdestruct(*rel_22_selfdestruct,symTable,"selfdestruct",std::array<const char *,6>{{"i:number","s:symbol","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"step","transaction_hash","caller","contract","destination","amount"}}),

wrapper_rel_23_ParityWalletHack2(*rel_23_ParityWalletHack2,symTable,"ParityWalletHack2",std::array<const char *,8>{{"s:symbol","s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,8>{{"hash1","hash2","timestamp1","timestamp2","caller","contract","destination","amount"}}),

wrapper_rel_24_condition(*rel_24_condition,symTable,"condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","transaction_hash"}}),

wrapper_rel_25_used_in_condition(*rel_25_used_in_condition,symTable,"used_in_condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_26_caller_check(*rel_26_caller_check,symTable,"caller_check",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_27_UncheckedDelegatecall(*rel_27_UncheckedDelegatecall,symTable,"UncheckedDelegatecall",std::array<const char *,5>{{"s:symbol","i:number","i:number","s:Address","s:Address"}},std::array<const char *,5>{{"hash","timestamp","step","caller","callee"}}),

wrapper_rel_28_UncheckedSuicide(*rel_28_UncheckedSuicide,symTable,"UncheckedSuicide",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","caller","contract","destination","amount"}}),

wrapper_rel_29_UnhandledException(*rel_29_UnhandledException,symTable,"UnhandledException",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}){
addRelation("block",&wrapper_rel_1_block,true,false);
addRelation("call",&wrapper_rel_2_call,true,false);
addRelation("throw",&wrapper_rel_3_throw,true,false);
addRelation("transaction",&wrapper_rel_4_transaction,true,false);
addRelation("DoSWithUnexpectedThrow",&wrapper_rel_5_DoSWithUnexpectedThrow,false,true);
addRelation("ParityWalletHack1",&wrapper_rel_6_ParityWalletHack1,false,true);
addRelation("UniswapHack",&wrapper_rel_7_UniswapHack,false,true);
addRelation("transfer",&wrapper_rel_8_transfer,true,false);
addRelation("ERC777Reentrancy",&wrapper_rel_9_ERC777Reentrancy,false,true);
addRelation("LendfmeHack",&wrapper_rel_10_LendfmeHack,false,true);
addRelation("ShortAddress",&wrapper_rel_11_ShortAddress,false,true);
addRelation("arithmetic",&wrapper_rel_12_arithmetic,true,false);
addRelation("use",&wrapper_rel_13_use,true,false);
addRelation("data_flow",&wrapper_rel_14_data_flow,false,false);
addRelation("def",&wrapper_rel_17_def,true,false);
addRelation("storage",&wrapper_rel_18_storage,true,false);
addRelation("IntegerOverflow",&wrapper_rel_19_IntegerOverflow,false,true);
addRelation("IntegerUnderflow",&wrapper_rel_20_IntegerUnderflow,false,true);
addRelation("Reentrancy",&wrapper_rel_21_Reentrancy,false,true);
addRelation("selfdestruct",&wrapper_rel_22_selfdestruct,true,false);
addRelation("ParityWalletHack2",&wrapper_rel_23_ParityWalletHack2,false,true);
addRelation("condition",&wrapper_rel_24_condition,true,false);
addRelation("used_in_condition",&wrapper_rel_25_used_in_condition,false,false);
addRelation("caller_check",&wrapper_rel_26_caller_check,false,false);
addRelation("UncheckedDelegatecall",&wrapper_rel_27_UncheckedDelegatecall,false,true);
addRelation("UncheckedSuicide",&wrapper_rel_28_UncheckedSuicide,false,true);
addRelation("UnhandledException",&wrapper_rel_29_UnhandledException,false,true);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_4_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- 
   call(step1,hash,"CALL",caller,callee,_,amount,depth3,0),
   throw(step2,hash,_,_,depth2),
   throw(step3,hash,_,_,depth3),
   transaction(hash,_,_,_,_,_,_,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2,
   (depth3+1) = depth2,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [271:1-281:33])_");
if(!(rel_2_call->empty()) && !(rel_3_throw->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_DoSWithUnexpectedThrow_op_ctxt,rel_5_DoSWithUnexpectedThrow->createContext());
CREATE_OP_CONTEXT(rel_3_throw_op_ctxt,rel_3_throw->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(0)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,(env0[7]) + (RamDomain(1))}};
auto range = rel_3_throw->equalRange_18(key,READ_OP_CONTEXT(rel_3_throw_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,env0[7]}};
auto range = rel_3_throw->equalRange_18(key,READ_OP_CONTEXT(rel_3_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,0,0}};
auto range = rel_4_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_5_DoSWithUnexpectedThrow->insert(tuple,READ_OP_CONTEXT(rel_5_DoSWithUnexpectedThrow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_3_throw->purge();
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- 
   transaction(hash1,from,to,input_data1,_,_,1,block1),
   transaction(hash2,from,to,input_data2,_,_,1,block2),
   call(step1,hash1,"DELEGATECALL",_,_,_,_,_,1),
   call(step2,hash2,"DELEGATECALL",_,_,_,_,_,1),
   call(step3,hash2,"CALL",caller,callee,_,amount,_,1),
   block(block1,_,_,timestamp1),
   block(block2,_,_,timestamp2),
   substr(input_data1,0,8) = "e46dcfeb",
   substr(input_data2,0,8) = "b61d27f6",
   step1 < step2,
   amount not_match "0",
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [224:1-236:35])_");
if(!(rel_4_transaction->empty()) && !(rel_2_call->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
CREATE_OP_CONTEXT(rel_6_ParityWalletHack1_op_ctxt,rel_6_ParityWalletHack1->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(18)))) {
const Tuple<RamDomain,8> key{{0,env0[1],env0[2],0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_70(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(19)))) {
const Tuple<RamDomain,9> key{{0,env0[0],RamDomain(17),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_262(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,9> key{{0,env1[0],RamDomain(17),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_262(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,9> key{{0,env1[0],RamDomain(4),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_262(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env4 : range) {
if( !regex_wrapper(symTable.resolve(env4[6]),symTable.resolve(RamDomain(3))) && ((env3[0]) < (env4[0]))) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
const Tuple<RamDomain,4> key{{env1[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env6 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env6[3]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env4[4]),static_cast<RamDomain>(env4[6])}};
rel_6_ParityWalletHack1->insert(tuple,READ_OP_CONTEXT(rel_6_ParityWalletHack1_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UniswapHack(hash,block,timestamp,caller,callee,attacker,amount,profit) :- 
   call(step1,hash,"CALL",callee,_,input_data1,amount,_,1),
   call(step2,hash,"CALL",caller,callee,input_data2,_,depth1,1),
   call(step3,hash,"CALL",caller,callee,input_data3,_,depth2,1),
   call(step4,hash,"CALL",callee,attacker,_,profit,_,1),
   transaction(hash,attacker,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   substr(input_data1,0,8) = "f39b5b9b",
   step1 < step2,
   substr(input_data2,0,8) = "75ab9782",
   substr(input_data3,0,8) = "75ab9782",
   depth1 < depth2,
   "0" not_match profit,
   step3 < step4.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [20:1-33:33])_");
if(!(rel_2_call->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_7_UniswapHack_op_ctxt,rel_7_UniswapHack->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(5)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),0,env0[3],0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_278(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((symTable.lookup(substr_wrapper(symTable.resolve(env1[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env1[3],env0[3],0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_286(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env2 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env2[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6))) && ((env1[7]) < (env2[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env0[3],0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_270(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env3[6])) && ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,8> key{{env0[1],env3[4],0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_67(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,8> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[7]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(env0[6]),static_cast<RamDomain>(env3[6])}};
rel_7_UniswapHack->insert(tuple,READ_OP_CONTEXT(rel_7_UniswapHack_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tblock\ttimestamp\tcaller\tcallee\tattacker\tamount\tprofit"},{"filename","./UniswapHack.csv"},{"name","UniswapHack"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_UniswapHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_8_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ERC777Reentrancy(hash,timestamp,caller,callee,amount,"Ether") :- 
   call(_,hash,"CALL",caller,callee,input_data1,_,depth1,1),
   call(step2,hash,"CALL",caller,callee,input_data2,_,depth2,1),
   call(step3,hash,"CALL",callee,from,_,amount,_,1),
   transaction(hash,from,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   substr(input_data1,0,8) = "75ab9782",
   substr(input_data2,0,8) = "75ab9782",
   depth1 < depth2,
   "0" not_match amount,
   step2 < step3.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [46:1-70:19])_");
if(!(rel_2_call->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_9_ERC777Reentrancy_op_ctxt,rel_9_ERC777Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env0[3],env0[4],0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_286(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6))) && ((env0[7]) < (env1[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env0[4],0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_270(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env0[1],env2[4],0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_67(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env2[6]),static_cast<RamDomain>(RamDomain(11))}};
rel_9_ERC777Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_9_ERC777Reentrancy_op_ctxt));
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
SignalHandler::instance()->setMsg(R"_(ERC777Reentrancy(hash,timestamp,caller,callee,amount,"Token") :- 
   call(step1,hash,"CALL",caller,callee,input_data1,_,_,1),
   call(step2,hash,"CALL",caller,callee,input_data2,_,_,1),
   transfer(step3,hash,callee,to,_),
   transfer(step4,hash,to,callee,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   substr(input_data1,0,8) = "75ab9782",
   substr(input_data2,0,8) = "75ab9782",
   step1 < step2,
   "0" not_match amount,
   step3 < step4.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [46:1-70:19])_");
if(!(rel_2_call->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_9_ERC777Reentrancy_op_ctxt,rel_9_ERC777Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env0[3],env0[4],0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_286(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(6))) && ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,5> key{{0,env0[1],env0[4],0,0}};
auto range = rel_8_transfer->equalRange_6(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,5> key{{0,env0[1],env2[3],env0[4],0}};
auto range = rel_8_transfer->equalRange_14(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env3[4])) && ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(RamDomain(12))}};
rel_9_ERC777Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_9_ERC777Reentrancy_op_ctxt));
}
}
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tamount\tasset"},{"filename","./ERC777Reentrancy.csv"},{"name","ERC777Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_9_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(LendfmeHack(hash,block,timestamp,token,amount) :- 
   call(_,hash,"STATICCALL","0x538359785a8d5ab1a741a0ba94f26a800759d91d",token,"70a082310000000000000000000000000eee3e3828a45f7601d5f54bf49bb01d1a9df5ea",_,1,1),
   call(_,hash,"CALL","0x0eee3e3828a45f7601d5f54bf49bb01d1a9df5ea",_,_,_,2,1),
   transfer(_,hash,"0x0eee3e3828a45f7601d5f54bf49bb01d1a9df5ea","0x538359785a8d5ab1a741a0ba94f26a800759d91d",amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [37:1-42:33])_");
if(!(rel_2_call->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_10_LendfmeHack_op_ctxt,rel_10_LendfmeHack->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(7),RamDomain(8),0,RamDomain(9),0,RamDomain(1),RamDomain(1)}};
auto range = rel_2_call->equalRange_428(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( !rel_2_call->equalRange_398(Tuple<RamDomain,9>{{0,env0[1],RamDomain(4),RamDomain(10),0,0,0,RamDomain(2),RamDomain(1)}},READ_OP_CONTEXT(rel_2_call_op_ctxt)).empty()) {
const Tuple<RamDomain,5> key{{0,env0[1],RamDomain(10),RamDomain(8),0}};
auto range = rel_8_transfer->equalRange_14(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[7]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env1[4])}};
rel_10_LendfmeHack->insert(tuple,READ_OP_CONTEXT(rel_10_LendfmeHack_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tblock\ttimestamp\ttoken\tamount"},{"filename","./LendfmeHack.csv"},{"name","LendfmeHack"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_LendfmeHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,timestamp,step6,from,to,amount) :- 
   transaction(hash,_,_,input_data,_,_,1,block),
   transfer(step6,hash,from,to,amount),
   block(block,_,_,timestamp),
   substr(input_data,0,8) = "a9059cbb",
   (strlen(input_data)/2) < 68.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [256:1-266:33])_");
if(!(rel_1_block->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_11_ShortAddress_op_ctxt,rel_11_ShortAddress->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(21))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(68)))) {
const Tuple<RamDomain,5> key{{0,env0[0],0,0,0}};
auto range = rel_8_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_11_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_11_ShortAddress_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,timestamp,step6,from,to,amount) :- 
   transaction(hash,_,_,input_data,_,_,1,block),
   transfer(step6,hash,from,to,amount),
   block(block,_,_,timestamp),
   substr(input_data,0,8) = "23b872dd",
   (strlen(input_data)/2) < 100.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [256:1-266:33])_");
if(!(rel_1_block->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_11_ShortAddress_op_ctxt,rel_11_ShortAddress->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(22))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(100)))) {
const Tuple<RamDomain,5> key{{0,env0[0],0,0,0}};
auto range = rel_8_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_11_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_11_ShortAddress_op_ctxt));
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfrom\tto\tamount"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_12_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_13_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,x).
in file lib/horus.dl [5:1-6:13])_");
if(!(rel_13_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_13_use_op_ctxt,rel_13_use->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
for(const auto& env0 : *rel_13_use) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[0])}};
rel_14_data_flow->insert(tuple,READ_OP_CONTEXT(rel_14_data_flow_op_ctxt));
}
}
();}
rel_15_delta_data_flow->insertAll(*rel_14_data_flow);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,z),
   data_flow(x,z).
in file lib/horus.dl [8:1-10:19])_");
if(!(rel_15_delta_data_flow->empty()) && !(rel_13_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_13_use_op_ctxt,rel_13_use->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_15_delta_data_flow_op_ctxt,rel_15_delta_data_flow->createContext());
CREATE_OP_CONTEXT(rel_16_new_data_flow_op_ctxt,rel_16_new_data_flow->createContext());
for(const auto& env0 : *rel_13_use) {
const Tuple<RamDomain,2> key{{0,env0[1]}};
auto range = rel_15_delta_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_15_delta_data_flow_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_14_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env0[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[0])}};
rel_16_new_data_flow->insert(tuple,READ_OP_CONTEXT(rel_16_new_data_flow_op_ctxt));
}
}
}
}
();}
if(rel_16_new_data_flow->empty()) break;
rel_14_data_flow->insertAll(*rel_16_new_data_flow);
std::swap(rel_15_delta_data_flow, rel_16_new_data_flow);
rel_16_new_data_flow->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_15_delta_data_flow->purge();
if (!isHintsProfilingEnabled()) rel_16_new_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_13_use->purge();
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_17_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_18_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"ADD",first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"ADD",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [155:1-180:19])_");
if(!(rel_17_def->empty()) && !(rel_12_arithmetic->empty()) && !(rel_18_storage->empty()) && !(rel_14_data_flow->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_18_storage_op_ctxt,rel_18_storage->createContext());
CREATE_OP_CONTEXT(rel_19_IntegerOverflow_op_ctxt,rel_19_IntegerOverflow->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_12_arithmetic_op_ctxt,rel_12_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(13)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(14),0,0,0,0}};
auto range = rel_12_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_12_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_14_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,8> key{{0,RamDomain(2),0,0,0,0,0,0}};
auto range = rel_18_storage->equalRange_2(key,READ_OP_CONTEXT(rel_18_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_14_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_8_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(12))}};
rel_19_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_19_IntegerOverflow_op_ctxt));
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
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"MUL",first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"MUL",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [155:1-180:19])_");
if(!(rel_17_def->empty()) && !(rel_12_arithmetic->empty()) && !(rel_18_storage->empty()) && !(rel_14_data_flow->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_18_storage_op_ctxt,rel_18_storage->createContext());
CREATE_OP_CONTEXT(rel_19_IntegerOverflow_op_ctxt,rel_19_IntegerOverflow->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_12_arithmetic_op_ctxt,rel_12_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(13)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(15),0,0,0,0}};
auto range = rel_12_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_12_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_14_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,8> key{{0,RamDomain(2),0,0,0,0,0,0}};
auto range = rel_18_storage->equalRange_2(key,READ_OP_CONTEXT(rel_18_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_14_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_8_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(12))}};
rel_19_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_19_IntegerOverflow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [185:1-196:19])_");
if(!(rel_17_def->empty()) && !(rel_12_arithmetic->empty()) && !(rel_18_storage->empty()) && !(rel_14_data_flow->empty()) && !(rel_8_transfer->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_18_storage_op_ctxt,rel_18_storage->createContext());
CREATE_OP_CONTEXT(rel_20_IntegerUnderflow_op_ctxt,rel_20_IntegerUnderflow->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_8_transfer_op_ctxt,rel_8_transfer->createContext());
CREATE_OP_CONTEXT(rel_12_arithmetic_op_ctxt,rel_12_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(13)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(16),0,0,0,0}};
auto range = rel_12_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_12_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_14_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,8> key{{0,RamDomain(2),0,0,0,0,0,0}};
auto range = rel_18_storage->equalRange_2(key,READ_OP_CONTEXT(rel_18_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_14_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_8_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_8_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(12))}};
rel_20_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_20_IntegerUnderflow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_12_arithmetic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_8_transfer->purge();
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(Reentrancy(hash,timestamp,step3,caller,callee,depth2,amount) :- 
   storage(step1,"SLOAD",_,hash,_,caller,index,depth1),
   call(step2,hash,_,caller,callee,_,_,depth1,1),
   call(step3,hash,_,caller,callee,_,amount,depth2,1),
   storage(step4,"SSTORE",_,hash,_,caller,index,depth1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   depth1 < depth2,
   step1 < step2,
   step3 < step4.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [5:1-15:33])_");
if(!(rel_2_call->empty()) && !(rel_18_storage->empty()) && !(rel_4_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_18_storage_op_ctxt,rel_18_storage->createContext());
CREATE_OP_CONTEXT(rel_21_Reentrancy_op_ctxt,rel_21_Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,8> key{{0,RamDomain(1),0,0,0,0,0,0}};
auto range = rel_18_storage->equalRange_2(key,READ_OP_CONTEXT(rel_18_storage_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[3],0,env0[5],0,0,0,env0[7],RamDomain(1)}};
auto range = rel_2_call->equalRange_394(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,9> key{{0,env0[3],0,env0[5],env1[4],0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_282(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env2[6])) && ((env0[7]) < (env2[7]))) {
const Tuple<RamDomain,8> key{{0,RamDomain(2),0,env0[3],0,env0[5],env0[6],env0[7]}};
auto range = rel_18_storage->equalRange_234(key,READ_OP_CONTEXT(rel_18_storage_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,8> key{{env0[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[5]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env2[7]),static_cast<RamDomain>(env2[6])}};
rel_21_Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_21_Reentrancy_op_ctxt));
}
}
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_18_storage->purge();
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_22_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- 
   transaction(hash1,from,to,input_data1,_,_,1,block1),
   block(block1,_,_,timestamp1),
   transaction(hash2,from,to,input_data2,_,_,1,block2),
   block(block2,_,_,timestamp2),
   selfdestruct(_,hash2,caller,contract,destination,amount),
   !call(_,hash1,"DELEGATECALL",_,_,_,_,_,1),
   !call(_,hash2,"DELEGATECALL",_,_,_,_,_,1),
   substr(input_data1,0,8) = "e46dcfeb",
   substr(input_data2,0,8) = "cbf0b0c0",
   block1 <= block2.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [241:1-251:65])_");
if(!(rel_4_transaction->empty()) && !(rel_1_block->empty()) && !(rel_22_selfdestruct->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_22_selfdestruct_op_ctxt,rel_22_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_23_ParityWalletHack2_op_ctxt,rel_23_ParityWalletHack2->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env0 : range) {
if( !(!rel_2_call->equalRange_262(Tuple<RamDomain,9>{{0,env0[0],RamDomain(17),0,0,0,0,0,RamDomain(1)}},READ_OP_CONTEXT(rel_2_call_op_ctxt)).empty()) && ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(18)))) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,8> key{{0,env0[1],env0[2],0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_70(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_2_call->equalRange_262(Tuple<RamDomain,9>{{0,env2[0],RamDomain(17),0,0,0,0,0,RamDomain(1)}},READ_OP_CONTEXT(rel_2_call_op_ctxt)).empty()) && ((symTable.lookup(substr_wrapper(symTable.resolve(env2[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(20))) && ((env0[7]) <= (env2[7]))) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,6> key{{0,env2[0],0,0,0,0}};
auto range = rel_22_selfdestruct->equalRange_2(key,READ_OP_CONTEXT(rel_22_selfdestruct_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,8> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env4[2]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env4[4]),static_cast<RamDomain>(env4[5])}};
rel_23_ParityWalletHack2->insert(tuple,READ_OP_CONTEXT(rel_23_ParityWalletHack2_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./condition.facts"},{"name","condition"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_24_condition);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(used_in_condition(step1,hash) :- 
   condition(step2,hash),
   data_flow(step1,step2).
in file lib/horus.dl [13:1-15:27])_");
if(!(rel_14_data_flow->empty()) && !(rel_24_condition->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_24_condition_op_ctxt,rel_24_condition->createContext());
CREATE_OP_CONTEXT(rel_25_used_in_condition_op_ctxt,rel_25_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
for(const auto& env0 : *rel_24_condition) {
const Tuple<RamDomain,2> key{{0,env0[0]}};
auto range = rel_14_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_14_data_flow_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[1])}};
rel_25_used_in_condition->insert(tuple,READ_OP_CONTEXT(rel_25_used_in_condition_op_ctxt));
}
}
}
();}
if (!isHintsProfilingEnabled()&& performIO) rel_24_condition->purge();
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(caller_check(step1,hash) :- 
   def(step1,"CALLER"),
   used_in_condition(step1,hash).
in file lib/horus.dl [18:1-20:34])_");
if(!(rel_25_used_in_condition->empty()) && !(rel_17_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_25_used_in_condition_op_ctxt,rel_25_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_26_caller_check_op_ctxt,rel_26_caller_check->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(0)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_25_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_25_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_26_caller_check->insert(tuple,READ_OP_CONTEXT(rel_26_caller_check_op_ctxt));
}
}
}
();}
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"DELEGATECALL",caller,callee,_,_,_,1),
   data_flow(step1,step2),
   transaction(hash,_,_,input_data,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash),
   substr(callee,2,strlen(callee)) contains input_data.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [212:1-219:33])_");
if(!(rel_1_block->empty()) && !(rel_4_transaction->empty()) && !(rel_14_data_flow->empty()) && !(rel_2_call->empty()) && !(rel_17_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_26_caller_check_op_ctxt,rel_26_caller_check->createContext());
CREATE_OP_CONTEXT(rel_27_UncheckedDelegatecall_op_ctxt,rel_27_UncheckedDelegatecall->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(13)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(17),0,0,0,0,0,RamDomain(1)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env1 : range) {
if( !(!rel_26_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env1[1]}},READ_OP_CONTEXT(rel_26_caller_check_op_ctxt)).empty()) && rel_14_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env2 : range) {
if( (symTable.resolve(env2[3]).find(symTable.resolve(symTable.lookup(substr_wrapper(symTable.resolve(env1[4]),(RamDomain(2)),(static_cast<RamDomain>(symTable.resolve(env1[4]).size())))))) != std::string::npos)) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_27_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_27_UncheckedDelegatecall_op_ctxt));
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- 
   def(step1,"CALLDATALOAD"),
   selfdestruct(step2,hash,caller,contract,destination,amount),
   data_flow(step1,step2),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash).
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [201:1-207:33])_");
if(!(rel_1_block->empty()) && !(rel_4_transaction->empty()) && !(rel_14_data_flow->empty()) && !(rel_22_selfdestruct->empty()) && !(rel_17_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_22_selfdestruct_op_ctxt,rel_22_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_17_def_op_ctxt,rel_17_def->createContext());
CREATE_OP_CONTEXT(rel_26_caller_check_op_ctxt,rel_26_caller_check->createContext());
CREATE_OP_CONTEXT(rel_28_UncheckedSuicide_op_ctxt,rel_28_UncheckedSuicide->createContext());
CREATE_OP_CONTEXT(rel_14_data_flow_op_ctxt,rel_14_data_flow->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(13)}};
auto range = rel_17_def->equalRange_2(key,READ_OP_CONTEXT(rel_17_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_22_selfdestruct) {
if( !(!rel_26_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env1[1]}},READ_OP_CONTEXT(rel_26_caller_check_op_ctxt)).empty()) && rel_14_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_14_data_flow_op_ctxt))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5])}};
rel_28_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_28_UncheckedSuicide_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_14_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_26_caller_check->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_17_def->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_22_selfdestruct->purge();
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UnhandledException(hash,timestamp,step1,caller,callee,amount) :- 
   call(step1,hash,"CALL",caller,callee,_,amount,_,0),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   !used_in_condition(step1,hash),
   "0" not_match amount.
in file /Users/christof.torres/Git/Horus/horus/analyzer/datalog/attacks.dl [145:1-150:33])_");
if(!(rel_1_block->empty()) && !(rel_4_transaction->empty()) && !(rel_2_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_25_used_in_condition_op_ctxt,rel_25_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_29_UnhandledException_op_ctxt,rel_29_UnhandledException->createContext());
CREATE_OP_CONTEXT(rel_2_call_op_ctxt,rel_2_call->createContext());
CREATE_OP_CONTEXT(rel_4_transaction_op_ctxt,rel_4_transaction->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(0)}};
auto range = rel_2_call->equalRange_260(key,READ_OP_CONTEXT(rel_2_call_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_25_used_in_condition->contains(Tuple<RamDomain,2>{{env0[0],env0[1]}},READ_OP_CONTEXT(rel_25_used_in_condition_op_ctxt))) && !regex_wrapper(symTable.resolve(RamDomain(3)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_4_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_4_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_29_UnhandledException->insert(tuple,READ_OP_CONTEXT(rel_29_UnhandledException_op_ctxt));
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_25_used_in_condition->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_2_call->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_block->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_4_transaction->purge();
}();
/* END STRATUM 26 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_block:\n";
rel_1_block->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_call:\n";
rel_2_call->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_throw:\n";
rel_3_throw->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_transaction:\n";
rel_4_transaction->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_DoSWithUnexpectedThrow:\n";
rel_5_DoSWithUnexpectedThrow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_ParityWalletHack1:\n";
rel_6_ParityWalletHack1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_UniswapHack:\n";
rel_7_UniswapHack->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_transfer:\n";
rel_8_transfer->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_ERC777Reentrancy:\n";
rel_9_ERC777Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_LendfmeHack:\n";
rel_10_LendfmeHack->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_ShortAddress:\n";
rel_11_ShortAddress->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_arithmetic:\n";
rel_12_arithmetic->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_use:\n";
rel_13_use->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_data_flow:\n";
rel_14_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_delta_data_flow:\n";
rel_15_delta_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_new_data_flow:\n";
rel_16_new_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_def:\n";
rel_17_def->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_storage:\n";
rel_18_storage->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_IntegerOverflow:\n";
rel_19_IntegerOverflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_IntegerUnderflow:\n";
rel_20_IntegerUnderflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_Reentrancy:\n";
rel_21_Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_selfdestruct:\n";
rel_22_selfdestruct->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_ParityWalletHack2:\n";
rel_23_ParityWalletHack2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_condition:\n";
rel_24_condition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_used_in_condition:\n";
rel_25_used_in_condition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_caller_check:\n";
rel_26_caller_check->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_UncheckedDelegatecall:\n";
rel_27_UncheckedDelegatecall->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_UncheckedSuicide:\n";
rel_28_UncheckedSuicide->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_UnhandledException:\n";
rel_29_UnhandledException->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tblock\ttimestamp\tcaller\tcallee\tattacker\tamount\tprofit"},{"filename","./UniswapHack.csv"},{"name","UniswapHack"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_UniswapHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tamount\tasset"},{"filename","./ERC777Reentrancy.csv"},{"name","ERC777Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_9_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\tblock\ttimestamp\ttoken\tamount"},{"filename","./LendfmeHack.csv"},{"name","LendfmeHack"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_LendfmeHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfrom\tto\tamount"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_2_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_3_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_4_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_8_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_12_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_13_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_17_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_18_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_22_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./condition.facts"},{"name","condition"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_24_condition);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_block");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_1_block);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_call");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_call);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_throw");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_throw);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_transaction");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_4_transaction);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_transfer");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_transfer);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_12_arithmetic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_12_arithmetic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_use");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_13_use);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_17_def");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_def);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_18_storage");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,0,1,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_storage);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_22_selfdestruct");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_selfdestruct);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_24_condition");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_condition);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_DoSWithUnexpectedThrow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_ParityWalletHack1");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_UniswapHack");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_UniswapHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_9_ERC777Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_9_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_LendfmeHack");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_10_LendfmeHack);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_11_ShortAddress");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_11_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_19_IntegerOverflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_20_IntegerUnderflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_21_Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_23_ParityWalletHack2");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_27_UncheckedDelegatecall");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_28_UncheckedSuicide");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_29_UnhandledException");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_UnhandledException);
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
souffle::CmdOptions opt(R"(./analyzer/datalog/attacks.dl)",
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

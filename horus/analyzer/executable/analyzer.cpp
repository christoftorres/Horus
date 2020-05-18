
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
struct t_btree_5__1_4_0_2_3__2__18__31 {
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
void insertAll(t_btree_5__1_4_0_2_3__2__18__31& other) {
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
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
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
struct t_btree_8__6_1_2_0__7_0_6__2_3_4_5_6_7__0_6_1_2_3_4_5_7__1__64__65__67__70__71__128__193__252__255 {
using t_tuple = Tuple<RamDomain, 8>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<6,1,2,0>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<7,0,6>>>;
t_ind_1 ind_1;
using t_ind_2 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,3,4,5,6,7>>>;
t_ind_2 ind_2;
using t_ind_3 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,6,1,2,3,4,5,7>>>;
t_ind_3 ind_3;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator_2 = IterDerefWrapper<typename t_ind_2::iterator>;
using iterator_3 = IterDerefWrapper<typename t_ind_3::iterator>;
using iterator = iterator_3;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
t_ind_3::operation_hints hints_3;
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
ind_3.insert(masterCopy, h.hints_3);
}
ind_0.insert(masterCopy, h.hints_0);
ind_1.insert(masterCopy, h.hints_1);
ind_2.insert(masterCopy, h.hints_2);
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
return ind_3.contains(&t, h.hints_3);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_3.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_3.find(&t, h.hints_3);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_3.begin(),ind_3.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_3.begin(),ind_3.end());
}
range<iterator_3> equalRange_1(const t_tuple& t, context& h) const {
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
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_1(const t_tuple& t) const {
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
range<iterator_3> equalRange_65(const t_tuple& t, context& h) const {
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
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_65(const t_tuple& t) const {
context h; return equalRange_65(t, h);
}
range<iterator_3> equalRange_67(const t_tuple& t, context& h) const {
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
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_67(const t_tuple& t) const {
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
range<iterator_0> equalRange_71(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
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
range<iterator_0> equalRange_71(const t_tuple& t) const {
context h; return equalRange_71(t, h);
}
range<iterator_1> equalRange_128(const t_tuple& t, context& h) const {
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
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_128(const t_tuple& t) const {
context h; return equalRange_128(t, h);
}
range<iterator_1> equalRange_193(const t_tuple& t, context& h) const {
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
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_193(const t_tuple& t) const {
context h; return equalRange_193(t, h);
}
range<iterator_2> equalRange_252(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_252(const t_tuple& t) const {
context h; return equalRange_252(t, h);
}
range<iterator_3> equalRange_255(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_3> equalRange_255(const t_tuple& t) const {
context h; return equalRange_255(t, h);
}
bool empty() const {
return ind_3.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_3.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
ind_2.clear();
ind_3.clear();
dataTable.clear();
}
iterator begin() const {
return ind_3.begin();
}
iterator end() const {
return ind_3.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [6,1,2,0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [7,0,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [2,3,4,5,6,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
const auto& stats_3 = ind_3.getHintStatistics();
o << prefix << "arity 8 indirect b-tree index [0,6,1,2,3,4,5,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_3.inserts.getHits() << "/" << stats_3.inserts.getMisses() << "/" << stats_3.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_3.contains.getHits() << "/" << stats_3.contains.getMisses() << "/" << stats_3.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_3.lower_bound.getHits() << "/" << stats_3.lower_bound.getMisses() << "/" << stats_3.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_3.upper_bound.getHits() << "/" << stats_3.upper_bound.getMisses() << "/" << stats_3.upper_bound.getAccesses() << "\n";
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
struct t_btree_9__2_6_8__2_8_1_3_4_6__1_2_5_8_3_4_6__2_4_8_1_3_5_0_6_7__4__260__262__270__276__286__294__302__318__324__350__382__511 {
using t_tuple = Tuple<RamDomain, 9>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,6,8>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,8,1,3,4,6>>>;
t_ind_1 ind_1;
using t_ind_2 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,5,8,3,4,6>>>;
t_ind_2 ind_2;
using t_ind_3 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,4,8,1,3,5,0,6,7>>>;
t_ind_3 ind_3;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator_2 = IterDerefWrapper<typename t_ind_2::iterator>;
using iterator_3 = IterDerefWrapper<typename t_ind_3::iterator>;
using iterator = iterator_3;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
t_ind_3::operation_hints hints_3;
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
ind_3.insert(masterCopy, h.hints_3);
}
ind_0.insert(masterCopy, h.hints_0);
ind_1.insert(masterCopy, h.hints_1);
ind_2.insert(masterCopy, h.hints_2);
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
return ind_3.contains(&t, h.hints_3);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_3.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_3.find(&t, h.hints_3);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_3.begin(),ind_3.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_3.begin(),ind_3.end());
}
range<iterator_1> equalRange_4(const t_tuple& t, context& h) const {
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
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_4(const t_tuple& t) const {
context h; return equalRange_4(t, h);
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
range<iterator_3> equalRange_276(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_276(const t_tuple& t) const {
context h; return equalRange_276(t, h);
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
range<iterator_2> equalRange_294(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_294(const t_tuple& t) const {
context h; return equalRange_294(t, h);
}
range<iterator_2> equalRange_302(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_302(const t_tuple& t) const {
context h; return equalRange_302(t, h);
}
range<iterator_3> equalRange_318(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_3>(ind_3.lower_bound(&low, h.hints_3), ind_3.upper_bound(&high, h.hints_3));
}
range<iterator_3> equalRange_318(const t_tuple& t) const {
context h; return equalRange_318(t, h);
}
range<iterator_0> equalRange_324(const t_tuple& t, context& h) const {
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
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_324(const t_tuple& t) const {
context h; return equalRange_324(t, h);
}
range<iterator_1> equalRange_350(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_350(const t_tuple& t) const {
context h; return equalRange_350(t, h);
}
range<iterator_2> equalRange_382(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_382(const t_tuple& t) const {
context h; return equalRange_382(t, h);
}
range<iterator_3> equalRange_511(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_3> equalRange_511(const t_tuple& t) const {
context h; return equalRange_511(t, h);
}
bool empty() const {
return ind_3.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_3.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
ind_2.clear();
ind_3.clear();
dataTable.clear();
}
iterator begin() const {
return ind_3.begin();
}
iterator end() const {
return ind_3.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,6,8]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,8,1,3,4,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,2,5,8,3,4,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
const auto& stats_3 = ind_3.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,4,8,1,3,5,0,6,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_3.inserts.getHits() << "/" << stats_3.inserts.getMisses() << "/" << stats_3.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_3.contains.getHits() << "/" << stats_3.contains.getMisses() << "/" << stats_3.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_3.lower_bound.getHits() << "/" << stats_3.lower_bound.getMisses() << "/" << stats_3.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_3.upper_bound.getHits() << "/" << stats_3.upper_bound.getMisses() << "/" << stats_3.upper_bound.getAccesses() << "\n";
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
struct t_btree_7__1_3_2_5_6__1_2_5_6_0_3_4__2__10__102__110__127 {
using t_tuple = Tuple<RamDomain, 7>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,3,2,5,6>>>;
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
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_2(const t_tuple& t) const {
context h; return equalRange_2(t, h);
}
range<iterator_0> equalRange_10(const t_tuple& t, context& h) const {
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
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_10(const t_tuple& t) const {
context h; return equalRange_10(t, h);
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
range<iterator_0> equalRange_110(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_110(const t_tuple& t) const {
context h; return equalRange_110(t, h);
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
o << prefix << "arity 7 indirect b-tree index [1,3,2,5,6]: (hits/misses/total)\n";
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
std::string profiling_fname;
public:
// -- initialize symbol table --
SymbolTable symTable
{
	R"_(CALLER)_",
	R"_(CALL)_",
	R"_(0)_",
	R"_(75ab9782)_",
	R"_(Ether)_",
	R"_(Token)_",
	R"_()_",
	R"_(SSTORE)_",
	R"_(DELEGATECALL)_",
	R"_(CALLCODE)_",
	R"_(CREATE)_",
	R"_(CALLDATALOAD)_",
	R"_(ADD)_",
	R"_(MUL)_",
	R"_(SUB)_",
	R"_(SLOAD)_",
	R"_(e46dcfeb)_",
	R"_(b61d27f6)_",
	R"_(cbf0b0c0)_",
	R"_(a9059cbb)_",
	R"_(23b872dd)_",
	R"_(out of gas)_",
	R"_(TIMESTAMP)_",
	R"_(ORIGIN)_",
	R"_(BLOCKHASH)_",
	R"_(COINBASE)_",
	R"_(NUMBER)_",
	R"_(DIFFICULTY)_",
	R"_(GASLIMIT)_",
	R"_(SHA3)_",
	R"_(0x0000000000000000000000000000000000000001)_",
	R"_(BALANCE)_",
};private:
  size_t freqs[425]{};
  size_t reads[39]{};
// -- Table: block
std::unique_ptr<t_btree_4__0_1_2_3__1__15> rel_1_block = std::make_unique<t_btree_4__0_1_2_3__1__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_2_3__1__15,Tuple<RamDomain,4>,4,1> wrapper_rel_1_block;
// -- Table: condition
std::unique_ptr<t_btree_2__0_1__3> rel_2_condition = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<1,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_2_condition;
// -- Table: def
std::unique_ptr<t_btree_2__1_0__2__3> rel_3_def = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<2,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_3_def;
// -- Table: throw
std::unique_ptr<t_btree_5__1_4_0_2_3__2__18__31> rel_4_throw = std::make_unique<t_btree_5__1_4_0_2_3__2__18__31>();
souffle::RelationWrapper<3,t_btree_5__1_4_0_2_3__2__18__31,Tuple<RamDomain,5>,5,1> wrapper_rel_4_throw;
// -- Table: transaction
std::unique_ptr<t_btree_8__6_1_2_0__7_0_6__2_3_4_5_6_7__0_6_1_2_3_4_5_7__1__64__65__67__70__71__128__193__252__255> rel_5_transaction = std::make_unique<t_btree_8__6_1_2_0__7_0_6__2_3_4_5_6_7__0_6_1_2_3_4_5_7__1__64__65__67__70__71__128__193__252__255>();
souffle::RelationWrapper<4,t_btree_8__6_1_2_0__7_0_6__2_3_4_5_6_7__0_6_1_2_3_4_5_7__1__64__65__67__70__71__128__193__252__255,Tuple<RamDomain,8>,8,1> wrapper_rel_5_transaction;
// -- Table: BlockStuffing
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_6_BlockStuffing = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<5,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_6_BlockStuffing;
// -- Table: use
std::unique_ptr<t_btree_2__0_1__3> rel_7_use = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<6,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_7_use;
// -- Table: BalanceInvariant
std::unique_ptr<t_btree_3__0_1_2__7> rel_8_BalanceInvariant = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<7,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_8_BalanceInvariant;
// -- Table: data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_9_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<8,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_9_data_flow;
// -- Table: @delta_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_10_delta_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: @new_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_11_new_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: used_in_condition
std::unique_ptr<t_btree_2__0_1__1__3> rel_12_used_in_condition = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<9,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_12_used_in_condition;
// -- Table: caller_check
std::unique_ptr<t_btree_2__1_0__2__3> rel_13_caller_check = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<10,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_13_caller_check;
// -- Table: call
std::unique_ptr<t_btree_9__2_6_8__2_8_1_3_4_6__1_2_5_8_3_4_6__2_4_8_1_3_5_0_6_7__4__260__262__270__276__286__294__302__318__324__350__382__511> rel_14_call = std::make_unique<t_btree_9__2_6_8__2_8_1_3_4_6__1_2_5_8_3_4_6__2_4_8_1_3_5_0_6_7__4__260__262__270__276__286__294__302__318__324__350__382__511>();
souffle::RelationWrapper<11,t_btree_9__2_6_8__2_8_1_3_4_6__1_2_5_8_3_4_6__2_4_8_1_3_5_0_6_7__4__260__262__270__276__286__294__302__318__324__350__382__511,Tuple<RamDomain,9>,9,1> wrapper_rel_14_call;
// -- Table: BlockStateDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_BlockStateDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_15_BlockStateDependence;
// -- Table: CallStackDepth
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_CallStackDepth = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_16_CallStackDepth;
// -- Table: CreateBasedReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_17_CreateBasedReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<14,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_17_CreateBasedReentrancy;
// -- Table: DelegatedReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_18_DelegatedReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<15,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_18_DelegatedReentrancy;
// -- Table: DoSWithUnexpectedThrow
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_19_DoSWithUnexpectedThrow = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<16,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_19_DoSWithUnexpectedThrow;
// -- Table: ParityWalletHack1
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_20_ParityWalletHack1 = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<17,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_20_ParityWalletHack1;
// -- Table: Reentrancy
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_21_Reentrancy = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<18,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_21_Reentrancy;
// -- Table: TimestampDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_22_TimestampDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<19,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_22_TimestampDependence;
// -- Table: TransactionStateDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_23_TransactionStateDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<20,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_23_TransactionStateDependence;
// -- Table: UncheckedDelegatecall
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_24_UncheckedDelegatecall = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<21,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_24_UncheckedDelegatecall;
// -- Table: UnhandledException
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_25_UnhandledException = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<22,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_25_UnhandledException;
// -- Table: storage
std::unique_ptr<t_btree_7__1_3_2_5_6__1_2_5_6_0_3_4__2__10__102__110__127> rel_26_storage = std::make_unique<t_btree_7__1_3_2_5_6__1_2_5_6_0_3_4__2__10__102__110__127>();
souffle::RelationWrapper<23,t_btree_7__1_3_2_5_6__1_2_5_6_0_3_4__2__10__102__110__127,Tuple<RamDomain,7>,7,1> wrapper_rel_26_storage;
// -- Table: CrossFunctionReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_CrossFunctionReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_27_CrossFunctionReentrancy;
// -- Table: TransactionOrderDependency
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_28_TransactionOrderDependency = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<25,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_28_TransactionOrderDependency;
// -- Table: error
std::unique_ptr<t_btree_2__0_1__3> rel_29_error = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<26,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_29_error;
// -- Table: DoSWithBlockGasLimit
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_30_DoSWithBlockGasLimit = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<27,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_30_DoSWithBlockGasLimit;
// -- Table: InsufficientGas
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_31_InsufficientGas = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<28,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_31_InsufficientGas;
// -- Table: transfer
std::unique_ptr<t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31> rel_32_transfer = std::make_unique<t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31>();
souffle::RelationWrapper<29,t_btree_5__1_4_0_2_3__1_2_3_0_4__2__6__14__18__31,Tuple<RamDomain,5>,5,1> wrapper_rel_32_transfer;
// -- Table: ERC777Reentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_33_ERC777Reentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<30,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_33_ERC777Reentrancy;
// -- Table: ShortAddress
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_34_ShortAddress = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<31,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_34_ShortAddress;
// -- Table: UncheckedSignature
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_35_UncheckedSignature = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<32,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_35_UncheckedSignature;
// -- Table: arithmetic
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_36_arithmetic = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<33,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_36_arithmetic;
// -- Table: IntegerOverflow
std::unique_ptr<t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095> rel_37_IntegerOverflow = std::make_unique<t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095>();
souffle::RelationWrapper<34,t_btree_12__0_1_2_3_4_5_6_7_8_9_10_11__4095,Tuple<RamDomain,12>,12,1> wrapper_rel_37_IntegerOverflow;
// -- Table: IntegerUnderflow
std::unique_ptr<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047> rel_38_IntegerUnderflow = std::make_unique<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047>();
souffle::RelationWrapper<35,t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047,Tuple<RamDomain,11>,11,1> wrapper_rel_38_IntegerUnderflow;
// -- Table: selfdestruct
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_39_selfdestruct = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<36,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_39_selfdestruct;
// -- Table: ParityWalletHack2
std::unique_ptr<t_btree_8__0_1_2_3_4_5_6_7__255> rel_40_ParityWalletHack2 = std::make_unique<t_btree_8__0_1_2_3_4_5_6_7__255>();
souffle::RelationWrapper<37,t_btree_8__0_1_2_3_4_5_6_7__255,Tuple<RamDomain,8>,8,1> wrapper_rel_40_ParityWalletHack2;
// -- Table: UncheckedSuicide
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_41_UncheckedSuicide = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<38,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_41_UncheckedSuicide;
public:
Sf_analyzer(std::string pf="profile.log") : profiling_fname(pf),

wrapper_rel_1_block(*rel_1_block,symTable,"block",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"block","gas_used","gas_limit","timestamp"}}),

wrapper_rel_2_condition(*rel_2_condition,symTable,"condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","transaction_hash"}}),

wrapper_rel_3_def(*rel_3_def,symTable,"def",std::array<const char *,2>{{"i:number","s:Opcode"}},std::array<const char *,2>{{"step","opcode"}}),

wrapper_rel_4_throw(*rel_4_throw,symTable,"throw",std::array<const char *,5>{{"i:number","s:symbol","s:Opcode","s:Address","i:number"}},std::array<const char *,5>{{"step","transaction_hash","opcode","caller","depth"}}),

wrapper_rel_5_transaction(*rel_5_transaction,symTable,"transaction",std::array<const char *,8>{{"s:symbol","s:Address","s:Address","s:symbol","i:number","i:number","i:number","i:number"}},std::array<const char *,8>{{"transaction_hash","from","to","input_data","gas_used","gas_limit","status","block"}}),

wrapper_rel_6_BlockStuffing(*rel_6_BlockStuffing,symTable,"BlockStuffing",std::array<const char *,4>{{"s:symbol","i:number","s:Address","s:Address"}},std::array<const char *,4>{{"hash","timestamp","from","to"}}),

wrapper_rel_7_use(*rel_7_use,symTable,"use",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"step1","step2"}}),

wrapper_rel_8_BalanceInvariant(*rel_8_BalanceInvariant,symTable,"BalanceInvariant",std::array<const char *,3>{{"s:symbol","i:number","i:number"}},std::array<const char *,3>{{"hash","timestamp","step"}}),

wrapper_rel_9_data_flow(*rel_9_data_flow,symTable,"data_flow",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"x","y"}}),

wrapper_rel_12_used_in_condition(*rel_12_used_in_condition,symTable,"used_in_condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_13_caller_check(*rel_13_caller_check,symTable,"caller_check",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_14_call(*rel_14_call,symTable,"call",std::array<const char *,9>{{"i:number","s:symbol","s:Opcode","s:Address","s:Address","s:symbol","s:Value","i:number","i:number"}},std::array<const char *,9>{{"step","transaction_hash","opcode","caller","callee","input_data","amount","depth","success"}}),

wrapper_rel_15_BlockStateDependence(*rel_15_BlockStateDependence,symTable,"BlockStateDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_16_CallStackDepth(*rel_16_CallStackDepth,symTable,"CallStackDepth",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_17_CreateBasedReentrancy(*rel_17_CreateBasedReentrancy,symTable,"CreateBasedReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_18_DelegatedReentrancy(*rel_18_DelegatedReentrancy,symTable,"DelegatedReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_19_DoSWithUnexpectedThrow(*rel_19_DoSWithUnexpectedThrow,symTable,"DoSWithUnexpectedThrow",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_20_ParityWalletHack1(*rel_20_ParityWalletHack1,symTable,"ParityWalletHack1",std::array<const char *,7>{{"s:symbol","s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash1","hash2","timestamp1","timestamp2","caller","callee","amount"}}),

wrapper_rel_21_Reentrancy(*rel_21_Reentrancy,symTable,"Reentrancy",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","caller","callee","depth","amount"}}),

wrapper_rel_22_TimestampDependence(*rel_22_TimestampDependence,symTable,"TimestampDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_23_TransactionStateDependence(*rel_23_TransactionStateDependence,symTable,"TransactionStateDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_24_UncheckedDelegatecall(*rel_24_UncheckedDelegatecall,symTable,"UncheckedDelegatecall",std::array<const char *,5>{{"s:symbol","i:number","i:number","s:Address","s:Address"}},std::array<const char *,5>{{"hash","timestamp","step","caller","callee"}}),

wrapper_rel_25_UnhandledException(*rel_25_UnhandledException,symTable,"UnhandledException",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_26_storage(*rel_26_storage,symTable,"storage",std::array<const char *,7>{{"i:number","s:Opcode","i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"step","opcode","block","transaction_hash","caller","contract","storage_index"}}),

wrapper_rel_27_CrossFunctionReentrancy(*rel_27_CrossFunctionReentrancy,symTable,"CrossFunctionReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_28_TransactionOrderDependency(*rel_28_TransactionOrderDependency,symTable,"TransactionOrderDependency",std::array<const char *,5>{{"s:symbol","s:symbol","i:number","i:number","s:Address"}},std::array<const char *,5>{{"hash1","hash2","timestamp","block","contract"}}),

wrapper_rel_29_error(*rel_29_error,symTable,"error",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"transaction_hash","error_message"}}),

wrapper_rel_30_DoSWithBlockGasLimit(*rel_30_DoSWithBlockGasLimit,symTable,"DoSWithBlockGasLimit",std::array<const char *,7>{{"s:symbol","i:number","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","gas_limit","caller","callee","amount"}}),

wrapper_rel_31_InsufficientGas(*rel_31_InsufficientGas,symTable,"InsufficientGas",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_32_transfer(*rel_32_transfer,symTable,"transfer",std::array<const char *,5>{{"i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,5>{{"step","transaction_hash","from","to","value"}}),

wrapper_rel_33_ERC777Reentrancy(*rel_33_ERC777Reentrancy,symTable,"ERC777Reentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","amount","asset"}}),

wrapper_rel_34_ShortAddress(*rel_34_ShortAddress,symTable,"ShortAddress",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","from","to","amount"}}),

wrapper_rel_35_UncheckedSignature(*rel_35_UncheckedSignature,symTable,"UncheckedSignature",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","input_data","from","to","amount"}}),

wrapper_rel_36_arithmetic(*rel_36_arithmetic,symTable,"arithmetic",std::array<const char *,6>{{"i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,6>{{"step","opcode","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_37_IntegerOverflow(*rel_37_IntegerOverflow,symTable,"IntegerOverflow",std::array<const char *,12>{{"s:symbol","i:number","i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,12>{{"hash","timestamp","step","opcode","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount","asset"}}),

wrapper_rel_38_IntegerUnderflow(*rel_38_IntegerUnderflow,symTable,"IntegerUnderflow",std::array<const char *,11>{{"s:symbol","i:number","i:number","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value","s:symbol"}},std::array<const char *,11>{{"hash","timestamp","step","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount","asset"}}),

wrapper_rel_39_selfdestruct(*rel_39_selfdestruct,symTable,"selfdestruct",std::array<const char *,6>{{"i:number","s:symbol","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"step","transaction_hash","caller","contract","destination","amount"}}),

wrapper_rel_40_ParityWalletHack2(*rel_40_ParityWalletHack2,symTable,"ParityWalletHack2",std::array<const char *,8>{{"s:symbol","s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,8>{{"hash1","hash2","timestamp1","timestamp2","caller","contract","destination","amount"}}),

wrapper_rel_41_UncheckedSuicide(*rel_41_UncheckedSuicide,symTable,"UncheckedSuicide",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","caller","contract","destination","amount"}}){
ProfileEventSingleton::instance().setOutputFile(profiling_fname);
addRelation("block",&wrapper_rel_1_block,true,false);
addRelation("condition",&wrapper_rel_2_condition,true,false);
addRelation("def",&wrapper_rel_3_def,true,false);
addRelation("throw",&wrapper_rel_4_throw,true,false);
addRelation("transaction",&wrapper_rel_5_transaction,true,false);
addRelation("BlockStuffing",&wrapper_rel_6_BlockStuffing,false,true);
addRelation("use",&wrapper_rel_7_use,true,false);
addRelation("BalanceInvariant",&wrapper_rel_8_BalanceInvariant,false,true);
addRelation("data_flow",&wrapper_rel_9_data_flow,false,false);
addRelation("used_in_condition",&wrapper_rel_12_used_in_condition,false,false);
addRelation("caller_check",&wrapper_rel_13_caller_check,false,false);
addRelation("call",&wrapper_rel_14_call,true,false);
addRelation("BlockStateDependence",&wrapper_rel_15_BlockStateDependence,false,true);
addRelation("CallStackDepth",&wrapper_rel_16_CallStackDepth,false,true);
addRelation("CreateBasedReentrancy",&wrapper_rel_17_CreateBasedReentrancy,false,true);
addRelation("DelegatedReentrancy",&wrapper_rel_18_DelegatedReentrancy,false,true);
addRelation("DoSWithUnexpectedThrow",&wrapper_rel_19_DoSWithUnexpectedThrow,false,true);
addRelation("ParityWalletHack1",&wrapper_rel_20_ParityWalletHack1,false,true);
addRelation("Reentrancy",&wrapper_rel_21_Reentrancy,false,true);
addRelation("TimestampDependence",&wrapper_rel_22_TimestampDependence,false,true);
addRelation("TransactionStateDependence",&wrapper_rel_23_TransactionStateDependence,false,true);
addRelation("UncheckedDelegatecall",&wrapper_rel_24_UncheckedDelegatecall,false,true);
addRelation("UnhandledException",&wrapper_rel_25_UnhandledException,false,true);
addRelation("storage",&wrapper_rel_26_storage,true,false);
addRelation("CrossFunctionReentrancy",&wrapper_rel_27_CrossFunctionReentrancy,false,true);
addRelation("TransactionOrderDependency",&wrapper_rel_28_TransactionOrderDependency,false,true);
addRelation("error",&wrapper_rel_29_error,true,false);
addRelation("DoSWithBlockGasLimit",&wrapper_rel_30_DoSWithBlockGasLimit,false,true);
addRelation("InsufficientGas",&wrapper_rel_31_InsufficientGas,false,true);
addRelation("transfer",&wrapper_rel_32_transfer,true,false);
addRelation("ERC777Reentrancy",&wrapper_rel_33_ERC777Reentrancy,false,true);
addRelation("ShortAddress",&wrapper_rel_34_ShortAddress,false,true);
addRelation("UncheckedSignature",&wrapper_rel_35_UncheckedSignature,false,true);
addRelation("arithmetic",&wrapper_rel_36_arithmetic,true,false);
addRelation("IntegerOverflow",&wrapper_rel_37_IntegerOverflow,false,true);
addRelation("IntegerUnderflow",&wrapper_rel_38_IntegerUnderflow,false,true);
addRelation("selfdestruct",&wrapper_rel_39_selfdestruct,true,false);
addRelation("ParityWalletHack2",&wrapper_rel_40_ParityWalletHack2,false,true);
addRelation("UncheckedSuicide",&wrapper_rel_41_UncheckedSuicide,false,true);
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
ProfileEventSingleton::instance().startTimer();
ProfileEventSingleton::instance().makeTimeEvent("@time;starttime");
{
Logger logger("@runtime;", 0);
ProfileEventSingleton::instance().makeConfigRecord("relationCount", std::to_string(39));[](){
ProfileEventSingleton::instance().makeStratumRecord(0, "relation", "block", "arity", "4");
ProfileEventSingleton::instance().makeStratumRecord(1, "relation", "condition", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(2, "relation", "def", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(3, "relation", "throw", "arity", "5");
ProfileEventSingleton::instance().makeStratumRecord(4, "relation", "transaction", "arity", "8");
ProfileEventSingleton::instance().makeStratumRecord(5, "relation", "BlockStuffing", "arity", "4");
ProfileEventSingleton::instance().makeStratumRecord(6, "relation", "use", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(7, "relation", "BalanceInvariant", "arity", "3");
ProfileEventSingleton::instance().makeStratumRecord(8, "relation", "data_flow", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(9, "relation", "used_in_condition", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(10, "relation", "caller_check", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(11, "relation", "call", "arity", "9");
ProfileEventSingleton::instance().makeStratumRecord(12, "relation", "BlockStateDependence", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(13, "relation", "CallStackDepth", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(14, "relation", "CreateBasedReentrancy", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(15, "relation", "DelegatedReentrancy", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(16, "relation", "DoSWithUnexpectedThrow", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(17, "relation", "ParityWalletHack1", "arity", "7");
ProfileEventSingleton::instance().makeStratumRecord(18, "relation", "Reentrancy", "arity", "7");
ProfileEventSingleton::instance().makeStratumRecord(19, "relation", "TimestampDependence", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(20, "relation", "TransactionStateDependence", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(21, "relation", "UncheckedDelegatecall", "arity", "5");
ProfileEventSingleton::instance().makeStratumRecord(22, "relation", "UnhandledException", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(23, "relation", "storage", "arity", "7");
ProfileEventSingleton::instance().makeStratumRecord(24, "relation", "CrossFunctionReentrancy", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(25, "relation", "TransactionOrderDependency", "arity", "5");
ProfileEventSingleton::instance().makeStratumRecord(26, "relation", "error", "arity", "2");
ProfileEventSingleton::instance().makeStratumRecord(27, "relation", "DoSWithBlockGasLimit", "arity", "7");
ProfileEventSingleton::instance().makeStratumRecord(28, "relation", "InsufficientGas", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(29, "relation", "transfer", "arity", "5");
ProfileEventSingleton::instance().makeStratumRecord(30, "relation", "ERC777Reentrancy", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(31, "relation", "ShortAddress", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(32, "relation", "UncheckedSignature", "arity", "7");
ProfileEventSingleton::instance().makeStratumRecord(33, "relation", "arithmetic", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(34, "relation", "IntegerOverflow", "arity", "12");
ProfileEventSingleton::instance().makeStratumRecord(35, "relation", "IntegerUnderflow", "arity", "11");
ProfileEventSingleton::instance().makeStratumRecord(36, "relation", "selfdestruct", "arity", "6");
ProfileEventSingleton::instance().makeStratumRecord(37, "relation", "ParityWalletHack2", "arity", "8");
ProfileEventSingleton::instance().makeStratumRecord(38, "relation", "UncheckedSuicide", "arity", "7");
}();
/* BEGIN STRATUM 0 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;block;edb.dl [13:7-13:12];loadtime;)_",iter, [&](){return rel_1_block->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;block;edb.dl [13:7-13:12];)",rel_1_block->size(),iter);}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;condition;edb.dl [7:7-7:16];loadtime;)_",iter, [&](){return rel_2_condition->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./condition.facts"},{"name","condition"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_2_condition);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;condition;edb.dl [7:7-7:16];)",rel_2_condition->size(),iter);}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;def;edb.dl [2:7-2:10];loadtime;)_",iter, [&](){return rel_3_def->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_3_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;def;edb.dl [2:7-2:10];)",rel_3_def->size(),iter);}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;throw;edb.dl [10:7-10:12];loadtime;)_",iter, [&](){return rel_4_throw->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_4_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;throw;edb.dl [10:7-10:12];)",rel_4_throw->size(),iter);}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;transaction;edb.dl [14:7-14:18];loadtime;)_",iter, [&](){return rel_5_transaction->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;transaction;edb.dl [14:7-14:18];)",rel_5_transaction->size(),iter);}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;BlockStuffing;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [443:7-443:20];)_",iter, [&](){return rel_6_BlockStuffing->size();});
SignalHandler::instance()->setMsg(R"_(BlockStuffing(hash1,timestamp,from,to) :- 
   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),
   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),
   block(block,_,_,timestamp),
   hash1 != hash2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [444:1-448:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStuffing;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [444:1-448:33];BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;)_",iter, [&](){return rel_6_BlockStuffing->size();});
if(!(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_6_BlockStuffing_op_ctxt,rel_6_BlockStuffing->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(0),0}};
auto range = rel_5_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,8> key{{0,0,env0[2],env0[3],env0[4],env0[5],RamDomain(0),env0[7]}};
auto range = rel_5_transaction->equalRange_252(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) != (env1[0]))) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2])}};
rel_6_BlockStuffing->insert(tuple,READ_OP_CONTEXT(rel_6_BlockStuffing_op_ctxt));
freqs[0]++;
}
freqs[1]++;
break;
}
}
freqs[2]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;BlockStuffing;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [443:7-443:20];savetime;)_",iter, [&](){return rel_6_BlockStuffing->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tfrom\tto"},{"filename","./BlockStuffing.csv"},{"name","BlockStuffing"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_BlockStuffing);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;use;edb.dl [3:7-3:10];loadtime;)_",iter, [&](){return rel_7_use->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_7_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;use;edb.dl [3:7-3:10];)",rel_7_use->size(),iter);}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;BalanceInvariant;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [421:7-421:23];)_",iter, [&](){return rel_8_BalanceInvariant->size();});
SignalHandler::instance()->setMsg(R"_(BalanceInvariant(hash,timestamp,step2) :- 
   def(step1,"BALANCE"),
   condition(step2,hash),
   use(step2,step1),
   throw(step3,hash,_,_,_),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   step2 < step3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [422:1-429:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BalanceInvariant;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [422:1-429:33];BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;)_",iter, [&](){return rel_8_BalanceInvariant->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_4_throw->empty()) && !(rel_7_use->empty()) && !(rel_2_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_condition_op_ctxt,rel_2_condition->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_4_throw_op_ctxt,rel_4_throw->createContext());
CREATE_OP_CONTEXT(rel_7_use_op_ctxt,rel_7_use->createContext());
CREATE_OP_CONTEXT(rel_8_BalanceInvariant_op_ctxt,rel_8_BalanceInvariant->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(31)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_2_condition) {
if( (reads[0]++,rel_7_use->contains(Tuple<RamDomain,2>{{env1[0],env0[0]}},READ_OP_CONTEXT(rel_7_use_op_ctxt)))) {
const Tuple<RamDomain,5> key{{0,env1[1],0,0,0}};
auto range = rel_4_throw->equalRange_2(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0])}};
rel_8_BalanceInvariant->insert(tuple,READ_OP_CONTEXT(rel_8_BalanceInvariant_op_ctxt));
freqs[3]++;
}
freqs[4]++;
}
freqs[5]++;
break;
}
}
}
freqs[6]++;
}
freqs[7]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;BalanceInvariant;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [421:7-421:23];savetime;)_",iter, [&](){return rel_8_BalanceInvariant->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep"},{"filename","./BalanceInvariant.csv"},{"name","BalanceInvariant"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;data_flow;lib/horus.dl [4:7-4:16];)_",iter, [&](){return rel_9_data_flow->size();});
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,x).
in file lib/horus.dl [5:1-6:13])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;data_flow;lib/horus.dl [5:1-6:13];data_flow(x,y) :- \n   use(y,x).;)_",iter, [&](){return rel_9_data_flow->size();});
if(!(rel_7_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_use_op_ctxt,rel_7_use->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
for(const auto& env0 : *rel_7_use) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[0])}};
rel_9_data_flow->insert(tuple,READ_OP_CONTEXT(rel_9_data_flow_op_ctxt));
freqs[8]++;
}
}
();}
}
}
rel_10_delta_data_flow->insertAll(*rel_9_data_flow);
iter = 0;
for(;;) {
{
	Logger logger(R"_(@t-recursive-relation;data_flow;lib/horus.dl [4:7-4:16];)_",iter, [&](){return rel_11_new_data_flow->size();});
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,z),
   data_flow(x,z).
in file lib/horus.dl [8:1-10:19])_");
{
	Logger logger(R"_(@t-recursive-rule;data_flow;0;lib/horus.dl [8:1-10:19];data_flow(x,y) :- \n   use(y,z),\n   data_flow(x,z).;)_",iter, [&](){return rel_11_new_data_flow->size();});
if(!(rel_10_delta_data_flow->empty()) && !(rel_7_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_7_use_op_ctxt,rel_7_use->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_delta_data_flow_op_ctxt,rel_10_delta_data_flow->createContext());
CREATE_OP_CONTEXT(rel_11_new_data_flow_op_ctxt,rel_11_new_data_flow->createContext());
for(const auto& env0 : *rel_7_use) {
const Tuple<RamDomain,2> key{{0,env0[1]}};
auto range = rel_10_delta_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_10_delta_data_flow_op_ctxt));
for(const auto& env1 : range) {
if( !((reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env0[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt))))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[0])}};
rel_11_new_data_flow->insert(tuple,READ_OP_CONTEXT(rel_11_new_data_flow_op_ctxt));
}
freqs[9]++;
}
freqs[10]++;
}
}
();}
}
}
if(rel_11_new_data_flow->empty()) break;
{
	Logger logger(R"_(@c-recursive-relation;data_flow;lib/horus.dl [4:7-4:16];)_",iter, [&](){return rel_11_new_data_flow->size();});
rel_9_data_flow->insertAll(*rel_11_new_data_flow);
std::swap(rel_10_delta_data_flow, rel_11_new_data_flow);
rel_11_new_data_flow->purge();
}
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_10_delta_data_flow->purge();
if (!isHintsProfilingEnabled()) rel_11_new_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_7_use->purge();
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;used_in_condition;lib/horus.dl [12:7-12:24];)_",iter, [&](){return rel_12_used_in_condition->size();});
SignalHandler::instance()->setMsg(R"_(used_in_condition(step1,hash) :- 
   condition(step2,hash),
   data_flow(step1,step2).
in file lib/horus.dl [13:1-15:27])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;used_in_condition;lib/horus.dl [13:1-15:27];used_in_condition(step1,hash) :- \n   condition(step2,hash),\n   data_flow(step1,step2).;)_",iter, [&](){return rel_12_used_in_condition->size();});
if(!(rel_9_data_flow->empty()) && !(rel_2_condition->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_condition_op_ctxt,rel_2_condition->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
for(const auto& env0 : *rel_2_condition) {
const Tuple<RamDomain,2> key{{0,env0[0]}};
auto range = rel_9_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_9_data_flow_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[1])}};
rel_12_used_in_condition->insert(tuple,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
freqs[11]++;
}
freqs[12]++;
}
}
();}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_2_condition->purge();
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;caller_check;lib/horus.dl [17:7-17:19];)_",iter, [&](){return rel_13_caller_check->size();});
SignalHandler::instance()->setMsg(R"_(caller_check(step1,hash) :- 
   def(step1,"CALLER"),
   used_in_condition(step1,hash).
in file lib/horus.dl [18:1-20:34])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;caller_check;lib/horus.dl [18:1-20:34];caller_check(step1,hash) :- \n   def(step1,\"CALLER\"),\n   used_in_condition(step1,hash).;)_",iter, [&](){return rel_13_caller_check->size();});
if(!(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_caller_check_op_ctxt,rel_13_caller_check->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(0)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env1[1])}};
rel_13_caller_check->insert(tuple,READ_OP_CONTEXT(rel_13_caller_check_op_ctxt));
freqs[13]++;
}
freqs[14]++;
}
}
();}
}
}
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;call;edb.dl [9:7-9:11];loadtime;)_",iter, [&](){return rel_14_call->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_14_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;call;edb.dl [9:7-9:11];)",rel_14_call->size(),iter);}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [366:7-366:27];)_",iter, [&](){return rel_15_BlockStateDependence->size();});
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"BLOCKHASH"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33];BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt,rel_15_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(24)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_15_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt));
freqs[15]++;
}
freqs[16]++;
}
}
freqs[17]++;
}
freqs[18]++;
}
freqs[19]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step2,"COINBASE"),
   used_in_condition(step1,hash),
   call(_,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33];BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt,rel_15_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(25)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_12_used_in_condition) {
if( ((env1[0]) < (env0[0]))) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_15_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt));
freqs[20]++;
}
freqs[21]++;
}
}
freqs[22]++;
}
}
freqs[23]++;
}
freqs[24]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"NUMBER"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33];BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt,rel_15_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(26)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_15_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt));
freqs[25]++;
}
freqs[26]++;
}
}
freqs[27]++;
}
freqs[28]++;
}
freqs[29]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"DIFFICULTY"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33];BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt,rel_15_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(27)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_15_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt));
freqs[30]++;
}
freqs[31]++;
}
}
freqs[32]++;
}
freqs[33]++;
}
freqs[34]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"GASLIMIT"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [367:1-406:33];BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt,rel_15_BlockStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(28)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_15_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_15_BlockStateDependence_op_ctxt));
freqs[35]++;
}
freqs[36]++;
}
}
freqs[37]++;
}
freqs[38]++;
}
freqs[39]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;BlockStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [366:7-366:27];savetime;)_",iter, [&](){return rel_15_BlockStateDependence->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;CallStackDepth;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [4:7-4:21];)_",iter, [&](){return rel_16_CallStackDepth->size();});
SignalHandler::instance()->setMsg(R"_(CallStackDepth(hash,timestamp,step,caller,callee,amount) :- 
   call(step,hash,"CALL",caller,callee,_,amount,depth,_),
   transaction(hash,_,_,_,_,_,_,block),
   block(block,_,_,timestamp),
   depth > 1024.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [5:1-9:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;CallStackDepth;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [5:1-9:33];CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;)_",iter, [&](){return rel_16_CallStackDepth->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_16_CallStackDepth_op_ctxt,rel_16_CallStackDepth->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,0}};
auto range = rel_14_call->equalRange_4(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[7]) > (RamDomain(1024)))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,0,0}};
auto range = rel_5_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_16_CallStackDepth->insert(tuple,READ_OP_CONTEXT(rel_16_CallStackDepth_op_ctxt));
freqs[40]++;
}
freqs[41]++;
}
}
freqs[42]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;CallStackDepth;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [4:7-4:21];savetime;)_",iter, [&](){return rel_16_CallStackDepth->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;CreateBasedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [106:7-106:28];)_",iter, [&](){return rel_17_CreateBasedReentrancy->size();});
SignalHandler::instance()->setMsg(R"_(CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- 
   call(step1,hash,"CALL",caller,callee1,_,amount,depth1,1),
   call(step2,hash,"CREATE",callee1,_,input_data,_,depth2,1),
   call(step3,hash,"CREATE",callee1,callee2,input_data,_,depth3,1),
   call(step4,hash,"CALL",callee2,caller,_,amount,depth4,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   step1 < step2,
   step2 < step3,
   step3 < step4,
   depth1 < depth2,
   depth2 < depth3,
   depth1 < depth4,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [107:1-120:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;CreateBasedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [107:1-120:33];CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_17_CreateBasedReentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_17_CreateBasedReentrancy_op_ctxt,rel_17_CreateBasedReentrancy->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(10),env0[4],0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_270(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(10),env0[4],0,env1[5],0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_302(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0])) && ((env1[7]) < (env2[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env2[4],env0[3],0,env0[6],0,RamDomain(1)}};
auto range = rel_14_call->equalRange_350(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0])) && ((env0[7]) < (env3[7]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[7]),static_cast<RamDomain>(env0[6])}};
rel_17_CreateBasedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_17_CreateBasedReentrancy_op_ctxt));
freqs[43]++;
}
freqs[44]++;
}
freqs[45]++;
break;
}
}
}
freqs[46]++;
}
}
freqs[47]++;
}
}
freqs[48]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;CreateBasedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [106:7-106:28];savetime;)_",iter, [&](){return rel_17_CreateBasedReentrancy->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;DelegatedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:7-74:26];)_",iter, [&](){return rel_18_DelegatedReentrancy->size();});
SignalHandler::instance()->setMsg(R"_(DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- 
   call(step1,hash,"DELEGATECALL",caller,callee1,input_data,"0",depth1,1),
   call(step2,hash,"CALL",caller,callee2,"",amount,depth2,1),
   call(step3,hash,"DELEGATECALL",caller,callee1,input_data,"0",depth3,1),
   call(step4,hash,"CALL",caller,callee2,"",amount,depth4,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   step1 < step2,
   step2 < step3,
   step3 < step4,
   depth1 < depth2,
   depth2 < depth3,
   depth3 < depth4,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [75:1-102:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;DelegatedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [75:1-102:33];DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_18_DelegatedReentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt,rel_18_DelegatedReentrancy->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(8),0,0,0,RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_324(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],0,RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_302(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(8),env0[3],env0[4],env0[5],RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_382(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0])) && ((env1[7]) < (env2[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env1[4],RamDomain(6),env1[6],0,RamDomain(1)}};
auto range = rel_14_call->equalRange_382(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0])) && ((env2[7]) < (env3[7]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env3[7]),static_cast<RamDomain>(env1[6])}};
rel_18_DelegatedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt));
freqs[49]++;
}
freqs[50]++;
}
}
freqs[51]++;
}
}
freqs[52]++;
}
}
freqs[53]++;
}
freqs[54]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- 
   call(step1,hash,"CALLCODE",caller,callee1,input_data,"0",depth1,1),
   call(step2,hash,"CALL",caller,callee2,"",amount,depth2,1),
   call(step3,hash,"CALLCODE",caller,callee1,input_data,"0",depth3,1),
   call(step4,hash,"CALL",caller,callee2,"",amount,depth4,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   step1 < step2,
   step2 < step3,
   step3 < step4,
   depth1 < depth2,
   depth2 < depth3,
   depth3 < depth4,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [75:1-102:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;DelegatedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [75:1-102:33];DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_18_DelegatedReentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt,rel_18_DelegatedReentrancy->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(9),0,0,0,RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_324(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],0,RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_302(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(9),env0[3],env0[4],env0[5],RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_382(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0])) && ((env1[7]) < (env2[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env1[4],RamDomain(6),env1[6],0,RamDomain(1)}};
auto range = rel_14_call->equalRange_382(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0])) && ((env2[7]) < (env3[7]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env3[7]),static_cast<RamDomain>(env1[6])}};
rel_18_DelegatedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt));
freqs[55]++;
}
freqs[56]++;
}
}
freqs[57]++;
}
}
freqs[58]++;
}
}
freqs[59]++;
}
freqs[60]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;DelegatedReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:7-74:26];savetime;)_",iter, [&](){return rel_18_DelegatedReentrancy->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./DelegatedReentrancy.csv"},{"name","DelegatedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;DoSWithUnexpectedThrow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [315:7-315:29];)_",iter, [&](){return rel_19_DoSWithUnexpectedThrow->size();});
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
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [316:1-326:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;DoSWithUnexpectedThrow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [316:1-326:33];DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;)_",iter, [&](){return rel_19_DoSWithUnexpectedThrow->size();});
if(!(rel_14_call->empty()) && !(rel_4_throw->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_4_throw_op_ctxt,rel_4_throw->createContext());
CREATE_OP_CONTEXT(rel_19_DoSWithUnexpectedThrow_op_ctxt,rel_19_DoSWithUnexpectedThrow->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,(env0[7]) + (RamDomain(1))}};
auto range = rel_4_throw->equalRange_18(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,env0[7]}};
auto range = rel_4_throw->equalRange_18(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,0,0}};
auto range = rel_5_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_19_DoSWithUnexpectedThrow->insert(tuple,READ_OP_CONTEXT(rel_19_DoSWithUnexpectedThrow_op_ctxt));
freqs[61]++;
}
freqs[62]++;
}
}
freqs[63]++;
}
}
freqs[64]++;
}
}
freqs[65]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;DoSWithUnexpectedThrow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [315:7-315:29];savetime;)_",iter, [&](){return rel_19_DoSWithUnexpectedThrow->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_4_throw->purge();
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;ParityWalletHack1;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [252:7-252:24];)_",iter, [&](){return rel_20_ParityWalletHack1->size();});
SignalHandler::instance()->setMsg(R"_(ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- 
   call(_,hash1,"DELEGATECALL",_,_,_,_,_,1),
   transaction(hash1,from,to,input_data1,_,_,1,block1),
   block(block1,_,_,timestamp1),
   call(_,hash2,"DELEGATECALL",_,_,_,_,_,1),
   transaction(hash2,from,to,input_data2,_,_,1,block2),
   block(block2,_,_,timestamp2),
   call(_,hash2,"CALL",caller,callee,_,amount,_,1),
   substr(input_data1,0,8) = "e46dcfeb",
   substr(input_data2,0,8) = "b61d27f6",
   block1 <= block2,
   amount not_match "0".
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [253:1-264:23])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ParityWalletHack1;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [253:1-264:23];ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;)_",iter, [&](){return rel_20_ParityWalletHack1->size();});
if(!(rel_5_transaction->empty()) && !(rel_1_block->empty()) && !(rel_14_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_20_ParityWalletHack1_op_ctxt,rel_20_ParityWalletHack1->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(8),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(16)))) {
const Tuple<RamDomain,4> key{{env1[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(8),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env3[1],env1[1],env1[2],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_71(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env4[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(17))) && ((env1[7]) <= (env4[7]))) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
const Tuple<RamDomain,9> key{{0,env3[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env6 : range) {
if( !regex_wrapper(symTable.resolve(env6[6]),symTable.resolve(RamDomain(2)))) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env3[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env6[3]),static_cast<RamDomain>(env6[4]),static_cast<RamDomain>(env6[6])}};
rel_20_ParityWalletHack1->insert(tuple,READ_OP_CONTEXT(rel_20_ParityWalletHack1_op_ctxt));
}
freqs[66]++;
}
freqs[67]++;
}
}
freqs[68]++;
}
freqs[69]++;
}
freqs[70]++;
}
}
freqs[71]++;
}
freqs[72]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;ParityWalletHack1;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [252:7-252:24];savetime;)_",iter, [&](){return rel_20_ParityWalletHack1->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [13:7-13:17];)_",iter, [&](){return rel_21_Reentrancy->size();});
SignalHandler::instance()->setMsg(R"_(Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- 
   call(step1,hash,"CALL",caller,callee,input_data,_,depth1,1),
   call(step2,hash,"CALL",caller,callee,input_data,amount,depth2,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   step1 < step2,
   depth1 < depth2,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [14:1-21:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [14:1-21:33];Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_21_Reentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_21_Reentrancy_op_ctxt,rel_21_Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],env0[5],0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_318(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env1[7]),static_cast<RamDomain>(env1[6])}};
rel_21_Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_21_Reentrancy_op_ctxt));
freqs[73]++;
}
freqs[74]++;
}
}
freqs[75]++;
}
freqs[76]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [13:7-13:17];savetime;)_",iter, [&](){return rel_21_Reentrancy->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;TimestampDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [341:7-341:26];)_",iter, [&](){return rel_22_TimestampDependence->size();});
SignalHandler::instance()->setMsg(R"_(TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"TIMESTAMP"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [342:1-349:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;TimestampDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [342:1-349:33];TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;)_",iter, [&](){return rel_22_TimestampDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_22_TimestampDependence_op_ctxt,rel_22_TimestampDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(22)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_22_TimestampDependence->insert(tuple,READ_OP_CONTEXT(rel_22_TimestampDependence_op_ctxt));
freqs[77]++;
}
freqs[78]++;
}
}
freqs[79]++;
}
freqs[80]++;
}
freqs[81]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;TimestampDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [341:7-341:26];savetime;)_",iter, [&](){return rel_22_TimestampDependence->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;TransactionStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [353:7-353:33];)_",iter, [&](){return rel_23_TransactionStateDependence->size();});
SignalHandler::instance()->setMsg(R"_(TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"ORIGIN"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,from,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2,
   callee != from.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [354:1-362:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;TransactionStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [354:1-362:33];TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;)_",iter, [&](){return rel_23_TransactionStateDependence->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty()) && !(rel_12_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_23_TransactionStateDependence_op_ctxt,rel_23_TransactionStateDependence->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(23)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_12_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[4]) != (env3[1]))) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_23_TransactionStateDependence->insert(tuple,READ_OP_CONTEXT(rel_23_TransactionStateDependence_op_ctxt));
freqs[82]++;
}
}
freqs[83]++;
}
}
freqs[84]++;
}
freqs[85]++;
}
freqs[86]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;TransactionStateDependence;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [353:7-353:33];savetime;)_",iter, [&](){return rel_23_TransactionStateDependence->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;UncheckedDelegatecall;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [240:7-240:28];)_",iter, [&](){return rel_24_UncheckedDelegatecall->size();});
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"DELEGATECALL",caller,callee,_,_,_,1),
   data_flow(step1,step2),
   transaction(hash,_,_,input_data,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash),
   substr(callee,2,strlen(callee)) contains input_data.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [241:1-248:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;UncheckedDelegatecall;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [241:1-248:33];UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;)_",iter, [&](){return rel_24_UncheckedDelegatecall->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_24_UncheckedDelegatecall_op_ctxt,rel_24_UncheckedDelegatecall->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
CREATE_OP_CONTEXT(rel_13_caller_check_op_ctxt,rel_13_caller_check->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(8),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( !((reads[2]++,!rel_13_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env1[1]}},READ_OP_CONTEXT(rel_13_caller_check_op_ctxt)).empty())) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
if( (symTable.resolve(env2[3]).find(symTable.resolve(symTable.lookup(substr_wrapper(symTable.resolve(env1[4]),(RamDomain(2)),(static_cast<RamDomain>(symTable.resolve(env1[4]).size())))))) != std::string::npos)) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_24_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_24_UncheckedDelegatecall_op_ctxt));
freqs[87]++;
}
}
freqs[88]++;
}
}
freqs[89]++;
}
freqs[90]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;UncheckedDelegatecall;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [240:7-240:28];savetime;)_",iter, [&](){return rel_24_UncheckedDelegatecall->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;UnhandledException;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [124:7-124:25];)_",iter, [&](){return rel_25_UnhandledException->size();});
SignalHandler::instance()->setMsg(R"_(UnhandledException(hash,timestamp,step1,caller,callee,amount) :- 
   call(step1,hash,"CALL",caller,callee,_,amount,_,0),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   !used_in_condition(step1,hash),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [125:1-130:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;UnhandledException;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [125:1-130:33];UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;)_",iter, [&](){return rel_25_UnhandledException->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_14_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_used_in_condition_op_ctxt,rel_12_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_25_UnhandledException_op_ctxt,rel_25_UnhandledException->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( !((reads[3]++,rel_12_used_in_condition->contains(Tuple<RamDomain,2>{{env0[0],env0[1]}},READ_OP_CONTEXT(rel_12_used_in_condition_op_ctxt)))) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_25_UnhandledException->insert(tuple,READ_OP_CONTEXT(rel_25_UnhandledException_op_ctxt));
freqs[91]++;
}
freqs[92]++;
}
}
freqs[93]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;UnhandledException;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [124:7-124:25];savetime;)_",iter, [&](){return rel_25_UnhandledException->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_12_used_in_condition->purge();
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;storage;edb.dl [6:7-6:14];loadtime;)_",iter, [&](){return rel_26_storage->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_26_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;storage;edb.dl [6:7-6:14];)",rel_26_storage->size(),iter);}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;CrossFunctionReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [54:7-54:30];)_",iter, [&](){return rel_27_CrossFunctionReentrancy->size();});
SignalHandler::instance()->setMsg(R"_(CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- 
   call(step1,hash,"CALL",caller,callee,input_data1,"0",depth1,1),
   call(step2,hash,"CALL",callee,caller,"",amount,depth2,1),
   call(step3,hash,"CALL",caller,callee,input_data2,"0",depth3,1),
   storage(step4,"SSTORE",block,hash,_,contract,index),
   transaction(hash,_,_,_,_,_,1,block),
   storage(step5,"SSTORE",block,hash,_,contract,index),
   block(block,_,_,timestamp),
   step1 < step2,
   step2 < step3,
   step3 < step4,
   step4 < step5,
   depth1 < depth2,
   depth2 < depth3,
   substr(input_data1,0,8) != substr(input_data2,0,8),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [55:1-70:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;CrossFunctionReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [55:1-70:33];CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;)_",iter, [&](){return rel_27_CrossFunctionReentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_26_storage->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_27_CrossFunctionReentrancy_op_ctxt,rel_27_CrossFunctionReentrancy->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_324(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[4],env0[3],RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_318(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],0,RamDomain(2),0,RamDomain(1)}};
auto range = rel_14_call->equalRange_350(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0])) && ((env1[7]) < (env2[7])) && ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) != (symTable.lookup(substr_wrapper(symTable.resolve(env2[5]),(RamDomain(0)),(RamDomain(8))))))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,env0[1],0,0,0}};
auto range = rel_26_storage->equalRange_10(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0])) && (reads[4]++,!rel_5_transaction->equalRange_193(Tuple<RamDomain,8>{{env0[1],0,0,0,0,0,RamDomain(1),env3[2]}},READ_OP_CONTEXT(rel_5_transaction_op_ctxt)).empty())) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),env3[2],env0[1],0,env3[5],env3[6]}};
auto range = rel_26_storage->equalRange_110(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env4 : range) {
if( ((env3[0]) < (env4[0]))) {
const Tuple<RamDomain,4> key{{env3[2],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[7]),static_cast<RamDomain>(env1[6])}};
rel_27_CrossFunctionReentrancy->insert(tuple,READ_OP_CONTEXT(rel_27_CrossFunctionReentrancy_op_ctxt));
freqs[94]++;
}
freqs[95]++;
break;
}
}
}
freqs[96]++;
}
}
freqs[97]++;
}
}
freqs[98]++;
}
freqs[99]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;CrossFunctionReentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [54:7-54:30];savetime;)_",iter, [&](){return rel_27_CrossFunctionReentrancy->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;TransactionOrderDependency;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [218:7-218:33];)_",iter, [&](){return rel_28_TransactionOrderDependency->size();});
SignalHandler::instance()->setMsg(R"_(TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- 
   storage(step1,"SSTORE",block,hash1,caller1,contract,index),
   storage(step2,"SLOAD",block,hash2,caller2,contract,index),
   block(block,_,_,timestamp),
   hash1 != hash2,
   step1 < step2,
   caller1 != caller2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [219:1-225:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;TransactionOrderDependency;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [219:1-225:33];TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;)_",iter, [&](){return rel_28_TransactionOrderDependency->size();});
if(!(rel_26_storage->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_28_TransactionOrderDependency_op_ctxt,rel_28_TransactionOrderDependency->createContext());
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(15),env0[2],0,0,env0[5],env0[6]}};
auto range = rel_26_storage->equalRange_102(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[3]) != (env1[3])) && ((env0[0]) < (env1[0])) && ((env0[4]) != (env1[4]))) {
const Tuple<RamDomain,4> key{{env0[2],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[5])}};
rel_28_TransactionOrderDependency->insert(tuple,READ_OP_CONTEXT(rel_28_TransactionOrderDependency_op_ctxt));
freqs[100]++;
}
}
freqs[101]++;
}
freqs[102]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;TransactionOrderDependency;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [218:7-218:33];savetime;)_",iter, [&](){return rel_28_TransactionOrderDependency->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp\tblock\tcontract"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;error;edb.dl [12:7-12:12];loadtime;)_",iter, [&](){return rel_29_error->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_29_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;error;edb.dl [12:7-12:12];)",rel_29_error->size(),iter);}();
/* END STRATUM 26 */
/* BEGIN STRATUM 27 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;DoSWithBlockGasLimit;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [330:7-330:27];)_",iter, [&](){return rel_30_DoSWithBlockGasLimit->size();});
SignalHandler::instance()->setMsg(R"_(DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- 
   block(block,gas_limit,gas_limit,timestamp),
   transaction(hash,_,_,_,_,_,_,block),
   error(hash,"out of gas"),
   call(step,hash,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [331:1-337:29])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;DoSWithBlockGasLimit;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [331:1-337:29];DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;)_",iter, [&](){return rel_30_DoSWithBlockGasLimit->size();});
if(!(rel_14_call->empty()) && !(rel_29_error->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_29_error_op_ctxt,rel_29_error->createContext());
CREATE_OP_CONTEXT(rel_30_DoSWithBlockGasLimit_op_ctxt,rel_30_DoSWithBlockGasLimit->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
for(const auto& env0 : *rel_1_block) {
if( ((env0[1]) == (env0[2]))) {
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,0,env0[0]}};
auto range = rel_5_transaction->equalRange_128(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
if( (reads[5]++,rel_29_error->contains(Tuple<RamDomain,2>{{env1[0],RamDomain(21)}},READ_OP_CONTEXT(rel_29_error_op_ctxt)))) {
const Tuple<RamDomain,9> key{{0,env1[0],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_262(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6]))) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_30_DoSWithBlockGasLimit->insert(tuple,READ_OP_CONTEXT(rel_30_DoSWithBlockGasLimit_op_ctxt));
}
freqs[103]++;
}
}
freqs[104]++;
}
}
freqs[105]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;DoSWithBlockGasLimit;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [330:7-330:27];savetime;)_",iter, [&](){return rel_30_DoSWithBlockGasLimit->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tgas_limit\tcaller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;InsufficientGas;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [432:7-432:22];)_",iter, [&](){return rel_31_InsufficientGas->size();});
SignalHandler::instance()->setMsg(R"_(InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"CALL",caller,callee,_,amount,_,0),
   data_flow(step1,step2),
   error(hash,"out of gas"),
   storage(_,"SSTORE",_,hash,_,_,_),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [433:1-440:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;InsufficientGas;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [433:1-440:33];InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;)_",iter, [&](){return rel_31_InsufficientGas->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_26_storage->empty()) && !(rel_29_error->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_29_error_op_ctxt,rel_29_error->createContext());
CREATE_OP_CONTEXT(rel_31_InsufficientGas_op_ctxt,rel_31_InsufficientGas->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt))) && (reads[5]++,rel_29_error->contains(Tuple<RamDomain,2>{{env1[1],RamDomain(21)}},READ_OP_CONTEXT(rel_29_error_op_ctxt))) && (reads[6]++,!rel_26_storage->equalRange_10(Tuple<RamDomain,7>{{0,RamDomain(7),0,env1[1],0,0,0}},READ_OP_CONTEXT(rel_26_storage_op_ctxt)).empty())) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[6])}};
rel_31_InsufficientGas->insert(tuple,READ_OP_CONTEXT(rel_31_InsufficientGas_op_ctxt));
freqs[106]++;
}
freqs[107]++;
}
}
freqs[108]++;
}
freqs[109]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;InsufficientGas;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [432:7-432:22];savetime;)_",iter, [&](){return rel_31_InsufficientGas->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./InsufficientGas.csv"},{"name","InsufficientGas"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_29_error->purge();
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;transfer;edb.dl [8:7-8:15];loadtime;)_",iter, [&](){return rel_32_transfer->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;transfer;edb.dl [8:7-8:15];)",rel_32_transfer->size(),iter);}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;ERC777Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [25:7-25:23];)_",iter, [&](){return rel_33_ERC777Reentrancy->size();});
SignalHandler::instance()->setMsg(R"_(ERC777Reentrancy(hash,timestamp,caller,callee,amount,"Ether") :- 
   call(step1,hash,"CALL",caller,callee,input_data1,_,_,1),
   call(step2,hash,"CALL",caller,callee,input_data2,_,_,1),
   call(step3,hash,"CALL",callee,from,_,amount,_,1),
   transaction(hash,from,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   substr(input_data1,0,8) = "75ab9782",
   substr(input_data2,0,8) = "75ab9782",
   step1 < step2,
   "0" not_match amount,
   step2 < step3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [26:1-50:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ERC777Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [26:1-50:19];ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;)_",iter, [&](){return rel_33_ERC777Reentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_33_ERC777Reentrancy_op_ctxt,rel_33_ERC777Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(3)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_286(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(3))) && ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[4],0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_270(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,8> key{{env0[1],env2[4],0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_67(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env2[6]),static_cast<RamDomain>(RamDomain(4))}};
rel_33_ERC777Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_33_ERC777Reentrancy_op_ctxt));
freqs[110]++;
}
freqs[111]++;
}
}
freqs[112]++;
}
}
freqs[113]++;
}
}
freqs[114]++;
}
}
();}
}
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
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [26:1-50:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ERC777Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [26:1-50:19];ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;)_",iter, [&](){return rel_33_ERC777Reentrancy->size();});
if(!(rel_14_call->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_33_ERC777Reentrancy_op_ctxt,rel_33_ERC777Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_260(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(3)))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_286(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env1[5]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(3))) && ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,5> key{{0,env0[1],env0[4],0,0}};
auto range = rel_32_transfer->equalRange_6(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,5> key{{0,env0[1],env2[3],env0[4],0}};
auto range = rel_32_transfer->equalRange_14(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env3[4])) && ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,8> key{{env0[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(RamDomain(5))}};
rel_33_ERC777Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_33_ERC777Reentrancy_op_ctxt));
freqs[115]++;
}
freqs[116]++;
}
}
freqs[117]++;
}
freqs[118]++;
}
freqs[119]++;
break;
}
}
}
freqs[120]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;ERC777Reentrancy;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [25:7-25:23];savetime;)_",iter, [&](){return rel_33_ERC777Reentrancy->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tamount\tasset"},{"filename","./ERC777Reentrancy.csv"},{"name","ERC777Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;ShortAddress;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [283:7-283:19];)_",iter, [&](){return rel_34_ShortAddress->size();});
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,timestamp,step6,from,to,amount) :- 
   transaction(hash,_,_,input_data,_,_,1,block),
   transfer(step6,hash,from,to,amount),
   block(block,_,_,timestamp),
   substr(input_data,0,8) = "a9059cbb",
   (strlen(input_data)/2) < 68.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [301:1-311:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ShortAddress;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [301:1-311:33];ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;)_",iter, [&](){return rel_34_ShortAddress->size();});
if(!(rel_1_block->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_34_ShortAddress_op_ctxt,rel_34_ShortAddress->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(19))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(68)))) {
const Tuple<RamDomain,5> key{{0,env0[0],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_34_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_34_ShortAddress_op_ctxt));
freqs[121]++;
}
freqs[122]++;
}
}
freqs[123]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,timestamp,step6,from,to,amount) :- 
   transaction(hash,_,_,input_data,_,_,1,block),
   transfer(step6,hash,from,to,amount),
   block(block,_,_,timestamp),
   substr(input_data,0,8) = "23b872dd",
   (strlen(input_data)/2) < 100.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [301:1-311:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ShortAddress;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [301:1-311:33];ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;)_",iter, [&](){return rel_34_ShortAddress->size();});
if(!(rel_1_block->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_34_ShortAddress_op_ctxt,rel_34_ShortAddress->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env0 : range) {
if( ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(20))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(100)))) {
const Tuple<RamDomain,5> key{{0,env0[0],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_34_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_34_ShortAddress_op_ctxt));
freqs[124]++;
}
freqs[125]++;
}
}
freqs[126]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;ShortAddress;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [283:7-283:19];savetime;)_",iter, [&](){return rel_34_ShortAddress->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfrom\tto\tamount"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;UncheckedSignature;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [409:7-409:25];)_",iter, [&](){return rel_35_UncheckedSignature->size();});
SignalHandler::instance()->setMsg(R"_(UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- 
   def(step1,"SHA3"),
   call(step2,hash,"CALL",_,"0x0000000000000000000000000000000000000001",input_data,_,_,1),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   !data_flow(step1,step3).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [410:1-418:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;UncheckedSignature;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [410:1-418:33];UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;)_",iter, [&](){return rel_35_UncheckedSignature->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_32_transfer->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_35_UncheckedSignature_op_ctxt,rel_35_UncheckedSignature->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(29)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,RamDomain(30),0,0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_276(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env1 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,env1[1],0,0,0}};
auto range = rel_26_storage->equalRange_10(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( !((reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt))))) {
const Tuple<RamDomain,5> key{{0,env1[1],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4])}};
rel_35_UncheckedSignature->insert(tuple,READ_OP_CONTEXT(rel_35_UncheckedSignature_op_ctxt));
freqs[127]++;
}
freqs[128]++;
}
freqs[129]++;
}
freqs[130]++;
break;
}
}
}
freqs[131]++;
}
freqs[132]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;UncheckedSignature;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [409:7-409:25];savetime;)_",iter, [&](){return rel_35_UncheckedSignature->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tinput_data\tfrom\tto\tamount"},{"filename","./UncheckedSignature.csv"},{"name","UncheckedSignature"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;arithmetic;edb.dl [4:7-4:17];loadtime;)_",iter, [&](){return rel_36_arithmetic->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_36_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;arithmetic;edb.dl [4:7-4:17];)",rel_36_arithmetic->size(),iter);}();
/* END STRATUM 33 */
/* BEGIN STRATUM 34 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [134:7-134:22];)_",iter, [&](){return rel_37_IntegerOverflow->size();});
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"ADD",first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"ADD",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19];IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;)_",iter, [&](){return rel_37_IntegerOverflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt,rel_37_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(12),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_32_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(5))}};
rel_37_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt));
freqs[133]++;
}
freqs[134]++;
}
freqs[135]++;
}
}
freqs[136]++;
}
}
freqs[137]++;
}
freqs[138]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"ADD",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,"Ether") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"ADD",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   call(_,hash,"CALL",from,to,"",amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19];IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_37_IntegerOverflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt,rel_37_IntegerOverflow->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(12),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,9> key{{0,env2[3],RamDomain(1),0,0,RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_294(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env3[6]))) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(env3[6]),static_cast<RamDomain>(RamDomain(4))}};
rel_37_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt));
freqs[139]++;
}
freqs[140]++;
}
}
freqs[141]++;
}
}
freqs[142]++;
}
}
freqs[143]++;
}
freqs[144]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"MUL",first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"MUL",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19];IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;)_",iter, [&](){return rel_37_IntegerOverflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt,rel_37_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(13),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_32_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(5))}};
rel_37_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt));
freqs[145]++;
}
freqs[146]++;
}
freqs[147]++;
}
}
freqs[148]++;
}
}
freqs[149]++;
}
freqs[150]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,"MUL",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,"Ether") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"MUL",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   call(_,hash,"CALL",from,to,"",amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [135:1-186:19];IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_37_IntegerOverflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt,rel_37_IntegerOverflow->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(13),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,9> key{{0,env2[3],RamDomain(1),0,0,RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_294(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env3[6]))) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,12> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(env3[6]),static_cast<RamDomain>(RamDomain(4))}};
rel_37_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_37_IntegerOverflow_op_ctxt));
freqs[151]++;
}
freqs[152]++;
}
}
freqs[153]++;
}
}
freqs[154]++;
}
}
freqs[155]++;
}
freqs[156]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;IntegerOverflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [134:7-134:22];savetime;)_",iter, [&](){return rel_37_IntegerOverflow->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
}();
/* END STRATUM 34 */
/* BEGIN STRATUM 35 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;IntegerUnderflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [190:7-190:23];)_",iter, [&](){return rel_38_IntegerUnderflow->size();});
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,"Token") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,amount,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [191:1-214:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerUnderflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [191:1-214:19];IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;)_",iter, [&](){return rel_38_IntegerUnderflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_32_transfer->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_38_IntegerUnderflow_op_ctxt,rel_38_IntegerUnderflow->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(14),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,env1[3]}};
auto range = rel_32_transfer->equalRange_18(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(RamDomain(5))}};
rel_38_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_38_IntegerUnderflow_op_ctxt));
freqs[157]++;
}
freqs[158]++;
}
freqs[159]++;
}
}
freqs[160]++;
}
}
freqs[161]++;
}
freqs[162]++;
}
}
();}
}
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,"Ether") :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   call(_,hash,"CALL",from,to,"",amount,_,1),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [191:1-214:19])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;IntegerUnderflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [191:1-214:19];IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;)_",iter, [&](){return rel_38_IntegerUnderflow->size();});
if(!(rel_3_def->empty()) && !(rel_36_arithmetic->empty()) && !(rel_26_storage->empty()) && !(rel_9_data_flow->empty()) && !(rel_14_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_26_storage_op_ctxt,rel_26_storage->createContext());
CREATE_OP_CONTEXT(rel_38_IntegerUnderflow_op_ctxt,rel_38_IntegerUnderflow->createContext());
CREATE_OP_CONTEXT(rel_36_arithmetic_op_ctxt,rel_36_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(14),0,0,0,0}};
auto range = rel_36_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_36_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_26_storage->equalRange_2(key,READ_OP_CONTEXT(rel_26_storage_op_ctxt));
for(const auto& env2 : range) {
if( (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,9> key{{0,env2[3],RamDomain(1),0,0,RamDomain(6),0,0,RamDomain(1)}};
auto range = rel_14_call->equalRange_294(key,READ_OP_CONTEXT(rel_14_call_op_ctxt));
for(const auto& env3 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env3[6]))) {
const Tuple<RamDomain,8> key{{env2[3],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(env3[6]),static_cast<RamDomain>(RamDomain(4))}};
rel_38_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_38_IntegerUnderflow_op_ctxt));
freqs[163]++;
}
freqs[164]++;
}
}
freqs[165]++;
}
}
freqs[166]++;
}
}
freqs[167]++;
}
freqs[168]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;IntegerUnderflow;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [190:7-190:23];savetime;)_",iter, [&](){return rel_38_IntegerUnderflow->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_36_arithmetic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_26_storage->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_32_transfer->purge();
}();
/* END STRATUM 35 */
/* BEGIN STRATUM 36 */
[&]() {
{
	Logger logger(R"_(@t-relation-loadtime;selfdestruct;edb.dl [11:7-11:19];loadtime;)_",iter, [&](){return rel_39_selfdestruct->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_39_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}
ProfileEventSingleton::instance().makeQuantityEvent( R"(@n-nonrecursive-relation;selfdestruct;edb.dl [11:7-11:19];)",rel_39_selfdestruct->size(),iter);}();
/* END STRATUM 36 */
/* BEGIN STRATUM 37 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;ParityWalletHack2;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [268:7-268:24];)_",iter, [&](){return rel_40_ParityWalletHack2->size();});
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
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [269:1-279:65])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;ParityWalletHack2;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [269:1-279:65];ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;)_",iter, [&](){return rel_40_ParityWalletHack2->size();});
if(!(rel_5_transaction->empty()) && !(rel_1_block->empty()) && !(rel_39_selfdestruct->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_39_selfdestruct_op_ctxt,rel_39_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_40_ParityWalletHack2_op_ctxt,rel_40_ParityWalletHack2->createContext());
CREATE_OP_CONTEXT(rel_14_call_op_ctxt,rel_14_call->createContext());
const Tuple<RamDomain,8> key{{0,0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_64(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env0 : range) {
if( !((reads[7]++,!rel_14_call->equalRange_262(Tuple<RamDomain,9>{{0,env0[0],RamDomain(8),0,0,0,0,0,RamDomain(1)}},READ_OP_CONTEXT(rel_14_call_op_ctxt)).empty())) && ((symTable.lookup(substr_wrapper(symTable.resolve(env0[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(16)))) {
const Tuple<RamDomain,4> key{{env0[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,8> key{{0,env0[1],env0[2],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_70(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
if( !((reads[7]++,!rel_14_call->equalRange_262(Tuple<RamDomain,9>{{0,env2[0],RamDomain(8),0,0,0,0,0,RamDomain(1)}},READ_OP_CONTEXT(rel_14_call_op_ctxt)).empty())) && ((symTable.lookup(substr_wrapper(symTable.resolve(env2[3]),(RamDomain(0)),(RamDomain(8))))) == (RamDomain(18))) && ((env0[7]) <= (env2[7]))) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,6> key{{0,env2[0],0,0,0,0}};
auto range = rel_39_selfdestruct->equalRange_2(key,READ_OP_CONTEXT(rel_39_selfdestruct_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,8> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env4[2]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env4[4]),static_cast<RamDomain>(env4[5])}};
rel_40_ParityWalletHack2->insert(tuple,READ_OP_CONTEXT(rel_40_ParityWalletHack2_op_ctxt));
freqs[169]++;
}
freqs[170]++;
}
}
freqs[171]++;
}
freqs[172]++;
}
}
freqs[173]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;ParityWalletHack2;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [268:7-268:24];savetime;)_",iter, [&](){return rel_40_ParityWalletHack2->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_14_call->purge();
}();
/* END STRATUM 37 */
/* BEGIN STRATUM 38 */
[&]() {
{
	Logger logger(R"_(@t-nonrecursive-relation;UncheckedSuicide;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [229:7-229:23];)_",iter, [&](){return rel_41_UncheckedSuicide->size();});
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- 
   def(step1,"CALLDATALOAD"),
   selfdestruct(step2,hash,caller,contract,destination,amount),
   data_flow(step1,step2),
   transaction(hash,_,_,_,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [230:1-236:33])_");
{
	Logger logger(R"_(@t-nonrecursive-rule;UncheckedSuicide;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [230:1-236:33];UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;)_",iter, [&](){return rel_41_UncheckedSuicide->size();});
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_9_data_flow->empty()) && !(rel_39_selfdestruct->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_9_data_flow_op_ctxt,rel_9_data_flow->createContext());
CREATE_OP_CONTEXT(rel_39_selfdestruct_op_ctxt,rel_39_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_41_UncheckedSuicide_op_ctxt,rel_41_UncheckedSuicide->createContext());
CREATE_OP_CONTEXT(rel_13_caller_check_op_ctxt,rel_13_caller_check->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_39_selfdestruct) {
if( !((reads[2]++,!rel_13_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env1[1]}},READ_OP_CONTEXT(rel_13_caller_check_op_ctxt)).empty())) && (reads[1]++,rel_9_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_9_data_flow_op_ctxt)))) {
const Tuple<RamDomain,8> key{{env1[1],0,0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_65(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[7],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5])}};
rel_41_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_41_UncheckedSuicide_op_ctxt));
freqs[174]++;
}
freqs[175]++;
}
}
freqs[176]++;
}
freqs[177]++;
}
}
();}
}
}
{
	Logger logger(R"_(@t-relation-savetime;UncheckedSuicide;/Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [229:7-229:23];savetime;)_",iter, [&](){return rel_41_UncheckedSuicide->size();});
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_41_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}
if (!isHintsProfilingEnabled()&& performIO) rel_3_def->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_39_selfdestruct->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_block->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_5_transaction->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_9_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_13_caller_check->purge();
}();
/* END STRATUM 38 */
}
ProfileEventSingleton::instance().stopTimer();
dumpFreqs();

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_block:\n";
rel_1_block->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_condition:\n";
rel_2_condition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_def:\n";
rel_3_def->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_throw:\n";
rel_4_throw->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_transaction:\n";
rel_5_transaction->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_BlockStuffing:\n";
rel_6_BlockStuffing->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_use:\n";
rel_7_use->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_BalanceInvariant:\n";
rel_8_BalanceInvariant->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_data_flow:\n";
rel_9_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_delta_data_flow:\n";
rel_10_delta_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_new_data_flow:\n";
rel_11_new_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_used_in_condition:\n";
rel_12_used_in_condition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_caller_check:\n";
rel_13_caller_check->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_call:\n";
rel_14_call->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_BlockStateDependence:\n";
rel_15_BlockStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_CallStackDepth:\n";
rel_16_CallStackDepth->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_CreateBasedReentrancy:\n";
rel_17_CreateBasedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_DelegatedReentrancy:\n";
rel_18_DelegatedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_DoSWithUnexpectedThrow:\n";
rel_19_DoSWithUnexpectedThrow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_ParityWalletHack1:\n";
rel_20_ParityWalletHack1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_Reentrancy:\n";
rel_21_Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_TimestampDependence:\n";
rel_22_TimestampDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_TransactionStateDependence:\n";
rel_23_TransactionStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_UncheckedDelegatecall:\n";
rel_24_UncheckedDelegatecall->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_UnhandledException:\n";
rel_25_UnhandledException->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_storage:\n";
rel_26_storage->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_CrossFunctionReentrancy:\n";
rel_27_CrossFunctionReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_TransactionOrderDependency:\n";
rel_28_TransactionOrderDependency->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_error:\n";
rel_29_error->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_30_DoSWithBlockGasLimit:\n";
rel_30_DoSWithBlockGasLimit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_31_InsufficientGas:\n";
rel_31_InsufficientGas->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_32_transfer:\n";
rel_32_transfer->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_ERC777Reentrancy:\n";
rel_33_ERC777Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_ShortAddress:\n";
rel_34_ShortAddress->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_UncheckedSignature:\n";
rel_35_UncheckedSignature->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_arithmetic:\n";
rel_36_arithmetic->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_37_IntegerOverflow:\n";
rel_37_IntegerOverflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_38_IntegerUnderflow:\n";
rel_38_IntegerUnderflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_39_selfdestruct:\n";
rel_39_selfdestruct->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_40_ParityWalletHack2:\n";
rel_40_ParityWalletHack2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_41_UncheckedSuicide:\n";
rel_41_UncheckedSuicide->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tfrom\tto"},{"filename","./BlockStuffing.csv"},{"name","BlockStuffing"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_BlockStuffing);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep"},{"filename","./BalanceInvariant.csv"},{"name","BalanceInvariant"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./DelegatedReentrancy.csv"},{"name","DelegatedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp\tblock\tcontract"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tgas_limit\tcaller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./InsufficientGas.csv"},{"name","InsufficientGas"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tamount\tasset"},{"filename","./ERC777Reentrancy.csv"},{"name","ERC777Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfrom\tto\tamount"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tinput_data\tfrom\tto\tamount"},{"filename","./UncheckedSignature.csv"},{"name","UncheckedSignature"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount\tasset"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_41_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
private:
void dumpFreqs() {
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BalanceInvariant;0;BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;block(block,_,_,timestamp);BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;5;)_", freqs[3],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BalanceInvariant;0;BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;condition(step2,hash);BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;1;)_", freqs[6],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BalanceInvariant;0;BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;def(step1,\"BALANCE\");BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;0;)_", freqs[7],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BalanceInvariant;0;BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;throw(step3,hash,_,_,_);BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;3;)_", freqs[5],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BalanceInvariant;0;BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;transaction(hash,_,_,_,_,_,1,block);BalanceInvariant(hash,timestamp,step2) :- \n   def(step1,\"BALANCE\"),\n   condition(step2,hash),\n   use(step2,step1),\n   throw(step3,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step2 < step3.;4;)_", freqs[4],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[15],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[17],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step1,\"BLOCKHASH\");BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[19],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[16],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"BLOCKHASH\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[18],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[30],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[32],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step1,\"DIFFICULTY\");BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[34],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[31],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"DIFFICULTY\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[33],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[35],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[37],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step1,\"GASLIMIT\");BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[39],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[36],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"GASLIMIT\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[38],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[25],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[27],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step1,\"NUMBER\");BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[29],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[26],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"NUMBER\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[28],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[20],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(_,hash,\"CALL\",caller,callee,_,amount,_,1);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[22],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step2,\"COINBASE\");BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[24],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[21],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStateDependence;0;BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step2,\"COINBASE\"),\n   used_in_condition(step1,hash),\n   call(_,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[23],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStuffing;0;BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;block(block,_,_,timestamp);BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;2;)_", freqs[0],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStuffing;0;BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block);BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;0;)_", freqs[2],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;BlockStuffing;0;BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block);BlockStuffing(hash1,timestamp,from,to) :- \n   transaction(hash1,from,to,input_data,gas_used,gas_limit,0,block),\n   transaction(hash2,_,to,input_data,gas_used,gas_limit,0,block),\n   block(block,_,_,timestamp),\n   hash1 != hash2.;1;)_", freqs[1],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CallStackDepth;0;CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;block(block,_,_,timestamp);CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;2;)_", freqs[40],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CallStackDepth;0;CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;call(step,hash,\"CALL\",caller,callee,_,amount,depth,_);CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;0;)_", freqs[42],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CallStackDepth;0;CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;transaction(hash,_,_,_,_,_,_,block);CallStackDepth(hash,timestamp,step,caller,callee,amount) :- \n   call(step,hash,\"CALL\",caller,callee,_,amount,depth,_),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   depth > 1024.;1;)_", freqs[41],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;block(block,_,_,timestamp);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;5;)_", freqs[43],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;0;)_", freqs[48],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;1;)_", freqs[47],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;2;)_", freqs[46],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;3;)_", freqs[45],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CreateBasedReentrancy;0;CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);CreateBasedReentrancy(hash,timestamp,caller,callee2,depth3,amount) :- \n   call(step1,hash,\"CALL\",caller,callee1,_,amount,depth1,1),\n   call(step2,hash,\"CREATE\",callee1,_,input_data,_,depth2,1),\n   call(step3,hash,\"CREATE\",callee1,callee2,input_data,_,depth3,1),\n   call(step4,hash,\"CALL\",callee2,caller,_,amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth1 < depth4,\n   \"0\" not_match amount.;4;)_", freqs[44],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;block(block,_,_,timestamp);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;6;)_", freqs[94],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;0;)_", freqs[99],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;1;)_", freqs[98],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;2;)_", freqs[97],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;storage(step4,\"SSTORE\",block,hash,_,contract,index);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;3;)_", freqs[96],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;CrossFunctionReentrancy;0;CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;storage(step5,\"SSTORE\",block,hash,_,contract,index);CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",callee,caller,\"\",amount,depth2,1),\n   call(step3,hash,\"CALL\",caller,callee,input_data2,\"0\",depth3,1),\n   storage(step4,\"SSTORE\",block,hash,_,contract,index),\n   transaction(hash,_,_,_,_,_,1,block),\n   storage(step5,\"SSTORE\",block,hash,_,contract,index),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   step4 < step5,\n   depth1 < depth2,\n   depth2 < depth3,\n   substr(input_data1,0,8) != substr(input_data2,0,8),\n   \"0\" not_match amount.;5;)_", freqs[95],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;block(block,_,_,timestamp);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;5;)_", freqs[55],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;0;)_", freqs[60],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;1;)_", freqs[59],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;2;)_", freqs[58],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;3;)_", freqs[57],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"CALLCODE\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;4;)_", freqs[56],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;block(block,_,_,timestamp);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;5;)_", freqs[49],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;0;)_", freqs[54],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;1;)_", freqs[53],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;2;)_", freqs[52],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;3;)_", freqs[51],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DelegatedReentrancy;0;DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);DelegatedReentrancy(hash,timestamp,caller,callee2,depth4,amount) :- \n   call(step1,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth1,1),\n   call(step2,hash,\"CALL\",caller,callee2,\"\",amount,depth2,1),\n   call(step3,hash,\"DELEGATECALL\",caller,callee1,input_data,\"0\",depth3,1),\n   call(step4,hash,\"CALL\",caller,callee2,\"\",amount,depth4,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   step2 < step3,\n   step3 < step4,\n   depth1 < depth2,\n   depth2 < depth3,\n   depth3 < depth4,\n   \"0\" not_match amount.;4;)_", freqs[50],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithBlockGasLimit;0;DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;block(block,gas_limit,gas_limit,timestamp);DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;0;)_", freqs[105],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithBlockGasLimit;0;DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;call(step,hash,\"CALL\",caller,callee,_,amount,_,1);DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;3;)_", freqs[103],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithBlockGasLimit;0;DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,_,block);DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- \n   block(block,gas_limit,gas_limit,timestamp),\n   transaction(hash,_,_,_,_,_,_,block),\n   error(hash,\"out of gas\"),\n   call(step,hash,\"CALL\",caller,callee,_,amount,_,1),\n   \"0\" not_match amount.;1;)_", freqs[104],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithUnexpectedThrow;0;DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;block(block,_,_,timestamp);DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;4;)_", freqs[61],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithUnexpectedThrow;0;DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0);DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;0;)_", freqs[65],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithUnexpectedThrow;0;DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;throw(step2,hash,_,_,depth2);DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;1;)_", freqs[64],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithUnexpectedThrow;0;DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;throw(step3,hash,_,_,depth3);DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;2;)_", freqs[63],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;DoSWithUnexpectedThrow;0;DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;transaction(hash,_,_,_,_,_,_,block);DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,depth3,0),\n   throw(step2,hash,_,_,depth2),\n   throw(step3,hash,_,_,depth3),\n   transaction(hash,_,_,_,_,_,_,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   (depth3+1) = depth2,\n   step2 < step3.;3;)_", freqs[62],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;block(block,_,_,timestamp);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;4;)_", freqs[110],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;0;)_", freqs[114],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;1;)_", freqs[113],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;call(step3,hash,\"CALL\",callee,from,_,amount,_,1);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;2;)_", freqs[112],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;transaction(hash,from,_,_,_,_,1,block);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Ether\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   call(step3,hash,\"CALL\",callee,from,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step2 < step3.;3;)_", freqs[111],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;block(block,_,_,timestamp);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;5;)_", freqs[115],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;0;)_", freqs[120],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;1;)_", freqs[119],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;transaction(hash,_,_,_,_,_,1,block);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;4;)_", freqs[116],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;transfer(step3,hash,callee,to,_);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;2;)_", freqs[118],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ERC777Reentrancy;0;ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;transfer(step4,hash,to,callee,amount);ERC777Reentrancy(hash,timestamp,caller,callee,amount,\"Token\") :- \n   call(step1,hash,\"CALL\",caller,callee,input_data1,_,_,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data2,_,_,1),\n   transfer(step3,hash,callee,to,_),\n   transfer(step4,hash,to,callee,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   substr(input_data1,0,8) = \"75ab9782\",\n   substr(input_data2,0,8) = \"75ab9782\",\n   step1 < step2,\n   \"0\" not_match amount,\n   step3 < step4.;3;)_", freqs[117],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;InsufficientGas;0;InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;block(block,_,_,timestamp);InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;6;)_", freqs[106],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;InsufficientGas;0;InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;call(step2,hash,\"CALL\",caller,callee,_,amount,_,0);InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;1;)_", freqs[108],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;InsufficientGas;0;InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;def(step1,\"CALLDATALOAD\");InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;0;)_", freqs[109],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;InsufficientGas;0;InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;transaction(hash,_,_,_,_,_,1,block);InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,0),\n   data_flow(step1,step2),\n   error(hash,\"out of gas\"),\n   storage(_,\"SSTORE\",_,hash,_,_,_),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp).;5;)_", freqs[107],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;1;)_", freqs[137],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;block(block,_,_,timestamp);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;7;)_", freqs[133],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;def(step1,\"CALLDATALOAD\");IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;0;)_", freqs[138],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;3;)_", freqs[136],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transaction(hash,_,_,_,_,_,1,block);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;6;)_", freqs[134],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transfer(_,hash,from,to,amount);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;5;)_", freqs[135],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;1;)_", freqs[143],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;block(block,_,_,timestamp);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;7;)_", freqs[139],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;call(_,hash,\"CALL\",from,to,\"\",amount,_,1);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;5;)_", freqs[141],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;def(step1,\"CALLDATALOAD\");IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;0;)_", freqs[144],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;3;)_", freqs[142],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);IntegerOverflow(hash,timestamp,step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"ADD\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;6;)_", freqs[140],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;1;)_", freqs[149],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;block(block,_,_,timestamp);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;7;)_", freqs[145],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;def(step1,\"CALLDATALOAD\");IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;0;)_", freqs[150],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;3;)_", freqs[148],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transaction(hash,_,_,_,_,_,1,block);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;6;)_", freqs[146],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transfer(_,hash,from,to,amount);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;5;)_", freqs[147],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;1;)_", freqs[155],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;block(block,_,_,timestamp);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;7;)_", freqs[151],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;call(_,hash,\"CALL\",from,to,\"\",amount,_,1);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;5;)_", freqs[153],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;def(step1,\"CALLDATALOAD\");IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;0;)_", freqs[156],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;3;)_", freqs[154],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerOverflow;0;IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);IntegerOverflow(hash,timestamp,step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"MUL\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;6;)_", freqs[152],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result);IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;1;)_", freqs[161],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;block(block,_,_,timestamp);IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;7;)_", freqs[157],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;def(step1,\"CALLDATALOAD\");IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;0;)_", freqs[162],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;3;)_", freqs[160],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transaction(hash,_,_,_,_,_,1,block);IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;6;)_", freqs[158],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;transfer(_,hash,from,to,amount);IntegerUnderflow(hash,timestamp,step2,first_operand,amount,arithmetic_result,evm_result,from,to,amount,\"Token\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,amount,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result.;5;)_", freqs[159],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result);IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;1;)_", freqs[167],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;block(block,_,_,timestamp);IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;7;)_", freqs[163],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;call(_,hash,\"CALL\",from,to,\"\",amount,_,1);IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;5;)_", freqs[165],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;def(step1,\"CALLDATALOAD\");IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;0;)_", freqs[168],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;storage(step3,\"SSTORE\",_,hash,_,_,_);IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;3;)_", freqs[166],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;IntegerUnderflow;0;IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount,\"Ether\") :- \n   def(step1,\"CALLDATALOAD\"),\n   arithmetic(step2,\"SUB\",first_operand,second_operand,arithmetic_result,evm_result),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   data_flow(step2,step3),\n   call(_,hash,\"CALL\",from,to,\"\",amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   arithmetic_result != evm_result,\n   \"0\" not_match amount.;6;)_", freqs[164],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;block(block1,_,_,timestamp1);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;2;)_", freqs[70],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;block(block2,_,_,timestamp2);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;5;)_", freqs[67],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;0;)_", freqs[72],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;call(_,hash2,\"CALL\",caller,callee,_,amount,_,1);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;6;)_", freqs[66],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;3;)_", freqs[69],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;transaction(hash1,from,to,input_data1,_,_,1,block1);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;1;)_", freqs[71],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack1;0;ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;transaction(hash2,from,to,input_data2,_,_,1,block2);ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,caller,callee,amount) :- \n   call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   call(_,hash2,\"CALL\",caller,callee,_,amount,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"b61d27f6\",\n   block1 <= block2,\n   amount not_match \"0\".;4;)_", freqs[68],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack2;0;ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;block(block1,_,_,timestamp1);ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;1;)_", freqs[172],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack2;0;ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;block(block2,_,_,timestamp2);ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;3;)_", freqs[170],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack2;0;ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;selfdestruct(_,hash2,caller,contract,destination,amount);ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;4;)_", freqs[169],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack2;0;ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;transaction(hash1,from,to,input_data1,_,_,1,block1);ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;0;)_", freqs[173],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ParityWalletHack2;0;ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;transaction(hash2,from,to,input_data2,_,_,1,block2);ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,caller,contract,destination,amount) :- \n   transaction(hash1,from,to,input_data1,_,_,1,block1),\n   block(block1,_,_,timestamp1),\n   transaction(hash2,from,to,input_data2,_,_,1,block2),\n   block(block2,_,_,timestamp2),\n   selfdestruct(_,hash2,caller,contract,destination,amount),\n   !call(_,hash1,\"DELEGATECALL\",_,_,_,_,_,1),\n   !call(_,hash2,\"DELEGATECALL\",_,_,_,_,_,1),\n   substr(input_data1,0,8) = \"e46dcfeb\",\n   substr(input_data2,0,8) = \"cbf0b0c0\",\n   block1 <= block2.;2;)_", freqs[171],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;Reentrancy;0;Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;block(block,_,_,timestamp);Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;3;)_", freqs[73],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;Reentrancy;0;Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1);Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;0;)_", freqs[76],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;Reentrancy;0;Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1);Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;1;)_", freqs[75],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;Reentrancy;0;Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);Reentrancy(hash,timestamp,step2,caller,callee,depth2,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,input_data,_,depth1,1),\n   call(step2,hash,\"CALL\",caller,callee,input_data,amount,depth2,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   step1 < step2,\n   depth1 < depth2,\n   \"0\" not_match amount.;2;)_", freqs[74],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;block(block,_,_,timestamp);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;2;)_", freqs[124],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;transaction(hash,_,_,input_data,_,_,1,block);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;0;)_", freqs[126],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;transfer(step6,hash,from,to,amount);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"23b872dd\",\n   (strlen(input_data)/2) < 100.;1;)_", freqs[125],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;block(block,_,_,timestamp);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;2;)_", freqs[121],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;transaction(hash,_,_,input_data,_,_,1,block);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;0;)_", freqs[123],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;ShortAddress;0;ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;transfer(step6,hash,from,to,amount);ShortAddress(hash,timestamp,step6,from,to,amount) :- \n   transaction(hash,_,_,input_data,_,_,1,block),\n   transfer(step6,hash,from,to,amount),\n   block(block,_,_,timestamp),\n   substr(input_data,0,8) = \"a9059cbb\",\n   (strlen(input_data)/2) < 68.;1;)_", freqs[122],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TimestampDependence;0;TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;block(block,_,_,timestamp);TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;4;)_", freqs[77],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TimestampDependence;0;TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;2;)_", freqs[79],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TimestampDependence;0;TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;def(step1,\"TIMESTAMP\");TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;0;)_", freqs[81],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TimestampDependence;0;TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;transaction(hash,_,_,_,_,_,1,block);TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;3;)_", freqs[78],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TimestampDependence;0;TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;used_in_condition(step1,hash);TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"TIMESTAMP\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2.;1;)_", freqs[80],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionOrderDependency;0;TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;block(block,_,_,timestamp);TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;2;)_", freqs[100],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionOrderDependency;0;TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;storage(step1,\"SSTORE\",block,hash1,caller1,contract,index);TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;0;)_", freqs[102],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionOrderDependency;0;TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;storage(step2,\"SLOAD\",block,hash2,caller2,contract,index);TransactionOrderDependency(hash1,hash2,timestamp,block,contract) :- \n   storage(step1,\"SSTORE\",block,hash1,caller1,contract,index),\n   storage(step2,\"SLOAD\",block,hash2,caller2,contract,index),\n   block(block,_,_,timestamp),\n   hash1 != hash2,\n   step1 < step2,\n   caller1 != caller2.;1;)_", freqs[101],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionStateDependence;0;TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;block(block,_,_,timestamp);TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;4;)_", freqs[82],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionStateDependence;0;TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;call(step2,hash,\"CALL\",caller,callee,_,amount,_,1);TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;2;)_", freqs[84],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionStateDependence;0;TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;def(step1,\"ORIGIN\");TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;0;)_", freqs[86],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionStateDependence;0;TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;transaction(hash,from,_,_,_,_,1,block);TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;3;)_", freqs[83],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;TransactionStateDependence;0;TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;used_in_condition(step1,hash);TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- \n   def(step1,\"ORIGIN\"),\n   used_in_condition(step1,hash),\n   call(step2,hash,\"CALL\",caller,callee,_,amount,_,1),\n   transaction(hash,from,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   \"0\" not_match amount,\n   step1 < step2,\n   callee != from.;1;)_", freqs[85],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedDelegatecall;0;UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;block(block,_,_,timestamp);UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;4;)_", freqs[87],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedDelegatecall;0;UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1);UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;1;)_", freqs[89],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedDelegatecall;0;UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;def(step1,\"CALLDATALOAD\");UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;0;)_", freqs[90],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedDelegatecall;0;UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;transaction(hash,_,_,input_data,_,_,1,block);UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- \n   def(step1,\"CALLDATALOAD\"),\n   call(step2,hash,\"DELEGATECALL\",caller,callee,_,_,_,1),\n   data_flow(step1,step2),\n   transaction(hash,_,_,input_data,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash),\n   substr(callee,2,strlen(callee)) contains input_data.;3;)_", freqs[88],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;block(block,_,_,timestamp);UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;6;)_", freqs[127],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1);UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;1;)_", freqs[131],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;def(step1,\"SHA3\");UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;0;)_", freqs[132],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;storage(step3,\"SSTORE\",_,hash,_,_,_);UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;3;)_", freqs[130],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;transaction(hash,_,_,_,_,_,1,block);UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;5;)_", freqs[128],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSignature;0;UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;transfer(_,hash,from,to,amount);UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- \n   def(step1,\"SHA3\"),\n   call(step2,hash,\"CALL\",_,\"0x0000000000000000000000000000000000000001\",input_data,_,_,1),\n   data_flow(step1,step2),\n   storage(step3,\"SSTORE\",_,hash,_,_,_),\n   transfer(_,hash,from,to,amount),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !data_flow(step1,step3).;4;)_", freqs[129],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSuicide;0;UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;block(block,_,_,timestamp);UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;4;)_", freqs[174],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSuicide;0;UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;def(step1,\"CALLDATALOAD\");UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;0;)_", freqs[177],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSuicide;0;UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;selfdestruct(step2,hash,caller,contract,destination,amount);UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;1;)_", freqs[176],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UncheckedSuicide;0;UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;transaction(hash,_,_,_,_,_,1,block);UncheckedSuicide(hash,timestamp,step2,caller,contract,destination,amount) :- \n   def(step1,\"CALLDATALOAD\"),\n   selfdestruct(step2,hash,caller,contract,destination,amount),\n   data_flow(step1,step2),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !caller_check(_,hash).;3;)_", freqs[175],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UnhandledException;0;UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;block(block,_,_,timestamp);UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;2;)_", freqs[91],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UnhandledException;0;UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;call(step1,hash,\"CALL\",caller,callee,_,amount,_,0);UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;0;)_", freqs[93],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;UnhandledException;0;UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;transaction(hash,_,_,_,_,_,1,block);UnhandledException(hash,timestamp,step1,caller,callee,amount) :- \n   call(step1,hash,\"CALL\",caller,callee,_,amount,_,0),\n   transaction(hash,_,_,_,_,_,1,block),\n   block(block,_,_,timestamp),\n   !used_in_condition(step1,hash),\n   \"0\" not_match amount.;1;)_", freqs[92],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;caller_check;0;caller_check(step1,hash) :- \n   def(step1,\"CALLER\"),\n   used_in_condition(step1,hash).;def(step1,\"CALLER\");caller_check(step1,hash) :- \n   def(step1,\"CALLER\"),\n   used_in_condition(step1,hash).;0;)_", freqs[14],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;caller_check;0;caller_check(step1,hash) :- \n   def(step1,\"CALLER\"),\n   used_in_condition(step1,hash).;used_in_condition(step1,hash);caller_check(step1,hash) :- \n   def(step1,\"CALLER\"),\n   used_in_condition(step1,hash).;1;)_", freqs[13],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;data_flow;0;@new_data_flow(x,y) :- \n   use(y,z),\n   @delta_data_flow(x,z),\n   !data_flow(x,y).;@delta_data_flow(x,z);data_flow(x,y) :- \n   use(y,z),\n   data_flow(x,z).;1;)_", freqs[9],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;data_flow;0;@new_data_flow(x,y) :- \n   use(y,z),\n   @delta_data_flow(x,z),\n   !data_flow(x,y).;use(y,z);data_flow(x,y) :- \n   use(y,z),\n   data_flow(x,z).;0;)_", freqs[10],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;data_flow;0;data_flow(x,y) :- \n   use(y,x).;use(y,x);data_flow(x,y) :- \n   use(y,x).;0;)_", freqs[8],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;used_in_condition;0;used_in_condition(step1,hash) :- \n   condition(step2,hash),\n   data_flow(step1,step2).;condition(step2,hash);used_in_condition(step1,hash) :- \n   condition(step2,hash),\n   data_flow(step1,step2).;0;)_", freqs[12],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@frequency-atom;used_in_condition;0;used_in_condition(step1,hash) :- \n   condition(step2,hash),\n   data_flow(step1,step2).;data_flow(step1,step2);used_in_condition(step1,hash) :- \n   condition(step2,hash),\n   data_flow(step1,step2).;1;)_", freqs[11],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;call)_", reads[7],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;caller_check)_", reads[2],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;data_flow)_", reads[1],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;error)_", reads[5],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;storage)_", reads[6],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;transaction)_", reads[4],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;use)_", reads[0],0);
	ProfileEventSingleton::instance().makeQuantityEvent(R"_(@relation-reads;used_in_condition)_", reads[3],0);
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./block.facts"},{"name","block"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_1_block);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./condition.facts"},{"name","condition"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_2_condition);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_3_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_4_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_7_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_14_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_26_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_29_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_36_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_39_selfdestruct);
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
ioDirectives.setRelationName("rel_2_condition");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_2_condition);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_def");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_3_def);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_throw");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_4_throw);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_transaction");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0,0,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_use");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_use);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_14_call");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_call);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_26_storage");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_26_storage);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_29_error");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_error);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_32_transfer");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_36_arithmetic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_36_arithmetic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_39_selfdestruct");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_39_selfdestruct);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_BlockStuffing");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_BlockStuffing);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_BalanceInvariant");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_8_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_15_BlockStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_CallStackDepth");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_17_CreateBasedReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_18_DelegatedReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_19_DoSWithUnexpectedThrow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_20_ParityWalletHack1");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_21_Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_22_TimestampDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_23_TransactionStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_24_UncheckedDelegatecall");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_25_UnhandledException");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_27_CrossFunctionReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_28_TransactionOrderDependency");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_30_DoSWithBlockGasLimit");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_31_InsufficientGas");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_33_ERC777Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_ERC777Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_34_ShortAddress");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_35_UncheckedSignature");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_37_IntegerOverflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_38_IntegerUnderflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_40_ParityWalletHack2");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_41_UncheckedSuicide");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_41_UncheckedSuicide);
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
true,
R"(profile.log)",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_analyzer obj(opt.getProfileName());
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
souffle::ProfileEventSingleton::instance().makeConfigRecord("", opt.getSourceFileName());
souffle::ProfileEventSingleton::instance().makeConfigRecord("fact-dir", opt.getInputFileDir());
souffle::ProfileEventSingleton::instance().makeConfigRecord("jobs", std::to_string(opt.getNumJobs()));
souffle::ProfileEventSingleton::instance().makeConfigRecord("output-dir", opt.getOutputFileDir());
souffle::ProfileEventSingleton::instance().makeConfigRecord("version", "1.7.1");
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif


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
struct t_btree_6__0_4_1_2_3_5__5_0_1_2_3_4__4_0_1_2_3_5__1__16__17__32__63 {
using t_tuple = Tuple<RamDomain, 6>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,4,1,2,3,5>>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<t_tuple, index_utils::comparator<5,0,1,2,3,4>>;
t_ind_1 ind_1;
using t_ind_2 = btree_set<t_tuple, index_utils::comparator<4,0,1,2,3,5>>;
t_ind_2 ind_2;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
ind_1.insert(t, h.hints_1);
ind_2.insert(t, h.hints_2);
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
void insertAll(t_btree_6__0_4_1_2_3_5__5_0_1_2_3_4__4_0_1_2_3_5__1__16__17__32__63& other) {
ind_0.insertAll(other.ind_0);
ind_1.insertAll(other.ind_1);
ind_2.insertAll(other.ind_2);
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
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_2::iterator> equalRange_16(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
return make_range(ind_2.lower_bound(low, h.hints_2), ind_2.upper_bound(high, h.hints_2));
}
range<t_ind_2::iterator> equalRange_16(const t_tuple& t) const {
context h;
return equalRange_16(t, h);
}
range<t_ind_0::iterator> equalRange_17(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_17(const t_tuple& t) const {
context h;
return equalRange_17(t, h);
}
range<t_ind_1::iterator> equalRange_32(const t_tuple& t, context& h) const {
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
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_32(const t_tuple& t) const {
context h;
return equalRange_32(t, h);
}
range<t_ind_2::iterator> equalRange_63(const t_tuple& t, context& h) const {
auto pos = ind_2.find(t, h.hints_2);
auto fin = ind_2.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_2::iterator> equalRange_63(const t_tuple& t) const {
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
ind_1.clear();
ind_2.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [0,4,1,2,3,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [5,0,1,2,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [4,0,1,2,3,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
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
struct t_btree_9__1_2_3_5_6_8_4__2_8_1_3_4_7__2_4_8_1_3_6_0_5_7__4__260__262__270__276__286__350__366__382__414__511 {
using t_tuple = Tuple<RamDomain, 9>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,3,5,6,8,4>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,8,1,3,4,7>>>;
t_ind_1 ind_1;
using t_ind_2 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<2,4,8,1,3,6,0,5,7>>>;
t_ind_2 ind_2;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator_2 = IterDerefWrapper<typename t_ind_2::iterator>;
using iterator = iterator_2;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
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
ind_2.insert(masterCopy, h.hints_2);
}
ind_0.insert(masterCopy, h.hints_0);
ind_1.insert(masterCopy, h.hints_1);
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
return ind_2.contains(&t, h.hints_2);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_2.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_2.find(&t, h.hints_2);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_2.begin(),ind_2.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_2.begin(),ind_2.end());
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
range<iterator_2> equalRange_276(const t_tuple& t, context& h) const {
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
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_276(const t_tuple& t) const {
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
range<iterator_2> equalRange_350(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_350(const t_tuple& t) const {
context h; return equalRange_350(t, h);
}
range<iterator_0> equalRange_366(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_366(const t_tuple& t) const {
context h; return equalRange_366(t, h);
}
range<iterator_0> equalRange_382(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[7] = MIN_RAM_DOMAIN;
high[7] = MAX_RAM_DOMAIN;
return range<iterator_0>(ind_0.lower_bound(&low, h.hints_0), ind_0.upper_bound(&high, h.hints_0));
}
range<iterator_0> equalRange_382(const t_tuple& t) const {
context h; return equalRange_382(t, h);
}
range<iterator_1> equalRange_414(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
low[6] = MIN_RAM_DOMAIN;
high[6] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_414(const t_tuple& t) const {
context h; return equalRange_414(t, h);
}
range<iterator_2> equalRange_511(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_2> equalRange_511(const t_tuple& t) const {
context h; return equalRange_511(t, h);
}
bool empty() const {
return ind_2.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_2.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
ind_2.clear();
dataTable.clear();
}
iterator begin() const {
return ind_2.begin();
}
iterator end() const {
return ind_2.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [1,2,3,5,6,8,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,8,1,3,4,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 9 indirect b-tree index [2,4,8,1,3,6,0,5,7]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
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
struct t_btree_7__1_4_5_6__1_3_4_5_6__1_2_5_6_0_3_4__2__10__102__114__122__127 {
using t_tuple = Tuple<RamDomain, 7>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,4,5,6>>>;
t_ind_0 ind_0;
using t_ind_1 = btree_multiset<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,3,4,5,6>>>;
t_ind_1 ind_1;
using t_ind_2 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<1,2,5,6,0,3,4>>>;
t_ind_2 ind_2;
using iterator_0 = IterDerefWrapper<typename t_ind_0::iterator>;
using iterator_1 = IterDerefWrapper<typename t_ind_1::iterator>;
using iterator_2 = IterDerefWrapper<typename t_ind_2::iterator>;
using iterator = iterator_2;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
t_ind_2::operation_hints hints_2;
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
ind_2.insert(masterCopy, h.hints_2);
}
ind_0.insert(masterCopy, h.hints_0);
ind_1.insert(masterCopy, h.hints_1);
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
return ind_2.contains(&t, h.hints_2);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_2.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_2.find(&t, h.hints_2);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_2.begin(),ind_2.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_2.begin(),ind_2.end());
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
range<iterator_1> equalRange_10(const t_tuple& t, context& h) const {
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
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_10(const t_tuple& t) const {
context h; return equalRange_10(t, h);
}
range<iterator_2> equalRange_102(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
return range<iterator_2>(ind_2.lower_bound(&low, h.hints_2), ind_2.upper_bound(&high, h.hints_2));
}
range<iterator_2> equalRange_102(const t_tuple& t) const {
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
range<iterator_1> equalRange_122(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
return range<iterator_1>(ind_1.lower_bound(&low, h.hints_1), ind_1.upper_bound(&high, h.hints_1));
}
range<iterator_1> equalRange_122(const t_tuple& t) const {
context h; return equalRange_122(t, h);
}
range<iterator_2> equalRange_127(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_2> equalRange_127(const t_tuple& t) const {
context h; return equalRange_127(t, h);
}
bool empty() const {
return ind_2.empty();
}
std::vector<range<iterator>> partition() const {
std::vector<range<iterator>> res;
for (const auto& cur : ind_2.getChunks(400)) {
    res.push_back(make_range(derefIter(cur.begin()), derefIter(cur.end())));
}
return res;
}
void purge() {
ind_0.clear();
ind_1.clear();
ind_2.clear();
dataTable.clear();
}
iterator begin() const {
return ind_2.begin();
}
iterator end() const {
return ind_2.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [1,4,5,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [1,3,4,5,6]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
const auto& stats_2 = ind_2.getHintStatistics();
o << prefix << "arity 7 indirect b-tree index [1,2,5,6,0,3,4]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_2.inserts.getHits() << "/" << stats_2.inserts.getMisses() << "/" << stats_2.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_2.contains.getHits() << "/" << stats_2.contains.getMisses() << "/" << stats_2.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_2.lower_bound.getHits() << "/" << stats_2.lower_bound.getMisses() << "/" << stats_2.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_2.upper_bound.getHits() << "/" << stats_2.upper_bound.getMisses() << "/" << stats_2.upper_bound.getAccesses() << "\n";
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
struct t_btree_5__1_0_2_3_4__2__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,2,3,4>>;
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
void insertAll(t_btree_5__1_0_2_3_4__2__31& other) {
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
o << prefix << "arity 5 direct b-tree index [1,0,2,3,4]: (hits/misses/total)\n";
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
struct t_btree_10__0_1_2_3_4_5_6_7_8_9__1023 {
using t_tuple = Tuple<RamDomain, 10>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6,7,8,9>>>;
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
RamDomain data[10];
std::copy(ramDomain, ramDomain + 10, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5,RamDomain a6,RamDomain a7,RamDomain a8,RamDomain a9) {
RamDomain data[10] = {a0,a1,a2,a3,a4,a5,a6,a7,a8,a9};
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
range<iterator_0> equalRange_1023(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_1023(const t_tuple& t) const {
context h; return equalRange_1023(t, h);
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
o << prefix << "arity 10 indirect b-tree index [0,1,2,3,4,5,6,7,8,9]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_6__1_3_0_2_4_5__10__63 {
using t_tuple = Tuple<RamDomain, 6>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,3,0,2,4,5>>;
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
void insertAll(t_btree_6__1_3_0_2_4_5__10__63& other) {
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
range<t_ind_0::iterator> equalRange_10(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[4] = MIN_RAM_DOMAIN;
high[4] = MAX_RAM_DOMAIN;
low[5] = MIN_RAM_DOMAIN;
high[5] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_10(const t_tuple& t) const {
context h;
return equalRange_10(t, h);
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
o << prefix << "arity 6 direct b-tree index [1,3,0,2,4,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_9__0_1_2_3_4_5_6_7_8__511 {
using t_tuple = Tuple<RamDomain, 9>;
Table<t_tuple> dataTable;
Lock insert_lock;
using t_ind_0 = btree_set<const t_tuple*, index_utils::deref_compare<typename index_utils::comparator<0,1,2,3,4,5,6,7,8>>>;
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
range<iterator_0> equalRange_511(const t_tuple& t, context& h) const {
auto pos = find(t, h);
auto fin = end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<iterator_0> equalRange_511(const t_tuple& t) const {
context h; return equalRange_511(t, h);
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
o << prefix << "arity 9 indirect b-tree index [0,1,2,3,4,5,6,7,8]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
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
	R"_(CALL)_",
	R"_(0)_",
	R"_(DELEGATECALL)_",
	R"_(CREATE)_",
	R"_(CALLDATALOAD)_",
	R"_(ADD)_",
	R"_(SSTORE)_",
	R"_(MUL)_",
	R"_(SUB)_",
	R"_(SLOAD)_",
	R"_(CALLDATACOPY)_",
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
	R"_(SHA3)_",
	R"_(0x0000000000000000000000000000000000000001)_",
	R"_(BALANCE)_",
};// -- Table: block
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
std::unique_ptr<t_btree_6__0_4_1_2_3_5__5_0_1_2_3_4__4_0_1_2_3_5__1__16__17__32__63> rel_5_transaction = std::make_unique<t_btree_6__0_4_1_2_3_5__5_0_1_2_3_4__4_0_1_2_3_5__1__16__17__32__63>();
souffle::RelationWrapper<4,t_btree_6__0_4_1_2_3_5__5_0_1_2_3_4__4_0_1_2_3_5__1__16__17__32__63,Tuple<RamDomain,6>,6,1> wrapper_rel_5_transaction;
// -- Table: use
std::unique_ptr<t_btree_2__0_1__3> rel_6_use = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<5,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_6_use;
// -- Table: BalanceInvariant
std::unique_ptr<t_btree_3__0_1_2__7> rel_7_BalanceInvariant = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<6,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3,1> wrapper_rel_7_BalanceInvariant;
// -- Table: data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_8_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<7,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_8_data_flow;
// -- Table: @delta_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_9_delta_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: @new_data_flow
std::unique_ptr<t_btree_2__1_0__2__3> rel_10_new_data_flow = std::make_unique<t_btree_2__1_0__2__3>();
// -- Table: used_in_condition
std::unique_ptr<t_btree_2__0_1__1__3> rel_11_used_in_condition = std::make_unique<t_btree_2__0_1__1__3>();
souffle::RelationWrapper<8,t_btree_2__0_1__1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_11_used_in_condition;
// -- Table: caller_check
std::unique_ptr<t_btree_2__1_0__2__3> rel_12_caller_check = std::make_unique<t_btree_2__1_0__2__3>();
souffle::RelationWrapper<9,t_btree_2__1_0__2__3,Tuple<RamDomain,2>,2,1> wrapper_rel_12_caller_check;
// -- Table: call
std::unique_ptr<t_btree_9__1_2_3_5_6_8_4__2_8_1_3_4_7__2_4_8_1_3_6_0_5_7__4__260__262__270__276__286__350__366__382__414__511> rel_13_call = std::make_unique<t_btree_9__1_2_3_5_6_8_4__2_8_1_3_4_7__2_4_8_1_3_6_0_5_7__4__260__262__270__276__286__350__366__382__414__511>();
souffle::RelationWrapper<10,t_btree_9__1_2_3_5_6_8_4__2_8_1_3_4_7__2_4_8_1_3_6_0_5_7__4__260__262__270__276__286__350__366__382__414__511,Tuple<RamDomain,9>,9,1> wrapper_rel_13_call;
// -- Table: BlockStateDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_BlockStateDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_14_BlockStateDependence;
// -- Table: CallStackDepth
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_CallStackDepth = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_15_CallStackDepth;
// -- Table: CreateBasedReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_CreateBasedReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_16_CreateBasedReentrancy;
// -- Table: CrossFunctionReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_17_CrossFunctionReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<14,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_17_CrossFunctionReentrancy;
// -- Table: DelegatedReentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_18_DelegatedReentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<15,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_18_DelegatedReentrancy;
// -- Table: DoSWithUnexpectedThrow
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_19_DoSWithUnexpectedThrow = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<16,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_19_DoSWithUnexpectedThrow;
// -- Table: Reentrancy
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_20_Reentrancy = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<17,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_20_Reentrancy;
// -- Table: TimestampDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_21_TimestampDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<18,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_21_TimestampDependence;
// -- Table: TransactionStateDependence
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_22_TransactionStateDependence = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<19,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_22_TransactionStateDependence;
// -- Table: UncheckedDelegatecall
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_23_UncheckedDelegatecall = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<20,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5,1> wrapper_rel_23_UncheckedDelegatecall;
// -- Table: UnhandledException
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_24_UnhandledException = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<21,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_24_UnhandledException;
// -- Table: error
std::unique_ptr<t_btree_2__0_1__3> rel_25_error = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<22,t_btree_2__0_1__3,Tuple<RamDomain,2>,2,1> wrapper_rel_25_error;
// -- Table: DoSWithBlockGasLimit
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_26_DoSWithBlockGasLimit = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<23,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_26_DoSWithBlockGasLimit;
// -- Table: InsufficientGas
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_InsufficientGas = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_27_InsufficientGas;
// -- Table: arithmetic
std::unique_ptr<t_btree_6__1_0_2_3_4_5__2__63> rel_28_arithmetic = std::make_unique<t_btree_6__1_0_2_3_4_5__2__63>();
souffle::RelationWrapper<25,t_btree_6__1_0_2_3_4_5__2__63,Tuple<RamDomain,6>,6,1> wrapper_rel_28_arithmetic;
// -- Table: storage
std::unique_ptr<t_btree_7__1_4_5_6__1_3_4_5_6__1_2_5_6_0_3_4__2__10__102__114__122__127> rel_29_storage = std::make_unique<t_btree_7__1_4_5_6__1_3_4_5_6__1_2_5_6_0_3_4__2__10__102__114__122__127>();
souffle::RelationWrapper<26,t_btree_7__1_4_5_6__1_3_4_5_6__1_2_5_6_0_3_4__2__10__102__114__122__127,Tuple<RamDomain,7>,7,1> wrapper_rel_29_storage;
// -- Table: ParityWalletHack1
std::unique_ptr<t_btree_8__0_1_2_3_4_5_6_7__255> rel_30_ParityWalletHack1 = std::make_unique<t_btree_8__0_1_2_3_4_5_6_7__255>();
souffle::RelationWrapper<27,t_btree_8__0_1_2_3_4_5_6_7__255,Tuple<RamDomain,8>,8,1> wrapper_rel_30_ParityWalletHack1;
// -- Table: TransactionOrderDependency
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_31_TransactionOrderDependency = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<28,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4,1> wrapper_rel_31_TransactionOrderDependency;
// -- Table: transfer
std::unique_ptr<t_btree_5__1_0_2_3_4__2__31> rel_32_transfer = std::make_unique<t_btree_5__1_0_2_3_4__2__31>();
souffle::RelationWrapper<29,t_btree_5__1_0_2_3_4__2__31,Tuple<RamDomain,5>,5,1> wrapper_rel_32_transfer;
// -- Table: IntegerOverflow
std::unique_ptr<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047> rel_33_IntegerOverflow = std::make_unique<t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047>();
souffle::RelationWrapper<30,t_btree_11__0_1_2_3_4_5_6_7_8_9_10__2047,Tuple<RamDomain,11>,11,1> wrapper_rel_33_IntegerOverflow;
// -- Table: IntegerUnderflow
std::unique_ptr<t_btree_10__0_1_2_3_4_5_6_7_8_9__1023> rel_34_IntegerUnderflow = std::make_unique<t_btree_10__0_1_2_3_4_5_6_7_8_9__1023>();
souffle::RelationWrapper<31,t_btree_10__0_1_2_3_4_5_6_7_8_9__1023,Tuple<RamDomain,10>,10,1> wrapper_rel_34_IntegerUnderflow;
// -- Table: UncheckedSignature
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_35_UncheckedSignature = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<32,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_35_UncheckedSignature;
// -- Table: selfdestruct
std::unique_ptr<t_btree_6__1_3_0_2_4_5__10__63> rel_36_selfdestruct = std::make_unique<t_btree_6__1_3_0_2_4_5__10__63>();
souffle::RelationWrapper<33,t_btree_6__1_3_0_2_4_5__10__63,Tuple<RamDomain,6>,6,1> wrapper_rel_36_selfdestruct;
// -- Table: ParityWalletHack2
std::unique_ptr<t_btree_9__0_1_2_3_4_5_6_7_8__511> rel_37_ParityWalletHack2 = std::make_unique<t_btree_9__0_1_2_3_4_5_6_7_8__511>();
souffle::RelationWrapper<34,t_btree_9__0_1_2_3_4_5_6_7_8__511,Tuple<RamDomain,9>,9,1> wrapper_rel_37_ParityWalletHack2;
// -- Table: UncheckedSuicide
std::unique_ptr<t_btree_7__0_1_2_3_4_5_6__127> rel_38_UncheckedSuicide = std::make_unique<t_btree_7__0_1_2_3_4_5_6__127>();
souffle::RelationWrapper<35,t_btree_7__0_1_2_3_4_5_6__127,Tuple<RamDomain,7>,7,1> wrapper_rel_38_UncheckedSuicide;
// -- Table: bitwise_logic
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_39_bitwise_logic = std::make_unique<t_btree_4__1_0_2_3__2__15>();
souffle::RelationWrapper<36,t_btree_4__1_0_2_3__2__15,Tuple<RamDomain,4>,4,1> wrapper_rel_39_bitwise_logic;
// -- Table: ShortAddress
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_40_ShortAddress = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<37,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6,1> wrapper_rel_40_ShortAddress;
public:
Sf_analyzer() : 
wrapper_rel_1_block(*rel_1_block,symTable,"block",std::array<const char *,4>{{"i:number","i:number","i:number","i:number"}},std::array<const char *,4>{{"block","gas_used","gas_limit","timestamp"}}),

wrapper_rel_2_condition(*rel_2_condition,symTable,"condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","transaction_hash"}}),

wrapper_rel_3_def(*rel_3_def,symTable,"def",std::array<const char *,2>{{"i:number","s:Opcode"}},std::array<const char *,2>{{"step","opcode"}}),

wrapper_rel_4_throw(*rel_4_throw,symTable,"throw",std::array<const char *,5>{{"i:number","s:symbol","s:Opcode","s:Address","i:number"}},std::array<const char *,5>{{"step","transaction_hash","opcode","caller","depth"}}),

wrapper_rel_5_transaction(*rel_5_transaction,symTable,"transaction",std::array<const char *,6>{{"s:symbol","s:Address","s:Address","s:symbol","i:number","i:number"}},std::array<const char *,6>{{"transaction_hash","from","to","input_data","status","block"}}),

wrapper_rel_6_use(*rel_6_use,symTable,"use",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"step1","step2"}}),

wrapper_rel_7_BalanceInvariant(*rel_7_BalanceInvariant,symTable,"BalanceInvariant",std::array<const char *,3>{{"s:symbol","i:number","i:number"}},std::array<const char *,3>{{"hash","timestamp","step"}}),

wrapper_rel_8_data_flow(*rel_8_data_flow,symTable,"data_flow",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"x","y"}}),

wrapper_rel_11_used_in_condition(*rel_11_used_in_condition,symTable,"used_in_condition",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_12_caller_check(*rel_12_caller_check,symTable,"caller_check",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"step","hash"}}),

wrapper_rel_13_call(*rel_13_call,symTable,"call",std::array<const char *,9>{{"i:number","s:symbol","s:Opcode","s:Address","s:Address","s:symbol","s:Value","i:number","i:number"}},std::array<const char *,9>{{"step","transaction_hash","opcode","caller","callee","input_data","amount","depth","success"}}),

wrapper_rel_14_BlockStateDependence(*rel_14_BlockStateDependence,symTable,"BlockStateDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_15_CallStackDepth(*rel_15_CallStackDepth,symTable,"CallStackDepth",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_16_CreateBasedReentrancy(*rel_16_CreateBasedReentrancy,symTable,"CreateBasedReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_17_CrossFunctionReentrancy(*rel_17_CrossFunctionReentrancy,symTable,"CrossFunctionReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_18_DelegatedReentrancy(*rel_18_DelegatedReentrancy,symTable,"DelegatedReentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_19_DoSWithUnexpectedThrow(*rel_19_DoSWithUnexpectedThrow,symTable,"DoSWithUnexpectedThrow",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_20_Reentrancy(*rel_20_Reentrancy,symTable,"Reentrancy",std::array<const char *,6>{{"s:symbol","i:number","s:Address","s:Address","i:number","s:Value"}},std::array<const char *,6>{{"hash","timestamp","caller","callee","depth","amount"}}),

wrapper_rel_21_TimestampDependence(*rel_21_TimestampDependence,symTable,"TimestampDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_22_TransactionStateDependence(*rel_22_TransactionStateDependence,symTable,"TransactionStateDependence",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_23_UncheckedDelegatecall(*rel_23_UncheckedDelegatecall,symTable,"UncheckedDelegatecall",std::array<const char *,5>{{"s:symbol","i:number","i:number","s:Address","s:Address"}},std::array<const char *,5>{{"hash","timestamp","step","caller","callee"}}),

wrapper_rel_24_UnhandledException(*rel_24_UnhandledException,symTable,"UnhandledException",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_25_error(*rel_25_error,symTable,"error",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"transaction_hash","error_message"}}),

wrapper_rel_26_DoSWithBlockGasLimit(*rel_26_DoSWithBlockGasLimit,symTable,"DoSWithBlockGasLimit",std::array<const char *,7>{{"s:symbol","i:number","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","gas_limit","caller","callee","amount"}}),

wrapper_rel_27_InsufficientGas(*rel_27_InsufficientGas,symTable,"InsufficientGas",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","caller","callee","amount"}}),

wrapper_rel_28_arithmetic(*rel_28_arithmetic,symTable,"arithmetic",std::array<const char *,6>{{"i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value"}},std::array<const char *,6>{{"step","opcode","first_operand","second_operand","arithmetic_result","evm_result"}}),

wrapper_rel_29_storage(*rel_29_storage,symTable,"storage",std::array<const char *,7>{{"i:number","s:Opcode","i:number","s:Value","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"step","opcode","block","transaction","caller","contract","storage_index"}}),

wrapper_rel_30_ParityWalletHack1(*rel_30_ParityWalletHack1,symTable,"ParityWalletHack1",std::array<const char *,8>{{"s:symbol","s:symbol","i:number","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,8>{{"hash1","hash2","timestamp1","timestamp2","step","caller","callee","amount"}}),

wrapper_rel_31_TransactionOrderDependency(*rel_31_TransactionOrderDependency,symTable,"TransactionOrderDependency",std::array<const char *,4>{{"s:symbol","s:symbol","i:number","i:number"}},std::array<const char *,4>{{"hash1","hash2","timestamp","block"}}),

wrapper_rel_32_transfer(*rel_32_transfer,symTable,"transfer",std::array<const char *,5>{{"i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,5>{{"step","transaction_hash","from","to","value"}}),

wrapper_rel_33_IntegerOverflow(*rel_33_IntegerOverflow,symTable,"IntegerOverflow",std::array<const char *,11>{{"s:symbol","i:number","i:number","s:Opcode","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value"}},std::array<const char *,11>{{"hash","timestamp","step","opcode","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount"}}),

wrapper_rel_34_IntegerUnderflow(*rel_34_IntegerUnderflow,symTable,"IntegerUnderflow",std::array<const char *,10>{{"s:symbol","i:number","i:number","s:Value","s:Value","s:Value","s:Value","s:Address","s:Address","s:Value"}},std::array<const char *,10>{{"hash","timestamp","step","first_operand","second_operand","arithmetic_result","evm_result","from","to","amount"}}),

wrapper_rel_35_UncheckedSignature(*rel_35_UncheckedSignature,symTable,"UncheckedSignature",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:symbol","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","input_data","from","to","amount"}}),

wrapper_rel_36_selfdestruct(*rel_36_selfdestruct,symTable,"selfdestruct",std::array<const char *,6>{{"i:number","s:symbol","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"step","transaction_hash","caller","contract","destination","amount"}}),

wrapper_rel_37_ParityWalletHack2(*rel_37_ParityWalletHack2,symTable,"ParityWalletHack2",std::array<const char *,9>{{"s:symbol","s:symbol","i:number","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,9>{{"hash1","hash2","timestamp1","timestamp2","step","caller","contract","destination","amount"}}),

wrapper_rel_38_UncheckedSuicide(*rel_38_UncheckedSuicide,symTable,"UncheckedSuicide",std::array<const char *,7>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Address","s:Value"}},std::array<const char *,7>{{"hash","timestamp","step","caller","contract","destination","amount"}}),

wrapper_rel_39_bitwise_logic(*rel_39_bitwise_logic,symTable,"bitwise_logic",std::array<const char *,4>{{"i:number","s:Opcode","s:Value","s:Value"}},std::array<const char *,4>{{"step","opcode","first_operand","second_operand"}}),

wrapper_rel_40_ShortAddress(*rel_40_ShortAddress,symTable,"ShortAddress",std::array<const char *,6>{{"s:symbol","i:number","i:number","s:Address","s:Address","s:Value"}},std::array<const char *,6>{{"hash","timestamp","step","from","to","amount"}}){
addRelation("block",&wrapper_rel_1_block,true,false);
addRelation("condition",&wrapper_rel_2_condition,true,false);
addRelation("def",&wrapper_rel_3_def,true,false);
addRelation("throw",&wrapper_rel_4_throw,true,false);
addRelation("transaction",&wrapper_rel_5_transaction,true,false);
addRelation("use",&wrapper_rel_6_use,true,false);
addRelation("BalanceInvariant",&wrapper_rel_7_BalanceInvariant,false,true);
addRelation("data_flow",&wrapper_rel_8_data_flow,false,false);
addRelation("used_in_condition",&wrapper_rel_11_used_in_condition,false,false);
addRelation("caller_check",&wrapper_rel_12_caller_check,false,false);
addRelation("call",&wrapper_rel_13_call,true,false);
addRelation("BlockStateDependence",&wrapper_rel_14_BlockStateDependence,false,true);
addRelation("CallStackDepth",&wrapper_rel_15_CallStackDepth,false,true);
addRelation("CreateBasedReentrancy",&wrapper_rel_16_CreateBasedReentrancy,false,true);
addRelation("CrossFunctionReentrancy",&wrapper_rel_17_CrossFunctionReentrancy,false,true);
addRelation("DelegatedReentrancy",&wrapper_rel_18_DelegatedReentrancy,false,true);
addRelation("DoSWithUnexpectedThrow",&wrapper_rel_19_DoSWithUnexpectedThrow,false,true);
addRelation("Reentrancy",&wrapper_rel_20_Reentrancy,false,true);
addRelation("TimestampDependence",&wrapper_rel_21_TimestampDependence,false,true);
addRelation("TransactionStateDependence",&wrapper_rel_22_TransactionStateDependence,false,true);
addRelation("UncheckedDelegatecall",&wrapper_rel_23_UncheckedDelegatecall,false,true);
addRelation("UnhandledException",&wrapper_rel_24_UnhandledException,false,true);
addRelation("error",&wrapper_rel_25_error,true,false);
addRelation("DoSWithBlockGasLimit",&wrapper_rel_26_DoSWithBlockGasLimit,false,true);
addRelation("InsufficientGas",&wrapper_rel_27_InsufficientGas,false,true);
addRelation("arithmetic",&wrapper_rel_28_arithmetic,true,false);
addRelation("storage",&wrapper_rel_29_storage,true,false);
addRelation("ParityWalletHack1",&wrapper_rel_30_ParityWalletHack1,false,true);
addRelation("TransactionOrderDependency",&wrapper_rel_31_TransactionOrderDependency,false,true);
addRelation("transfer",&wrapper_rel_32_transfer,true,false);
addRelation("IntegerOverflow",&wrapper_rel_33_IntegerOverflow,false,true);
addRelation("IntegerUnderflow",&wrapper_rel_34_IntegerUnderflow,false,true);
addRelation("UncheckedSignature",&wrapper_rel_35_UncheckedSignature,false,true);
addRelation("selfdestruct",&wrapper_rel_36_selfdestruct,true,false);
addRelation("ParityWalletHack2",&wrapper_rel_37_ParityWalletHack2,false,true);
addRelation("UncheckedSuicide",&wrapper_rel_38_UncheckedSuicide,false,true);
addRelation("bitwise_logic",&wrapper_rel_39_bitwise_logic,true,false);
addRelation("ShortAddress",&wrapper_rel_40_ShortAddress,false,true);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./condition.facts"},{"name","condition"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_2_condition);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./def.facts"},{"name","def"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1}), symTable, ioDirectives, false, 1)->readAll(*rel_3_def);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./throw.facts"},{"name","throw"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,0}), symTable, ioDirectives, false, 1)->readAll(*rel_4_throw);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transaction.facts"},{"name","transaction"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_6_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(BalanceInvariant(hash,timestamp,step2) :- 
   def(step1,"BALANCE"),
   condition(step2,hash),
   use(step2,step1),
   throw(step3,hash,_,_,_),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   step2 < step3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [357:1-364:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_4_throw->empty()) && !(rel_6_use->empty()) && !(rel_2_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_2_condition_op_ctxt,rel_2_condition->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_4_throw_op_ctxt,rel_4_throw->createContext());
CREATE_OP_CONTEXT(rel_6_use_op_ctxt,rel_6_use->createContext());
CREATE_OP_CONTEXT(rel_7_BalanceInvariant_op_ctxt,rel_7_BalanceInvariant->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(24)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_2_condition) {
if( rel_6_use->contains(Tuple<RamDomain,2>{{env1[0],env0[0]}},READ_OP_CONTEXT(rel_6_use_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env1[1],0,0,0}};
auto range = rel_4_throw->equalRange_2(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,3> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0])}};
rel_7_BalanceInvariant->insert(tuple,READ_OP_CONTEXT(rel_7_BalanceInvariant_op_ctxt));
}
}
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep"},{"filename","./BalanceInvariant.csv"},{"name","BalanceInvariant"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,x).
in file lib/horus.dl [5:1-6:13])_");
if(!(rel_6_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_6_use_op_ctxt,rel_6_use->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
for(const auto& env0 : *rel_6_use) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[0])}};
rel_8_data_flow->insert(tuple,READ_OP_CONTEXT(rel_8_data_flow_op_ctxt));
}
}
();}
rel_9_delta_data_flow->insertAll(*rel_8_data_flow);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(data_flow(x,y) :- 
   use(y,z),
   data_flow(x,z).
in file lib/horus.dl [8:1-10:19])_");
if(!(rel_9_delta_data_flow->empty()) && !(rel_6_use->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_6_use_op_ctxt,rel_6_use->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_9_delta_data_flow_op_ctxt,rel_9_delta_data_flow->createContext());
CREATE_OP_CONTEXT(rel_10_new_data_flow_op_ctxt,rel_10_new_data_flow->createContext());
for(const auto& env0 : *rel_6_use) {
const Tuple<RamDomain,2> key{{0,env0[1]}};
auto range = rel_9_delta_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_9_delta_data_flow_op_ctxt));
for(const auto& env1 : range) {
if( !(rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env0[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[0])}};
rel_10_new_data_flow->insert(tuple,READ_OP_CONTEXT(rel_10_new_data_flow_op_ctxt));
}
}
}
}
();}
if(rel_10_new_data_flow->empty()) break;
rel_8_data_flow->insertAll(*rel_10_new_data_flow);
std::swap(rel_9_delta_data_flow, rel_10_new_data_flow);
rel_10_new_data_flow->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_9_delta_data_flow->purge();
if (!isHintsProfilingEnabled()) rel_10_new_data_flow->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_6_use->purge();
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(used_in_condition(step1,hash) :- 
   condition(step2,hash),
   data_flow(step1,step2).
in file lib/horus.dl [19:1-21:27])_");
if(!(rel_8_data_flow->empty()) && !(rel_2_condition->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_condition_op_ctxt,rel_2_condition->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
for(const auto& env0 : *rel_2_condition) {
const Tuple<RamDomain,2> key{{0,env0[0]}};
auto range = rel_8_data_flow->equalRange_2(key,READ_OP_CONTEXT(rel_8_data_flow_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[1])}};
rel_11_used_in_condition->insert(tuple,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
}
}
}
();}
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(caller_check(step2,hash) :- 
   def(step1,"CALLER"),
   condition(step2,hash),
   data_flow(step1,step2).
in file lib/horus.dl [13:1-16:27])_");
if(!(rel_8_data_flow->empty()) && !(rel_2_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_2_condition_op_ctxt,rel_2_condition->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_12_caller_check_op_ctxt,rel_12_caller_check->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(0)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_2_condition) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
Tuple<RamDomain,2> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1])}};
rel_12_caller_check->insert(tuple,READ_OP_CONTEXT(rel_12_caller_check_op_ctxt));
}
}
}
}
();}
if (!isHintsProfilingEnabled()&& performIO) rel_2_condition->purge();
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_13_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"BLOCKHASH"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [306:1-341:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt,rel_14_BlockStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(17)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_14_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step2,"COINBASE"),
   used_in_condition(step1,hash),
   call(_,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [306:1-341:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt,rel_14_BlockStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(18)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_11_used_in_condition) {
if( ((env1[0]) < (env0[0]))) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_14_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"NUMBER"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [306:1-341:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt,rel_14_BlockStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(19)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_14_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"DIFFICULTY"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [306:1-341:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt,rel_14_BlockStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(20)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_14_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(BlockStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"GASLIMIT"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [306:1-341:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt,rel_14_BlockStateDependence->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(21)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_14_BlockStateDependence->insert(tuple,READ_OP_CONTEXT(rel_14_BlockStateDependence_op_ctxt));
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CallStackDepth(hash,timestamp,step,caller,callee,amount) :- 
   call(step,hash,"CALL",caller,callee,_,amount,depth,_),
   transaction(hash,_,_,_,_,block),
   block(block,_,_,timestamp),
   depth > 1024.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [5:1-9:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_15_CallStackDepth_op_ctxt,rel_15_CallStackDepth->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,0}};
auto range = rel_13_call->equalRange_4(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
if( ((env0[7]) > (RamDomain(1024)))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,0,0}};
auto range = rel_5_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_15_CallStackDepth->insert(tuple,READ_OP_CONTEXT(rel_15_CallStackDepth_op_ctxt));
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CreateBasedReentrancy(hash,timestamp,caller,callee,depth3,amount2) :- 
   call(_,hash,"CREATE",caller,_,input_data,amount1,depth1,1),
   call(_,hash,"CREATE",caller,callee,input_data,amount1,depth3,1),
   call(_,hash,"CALL",caller,callee,_,amount2,depth3,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   depth1 < depth3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [52:1-59:33])_");
if(!(rel_13_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_16_CreateBasedReentrancy_op_ctxt,rel_16_CreateBasedReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(4),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(4),env0[3],0,env0[5],env0[6],0,RamDomain(1)}};
auto range = rel_13_call->equalRange_366(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env1[4],0,0,env1[7],RamDomain(1)}};
auto range = rel_13_call->equalRange_414(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[7]),static_cast<RamDomain>(env2[6])}};
rel_16_CreateBasedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_16_CreateBasedReentrancy_op_ctxt));
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(CrossFunctionReentrancy(hash,timestamp,callee,caller,depth2,amount2) :- 
   call(_,hash,"CALL",caller,callee,input_data1,amount1,depth1,1),
   call(_,hash,"CALL",callee,caller,_,amount2,depth2,1),
   call(_,hash,"CALL",caller,callee,input_data3,amount1,depth3,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   depth1 < depth2,
   depth2 < depth3,
   input_data1 != input_data3,
   "0" not_match amount2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [25:1-34:33])_");
if(!(rel_13_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_17_CrossFunctionReentrancy_op_ctxt,rel_17_CrossFunctionReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[4],env0[3],0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_286(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],0,env0[6],0,RamDomain(1)}};
auto range = rel_13_call->equalRange_350(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[7]) < (env2[7])) && ((env0[5]) != (env2[5]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[7]),static_cast<RamDomain>(env1[6])}};
rel_17_CrossFunctionReentrancy->insert(tuple,READ_OP_CONTEXT(rel_17_CrossFunctionReentrancy_op_ctxt));
}
}
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CrossFunctionReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DelegatedReentrancy(hash,timestamp,caller,callee1,depth2,amount2) :- 
   call(_,hash,"DELEGATECALL",caller,callee1,input_data,amount1,depth1,1),
   call(_,hash,"CALL",callee1,_,_,amount2,depth2,1),
   call(_,hash,"DELEGATECALL",caller,callee1,input_data,amount1,depth3,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   depth1 < depth2,
   depth2 < depth3,
   "0" not_match amount2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [39:1-47:33])_");
if(!(rel_13_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt,rel_18_DelegatedReentrancy->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[4],0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_270(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7])) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env1[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(3),env0[3],env0[4],env0[5],env0[6],0,RamDomain(1)}};
auto range = rel_13_call->equalRange_382(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[7]) < (env2[7]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env1[7]),static_cast<RamDomain>(env1[6])}};
rel_18_DelegatedReentrancy->insert(tuple,READ_OP_CONTEXT(rel_18_DelegatedReentrancy_op_ctxt));
}
}
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./DelegatedReentrancy.csv"},{"name","DelegatedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_18_DelegatedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DoSWithUnexpectedThrow(hash,timestamp,step3,caller,callee,amount) :- 
   call(step1,hash,"CALL",caller,callee,_,amount,depth3,0),
   throw(step2,hash,_,_,depth2),
   throw(step3,hash,_,_,depth3),
   transaction(hash,_,_,_,_,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2,
   depth3 < depth2,
   step1 < step3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [255:1-265:33])_");
if(!(rel_13_call->empty()) && !(rel_4_throw->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_19_DoSWithUnexpectedThrow_op_ctxt,rel_19_DoSWithUnexpectedThrow->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_4_throw_op_ctxt,rel_4_throw->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,0}};
auto range = rel_4_throw->equalRange_2(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0])) && ((env0[7]) < (env1[4]))) {
const Tuple<RamDomain,5> key{{0,env0[1],0,0,env0[7]}};
auto range = rel_4_throw->equalRange_18(key,READ_OP_CONTEXT(rel_4_throw_op_ctxt));
for(const auto& env2 : range) {
if( ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,0,0}};
auto range = rel_5_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_19_DoSWithUnexpectedThrow->insert(tuple,READ_OP_CONTEXT(rel_19_DoSWithUnexpectedThrow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./DoSWithUnexpectedThrow.csv"},{"name","DoSWithUnexpectedThrow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_19_DoSWithUnexpectedThrow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_4_throw->purge();
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(Reentrancy(hash,timestamp,caller,callee,depth1,amount) :- 
   call(_,hash,"CALL",caller,callee,_,amount,depth1,1),
   call(_,hash,"CALL",caller,callee,_,amount,depth2,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   depth1 < depth2,
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [14:1-20:33])_");
if(!(rel_13_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_20_Reentrancy_op_ctxt,rel_20_Reentrancy->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,9> key{{0,env0[1],RamDomain(1),env0[3],env0[4],0,env0[6],0,RamDomain(1)}};
auto range = rel_13_call->equalRange_350(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[7]) < (env1[7]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[7]),static_cast<RamDomain>(env0[6])}};
rel_20_Reentrancy->insert(tuple,READ_OP_CONTEXT(rel_20_Reentrancy_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TimestampDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"TIMESTAMP"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [281:1-288:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_21_TimestampDependence_op_ctxt,rel_21_TimestampDependence->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(15)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_21_TimestampDependence->insert(tuple,READ_OP_CONTEXT(rel_21_TimestampDependence_op_ctxt));
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TransactionStateDependence(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"ORIGIN"),
   used_in_condition(step1,hash),
   call(step2,hash,"CALL",caller,callee,_,amount,_,1),
   transaction(hash,from,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2,
   callee != from.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [293:1-301:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_22_TransactionStateDependence_op_ctxt,rel_22_TransactionStateDependence->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(16)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{env0[0],0}};
auto range = rel_11_used_in_condition->equalRange_1(key,READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,9> key{{0,env1[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6])) && ((env0[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[4]) != (env3[1]))) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_22_TransactionStateDependence->insert(tuple,READ_OP_CONTEXT(rel_22_TransactionStateDependence_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"DELEGATECALL",caller,callee,_,_,_,1),
   data_flow(step1,step2),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [172:1-185:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_8_data_flow->empty()) && !(rel_13_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_23_UncheckedDelegatecall_op_ctxt,rel_23_UncheckedDelegatecall->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_12_caller_check_op_ctxt,rel_12_caller_check->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( !(!rel_12_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env1[1]}},READ_OP_CONTEXT(rel_12_caller_check_op_ctxt)).empty()) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_23_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_23_UncheckedDelegatecall_op_ctxt));
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(UncheckedDelegatecall(hash,timestamp,step2,caller,callee) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"DELEGATECALL",caller,callee,_,_,_,1),
   data_flow(step1,step2),
   caller_check(step3,hash),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   step2 < step3.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [172:1-185:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_12_caller_check->empty()) && !(rel_8_data_flow->empty()) && !(rel_13_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_23_UncheckedDelegatecall_op_ctxt,rel_23_UncheckedDelegatecall->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_12_caller_check_op_ctxt,rel_12_caller_check->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,env1[1]}};
auto range = rel_12_caller_check->equalRange_2(key,READ_OP_CONTEXT(rel_12_caller_check_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[0]) < (env2[0]))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,5> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4])}};
rel_23_UncheckedDelegatecall->insert(tuple,READ_OP_CONTEXT(rel_23_UncheckedDelegatecall_op_ctxt));
}
}
break;
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UnhandledException(hash,timestamp,step1,caller,callee,amount) :- 
   call(step1,hash,"CALL",caller,callee,_,amount,_,0),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   !used_in_condition(step1,hash),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [64:1-69:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_13_call->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_24_UnhandledException_op_ctxt,rel_24_UnhandledException->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_11_used_in_condition->contains(Tuple<RamDomain,2>{{env0[0],env0[1]}},READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt))) && !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[6]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[6])}};
rel_24_UnhandledException->insert(tuple,READ_OP_CONTEXT(rel_24_UnhandledException_op_ctxt));
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_25_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(DoSWithBlockGasLimit(hash,timestamp,step,gas_limit,caller,callee,amount) :- 
   block(block,gas_limit,gas_limit,timestamp),
   transaction(hash,_,_,_,_,block),
   error(hash,"out of gas"),
   call(step,hash,"CALL",caller,callee,_,amount,_,1),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [270:1-276:29])_");
if(!(rel_13_call->empty()) && !(rel_25_error->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_26_DoSWithBlockGasLimit_op_ctxt,rel_26_DoSWithBlockGasLimit->createContext());
CREATE_OP_CONTEXT(rel_25_error_op_ctxt,rel_25_error->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
for(const auto& env0 : *rel_1_block) {
if( ((env0[1]) == (env0[2]))) {
const Tuple<RamDomain,6> key{{0,0,0,0,0,env0[0]}};
auto range = rel_5_transaction->equalRange_32(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
if( rel_25_error->contains(Tuple<RamDomain,2>{{env1[0],RamDomain(14)}},READ_OP_CONTEXT(rel_25_error_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,env1[0],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env2[6]))) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_26_DoSWithBlockGasLimit->insert(tuple,READ_OP_CONTEXT(rel_26_DoSWithBlockGasLimit_op_ctxt));
}
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tgas_limit\tcaller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_26_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(InsufficientGas(hash,timestamp,step2,caller,callee,amount) :- 
   def(step1,"CALLDATALOAD"),
   call(step2,hash,"CALL",caller,callee,_,amount,_,0),
   data_flow(step1,step2),
   error(hash,"out of gas"),
   transaction(hash,_,_,_,_,block),
   block(block,_,_,timestamp).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [368:1-374:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_25_error->empty()) && !(rel_8_data_flow->empty()) && !(rel_13_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_27_InsufficientGas_op_ctxt,rel_27_InsufficientGas->createContext());
CREATE_OP_CONTEXT(rel_25_error_op_ctxt,rel_25_error->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(0)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt)) && rel_25_error->contains(Tuple<RamDomain,2>{{env1[1],RamDomain(14)}},READ_OP_CONTEXT(rel_25_error_op_ctxt))) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,0,0}};
auto range = rel_5_transaction->equalRange_1(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[6])}};
rel_27_InsufficientGas->insert(tuple,READ_OP_CONTEXT(rel_27_InsufficientGas_op_ctxt));
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./InsufficientGas.csv"},{"name","InsufficientGas"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_25_error->purge();
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_28_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
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
SignalHandler::instance()->setMsg(R"_(ParityWalletHack1(hash1,hash2,timestamp1,timestamp2,step6,caller,callee,amount) :- 
   call(step0,hash1,"DELEGATECALL",_,_,_,_,_,1),
   def(step1,"CALLDATACOPY"),
   storage(step2,"SSTORE",_,hash1,from,contract,index),
   data_flow(step1,step2),
   call(step3,hash2,"DELEGATECALL",_,_,_,_,_,1),
   storage(step4,"SLOAD",_,hash2,from,contract,index),
   used_in_condition(step4,hash2),
   call(step6,hash2,"CALL",caller,callee,_,amount,_,1),
   transaction(hash1,_,_,_,1,block1),
   block(block1,_,_,timestamp1),
   transaction(hash2,_,_,_,1,block2),
   block(block2,_,_,timestamp2),
   step0 < step2,
   step3 < step4,
   step2 < step4,
   hash1 != hash2,
   "0" not_match amount,
   step4 < step6.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [190:1-208:35])_");
if(!(rel_3_def->empty()) && !(rel_8_data_flow->empty()) && !(rel_29_storage->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_13_call->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_30_ParityWalletHack1_op_ctxt,rel_30_ParityWalletHack1->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,env0[1],0,0,0}};
auto range = rel_29_storage->equalRange_10(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( ((env0[0]) < (env2[0])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(3),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env3 : range) {
if( ((env0[1]) != (env3[1]))) {
const Tuple<RamDomain,7> key{{0,RamDomain(10),0,env3[1],env2[4],env2[5],env2[6]}};
auto range = rel_29_storage->equalRange_122(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env4 : range) {
if( ((env2[0]) < (env4[0])) && ((env3[0]) < (env4[0])) && rel_11_used_in_condition->contains(Tuple<RamDomain,2>{{env4[0],env3[1]}},READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,env3[1],RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_262(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env5 : range) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env5[6])) && ((env4[0]) < (env5[0]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env6 : range) {
const Tuple<RamDomain,4> key{{env6[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env7 : range) {
const Tuple<RamDomain,6> key{{env3[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env8 : range) {
const Tuple<RamDomain,4> key{{env8[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env9 : range) {
Tuple<RamDomain,8> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env3[1]),static_cast<RamDomain>(env7[3]),static_cast<RamDomain>(env9[3]),static_cast<RamDomain>(env5[0]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env5[4]),static_cast<RamDomain>(env5[6])}};
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
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tstep\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
SignalHandler::instance()->setMsg(R"_(TransactionOrderDependency(hash1,hash2,timestamp,block) :- 
   storage(step1,"SSTORE",block,hash1,caller1,contract,index),
   storage(step2,"SLOAD",block,hash2,caller2,contract,index),
   block(block,_,_,timestamp),
   hash1 != hash2,
   step1 < step2,
   caller1 != caller2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [145:1-151:33])_");
if(!(rel_29_storage->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_31_TransactionOrderDependency_op_ctxt,rel_31_TransactionOrderDependency->createContext());
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(10),env0[2],0,0,env0[5],env0[6]}};
auto range = rel_29_storage->equalRange_102(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[3]) != (env1[3])) && ((env0[0]) < (env1[0])) && ((env0[4]) != (env1[4]))) {
const Tuple<RamDomain,4> key{{env0[2],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple{{static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[2])}};
rel_31_TransactionOrderDependency->insert(tuple,READ_OP_CONTEXT(rel_31_TransactionOrderDependency_op_ctxt));
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp\tblock"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,opcode,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(step4,hash,from,to,amount),
   data_flow(step1,step4),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "ADD" match opcode,
   from != to.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:1-116:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_29_storage->empty()) && !(rel_32_transfer->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt,rel_33_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_28_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(6)),symTable.resolve(env1[1])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
if( ((env3[2]) != (env3[3])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env3[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[3],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4])}};
rel_33_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt));
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
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,opcode,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   call(step3,hash,"CALL",from,to,_,amount,_,1),
   data_flow(step2,step3),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "ADD" match opcode.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:1-116:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_13_call->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt,rel_33_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_28_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(6)),symTable.resolve(env1[1])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_33_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt));
}
}
}
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,opcode,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(step4,hash,from,to,amount),
   data_flow(step1,step4),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "MUL" match opcode,
   from != to.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:1-116:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_29_storage->empty()) && !(rel_32_transfer->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt,rel_33_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_28_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(8)),symTable.resolve(env1[1])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
if( ((env3[2]) != (env3[3])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env3[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[3],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4])}};
rel_33_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt));
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
SignalHandler::instance()->setMsg(R"_(IntegerOverflow(hash,timestamp,step2,opcode,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,opcode,first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   call(step3,hash,"CALL",from,to,_,amount,_,1),
   data_flow(step2,step3),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   "MUL" match opcode.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [74:1-116:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_13_call->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt,rel_33_IntegerOverflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
for(const auto& env1 : *rel_28_arithmetic) {
if( ((env1[4]) != (env1[5])) && regex_wrapper(symTable.resolve(RamDomain(8)),symTable.resolve(env1[1])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,11> tuple{{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_33_IntegerOverflow->insert(tuple,READ_OP_CONTEXT(rel_33_IntegerOverflow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   data_flow(step2,step3),
   transfer(step4,hash,from,to,amount),
   data_flow(step1,step4),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result,
   from != to.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [121:1-140:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_29_storage->empty()) && !(rel_32_transfer->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_34_IntegerUnderflow_op_ctxt,rel_34_IntegerUnderflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(9),0,0,0,0}};
auto range = rel_28_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_28_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,5> key{{0,env2[3],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
if( ((env3[2]) != (env3[3])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env3[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[3],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,10> tuple{{static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4])}};
rel_34_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_34_IntegerUnderflow_op_ctxt));
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
SignalHandler::instance()->setMsg(R"_(IntegerUnderflow(hash,timestamp,step2,first_operand,second_operand,arithmetic_result,evm_result,from,to,amount) :- 
   def(step1,"CALLDATALOAD"),
   arithmetic(step2,"SUB",first_operand,second_operand,arithmetic_result,evm_result),
   data_flow(step1,step2),
   call(step3,hash,"CALL",from,to,_,amount,_,1),
   data_flow(step2,step3),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   arithmetic_result != evm_result.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [121:1-140:33])_");
if(!(rel_3_def->empty()) && !(rel_28_arithmetic->empty()) && !(rel_13_call->empty()) && !(rel_8_data_flow->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_34_IntegerUnderflow_op_ctxt,rel_34_IntegerUnderflow->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,6> key{{0,RamDomain(9),0,0,0,0}};
auto range = rel_28_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_28_arithmetic_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[4]) != (env1[5])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,0,0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_260(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env2 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{env2[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,4> key{{env3[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env4 : range) {
Tuple<RamDomain,10> tuple{{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env4[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[2]),static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env1[4]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env2[4]),static_cast<RamDomain>(env2[6])}};
rel_34_IntegerUnderflow->insert(tuple,READ_OP_CONTEXT(rel_34_IntegerUnderflow_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedSignature(hash,timestamp,step2,input_data,from,to,amount) :- 
   def(step1,"SHA3"),
   call(step2,hash,"CALL",_,"0x0000000000000000000000000000000000000001",input_data,_,_,1),
   data_flow(step1,step2),
   storage(step3,"SSTORE",_,hash,_,_,_),
   transfer(_,hash,from,to,amount),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   !data_flow(step1,step3).
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [345:1-353:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_32_transfer->empty()) && !(rel_29_storage->empty()) && !(rel_8_data_flow->empty()) && !(rel_13_call->empty()) && !(rel_3_def->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_13_call_op_ctxt,rel_13_call->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_35_UncheckedSignature_op_ctxt,rel_35_UncheckedSignature->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(22)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,9> key{{0,0,RamDomain(1),0,RamDomain(23),0,0,0,RamDomain(1)}};
auto range = rel_13_call->equalRange_276(key,READ_OP_CONTEXT(rel_13_call_op_ctxt));
for(const auto& env1 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,env1[1],0,0,0}};
auto range = rel_29_storage->equalRange_10(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt)))) {
const Tuple<RamDomain,5> key{{0,env1[1],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,6> key{{env1[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env3[4])}};
rel_35_UncheckedSignature->insert(tuple,READ_OP_CONTEXT(rel_35_UncheckedSignature_op_ctxt));
}
}
}
break;
}
}
}
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tinput_data\tfrom\tto\tamount"},{"filename","./UncheckedSignature.csv"},{"name","UncheckedSignature"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_13_call->purge();
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_36_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 33 */
/* BEGIN STRATUM 34 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ParityWalletHack2(hash1,hash2,timestamp1,timestamp2,step4,caller,contract,destination,amount) :- 
   def(step0,"CALLDATACOPY"),
   storage(step1,"SSTORE",_,hash1,from,contract,index),
   data_flow(step0,step1),
   storage(step2,"SLOAD",_,hash2,from,contract,index),
   used_in_condition(step2,hash2),
   selfdestruct(step4,hash2,caller,contract,destination,amount),
   transaction(hash1,_,_,_,1,block1),
   block(block1,_,_,timestamp1),
   transaction(hash2,_,_,_,1,block2),
   block(block2,_,_,timestamp2),
   step1 < step2,
   hash1 != hash2,
   step2 < step4.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [213:1-226:35])_");
if(!(rel_3_def->empty()) && !(rel_8_data_flow->empty()) && !(rel_29_storage->empty()) && !(rel_11_used_in_condition->empty()) && !(rel_36_selfdestruct->empty()) && !(rel_5_transaction->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_11_used_in_condition_op_ctxt,rel_11_used_in_condition->createContext());
CREATE_OP_CONTEXT(rel_37_ParityWalletHack2_op_ctxt,rel_37_ParityWalletHack2->createContext());
CREATE_OP_CONTEXT(rel_36_selfdestruct_op_ctxt,rel_36_selfdestruct->createContext());
const Tuple<RamDomain,2> key{{0,RamDomain(11)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,0,0,0,0}};
auto range = rel_29_storage->equalRange_2(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env1 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env0[0],env1[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(10),0,0,env1[4],env1[5],env1[6]}};
auto range = rel_29_storage->equalRange_114(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env2 : range) {
if( ((env1[3]) != (env2[3])) && ((env1[0]) < (env2[0])) && rel_11_used_in_condition->contains(Tuple<RamDomain,2>{{env2[0],env2[3]}},READ_OP_CONTEXT(rel_11_used_in_condition_op_ctxt))) {
const Tuple<RamDomain,6> key{{0,env2[3],0,env1[5],0,0}};
auto range = rel_36_selfdestruct->equalRange_10(key,READ_OP_CONTEXT(rel_36_selfdestruct_op_ctxt));
for(const auto& env3 : range) {
if( ((env2[0]) < (env3[0]))) {
const Tuple<RamDomain,6> key{{env1[3],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env4 : range) {
const Tuple<RamDomain,4> key{{env4[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env5 : range) {
const Tuple<RamDomain,6> key{{env2[3],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env6 : range) {
const Tuple<RamDomain,4> key{{env6[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env7 : range) {
Tuple<RamDomain,9> tuple{{static_cast<RamDomain>(env1[3]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env5[3]),static_cast<RamDomain>(env7[3]),static_cast<RamDomain>(env3[0]),static_cast<RamDomain>(env3[2]),static_cast<RamDomain>(env1[5]),static_cast<RamDomain>(env3[4]),static_cast<RamDomain>(env3[5])}};
rel_37_ParityWalletHack2->insert(tuple,READ_OP_CONTEXT(rel_37_ParityWalletHack2_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_11_used_in_condition->purge();
}();
/* END STRATUM 34 */
/* BEGIN STRATUM 35 */
[&]() {
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(hash,timestamp,step1,caller,contract,destination,amount) :- 
   selfdestruct(step1,hash,caller,contract,destination,amount),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   !caller_check(_,hash),
   "0" not_match amount.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [156:1-167:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_36_selfdestruct->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_caller_check_op_ctxt,rel_12_caller_check->createContext());
CREATE_OP_CONTEXT(rel_36_selfdestruct_op_ctxt,rel_36_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_38_UncheckedSuicide_op_ctxt,rel_38_UncheckedSuicide->createContext());
for(const auto& env0 : *rel_36_selfdestruct) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[5])) && !(!rel_12_caller_check->equalRange_2(Tuple<RamDomain,2>{{0,env0[1]}},READ_OP_CONTEXT(rel_12_caller_check_op_ctxt)).empty())) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{env1[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env2[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[5])}};
rel_38_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_38_UncheckedSuicide_op_ctxt));
}
}
}
}
}
();}
SignalHandler::instance()->setMsg(R"_(UncheckedSuicide(hash,timestamp,step1,caller,contract,destination,amount) :- 
   selfdestruct(step1,hash,caller,contract,destination,amount),
   caller_check(step2,hash),
   transaction(hash,_,_,_,1,block),
   block(block,_,_,timestamp),
   "0" not_match amount,
   step1 < step2.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [156:1-167:33])_");
if(!(rel_1_block->empty()) && !(rel_5_transaction->empty()) && !(rel_12_caller_check->empty()) && !(rel_36_selfdestruct->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_12_caller_check_op_ctxt,rel_12_caller_check->createContext());
CREATE_OP_CONTEXT(rel_36_selfdestruct_op_ctxt,rel_36_selfdestruct->createContext());
CREATE_OP_CONTEXT(rel_38_UncheckedSuicide_op_ctxt,rel_38_UncheckedSuicide->createContext());
for(const auto& env0 : *rel_36_selfdestruct) {
if( !regex_wrapper(symTable.resolve(RamDomain(2)),symTable.resolve(env0[5]))) {
const Tuple<RamDomain,2> key{{0,env0[1]}};
auto range = rel_12_caller_check->equalRange_2(key,READ_OP_CONTEXT(rel_12_caller_check_op_ctxt));
for(const auto& env1 : range) {
if( ((env0[0]) < (env1[0]))) {
const Tuple<RamDomain,6> key{{env0[1],0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_17(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env2 : range) {
const Tuple<RamDomain,4> key{{env2[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env3 : range) {
Tuple<RamDomain,7> tuple{{static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env3[3]),static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[2]),static_cast<RamDomain>(env0[3]),static_cast<RamDomain>(env0[4]),static_cast<RamDomain>(env0[5])}};
rel_38_UncheckedSuicide->insert(tuple,READ_OP_CONTEXT(rel_38_UncheckedSuicide_op_ctxt));
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_36_selfdestruct->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_12_caller_check->purge();
}();
/* END STRATUM 35 */
/* BEGIN STRATUM 36 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./bitwise_logic.facts"},{"name","bitwise_logic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_39_bitwise_logic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 36 */
/* BEGIN STRATUM 37 */
[&]() {
SignalHandler::instance()->setMsg(R"_(ShortAddress(hash,timestamp,step7,from,to,amount) :- 
   transaction(hash,_,_,input_data,1,block),
   def(step1,"CALLDATALOAD"),
   bitwise_logic(step2,"AND",_,second_operand),
   data_flow(step1,step2),
   storage(step3,"SLOAD",_,hash,_,_,_),
   data_flow(step2,step3),
   arithmetic(step4,"ADD",_,_,_,_),
   data_flow(step3,step4),
   storage(step5,"SSTORE",_,hash,_,_,_),
   data_flow(step4,step5),
   def(step6,"CALLDATALOAD"),
   transfer(step7,hash,from,to,amount),
   data_flow(step6,step7),
   block(block,_,_,timestamp),
   (strlen(input_data)/2) > 36,
   (strlen(input_data)/2) < 68,
   "1461501637330902918203684832716283019655932542975" match second_operand,
   from != to.
in file /Users/Christof/Git/Horus/horus/analyzer/datalog/attacks.dl [231:1-250:33])_");
if(!(rel_5_transaction->empty()) && !(rel_39_bitwise_logic->empty()) && !(rel_28_arithmetic->empty()) && !(rel_29_storage->empty()) && !(rel_3_def->empty()) && !(rel_32_transfer->empty()) && !(rel_8_data_flow->empty()) && !(rel_1_block->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_28_arithmetic_op_ctxt,rel_28_arithmetic->createContext());
CREATE_OP_CONTEXT(rel_29_storage_op_ctxt,rel_29_storage->createContext());
CREATE_OP_CONTEXT(rel_1_block_op_ctxt,rel_1_block->createContext());
CREATE_OP_CONTEXT(rel_3_def_op_ctxt,rel_3_def->createContext());
CREATE_OP_CONTEXT(rel_5_transaction_op_ctxt,rel_5_transaction->createContext());
CREATE_OP_CONTEXT(rel_8_data_flow_op_ctxt,rel_8_data_flow->createContext());
CREATE_OP_CONTEXT(rel_32_transfer_op_ctxt,rel_32_transfer->createContext());
CREATE_OP_CONTEXT(rel_39_bitwise_logic_op_ctxt,rel_39_bitwise_logic->createContext());
CREATE_OP_CONTEXT(rel_40_ShortAddress_op_ctxt,rel_40_ShortAddress->createContext());
const Tuple<RamDomain,6> key{{0,0,0,0,RamDomain(1),0}};
auto range = rel_5_transaction->equalRange_16(key,READ_OP_CONTEXT(rel_5_transaction_op_ctxt));
for(const auto& env0 : range) {
if( (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) > (RamDomain(36))) && (((static_cast<RamDomain>(symTable.resolve(env0[3]).size())) / (RamDomain(2))) < (RamDomain(68)))) {
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,4> key{{0,RamDomain(12),0,0}};
auto range = rel_39_bitwise_logic->equalRange_2(key,READ_OP_CONTEXT(rel_39_bitwise_logic_op_ctxt));
for(const auto& env2 : range) {
if( regex_wrapper(symTable.resolve(RamDomain(13)),symTable.resolve(env2[3])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env1[0],env2[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(10),0,env0[0],0,0,0}};
auto range = rel_29_storage->equalRange_10(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env3 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env2[0],env3[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,6> key{{0,RamDomain(6),0,0,0,0}};
auto range = rel_28_arithmetic->equalRange_2(key,READ_OP_CONTEXT(rel_28_arithmetic_op_ctxt));
for(const auto& env4 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env3[0],env4[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,7> key{{0,RamDomain(7),0,env0[0],0,0,0}};
auto range = rel_29_storage->equalRange_10(key,READ_OP_CONTEXT(rel_29_storage_op_ctxt));
for(const auto& env5 : range) {
if( rel_8_data_flow->contains(Tuple<RamDomain,2>{{env4[0],env5[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,2> key{{0,RamDomain(5)}};
auto range = rel_3_def->equalRange_2(key,READ_OP_CONTEXT(rel_3_def_op_ctxt));
for(const auto& env6 : range) {
const Tuple<RamDomain,5> key{{0,env0[0],0,0,0}};
auto range = rel_32_transfer->equalRange_2(key,READ_OP_CONTEXT(rel_32_transfer_op_ctxt));
for(const auto& env7 : range) {
if( ((env7[2]) != (env7[3])) && rel_8_data_flow->contains(Tuple<RamDomain,2>{{env6[0],env7[0]}},READ_OP_CONTEXT(rel_8_data_flow_op_ctxt))) {
const Tuple<RamDomain,4> key{{env0[5],0,0,0}};
auto range = rel_1_block->equalRange_1(key,READ_OP_CONTEXT(rel_1_block_op_ctxt));
for(const auto& env8 : range) {
Tuple<RamDomain,6> tuple{{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env8[3]),static_cast<RamDomain>(env7[0]),static_cast<RamDomain>(env7[2]),static_cast<RamDomain>(env7[3]),static_cast<RamDomain>(env7[4])}};
rel_40_ShortAddress->insert(tuple,READ_OP_CONTEXT(rel_40_ShortAddress_op_ctxt));
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
}
}
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled()&& performIO) rel_3_def->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_28_arithmetic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_29_storage->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_39_bitwise_logic->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_32_transfer->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_1_block->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_5_transaction->purge();
if (!isHintsProfilingEnabled()&& performIO) rel_8_data_flow->purge();
}();
/* END STRATUM 37 */

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
std::cout << "Relation rel_6_use:\n";
rel_6_use->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_BalanceInvariant:\n";
rel_7_BalanceInvariant->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_data_flow:\n";
rel_8_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_delta_data_flow:\n";
rel_9_delta_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_new_data_flow:\n";
rel_10_new_data_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_used_in_condition:\n";
rel_11_used_in_condition->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_caller_check:\n";
rel_12_caller_check->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_call:\n";
rel_13_call->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_BlockStateDependence:\n";
rel_14_BlockStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_CallStackDepth:\n";
rel_15_CallStackDepth->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_CreateBasedReentrancy:\n";
rel_16_CreateBasedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_CrossFunctionReentrancy:\n";
rel_17_CrossFunctionReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_DelegatedReentrancy:\n";
rel_18_DelegatedReentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_DoSWithUnexpectedThrow:\n";
rel_19_DoSWithUnexpectedThrow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_Reentrancy:\n";
rel_20_Reentrancy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_TimestampDependence:\n";
rel_21_TimestampDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_TransactionStateDependence:\n";
rel_22_TransactionStateDependence->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_UncheckedDelegatecall:\n";
rel_23_UncheckedDelegatecall->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_UnhandledException:\n";
rel_24_UnhandledException->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_error:\n";
rel_25_error->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_DoSWithBlockGasLimit:\n";
rel_26_DoSWithBlockGasLimit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_InsufficientGas:\n";
rel_27_InsufficientGas->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_arithmetic:\n";
rel_28_arithmetic->printHintStatistics(std::cout,"  ");
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
std::cout << "Relation rel_32_transfer:\n";
rel_32_transfer->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_IntegerOverflow:\n";
rel_33_IntegerOverflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_IntegerUnderflow:\n";
rel_34_IntegerUnderflow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_UncheckedSignature:\n";
rel_35_UncheckedSignature->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_selfdestruct:\n";
rel_36_selfdestruct->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_37_ParityWalletHack2:\n";
rel_37_ParityWalletHack2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_38_UncheckedSuicide:\n";
rel_38_UncheckedSuicide->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_39_bitwise_logic:\n";
rel_39_bitwise_logic->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_40_ShortAddress:\n";
rel_40_ShortAddress->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep"},{"filename","./BalanceInvariant.csv"},{"name","BalanceInvariant"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./BlockStateDependence.csv"},{"name","BlockStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./CallStackDepth.csv"},{"name","CallStackDepth"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CreateBasedReentrancy.csv"},{"name","CreateBasedReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./CrossFunctionReentrancy.csv"},{"name","CrossFunctionReentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CrossFunctionReentrancy);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tcaller\tcallee\tdepth\tamount"},{"filename","./Reentrancy.csv"},{"name","Reentrancy"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TimestampDependence.csv"},{"name","TimestampDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./TransactionStateDependence.csv"},{"name","TransactionStateDependence"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee"},{"filename","./UncheckedDelegatecall.csv"},{"name","UncheckedDelegatecall"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./UnhandledException.csv"},{"name","UnhandledException"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tgas_limit\tcaller\tcallee\tamount"},{"filename","./DoSWithBlockGasLimit.csv"},{"name","DoSWithBlockGasLimit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_26_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcallee\tamount"},{"filename","./InsufficientGas.csv"},{"name","InsufficientGas"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tstep\tcaller\tcallee\tamount"},{"filename","./ParityWalletHack1.csv"},{"name","ParityWalletHack1"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp\tblock"},{"filename","./TransactionOrderDependency.csv"},{"name","TransactionOrderDependency"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\topcode\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount"},{"filename","./IntegerOverflow.csv"},{"name","IntegerOverflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfirst_operand\tsecond_operand\tarithmetic_result\tevm_result\tfrom\tto\tamount"},{"filename","./IntegerUnderflow.csv"},{"name","IntegerUnderflow"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tinput_data\tfrom\tto\tamount"},{"filename","./UncheckedSignature.csv"},{"name","UncheckedSignature"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash1\thash2\ttimestamp1\ttimestamp2\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./ParityWalletHack2.csv"},{"name","ParityWalletHack2"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tcaller\tcontract\tdestination\tamount"},{"filename","./UncheckedSuicide.csv"},{"name","UncheckedSuicide"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","hash\ttimestamp\tstep\tfrom\tto\tamount"},{"filename","./ShortAddress.csv"},{"name","ShortAddress"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ShortAddress);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
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
IOSystem::getInstance().getReader(std::vector<bool>({1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./use.facts"},{"name","use"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_6_use);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./call.facts"},{"name","call"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->readAll(*rel_13_call);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./error.facts"},{"name","error"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_25_error);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./arithmetic.facts"},{"name","arithmetic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_28_arithmetic);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./storage.facts"},{"name","storage"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_29_storage);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./transfer.facts"},{"name","transfer"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./selfdestruct.facts"},{"name","selfdestruct"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_36_selfdestruct);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./bitwise_logic.facts"},{"name","bitwise_logic"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->readAll(*rel_39_bitwise_logic);
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_5_transaction);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_use");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_6_use);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_call");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_13_call);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_25_error");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_25_error);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_28_arithmetic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_28_arithmetic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_29_storage");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_29_storage);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_32_transfer");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_32_transfer);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_36_selfdestruct");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_36_selfdestruct);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_39_bitwise_logic");
IOSystem::getInstance().getWriter(std::vector<bool>({0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_39_bitwise_logic);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_BalanceInvariant");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_7_BalanceInvariant);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_14_BlockStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_14_BlockStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_15_CallStackDepth");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_15_CallStackDepth);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_CreateBasedReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_16_CreateBasedReentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_17_CrossFunctionReentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_17_CrossFunctionReentrancy);
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
ioDirectives.setRelationName("rel_20_Reentrancy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,1,1,0,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_20_Reentrancy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_21_TimestampDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_21_TimestampDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_22_TransactionStateDependence");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_22_TransactionStateDependence);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_23_UncheckedDelegatecall");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_23_UncheckedDelegatecall);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_24_UnhandledException");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_24_UnhandledException);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_26_DoSWithBlockGasLimit");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_26_DoSWithBlockGasLimit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_27_InsufficientGas");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_27_InsufficientGas);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_30_ParityWalletHack1");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_30_ParityWalletHack1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_31_TransactionOrderDependency");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, false, 1)->writeAll(*rel_31_TransactionOrderDependency);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_33_IntegerOverflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_33_IntegerOverflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_34_IntegerUnderflow");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_34_IntegerUnderflow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_35_UncheckedSignature");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_35_UncheckedSignature);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_37_ParityWalletHack2");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_37_ParityWalletHack2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_38_UncheckedSuicide");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_38_UncheckedSuicide);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_40_ShortAddress");
IOSystem::getInstance().getWriter(std::vector<bool>({1,0,0,1,1,1}), symTable, ioDirectives, false, 1)->writeAll(*rel_40_ShortAddress);
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

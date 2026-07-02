#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

// EDITORIAL SOL 

/**
 * can(s, m, lim)
 *
 * Returns whether it is possible to construct an array of size <= lim.
 *
 * Think of c[i] = how many copies of 2^i we still need.
 *
 * Initially, c is just the binary representation of s.
 *
 * We process bits from MSB -> LSB.
 *
 * If a bit is NOT allowed by m, we cannot leave anything there, so every copy
 * must be split into two copies of the next lower bit.
 *
 * If a bit IS allowed, we may "consume" at most lim copies there, because
 * across lim numbers, each bit position can only appear once per number.
 *
 * Any leftover copies must also be split downward.
 */
bool can(ll s, ll m, ll lim) {

    // need = number of copies of the current bit that still need to be placed.
    ll need = 0;

    // Process high -> low.
    for (int bit = 60; bit >= 0; bit--) {

        // Moving one level down.
        //
        // One 2^bit becomes two 2^(bit-1),
        // so every remaining copy doubles.
        need <<= 1;

        // If s originally has this bit,
        // we need one more copy of this power.
        if ((s >> bit) & 1LL)
            need++;

        // If m allows this bit,
        // we can place at most lim copies here.
        if ((m >> bit) & 1LL)
            need -= min(need, lim);

        // Whatever remains must continue downward.
    }

    // Everything successfully placed.
    return need == 0;
}

void solve() {

    ll s, m;
    cin >> s >> m;

    /**
     * Original idea:
     *
     * if the (i-1)th bit of m is 1,
     * then 2^i may appear inside a valid number.
     *
     * I originally tried greedy on these powers of two.
     *
     * That correctly identifies the usable bits,
     * but misses that:
     *
     * 1. each array element may combine MANY allowed bits
     * 2. higher bits may be split into lower bits
     *
     * Example:
     *
     * 8 = 4 + 4 = 2 + 2 + 2 + 2
     *
     * so greedy on powers alone is not optimal.
     */

    // First check if ANY solution exists.
    //
    // Huge limit = effectively unlimited copies of each bit.
    //
    // If this fails,
    // some forbidden bit can never be pushed onto an allowed bit.
    if (!can(s, m, (1LL << 60))) {
        cout << -1 << '\n';
        return;
    }

    /**
     * Binary search.
     *
     * We are searching for:
     *
     * minimum number of array elements.
     *
     * Observation:
     *
     * If lim numbers work,
     * then lim+1 numbers also work
     * (just append a zero).
     *
     * Therefore:
     *
     * false false false true true true
     *
     * Binary search for first true.
     */

    ll lo = 1;
    ll hi = (1LL << 60);

    while (lo <= hi) {

        ll mid = lo + (hi - lo) / 2;

        if (can(s, m, mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    cout << lo << '\n';
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t; cin >> t;
     
    while (t--) { 
        solve();
    }

    return 0; 
}
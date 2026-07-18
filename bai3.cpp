// BAI 3: Loai bo cac dau ngoac thua (chi co bien hoa va cac phep + -)
#include <bits/stdc++.h>
using namespace std;

static string s;
static size_t p;

struct Expr;
using PE = shared_ptr<Expr>;
struct Term { bool isVar; char var; PE inner; };
struct Expr { vector<char> ops; vector<Term> terms; };

PE parseExpr();

Term parseTerm() {
    Term t; t.isVar = true; t.var = 0; t.inner = nullptr;
    if (p < s.size() && s[p] == '(') {
        ++p;
        t.isVar = false;
        t.inner = parseExpr();
        if (p < s.size() && s[p] == ')') ++p;
    } else if (p < s.size()) {
        t.var = s[p++];
    }
    return t;
}

PE parseExpr() {
    PE e = make_shared<Expr>();
    char op = '+';
    if (p < s.size() && (s[p] == '+' || s[p] == '-')) op = s[p++];
    e->ops.push_back(op);
    e->terms.push_back(parseTerm());
    while (p < s.size() && (s[p] == '+' || s[p] == '-')) {
        e->ops.push_back(s[p++]);
        e->terms.push_back(parseTerm());
    }
    return e;
}

// sau khi rut gon, bieu thuc co nhieu hon 1 hang tu o muc ngoai cung?
bool multi(const PE &e) {
    if (e->terms.size() > 1) return true;
    if (e->terms[0].isVar) return false;
    return multi(e->terms[0].inner);
}

string render(const PE &e) {
    string res;
    for (size_t i = 0; i < e->terms.size(); ++i) {
        char op = e->ops[i];
        if (i > 0) res += op;
        else if (op == '-') res += '-';

        const Term &t = e->terms[i];
        if (t.isVar) res += t.var;
        else {
            string in = render(t.inner);
            // chi giu ngoac khi dung sau dau '-' va ben trong con phep toan
            if (op == '-' && multi(t.inner)) { res += '('; res += in; res += ')'; }
            else res += in;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (m--) {
        string line;
        if (!getline(cin, line)) break;
        s.clear();
        for (char c : line) if (!isspace((unsigned char)c)) s += c;
        if (s.empty()) { cout << '\n'; continue; }
        p = 0;
        cout << render(parseExpr()) << '\n';
    }
    return 0;
}

#include "Validator.h"
#include <regex>
#include <stdexcept>

// ── Date ─────────────────────────────────────────────────────────────────────
// Format: DD/MM/AAAA  — validates format AND calendar logic

bool Validator::isDateValid(const string& date) {
    // Format check
    static const regex fmt(R"(^(\d{2})/(\d{2})/(\d{4})$)");
    smatch m;
    if (!regex_match(date, m, fmt)) return false;

    int day   = stoi(m[1]);
    int month = stoi(m[2]);
    int year  = stoi(m[3]);

    if (year  < 1900 || year  > 2100) return false;
    if (month < 1    || month > 12  ) return false;
    if (day   < 1                   ) return false;

    // Days per month
    static const int daysInMonth[] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int maxDay = daysInMonth[month];

    // Leap year check for February
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leap) maxDay = 29;
    }

    return day <= maxDay;
}

// ── Licença ───────────────────────────────────────────────────────────────────
// 3-20 chars, alphanumeric and hyphens allowed (e.g. LIC-0001, ABC123)

bool Validator::isLicencaValid(const string& licenca) {
    if (licenca.size() < 3 || licenca.size() > 20) return false;
    static const regex fmt(R"(^[A-Za-z0-9\-]+$)");
    return regex_match(licenca, fmt);
}

// ── Matrícula ─────────────────────────────────────────────────────────────────
// 6-8 chars, alphanumeric and hyphens (e.g. AA-00-AA, AB-12-CD)

bool Validator::isMatriculaValid(const string& matricula) {
    if (matricula.size() < 6 || matricula.size() > 10) return false;
    static const regex fmt(R"(^[A-Za-z0-9\-]+$)");
    return regex_match(matricula, fmt);
}

// ── Ano ───────────────────────────────────────────────────────────────────────

bool Validator::isAnoValid(int ano) {
    return ano >= 1900 && ano <= 2100;
}

// ── Nome ──────────────────────────────────────────────────────────────────────
// At least 2 chars, letters and spaces only

bool Validator::isNomeValid(const string& nome) {
    if (nome.size() < 2) return false;
    static const regex fmt(R"(^[A-Za-zÀ-ÿ\s\-']+$)");
    return regex_match(nome, fmt);
}

// ── País ──────────────────────────────────────────────────────────────────────

bool Validator::isPaisValid(const string& pais) {
    if (pais.size() < 2) return false;
    static const regex fmt(R"(^[A-Za-zÀ-ÿ\s\-]+$)");
    return regex_match(pais, fmt);
}

// ── Posição ───────────────────────────────────────────────────────────────────

bool Validator::isPosicaoValid(int posicao) {
    return posicao >= 1;
}

// ── Tempo ─────────────────────────────────────────────────────────────────────

bool Validator::isTempoValid(float tempo) {
    return tempo > 0.0f;
}

// ── Error messages ────────────────────────────────────────────────────────────

string Validator::dateError() {
    return "Data invalida. Use o formato DD/MM/AAAA (ex: 25/03/1990).";
}
string Validator::licencaError() {
    return "Licenca invalida. Use 3-20 caracteres alfanumericos ou hifens (ex: LIC-0001).";
}
string Validator::matriculaError() {
    return "Matricula invalida. Use 6-10 caracteres alfanumericos ou hifens (ex: AA-00-AA).";
}
string Validator::anoError() {
    return "Ano invalido. Introduza um ano entre 1900 e 2100.";
}
string Validator::nomeError() {
    return "Nome invalido. Minimo 2 caracteres, apenas letras e espacos.";
}
string Validator::paisError() {
    return "Pais invalido. Minimo 2 caracteres, apenas letras.";
}
string Validator::posicaoError() {
    return "Posicao invalida. Deve ser >= 1.";
}
string Validator::tempoError() {
    return "Tempo invalido. Deve ser um valor positivo em segundos.";
}
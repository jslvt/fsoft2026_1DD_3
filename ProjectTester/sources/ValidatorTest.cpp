#include <gtest/gtest.h>
#include "Validator.h"

// ── Date ──────────────────────────────────────────────────────────────────────

TEST(ValidatorDate, ValidDates) {
    EXPECT_TRUE(Validator::isDateValid("01/01/2000"));
    EXPECT_TRUE(Validator::isDateValid("29/02/2000")); // leap year
    EXPECT_TRUE(Validator::isDateValid("31/12/1999"));
    EXPECT_TRUE(Validator::isDateValid("28/02/1999")); // non-leap Feb
}

TEST(ValidatorDate, InvalidDates) {
    EXPECT_FALSE(Validator::isDateValid("29/02/1999")); // not a leap year
    EXPECT_FALSE(Validator::isDateValid("32/01/2000")); // day out of range
    EXPECT_FALSE(Validator::isDateValid("00/01/2000")); // day zero
    EXPECT_FALSE(Validator::isDateValid("01/13/2000")); // month out of range
    EXPECT_FALSE(Validator::isDateValid("2000-01-01")); // wrong format
    EXPECT_FALSE(Validator::isDateValid(""));
    EXPECT_FALSE(Validator::isDateValid("abc/de/fghi"));
    EXPECT_FALSE(Validator::isDateValid("01/01/1800")); // year too old
}

// ── Licença ───────────────────────────────────────────────────────────────────

TEST(ValidatorLicenca, Valid) {
    EXPECT_TRUE(Validator::isLicencaValid("LIC-0001"));
    EXPECT_TRUE(Validator::isLicencaValid("ABC123"));
    EXPECT_TRUE(Validator::isLicencaValid("A1B"));
}

TEST(ValidatorLicenca, Invalid) {
    EXPECT_FALSE(Validator::isLicencaValid("AB"));       // too short
    EXPECT_FALSE(Validator::isLicencaValid("LIC 001"));  // space
    EXPECT_FALSE(Validator::isLicencaValid(""));
}

// ── Matrícula ─────────────────────────────────────────────────────────────────

TEST(ValidatorMatricula, Valid) {
    EXPECT_TRUE(Validator::isMatriculaValid("AA-00-AA"));
    EXPECT_TRUE(Validator::isMatriculaValid("AB1234"));
}

TEST(ValidatorMatricula, Invalid) {
    EXPECT_FALSE(Validator::isMatriculaValid("AB"));      // too short
    EXPECT_FALSE(Validator::isMatriculaValid("AA 00 AA")); // spaces
    EXPECT_FALSE(Validator::isMatriculaValid(""));
}

// ── Ano ───────────────────────────────────────────────────────────────────────

TEST(ValidatorAno, Valid) {
    EXPECT_TRUE(Validator::isAnoValid(1900));
    EXPECT_TRUE(Validator::isAnoValid(2024));
    EXPECT_TRUE(Validator::isAnoValid(2100));
}

TEST(ValidatorAno, Invalid) {
    EXPECT_FALSE(Validator::isAnoValid(1899));
    EXPECT_FALSE(Validator::isAnoValid(2101));
    EXPECT_FALSE(Validator::isAnoValid(0));
}

// ── Nome ──────────────────────────────────────────────────────────────────────

TEST(ValidatorNome, Valid) {
    EXPECT_TRUE(Validator::isNomeValid("Lewis Hamilton"));
    EXPECT_TRUE(Validator::isNomeValid("Ana"));
}

TEST(ValidatorNome, Invalid) {
    EXPECT_FALSE(Validator::isNomeValid("A"));      // too short
    EXPECT_FALSE(Validator::isNomeValid("Lewis1")); // has digit
    EXPECT_FALSE(Validator::isNomeValid(""));
}

// ── País ──────────────────────────────────────────────────────────────────────

TEST(ValidatorPais, Valid) {
    EXPECT_TRUE(Validator::isPaisValid("Portugal"));
    EXPECT_TRUE(Validator::isPaisValid("UK"));
}

TEST(ValidatorPais, Invalid) {
    EXPECT_FALSE(Validator::isPaisValid("A"));
    EXPECT_FALSE(Validator::isPaisValid(""));
}

// ── Posição / Tempo ───────────────────────────────────────────────────────────

TEST(ValidatorPosicao, Valid)   { EXPECT_TRUE(Validator::isPosicaoValid(1));  }
TEST(ValidatorPosicao, Invalid) { EXPECT_FALSE(Validator::isPosicaoValid(0)); }

TEST(ValidatorTempo, Valid)   { EXPECT_TRUE(Validator::isTempoValid(5432.5f));  }
TEST(ValidatorTempo, Invalid) { EXPECT_FALSE(Validator::isTempoValid(0.0f));    }

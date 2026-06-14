#include <gtest/gtest.h>
#include "Piloto.h"
#include "PilotoContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"

// ── Piloto construction ───────────────────────────────────────────────────────

TEST(PilotoConstruction, ValidPiloto) {
    EXPECT_NO_THROW(Piloto(1, "Lewis Hamilton", "07/01/1985", "LIC-0001"));
}

TEST(PilotoConstruction, InvalidId) {
    EXPECT_THROW(Piloto(0, "Lewis Hamilton", "07/01/1985", "LIC-0001"),
                 InvalidDataException);
}

TEST(PilotoConstruction, NomeTooShort) {
    EXPECT_THROW(Piloto(1, "A", "07/01/1985", "LIC-0001"),
                 InvalidDataException);
}

TEST(PilotoConstruction, NomeWithDigits) {
    EXPECT_THROW(Piloto(1, "Lewis1", "07/01/1985", "LIC-0001"),
                 InvalidDataException);
}

TEST(PilotoConstruction, InvalidDate) {
    EXPECT_THROW(Piloto(1, "Lewis Hamilton", "32/01/1985", "LIC-0001"),
                 InvalidDataException);
}

TEST(PilotoConstruction, InvalidDateFormat) {
    EXPECT_THROW(Piloto(1, "Lewis Hamilton", "1985-01-07", "LIC-0001"),
                 InvalidDataException);
}

TEST(PilotoConstruction, LicencaTooShort) {
    EXPECT_THROW(Piloto(1, "Lewis Hamilton", "07/01/1985", "AB"),
                 InvalidDataException);
}

// ── Piloto getters ────────────────────────────────────────────────────────────

class PilotoGettersFixture : public ::testing::Test {
protected:
    Piloto p{1, "Lewis Hamilton", "07/01/1985", "LIC-0001"};
};

TEST_F(PilotoGettersFixture, GetId)       { EXPECT_EQ(1,                     p.getId());       }
TEST_F(PilotoGettersFixture, GetNome)     { EXPECT_EQ("Lewis Hamilton",       p.getNome());     }
TEST_F(PilotoGettersFixture, GetDataNasc) { EXPECT_EQ("07/01/1985",           p.getDataNasc()); }
TEST_F(PilotoGettersFixture, GetLicenca)  { EXPECT_EQ("LIC-0001",             p.getNLicenca()); }
TEST_F(PilotoGettersFixture, OpEqId)      { EXPECT_TRUE(p == 1);                                }
TEST_F(PilotoGettersFixture, OpEqLicenca) { EXPECT_TRUE(p == std::string("LIC-0001"));          }

// ── PilotoContainer ───────────────────────────────────────────────────────────

class PilotoContainerFixture : public ::testing::Test {
protected:
    PilotoContainer c;
    void SetUp() override {
        c.add("Lewis Hamilton", "07/01/1985", "LIC-0001");
        c.add("Max Verstappen", "30/09/1997", "LIC-0002");
    }
};

TEST_F(PilotoContainerFixture, AddValid) {
    EXPECT_NO_THROW(c.add("Carlos Sainz", "01/09/1994", "LIC-0003"));
}

TEST_F(PilotoContainerFixture, AddDuplicateLicenca) {
    EXPECT_THROW(c.add("Fake", "01/01/2000", "LIC-0001"),
                 DuplicatedDataException);
}

TEST_F(PilotoContainerFixture, GetById) {
    Piloto* p = c.get(1);
    ASSERT_NE(nullptr, p);
    EXPECT_EQ("Lewis Hamilton", p->getNome());
}

TEST_F(PilotoContainerFixture, GetNonExistent) {
    EXPECT_THROW(c.get(999), NoDataException);
}

TEST_F(PilotoContainerFixture, GetAllSize) {
    EXPECT_EQ(2, (int)c.getAll().size());
}

TEST_F(PilotoContainerFixture, Remove) {
    c.remove(1);
    EXPECT_EQ(1, (int)c.getAll().size());
}

TEST_F(PilotoContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(999), NoDataException);
}

TEST_F(PilotoContainerFixture, Update) {
    c.update(1, "Carlos Sainz", "01/09/1994", "LIC-0003");
    EXPECT_EQ("Carlos Sainz", c.get(1)->getNome());
}

TEST_F(PilotoContainerFixture, UpdateNonExistent) {
    EXPECT_THROW(c.update(999, "Nobody", "01/01/2000", "LIC-9999"),
                 NoDataException);
}

TEST_F(PilotoContainerFixture, NextIdIncrements) {
    c.add("Fernando Alonso", "29/07/1981", "LIC-0004");
    EXPECT_EQ(3, c.get(3)->getId());
}

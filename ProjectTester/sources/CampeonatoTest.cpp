#include <gtest/gtest.h>
#include "Campeonato.h"
#include "CampeonatoContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"

TEST(CampeonatoConstruction, Valid) {
    EXPECT_NO_THROW(Campeonato(1, "Formula 1 2024", 2024));
}

TEST(CampeonatoConstruction, InvalidId) {
    EXPECT_THROW(Campeonato(0, "Formula 1 2024", 2024), InvalidDataException);
}

TEST(CampeonatoConstruction, NomeTooShort) {
    EXPECT_THROW(Campeonato(1, "A", 2024), InvalidDataException);
}

TEST(CampeonatoConstruction, AnoOutOfRange) {
    EXPECT_THROW(Campeonato(1, "Formula 1", 1800), InvalidDataException);
}

class CampeonatoAssocFixture : public ::testing::Test {
protected:
    Campeonato camp{1, "Formula 1 2024", 2024};
};

TEST_F(CampeonatoAssocFixture, AddCorrida) {
    EXPECT_NO_THROW(camp.addCorrida(1));
    EXPECT_TRUE(camp.hasCorrida(1));
}

TEST_F(CampeonatoAssocFixture, AddCorridaDuplicate) {
    camp.addCorrida(1);
    EXPECT_THROW(camp.addCorrida(1), DuplicatedDataException);
}

TEST_F(CampeonatoAssocFixture, RemoveCorrida) {
    camp.addCorrida(1);
    camp.removeCorrida(1);
    EXPECT_FALSE(camp.hasCorrida(1));
}

TEST_F(CampeonatoAssocFixture, RemoveCorridaNotIn) {
    EXPECT_THROW(camp.removeCorrida(99), NoDataException);
}

TEST_F(CampeonatoAssocFixture, AddEquipa) {
    EXPECT_NO_THROW(camp.addEquipa(10));
    EXPECT_TRUE(camp.hasEquipa(10));
}

TEST_F(CampeonatoAssocFixture, AddEquipaDuplicate) {
    camp.addEquipa(10);
    EXPECT_THROW(camp.addEquipa(10), DuplicatedDataException);
}

TEST_F(CampeonatoAssocFixture, RemoveEquipa) {
    camp.addEquipa(10);
    camp.removeEquipa(10);
    EXPECT_FALSE(camp.hasEquipa(10));
}

TEST_F(CampeonatoAssocFixture, RemoveEquipaNotIn) {
    EXPECT_THROW(camp.removeEquipa(99), NoDataException);
}

class CampeonatoContainerFixture : public ::testing::Test {
protected:
    CampeonatoContainer c;
    void SetUp() override {
        c.add("Formula 1 2024", 2024);
        c.add("Formula 2 2024", 2024);
    }
};

TEST_F(CampeonatoContainerFixture, GetAll) {
    EXPECT_EQ(2, (int)c.getAll().size());
}

TEST_F(CampeonatoContainerFixture, GetById) {
    EXPECT_EQ("Formula 1 2024", c.get(1)->getNome());
}

TEST_F(CampeonatoContainerFixture, GetNonExistent) {
    EXPECT_THROW(c.get(999), NoDataException);
}

TEST_F(CampeonatoContainerFixture, AddCorrida) {
    c.addCorrida(1, 5);
    EXPECT_TRUE(c.get(1)->hasCorrida(5));
}

TEST_F(CampeonatoContainerFixture, AddEquipa) {
    c.addEquipa(1, 10);
    EXPECT_TRUE(c.get(1)->hasEquipa(10));
}

TEST_F(CampeonatoContainerFixture, Remove) {
    c.remove(2);
    EXPECT_EQ(1, (int)c.getAll().size());
}

TEST_F(CampeonatoContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(999), NoDataException);
}

TEST_F(CampeonatoContainerFixture, Update) {
    c.update(1, "Formula 1 2025", 2025);
    EXPECT_EQ("Formula 1 2025", c.get(1)->getNome());
    EXPECT_EQ(2025, c.get(1)->getAno());
}

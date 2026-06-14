#include <gtest/gtest.h>
#include "Equipa.h"
#include "EquipaContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"

// ── Equipa construction ───────────────────────────────────────────────────────

TEST(EquipaConstruction, Valid) {
    EXPECT_NO_THROW(Equipa(1, "Red Bull Racing", "Austria"));
}

TEST(EquipaConstruction, InvalidId) {
    EXPECT_THROW(Equipa(0, "Red Bull Racing", "Austria"), InvalidDataException);
}

TEST(EquipaConstruction, NomeTooShort) {
    EXPECT_THROW(Equipa(1, "A", "Austria"), InvalidDataException);
}

TEST(EquipaConstruction, PaisEmpty) {
    EXPECT_THROW(Equipa(1, "Red Bull Racing", ""), InvalidDataException);
}

// ── Equipa pilot association ──────────────────────────────────────────────────

class EquipaPilotoFixture : public ::testing::Test {
protected:
    Equipa e{1, "Red Bull Racing", "Austria"};
};

TEST_F(EquipaPilotoFixture, AddPiloto) {
    EXPECT_NO_THROW(e.addPiloto(1));
    EXPECT_TRUE(e.hasPiloto(1));
}

TEST_F(EquipaPilotoFixture, AddPilotoDuplicate) {
    e.addPiloto(1);
    EXPECT_THROW(e.addPiloto(1), DuplicatedDataException);
}

TEST_F(EquipaPilotoFixture, RemovePiloto) {
    e.addPiloto(1);
    EXPECT_NO_THROW(e.removePiloto(1));
    EXPECT_FALSE(e.hasPiloto(1));
}

TEST_F(EquipaPilotoFixture, RemovePilotoNotInEquipa) {
    EXPECT_THROW(e.removePiloto(99), NoDataException);
}

TEST_F(EquipaPilotoFixture, PilotoIdsSize) {
    e.addPiloto(1);
    e.addPiloto(2);
    EXPECT_EQ(2, (int)e.getPilotoIds().size());
}

// ── EquipaContainer ───────────────────────────────────────────────────────────

class EquipaContainerFixture : public ::testing::Test {
protected:
    EquipaContainer c;
    void SetUp() override {
        c.add("Red Bull Racing", "Austria");
        c.add("Ferrari", "Italy");
    }
};

TEST_F(EquipaContainerFixture, AddDuplicate) {
    EXPECT_THROW(c.add("Red Bull Racing", "Austria"), DuplicatedDataException);
}

TEST_F(EquipaContainerFixture, GetAll) {
    EXPECT_EQ(2, (int)c.getAll().size());
}

TEST_F(EquipaContainerFixture, GetById) {
    EXPECT_EQ("Red Bull Racing", c.get(1)->getNome());
}

TEST_F(EquipaContainerFixture, GetNonExistent) {
    EXPECT_THROW(c.get(999), NoDataException);
}

TEST_F(EquipaContainerFixture, FindEquipaByPiloto) {
    c.addPiloto(1, 10);
    Equipa* found = c.findEquipaByPiloto(10);
    ASSERT_NE(nullptr, found);
    EXPECT_EQ("Red Bull Racing", found->getNome());
}

TEST_F(EquipaContainerFixture, FindEquipaByPilotoNotFound) {
    EXPECT_EQ(nullptr, c.findEquipaByPiloto(999));
}

TEST_F(EquipaContainerFixture, Remove) {
    c.remove(2);
    EXPECT_EQ(1, (int)c.getAll().size());
}

TEST_F(EquipaContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(999), NoDataException);
}

TEST_F(EquipaContainerFixture, Update) {
    c.update(1, "Oracle Red Bull", "Austria");
    EXPECT_EQ("Oracle Red Bull", c.get(1)->getNome());
}

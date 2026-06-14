#include <gtest/gtest.h>
#include "Veiculo.h"
#include "VeiculoContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"

TEST(VeiculoConstruction, Valid) {
    EXPECT_NO_THROW(Veiculo(1, "Ferrari F1-75", "AA-00-AA", 2022));
}

TEST(VeiculoConstruction, InvalidId) {
    EXPECT_THROW(Veiculo(0, "Ferrari F1-75", "AA-00-AA", 2022), InvalidDataException);
}

TEST(VeiculoConstruction, InvalidMatricula) {
    EXPECT_THROW(Veiculo(1, "Ferrari F1-75", "AB", 2022), InvalidDataException);
}

TEST(VeiculoConstruction, InvalidAno) {
    EXPECT_THROW(Veiculo(1, "Ferrari F1-75", "AA-00-AA", 1800), InvalidDataException);
}

class VeiculoGettersFixture : public ::testing::Test {
protected:
    Veiculo v{1, "Ferrari F1-75", "AA-00-AA", 2022, 0};
};

TEST_F(VeiculoGettersFixture, GetId)        { EXPECT_EQ(1,             v.getId());        }
TEST_F(VeiculoGettersFixture, GetModelo)    { EXPECT_EQ("Ferrari F1-75", v.getModelo());  }
TEST_F(VeiculoGettersFixture, GetMatricula) { EXPECT_EQ("AA-00-AA",    v.getMatricula()); }
TEST_F(VeiculoGettersFixture, GetAno)       { EXPECT_EQ(2022,          v.getAno());       }
TEST_F(VeiculoGettersFixture, GetEquipaId)  { EXPECT_EQ(0,             v.getEquipaId());  }
TEST_F(VeiculoGettersFixture, SetEquipaId)  { v.setEquipaId(5); EXPECT_EQ(5, v.getEquipaId()); }

class VeiculoContainerFixture : public ::testing::Test {
protected:
    VeiculoContainer c;
    void SetUp() override {
        c.add("Ferrari F1-75", "AA-00-AA", 2022);
        c.add("Red Bull RB18", "BB-11-BB", 2022);
    }
};

TEST_F(VeiculoContainerFixture, AddDuplicateMatricula) {
    EXPECT_THROW(c.add("Ferrari F1-75", "AA-00-AA", 2023), DuplicatedDataException);
}

TEST_F(VeiculoContainerFixture, GetAll) {
    EXPECT_EQ(2, (int)c.getAll().size());
}

TEST_F(VeiculoContainerFixture, GetById) {
    EXPECT_EQ("Ferrari F1-75", c.get(1)->getModelo());
}

TEST_F(VeiculoContainerFixture, GetNonExistent) {
    EXPECT_THROW(c.get(999), NoDataException);
}

TEST_F(VeiculoContainerFixture, AssignEquipa) {
    c.assignEquipa(1, 10);
    EXPECT_EQ(10, c.get(1)->getEquipaId());
}

TEST_F(VeiculoContainerFixture, GetByEquipa) {
    c.assignEquipa(1, 10);
    EXPECT_EQ(1, (int)c.getByEquipa(10).size());
}

TEST_F(VeiculoContainerFixture, UnassignEquipa) {
    c.assignEquipa(1, 10);
    c.unassignEquipa(1);
    EXPECT_EQ(0, c.get(1)->getEquipaId());
}

TEST_F(VeiculoContainerFixture, Remove) {
    c.remove(2);
    EXPECT_EQ(1, (int)c.getAll().size());
}

TEST_F(VeiculoContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(999), NoDataException);
}

TEST_F(VeiculoContainerFixture, Update) {
    c.update(1, "Ferrari F1-75", "AA-00-AA", 2023);
    EXPECT_EQ(2023, c.get(1)->getAno());
}

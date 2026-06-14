#include <gtest/gtest.h>
#include "Corrida.h"
#include "CorridaContainer.h"
#include "InvalidDataException.h"
#include "NoDataException.h"

TEST(CorridaConstruction, ValidNormal) {
    EXPECT_NO_THROW(Corrida(1, "GP Portugal", "Algarve", "23/04/2024", TipoCorrida::NORMAL));
}

TEST(CorridaConstruction, ValidCampeonato) {
    EXPECT_NO_THROW(Corrida(1, "GP Portugal", "Algarve", "23/04/2024", TipoCorrida::CAMPEONATO, 1));
}

TEST(CorridaConstruction, InvalidId) {
    EXPECT_THROW(Corrida(0, "GP Portugal", "Algarve", "23/04/2024", TipoCorrida::NORMAL),
                 InvalidDataException);
}

TEST(CorridaConstruction, NomeTooShort) {
    EXPECT_THROW(Corrida(1, "A", "Algarve", "23/04/2024", TipoCorrida::NORMAL),
                 InvalidDataException);
}

TEST(CorridaConstruction, InvalidDate) {
    EXPECT_THROW(Corrida(1, "GP Portugal", "Algarve", "99/99/9999", TipoCorrida::NORMAL),
                 InvalidDataException);
}

class CorridaGettersFixture : public ::testing::Test {
protected:
    Corrida cr{1, "GP Portugal", "Algarve", "23/04/2024", TipoCorrida::CAMPEONATO, 2};
};

TEST_F(CorridaGettersFixture, GetId)           { EXPECT_EQ(1,            cr.getId());           }
TEST_F(CorridaGettersFixture, GetNome)         { EXPECT_EQ("GP Portugal", cr.getNome());         }
TEST_F(CorridaGettersFixture, GetCircuito)     { EXPECT_EQ("Algarve",     cr.getCircuito());     }
TEST_F(CorridaGettersFixture, GetData)         { EXPECT_EQ("23/04/2024",  cr.getData());         }
TEST_F(CorridaGettersFixture, GetCampeonatoId) { EXPECT_EQ(2,             cr.getCampeonatoId()); }
TEST_F(CorridaGettersFixture, GetTipoStr)      { EXPECT_EQ("Campeonato",  cr.getTipoStr());      }
TEST_F(CorridaGettersFixture, GetTipo)         { EXPECT_EQ(TipoCorrida::CAMPEONATO, cr.getTipo()); }

class CorridaContainerFixture : public ::testing::Test {
protected:
    CorridaContainer c;
    void SetUp() override {
        c.add("GP Portugal", "Algarve", "23/04/2024", TipoCorrida::NORMAL);
        c.add("GP Monza",    "Monza",   "01/09/2024", TipoCorrida::CAMPEONATO, 1);
    }
};

TEST_F(CorridaContainerFixture, GetAll) {
    EXPECT_EQ(2, (int)c.getAll().size());
}

TEST_F(CorridaContainerFixture, GetById) {
    EXPECT_EQ("GP Portugal", c.get(1)->getNome());
}

TEST_F(CorridaContainerFixture, GetNonExistent) {
    EXPECT_THROW(c.get(999), NoDataException);
}

TEST_F(CorridaContainerFixture, GetByCampeonato) {
    EXPECT_EQ(1, (int)c.getByCampeonato(1).size());
    EXPECT_EQ(0, (int)c.getByCampeonato(99).size());
}

TEST_F(CorridaContainerFixture, AssignCampeonato) {
    c.assignCampeonato(1, 5);
    EXPECT_EQ(5, c.get(1)->getCampeonatoId());
}

TEST_F(CorridaContainerFixture, UnassignCampeonato) {
    c.assignCampeonato(1, 5);
    c.unassignCampeonato(1);
    EXPECT_EQ(0, c.get(1)->getCampeonatoId());
}

TEST_F(CorridaContainerFixture, Remove) {
    c.remove(2);
    EXPECT_EQ(1, (int)c.getAll().size());
}

TEST_F(CorridaContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(999), NoDataException);
}

TEST_F(CorridaContainerFixture, Update) {
    c.update(1, "GP Lisboa", "Lisboa", "24/04/2024", TipoCorrida::CAMPEONATO);
    EXPECT_EQ("GP Lisboa", c.get(1)->getNome());
}

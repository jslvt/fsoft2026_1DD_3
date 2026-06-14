#include <gtest/gtest.h>
#include "Participacao.h"
#include "ParticipacaoContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"

TEST(ParticipacaoConstruction, Valid) {
    EXPECT_NO_THROW(Participacao(1, 1, 1, 5432.5f, 25));
}

TEST(ParticipacaoConstruction, InvalidPilotoId) {
    EXPECT_THROW(Participacao(0, 1, 1, 5432.5f), InvalidDataException);
}

TEST(ParticipacaoConstruction, InvalidCorridaId) {
    EXPECT_THROW(Participacao(1, 0, 1, 5432.5f), InvalidDataException);
}

TEST(ParticipacaoConstruction, InvalidPosicao) {
    EXPECT_THROW(Participacao(1, 1, 0, 5432.5f), InvalidDataException);
}

TEST(ParticipacaoConstruction, InvalidTempo) {
    EXPECT_THROW(Participacao(1, 1, 1, 0.0f), InvalidDataException);
}

class ParticipacaoContainerFixture : public ::testing::Test {
protected:
    ParticipacaoContainer c;
    void SetUp() override {
        c.add(1, 1, 1, 5400.0f, true);   // pos 1, campeonato → 25 pts
        c.add(2, 1, 2, 5410.0f, false);  // pos 2, normal    → 0 pts
        c.add(3, 2, 1, 3600.0f, true);   // pos 1, campeonato → 25 pts
        c.add(4, 2, 2, 3610.0f, true);   // pos 2, campeonato → 18 pts
        c.add(5, 2, 3, 3620.0f, true);   // pos 3 → 15 pts
        c.add(6, 2, 10, 3700.0f, true);  // pos 10 → 1 pt
        c.add(7, 2, 11, 3710.0f, true);  // pos 11 → 0 pts
    }
};

TEST_F(ParticipacaoContainerFixture, F1PointsPos1Campeonato) {
    EXPECT_EQ(25, c.get(1, 1)->getPontos());
}

TEST_F(ParticipacaoContainerFixture, F1PointsNormalRace) {
    EXPECT_EQ(0, c.get(2, 1)->getPontos());
}

TEST_F(ParticipacaoContainerFixture, F1PointsPos2)  { EXPECT_EQ(18, c.get(4, 2)->getPontos()); }
TEST_F(ParticipacaoContainerFixture, F1PointsPos3)  { EXPECT_EQ(15, c.get(5, 2)->getPontos()); }
TEST_F(ParticipacaoContainerFixture, F1PointsPos10) { EXPECT_EQ(1,  c.get(6, 2)->getPontos()); }
TEST_F(ParticipacaoContainerFixture, F1PointsPos11) { EXPECT_EQ(0,  c.get(7, 2)->getPontos()); }

TEST_F(ParticipacaoContainerFixture, AddDuplicate) {
    EXPECT_THROW(c.add(1, 1, 2, 5420.0f, true), DuplicatedDataException);
}

TEST_F(ParticipacaoContainerFixture, GetByCorrida) {
    auto result = c.getByCorrida(2);
    EXPECT_EQ(5, (int)result.size());
    EXPECT_EQ(1, result.front()->getPosicao());  // sorted ascending
    EXPECT_EQ(11, result.back()->getPosicao());
}

TEST_F(ParticipacaoContainerFixture, GetByPiloto) {
    EXPECT_EQ(1, (int)c.getByPiloto(1).size());
}

TEST_F(ParticipacaoContainerFixture, HasPiloto) {
    EXPECT_TRUE(c.hasPiloto(1));
    EXPECT_FALSE(c.hasPiloto(99));
}

TEST_F(ParticipacaoContainerFixture, HasCorrida) {
    EXPECT_TRUE(c.hasCorrida(1));
    EXPECT_FALSE(c.hasCorrida(99));
}

TEST_F(ParticipacaoContainerFixture, Remove) {
    c.remove(1, 1);
    EXPECT_FALSE(c.hasPiloto(1));
}

TEST_F(ParticipacaoContainerFixture, RemoveNonExistent) {
    EXPECT_THROW(c.remove(99, 99), NoDataException);
}

TEST_F(ParticipacaoContainerFixture, UpdateRecalculatesPontos) {
    c.update(3, 2, 2, 3605.0f, true);  // change pos to 2 → 18 pts
    EXPECT_EQ(18, c.get(3, 2)->getPontos());
}

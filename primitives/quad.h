#pragma once

#include "primitive.h"
#include "triangle.h"

namespace graphics {

/**
 * @details Основной задачей было правильно выстроить иерархию наследования
 * для квадрата и прямоугольника.
 * Квадрат есть частный случай прямоугольника - в математике, но с не с точки зрения ООП.
 * Как правило, производный класс должен расширять базовый класс, но если мы сделаем иерархию
 * Recatangle is a Quad, тогда получается что производный не расширяет, а наоборот сужает функционал
 * по очевидным причинам. Следовательно, более прваильным путем будет след иерархия -
 * Quad is a Rectangle. Теперь все вроде бы верно, в плане того что производный класс расширяет базовый,
 * а не наоборот как в предыдущем способе. Но это способ тоже не решен недостатков.
 * Пример:
 *  Допустим что есть метод/функция doSomething(Quad &quad), в ней меняется сторона Quad,
 *  а затем вычисляется площадь. Т.к. принимает аргумент полиморфно туда можно переать экземпляры
 *  как Quad, так и Rectangle.
 *  В этом случае:
 *  1) doSomething(Quad &quad -> instance Quad):
 *          oldSideLen = quad.getSide()
 *          oldSquare = quad.square()
 *          quad.setSide(oldSideLen * 2)
 *          assert(quad.square() == oldSquare) -> True
 *
 *  2) doSomething(Quad &quad -> instance Rectangle):
 *          oldSideLen = quad.getSide()
 *          oldSquare = quad.square()
 *          quad.setSide(oldSideLen * 2)
 *          assert(quad.square() == oldSquare) -> False т.к. стороны у него будут разные
 *
 *  Это возможно надуманный пример, но все же могут быть более реалистичные примеры, где
 *  могут возникать подобные неприятности. Более того, в принципах подстановки Лисков сказано о
 *  том что, в местах где возможно использование полиморфного типа, при замене его на производный тип
 *  поведения и самое главное инварианты должны сохраняться. В примере 2) мы видим что
 *  сохранением инварианта у нас не все ясно, у прямоугольника две стороны разные, соответственно
 *  при изменении одной стороны мы получаем что плошщадь этой фигуры не удваивается, что мы
 *  ожидаем у квадрата и всех типов заявленных как квадраты(путем публичного наследования).
 *  Поэтому на мой взляд правильнее сделать их двумя
 *  разными иерархиями с общим предков Primitive.
 */
class Quad : public Primitive {
public:
    typedef util::PointF32 PointF32;
    static constexpr auto vertexesCapacity = Triangle::vertexesCapacity * 2;

    Quad() = default;
    Quad(const PointF32 &pos, float size);
    PrimitiveVertexes &getVertexes() override;
    virtual const PrimitiveVertexes &getVertexes() const;
    virtual std::string getFigureName() const;

private:
    std::vector<float> vertexes_;
};

} // namespace graphics
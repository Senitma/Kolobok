//#include "OptionForMove.h"
//#include "Field\Field.h"
//#include "Field\PathFinder.h"
//
//void OptionForMove::SetParent(Element * parent)
//{
//	OptionForOneStep::SetParent(parent);
//
//	x = parent->GetX();
//	y = parent->GetY();
//}
//
//void OptionForMove::Update()
//{
//	OptionForOneStep::Update();
//
//	if (this->moveType != MoveType::ToOneStep && this->points.size() > 1)
//	{
//		if (parent->GetLeft() == FieldPoint::ConvertToLeft(this->points.at(0)->GetX()) && 
//			parent->GetTop() == FieldPoint::ConvertToTop(this->points.at(0)->GetY()))
//		{
//			points.erase(0);
//			OptionForOneStep::MoveTo(points.at(0)->GetX(), points.at(0)->GetY());
//		}
//	}
//}
//bool OptionForMove::MoveTo(int x, int y)
//{
//	return this->MoveTo(this->moveType, x, y);
//}
//bool OptionForMove::MoveTo(MoveType type, int x, int y)
//{
//	if (type == MoveType::ToOneStep)
//	{
//		return OptionForOneStep::MoveTo(x, y);
//	}
//	else
//	{
//		int calcX = parent->GetX() - x;
//		int calcY = parent->GetY() - y;
//
//		// При движении в соседние клетки передаем управление в OptionForOneStep
//		if ((calcX * calcY == 0) && (calcX + calcY == -1 || calcX + calcY == 1))
//		{
//			return OptionForOneStep::MoveTo(x, y);
//		}
//		else if (calcX == 0 && calcY == 0)
//		{
//			return OptionForOneStep::MoveTo(x, y);
//		}
//		else
//		{
//			this->points = this->GeneratePath(type, x, y);
//
//			return OptionForOneStep::MoveTo(points.at(0)->GetX(), points.at(0)->GetY());
//		}
//	}
//}
//
//cocos2d::Vector<FieldPoint *> OptionForMove::GeneratePath(MoveType type, int x, int y)
//{
//	if (type == MoveType::ToLine)
//	{
//		return this->GenerateLinePath(x, y);
//	}
//	else if (type == MoveType::ToByPass)
//	{
//		return this->GenerateByPassPath(x, y);
//	}
//	else
//	{
//		// По умолчанию элемент идет по прямой
//		return this->GenerateLinePath(x, y);
//	}
//}
//cocos2d::Vector<FieldPoint *> OptionForMove::GenerateLinePath(int x, int y)
//{
//	cocos2d::Vector<FieldPoint *> pointList;
//	int stepX = parent->GetX() < x ? 1 : -1;
//	int stepY = parent->GetY() < y ? 1 : -1;
//	int calcX = parent->GetX();
//	int calcY = parent->GetY();
//
//	while (calcX != x)
//	{
//		calcX += stepX;
//		pointList.pushBack(new FieldPoint(calcX, calcY));
//	}
//	while (calcY != y)
//	{
//		calcY += stepY;
//		pointList.pushBack(new FieldPoint(calcX, calcY));
//	}
//
//	return pointList;
//}
//cocos2d::Vector<FieldPoint *> OptionForMove::GenerateByPassPath(int x, int y)
//{
//	auto map = Field::CreateBlockMap();
//
//	// Временное решение
//	std::vector<Axes> temp = PathFinder::MoveTo(map, Axes(parent->GetX(), parent->GetY()), Axes(x, y), true);
//	cocos2d::Vector<FieldPoint *> temp2 = cocos2d::Vector<FieldPoint *>();
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		temp2.pushBack(new FieldPoint(temp.at(i).GetX(), temp.at(i).GetY()));
//	}
//
//	return temp2;
//}
// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"��ɳ", "����", "±��", "�ٹ�","Ŵ��"});
	set_name( order[random(5)] + "����", ({ "zongzi", "zong zi" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ð�����������ӡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "�����");
	}
	 ::init_item();
}
int finish_eat()
{
	set_name("��Ҷ", ({"zong ye"}) );
	set("value", 1);
	set("long", "һ��ճ�ણ����滹����Ŵ�׵�����Ҷ��\n");
	return 1;
}	
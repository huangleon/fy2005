
inherit ITEM;
void create()
{
	string *name=({"��"});
	string *num = ({"��","��","��","��"});
	set_name( num[random(4)]+name[random(1)] , ({ "majiangpai tiao","majiangpai","tiao"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���µ������齫��\n");
		set("unit", "��");
		set("value", 10);
	}
	::init_item();
}


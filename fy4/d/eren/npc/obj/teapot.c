inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ջ����", ({ "tea pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����������װ�žջ��衣\n");
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 100);
	}

	set("liquid", ([
		"name": "�ջ���",
		"remaining": 100,
		"drunk_apply": 7,
	]) );
	::init_item();
}

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���߹�", ({ "poor pot", "pot" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������õ����߹ޣ���߻�װ�˰ˡ������ľơ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "��ƷŮ����",
		"remaining": 150,
		"drunk_apply": 30,
	]) );
	::init_item();
}

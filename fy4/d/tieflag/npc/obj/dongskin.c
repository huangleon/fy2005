inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({ "dongskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 1000);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "����",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
}
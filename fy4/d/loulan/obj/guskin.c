
inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("�ų���", ({ "old skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "һ��Ƥ�ƾƴ������װ�ðˡ������Ĺ��⺺�ӳ��ȵĹų��վơ�\n");
		set("unit", "��");
        	set("value", 5000);
		set("max_liquid", 45);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
        	"name": "�ų���",
        	"remaining": 45,
        	"drunk_apply": 10,
	]) );
	::init_item();
}
// water.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("����С��Ͱ", ({"water"}));
    set_weight(700);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("long", "������˪��\n");
	set("unit", "��");
	set("value", 0);
	set("max_liquid", 100);
    }

    set("liquid", ([
	"type": "water",
	"name": "Ʈ�Ŷ�����ˮ",
	"remaining": 100,
      ]));
    ::init_item();
}


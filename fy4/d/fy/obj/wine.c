// wine.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("�Ʊ�", ({"wine"}));
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
	"type": "alcohol",
	"name": "���ӵİ׾�",
	"remaining": 100,
	"drunk_apply": 5,
      ]) );
    ::init_item();
}

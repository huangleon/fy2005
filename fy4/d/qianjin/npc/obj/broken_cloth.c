
inherit ITEM;
void create()
{
	set_name("���Ƶ�Ů������", ({ "neiyi" , "����"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶ�Ů������\n");
		set("value", 1);
	}
}




inherit ITEM;

void create()
{
	set_name("ľ��", ({ "wood","ľ��"}) );
	set_weight(270);
	set_max_encumbrance(800);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ľ�塣\n");
		set("value", 0);
		set("lore",1);
	}
    ::init_item();
}

int init()
{
	set_max_encumbrance(800*(!userp(environment())));
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

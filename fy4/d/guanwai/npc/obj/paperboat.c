inherit ITEM;

void create()
{
	set_name("ֽ��С��", ({ "paper boat","boat" }) );
	set_weight(1300);
	set_max_encumbrance(100);
	set("prep","inside");
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "��");
			set("long", "һ��ֽ�۵�С��������������ϸ�������ֹ����侫�¡�\n");
			set("value", 1000);
			set("real", 1);
	}
	::init_item();
}

int query_autoload() { return 1; }

int is_container()
{
	return 1;
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


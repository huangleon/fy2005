#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 6

void create()
{
	set_name("��ľ��", ({ "big woodcase"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("prep","on");
	set("unit", "��");
	set("desc", "һ�����Էźܶණ���Ĵ�ľ�䡣\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","f");
	set("size",3);
	set("lore_item",1);

	set("value", 400000);
	set("tax",40);
	set("score_tax",6);
	set("max_item",MAX_ITEM);

	seteuid(getuid());
}

int is_container() {return 1;}

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

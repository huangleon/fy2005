#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 10

void create()
{
	set_name("��̴���", ({ "big bookcase"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set_max_encumbrance(80000);
	set("unit", "��");
	set("desc", "һ����̴ľ���Ĵ�������ƺ����԰��²����鼮��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","d");
	set("size",1);
	set("lore_item",1);
	set("value", 150000);
	set("tax",15);
	set("score_tax",4);
	set("max_item",MAX_ITEM);
	seteuid(getuid());
}

int is_container(){	return 1;}
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

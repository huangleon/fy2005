#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("��Ȫ", ({ "small fountain"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "һ��ˮ��������С��Ȫ��վ��Ȫ��Ƭ�̣������ͻᾡʪ��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","k");
	set("lore_item",1);
	set("outdoors",1);
	set("size",1);
	set("value", 100000);
	set("tax",10);
	set("score_tax",1);

	set("liq",([
				"name":"��Ȫˮ",
				"container":"��Ȫ"]));

	seteuid(getuid());
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

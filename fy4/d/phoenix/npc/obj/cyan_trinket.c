#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("������ħ��", ({ "wood" }) );
	set_weight(500);
	set("no_get",1);
	set("no_drop",1);
	set("no_sell",1);
	set("lore",1);
	set("long","�������������ħ̳�������һ����ħ���ϵ�������һ���������Ƶķ�ˡ�");
	set("desc_ext","֤ʵ���");
    ::init_item();
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

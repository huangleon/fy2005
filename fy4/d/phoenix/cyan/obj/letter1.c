#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"��Ѫƽ�ܴ�����"NOR, ({ "letter" }) );
	set_weight(500);
	set("lore",1);
	set("unit","��");
	set("long","һ������ʮ�ֱ���Ĵ�������������Ũ�ݵļ������֣���ƽ���¡����ѹ⣢��");
	set("desc_ext","�μӴ��");
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

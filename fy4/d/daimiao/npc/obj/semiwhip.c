#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(MAG"������"NOR, ({ "whip" }) );
	set_weight(2000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "��");
			set("long", "����һ����ɫ��˿����");
			set("value", 10);
			set("material", "silk");
	}
	::init_whip(10);
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



#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("����", ({ "willow" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ��ϸ��ϸ����������\n");
		set("unit", "��");
	}
	::init_whip(1);
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

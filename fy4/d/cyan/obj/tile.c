
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����Ƭ", ({ "tile" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ���������Ƭ��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 100);
	}
	set_amount(1);
	::init_throwing(100);
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

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name("����ָ��", ({ "nail" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������ֲڵ���ָͭ�ס�\n");
		set("material", "bronze");
		set("female_only",1);
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(15);	// ��õ�ָ��.
}

int init()
{
	set("weapon_wielded","ָ����");
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

// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(CYN"�Ž����ɽ�"NOR, ({ "ancient sword","sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ʽ��ŵĶ̽�����ɫ�Ľ����ϵ���ŷ����Ļ��ơ�\n�������������۵Ķ̽���ݺ����л�����ǧ�������������\n");
		set("material", "bronze");
		set("no_get",1);
		set("nodrop_weapon",1);
	}
	::init_sword(120);	
}

int init()
{
	set("weapon_wielded","��");
}


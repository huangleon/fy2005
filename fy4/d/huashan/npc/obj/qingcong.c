// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name(CYN"��м�"NOR, ({ "qingcong" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ե��ž�ϸ���Ƶ�����ָ�ף�����һ�����ĵĺ��⡣\n");
		set("material", "crystal");
		set("no_get",1);
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(40);	// ��õ�ָ��.
}

int init()
{
//	::init();
	set("weapon_wielded","ָ����");
}

//int query_autoload() { return 1; }

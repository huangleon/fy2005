// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name(CYN"������צ"NOR, ({ "wolf claw","claw" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��������֮�����ɵ�צ�ӡ�\n");
		set("material", "bone");
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(5);	
}


#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("����", ({ "erhu", "er hu", "����" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("timbre",10);
		set("material", "wood");
		set("long", "һ����ɫ����ĺ��١�������10��\n");
		set("weapon_prop/karma",3);
	}
	::init_staff(15);
}

void init()
{
   add_action("do_play","play");
}


int do_play(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "erhu") {
      tell_object(me, "��Ҫ��ʲô��\n");
      return 1;
   }
   message_vision("$Nһ�������٣���ʱ������һ����Թ��������\n",me);
   return 1;
}

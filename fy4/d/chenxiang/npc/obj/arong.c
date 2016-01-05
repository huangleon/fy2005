// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("����", ({ "airong"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ���Խ��ɽ�����İ��ޡ�������Ĺ�Ч�������ξģ�cure���������ס�\n");
		set("unit", "��");
		set("value", 1000);
		set("wear_msg", "$N��һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N��$n��ͷ�ϳ���������\n");
		set("female_only", 1);

	}
	::init_head();
}

void init()
{
  	if(this_player()==environment() )
  	add_action("do_cure","cure");
}

int do_cure(string arg)
{
 	object me;
 	object ob;
 	if(!arg) return notify_fail("cure <ĳ��>\n");
 	me =this_player();
 	if (me->is_busy())
 		return notify_fail("��������æ��\n");
 	if(objectp(ob=present(arg,environment(me)))) {
	   	if (ob==me) {
	   		tell_object(me,"��ӻ����ͳ�һ��Խ��ɽ�������Լ������ξ���һ�����\n");
	   		message("vision",me->name()+"�ӻ����ͳ�һ��Խ��ɽ�������Լ������ξ���һ�����\n",environment(me),me);	
	   	} else 	
	   	   	message_vision("$N�ӻ����ͳ�һ��Խ��ɽ������$n�����ξ���һ�����\n",me,ob);
	   	ob->cure_arong(me);
   		me->perform_busy(1);
   		return 1;
 	} else return notify_fail("�Ҳ���"+arg+"��\n");
 
}

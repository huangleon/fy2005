// silencer@fengyun.com
#include <ansi.h>
inherit ITEM;

void create()
{	set_name("������",({ "fan" }) );
	set_weight(10000);
	set("unit", "��");
    set("long", "һ�������ӱ�ɵĴ����ȡ�\n");
	set("value", 1000);
	set("desc_ext","�ȣ�use fan��");
	::init_item();
}

void init(){
	add_action("do_wave", "use");
}

int do_wave(string arg){
	
	object me;		
	me = this_player();
	
	if (arg!="fan" && arg!="������")
		return 0;
		
	if( me->is_busy() ){
		tell_object(me,"��������æ��\n");
		return 1;
	}
	message_vision("$N����һ�Ѵ����ȣ����������˼��£�����ϰϰ�������ʱ�泩����ࡣ\n",me);
	if (me->query("bellicosity")>50)
		me->add("bellicosity",-50);
	else 
		me->set("bellicosity",0);
	me->start_busy(1);	
	return 1;
}

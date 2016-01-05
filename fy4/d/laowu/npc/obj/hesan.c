#include <ansi.h>  
inherit ITEM;

void create()
{
		set_name(HIB"���ɢ"NOR, ({ "lihunsan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�������������ӵĶ�����ҩ�����������Լ����ϡ�\n");
                set("desc_ext", "use lihunsan");
        }
        ::init_item();
}
void init()
{
	add_action("do_yong","use");
}

int do_yong(string arg)
{
	object ob,room;
	object me,corpse;
	me=this_player();
	
	
	if (arg != "lihunsan") 
		return 0;
		
	if(me->is_busy()|| me->is_fighting()) 
		return notify_fail("����æ���ء�\n");
	
    if(environment(me)->query("no_fight") || environment(me)->query("no_fly"))
		return notify_fail("�����ﲻ�������������\n");
    
    message_vision("$NС�����������$n������ȥ��\n",me, this_object());
	
	if (random(20)) {
		tell_object(me,"��ҩ��ʱ��̫�����ƺ��Ѿ�ʧЧ�ˡ�\n");
		return 1;
	}
		
	message_vision(BLU "$Nֻ�����Ʈ�������ƻ������˿���γ����⣬ƮƮ�������Ź��Źض�ȥ��\n"NOR, me);
	room = environment(me);
	if(objectp(corpse = CHAR_D->make_corpse(me, me)))
		corpse->move(room);
	me->move("/d/death/gate");
	me -> unconcious();  
	destruct(this_object());     
	return 1;
}

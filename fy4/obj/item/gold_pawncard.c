
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���̽�", ({ "golden pawncard","card" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","
СС�Ŀ�Ƭ�ϸ��ŷ��Ƶ��̵�ӡ�ǣ������˺󣬿�
���ɵ���Ʒ���������ӵ�������������ֻ��������
ӵ���߲���ʹ�ô˿���");
                set("value", 3000000);
				set("destination","none");
				set("material", "paper");
				set("desc_ext","���activate golden pawncard��");
        }
        ::init_item();
}


void init()
{
   	add_action("do_activate","activate");
}
    
    
int do_activate(string arg)
{
    	object me = this_player();

		if (!arg)		return 0;
		if (present(arg, me)!= this_object())
			return 0;
		
		
		if (!REWARD_D->check_m_success(me,"��������")) {
			tell_object(me,"ֻ�е���������ӵ���߲��ܹ�����𿨣�\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"���̽�")) {
			tell_object(me,"���Ѿ�ӵ�е��̽��ˣ�\n");
			return 1;
		}
		
			
		tell_object(me, "�㼤���˵��̽𿨣�������ڵ����ﴢ�棲������Ʒ�ˡ�\n\n")	;	
		
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s��Ϊ���Ƶ��̽𿨵�ӵ��������",me->name(1)));
        
        REWARD_D->riddle_done(me,"���̽�",10,1);
        me->set("marks/pawn_expansion",10);
        destruct(this_object());
    	return 1;
}


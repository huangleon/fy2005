//	Used by /d/fy/npc/mapseller
// 	��Ϥ���������Ĺ���	--- By silencer@fy4. workgroup

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ĺ���", ({ "golden card","card" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","
СС�Ŀ�Ƭ�ϸ��ŷ����Ϲ�Ǯׯ��ӡ�ǣ���˵�����˺�
���ܹ��ڴ󲿷ֵĵ�����ֱ��ͨ��Ǯׯת�˽��ס�
Ҳ��ͨ��set e_money 1��0 ��ת����Ǯ��ʽ��");
                set("value", 100000);
				set("destination","none");
				set("material", "paper");
				set("desc_ext","���activate��");
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

		if (!arg || (arg!="golden card" && arg!="card"))	{
			tell_object(me,"��ʽ��activate golden card\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"�ĺ���")) {
			tell_object(me,"���Ѿ�ӵ���ĺ����ˣ�\n");
			return 1;
		}
		
			
		tell_object(me, "
�㼤�����Ϲ�Ǯׯ�������˺ţ������ڿ�ʼ�������ͨ������
set e_money 1	:ͨ��ת�������н���
unset e_money	:������ֽ���н���\n\n")	;	
		
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s��Ϊ�Ϲ�����Ǯׯ�ĺ��𿨵�ӵ��������",me->name(1)));
        
        REWARD_D->riddle_done(me,"�ĺ���",10,1);
        destruct(this_object());
    	return 1;
}


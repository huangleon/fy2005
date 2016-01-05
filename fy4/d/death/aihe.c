// Silencer@FY4

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�κ���");
        set("long", @LONG
�����ֻ֪���κ��ţ�ȴ��֪���κ��ţ���ʵ�κ����������κӣ��κӹᴩ��
���������������һ��ʯ�ţ��ŵ�һ������ƽ��������һ��[37m����[32m���ƣ���������ȥ
·��ʫ�ơ����ֻ�Ȫ·���˹��κ��ţ�����ʯ���ޣ�����̨Ե�ơ��������ǵظ���
�˼�Ľ���֮���������κ��ţ����������ˡ�
LONG
        );
        set("exits", ([
		"north" : __DIR__"pingan",
		
        ]) );
        
        set("item_desc", ([
        	"����": "�κ��ŵľ�ͷ�������ƣ��������¶����ģ����߽�ȥ��(dash mist)��\n",
        	"mist":  "�κ��ŵľ�ͷ�������ƣ��������¶����ģ����߽�ȥ��(dash mist)��\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/yurui" : 1,
        ]) );
        
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-190);
	set("no_fight",1);
	set("no_meal","���Ȼ���ֿ��е�ʳ����ˮ���˿�ɬ�����࣬�Ͽ����۵����˳�����\n");
	setup();
}


void	init()
{
	add_action("do_dash","dash");
	return;
}


int	do_dash(string arg)
{
	string *revive_loc= ({   AREA_FY"church",   AREA_GUANWAI"tower",});
	object me, cloth;
	mapping buff;
	
	if (!arg)
		return notify_fail("��Ҫ���Ķ�����\n");
	
	if (arg!= "mist" && arg!= "����")
		return notify_fail("�㲻���߽�"+arg+"ȥ��\n");
			  	   	
   	me = this_player();
	
	if (!me->query_temp("marks/ready_incar"))
		return notify_fail("�㻹û���������������ܹ������أ�\n");
		
	if (ANNIE_D->check_buff(me,"mengpo-soup")>0)
		return notify_fail("�������Ķ�Թδ���������ٵ�һ����ɡ�����Ҫ�ȵ�"HIB"�����Ļ�"NOR"��״̬��ʧ��\n");
			
	me->delete_temp("marks/ready_incar");  	
   	message_vision(WHT"\n$N���˺��ģ�һͷ����������֮�У�ֻ������Ǻ���գ�ۼ�ʧ����Ӱ��������\n"NOR,me);
   	
   	if (!REWARD_D->check_m_success(me,"���εع�")) {
   		REWARD_D->riddle_done(me,"���εع�",50,1);
   		me->add("combat_exp",1500);
   		tell_object(me,WHT"��Ľ�����������ˡ�\n"NOR);
   	}
   	   	
   	if(me->is_ghost()){
		me->reincarnate();
		cloth = new("/obj/armor/cloth");
		if(objectp(cloth)) {
			cloth->move(me);
			cloth->wear();
		}
		
		// 5 mins NO_PK mark
/*		buff =
			([
				"caster":me,
				"who": 	 me,
				"type":	"no-pk",
				"att":	"bless",
				"name":	"���˽���",
				"buff1": "NO_PK",
				"buff1_c":1,
				"time":  300,
				"buff_msg":""NOR,
			]);
		ANNIE_D->buffup(buff);*/
				
//		me->unconcious();
		if (F_LEVEL->get_level(me->query("combat_exp"))< 11)
			me->move(AREA_FY"church");
		else
			me->move(revive_loc[random(sizeof(revive_loc))]);
		me->set("startroom", base_name(environment(this_player())));
		me->perform_busy(1);
		message("vision",
        	        "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
            	    "�ܾ��ˣ�ֻ����һֱû������\n", environment(this_player()), this_player());
   	
   		me->set("kee",10);
   		me->set("gin",10);
   		me->set("sen",10);
   		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		me->status_msg("all");
			
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"���ꡤ��������",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N�����������˼��㣬��վ��վ�����ˡ�\n"NOR,
		]);
		ANNIE_D->buffup(buff);
   	   	
   	}	
  	return 1;
		
}
	
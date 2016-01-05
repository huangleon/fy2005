// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
        if(me->query("class")!="taoist")
         	return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
   
        if((int)me->query_skill("scratmancy",1) < 20 )
                return notify_fail("��������Ҫ20���ĵ����������\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("������Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 50 ) 
			return notify_fail("����������Ҫ50�㷨����\n");
		me->add("mana", -50);
        me->force_status_msg("mana");

        sheet->add_amount(-1);
		seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "������" NOR, 
		({ "earth-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        
        me->save();
        message_vision("$Nд��һ����������\n" NOR, me);
        return 1;
}

int do_warp(string target, object who)
{
        object env, ding;
        env = environment(this_player());
        
        if(environment(this_player())->query("no_fly")
        	||environment(this_player())->query("no_death_penalty"))
    		return notify_fail("�˵ز���ʹ����������\n");  
        
        if (stringp(this_player()->query_temp("no_move")))
        	return notify_fail(this_player()->query_temp("no_move"));
        
		if (this_player()->query("class")!="taoist") {
			if(!objectp(ding = present("ding", env)))
				return notify_fail("���������ֻ���ڱ�����������\n");        
			if (ding->is_character()) 
	 	 		return notify_fail("���������ֻ���ڱ�����������\n");
		}
		
		if (this_player()->is_fighting())
    		return notify_fail("��ѽ�����ʱ���շ���û���õģ���������Ѿ���Ӱɡ�\n");  

        message("vision",
                HIB + this_player()->name() + "����һ����������\n"
"��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n"
                "Ȼ��һ����ͻȻ����\n" NOR, env);
        message("vision", "����...." + this_player()->name() + 
"�Ѿ������ˡ�\n", environment(this_player()), ({this_player()}));
	this_player()->start_busy(4);
	call_out("move_him",1+random(4),this_player());
	return 1;
}


int move_him(object me)
{
        message("vision",
                CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n"
                NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n"
                        "ȴ��һ����....\n\n\n", me);
        TASK_D->flying_risk(me);
        me->move(AREA_DEATH"gate");
        return 1;
}
 


/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/

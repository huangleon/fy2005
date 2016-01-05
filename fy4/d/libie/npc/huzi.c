#include <ansi.h>
inherit NPC;

void create()
{       set_name("С����", ({ "xiao huzi", "huzi" }) );
        set("long",  "
����һ����ͺ���Ĳ��죬���Ѿ�������Ѫ������һϢ�ˣ������ƺ���
���Ծ��Σ�����죩������ϣ����������֮ǰ�ܸ�����˭�����֡�\n");

	set("attitude", "heroism");
	set("age", 17);
	set("gin", -1);
        set("kee", -1);
        set("sen", -1);
        set("eff_gin", 1);
        set("eff_kee", 1);
        set("eff_sen", 1);
        set("title", "����");
        set("disable_type", HIR "<���Բ���>"NOR);
        set("combat_exp", random(10000));

        set_skill("unarmed", 70+random(100));
        set_skill("staff", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
        set_temp("apply/damage", random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);

        setup();
	this_object()->disable_player(" <���Բ���>");
	this_object()->set_temp("is_unconcious",1);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

}

void init()
{
    	::init();
    	call_out("die", 60, this_object());
}
 

void heart_beat()
{
	object ob,me,room;
	
	room=environment();
	ob = this_object();
	me=ob->query("������");
	if(living(ob))
	if(present(me,room))
	{	
		if(!me->query_temp("libie/���_��С����"))
        	{
               		me->set_temp("libie/���_��С����", 1);
                	message("vision",RED"\n����ԡѪ��С�����۵����һ�����Ѫ����ȵ���֣�����ߡ��� �����߰���\n�԰�С�����ֻ��˹�ȥ��\n"NOR, me);
        		ob->disable_player(" <���Բ���>");
        		ob->set_temp("is_unconcious",1);
        	}
        	else
        	{
                        message_vision(RED"С����������ת�����³�����Ѫ���ƺ�������Щ��\n"NOR,me);
                        me->delete_temp("libie/���_��С����");
                        if (REWARD_D->riddle_check(me,"���")<2)
                        	message_vision(RED"С���ӽ���ס$N���ֽе����㡢�㡢��ɱ����֣��磬�Ҹ���ƴ�ˣ�
����δ�䣬���ֵ�����ȥ��\n"NOR,me);
						else
						{
							tell_object(me, RED"С���ӽ���ס���������������Լ����Լ����������\n"NOR);
			                me->set("libie/huzi",1);	// perma here so ppl won't have to keep using lotus
			            }	
			        	ob->die();
        	}
	}
	else 
		ob->unconcious();
	::heart_beat();
}

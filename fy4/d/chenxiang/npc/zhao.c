#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("��һ��", ({ "zhao yidao", "zhao" }) );
        set("long", "�ɰ˿���һ���󺺣��಼���£�������ͷ��һ��������Ѫ���졣\n");
    	set("nickname", HIY"��̫��"NOR);	
    	
    	set("chat_chance",1);
		set("chat_msg",	({
            "��һ���������ŵ�������Ц������ͷʹ�������������ү�����⣬\nҪ��Ҫ��ү�������ΰ��������̵ģ����䲡����\n",
			})  );
        set("inquiry",([
        	"��ȸͼ"  :"��������Ǻö������������������ϱ�������ǰ�̫\n����һ���������ˡ�\n",
              ]) );
        set("combat_exp", 800000);

		set_skill("unarmed",150);
		set_skill("blade",150);
		set_skill("wind-blade",100);
		set_skill("tigerstrike",200);
		set_skill("parry",150);
		set_skill("dodge",150);
		set_skill("demon-steps",100);
				
		set("perform_weapon_attack", "npc/blade/wind-blade/leitingpili");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
		map_skill("parry","wind-blade");
		map_skill("dodge","demon-steps");
		map_skill("unarmed","tigerstrike");
		map_skill("blade","wind-blade");
	
		setup();
        carry_object("/d/chenxiang/npc/obj/qingcloth")->wear();
        carry_object("/d/chenxiang/npc/obj/qingribbon")->wear();
        carry_object("/d/chenxiang/npc/obj/redgirth")->wear();
        carry_object("/d/chenxiang/npc/obj/gold_blade")->wield();
 }

int accept_object(object me, object obj)
{                                                                 
	if( (string) obj->query("name") == "��ȸͼ")
	{
		message_vision(HIY"$N͵͵����$nһ����ȸͼ��\n"NOR,me,this_object());
		message_vision(HIY"$N���˿���ͻȻ�˷ܵĹ�����Ц������\n"NOR,this_object());
		me->set_temp("marks/longlife_peacockmap",1);
		call_out("fighting",2,me);
		return 1;
	}
	else
 	{
		message_vision("$N˵��������С�����գ����ҷ�����ȸͼ��û�ţ�\n",this_object());
		return 1;
	}
 	  return 1;
}


int fighting(object me)
{
	object miao,zhang;
	if (present(me,environment(this_object())))
	{
		if (miao=present("miao shaotian",environment(this_object())))
		{
			miao->kill_ob(this_object());
			message_vision("$N˵����С�����ӣ�������ȸͼ���Ҿ������㣡��\n",miao);
			this_object()->kill_ob(miao);
		}
		if (zhang=present("zhang san",environment(this_object())))
		{
			zhang->kill_ob(this_object());
			message_vision("$N˵����˭����̿�ȸͼ���Ҿ�Ҫ����������\n",zhang);
			this_object()->kill_ob(zhang);
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

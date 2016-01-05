
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("������", ({ "di qinglin","di","qinglin" }) );
        set("long","
һ��ѩ�׵����ѣ�һ����Ⱦ��һ�Ų԰���������ϣ����Ǵ������䵭����
�ı��顣������ӹ��������糾����ȴ�������������������ĵ�С��ү��\n");

        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty", 20);
	set("age",27);
        set("title", HIY"��Ϯһ�Ⱥ�"NOR);

        set("combat_exp", 3000000+random(1000000));
        set("max_force",2000);
        set("force",2000);
        
        set_skill("unarmed",200);
    	set_skill("dagger",200);
    	set_skill("xinyue-dagger",150);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
    	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","fall-steps");
	map_skill("parry", "xinyue-dagger");

        setup();

        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
//        carry_object(__DIR__"obj/letter2");
}

void init()
{
		if( !query_heart_beat(this_object()) ) set_heart_beat(1);
//		::init();
}

void heart_beat()
{
	object di,yang,room,ying, weapon;
	int rival;
	
	::heart_beat();
	di=this_object();
	if (!di)	return;
		
	room=environment();
	if (!room)	return;
	
	yang=present("yang zheng",room);
	if(query("yang_die"))
	{
		ying=present("ying wuwu",room);
		di->start_call_out( (: call_other, di, "kill_ying" ,di,ying:), 3);
		delete("yang_die");
	}
	if(rival=query("begin_rival"))
	{
		if((rival==4)||(rival==3))
		{
			command("nod");
			say("\n");
		}
		if(rival==2){
			say("\n");
			command("say ֻҪ���ܴ���ң�����������ģ��ҵ���Ҳ����ģ��㶼���Դ��ߡ�\n");
		}
		if(rival==1)
		{
			di->kill_ob(yang);
			yang->kill_ob(di);
			call_out("do_busy",5,di);
			delete("begin_rival");
		}

		yang->add("begin_rival",-1);
	} 
	
	
	if (objectp(yang))
	if (di->is_fighting(yang))
	if (random(3)==1&&!yang->query_busy()&&query("do_busy"))
	{
		message_vision(HIR"\n$N����һת��������$n��۵�����Ѩ�ϣ�$nֻ��������飬��Ҳ���ܶ��ˡ�\n"NOR,di,yang);
		yang->start_busy(200);
		weapon = yang->query_temp("weapon");
		if (objectp(weapon) && !weapon->query("blood"))
			message_vision(CYN"\n$N������˵�����⹳���ǲ���֮����Ȼ����������ע��һ��ʹ�ࡣ\n\n"NOR, di);
	}
}

int do_busy(object di)
{
	di->set("do_busy",1);
	return 1;
}

int kill_ying(object di,object ying)
{
	object room,who;
	
	room=environment();

	if(objectp(ying))
	{
		message_vision(YEL"$N�Ų��ߵ�$n���ʲô��Ҳû˵��ͻȻ����һ������$n
�������$p�����ࡣ\n\n"NOR,di,ying);
		who=ying->query("busy_object");
		if (environment(who)!= environment(this_object()))	return 0;
		message_vision(YEL"$N¶��һ�ֹŹֿ־�����񣬵���$n���ԣ��þ����һ˿������
Ϊ$n�⿪Ѩ����\n"NOR,ying,who);
		who->start_busy(1);
		ying->die();
		call_out("kill_who",3,di,who);
		return 1;
	}
	return 0;
}

int kill_who(object di, object who)
{
	message_vision(HIY"$N��$n΢Ц��������˵����ֻҪ�ܹ�ʤ���ң�ʲô�㶼������ȥ����\n"NOR,di,who);
	di->kill_ob(who);
	who->kill_ob(di);
	return 1;
}
	
void die()
{
	object yang,room,me,yangcorpse,ying;
	
	room=environment();
	
	yang=present("yang zheng",room);
	ying=present("ying wuwu",room);
	if(objectp(yang))
	{
		yang->set("killed_di",1);
		ying->set("sad_leave",1);
	}
	else
		if(me=room->query("�������"))
	{
		me->set("libie/���_ɱ��������",1);
		REWARD_D->riddle_set(me,"���",4);
		
	}
	::die();
}


int return_home(object home)
{
	home=environment();
	if(!present("yang zheng",home))
	{
		destruct(this_object());
		home->delete("�������");
	}
	return 1;
}
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
СС�����ϣ��������ʻ�����ʽ�������ʻ�����Զɽ�������ʻ��������⻨��
����ص����ţ����������еĻ������е���ˮ�е��£��ƺ��ܿ�����ȴ��Զ׽��
ס�������ʻ���һ����ȫ���������Ů�˰��׶�������˯�š�
LONG);

	set("type","indoors");
	set("outdoors", "wolfmount");
        set("exits",([
                "out":__DIR__"sunlake",
        ]) );
	set("objects",([
		__DIR__"npc/xiaolin":1,
		__DIR__"npc/liangyu":1,
     		__DIR__"npc/laopi":1,
		__DIR__"obj/flower1":1,
		__DIR__"obj/flower2":1,
		__DIR__"obj/flower3":1,
 		__DIR__"obj/flower4":1,
        	__DIR__"obj/flower5":1,
	]) ); 
	set("coor/x",-120);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

int kill_notify(object npc, int k)
{
	int i,j;
	object me,xiaoma,laopi;
	xiaoma=present("xiao ma",this_object());
	me = this_player();
	{
		if ( xiaoma && me->query_temp("marks/wolf_xiaoma_good") && xiaoma->query("free_hit") )
		{
			npc->set("chat_chance_combat", 5);
			npc->set("force_factor",0);
			npc->set("combat_exp", 5000000);
			xiaoma->delete("free_hit");
			xiaoma->set_temp("scene_start",1);
			
			message_vision(HIR"$N����$n�ȵ��������������ղ������������һ��\n"NOR,me,npc);
			me->kill_ob(npc);
			npc->kill_ob(me);

			message_vision(HIY"$NҲͻȻ����$n������������ȭ����\n"NOR,xiaoma,npc);
			npc->start_busy(3);
			
			npc->add_temp("cant_parry",1);
			npc->add_temp("cant_dodge",1);
			j=random(3)+2;
			for (i=0;i<=j;i++)
			{
				COMBAT_D->do_attack(xiaoma, npc, query_temp("weapon"));
			}
			npc->add_temp("cant_dodge",-1);
			npc->add_temp("cant_parry",-1);
			
			xiaoma->kill_ob(npc);
			npc->kill_ob(xiaoma);
		}
		else if (me->query_temp("marks/wolf_xiaoma_normal") && me->query_temp("marks/wolf_laopi_friend"))
		{
			npc->set("chat_chance_combat", 5);
			npc->set("force_factor",0);
			npc->set("combat_exp", 5000000);
			message_vision(HIR"$N����$n�ȵ��������������ղ������������һ��\n"NOR,me,npc);
			me->kill_ob(npc);
			npc->kill_ob(me);
			if (laopi = present("laopi",this_object()))
			{
				call_out("laopistory",20+random(40),laopi,npc,me);
			}
		}
		else 
		{
			message_vision(HIR"$N����$n�ȵ��������������ղ������������һ��\n"NOR,me,npc);
			me->kill_ob(npc);
			npc->kill_ob(me);
			return 1;
		}
	}
	return 0;
}

void goodresult_notify(object me,object xiaolin,int i)
{
	object xiaoma;
	if(living(xiaolin) && me->query_temp("marks/wolf_xiaoma_good"))
	{
		message_vision(HIW"$NͻȻ����һ�������ѹ���......������ʲô�ط���\n"NOR,xiaolin);
		if(!xiaolin->query("xiaoma_died") && xiaoma = present("xiao ma", this_object()))
		{
			xiaolin->set("nickname","��������");
			call_out("goodevent",4,xiaoma,xiaolin,me,1);
		}
		else if (xiaolin->query("xiaoma_died"))
		{
			xiaolin->set("nickname","��������");
			call_out("badevent",4,xiaolin,me,1);
		}
	}
	else if(living(xiaolin) && me->query_temp("marks/wolf_xiaoma_normal"))
	{
		xiaolin->set("nickname","��ˮܽ��");
		call_out("normalevent",4,xiaolin,me,1);
	}
}

void normalresult_notify(object me,object xiaolin,int i)
{

	if(living(xiaolin))
	{
		message_vision(HIW"$NͻȻ����һ�������ѹ���......������ʲô�ط���\n\n"NOR,xiaolin);
		xiaolin->set("nickname","��������");
		me->delete_temp("marks/wolf_xiaoma_normal");
		REWARD_D->riddle_done( me, "��ɽ����",100, 2);	// �ȳ�С�վ����Ժ�������
	}
}

void goodevent(object xiaoma,object xiaolin,object me,int i)
{
	switch(i)
	{
	case 1:	
		message_vision(HIR"$N������§ס$n����ҭ��˵����������\n\n"NOR,xiaoma,xiaolin);
		break;
	case 2:
        message_vision(HIR"$N��$n��ȭ��л����лӢ��������ȡ����ս�������������յǧ���������飡\n\n"NOR,xiaoma,me);
		break;
	case 3:
		message_vision(HIY"$Nһ�ѱ���$n���ݳ����ۡ�����\n\n"NOR,xiaoma,xiaolin);
			
			REWARD_D->riddle_done( me, "��ɽ����",100, 1);	// �ȳ�С�վ����Ժ�������
			me->delete_temp("marks/wolf_xiaoma_good");
	        destruct(xiaoma);
	        destruct(xiaolin);
		return;
	}
	i=i+1;
	call_out("goodevent",4,xiaoma,xiaolin,me,i);
}

void badevent(object xiaolin,object me,int i)
{
	switch(i)
	{
	case 1:
        	message_vision(HIC"$NͻȻ����һ��������������,��ͷ�����\n\n"NOR,xiaolin);
		break;
	case 2:
        	message_vision(HIC"$N��$nǳʩһ�񣺡���лӢ�۴�ȡ���Ҫȥ��С���ˣ���\n\n"NOR,xiaolin,me);
		break;
	case 3:
		message_vision(HIC"$N�૵�����С��С��Ϊʲô����Ҫ�׿��ң���...��...��...���㡣��\n\n"NOR,xiaolin);
		break;
	case 4:
        	message_vision(HIY"$N����һЦ��ת��Ծ�����......���ᴵ��һ����������ʧ�ں��档\n\n"NOR,xiaolin);
			
		// С��С��ͳͳ����⣬�����ɣ�û����������ˣ��������廹���ܰݵ�
			me->delete_temp("marks/wolf_xiaoma_good");
			me->delete("riddle/��ɽ����");
	        destruct(xiaolin);
		return;
	}
	i=i+1;
	call_out("badevent",4,xiaolin,me,i);
}

void laopistory(object laopi,object npc,object me){
	object grass, xiaoma;
	if(!objectp(npc))
	{
		return;
	}
	message_vision(HIR"\n\n$N΢΢̧��̧ͷ����$nһ�ۣ�ͻȻ����ȥ��ס̫��ʹ�ߣ�����й�ȥ......\n\n"NOR,laopi,me);
	grass = new(__DIR__"npc/obj/grass");
	grass->move(this_object());
	message_vision(HIR"$N����$n�����ˮǰ˵��������仰��\n		������ҵ����ѣ��Ҳ������㶪�ˡ���\n"NOR,me,laopi);
	me->set("marks/ɱ̫��ʹ��",1);
//	if (xiaoma = present("xiao ma", this_object()))
//		xiaoma->delete_scene();
	destruct(laopi);
	destruct(npc);
	
}

/*
void reset()
{
	object item;
	::reset();
	if (!present("begonia",this_object()))
	{
		item = new(__DIR__"obj/flower1");
		item->move(this_object());
	}
	if (!present("gardenia",this_object()))
	{
		item = new(__DIR__"obj/flower2");
		item->move(this_object());
	}
	if (!present("daisy",this_object()))
	{
		item = new(__DIR__"obj/flower3");
		item->move(this_object());
	}
	if (!present("hyacinth",this_object()))
	{
		item = new(__DIR__"obj/flower5");
		item->move(this_object());
	}
	if (!present("lily",this_object()))
	{
		item = new(__DIR__"obj/flower4");
		item->move(this_object());
	}
}
*/

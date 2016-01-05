inherit SMART_NPC;
#include <ansi.h>
void  smart_fight( object who);
int kill_him();

void create()
{
        set_name("ɽ����", ({ "taoist shan","shan" }) );
        set("nickname",HIY "����" NOR);
        set("title","���幩��");
        set("gender", "����");
        set("age", 60);
        set("long",
"ɽ�����Ƕ������ô��Ͻ����������幬�Ĺ���֮һ���ֳ�һ������ɫ
�ķ��ȡ�\n"
);
        set("attitude", "friendly");
        set("combat_exp", 800000);
        set("score", 2000);

        set("class", "beggar");
        set("reward_npc", 1);
		set("difficulty", 2);

        set("inquiry", ([
                "�����ķ�": "�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
		         "�ڼ�" : "action"CYN"���ڼ飿��ɽ����һ���ɻ�ؿ����㣺��˭�����㹬�����ڼ飿��\n"NOR,
                "�������":  (: kill_him :),

        ]) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        
        auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","dagou-stick",1);
        setup();
        
        carry_object(__DIR__"obj/s_staff")->wield();
		carry_object(__DIR__"obj/s_cloth")->wear();
}

int kill_him()
{
	object me;
	me = this_player();
	if (!me->query("annie/demon_puzzle") || REWARD_D->riddle_check(me,"��������") != 4)
	{
		message_vision(CYN"$N����Ŀ���$nһ�ۣ��ӱǿ������һ����\n",this_object(),me);
		command("say ��ܵ�Ҳ̫���˰ɣ�\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		me->start_busy(2);
		return 1;
	}
	else
	{
		if (!me->query_temp("annie/demon_san"))
		{
			me->set_temp("annie/demon_san",1);
			command("say ��Ȥ����Ȥ������ô��֪������£�");
			command("say ��Ȼ��ˣ��Ҿ͸�����һ�����ܡ�");
			command("say "+me->query("annie/demon_puzzle_san")+"\n");
		}
		else
		{
			command("say Ŷ������Ϊ�Ҿ���͵����ˣ�");
			command("say �Ҳ����ǻ��ǣ��Ѿ����������ˣ�");
			this_object()->kill_ob(me);
			me->kill_ob(this_object());
			me->perform_busy(2);
		}
	}
	return 1;
}

void die()
{
	object me, owner;
    if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed"))
			me = owner;
	if (!me)
	{
		::die();
		return;
	}

	if (!me->query_temp("annie/demon_san") || REWARD_D->riddle_check(me,"��������") != 4)
	{
		::die();
		return;
	}
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if (me->query("annie/demon_puzzle") == 3)
	{
		message_vision(CYN"\n$N�ڴ���֮�ʺ�Ȼ��������Ť��������$n˵��\n",this_object(),me);
		message_vision("�á����ðɣ��Ҿ͡����͸����㣬�Ǳ������ھ��ڡ������ڡ���̫����š���\n\n",this_object(),me);
		message_vision(RED"һ�ѷɵ�ͻȻ�Ӱ����ɳ���Ѹ���Ĳ�����$N���ʺ�\n\n"NOR,this_object(),me);
		message_vision(HIY"$N������������ͻ�˳��������п������죬�����ĵ���$n����\n$N��Ȼ��˫�ְ��·ɵ���ֻ��һ��ѪȪ�����$N���е����������ܡ���\n\n"NOR,this_object(),me);
		REWARD_D->riddle_set(me,"��������",5);
		REWARD_D->riddle_done(me,"�������",50,1);
	}
	else
	{
		message_vision(CYN"$N�ڴ���֮�ʺ�Ȼ��������Ť����������$n�Ķ��䣬����˵��һ�仰��\n",this_object(),me);
		tell_object(me,name()+"�����㣺����ˣ��鲻����͵�ġ�\n");
		message_vision("$n��ɫ��䣬��$N�Ѿ��ڿ�Ц���е�����ȥ��\n\n"NOR,this_object(),me);
		// failed,penalty: clean marks,��ͷ����
		REWARD_D->riddle_clear(me,"��������");
		me->add("annie/demon_xin_failed",1);
	}
	::die();
	return;
}
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


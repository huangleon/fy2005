inherit SMART_NPC;
#include <ansi.h>
int kill_him();

void create()
{
        set_name("�ֵ���", ({ "taoist lin" }) );
        set("nickname",HIG "���" NOR);
        set("gender", "����");
        set("title","���幩��");
        set("age", 65);
        set("long",
"�ֵ����Ƕ������ô��Ͻ����������幬�Ĺ���֮һ��\n"
);
	set("attitude", "friendly");
        set("combat_exp", 550000);
        set("score", 2000);

        set("class", "yinshi");

    	set("reward_npc", 1);
		set("difficulty", 1);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
		         "�ڼ�" : "action"CYN"���ڼ飿���ֵ�������С���ӣ�ҡͷ�������������Ū���˰ɡ���\n"NOR,
                "�������":  (: kill_him :),
        ]) );
		
		set("perform_weapon_attack", "palace/whip/thunderwhip/tianleiyiji");
	
		set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		set_skill("flame-strike",100);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
		set_skill("whip",100);
		set_skill("thunderwhip",100);
		set_skill("zuixian-steps",160);
        set_skill("cursism", 100);
        set_skill("necromancy", 100);    

        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("whip","thunderwhip");
        map_skill("dodge","zuixian-steps");
        map_skill("parry","thunderwhip");
        map_skill("move","zuixian-steps");
        map_skill("unarmed","flame-strike");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        add_money("coin", 30);
        carry_object(__DIR__"obj/l_whip")->wield();
	carry_object(__DIR__"obj/l_cloth")->wear();
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
		me->perform_busy(2);
		return 1;
	}
	else
	{
		if (!me->query_temp("annie/demon_lin"))
		{
			me->set_temp("annie/demon_lin",1);
			command("say ��Ȥ����Ȥ������ô��֪������£�");
			command("say ��Ȼ��ˣ��Ҿ͸�����һ�����ܡ�");
			command("say "+me->query("annie/demon_puzzle_lin")+"\n");
		}
		else
		{
			command("say Ŷ������Ϊ�Ҿ���͵����ˣ�\n");
			command("say �Ҳ����ǻ��ǣ��Ѿ����������ˣ�\n");
			this_object()->kill_ob(me);
			me->kill_ob(this_object());
			me->start_busy(2);
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

	if (!me->query_temp("annie/demon_lin") || REWARD_D->riddle_check(me,"��������") != 4)
	{
		::die();
		return;
	}
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if (me->query("annie/demon_puzzle") == 1)
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


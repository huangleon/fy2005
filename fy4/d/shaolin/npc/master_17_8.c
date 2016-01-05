
#include <ansi.h>
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("�ļ�", ({ "master jian", "master"}) );
        set("gender", "����" );
        set("class", "shaolin");
        set("age", 44);
		set("per", 35);
		set("attitude","friendly");
        
        set("long","\n");
        create_family("������", 17, "����");
        
        set("combat_exp", 1500000);
        
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("unarmed",160);
		set_skill("puti-steps",150);
		set_skill("dabei-strike",150);
		set_skill("xiaochengforce",100);
		set_skill("parry",150);
		set_skill("perception",50);
	
		map_skill("parry","dabei-strike");
        map_skill("dodge", "puti-steps");
		map_skill("force", "xiaochengforce");
		map_skill("unarmed", "dabei-strike");
	        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
            (: perform_action, "unarmed.qianshouqianbian" :),
            (: perform_action, "dodge.wuwuwuwo" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/skinmask")->wear();
		carry_object("/obj/armor/cloth")->wear();
}


void unconcious()
{
	die();
}

void die()
{
        int i;
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
				if(owner=killer->query("possessed"))
					killer = owner;

				me = killer;
				if (REWARD_D->riddle_check(me,"����֮��") == 3 && REWARD_D->riddle_check(me,"�ؾ�¥") == 4)
				{
					REWARD_D->riddle_set(me,"����֮��",4);
					message_vision(CYN"\n\n$NͻȻ��е���ס����ס�֣�\n",this_object());
					message_vision("$NĨȥ�����Ѫ������������ɱ�ң��Ҹ�����˭������͵���飡\n\n",this_object());
					me->ccommand("nod");
					message_vision(CYN"\n$N�������ֳ�һĨ�����΢Ц���Ǹ���ı���ǣ�����\n\n"NOR,this_object());
					message_vision(HIC"һ�ѳ���ͻȻ�Բؾ���¥�Ĵ������������ƫ���еش���$N�Ŀڡ�\n"NOR,this_object());
					message_vision(HIW"$N�͵���ͷ���������ŵؿ�����ǰ�������૵����ݣ������ݣ�����\n\n"NOR,this_object());
					REWARD_D->riddle_done(me,"�ؾ�¥",50,1);
				}

		}
        ::die();

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/




inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name(HIW"ѦЦ��"NOR, ({ "xue xiaoren", "xue" }) );
	set("nickname",HIG"��Ű׳�"NOR);
        set("title","ɱ��ׯ     ��ׯ��");
	set("gender", "����" );
        set("quality","evil");
        set("age", 53);
	set("int", 55);
	set("per", 30);
	set("long",
"���������Ҳ����ʮ���ˣ���������Щ���ף�����ȴ���ż�����廨����
�����������������Ǯ�����ϻ�����˫��ͷ���������ǹ��¿���������ɫ
�ƺ�ʮ�ֺ�����ϸһ����ԭ����Ϳ����֬��\n"
		);
        set("max_force", 5000);
        set("force", 5000);
	set("force_factor", 50);
	set("cor",90);
	set("str",60);
        set("combat_exp", 5200000);
	set("bellicosity",0);
        set("score", -1500);
        set_skill("sword", 180);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("literate", 40);
	set_skill("dodge", 330);
        set("agi",25);
        set("int",30);
/*		set("chat_chance",10);
		set("chat_msg",({
"·С������һ�Ż���������������Ȼ������Ż����䵽�Լ���������۾���
������̾�˿�������ʼ�����׽���\n",
"·С�Ѻ�ȻЦЦ ��˵������ɱ���Ǽ��ɾ�ʹ������顣��������һ�٣���˵����
��������ɱ��֮ǰ����һ��Ҫϴ���衣��\n",
		})	);
*/
 
	set_skill("sharen-sword", 120);
        map_skill("sword", "sharen-sword");
        map_skill("parry", "sharen-sword");
	set("flee_rate",60);
	set("alert_rate",80);
	set("strategy","conservative");
	set("w_type","sword");
	set("hunting",1);
	setup();
	carry_object(__DIR__"obj/xiuhuapao")->wear();
	carry_object(__DIR__"obj/hutoushoe")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
/*
void init()
{
    object room;
    remove_call_out("hunting");
    if(!room=environment()) return 0;
	if(!room->query("no_fight"))
		hunting();
       call_out("hunting",1);
}

void hunting()
{
    object ob;
	//if (!interactive(ob = this_player())) return;
	ob = this_player();
    if( ob->is_character() && living(ob) && !userp(ob) && !ob->query("quality"))
	//CHANNEL_D->do_sys_channel("sys","I meet "+ob->name());
	{
		kill_ob(ob);
		ob->kill_ob(this_object());
	}
}
*/
int normal_att(object opp)
{
	if(random(100)<30)
	command("perform sharenruma");
}

int alert_att(object opp)
{
	if(random(100)<50)
	command("perform sharenruma");
}

int flee_att(object opp)
{
	if(random(100)<80)
	command("perform sharenruma");
}

int die_action()
{
	object killer;
	
	if(objectp(killer=this_object()->query_temp("last_damage_from")))
	if(present(killer,environment()))
	{
		message_vision(HIR"$N��$n��е���������̫�������Ӹ���ƴ�ˣ�������\n",this_object(),killer);
		message_vision(HIR"$N���ܲ��ˣ���������$n���˹�ȥ��$n�ٲ��������������˸���æ���ҡ�\n",this_object(),killer);
		killer->die();
	}
	return 0;
}
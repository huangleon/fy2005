// XXDER@FY3
inherit SMART_NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "jian kuang","jian" }) );
    set("long", "�򽣶���Ϊ������\n");
	set("attitude", "friendly");
    set("age", 62);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",4);
    set("combat_exp", 2000000);
	set("class","baiyun");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	auto_npc_setup("wang",150,150,1,"/obj/weapon/","fighter_w","feixian-sword",1);
	set_skill("iron-cloth",100);
	set_skill("xisui", 50);
	map_skill("iron-cloth","xisui");
	setup();
    carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object who)
{
	if (REWARD_D->riddle_check(who,"��ͼһ��") !=9 )
	{
		ccommand("shake");
		ccommand("say ʦ����ǰ�����񲻸ҷ�����");
		return 0;
	}
	ccommand("emote �ֽ���Ҷ�³�΢һ��ͷ�����޶��ԣ��������է�֣�����ٿȻ����"+who->name(1)+"��");
	return 1;
}

void lose_enemy(object winner)
{
	object ye;
	ye = present("Master ye",environment());
	if (!ye || userp(ye))
		return;
	
	if (REWARD_D->riddle_check(winner,"��ͼһ��") !=9 )
		return;
		
	ye->ccommand("emote ������ɫ�������á�");
	ye->ccommand("emote ����Ť����һ�°��������ϵ���ͷ�� ");
	message_vision(YEL"\n����֨֨��һ������������κ�İ����ͻȻһת���ֳ�һ��ʯ�š�\n\n"NOR,ye);
	ye->ccommand("emote ��Ȼ�������Ƴ������ɾͰ�ҵ֮ʱ���������пɣ��������ҡ�
�����İ��Ƴ����ں���İ��ƹ��У����ǰȥߵ����");
	ye->ccommand("kick "+winner->query("id"));
	message_vision(YEL"\n$N���ߵ�һͷ������ʯ��֮�С�\n"NOR,winner);
	winner->move(load_object("/d/baiyun/changlang"));
	winner->perform_busy(1);
	message("vision",winner->name()+"�ߺ�����ķ��˽��������صĵ��ڵ��ϡ�\n",environment(winner),winner);
	REWARD_D->riddle_set(winner,"��ͼһ��",10);
	return ;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

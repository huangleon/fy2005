inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

int failit();
int dont();

void create()
{
    	set_name("���", ({ "master tian", "master"}) );
    	set("nickname", HIW "ǰ�η���"NOR);
    	set("gender", "����" );
    	set("age", 94);
    	set("per", 25);
    
    	set("attitude","friendly");
    	      
    	set("long", "���ֵĵ�ʮ������ɣ��������Ѹߣ������ڴˣ����Ѿ���������֮���ˡ�\n");
    	create_family("������", 15, "��ʦ");
    	set("class","shaolin");
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
    	    	"�������������������ã�һ��ƷζƷζ���ɡ�����\n",
            	"���̾����������ѽ������\n"
        }) );
    
	    	set("inquiry", ([
        	"����": (: dont :),
        	"�ر�": (: failit :),
    	]));

    	set("reward_npc", 1);
    	set("difficulty", 10);    
    	set("combat_exp", 5000000);
    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","yizhichan",1);
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}


int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 5)  
	{
		ccommand("dunno "+me->query("id"));
		return 1;
	}
	ccommand("pat master tian");
	ccommand("emote �����������ֺ�¥����Ҳ��̫ƽ��Ī�����������ǣ����");
	ccommand("say ��λʩ���뵽��¥һ̽�������������֡�");
	REWARD_D->riddle_set(me,"����֮��",6);
	return 1;
}


int failit()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 7)  
	{
		ccommand("pure "+me->query("id"));
		return 1;
	}
	me->ccommand("emote ������ʼĩ��ϸ��������һ�顣");
	ccommand("emote ���еĲ豭һ������ɫ�������д��£���");
	ccommand("emote ��ü��˼��˫���յĻ��γ���������˫���յĻ��γ���������");
	ccommand("say �ǲ��ǣ�����");
   	set_name(MAG"���"NOR, ({ "master tian", "master"}) );
	ccommand("emote "MAG"����ɫͻȻ��òҰף�������ӿ���Ϻ�ɫ����Ѫ����������"NOR);
   	set_name(HIR"���"NOR, ({ "master tian", "master"}) );
	ccommand("emote "HIR"���������壮����"NOR);
	REWARD_D->riddle_set(me,"����֮��",8);
	if (present("master wu",environment()))
	{
		present("master wu",environment())->ccommand("emote ������ʦ����������");
	}
   	set_name("���", ({ "master tian", "master"}) );
	tell_object(me,HIG"����ʦ����������˭��֪��"YEL"���γ���"HIG"�������أ�\n"NOR);
	die();
	return 1;
}


void attempt_apprentice(object me)
{
    	command("shake");
    	command("say ���������Ѹߣ��㻹��ȥ�ҷ��ɰɣ�\n");
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/



#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("����", ({ "lv san", "lv" }) );
	set("gender", "����" );
	set("nickname",HIY"��������"NOR);
        set("title","����     ��������");
        set("quality","evil");
	set("age", 67);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
    
	set("long",
"���Ǳ����ĺܺõ����ˣ�����֮�⣬ʵ��ûʲô���ڵĵط������������� 
һ����ȴ�Ǵ�˵�С����֡����������֯�����졣\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 7000000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("flame-strike", 150);
	map_skill("unarmed", "flame-strike");
	set("chat_chance",2);
	set("chat_msg",	({
	"������Ŀ��˼��ã�̾�˿���������ӥ����ӥ�����ܶ㵽���أ�\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
//                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}

#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("�Ϲٷ�", ({ "shangguan fei", "shangguan" }) );
	set("gender", "����" );
	set("nickname",HIC"�ɻ�"NOR);
        set("title","��Ǯ��     �ٰ���");
        set("quality","evil");
	set("age", 27);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"�Ϲٷ���ıȾ�������Щ�����Ҳ���ᣬ�������������飬������·�� 
��̬�ͺ����Ǿ��������ֵܡ�\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 8000000);
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
	"�Ϲٷ�Ŀ�и�������Թ��֮ɫ��������������������û�о��������ҾͿɻ� 
�ø���Щ���������������ҵĵ�λ��Ҳ�������ҵĸ��ף����������ҵ�һ�У� 
�ͺ�Ȼ����������ġ�\n",
        "�Ϲٷ�ͻȻ�������������������ɱ�˾�������Ҫ�Ҹ���ʲô���С�\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
//                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}

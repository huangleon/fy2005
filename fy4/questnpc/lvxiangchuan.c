#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("���㴨", ({ "lv xiangchuan", "lv" }) );
	set("gender", "����" );
	set("nickname",HIY"�㻨��԰"NOR);
        set("title","��԰     �ϲ�����");
        set("quality","evil");
	set("age", 23);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"���Ǹ���ɫ�԰ף����ʱ����ˣ����Ա���������͹����������������㴨���� 
����������������֣�Ҳ��������������ڰ�������֮һ�����������ڻ��� 
һ��İ���������Ҳû���κ����ܱȵ�������\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 3400000);
        set("score", -16000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("dragonstrike", 150);
	map_skill("unarmed", "dragonstrike");
	set("chat_chance",2);
	set("chat_msg",	({
	"���㴨ͻȻ�����˻�е�����һ�����ҵģ������ҵġ�\n",
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}

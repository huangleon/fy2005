#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("������", ({ "wang banxia", "wang" }) );
	set("gender", "����" );
	set("nickname",HIC"�������"NOR);
        set("title","ؤ��     ʮ������");
        set("quality","evil");
	set("age", 37);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"����ĸ��ݣ���ɫ���࣬��һ����Ȼ���ǲ�������ȴϴ���ڸɾ��������� 
�£�һ˫���Ƹ����������������ָ�ϴ��Ÿ����α����ָ����Ⱦ������ 
Į�Ѽ����Ų��ƶ���ʾ�������Ϣ��\n");
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
	set_skill("dragonstrike", 150);
	map_skill("unarmed", "dragonstrike");
	set("chat_chance",2);
	set("chat_msg",	({
	"�������ٺ�Ц����ؤ����������ٺ٣������ң�˭�����ʸ�ؤ����ͷ�ϴ�\n"
	})	);  
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.xianglongwuhui":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}

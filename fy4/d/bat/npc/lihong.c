#include <ansi.h>
inherit NPC;

void create()
{
 	set_name("�����", ({ "li hongxiu","li" }) );
 	set("gender", "Ů��" );
 	set("title", "��ѧ��Ů" );
 	set("age", 22);
 	set("attitude", "friendly");	
 
 	set("long","
����һ����������Ů������������������ʺ����ѣ��㷢���ɵ�����¶��
˫��Ө���޳������ȣ�������ġ������޴õ�˫�㡣\n" );
 	set("combat_exp", 900000);
 	
 	set_skill("luoriquan",150);
 	set_skill("unarmed", 200);
 	set_skill("parry", 200);
 	set_skill("dodge",200);
 	set_skill("fengyu-piaoxiang",150);
 	
 	map_skill("unarmed","luoriquan");
 	map_skill("dodge","fengyu-piaoxiang");
 	
 	
 	
 	set("chat_chance", 1);
 	set("chat_msg", ({
 	"�����ҧ���촽������
��ƫ����������ƫ�������£���Ҳ��Ҫɹ̫������������̫����
ɹ����ͷ�Σ����治����Ϊʲ��ϲ��̫����\n",
	"�����Ц������ֹͣ�ֵ���
����Ҳ��������������ˣ��ԴӾ��ǻ����ᣬ������������붯��
����������ȥ�����Ҫ�����å�ˡ�\n",
	"�����Ʋ�����������ү���Ṧ������˫����������˭��֪������
��������ү�����ţ�Ѵ������᣿\n",
        }) );
 
 	setup();
 	carry_object("/obj/armor/cloth", 
 		([	"name"	:	HIR"�ʺ�����"NOR,
 			"long"	:	"һ������������ʺ����ѡ�\n",
 			])
 		)->wear();
}

void reset(){
	if (!present("cloth",this_object()))
		carry_object("/obj/armor/cloth", 
 		([	"name"	:	HIR"�ʺ�����"NOR,
 			"long"	:	"һ������������ʺ����ѡ�\n",
 			])
 		)->wear();
}
		
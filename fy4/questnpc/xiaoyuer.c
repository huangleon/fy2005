#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("С���", ({ "xiao yuer","yuer" }) );
	set("gender", "����" );
        set("nickname",HIC"���µ�һ������"NOR);
        set("title","���˹�     С����");
        set("quality","good");
	set("age", 21);
	set("int", 100);
	set("per", 40);
	set("str", 52);
	set("dur", 30);
	set("cor", 50);
	set("long",
"����ͷ�ڷ�Ҳδ�ᣬ��������˸��ᣬ����֪���أ�������������Ƥ�������� 
���̵����꣬����ȴ�����������������ǿ�ҵ��������������������������� 
�е����̣��⵶��ȴ�ǵ�δʹ���ѿ�����ʹ������������������˵�������������� 
������������Ƥ�������ǵ��̵����꣬���˵ĵ�һ��ӡ�󣬾��Ǹ������꣬���� 
�������ꡣ\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
	set("max_force",2000);
	set("force",2000);

        set("combat_exp", 6000000);
        set("score", 5200);
        set_skill("unarmed", 80);
        set_skill("sword", 110);
        set_skill("force", 70);
        set_skill("parry", 110);
        set_skill("literate", 80);
	set_skill("dodge", 140);

        set_skill("feixian-sword", 180);
	set_skill("jingyiforce", 60);
        set_skill("feixian-steps",180);
	
        map_skill("sword","feixian-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "feixian-sword");
	map_skill("dodge","feixian-steps");
	set("chat_chance",10);
	set("chat_msg",	({
		"С���������һЦ��Ʋ��Ʋ�������촽��������ȱ�����ͷ�죬��������Ӱ� 
�����ƻ��������ҳ����� \n",
"С���գգ�ۣ��������������ӣ�մ�С�㻹���ͳƵ������˶��ɡ�\n",
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("���޼�", ({ "zhao wuji","zhao" }) );
	set("gender", "����" );
        set("nickname",HIW"�����ϻ�"NOR);
        set("title","�����     ������");
        set("quality","good");
	set("age", 29);
	set("int", 59);
	set("per", 30);
	set("str", 32);
	set("dur", 30);
	set("cor", 50);
	set("long",
"��ԭ���Ǹ���Ӣ�������꣬�����������촽��Ǭ�ѣ��ڳ�Ѫ˿��������Ƥ 
�����Ѿ�Ǭ�ѡ��ۿ��Ѱ���ȥ�������������ɫ���ѱ�������Ű�ֽ��\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
	set("max_force",2000);
	set("force",2000);

        set("combat_exp", 5000000);
        set("score", 1200);
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
		"���޼���������գ�һ��һ�ֵ����һ�û�е���ȥ���һ����ţ���Ϊ�һ��г�ޡ�\n"
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

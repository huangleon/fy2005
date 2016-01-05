
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create()

{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    	set("nickname", HIW "���ɹ�"NOR);
    	set("gender", "Ů��");

    	set("class","huashan");
    	create_family("��ɽ��", 16, "����");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"Ůͯ","С��","����","Ů��","÷ʹ","��ʹ",
					"��ʹ","��ʹ","����Ů��","������Ů","��������",
					"�����ɼ�",CYN"��Ů"NOR,CYN"��ʥ"NOR,CYN"���ڴ���
					"NOR,HIC"��������"NOR}));
    	
    	set("reward_npc", 1);
    	set("difficulty", 5);
    
    	set("age", 59);
    	set("per", 3);
    
    	set("combat_exp", 3200000);
    	set("attitude", "friendly");
	set("guard_msg","$N�ȵ���ƶ���ͽ�ܣ��ݲ��ø������̣ܽ�\n\n");

    	set_skill("unarmed", 150);
    	set_skill("zhaixin-claw",150);
    	set_skill("move", 150);
    	set_skill("dodge", 150);
    	set_skill("parry", 150);
    	set_skill("literate", 100);
    	set_skill("chanting",100);
    	set_skill("force", 150);
	set_skill("sword", 200);
	set_skill("anxiang-steps", 150);
	set_skill("tanzhi-shentong", 150);
	set_skill("throwing", 200);
	set_skill("hanmei-force", 150);
	set_skill("qingfeng-sword", 150);
	set_skill("perception", 100);
	set_skill("foreknowledge", 100);
	
	
	map_skill("force", "hanmei-force");
	map_skill("move", "anxiang-steps");
	map_skill("parry", "tanzhi-shentong");
	map_skill("sword", "qingfeng-sword");
	map_skill("dodge", "anxiang-steps");
	map_skill("unarmed", "zhaixin-claw");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("sword", "qingfeng-sword");
	
	set("inquiry", ([
		"leave" : (: leave :),
	]));

	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (: exert_function, "chill" :),
    }) );
	
   	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "������"NOR,
                        "long"  :       0 ])
                )->wear();
}


void attempt_apprentice(object ob)
{
    	if (ob->query("gender")=="����") {
    		command("say ��ɽֻ��Ů��Ϊͽ��\n");
    		return;
    	}	
    	if (ob->query_skill("sword",1) < 15) {
        	 command("say  ��Խ�����֪���٣���Ȼ�������ң�����15������������ ");
			return;
    	}
    	if ((int)ob->query_skill("move",1) < 15 ) {
        	command("say ���µ����ƺ�����ѧ�䰡������15�������Ṧ��");
		return;
    	}
    	command("recruit " + ob->query("id"));
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="huashan") return 0;
	message_vision(CYN"$N��Цһ��������ɽ��Ȼ�������ĵ��ӡ���\n"NOR, this_object());
	message_vision(CYN"$N˵����÷�ķ���ժ���ֵ��ؾ�������¡�\n"NOR,this_object());
	return 1;
}
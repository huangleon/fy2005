
inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("Ѧ����", ({ "xue yiren", "xue" }) );
	set("nickname",RED"Ѫ����"NOR);
        set("title","ɱ��ׯ     ��ׯ��");
        set("gender", "����" );
        set("quality","evil");
        set("age", 48);
	set("int", 52);
	set("per", 15);
	set("fle",40);
	set("long",
"�������������ݣ����ż��������������Ҳû��ʲô���촦��ֻ����һ˫�۾�
ȴ�Ǿ����й⣬���˲��ұ��ӡ������ᱳ�ű����ʳ��ң������ķ�ʽ���κ���
����õ�����˱�����ֻΪ�����������ʱ���ｫ���γ�����\n"
		);
        set("max_force", 3000);
        set("force", 3000);
	set("force_factor", 130);
	set("cor",60);
	set("str",40);
        set("combat_exp", 10000000);
		set("bellicosity",0);
        set("score", 7200);
        set_skill("sword", 200);
        set_skill("force", 140);
        set_skill("parry", 180);
        set_skill("literate", 50);
	set_skill("dodge", 350);
        set("agi",25);
        set("int",30);
		set("chat_chance",10);
/*		set("chat_msg",({

		})	);
  */
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
        }) );
    set_skill("huanhua-sword", 180);
        map_skill("sword", "huanhua-sword");
		
	setup();
        carry_object("/obj/weapon/sword")->wield();
}
/*
void init()
{
        object room;
        remove_call_out("hunting");
        if(!room=environment()) return 0;
	if(!room->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])||userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->kill_ob(this_object());
        }
}
*/

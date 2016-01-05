//written by Cheng Bao
// gangster.c

#include <ansi.h>
inherit NPC;
void goaway();
void create()
{
        set_name("ɽ���ٷ�", ({ "shanxi gangster","gangster" }) );
        set("gender", "����" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", "��ǿ�������˰̣�����������һ���׺ݶ��Ե������ӡ�");
        set("attitude", "heroism");
        
        set("bellicosity", 1500 );
        set("combat_exp", 10000);
		set("no_lu_letter",1);
        set("chat_chance", 50);
        set("chat_msg", ({
		(: goaway :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              	"ǿ�������Խ�Ϊ����������Ҫ��������\n",
              	"ǿ���ߺ��������˲����ա�\n",
        }) );

        set("force_factor",20);
        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        
        set_skill("demon-steps",100);
        set_skill("demon-blade",120);
        set_skill("demon-strike",120);
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("unarmed","demon-strike");
	    setup();
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
	object ob;
	if (ob=present("li biaotou",environment()) )
	{
		command("grin");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return; 
	}
		
	message_vision("$Nһ�����ڣ���ʧ����Ӱ���٣�\n",this_object());
	destruct(this_object());
}


void unconcious()	{ die();}


void	die(){
	
	object killer;
	string deathmsg;
	string *msg = ({
		"\nɽ���ٷ˵��ڵ��������˼��µ����������ˣ��ֵ�������һ����\n",
		"\nɽ���ٷ������ؿ�ʹ���˵����֪�����Ͳ��������ˡ�\n",
		"\nɽ���ٷ˼�е������е��ˣ����е��ˣ��ͣ���㣡\n",
		"\nɽ���ٷ˰���һš����ʮ�������һ���ú���\n",
		"\nɽ���ٷ˾��ֵ�˵����ô���£�����˵���ڵ��ǲ���ô��\n",
	});
	
	deathmsg = msg[random(5)];
	
	if (objectp(killer = query_temp("last_damage_from"))) {
		if (killer->query("id")=="shanxi laoda")
			deathmsg = "\nɽ���ٷ˼�е����ϴ�ɱ�����ˣ���\n";
	}		
	message_vision(HIR""+ deathmsg + "\nɽ���ٷ����ˡ�\n"NOR, this_object());
	destruct(this_object());
}


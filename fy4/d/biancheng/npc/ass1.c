//written by Cheng Bao
// gangster.c

#include <ansi.h>
inherit SMART_NPC;
void goaway();
void create()
{
        set_name("������", ({ "veiled man","man" }) );
        set("gender", "����" );
        set("age", 27);
        set("per",10);
        set("long", "���˺ڲ����棬��������������Ů����������������Ŀ��");
                
        set("bellicosity", 1500 );
        set("combat_exp", 10000);

        set("chat_chance", 50);
        set("chat_msg", ({
			(: goaway :),
        }) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(30) :),
        }) );
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
		object ob;
		if (ob=present("fat lady",environment()) )
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
		"\n�����˰�ѽһ���������ؿڵ�����ȥ��\n",
		"\n�����˵���ײײ��б�ɳ�ȥ���ڵ��ϴ��˼���������Ѫ���ɽ���\n",
		"\n������˵����Ȼ�б��ڣ������ϴ�ʧ���ˣ��ö�������֣�\n",
		"\n�����˺�ڵ�˵��û�뵽�������ɶ������˲���ò�֣�\n",
		"\n�����˾��ֵ�˵����ô���£�����˵�����ǲ���ô��\n",
	});
	
	deathmsg = msg[random(5)];
	
	message_vision(HIR""+ deathmsg + "\n���������ˡ�\n"NOR, this_object());
	destruct(this_object());
}

